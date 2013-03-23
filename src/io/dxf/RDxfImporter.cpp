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
#include <QList>
#include <QFileInfo>
#include <QTextCodec>
#include <QMultiMap>

#include "dxflib/src/dl_dxf.h"

#include "RArcEntity.h"
#include "RBlock.h"
#include "RBlockReferenceEntity.h"
#include "RCircleEntity.h"
#include "RColor.h"
#include "RDebug.h"
#include "RDimAlignedEntity.h"
#include "RDimAngularEntity.h"
#include "RDimDiametricEntity.h"
#include "RDimRadialEntity.h"
#include "RDimRotatedEntity.h"
#include "RDimOrdinateEntity.h"
#include "RDocument.h"
#include "RDxfImporter.h"
#include "REllipseEntity.h"
#include "RFileImporterRegistry.h"
#include "RGlobal.h"
#include "RHatchEntity.h"
#include "RImageEntity.h"
#include "RLayer.h"
#include "RLeaderEntity.h"
#include "RLineEntity.h"
#include "RLinetype.h"
#include "RModifyObjectsOperation.h"
#include "RPointEntity.h"
#include "RPolylineEntity.h"
#include "RSettings.h"
#include "RSolidEntity.h"
#include "RSplineEntity.h"
#include "RStorage.h"
#include "RTextEntity.h"
#include "RTextRenderer.h"
#include "RVector.h"
#include "RView.h"


RDxfImporter::RDxfImporter(RDocument& document, RMessageHandler* messageHandler, RProgressHandler* progressHandler)
    : RFileImporter(document, messageHandler, progressHandler),
      inDict(false) {
}

RDxfImporter::~RDxfImporter() {
}

bool RDxfImporter::importFile(const QString& fileName, const QString& nameFilter) {
    Q_UNUSED(nameFilter)

    this->fileName = fileName;
    QFileInfo fi(fileName);
    if (!fi.exists()) {
        qWarning() << "RDxfImporter::importFile: "
                   << "file does not exist: " << fileName;
        return false;
    }

    if (fi.size()==0) {
        qWarning() << "RDxfImporter::importFile: "
                   << "file has 0 length: " << fileName;
        return false;
    }

    // detect QCAD 2 DXF file format (dxflib 2.x):
    dxfServices.detectQCad2Format(fileName);

    lockedLayers.clear();
    mtext = "";
    textStyles.clear();

    setCurrentBlockId(document->getModelSpaceBlockId());

    RImporter::startImport();

    DL_Dxf dxflib;
    bool success = dxflib.in((const char*)fileName.toUtf8(), this);

    if (success==false) {
        qWarning() << "Cannot open DXF file: " << fileName;
        return false;
    }

    // lock locked layers now. they are unlocked during import to load
    // the entitied on them:
    for (int i=0; i<lockedLayers.size(); i++) {
        RModifyObjectsOperation op;
        QSharedPointer<RLayer> layer = document->queryLayer(lockedLayers.at(i));
        if (layer.isNull()) {
            continue;
        }
        layer->setLocked(true);
        op.addObject(layer);
        op.apply(*document, false);
    }

    RImporter::endImport();

    // add some variables that need to be there for DXF drawings:
    /*
    TODO
    if (graphic->getVariableString("$DIMSTYLE", "").isEmpty()) {
        RS_DEBUG->print("RDxfImporter::fileImport: adding DIMSTYLE");
        graphic->addVariable("$DIMSTYLE", "Standard", 2);
        RS_DEBUG->print("RDxfImporter::fileImport: adding DIMSTYLE: OK");
    }
    */

    return true;
}

void RDxfImporter::processCodeValuePair(unsigned int groupCode, char* groupValue) {
    //printf("group code: %d\n", groupCode);
    //printf("group value: %s\n", groupValue);
}

/**
 * @return Pen with the same attributes as 'attributes'.
 */
RColor RDxfImporter::attributesToColor(bool forLayer) const {
    RColor color;
    if (attributes.getColor24()!=-1) {
        color = numberToColor24(attributes.getColor24());
    }
    else {
        color = numberToColor(attributes.getColor(), false, forLayer);
    }

    return color;
}

/**
 * Converts a color index (num) into a RS_Color object.
 * Please refer to the dxflib documentation for details.
 *
 * @param num Color number.
 * @param comp Compatibility with older QCad versions (1.5.3 and older)
 */
RColor RDxfImporter::numberToColor(int num, bool comp, bool forLayer) const {
    if (forLayer) {
        num = abs(num);
    }

    // Compatibility with QCad 1.5.3 and older:
    if (comp) {
        switch(num) {
        case 0:
            return RColor(Qt::black);
            break;
        case 1:
            return RColor(Qt::darkBlue);
            break;
        case 2:
            return RColor(Qt::darkGreen);
            break;
        case 3:
            return RColor(Qt::darkCyan);
            break;
        case 4:
            return RColor(Qt::darkRed);
            break;
        case 5:
            return RColor(Qt::darkMagenta);
            break;
        case 6:
            return RColor(Qt::darkYellow);
            break;
        case 7:
            return RColor(Qt::lightGray);
            break;
        case 8:
            return RColor(Qt::darkGray);
            break;
        case 9:
            return RColor(Qt::blue);
            break;
        case 10:
            return RColor(Qt::green);
            break;
        case 11:
            return RColor(Qt::cyan);
            break;
        case 12:
            return RColor(Qt::red);
            break;
        case 13:
            return RColor(Qt::magenta);
            break;
        case 14:
            return RColor(Qt::yellow);
            break;
        case 15:
            return RColor(Qt::black);
            break;
        default:
            break;
        }
    } else {
        if (num==0) {
            return RColor(RColor::ByBlock);
        } else if (num==256) {
            return RColor(RColor::ByLayer);
        } else if (num<=255 && num>=0) {
            return RColor((int)(dxfColors[num][0]*255),
                          (int)(dxfColors[num][1]*255),
                          (int)(dxfColors[num][2]*255));
        } else {
            qWarning() << "RDxfImporter::numberToColor: Invalid color number given.";
            return RColor(RColor::ByLayer);
        }
    }
    return RColor();
}

