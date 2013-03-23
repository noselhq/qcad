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
#include <QDir>

#include "RScriptHandler.h"
#include "RDebug.h"
#include "RScriptHandlerRegistry.h"


QString RScriptHandler::autostartScriptName = "autostart";


/**
 * Looks up and initializes the autostart script(s) available for this
 * script handler.
 * This method calls \ref initScript for all files with a
 * supported file extension (see \ref getSupportedFileExtensions).
 */
void RScriptHandler::init(const QString& autostartFile,
    const QStringList& arguments) {

    QList<QString> extensions = getSupportedFileExtensions();
    QList<QString>::iterator it;
    for (it = extensions.begin(); it != extensions.end(); ++it) {
        QString scriptFile;
        if (autostartFile.isEmpty()) {
            scriptFile = "scripts" + QString(QDir::separator())
                    + autostartScriptName + "." + (*it);
        }
        else {
            scriptFile = autostartFile;
        }

        if (QFileInfo(scriptFile).exists()) {
            doScript(scriptFile, arguments);
        }
        else {
            qWarning() << "Autostart script not found at: '"
                       << scriptFile << "'";
        }
    }
}

/**
 * Runs the given script file as application level action.
 */
void RScriptHandler::triggerActionApplicationLevel(const QString& scriptFile,
        RGuiAction* guiAction) {
    QString suffix = QFileInfo(scriptFile).suffix();
    RScriptHandler* h = RScriptHandlerRegistry::getGlobalScriptHandler(suffix);
    if (h == NULL) {
        qWarning("RScriptHandler::triggerActionApplicationLevel: "
            "no script handler found for scriptFile: %s",
                (const char*) scriptFile.toUtf8());
        return;
    }

    h->createActionApplicationLevel(scriptFile, guiAction);
}