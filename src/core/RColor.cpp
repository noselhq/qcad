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
#include <QPainter>
#include <QPixmap>
#include <QBrush>

#include "RColor.h"
#include "RCircle.h"
#include "RDebug.h"
#include "RMath.h"

QColor RColor::CompatByLayer = QColor(1,1,1);
QColor RColor::CompatByBlock = QColor(2,2,2);
QList<QPair<QString, RColor> > RColor::list;
QMap<RColor, QIcon> RColor::iconMap;
bool RColor::isInitialized = false;
#include "RColorCodes.h"

/**
 * Constructs an invalid color with the fixed RGB value (0, 0, 0).
 */
RColor::RColor() :
    QColor(), mode(RColor::Fixed) {
}

RColor::RColor(const QColor& color, RColor::Mode mode) :
    QColor(color), mode(mode) {
}

RColor::RColor(int r, int g, int b, int a, RColor::Mode mode) :
    QColor(r, g, b, a), mode(mode) {
}

RColor::RColor(Qt::GlobalColor color, RColor::Mode mode) :
    QColor(color), mode(mode) {
}

RColor::RColor(RColor::Mode mode) :
    QColor(), mode(mode) {
}

RColor::RColor(const QString & name, RColor::Mode mode) :
    QColor(name), mode(mode) {
}

//bool RColor::equalsCorrected(const RColor & color) const {
//    return operator==(color);
//}

bool RColor::operator==(const RColor & color) const {
    if (mode == RColor::ByLayer) {
        return color.mode == RColor::ByLayer;
    }
    if (mode == RColor::ByBlock) {
        return color.mode == RColor::ByBlock;
    }
    return mode == color.mode && QColor::operator==(color);
}

bool RColor::operator!=(const RColor & color) const {
    return !operator==(color);
}

bool RColor::operator<(const RColor & color) const {
    return getHash() < color.getHash();
}

unsigned long long RColor::getHash() const {
    return ((unsigned long long)rgba())
            + (((unsigned long long)mode) << (4 * 8))
            + (((unsigned long long)isValid()) << (4 * 8 + 4));
}

/**
 * \return Highlighted color for the given color.
 */
RColor RColor::getHighlighted(const RColor& color, const QColor& bgColor) {
    if (!color.isValid()) {
        return Qt::gray;
    }

    RColor ret = color;
    int minDist = 75;

    int vColor = color.value();
    int vBgColor = bgColor.value();

    if (vBgColor > vColor) {
        if (vColor+minDist <= vBgColor-minDist) {
            ret.setHsv(color.hue(), color.saturation(), vColor+minDist);
            return ret;
        }
        if (vColor-minDist >= minDist) {
            ret.setHsv(color.hue(), color.saturation(), vColor-minDist);
            return ret;
        }
        else {
            ret.setHsv(color.hue(), color.saturation(), vBgColor+minDist);
            return ret;
        }
    }

    if (vBgColor < vColor) {
        if (vColor-minDist >= vBgColor+minDist) {
            ret.setHsv(color.hue(), color.saturation(), vColor-minDist);
            return ret;
        }
        if (vColor+minDist <= 255) {
            ret.setHsv(color.hue(), color.saturation(), vColor+minDist);
            return ret;
        }
        else {
            ret.setHsv(color.hue(), color.saturation(), vBgColor-minDist);
            return ret;
        }
    }

    if (vBgColor == vColor) {
        if (vColor+minDist <= 255-minDist) {
            ret.setHsv(color.hue(), color.saturation(), vColor+minDist);
            return ret;
        }
        else {
            ret.setHsv(color.hue(), color.saturation(), vColor-minDist);
            return ret;
        }
    }

    return ret;


//    if (color.value()+minDist < bgColor.value()-minDist) {
//        ret.setHsv(color.hue(), color.saturation(), color.value()+minDist);
//        return ret;
//    }

//    if (color.value()-minDist > bgColor.value()+minDist) {
//        ret.setHsv(color.hue(), color.saturation(), color.value()-minDist);
//        return ret;
//    }

//    RVector bgCenter(bgColor.hue(), bgColor.value());
//    RVector clrCenter(color.hue(), color.value());

//    RCircle bgCircle(bgCenter, minDist);
//    RCircle clrCircle(clrCenter, minDist);

//    QList<RVector> inters = RShape::getIntersectionPointsCC(bgCircle, clrCircle);
//    if (inters.size()==0) {
//        RVector s = (bgCenter+clrCenter)/2;
//        ret.setHsv((int)s.x, ret.saturation(), (int)s.y);
//        return ret;
//    }

//    if (inters.size()==1) {
//        RVector s = inters.at(0);
//        ret.setHsv((int)s.x, ret.saturation(), (int)s.y);
//        return ret;
//    }

//    if (inters.size()==2) {
//        RVector s1 = inters.at(0);
//        RVector s2 = inters.at(1);
//        if (s1.x>=0 && s1.x<=255 && s1.y>=0 && s1.y<=255) {
//            ret.setHsv((int)s1.x, ret.saturation(), (int)s1.y);
//            return ret;
//        }
//        if (s2.x>=0 && s2.x<=255 && s2.y>=0 && s2.y<=255) {
//            ret.setHsv((int)s2.x, ret.saturation(), (int)s2.y);
//            return ret;
//        }
//    }

//    Q_ASSERT(false);

    /*

    int val = ret.value();
    int hue = ret.hue();
    int sat = ret.saturation();

    int valDarker = val - 50;
    if (valDarker<0) {
        valDarker = -1;
    }

    int valLighter = val + 50;
    if (valLighter>255) {
        valLighter = -1;
    }

    if (valLighter!=-1 && qAbs(valLighter-bgColorValue)>=50) {
        ret.setHsv(hue, sat, valLighter);
        return ret;
    }

    if (valDarker!=-1 && qAbs(valDarker-bgColorValue)>=50) {
        ret.setHsv(hue, sat, valDarker);
        return ret;
    }
    */

    /*
    int bgValLighter = bgColorValue + 50;
    if (bgValLighter>255) {
        bgValLighter = -1;
    }



    // dark entity color:
    if (val < 192) {
        // bright bg:
        if (bgColorValue>200) {
            return ret.darker(200);
        }
        // dark bg:
        else {
            return ret.lighter(200);
        }
    }

    // bright entity:
    else {
        // bright bg:
        if (bgColorValue>200) {
            return ret.darker(200);
        }
        // dark bg:
        else {
            return ret.lighter(200);
        }
    }
    */

//    if (clr == Qt::white) {
//        return Qt::gray;
//    }

    // entity color is bright
    //return clr.darker(200);
    return RColor(255,255,0);
}