/**
 * @return color object from DXF coded integar 24 bit color number.
 */
RColor RDxfImporter::numberToColor24(int num) const {
    return RColor(
              (num&0x00ff0000) >> 16,
              (num&0x0000ff00) >> 8,
              (num&0x000000ff) >> 0
           );
}

/**
 * Converts a line width number (e.g. 1) into a RS2::LineWidth.
 */
RLineweight::Lineweight RDxfImporter::numberToWeight(int num) {
    switch (num) {
    case -1:
        return RLineweight::WeightByLayer;
    case -2:
        return RLineweight::WeightByBlock;
    case -3:
        return RLineweight::WeightByLwDefault;
    default:
        if (num<3) {
            return RLineweight::Weight000;
        } else if (num<7) {
            return RLineweight::Weight005;
        } else if (num<11) {
            return RLineweight::Weight009;
        } else if (num<14) {
            return RLineweight::Weight013;
        } else if (num<16) {
            return RLineweight::Weight015;
        } else if (num<19) {
            return RLineweight::Weight018;
        } else if (num<22) {
            return RLineweight::Weight020;
        } else if (num<27) {
            return RLineweight::Weight025;
        } else if (num<32) {
            return RLineweight::Weight030;
        } else if (num<37) {
            return RLineweight::Weight035;
        } else if (num<45) {
            return RLineweight::Weight040;
        } else if (num<52) {
            return RLineweight::Weight050;
        } else if (num<57) {
            return RLineweight::Weight053;
        } else if (num<65) {
            return RLineweight::Weight060;
        } else if (num<75) {
            return RLineweight::Weight070;
        } else if (num<85) {
            return RLineweight::Weight080;
        } else if (num<95) {
            return RLineweight::Weight090;
        } else if (num<103) {
            return RLineweight::Weight100;
        } else if (num<112) {
            return RLineweight::Weight106;
        } else if (num<130) {
            return RLineweight::Weight120;
        } else if (num<149) {
            return RLineweight::Weight140;
        } else if (num<180) {
            return RLineweight::Weight158;
        } else if (num<205) {
            return RLineweight::Weight200;
        } else {
            return RLineweight::Weight211;
        }
    }
    return (RLineweight::Lineweight)num;
}

void RDxfImporter::addLayer(const DL_LayerData& data) {
    QString layerName = data.name.c_str();
    bool frozen = (attributes.getColor()<0 || data.flags&0x01);
    bool locked = data.flags&0x04;
    attributes.setColor(abs(attributes.getColor()));
    RColor color = attributesToColor(true);
    RLinetype::Id linetypeId = RLinetype::INVALID_ID;
    linetypeId = document->getLinetypeId(attributes.getLineType().c_str());
    if (linetypeId == RLinetype::INVALID_ID) {
        linetypeId = document->getLinetypeId("CONTINUOUS");
    }
    RLineweight::Lineweight lw = numberToWeight(attributes.getWidth());

    QSharedPointer<RLayer> layer(
                new RLayer(
                    document,
                    layerName,
                    frozen,
                    false,
                    color,
                    linetypeId,
                    lw
                    )
                );

    if (locked) {
        lockedLayers.append(layerName);
    }

    importObject(layer);
}

void RDxfImporter::addBlock(const DL_BlockData& data) {
    QString blockName = QString(data.name.c_str());

    /*
    if (blockName.toLower()=="*paper_space0" ||
        blockName.toLower()=="*paper_space" ||
        blockName.toLower()=="*model_space" ||
        blockName.toLower()=="$paper_space0" ||
        blockName.toLower()=="$paper_space" ||
        blockName.toLower()=="$model_space") {
        return;
    }
    */

    // ignore internal dimension entity blocks:
    if (blockName.toLower().startsWith("*d")) {
        setCurrentBlockId(RBlock::INVALID_ID);
        return;
    }

    // fix invalid block names (mainly from QCAD 2):
    // TODO
//    if (!blockName.startsWith("*")) {
//        QString oldBlockName = blockName;
//        blockName.replace(QRegExp("[<>/\":;?*|,=`\\\\]"), "_");
//        qcad2BlockMapping.insert(oldBlockName, blockName);
//    }

    RVector bp(data.bpx, data.bpy);
    QSharedPointer<RBlock> block(
                new RBlock(
                    document,
                    blockName,
                    bp
                    )
                );

    importObject(block);
    setCurrentBlockId(block->getId());
}

void RDxfImporter::endBlock() {
    setCurrentBlockId(document->getModelSpaceBlockId());
}

