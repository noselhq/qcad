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

#ifndef RDIMALIGNEDDATA_H
#define RDIMALIGNEDDATA_H

#include "RDocument.h"
#include "RDimLinearData.h"
#include "RVector.h"

/**
 * Aligned dimension entity data class.
 *
 * \scriptable
 * \ingroup entity
 */
class RDimAlignedData: public RDimLinearData {
    friend class RDimAlignedEntity;

protected:
    RDimAlignedData(RDocument* document, const RDimAlignedData& data);

public:
    RDimAlignedData();
    RDimAlignedData(const RDimensionData& dimData,
                    const RVector& extensionPoint1,
                    const RVector& extensionPoint2);

    virtual QList<RVector> getReferencePoints(
        RS::ProjectionRenderingHint hint = RS::RenderTop) const;

    virtual bool moveReferencePoint(const RVector& referencePoint, 
        const RVector& targetPoint);

    virtual void recomputeDefinitionPoint(
        const RVector& oldExtPoint1, const RVector& oldExtPoint2,
        const RVector& newExtPoint1, const RVector& newExtPoint2);

    virtual QList<QSharedPointer<RShape> > getShapes(const RBox& queryBox = RDEFAULT_RBOX) const;
    virtual QString getAutoMeasurement() const;

private:
    // for caching only:
    mutable RVector refDefinitionPoint1;
    mutable RVector refDefinitionPoint2;
};

Q_DECLARE_METATYPE(RDimAlignedData*)
Q_DECLARE_METATYPE(QSharedPointer<RDimAlignedData>)

#endif