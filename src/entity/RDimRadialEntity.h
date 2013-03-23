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

#ifndef RDIMRADIALENTITY_H
#define RDIMRADIALENTITY_H

#include "RDimensionEntity.h"
#include "RDimRadialData.h"

class RDocument;
class RExporter;

/**
 * Aligned dimension entity class.
 *
 * \scriptable
 * \sharedPointerSupport
 * \ingroup entity
 */
class RDimRadialEntity: public RDimensionEntity {

    Q_DECLARE_TR_FUNCTIONS(RDimRadialEntity)

public:
    static RPropertyTypeId PropertyCustom;
    static RPropertyTypeId PropertyHandle;
    static RPropertyTypeId PropertyType;
    static RPropertyTypeId PropertyBlock;
    static RPropertyTypeId PropertyLayer;
    static RPropertyTypeId PropertyLinetype;
    static RPropertyTypeId PropertyLineweight;
    static RPropertyTypeId PropertyColor;
    static RPropertyTypeId PropertyDrawOrder;

    static RPropertyTypeId PropertyMiddleOfTextX;
    static RPropertyTypeId PropertyMiddleOfTextY;
    static RPropertyTypeId PropertyMiddleOfTextZ;
    static RPropertyTypeId PropertyText;
    static RPropertyTypeId PropertyUpperTolerance;
    static RPropertyTypeId PropertyLowerTolerance;

    static RPropertyTypeId PropertyCenterPointX;
    static RPropertyTypeId PropertyCenterPointY;
    static RPropertyTypeId PropertyCenterPointZ;

    static RPropertyTypeId PropertyChordPointX;
    static RPropertyTypeId PropertyChordPointY;
    static RPropertyTypeId PropertyChordPointZ;

public:
    RDimRadialEntity(RDocument* document, const RDimRadialData& data,
                      RObject::Id objectId = RObject::INVALID_ID);
    virtual ~RDimRadialEntity();

    static void init();

    virtual RDimRadialEntity* clone() const {
        return new RDimRadialEntity(*this);
    }

    virtual RS::EntityType getType() const {
        return RS::EntityDimRadial;
    }

    bool setProperty(RPropertyTypeId propertyTypeId, const QVariant& value);
    QPair<QVariant, RPropertyAttributes> getProperty(
            RPropertyTypeId propertyTypeId,
            bool humanReadable = false, bool noAttributes = false);

    virtual RDimRadialData& getData() {
        return data;
    }

    void setData(RDimRadialData& d) {
        data = d;
    }

    virtual const RDimRadialData& getData() const {
        return data;
    }

    void setChordPoint(const RVector& p) {
        data.setChordPoint(p);
    }

    RVector getChordPoint() const {
        return data.getChordPoint();
    }

protected:
    virtual void print(QDebug dbg) const;

protected:
    RDimRadialData data;
};

Q_DECLARE_METATYPE(RDimRadialEntity*)
Q_DECLARE_METATYPE(QSharedPointer<RDimRadialEntity>)
Q_DECLARE_METATYPE(QSharedPointer<RDimRadialEntity>*)

#endif