void RDxfImporter::endEntity() {
    if (polyline.countVertices()>1) {
        QSharedPointer<RPolylineEntity> entity(new RPolylineEntity(document, RPolylineData(polyline)));
        importEntity(entity);
        polyline = RPolyline();
    }
    if (leader.countVertices()>1) {
        QSharedPointer<RLeaderEntity> entity(new RLeaderEntity(document, leader));
        importEntity(entity);
        leader = RLeaderData();
    }
    if (spline.isValid()) {
//        bool periodic = true;
//        QList<RVector> controlPoints = spline.getControlPoints();
//        QList<double> knots = spline.getKnotVector();

//        for (int i=0; i<spline.getDegree(); i++) {
//            if (controlPoints.at(i).getDistanceTo(controlPoints.at(controlPoints.size()-spline.getDegree()+i)) > RS::PointTolerance) {
//                periodic = false;
//            }
//        }

//        if (periodic) {
//            for (int i=0; i<spline.getDegree(); ++i) {
//                controlPoints.removeLast();
//            }
//            spline.setControlPoints(controlPoints);
//            spline.setPeriodic(true);
//        }
//        else {
//            spline.setControlPoints(controlPoints);
//            spline.setKnotVector(knots);
//        }

        QList<RVector> fitPoints = spline.getFitPoints();
        if (!fitPoints.isEmpty()) {
            // TODO: check for start / end tangent equality if given:
            if (fitPoints.first().getDistanceTo(fitPoints.last()) < RS::PointTolerance) {
                spline.setPeriodic(true);
                //fitPoints.removeLast();
                spline.removeLastFitPoint(true);
            }
        }

        QSharedPointer<RSplineEntity> entity(new RSplineEntity(document, RSplineData(spline)));
        importEntity(entity);
        spline = RSpline();
    }
    if (hatch.getLoopCount()>0) {
        QSharedPointer<RHatchEntity> entity(new RHatchEntity(document, hatch));
        importEntity(entity);
        hatch = RHatchData();
    }
}

void RDxfImporter::endSection() {
    xData.clear();
    xDataAppId = "";
}

void RDxfImporter::importEntity(QSharedPointer<REntity> entity) {
    if (getCurrentBlockId()==RBlock::INVALID_ID) {
        qDebug() << "RDxfImporter::importEntity: ignoring entity";
        return;
    }

    // Layer:
    if (attributes.getLayer().empty()) {
        qWarning() << "RDxfImporter::importEntity: default to layer: '0'";
        entity->setLayerId(document->getLayerId("0"));
    } else {
        // add layer in case it doesn't exist:
        if (document->queryLayer(attributes.getLayer().c_str()).isNull()) {
            qWarning() << "RDxfImporter::importEntity: "
                << "creating layer: " << attributes.getLayer().c_str();
            addLayer(DL_LayerData(attributes.getLayer(), 0));
        }

        entity->setLayerId(document->getLayerId(attributes.getLayer().c_str()));
    }

    // Color:
    RColor col = numberToColor(attributes.getColor());
    RColor col24 = numberToColor24(attributes.getColor24());

    // bylayer / byblock overrules all colors:
    if (col.isByBlock() || col.isByLayer()) {
        entity->setColor(col);
    }
    else {
        // 24 bit colors overrule palette colors:
        if (attributes.getColor24()!=-1) {
            entity->setColor(col24);
        }
        else {
            entity->setColor(col);
        }
    }

    // Linetype:
    QString linetypeName = attributes.getLineType().c_str();
    RLinetype::Id linetypeId = document->getLinetypeId(linetypeName);
    if (linetypeId==RLinetype::INVALID_ID) {
        qWarning() << "RDxfImporter::importEntity: "
            << "unsupported linetype name (defaulting to BYLAYER): "
            << linetypeName;
        linetypeId = document->getLinetypeByLayerId();
    }
    entity->setLinetypeId(linetypeId);

    // Width:
    entity->setLineweight(numberToWeight(attributes.getWidth()));

    int handle = attributes.getHandle();
    if (handle!=-1) {
        document->getStorage().setObjectHandle(*entity, handle);
    }

    // Block:
    entity->setBlockId(getCurrentBlockId());

    if (RSettings::isXDataEnabled()) {
        // TODO:
        //importXData(odEntity, entity);
    }

    importObject(entity);
}

void RDxfImporter::addPoint(const DL_PointData& data) {
    RVector v(data.x, data.y);
    QSharedPointer<RPointEntity> entity(
        new RPointEntity(document, RPointData(v))
    );
    importEntity(entity);
}

void RDxfImporter::addLine(const DL_LineData& data) {
    RVector v1(data.x1, data.y1);
    RVector v2(data.x2, data.y2);
    QSharedPointer<RLineEntity> entity(
        new RLineEntity(document, RLineData(v1, v2))
    );
    importEntity(entity);
}

void RDxfImporter::addArc(const DL_ArcData& data) {
    RVector v(data.cx, data.cy);
    QSharedPointer<RArcEntity> entity(
        new RArcEntity(document,
            RArcData(v, data.radius,
                RMath::deg2rad(data.angle1),
                RMath::deg2rad(data.angle2),
                false)
        )
    );
    importEntity(entity);
}

void RDxfImporter::addEllipse(const DL_EllipseData& data) {
    RVector v1(data.cx, data.cy);
    RVector v2(data.mx, data.my);
    QSharedPointer<REllipseEntity> entity(
        new REllipseEntity(document,
            REllipseData(v1, v2,
                data.ratio,
                data.angle1,
                data.angle2,
                false)
        )
    );
    importEntity(entity);
}

void RDxfImporter::addCircle(const DL_CircleData& data) {
    RVector v(data.cx, data.cy);
    QSharedPointer<RCircleEntity> entity(
        new RCircleEntity(document,
            RCircleData(v, data.radius)
        )
    );
    importEntity(entity);
}

void RDxfImporter::addPolyline(const DL_PolylineData& data) {
    polyline = RPolyline();
    polyline.setClosed(data.flags&0x1);
}

void RDxfImporter::addVertex(const DL_VertexData& data) {
    RVector v(data.x, data.y);
    polyline.appendVertex(v, data.bulge);
}

void RDxfImporter::addSpline(const DL_SplineData& data) {
    if (data.degree<=1 || data.degree>3) {
        qWarning() << "RDxfImporter::addSpline: invalid spline degree: " << data.degree;
        return;
    }

    spline.setDegree(data.degree);
    //spline.setPeriodic(data.flags&0x2);
    spline.setPeriodic(false);
    RVector tanS(data.tangentStartX, data.tangentStartY, data.tangentStartZ);
    RVector tanE(data.tangentEndX, data.tangentEndY, data.tangentEndZ);
    if (tanS.getMagnitude()>RS::PointTolerance) {
        spline.setTangentAtStart(tanS);
    }
    if (tanE.getMagnitude()>RS::PointTolerance) {
        spline.setTangentAtEnd(tanE);
    }
}

