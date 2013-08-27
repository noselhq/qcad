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

#ifndef RATTRIBUTEDEFINITIONENTITY_H
#define RATTRIBUTEDEFINITIONENTITY_H

#include "entity_global.h"

#include "RTextEntity.h"
#include "RAttributeDefinitionData.h"

class RDocument;
class RExporter;

/**
 * Text entity.
 *
 * \scriptable
 * \sharedPointerSupport
 * \ingroup entity
 */
class QCADENTITY_EXPORT RAttributeDefinitionEntity: public RTextEntity {

    Q_DECLARE_TR_FUNCTIONS(RAttributeDefinitionEntity)

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

    static RPropertyTypeId PropertyAngle;
    static RPropertyTypeId PropertyBold;
    static RPropertyTypeId PropertyFontName;
    static RPropertyTypeId PropertyHAlign;
    static RPropertyTypeId PropertyHeight;
    static RPropertyTypeId PropertyItalic;
    static RPropertyTypeId PropertyLineSpacingFactor;
    static RPropertyTypeId PropertyPositionX;
    static RPropertyTypeId PropertyPositionY;
    static RPropertyTypeId PropertyPositionZ;
    static RPropertyTypeId PropertyPrompt;
    static RPropertyTypeId PropertySimple;
    static RPropertyTypeId PropertyTag;
    static RPropertyTypeId PropertyText;
    static RPropertyTypeId PropertyVAlign;

public:
    RAttributeDefinitionEntity(RDocument* document, const RAttributeDefinitionData& data,
        RObject::Id objectId = RObject::INVALID_ID);
    virtual ~RAttributeDefinitionEntity();

    static void init();

    virtual RAttributeDefinitionEntity* clone() const {
        return new RAttributeDefinitionEntity(*this);
    }

    virtual RS::EntityType getType() const {
        return RS::EntityAttributeDefinition;
    }

    bool setProperty(RPropertyTypeId propertyTypeId, const QVariant& value);
    QPair<QVariant, RPropertyAttributes> getProperty(
            RPropertyTypeId propertyTypeId,
            bool humanReadable = false, bool noAttributes = false);

    QString getTag() const {
        return data.getTag();
    }

    void setTag(const QString& t) {
        data.setTag(t);
    }

    QString getPrompt() const {
        return data.getPrompt();
    }

    void setPrompt(const QString& p) {
        data.setPrompt(p);
    }

protected:
    virtual void print(QDebug dbg) const;

protected:
    RAttributeDefinitionData data;
};

Q_DECLARE_METATYPE(RAttributeDefinitionEntity*)
Q_DECLARE_METATYPE(QSharedPointer<RAttributeDefinitionEntity>)
Q_DECLARE_METATYPE(QSharedPointer<RAttributeDefinitionEntity>*)

#endif