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

#ifndef RACTIONADAPTER_H
#define RACTIONADAPTER_H

#include "RAction.h"
#include "RVector.h"
#include "RDebug.h"
#include "REntity.h"

class RPropertyEvent;
class RGraphicsScene;
class RDocumentInterface;
class RCommandEvent;
class RCoordinateEvent;
class RDocument;
class REntityPickEvent;
class RMouseEvent;
class RWheelEvent;
class RGuiAction;
class RStorage;
class RTabletEvent;

/**
 * \brief Abstract base class for all action classes.
 *
 * Action classes handle user interaction with a document. A menu,
 * toolbar button or command usually triggers an action.
 *
 * \ingroup core
 * \scriptable
 * \generateScriptShell
 */
class RActionAdapter : public RAction {
public:
    RActionAdapter(RGuiAction* guiAction=NULL) : RAction(guiAction) {}
    virtual void beginEvent() {}
    virtual void setGraphicsView(RGraphicsView* /*view*/) {}
    virtual void finishEvent() {}
    virtual void suspendEvent() {}
    virtual void resumeEvent() {}
    virtual void escapeEvent() {}
    virtual void keyPressEvent(QKeyEvent& /*event*/) {}
    virtual void keyReleaseEvent(QKeyEvent& /*event*/) {}
    virtual void mousePressEvent(RMouseEvent& /*event*/) {}
    virtual void mouseMoveEvent(RMouseEvent& /*event*/) {}
    virtual void mouseReleaseEvent(RMouseEvent& /*event*/) {}
    virtual void mouseDoubleClickEvent(RMouseEvent& /*event*/) {}
    virtual void wheelEvent(RWheelEvent& /*event*/) {}
    virtual void tabletEvent(RTabletEvent& /*event*/) {}
    virtual void swipeGestureEvent(QSwipeGesture& /*gesture*/) {}
    virtual void panGestureEvent(QPanGesture& /*gesture*/) {}
    virtual void pinchGestureEvent(QPinchGesture& /*gesture*/) {}
    virtual void commandEvent(RCommandEvent& /*event*/) {}
    virtual void commandEventPreview(RCommandEvent& /*event*/) {}
    virtual void coordinateEvent(RCoordinateEvent& /*event*/) {}
    virtual void coordinateEventPreview(RCoordinateEvent& /*event*/) {}
    virtual void entityPickEvent(REntityPickEvent& /*event*/) {}
    virtual void entityPickEventPreview(REntityPickEvent& /*event)*/) {}
    virtual void propertyChangeEvent(RPropertyEvent& /*event*/) {}
};

Q_DECLARE_METATYPE(RActionAdapter*)

#endif