void RDxfImporter::addControlPoint(const DL_ControlPointData& data) {
    RVector v(data.x, data.y);

    // weight is ignored for now:
    //double w = data.w;

    spline.appendControlPoint(v);
}

void RDxfImporter::addFitPoint(const DL_FitPointData& data) {
    RVector v(data.x, data.y);

    spline.appendFitPoint(v);
}

void RDxfImporter::addKnot(const DL_KnotData& data) {
//    printf("add knot\n");
}

void RDxfImporter::addInsert(const DL_InsertData& data) {
    QString blockName = data.name.c_str();
    if (blockName.left(3)=="A$C") {
        return;
    }

    RBlock::Id blockId = document->getBlockId(blockName);
    if (blockId==RBlock::INVALID_ID) {
        qWarning() << "RDxfImporter::import: "
                   << "block reference references invalid block: " << blockName;
        return;
    }

    RVector insertionPoint(data.ipx, data.ipy);
    RVector scale(data.sx, data.sy);

    QSharedPointer<RBlockReferenceEntity> entity(
            new RBlockReferenceEntity(
                    document,
                    RBlockReferenceData(
                            blockId,
                            insertionPoint,
                            scale,
                            RMath::deg2rad(data.angle)
                    )
            )
    );
    importEntity(entity);
}

void RDxfImporter::addSolid(const DL_SolidData& data) {
    RVector v1(data.x[0], data.y[0], data.z[0]);
    RVector v2(data.x[1], data.y[1], data.z[1]);
    RVector v3(data.x[2], data.y[2], data.z[2]);
    RVector v4(data.x[3], data.y[3], data.z[3]);

    RSolidData d;
    if (v3.getDistanceTo(v4) < RS::PointTolerance) {
        // last two vertices identical: triangle:
        d = RSolidData(v1, v2, v3);
    }
    else {
        d = RSolidData(v1, v2, v3, v4);
    }

    QSharedPointer<RSolidEntity> entity(new RSolidEntity(document, d));
    importEntity(entity);
}

void RDxfImporter::addTextStyle(const DL_StyleData& data) {
    QString xDataFont = getXDataString("ACAD", 1000, 0);
    int xDataFlags = getXDataInt("ACAD", 1071, 0);

    RDxfTextStyle s;

    s.font = data.primaryFontFile.c_str();
    if (s.font.isEmpty()) {
        s.font = xDataFont;
    }

    s.italic = xDataFlags&0x1000000;
    s.bold = xDataFlags&0x2000000;

    textStyles.insert(QString(data.name.c_str()), s);
}

void RDxfImporter::addMTextChunk(const std::string& text) {
    mtext.append(text.c_str());
}

void RDxfImporter::addMText(const DL_MTextData& data) {
    RVector ip(data.ipx, data.ipy);
    //RVector dirx(data.dirx, data.diry);
    RS::VAlign valign;
    RS::HAlign halign;
    RS::TextDrawingDirection dir;
    RS::TextLineSpacingStyle lss;

    RDxfTextStyle s = textStyles.value(data.style.c_str(), RDxfTextStyle());

    // QCAD 2 compat: use style name as font name:
    if (s.font.isEmpty()) {
        s.font = data.style.c_str();
    }

    if (data.attachmentPoint<=3) {
        valign=RS::VAlignTop;
    } else if (data.attachmentPoint<=6) {
        valign=RS::VAlignMiddle;
    } else {
        valign=RS::VAlignBottom;
    }

    if (data.attachmentPoint%3==1) {
        halign=RS::HAlignLeft;
    } else if (data.attachmentPoint%3==2) {
        halign=RS::HAlignCenter;
    } else {
        halign=RS::HAlignRight;
    }

    if (data.drawingDirection==1) {
        dir = RS::LeftToRight;
    } else if (data.drawingDirection==3) {
        dir = RS::TopToBottom;
    } else {
        dir = RS::ByStyle;
    }

    if (data.lineSpacingStyle==1) {
        lss = RS::AtLeast;
    } else {
        lss = RS::Exact;
    }

    mtext.append(data.text.c_str());
    mtext.replace(QByteArray("^ "), QByteArray("^"));
    QString mtextString = QString(mtext);
    //mtextString.replace("^ ", "^");

    QVariant vDwgCodePage = document->getKnownVariable(RS::DWGCODEPAGE);
    if (vDwgCodePage.isValid()) {
        QString dwgCodePage = vDwgCodePage.toString();
        QString enc = getEncoding(dwgCodePage);

        // get the text codec:
        QTextCodec* codec = QTextCodec::codecForName(enc.toLatin1());
        if (codec!=NULL) {
            mtextString = codec->toUnicode(mtext);
        }
        else {
            qWarning() << "RDxfImporter::addMText: unsupported text codec: " << enc;
        }
    }

    // use default style for the drawing:
    if (s.font.isEmpty()) {
        // japanese, cyrillic:
        QString codepage = document->getKnownVariable(RS::DWGCODEPAGE, "ANSI_1252").toString().toUpper();
        if (codepage=="ANSI_932" || codepage=="ANSI_1251") {
            s.font = "Unicode";
        } else {
            s.font = document->getKnownVariable(RS::TEXTSTYLE, "Standard").toString();
        }
    }

    dxfServices.fixQCad2String(mtextString);

    RTextData d(
        RVector::invalid, ip,
        data.height, data.width,
        valign, halign,
        dir, lss,
        data.lineSpacingFactor,
        mtextString, s.font,
        s.bold,
        s.italic,
        data.angle,
        false
    );

    QSharedPointer<RTextEntity> entity(new RTextEntity(document, d));
    importEntity(entity);

    mtext = "";
}

