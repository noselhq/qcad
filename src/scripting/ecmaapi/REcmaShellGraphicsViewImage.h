


	// ***** AUTOGENERATED CODE, DO NOT EDIT *****
    
        #ifndef RECMASHELLGRAPHICSVIEWIMAGE_H
        #define RECMASHELLGRAPHICSVIEWIMAGE_H

        #include <QScriptEngine>
        #include <QScriptValue>
        #include <QScriptContextInfo>
        #include <QDebug>

        
                #include "RGraphicsViewImage.h"
            

        /**
         * \ingroup scripting_ecmaapi
         */
        class REcmaShellGraphicsViewImage : public RGraphicsViewImage {

        public:
      
    // Destructor:
    
            ~REcmaShellGraphicsViewImage();
        static RGraphicsViewImage* getSelf(const QString& fName, QScriptContext* context)
    ;static REcmaShellGraphicsViewImage* getSelfShell(const QString& fName, QScriptContext* context)
    ;
    
    
    // Constructors:
    
      REcmaShellGraphicsViewImage(
                
            );
        
    
    
      void setViewportNumber(
                int n
            );
        
    
    
      int getViewportNumber(
                
            );
        
    
    
      void setNavigationAction(
                RAction * action
            );
        
    
    
      RBox getBox(
                
            );
        
    
    
      void autoZoom(
                int margin
        = RDEFAULT_MIN1
            );
        
    
    
      void zoomTo(
                const RBox & window, int margin
        = 0
            );
        
    
    
      void zoom(
                const RVector & center, double factor
            );
        
    
    
      void centerToBox(
                const RBox & box
            );
        
    
    
      void centerToPoint(
                const RVector & point
            );
        
    
    
      void setGrid(
                RGrid * grid
            );
        
    
    
      RGrid * getGrid(
                
            );
        
    
    
      double getFactor(
                bool includeStepFactor
        =  true
            );
        
    
    
      void setFactor(
                double f, bool regen
        =  true
            );
        
    
    
      RVector getOffset(
                bool includeStepOffset
        =  true
            );
        
    
    
      void setOffset(
                const RVector & offset, bool regen
        =  true
            );
        
    
    
      QColor getBackgroundColor(
                
            );
        
    
    
      void setMargin(
                int m
            );
        
    
    
      void setColorMode(
                RGraphicsView::ColorMode cm
            );
        
    
    
      RGraphicsScene * getScene(
                
            );
        
    
    
      RDocument * getDocument(
                
            );
        
    
    
      RDocumentInterface * getDocumentInterface(
                
            );
        
    
    
      void setDraftMode(
                bool on
            );
        
    
    
      bool getDraftMode(
                
            );
        
    
    
      void setPrinting(
                bool on
            );
        
    
    
      bool isPrinting(
                
            );
        
    
    
      void setPrintPreview(
                bool on
            );
        
    
    
      bool isPrintPreview(
                
            );
        
    
    
      void setPrintPointSize(
                const RVector & s
            );
        
    
    
      void simulateMouseMoveEvent(
                
            );
        
    
    
      void setTextHeightThresholdOverride(
                int v
            );
        
    
    
      int getTextHeightThresholdOverride(
                
            );
        
    
    
      bool isGridVisible(
                
            );
        
    
    
      void setGridVisible(
                bool on
            );
        
    
    
      void setScene(
                RGraphicsSceneQt * scene, bool regen
        =  true
            );
        
    
    
      void setBackgroundColor(
                const QColor & col
            );
        
    
    
      void regenerate(
                bool force
        =  false
            );
        
    
    
      void repaintView(
                
            );
        
    
    
      void updateImage(
                
            );
        
    
    
      bool hasFocus(
                
            );
        
    
    
      void removeFocus(
                
            );
        
    
    
      void saveViewport(
                
            );
        
    
    
      void restoreViewport(
                
            );
        
    
    
      RVector mapFromView(
                const RVector & v, double z
        = 0.0
            );
        
    
    
      RVector mapToView(
                const RVector & v
            );
        
    
    
      double mapDistanceFromView(
                double d
            );
        
    
    
      double mapDistanceToView(
                double d
            );
        
    
    
      int getWidth(
                
            );
        
    
    
      int getHeight(
                
            );
        
    
    
      void resizeImage(
                int w, int h
            );
        
    
    
      void paintGridPoint(
                const RVector & ucsPosition
            );
        
    
    
      void paintGridLine(
                const RLine & ucsPosition
            );
        
    
    
      void setPaintOrigin(
                bool val
            );
        
    
    
      void setAntialiasing(
                bool val
            );
        
    
    
      bool getAntialiasing(
                
            );
        
    
    
      void setPanOptimization(
                bool on
            );
        
    
    
      bool getPanOptimization(
                
            );
        
    
    
      void paintEntities(
                QPainter * painter, const RBox & queryBox
            );
        
    
    
      void paintEntity(
                QPainter * painter, REntity::Id id
            );
        
    
    
      QImage getBuffer(
                
            );
        
    
    
      QTransform getTransform(
                
            );
        
    
    
      void emitUpdateSnapInfo(
                RSnap * snap, RSnapRestriction * restriction
            );
        
    
    
      void emitUpdateTextLabel(
                const RTextLabel & textLabel
            );
        
    
    
      void emitDecorateBackground(
                QPainter * painter
            );
        
    
    
      void emitDecorateForeground(
                QPainter * painter
            );
        
    
    
      void clearBackground(
                
            );
        
    
    
      void addToBackground(
                const RPainterPath & path
            );
        
    
    
      void setBackgroundTransform(
                double bgFactor, const RVector & bgOffset
            );
        
    
    
      void setColorCorrectionOverride(
                bool on
            );
        
    
    
      bool getColorCorrectionOverride(
                
            );
        
    
    
      void paintImage(
                QPainter * painter, RImageData & image
            );
        
    
    
      void paintOrigin(
                QPaintDevice & device
            );
        
    
    
      void paintCursor(
                QPaintDevice & device
            );
        
    
    
      void paintRelativeZero(
                QPaintDevice & device
            );
        
    
    
      void invalidate(
                bool force
        =  false
            );
        
    
    
      void updateGraphicsBuffer(
                
            );
        
    
    
      void updateTransformation(
                
            );
        
    
  
        // methods of 1st level base class RGraphicsView:
        
      void clearCaches(
                
            );
        
    
      void setDisplayOnlyCurrentUcs(
                bool on
            );
        
    
      QList < RVector > mapCornersFromView(
                
            );
        
    
      RVector getMinimum(
                
            );
        
    
      RVector getMaximum(
                
            );
        
    
      void handleTerminateEvent(
                RTerminateEvent & event
            );
        
    
      void handleKeyPressEvent(
                QKeyEvent & event
            );
        
    
      void handleKeyReleaseEvent(
                QKeyEvent & event
            );
        
    
      void handleMouseMoveEvent(
                RMouseEvent & event
            );
        
    
      void handleMousePressEvent(
                RMouseEvent & event
            );
        
    
      void handleMouseReleaseEvent(
                RMouseEvent & event
            );
        
    
      void handleMouseDoubleClickEvent(
                RMouseEvent & event
            );
        
    
      void handleWheelEvent(
                RWheelEvent & event
            );
        
    
      void handleTabletEvent(
                RTabletEvent & event
            );
        
    
      void handleSwipeGestureEvent(
                QSwipeGesture & gesture
            );
        
    
      void handlePanGestureEvent(
                QPanGesture & gesture
            );
        
    
      void handlePinchGestureEvent(
                QPinchGesture & gesture
            );
        
    
      void viewportChangeEvent(
                
            );
        
    
      void zoomIn(
                
            );
        
      void zoomIn(
                const RVector & center
            );
        
    
      void zoomOut(
                
            );
        
      void zoomOut(
                const RVector & center
            );
        
    
      void zoomPrevious(
                
            );
        
    
      bool zoomToSelection(
                
            );
        
    
      void pan(
                const RVector & delta
            );
        
    
      void startPan(
                
            );
        
    
      QCursor getCursor(
                
            );
        
    
      void setCursor(
                Qt::CursorShape arg1
            );
        
      void setCursor(
                const QCursor & arg1
            );
        
    
      RVector getClosestReferencePoint(
                const RVector & screenPosition, int range
            );
        
      RVector getClosestReferencePoint(
                REntity::Id entityId, const RVector & screenPosition
            );
        
    
      REntity::Id getClosestEntity(
                const RVector & screenPosition, int range, bool includeLockedLayers
        =  true
            );
        
    
      int getMargin(
                
            );
        
    
      RGraphicsView::ColorMode getColorMode(
                
            );
        
    
      QList < RTextLabel > getTextLabels(
                
            );
        
    
      void clearTextLabels(
                
            );
        
    
      void addTextLabel(
                const RTextLabel & textLabel
            );
        
    
      RVector getLastKnownMousePosition(
                
            );
        
    
      double getCurrentStepScaleFactor(
                
            );
        
    
      void setCurrentStepScaleFactor(
                double f
            );
        
    
      RVector getCurrentStepOffset(
                
            );
        
    
      void setCurrentStepOffset(
                const RVector & s
            );
        
    
      void updateTextHeightThreshold(
                
            );
        
    
      bool isPathVisible(
                const RPainterPath & path
            );
        
    

    // protected methods (only available for ECMA shell classes) (generated by xsl2xpp.xsl):
	static  QScriptValue
        paintImage
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        paintOrigin
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        paintCursor
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        paintRelativeZero
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        invalidate
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        updateGraphicsBuffer
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        updateTransformation
        (QScriptContext* context, QScriptEngine* engine) 
        ;QScriptValue __qtscript_self;
            };
            Q_DECLARE_METATYPE(REcmaShellGraphicsViewImage*)
        
	#endif
    