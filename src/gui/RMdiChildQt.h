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

#ifndef RMDICHILDQT_H
#define RMDICHILDQT_H

#include <QMdiSubWindow>

#include "RDebug.h"
#include "RModifiedListener.h"

class RDocument;
class RDocumentInterface;
class RGraphicsViewQt;

/**
 * \brief MDI child window.
 *
 * \ingroup gui_qt
 *
 * \scriptable
 */
class RMdiChildQt: public QMdiSubWindow, public RModifiedListener {
Q_OBJECT

public:
    RMdiChildQt(QWidget* parent = NULL);
    virtual ~RMdiChildQt();

    void setDocumentInterface(RDocumentInterface* di);

    RDocumentInterface* getDocumentInterface();
    RDocument* getDocument();
    RGraphicsViewQt* getLastKnownViewWithFocus();

    virtual void updateModifiedListener(const RStorage* storage);

    void setCloseEventRejected() {
        //userNotifiedAboutClosing = false;
        closeEventAccepted = false;
    }

    void setCloseEventAccepted() {
        closeEventAccepted = true;
    }

//    bool isInBackground() {
//        return inBackground;
//    }

//    void setInBackground(bool on) {
//        inBackground = on;
//    }

    //static RMdiChildQt* getMdiChild(QWidget* w);

signals:
    void closeRequested(RMdiChildQt* mdiChild);
    void modifiedStatusChanged(RMdiChildQt* mdiChild);

protected:
    virtual void closeEvent(QCloseEvent* closeEvent);
    virtual QSize sizeHint() const;

private:
    RDocumentInterface* documentInterface;
    static RDocumentInterface* diLast;
    //bool userNotifiedAboutClosing;
    bool closeEventAccepted;
//    bool inBackground;
};

Q_DECLARE_METATYPE(RMdiChildQt*)

#endif