/**
 * Implementation of the method which handles
 * texts (TEXT).
 */
void RDxfImporter::addText(const DL_TextData& data) {
    RS::VAlign valign;
    RS::HAlign halign;
    RVector refPoint;
    double angle = data.angle;

    RDxfTextStyle s = textStyles.value(data.style.c_str(), RDxfTextStyle());

    // QCAD 2 compat: use style name as font name:
    if (s.font.isEmpty()) {
        s.font = data.style.c_str();
    }

    // baseline has 5 vertical alignment modes:
    if (data.vJustification!=0 || data.hJustification!=0) {
        switch (data.hJustification) {
        default:
        case 0: // left aligned
            halign = RS::HAlignLeft;
            refPoint = RVector(data.apx, data.apy);
            break;
        case 1: // centered
            halign = RS::HAlignCenter;
            refPoint = RVector(data.apx, data.apy);
            break;
        case 2: // right aligned
            halign = RS::HAlignRight;
            refPoint = RVector(data.apx, data.apy);
            break;
        case 3: // aligned (TODO)
            halign = RS::HAlignCenter;
            refPoint = RVector((data.ipx+data.apx)/2.0,
                                 (data.ipy+data.apy)/2.0);
            angle =
                RVector(data.ipx, data.ipy).getAngleTo(
                    RVector(data.apx, data.apy));
            break;
        case 4: // Middle (TODO)
            halign = RS::HAlignCenter;
            refPoint = RVector(data.apx, data.apy);
            break;
        case 5: // fit (TODO)
            halign = RS::HAlignCenter;
            refPoint = RVector((data.ipx+data.apx)/2.0,
                                 (data.ipy+data.apy)/2.0);
            angle =
                RVector(data.ipx, data.ipy).getAngleTo(
                    RVector(data.apx, data.apy));
            break;
        }

        switch (data.vJustification) {
        default:
        case 0: // baseline
            valign = RS::VAlignBase;
            break;

        case 1: // bottom
            valign = RS::VAlignBottom;
            break;

        case 2: // middle
            valign = RS::VAlignMiddle;
            break;

        case 3: // top
            valign = RS::VAlignTop;
            break;
        }
    } else {
        halign = RS::HAlignLeft;
        valign = RS::VAlignBottom;
        refPoint = RVector(data.ipx, data.ipy);
    }

    //int drawingDirection = 5;
    double width = 100.0;

    RTextData d(
        RVector::invalid, refPoint,
        data.height, width,
        valign, halign,
        RS::LeftToRight, RS::Exact,
        1.0,
        data.text.c_str(), s.font,
        s.bold,                      // bold
        s.italic,                    // italic
        data.angle,
        true                         // simple
    );

    QSharedPointer<RTextEntity> entity(new RTextEntity(document, d));
    importEntity(entity);
}

RDimensionData RDxfImporter::convDimensionData(const DL_DimensionData& data) {
    RVector defP(data.dpx, data.dpy);
    RVector midP(data.mpx, data.mpy);
    RS::VAlign valign;
    RS::HAlign halign;
    RS::TextLineSpacingStyle lss;

    QString t;

    if (dxfServices.getQCad2Compatibility()) {
        // middlepoint of text can be 0/0 which is considered to be invalid (!):
        //  because older QCad 1 versions save the middle of the text as 0/0
        //  althought they didn't support custom text positions.
        if (fabs(data.mpx)<1.0e-6 && fabs(data.mpy)<1.0e-6) {
            midP = RVector::invalid;
        }
    }

    // auto positioned:
    if ((data.type&0x80)==0) {
        midP = RVector::invalid;
    }

    if (data.attachmentPoint<=3) {
        valign=RS::VAlignTop;
    } else if (data.attachmentPoint<=6) {
        valign=RS::VAlignMiddle;
    } else {
        valign=RS::VAlignBottom;
    }

    if (data.attachmentPoint%3==1) {
        halign=RS::HAlignLeft;
    } else if (data.attachmentPoint%3==2) {
        halign=RS::HAlignCenter;
    } else {
        halign=RS::HAlignRight;
    }

    if (data.lineSpacingStyle==1) {
        lss = RS::AtLeast;
    } else {
        lss = RS::Exact;
    }

    t = data.text.c_str();
    t.replace("^ ", "^");
    dxfServices.fixQCad2String(t);

    // data needed to add the actual dimension entity
    RDimensionData ret(defP, midP,
                            valign, halign,
                            lss,
                            data.lineSpacingFactor,
                            t, "standard",
                            data.angle);

    if (midP.isValid()) {
        ret.setCustomTextPosition(true);
    }

    dxfServices.fixDimensionLabel(ret);
    return ret;
}

void RDxfImporter::addDimAlign(const DL_DimensionData& data, const DL_DimAlignedData& edata) {
    RDimensionData dimData = convDimensionData(data);

    RVector ext1(edata.epx1, edata.epy1);
    RVector ext2(edata.epx2, edata.epy2);

    RDimAlignedData d(dimData, ext1, ext2);

    QSharedPointer<RDimAlignedEntity> entity(new RDimAlignedEntity(document, d));
    importEntity(entity);
}

void RDxfImporter::addDimLinear(const DL_DimensionData& data,
                                const DL_DimLinearData& edata) {
    RDimensionData dimData = convDimensionData(data);

    RVector dxt1(edata.dpx1, edata.dpy1);
    RVector dxt2(edata.dpx2, edata.dpy2);

    RDimRotatedData d(dimData, dxt1, dxt2, RMath::deg2rad(edata.angle));

    QSharedPointer<RDimRotatedEntity> entity(new RDimRotatedEntity(document, d));
    importEntity(entity);
}

