/**
 * Copyright (c) 2011-2013 by Andrew Mustun. All rights reserved.
 * 
 * This file is part of the QCAD project.
 *
 * QCAD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QCAD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QCAD.
 */

include("../Plugin.js");
include("Edit.js");

function AbstractPreferences(guiAction, appPreferences) {
    Edit.call(this, guiAction);
    if (isNull(appPreferences)) {
        appPreferences = true;
    }
    this.appPreferences = appPreferences;
    this.restartWarningShown = false;
}

AbstractPreferences.prototype = new Edit();

AbstractPreferences.prototype.beginEvent = function() {
    Edit.prototype.beginEvent.call(this);
    
    this.formWidget = this.createWidget("scripts/Edit/AbstractPreferences.ui");
    this.treeWidget = this.formWidget.findChild("twCategory");
    var title;
    if (this.appPreferences) {
        title = qsTr("Application Preferences");
    } else {
        title = qsTr("Drawing Preferences");
    }
    this.formWidget.setWindowTitle(title);
    this.treeWidget.setHeaderLabel(title);
    this.pageWidget = this.formWidget.findChild("stwPage");
    this.filterWidget = this.formWidget.findChild("leFilter");
    this.titleWidget = this.formWidget.findChild("lbTitle");
    
    var splitter = this.formWidget.findChild("splitter");
    splitter.setStretchFactor(0, 1);
    splitter.setStretchFactor(1, 4);
    
    // connections:
    this.treeWidget.itemSelectionChanged.connect(this, "showPage");
    this.filterWidget.textChanged.connect(this, "filterTree");    

    var btApply = this.formWidget.findChild("buttonBox").button(QDialogButtonBox.Apply);
    btApply.clicked.connect(this, "apply");

    if (this.appPreferences) {
        this.plugins = Plugin.getPlugins();
    } else {
        this.plugins = Plugin.getPlugins("scripts/Edit/DrawingPreferences");
    }
    AbstractPreferences.fillTreeWidget(this.plugins, this.treeWidget,
            this.appPreferences);
    this.treeWidget.expandAll();

    if (this.formWidget.exec() === QDialog.Accepted.valueOf()) {
        //this.save();
        // apply calls save and apply:
        this.apply();

        // force all settings to be reloaded from RSettings when they are
        // used next time:
        //RSettings.resetCache();

        /*
        if (!this.appPreferences) {
            var view = EAction.getGraphicsView();
            view.regenerate(true);
        }
        */
    }
    this.formWidget.destroy();
    this.terminate();
};

/**
 * Initializes the navigation tree based on available plugins with preferences.
 */
AbstractPreferences.fillTreeWidget = function(plugins, treeWidget, appPreferences) {
    for (var i = 0; i < plugins.length; ++i) {
        var plugin = plugins[i];
        var className = plugin.getClassName();
        try {
            // include normally not needed
            var doInclude = false;
            eval("if( typeof(" + className + ") == 'undefined' ) {"
                +    "doInclude = true;"
                + "}");
            if(doInclude) {
                eval("include('" + plugin.getFilePath() + "');");
            }
        } catch (e1) {
            qWarning("AppPreferences.js: Exception: ", e1);
            continue;
        }
        var cat;
        cat = undefined;
        try {
            eval("if( typeof(" + className + ") != 'undefined' && "
                    + className + ".getPreferencesCategory != undefined ) {"
                    + "cat = " + className + ".getPreferencesCategory("
                    + appPreferences + ");"
                + "}");
            if (cat == undefined) {
                continue;
            }
        } catch (e2) {
            qWarning("AppPreferences.js: Plugin class not found: ", className, " exception: ", e2);
            continue;
        }
        
        if (!plugin.preferenceFileExists()) {
            continue;
        }

        // update tree
        var items = treeWidget.findItems(cat[0], Qt.MatchFixedString);
        var item;
        item = undefined;
        if (items.length == 0) {
            item = new QTreeWidgetItem(treeWidget, [ cat[0] ]);
            treeWidget.addTopLevelItem(item);
            if (cat.length == 1) {
                item.setData(0, Qt.UserRole, i);
            }
        } else {
            item = items[0];
        }
        var parent = item;
        for (var x = 1; x < cat.length; ++x) {
            var subitem;
            subitem = undefined;
            for (var c = 0; c < parent.childCount(); ++c) {
                var child = parent.child(c);
                if (child.text(0) == cat[x]) {
                    subitem = child;
                    break;
                }
            }
            if (subitem == undefined) {
                subitem = new QTreeWidgetItem(parent, [ cat[x] ]);
                parent.addChild(subitem);
                if (x == cat.length - 1) {
                    subitem.setData(0, Qt.UserRole, i);
                }
            }
            parent = subitem;
        }
    }
    treeWidget.sortItems(0, Qt.AscendingOrder);
};

/**
 * Applies the settings of all preference pages by calling
 * 'applyPreferences' for every plugin class.
 */
