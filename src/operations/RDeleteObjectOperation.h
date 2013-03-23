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

#ifndef RDELETEOBJECTOPERATION_H
#define RDELETEOBJECTOPERATION_H

#include <QSharedPointer>

#include "RDeleteObjectsOperation.h"
#include "ROperation.h"
#include "RVector.h"

class RDocument;
class RExporter;
class RObject;

/**
 * Implementation of an operation that deletes entities.
 * 
 * \ingroup operations
 * \scriptable
 */
class RDeleteObjectOperation: public RDeleteObjectsOperation {
public:
    RDeleteObjectOperation(QSharedPointer<RObject> object, bool undoable = true);
    virtual ~RDeleteObjectOperation() {
    }
};

Q_DECLARE_METATYPE(RDeleteObjectOperation*)

#endif