void RDxfImporter::addDimRadial(const DL_DimensionData& data,
                                const DL_DimRadialData& edata) {
    RDimensionData dimData = convDimensionData(data);
    RVector dp(edata.dpx, edata.dpy);

    RDimRadialData d(dimData, dp);

    QSharedPointer<RDimRadialEntity> entity(new RDimRadialEntity(document, d));
    importEntity(entity);
}

void RDxfImporter::addDimDiametric(const DL_DimensionData& data,
                                   const DL_DimDiametricData& edata) {
    RDimensionData dimData = convDimensionData(data);
    RVector dp(edata.dpx, edata.dpy);

    RDimDiametricData d(dimData, dp);

    QSharedPointer<RDimDiametricEntity> entity(new RDimDiametricEntity(document, d));
    importEntity(entity);
}

void RDxfImporter::addDimAngular(const DL_DimensionData& data,
                                 const DL_DimAngularData& edata) {
    RDimensionData dimData = convDimensionData(data);
    RVector dp1(edata.dpx1, edata.dpy1);
    RVector dp2(edata.dpx2, edata.dpy2);
    RVector dp3(edata.dpx3, edata.dpy3);
    RVector dp4(edata.dpx4, edata.dpy4);

    RDimAngularData d(dimData, dp1, dp2, dp3, dp4);

    QSharedPointer<RDimAngularEntity> entity(new RDimAngularEntity(document, d));
    importEntity(entity);
}

void RDxfImporter::addDimAngular3P(const DL_DimensionData& data,
                                   const DL_DimAngular3PData& edata) {
    RDimensionData dimData = convDimensionData(data);
    RVector dp1(edata.dpx3, edata.dpy3);
    RVector dp2(edata.dpx1, edata.dpy1);
    RVector dp3(edata.dpx3, edata.dpy3);
    RVector dp4 = dimData.getDefinitionPoint();
    dimData.setDefinitionPoint(RVector(edata.dpx2, edata.dpy2));

    RDimAngularData d(dimData, dp1, dp2, dp3, dp4);

    QSharedPointer<RDimAngularEntity> entity(new RDimAngularEntity(document, d));
    importEntity(entity);
}

void RDxfImporter::addDimOrdinate(const DL_DimensionData& data,
                               const DL_DimOrdinateData& edata) {
    RDimensionData dimData = convDimensionData(data);
    RVector definingPoint(edata.dpx1, edata.dpy1);
    RVector leaderEndPoint(edata.dpx2, edata.dpy2);

    RDimOrdinateData d(dimData, leaderEndPoint, definingPoint);
    if (edata.xtype) {
        d.setMeasuringXAxis();
    }
    else {
        d.setMeasuringYAxis();
    }

    QSharedPointer<RDimOrdinateEntity> entity(new RDimOrdinateEntity(document, d));
    importEntity(entity);
}

void RDxfImporter::addLeader(const DL_LeaderData& data) {
    leader = RLeaderData();
    leader.setArrowHead(data.arrowHeadFlag==1);
}

void RDxfImporter::addLeaderVertex(const DL_LeaderVertexData& data) {
    RVector v(data.x, data.y);
    leader.appendVertex(v);
}

void RDxfImporter::addHatch(const DL_HatchData& data) {
    hatch = RHatchData(data.solid,
                       data.scale,
                       RMath::deg2rad(data.angle),
                       data.pattern.c_str());

    if (dxfServices.getQCad2Compatibility()) {
        dxfServices.fixQCad2HatchData(hatch);
    }
}

void RDxfImporter::addHatchLoop(const DL_HatchLoopData& data) {
    hatch.newLoop();
}

void RDxfImporter::addHatchEdge(const DL_HatchEdgeData& data) {
    QSharedPointer<RShape> shape;

    switch (data.type) {
    case 0: {
        RPolyline pl;
        for (int i=0; i<data.vertices.size(); i++) {
            if (data.vertices[i].size()==2) {
                pl.appendVertex(RVector(data.vertices[i][0], data.vertices[i][1]));
            }
            else if (data.vertices[i].size()==3) {
                pl.appendVertex(RVector(data.vertices[i][0], data.vertices[i][1]), data.vertices[i][2]);
            }
        }
        pl.setClosed(true);
        shape = QSharedPointer<RShape>(new RPolyline(pl));
        } break;

    case 1:
        shape = QSharedPointer<RShape>(
            new RLine(RVector(data.x1, data.y1),
                      RVector(data.x2, data.y2))
        );
        break;

    case 2:
        if (data.ccw && data.angle1<RS::AngleTolerance && data.angle2>2*M_PI-RS::AngleTolerance) {
            shape = QSharedPointer<RShape>(
                new RCircle(RVector(data.cx, data.cy), data.radius)
            );
        } else {
            if (data.ccw) {
                shape = QSharedPointer<RShape>(
                    new RArc(RVector(data.cx, data.cy),
                             data.radius,
                             RMath::getNormalizedAngle(data.angle1),
                             RMath::getNormalizedAngle(data.angle2),
                             false)
                );
            } else {
                shape = QSharedPointer<RShape>(
                    new RArc(RVector(data.cx, data.cy),
                             data.radius,
                             RMath::getNormalizedAngle(2*M_PI-data.angle1),
                             RMath::getNormalizedAngle(2*M_PI-data.angle2),
                             true)
                );
            }
        }
        break;

    case 3:
        if (!data.ccw) {
            REllipse* el = new REllipse(RVector(data.cx, data.cy),
                         RVector(data.mx, data.my),
                         data.ratio,
                         0.0,
                         0.0,
                         true);
            el->setStartAngle(-data.angle1);
            el->setEndAngle(-data.angle2);
            shape = QSharedPointer<RShape>(el);
        }
        else {
            REllipse* el = new REllipse(RVector(data.cx, data.cy),
                             RVector(data.mx, data.my),
                             data.ratio,
                             0.0,
                             0.0,
                             false);
            el->setStartAngle(data.angle1);
            el->setEndAngle(data.angle2);
            shape = QSharedPointer<RShape>(el);
        }
        break;

    case 4: {
        RSpline* s = new RSpline();

        s->setDegree(data.degree);
        QList<RVector> controlPoints;
        for (int i=0; i<data.controlPoints.size(); i++) {
            RVector v(data.controlPoints[i][0], data.controlPoints[i][1]);
            controlPoints.append(v);
        }
        QList<double> knots;
        for (int i=0; i<data.knots.size(); i++) {
            knots.append(data.knots[i]);
        }
        //Q_ASSERT(data.degree + 1 + controlPoints.size() == knots.size());

        bool periodic = true;
        for (int i=0; i<data.degree; i++) {
            if (controlPoints.at(i).getDistanceTo(controlPoints.at(controlPoints.size()-data.degree+i)) > RS::PointTolerance) {
                periodic = false;
                break;
            }
        }

        if (periodic) {
            for (int i=0; i<data.degree; ++i) {
                controlPoints.removeLast();
            }
            s->setControlPoints(controlPoints);
            s->setPeriodic(true);
        }
        else {
            s->setControlPoints(controlPoints);
            knots.removeFirst();
            knots.removeLast();
            s->setKnotVector(knots);
        }

        shape = QSharedPointer<RShape>(s);
        }
        break;

    default:
        break;
    }

    if (!shape.isNull()) {
        hatch.addBoundary(shape);
    }
}