AbstractPreferences.prototype.apply = function() {
    var mdiChild, document;

    // force all settings to be reloaded from RSettings when they are
    // used next time:
    RSettings.resetCache();
    
    this.save();

    for (var i = 0; i < this.plugins.length; ++i) {
        var plugin = this.plugins[i];
        var className = plugin.getClassName();
        
        var widget = plugin.getPreferenceWidget();
        if (isNull(widget) || widget.hasChanged != true) {
            continue;
        }
        
        try {
            // include normally not needed
            var doInclude = false;
            eval("if( typeof(" + className + ") == 'undefined' ) {"
                +    "doInclude = true;"
                + "}");
            if (doInclude) {
                eval("include('" + plugin.getFilePath() + "');");
            }
            
            // apply application settings globally:
            if (this.appPreferences) {
                eval("if(typeof(" + className + ".applyPreferences) == 'function') {"
                     + className + ".applyPreferences(undefined, undefined, widget);"
                     + "}");

                var mdiArea = EAction.getMdiArea();
                var mdiChildren = mdiArea.subWindowList();
                for (var j = 0; j < mdiChildren.length; ++j) {
                    mdiChild = mdiChildren[j];
                    document = mdiChild.getDocument();
                    eval("if( typeof(" + className + ".applyPreferences) == 'function' ) {"
                         + className + ".applyPreferences(document, mdiChild, widget);"
                         + "}");
                }
            }

            // apply document specific settings to current document:
            else {
                mdiChild = EAction.getMdiChild();
                document = EAction.getDocument();
                eval("if( typeof(" + className + ".applyPreferences) == 'function' ) {"
                     + className + ".applyPreferences(document, mdiChild, widget);"
                     + "}");
            }
        } catch (e) {
            qWarning("AbstractPreferences.js:",
                "apply(): Exception: %1; %2; %3"
                .arg(e.message).arg(e.fileName).arg(e.lineNumber));
            continue;
        }
    }
};

/**
 * Loads the preference page of the given plugin.
 * Called by 'showPage'.
 */
AbstractPreferences.prototype.load = function(plugin) {
    var widget = plugin.getPreferenceWidget();
    if (widget == undefined) {
        return;
    }
    // load preferences
    var className = plugin.getClassName();
    var document;
    document = undefined;
    if (!this.appPreferences) {
        document = EAction.getDocument();
    }
    try {
        eval("if (isFunction(" + className + ".initPreferences)) {"
                + className + ".initPreferences(widget, true, document, this);" + "}");
    } catch (e) {
        qWarning("AbstractPreferences.js:", "load(): exception:", e);
    }

    WidgetFactory.restoreState(widget, undefined, undefined, false, document);

    try {
        eval("if (isFunction(" + className + ".postInitPreferences)) {"
                + className + ".postInitPreferences(widget, true, document, this);" + "}");
    } catch (e) {
        qWarning("AbstractPreferences.js:", "load(): exception:", e);
    }
};

/**
 * Saves all preferences to the current document (this.appPreferences==false)
 * or to a global settings file (this.appPreferences==true).
 */
AbstractPreferences.prototype.save = function() {
    for (var i = 0; i < this.plugins.length; ++i) {
        var plugin = this.plugins[i];
        var widget = plugin.getPreferenceWidget();
        if (isNull(widget) || widget.hasChanged !== true) {
            continue;
        }
        var className = plugin.getClassName();
        var document;
        document = undefined;
        if (!this.appPreferences) {
            document = EAction.getDocument();
        }

        try {
            eval("if (isFunction(" + className + ".savePreferences)) {"
                    + className + ".savePreferences(widget, true, document);" + "}");
        } catch (e) {
            qWarning("AbstractPreferences.js:", "save(): exception:", e);
        }
        WidgetFactory.saveState(widget, undefined, document);
    }

    // check if preference changes require application restart and show
    // message if appropriate:
    if (WidgetFactory.requiresRestart===true && this.restartWarningShown === false) {
        var dlg = new QMessageBox(QMessageBox.Warning,
                qsTr("Restart required"),
                "",
                QMessageBox.OK);
        dlg.text = qsTr("Please restart QCAD for\nthe preference changes to take effect.");
        dlg.exec();
        this.restartWarningShown = true;
    }

    WidgetFactory.requiresRestart = false;
};

/**
 * Updates the navigation tree based on the given filter string.
 */
AbstractPreferences.prototype.updateTreeWidget = function(filterText) {
    if (isNull(filterText)) {
        filterText = "";
    }

    var rexp;
    try{
        rexp = new RegExp(filterText, "i");
    } catch (e) {
        rexp = new RegExp(".*", "i");
    }
    
    for(var i=0; i<this.treeWidget.topLevelItemCount; ++i) {
        var item = this.treeWidget.topLevelItem(i);
        var match = item.text(0).match(rexp);
        var found = this.filterItems(item, rexp, match);
        if (found || match) {
            item.setHidden(false);
            item.setExpanded(true);
        } else if(!match) {
            item.setHidden(true);
        }
    }
};

/**
 * \internal
 */