bool RColor::isValid() const {
    if (mode == RColor::ByBlock || mode == RColor::ByLayer) {
        return true;
    }
    return QColor::isValid();
}

bool RColor::isByLayer() const {
    return mode == RColor::ByLayer;
}

bool RColor::isByBlock() const {
    return mode == RColor::ByBlock;
}

bool RColor::isFixed() const {
    return mode == RColor::Fixed;
}

/**
 * \return Name of the color if known, otherwise "#RRGGBB".
 */
QString RColor::getName() const {
    init();

    QListIterator<QPair<QString, RColor> > it(list);
    while (it.hasNext()) {
        QPair<QString, RColor> p = it.next();
        if (p.second == *this) {
            return p.first;
        }
    }

    return QColor::name();
}

/**
 * \return List of known colors.
 *
 * \param onlyFixed Only fixed colors, not ByLayer, ByBlock, ...
 */
QList<QPair<QString, RColor> > RColor::getList(bool onlyFixed) {
    init();
    QList<QPair<QString, RColor> > l = list;
    //if (combineBw) {
    //    QString name = RColor(Qt::black).getName();
    //    l.removeAll(QPair<QString, RColor> (name, Qt::black));
    //    name = RColor(Qt::white).getName();
    //    l.removeAll(QPair<QString, RColor> (name, Qt::white));
    //} else {
    //    QString name = RColor(Qt::black, RColor::BlackWhite).getName();
    //    l.removeAll(QPair<QString, RColor> (name, RColor(Qt::black,
    //            RColor::BlackWhite)));
    //}
    if (!onlyFixed) {
        return l;
    }

    // remove "By Layer"
    QString name = RColor(RColor::ByLayer).getName();
    l.removeAll(QPair<QString, RColor> (name, RColor(RColor::ByLayer)));

    // remove "By Block"
    name = RColor(RColor::ByBlock).getName();
    l.removeAll(QPair<QString, RColor> (name, RColor(RColor::ByBlock)));

    return l;
}

/**
 * \return CAD index of this color used in MTEXT strings.
 */
int RColor::getColorIndex() const {
    if (isByBlock()) {
        return 0;
    }
    if (isByLayer()) {
        return 256;
    }

    for (int i=1; i<255; i++) {
        if (red()==RMath::mround(cadColors[i][0]*255) &&
            green()==RMath::mround(cadColors[i][1]*255) &&
            blue()==RMath::mround(cadColors[i][2]*255)) {

            return i;
        }
    }

    return -1;
}

int RColor::getCustomColorCode() const {
     return (red() << 0) + (green() << 8) + (blue() << 16);
}

/**
 * Creates a color from the given CAD code (index 0...256).
 */
RColor RColor::createFromCadIndex(int code) {
    // special colors:
    if (code==0) {
        return RColor(RColor::ByBlock);
    }
    if (code==256) {
        return RColor(RColor::ByLayer);
    }

    // normal indexed colors:
    if (code>0 && code<256) {
        RColor c;
        c.setRgbF(cadColors[code][0], cadColors[code][1], cadColors[code][2]);
        return c;
    }

    return RColor();
}

/**
 * Creates a color from the given CAD code (RGB encoded int).
 */
