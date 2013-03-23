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
#include "REllipseData.h"
//#include "REllipseEntity.h"

REllipseData::REllipseData() {
}

REllipseData::REllipseData(const REllipse& ellipse) : REllipse(ellipse) {
}

REllipseData::REllipseData(RDocument* document, const REllipseData& data) {
    *this = data;
    this->document = document;
}

REllipseData::REllipseData(const RVector& center, const RVector& majorPoint, 
        double ratio, double startAngle, double endAngle, bool reversed) :
    REllipse(center, majorPoint, ratio, startAngle, endAngle, reversed) {
}

QList<RVector> REllipseData::getReferencePoints(
        RS::ProjectionRenderingHint hint) const {
    Q_UNUSED(hint)

    QList<RVector> ret;

    ret.append(center);
    ret.append(center+majorPoint);
    ret.append(center-majorPoint);
    ret.append(center+getMinorPoint());
    ret.append(center-getMinorPoint());
    ret.append(getFoci());

    if (!isFullEllipse()) {
        ret.append(getStartPoint());
        ret.append(getEndPoint());
    }

    return ret;
}

bool REllipseData::moveReferencePoint(const RVector& referencePoint,
        const RVector& targetPoint) {

    RVector startPoint = getStartPoint();
    RVector endPoint = getEndPoint();

    if (!isFullEllipse()) {
        if (referencePoint.getDistanceTo(startPoint)<RS::PointTolerance) {
            moveStartPoint(targetPoint, true);
            return true;
        }
        if (referencePoint.getDistanceTo(endPoint)<RS::PointTolerance) {
            moveEndPoint(targetPoint, true);
            return true;
        }
    }

    if (referencePoint.getDistanceTo(center+majorPoint)<RS::PointTolerance) {
        double minorRadius = getMinorRadius();
        majorPoint = targetPoint-center;
        setRatio(minorRadius / getMajorRadius());
        return true;
    }

    if (referencePoint.getDistanceTo(center-majorPoint)<RS::PointTolerance) {
        double minorRadius = getMinorRadius();
        majorPoint = -(targetPoint-center);
        setRatio(minorRadius / getMajorRadius());
        return true;
    }

    if (referencePoint.getDistanceTo(center+getMinorPoint())<RS::PointTolerance) {
        setMinorPoint(targetPoint-center);
        return true;
    }
    if (referencePoint.getDistanceTo(center-getMinorPoint())<RS::PointTolerance) {
        setMinorPoint(-(targetPoint-center));
        return true;
    }

    if (referencePoint.getDistanceTo(center)<RS::PointTolerance) {
        center = targetPoint;
        return true;
    }

    return false;
}