AbstractPreferences.prototype.filterItems = function(item, rexp, showAll) {
    var foundAny = false;
    for(var i=0; i<item.childCount(); ++i) {
        var subitem = item.child(i);
        var match = subitem.text(0).match(rexp);
        var found = this.filterItems(subitem, rexp, match);
        if (found || match) {
            subitem.setHidden(false);
            subitem.setExpanded(true);
            foundAny = true;
        } else if(!match) {
            if(!showAll) {
                subitem.setHidden(true);
            }
        }
    }
    return foundAny;
};

/**
 * Called when user enters a filter text for the navigation tree.
 */
AbstractPreferences.prototype.filterTree = function(text) {
    this.updateTreeWidget(text);
};

/**
 * Loads and shows the appropriate preferences page for the
 * current selected item in the navigation tree. Called
 * when the user selects an item in the tree.
 */
AbstractPreferences.prototype.showPage = function() {
    var items = this.treeWidget.selectedItems();
    if (items.length != 1) {
        return;
    }
    var item = items[0];
    if (item == undefined) {
        return;
    }

    var parent = item.parent();
    var pText = "";
    while(parent != undefined) {
        pText += parent.text(0) + ": " + pText;
        parent = parent.parent();
    }
    if (pText == "") {
        this.titleWidget.text = item.text(0);
    } else {
        this.titleWidget.text = pText + item.text(0);
    }
    var i = item.data(0, Qt.UserRole);
    var widget;
    if (typeof(i) != "undefined") {
        var plugin = this.plugins[i];
        widget = plugin.getPreferenceWidget();
        if (typeof(widget) == "undefined") {
            var prefFile = plugin.getPreferenceFile();
            widget = this.createWidget(prefFile);
            this.pageWidget.addWidget(widget);
            plugin.setPreferenceWidget(widget);
            this.load(plugin);
            var treeWidget = this.treeWidget;
            widget.settingChangedEvent = function() {
                var font = treeWidget.currentItem().font(0);
                font.setBold(true);
                treeWidget.currentItem().setFont(0, font);
            };
            var btReset = this.formWidget.findChild("ResetToDefaults");
            try {
                btReset.clicked.disconnect(this, "reset");
            } catch (e) {
                // ignored: signal might not be connected
            }
            btReset.clicked.connect(this, "reset");
        }
    } else {
        widget = this.pageWidget.findChild("empty");
    }
    this.pageWidget.setCurrentWidget(widget);
    this.treeWidget.setCurrentItem(item);
};

/**
 * Called when user clicks reset button on preferences page.
 */
AbstractPreferences.prototype.reset = function() {
    var widget = this.pageWidget.currentWidget();
    //qDebug("AbstractPreferences.js:", "reset(): widget.objectName:", widget.objectName);
//    debugger;
    WidgetFactory.resetState(widget);
};

/**
 * Called when the global or drawing unit changes. Notifies all loaded
 * plugin pages.
 */
AbstractPreferences.prototype.unitUpdated = function(unit) {
    for (var i=0; i<this.plugins.length; ++i) {
        var plugin = this.plugins[i];
        var className = plugin.getClassName();

        // pref page of this plugin is not opened yet, skip:
        var widget = plugin.getPreferenceWidget();
        if (isNull(widget)) {
            continue;
        }

        try {
            eval("if(isFunction(" + className + ".updateUnit)) {"
                    + className + ".updateUnit(unit);"
                    + "}");
        } catch (e) {
            qWarning("AbstractPreferences.js:", "unitUpdated(): Exception:", e);
            continue;
        }
    }
};

/**
 * Called when the global or drawing paper unit changes. Notifies all loaded
 * plugin pages.
 */
AbstractPreferences.prototype.paperUnitUpdated = function(unit) {
    for (var i=0; i<this.plugins.length; ++i) {
        var plugin = this.plugins[i];
        var className = plugin.getClassName();

        // pref page of this plugin is not opened yet, skip:
        var widget = plugin.getPreferenceWidget();
        if (isNull(widget)) {
            continue;
        }

        try {
            eval("if(isFunction(" + className + ".updatePaperUnit)) {"
                    + className + ".updatePaperUnit(unit);"
                    + "}");
        } catch (e) {
            qWarning("AbstractPreferences.js:", "paperUnitUpdated(): Exception:", e);
            continue;
        }
    }
};

AbstractPreferences.prototype.linearFormatUpdated = function(linearFormat) {
    for (var i=0; i<this.plugins.length; ++i) {
        var plugin = this.plugins[i];
        var className = plugin.getClassName();

        // pref page of this plugin is not opened yet, skip:
        var widget = plugin.getPreferenceWidget();
        if (isNull(widget)) {
            continue;
        }

        try {
            eval("if(isFunction(" + className + ".updateLinearFormat)) {"
                    + className + ".updateLinearFormat(linearFormat);"
                    + "}");
        } catch (e) {
            qWarning("AbstractPreferences.js:", "linearFormatUpdated(): Exception:", e);
            continue;
        }
    }
};