RColor RColor::createFromCadCustom(int code) {
    return RColor(
              (code&0x0000ff) >> 0,
              (code&0x00ff00) >> 8,
              (code&0xff0000) >> 16
           );
}

RColor RColor::createFromName(const QString& name) {
    init();

    QListIterator<QPair<QString, RColor> > it(list);
    while (it.hasNext()) {
        QPair<QString, RColor> p = it.next();
        if (p.first == name) {
            return p.second;
        }
    }

    return RColor(name);
}

void RColor::init() {
    if (isInitialized) {
        return;
    }

    isInitialized = true;

    init(tr("By Layer"), RColor(RColor::ByLayer));
    init(tr("By Block"), RColor(RColor::ByBlock));
    init(tr("Red"), RColor(Qt::red));
    init(tr("Yellow"), RColor(Qt::yellow));
    init(tr("Green"), RColor(Qt::green));
    init(tr("Cyan"), RColor(Qt::cyan));
    init(tr("Blue"), RColor(Qt::blue));
    init(tr("Magenta"), RColor(Qt::magenta));
    //init(tr("Black / White"), RColor(Qt::black, RColor::BlackWhite));
    init(tr("Black"), RColor(Qt::black));
    init(tr("White"), RColor(Qt::white));
    init(tr("Gray"), RColor(Qt::gray));
    init(tr("Light Gray"), RColor(Qt::lightGray));
    init(tr("Others..."), RColor());
}

void RColor::init(const QString& cn, const RColor& c) {
    list.append(QPair<QString, RColor> (cn, c));
    iconMap.insert(c, getIcon(c));
}

QIcon RColor::getIcon(const RColor& color, const QSize& size) {
    init();

    if (iconMap.contains(color)) {
        return iconMap[color];
    }

    RColor col = color;
    if (color.isByLayer() || color.isByBlock() || /*color == RColor(Qt::black,
            RColor::BlackWhite) ||*/ !color.isValid()) {
        col = Qt::white;
    }
    QImage img(size, QImage::Format_ARGB32_Premultiplied);
    img.fill(0);
    QPainter painter(&img);
    int w = img.width();
    int h = img.height();
    //    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(0, 0, w, h, col);
    if (!color.isValid()) {
        // icon for "Other colors..."
        QLinearGradient grad(0, 0, w, 0);
        grad.setColorAt(0, Qt::red);
        grad.setColorAt(0.33, Qt::yellow);
        grad.setColorAt(0.66, Qt::blue);
        grad.setColorAt(1, Qt::green);
        painter.fillRect(QRect(0, 0, w, h), grad);
    } /*else if (color == RColor(Qt::black, RColor::BlackWhite) || color
            == RColor(Qt::white, RColor::BlackWhite)) {
        // icon for black / white
        painter.setRenderHint(QPainter::Antialiasing);
        QPainterPath path;
        path.moveTo(0, 0);
        path.lineTo(w, 0);
        path.lineTo(w, h);
        painter.fillPath(path, Qt::black);
        painter.setRenderHint(QPainter::Antialiasing, false);
    }*/ else if (col.alpha() != 255) {
        // indicate alpha by an inset
        QBrush opaqueBrush = col;
        col.setAlpha(255);
        opaqueBrush.setColor(col);
        painter.fillRect(w / 4, h / 4, w / 2, h / 2, opaqueBrush);
    }
    painter.setPen(Qt::black);
    painter.drawRect(0, 0, w - 1, h - 1);
    painter.end();
    return QIcon(QPixmap::fromImage(img));
}

/**
 * \return QColor compatibility equivlent of the current color.
 */
QColor RColor::toCompat() const {
    if (isByLayer()) {
        return CompatByLayer;
    }
    if (isByBlock()) {
        return CompatByBlock;
    }

    return *this;
}

/**
 * Stream operator for QDebug
 */
QDebug operator<<(QDebug dbg, const RColor& c) {
    if (c.isValid()) {
        if (c.isByLayer()) {
            dbg.nospace() << "RColor(ByLayer)";
        } else if (c.isByBlock()) {
            dbg.nospace() << "RColor(ByBlock)";
        } else {
            dbg.nospace() << "RColor(RGBA: " << c.red() << ", " << c.green() << ", "
                    << c.blue() << ", " << c.alpha() << ")";
        }
    } else {
        dbg.nospace() << "RColor(invalid)";
    }
    return dbg.space();
}

/**
 * Serializes the given RColor object. Used for RSettings, keep in sync
 * with operator>>.
 */
QDataStream& operator<<(QDataStream& stream, const RColor& color) {
    stream << (const QColor&) color;
    stream << (quint16) color.mode;
    return stream;
}

/**
 * Deserializes the given RColor object.
 */
QDataStream& operator>>(QDataStream& stream, RColor& color) {
    stream >> (QColor&) color;
    quint16 mode;
    stream >> mode;
    color.mode = (RColor::Mode) mode;
    return stream;
}