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

#ifndef RPROPERTYTYPEID_H_
#define RPROPERTYTYPEID_H_

#include <typeinfo>

#include <QMap>
#include <QMetaType>
#include <QSet>
#include <QString>

#include "RDebug.h"

/**
 * Represents unique property type IDs. Every property type an object can have
 * has such an unique ID.
 *
 * E.g. all objects of type car may have a property
 * type called brand. This property type is uniquely identified by an instance
 * of this class. All instances of this class are automatically unique.
 *
 * \code
 * class Car {
 * public:
 * static RPropertyTypeId propertyBrand;
 * }
 *
 * RPropertyTypeId Car::propertyBrand(typeid(Car));
 * \endcode
 *
 * \ingroup core
 *
 * \scriptable
 * \copyable
 */
class RPropertyTypeId {
public:
    /**
     * \ nonscriptable
     */
    //RPropertyTypeId(const std::type_info& classInfo, const QString& groupTitle,
    //      const QString& title);
    /**
     * \ nonscriptable
     */
    //RPropertyTypeId(const std::type_info& classInfo, const RPropertyTypeId& other);

    RPropertyTypeId(const QString& customPropertyName);

    RPropertyTypeId(const RPropertyTypeId& other);
    RPropertyTypeId(long int id = INVALID_ID);

    long int getId() const;
    QString getCustomPropertyName() const;

    bool isValid() const;
    bool isCustom() const;

    /**
     * \nonscriptable
     */
    void generateId(const std::type_info& classInfo, 
        const QString& groupTitle, const QString& title, bool forceNew = false);
    /**
     * \nonscriptable
     */
    void generateId(const std::type_info& classInfo, 
        const RPropertyTypeId& other);

    /**
     * \nonscriptable
     */
    static QSet<RPropertyTypeId> getPropertyTypeIds(
            const std::type_info& classInfo);
    /**
     * \nonscriptable
     */
    static bool hasPropertyType(const std::type_info& classInfo,
            RPropertyTypeId propertyTypeId);
    QString getPropertyGroupTitle() const;
    QString getPropertyTitle() const;
    static RPropertyTypeId getPropertyTypeId(const QString& groupTitle,
            const QString& title);

    bool operator ==(const RPropertyTypeId& other) const;
    bool operator !=(const RPropertyTypeId& other) const;
    bool operator <(const RPropertyTypeId& other) const;

public:
    const static long int INVALID_ID;

private:
    long int id;
    QString customPropertyName;

    static long int counter;
    static QMap<QString, QSet<RPropertyTypeId> > propertyTypeByObjectMap;
    static QMap<long int, QPair<QString, QString> > titleMap;
};

QDebug operator<<(QDebug dbg, RPropertyTypeId& p);

uint qHash(RPropertyTypeId propertyTypeId);

Q_DECLARE_METATYPE(RPropertyTypeId)
Q_DECLARE_METATYPE(RPropertyTypeId*)
Q_DECLARE_METATYPE(const RPropertyTypeId*)
Q_DECLARE_METATYPE(QSet<RPropertyTypeId>)
Q_DECLARE_METATYPE(QList<RPropertyTypeId>)

#endif /* RPROPERTYTYPEID_H_ */