void RDxfImporter::addImage(const DL_ImageData& data) {
    int handle = QString(data.ref.c_str()).toInt(NULL, 16);
    RVector ip(data.ipx, data.ipy);
    RVector uv(data.ux, data.uy);
    RVector vv(data.vx, data.vy);

    RImageData d("", ip, uv, vv, data.brightness, data.contrast, data.fade);

    QSharedPointer<RImageEntity> entity(new RImageEntity(document, d));
    importEntity(entity);
    images.insertMulti(handle, entity->getId());
}

void RDxfImporter::linkImage(const DL_ImageDefData& data) {
    int handle = QString(data.ref.c_str()).toInt(NULL, 16);

    if (!images.contains(handle)) {
        qWarning() << "unused image definition: " << data.ref.c_str();
        return;
    }

    QString filePath = data.file.c_str();

    QList<RObject::Id> imageData = images.values(handle);
    for (int i=0; i<imageData.length(); i++) {
        RObject::Id id = imageData.at(i);
        QSharedPointer<REntity> entity = document->queryEntity(id);
        if (entity.isNull()) {
            continue;
        }
        QSharedPointer<RImageEntity> image = entity.dynamicCast<RImageEntity>();
        if (image.isNull()) {
            continue;
        }
        //image->setFileName(fi.absoluteFilePath());
        image->setFileName(filePath);
        importObject(image);
    }

    images.remove(handle);
}

void RDxfImporter::addXRecord(const std::string& handle) {
    if (qcadDict.count(handle.c_str())==1) {
        variableKey = qcadDict[handle.c_str()];
    }
}

void RDxfImporter::addXRecordString(int code, const std::string& value) {
    if (variableKey.isEmpty()) {
        return;
    }
    document->setVariable(variableKey, value.c_str());
}

void RDxfImporter::addXRecordReal(int code, double value) {
    if (variableKey.isEmpty()) {
        return;
    }
    document->setVariable(variableKey, value);
}

void RDxfImporter::addXRecordInt(int code, int value) {
    if (variableKey.isEmpty()) {
        return;
    }
    document->setVariable(variableKey, value);
}

void RDxfImporter::addXRecordBool(int code, bool value) {
    if (variableKey.isEmpty()) {
        return;
    }
    document->setVariable(variableKey, value);
}

void RDxfImporter::addXDataApp(const std::string& appId) {
    xDataAppId = appId.c_str();
    xData.insert(xDataAppId, QList<QPair<int, QVariant> >());
}

void RDxfImporter::addXDataString(int code, const std::string& value) {
    if (!xData.contains(xDataAppId)) {
        qWarning() << "RDxfImporter::addXDataString: app ID not found: " << xDataAppId;
        return;
    }

    xData[xDataAppId].append(QPair<int, QVariant>(code, value.c_str()));
}

void RDxfImporter::addXDataReal(int code, double value) {
    if (!xData.contains(xDataAppId)) {
        qWarning() << "RDxfImporter::addXDataString: app ID not found: " << xDataAppId;
        return;
    }

    xData[xDataAppId].append(QPair<int, QVariant>(code, value));
}

void RDxfImporter::addXDataInt(int code, int value) {
    if (!xData.contains(xDataAppId)) {
        qWarning() << "RDxfImporter::addXDataString: app ID not found: " << xDataAppId;
        return;
    }

    xData[xDataAppId].append(QPair<int, QVariant>(code, value));
}

void RDxfImporter::addDictionary(const DL_DictionaryData& data) {
    if (qcadDictHandle==data.handle.c_str()) {
        inDict = true;
    }
}

void RDxfImporter::addDictionaryEntry(const DL_DictionaryEntryData& data) {
    if (data.name=="QCAD_OBJECTS") {
        qcadDictHandle = data.handle.c_str();
        return;
    }

    if (inDict) {
        qcadDict[data.handle.c_str()] = data.name.c_str();
    }
}

void RDxfImporter::setVariableVector(const std::string& key,
                                     double v1, double v2, double v3, int code) {

    RS::KnownVariable v = dxfServices.stringToVariable(key.c_str());
    if (v!=RS::INVALID) {
        document->setKnownVariable(v, RVector(v1, v2, v3));
    }
}

void RDxfImporter::setVariableString(const std::string& key,
                                     const std::string& value, int code) {
    RS::KnownVariable v = dxfServices.stringToVariable(key.c_str());
    if (v!=RS::INVALID) {
        document->setKnownVariable(v, value.c_str());
    }
}

void RDxfImporter::setVariableInt(const std::string& key, int value, int code) {
    RS::KnownVariable v = dxfServices.stringToVariable(key.c_str());
    if (v!=RS::INVALID) {
        document->setKnownVariable(v, value);
    }
}

void RDxfImporter::setVariableDouble(const std::string& key, double value, int code) {
    RS::KnownVariable v = dxfServices.stringToVariable(key.c_str());
    if (v!=RS::INVALID) {
        document->setKnownVariable(v, value);
    }
}

/**
 * Tries to convert the given DXF encoding string to an encoding recognized by Qt.
 */
QString RDxfImporter::getEncoding(const QString& str) {
    QString l=str.toLower();

    if (l=="latin1" || l=="ansi_1252" || l=="iso-8859-1" ||
            l=="cp819" || l=="csiso" || l=="ibm819" || l=="iso_8859-1" ||
            l=="iso8859-1" || l=="iso-ir-100" || l=="l1") {
        return "Latin1";
    } else if (l=="big5" || l=="ansi_950" || l=="cn-big5" || l=="csbig5" ||
               l=="x-x-big5") {
        return "Big5";
    } else if (l=="big5-hkscs") {
        return "Big5-HKSCS";
    } else if (l=="eucjp" || l=="euc-jp" || l=="cseucpkdfmtjapanese" ||
               l=="x-euc" || l=="x-euc-jp") {
        return "eucJP";
    } else if (l=="euckr") {
        return "eucKR";
    } else if (l=="gb2312" || l=="gb2312" || l=="chinese" || l=="cn-gb" ||
               l=="csgb2312" || l=="csgb231280" || l=="csiso58gb231280" ||
               l=="gb_2312-80" || l=="gb231280" || l=="gb2312-80" || l=="gbk" ||
               l=="iso-ir-58") {
        return "GB2312";
    } else if (l=="gbk") {
        return "GBK";
    } else if (l=="gb18030") {
        return "GB18030";
    } else if (l=="jis7") {
        return "JIS7";
    } else if (l=="shift-jis" || l=="ansi_932" || l=="shift_jis" || l=="csShiftJIS" ||
               l=="cswindows31j" || l=="ms_kanji" || l=="x-ms-cp932" || l=="x-sjis") {
        return "Shift-JIS";
    } else if (l=="tscii") {
        return "TSCII";
    } else if (l=="utf88-bit") {
        return "utf88-bit";
    } else if (l=="utf16") {
        return "utf16";
    } else if (l=="koi8-r") {
        return "KOI8-R";
    } else if (l=="koi8-u") {
        return "KOI8-U";
    } else if (l=="iso8859-1") {
        return "ISO8859-1";
    } else if (l=="iso8859-2") {
        return "ISO8859-2";
    } else if (l=="iso8859-3") {
        return "ISO8859-3";
    } else if (l=="iso8859-4" || l=="ansi_1257") {
        return "ISO8859-4";
    } else if (l=="iso8859-5") {
        return "ISO8859-5";
    } else if (l=="iso8859-6" || l=="ansi_1256") {
        return "ISO8859-6";
    } else if (l=="iso8859-7" || l=="ansi_1253") {
        return "ISO8859-7";
    } else if (l=="iso8859-8") {
        return "ISO8859-8";
    } else if (l=="iso8859-8-i" || l=="ansi_1255") {
        return "ISO8859-8-i";
    } else if (l=="iso8859-9" || l=="ansi_1254") {
        return "ISO8859-9";
    } else if (l=="iso8859-10") {
        return "ISO8859-10";
    } else if (l=="iso8859-13") {
        return "ISO8859-13";
    } else if (l=="iso8859-14") {
        return "ISO8859-14";
    } else if (l=="iso8859-15") {
        return "ISO8859-15";
    } else if (l=="ibm 850") {
        return "IBM 850";
    } else if (l=="ibm 866") {
        return "IBM 866";
    } else if (l=="cp874") {
        return "CP874";
    } else if (l=="cp1250") {
        return "CP1250";
    } else if (l=="cp1251") {
        return "CP1251";
    } else if (l=="cp1252") {
        return "CP1252";
    } else if (l=="cp1253") {
        return "CP1253";
    } else if (l=="cp1254") {
        return "CP1254";
    } else if (l=="cp1255") {
        return "CP1255";
    } else if (l=="cp1256") {
        return "CP1256";
    } else if (l=="cp1257") {
        return "CP1257";
    } else if (l=="cp1258") {
        return "CP1258";
    } else if (l=="apple roman") {
        return "Apple Roman";
    } else if (l=="tis-620") {
        return "TIS-620";
    }

    return "Latin1";
}

QString RDxfImporter::getXDataString(const QString& appId, int code, int pos) {
    if (!xData.contains(appId)) {
        return QString::null;
    }

    int c = 0;
    for (int i=0; i<xData[appId].count(); i++) {
        if (c==pos && xData[appId][i].first==code) {
            return xData[appId][i].second.toString();
        }
    }

    return QString::null;
}

int RDxfImporter::getXDataInt(const QString& appId, int code, int pos) {
    if (!xData.contains(appId)) {
        return 0;
    }

    int c = 0;
    for (int i=0; i<xData[appId].count(); i++) {
        if (c==pos && xData[appId][i].first==code) {
            return xData[appId][i].second.toInt();
        }
    }

    return 0;
}
