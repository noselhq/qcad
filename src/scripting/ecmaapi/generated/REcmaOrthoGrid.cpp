// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #include "REcmaOrthoGrid.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
                #include "RGraphicsView.h"
            
                #include "RRuler.h"
            
            
        // includes for base ecma wrapper classes
        
                  #include "REcmaGrid.h"
                 void REcmaOrthoGrid::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (ROrthoGrid*) 0)));
        protoCreated = true;
    }

    
        // primary base class RGrid:
        
            QScriptValue dpt = engine.defaultPrototype(
                qMetaTypeId<RGrid*>());

            if (dpt.isValid()) {
                proto->setPrototype(dpt);
            }
          
        /*
        
        */
    

    QScriptValue fun;

    // toString:
    REcmaHelper::registerFunction(&engine, proto, toString, "toString");
    

    // destroy:
    REcmaHelper::registerFunction(&engine, proto, destroy, "destroy");
    
        // conversion for base class RGrid
        REcmaHelper::registerFunction(&engine, proto, getRGrid, "getRGrid");
        

    // get class name
    REcmaHelper::registerFunction(&engine, proto, getClassName, "getClassName");
    

    // conversion to all base classes (multiple inheritance):
    REcmaHelper::registerFunction(&engine, proto, getBaseClasses, "getBaseClasses");
    

    // properties:
    

    // methods:
    
            REcmaHelper::registerFunction(&engine, proto, clearCache, "clearCache");
            
            REcmaHelper::registerFunction(&engine, proto, snapToGrid, "snapToGrid");
            
            REcmaHelper::registerFunction(&engine, proto, update, "update");
            
            REcmaHelper::registerFunction(&engine, proto, paint, "paint");
            
            REcmaHelper::registerFunction(&engine, proto, paintMetaGrid, "paintMetaGrid");
            
            REcmaHelper::registerFunction(&engine, proto, paintCursor, "paintCursor");
            
            REcmaHelper::registerFunction(&engine, proto, paintRuler, "paintRuler");
            
            REcmaHelper::registerFunction(&engine, proto, getInfoText, "getInfoText");
            
            REcmaHelper::registerFunction(&engine, proto, getIdealSpacing, "getIdealSpacing");
            
            REcmaHelper::registerFunction(&engine, proto, isIsometric, "isIsometric");
            
            REcmaHelper::registerFunction(&engine, proto, setIsometric, "setIsometric");
            
            REcmaHelper::registerFunction(&engine, proto, getProjection, "getProjection");
            
            REcmaHelper::registerFunction(&engine, proto, setProjection, "setProjection");
            
        engine.setDefaultPrototype(
            qMetaTypeId<ROrthoGrid*>(), *proto);

        
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    
            REcmaHelper::registerFunction(&engine, &ctor, getIdealGridSpacing, "getIdealGridSpacing");
            
            REcmaHelper::registerFunction(&engine, &ctor, isFractionalFormat, "isFractionalFormat");
            

    // static properties:
    

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("ROrthoGrid",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaOrthoGrid::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
    if (context->thisObject().strictlyEquals(
       engine->globalObject())) {
       return REcmaHelper::throwError(
       QString::fromLatin1("ROrthoGrid(): Did you forget to construct with 'new'?"),
           context);
    }

    QScriptValue result;
        
            // generate constructor variants:
            
    if( context->argumentCount() ==
        1
                && (
                
                        context->argument(
                        0
                        ).isVariant()
                        ||
                    
                        context->argument(
                        0
                        ).isQObject()
                        ||
                    
                        context->argument(
                        0
                        ).isNull()
                ) /* type: RGraphicsView */
            
    ){
    // prepare arguments:
    
                    // argument is reference
                    RGraphicsView*
                    ap0 =
                    qscriptvalue_cast<
                    RGraphicsView*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if( ap0 == NULL ){
                           return REcmaHelper::throwError("ROrthoGrid: Argument 0 is not of type RGraphicsView*.",
                               context);                    
                    }
                    RGraphicsView& a0 = *ap0;
                
    // end of arguments

    // call C++ constructor:
    
            // non-copyable class:
            ROrthoGrid
                    * cppResult =
                    new
                    ROrthoGrid
                    (
                    a0
                    );
                
                    // TODO: triggers: Warning: QScriptEngine::newVariant(): changing class of non-QScriptObject not supported:
                    result = engine->newVariant(context->thisObject(), qVariantFromValue(cppResult));
                
    } else 

    {
       return REcmaHelper::throwError(
       QString::fromLatin1("ROrthoGrid(): no matching constructor found."),
           context);
    }
    
    return result;
    }
    

    // conversion functions for base classes:
     QScriptValue REcmaOrthoGrid::getRGrid(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                RGrid* cppResult =
                    qscriptvalue_cast<ROrthoGrid*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
            

    // returns class name:
     QScriptValue REcmaOrthoGrid::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("ROrthoGrid"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaOrthoGrid::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        
        list.append("RGrid");
    

        return qScriptValueFromSequence(engine, list);
    }
    

    // properties:
    

    // public methods:
     QScriptValue
        REcmaOrthoGrid::clearCache
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOrthoGrid::clearCache", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOrthoGrid::clearCache";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROrthoGrid* self = 
                        getSelf("clearCache", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->clearCache();
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROrthoGrid.clearCache().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOrthoGrid::clearCache", context, engine);
            return result;
        }
         QScriptValue
        REcmaOrthoGrid::snapToGrid
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOrthoGrid::snapToGrid", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOrthoGrid::snapToGrid";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROrthoGrid* self = 
                        getSelf("snapToGrid", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RVector */
    
    ){
    // prepare arguments:
    
                    // argument isCopyable and has default constructor and isSimpleClass 
                    RVector*
                    ap0 =
                    qscriptvalue_cast<
                    RVector*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if (ap0 == NULL) {
                           return REcmaHelper::throwError("ROrthoGrid: Argument 0 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a0 = 
                    *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'RVector'
    RVector cppResult =
        
               self->snapToGrid(a0);
        // return type: RVector
                // not standard type nor reference
                result = qScriptValueFromValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROrthoGrid.snapToGrid().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOrthoGrid::snapToGrid", context, engine);
            return result;
        }
         QScriptValue
        REcmaOrthoGrid::update
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOrthoGrid::update", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOrthoGrid::update";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROrthoGrid* self = 
                        getSelf("update", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->update();
    } else


        
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isBool()
        ) /* type: bool */
    
    ){
    // prepare arguments:
    
                    // argument isStandardType
                    bool
                    a0 =
                    (bool)
                    
                    context->argument( 0 ).
                    toBool();
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->update(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROrthoGrid.update().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOrthoGrid::update", context, engine);
            return result;
        }
         QScriptValue
        REcmaOrthoGrid::paint
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOrthoGrid::paint", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOrthoGrid::paint";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROrthoGrid* self = 
                        getSelf("paint", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->paint();
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROrthoGrid.paint().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOrthoGrid::paint", context, engine);
            return result;
        }
         QScriptValue
        REcmaOrthoGrid::paintMetaGrid
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOrthoGrid::paintMetaGrid", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOrthoGrid::paintMetaGrid";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROrthoGrid* self = 
                        getSelf("paintMetaGrid", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->paintMetaGrid();
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROrthoGrid.paintMetaGrid().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOrthoGrid::paintMetaGrid", context, engine);
            return result;
        }
         QScriptValue
        REcmaOrthoGrid::paintCursor
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOrthoGrid::paintCursor", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOrthoGrid::paintCursor";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROrthoGrid* self = 
                        getSelf("paintCursor", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RVector */
    
    ){
    // prepare arguments:
    
                    // argument isCopyable and has default constructor and isSimpleClass 
                    RVector*
                    ap0 =
                    qscriptvalue_cast<
                    RVector*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if (ap0 == NULL) {
                           return REcmaHelper::throwError("ROrthoGrid: Argument 0 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a0 = 
                    *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->paintCursor(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROrthoGrid.paintCursor().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOrthoGrid::paintCursor", context, engine);
            return result;
        }
         QScriptValue
        REcmaOrthoGrid::paintRuler
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOrthoGrid::paintRuler", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOrthoGrid::paintRuler";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROrthoGrid* self = 
                        getSelf("paintRuler", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RRuler */
    
    ){
    // prepare arguments:
    
                    // argument is reference
                    RRuler*
                    ap0 =
                    qscriptvalue_cast<
                    RRuler*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if( ap0 == NULL ){
                           return REcmaHelper::throwError("ROrthoGrid: Argument 0 is not of type RRuler*.",
                               context);                    
                    }
                    RRuler& a0 = *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->paintRuler(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROrthoGrid.paintRuler().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOrthoGrid::paintRuler", context, engine);
            return result;
        }
         QScriptValue
        REcmaOrthoGrid::getInfoText
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOrthoGrid::getInfoText", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOrthoGrid::getInfoText";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROrthoGrid* self = 
                        getSelf("getInfoText", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'QString'
    QString cppResult =
        
               self->getInfoText();
        // return type: QString
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROrthoGrid.getInfoText().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOrthoGrid::getInfoText", context, engine);
            return result;
        }
         QScriptValue
        REcmaOrthoGrid::getIdealSpacing
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOrthoGrid::getIdealSpacing", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOrthoGrid::getIdealSpacing";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROrthoGrid* self = 
                        getSelf("getIdealSpacing", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    2 && (
            context->argument(0).isNumber()
        ) /* type: int */
     && (
            context->argument(1).isVariant() || 
            context->argument(1).isQObject() || 
            context->argument(1).isNull()
        ) /* type: RVector */
    
    ){
    // prepare arguments:
    
                    // argument isStandardType
                    int
                    a0 =
                    (int)
                    
                    context->argument( 0 ).
                    toNumber();
                
                    // argument isCopyable and has default constructor and isSimpleClass 
                    RVector*
                    ap1 =
                    qscriptvalue_cast<
                    RVector*
                        >(
                        context->argument(
                        1
                        )
                    );
                    if (ap1 == NULL) {
                           return REcmaHelper::throwError("ROrthoGrid: Argument 1 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a1 = 
                    *ap1;
                
    // end of arguments

    // call C++ function:
    // return type 'QList < RVector >'
    QList < RVector > cppResult =
        
               self->getIdealSpacing(a0
        ,
    a1);
        // return type: QList < RVector >
                // List of ...:
                result = REcmaHelper::listToScriptValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROrthoGrid.getIdealSpacing().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOrthoGrid::getIdealSpacing", context, engine);
            return result;
        }
         QScriptValue
        REcmaOrthoGrid::isIsometric
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOrthoGrid::isIsometric", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOrthoGrid::isIsometric";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROrthoGrid* self = 
                        getSelf("isIsometric", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'bool'
    bool cppResult =
        
               self->isIsometric();
        // return type: bool
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROrthoGrid.isIsometric().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOrthoGrid::isIsometric", context, engine);
            return result;
        }
         QScriptValue
        REcmaOrthoGrid::setIsometric
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOrthoGrid::setIsometric", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOrthoGrid::setIsometric";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROrthoGrid* self = 
                        getSelf("setIsometric", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isBool()
        ) /* type: bool */
    
    ){
    // prepare arguments:
    
                    // argument isStandardType
                    bool
                    a0 =
                    (bool)
                    
                    context->argument( 0 ).
                    toBool();
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->setIsometric(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROrthoGrid.setIsometric().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOrthoGrid::setIsometric", context, engine);
            return result;
        }
         QScriptValue
        REcmaOrthoGrid::getProjection
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOrthoGrid::getProjection", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOrthoGrid::getProjection";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROrthoGrid* self = 
                        getSelf("getProjection", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'RS::IsoProjectionType'
    RS::IsoProjectionType cppResult =
        
               self->getProjection();
        // return type: RS::IsoProjectionType
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROrthoGrid.getProjection().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOrthoGrid::getProjection", context, engine);
            return result;
        }
         QScriptValue
        REcmaOrthoGrid::setProjection
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOrthoGrid::setProjection", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOrthoGrid::setProjection";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    ROrthoGrid* self = 
                        getSelf("setProjection", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isNumber()
        ) /* type: RS::IsoProjectionType */
    
    ){
    // prepare arguments:
    
                    // argument isStandardType
                    RS::IsoProjectionType
                    a0 =
                    (RS::IsoProjectionType)
                    (int)
                    context->argument( 0 ).
                    toNumber();
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->setProjection(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROrthoGrid.setProjection().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOrthoGrid::setProjection", context, engine);
            return result;
        }
         QScriptValue
        REcmaOrthoGrid::getIdealGridSpacing
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOrthoGrid::getIdealGridSpacing", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOrthoGrid::getIdealGridSpacing";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
    
    if( context->argumentCount() ==
    3 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RGraphicsView */
     && (
            context->argument(1).isNumber()
        ) /* type: int */
     && (
            context->argument(2).isVariant() || 
            context->argument(2).isQObject() || 
            context->argument(2).isNull()
        ) /* type: RVector */
    
    ){
    // prepare arguments:
    
                    // argument is reference
                    RGraphicsView*
                    ap0 =
                    qscriptvalue_cast<
                    RGraphicsView*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if( ap0 == NULL ){
                           return REcmaHelper::throwError("ROrthoGrid: Argument 0 is not of type RGraphicsView*.",
                               context);                    
                    }
                    RGraphicsView& a0 = *ap0;
                
                    // argument isStandardType
                    int
                    a1 =
                    (int)
                    
                    context->argument( 1 ).
                    toNumber();
                
                    // argument isCopyable and has default constructor and isSimpleClass 
                    RVector*
                    ap2 =
                    qscriptvalue_cast<
                    RVector*
                        >(
                        context->argument(
                        2
                        )
                    );
                    if (ap2 == NULL) {
                           return REcmaHelper::throwError("ROrthoGrid: Argument 2 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a2 = 
                    *ap2;
                
    // end of arguments

    // call C++ function:
    // return type 'QList < RVector >'
    QList < RVector > cppResult =
        ROrthoGrid::
       getIdealGridSpacing(a0
        ,
    a1
        ,
    a2);
        // return type: QList < RVector >
                // List of ...:
                result = REcmaHelper::listToScriptValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROrthoGrid.getIdealGridSpacing().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOrthoGrid::getIdealGridSpacing", context, engine);
            return result;
        }
         QScriptValue
        REcmaOrthoGrid::isFractionalFormat
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaOrthoGrid::isFractionalFormat", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaOrthoGrid::isFractionalFormat";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isNumber()
        ) /* type: RS::LinearFormat */
    
    ){
    // prepare arguments:
    
                    // argument isStandardType
                    RS::LinearFormat
                    a0 =
                    (RS::LinearFormat)
                    (int)
                    context->argument( 0 ).
                    toNumber();
                
    // end of arguments

    // call C++ function:
    // return type 'bool'
    bool cppResult =
        ROrthoGrid::
       isFractionalFormat(a0);
        // return type: bool
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for ROrthoGrid.isFractionalFormat().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaOrthoGrid::isFractionalFormat", context, engine);
            return result;
        }
         QScriptValue REcmaOrthoGrid::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    ROrthoGrid* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("ROrthoGrid(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaOrthoGrid::destroy(QScriptContext *context, QScriptEngine *engine)
    
    {

        ROrthoGrid* self = getSelf("ROrthoGrid", context);
        //Q_ASSERT(self!=NULL);
        if (self==NULL) {
            return REcmaHelper::throwError("self is NULL", context);
        }
        
    
        delete self;
        context->thisObject().setData(engine->nullValue());
        context->thisObject().prototype().setData(engine->nullValue());
        context->thisObject().setPrototype(engine->nullValue());
        context->thisObject().setScriptClass(NULL);
        return engine->undefinedValue();
    }
    ROrthoGrid* REcmaOrthoGrid::getSelf(const QString& fName, QScriptContext* context)
    
        {
            ROrthoGrid* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<ROrthoGrid >(context->thisObject())
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("ROrthoGrid.%1(): "
                        "This object is not a ROrthoGrid").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        ROrthoGrid* REcmaOrthoGrid::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          ROrthoGrid* selfBase = getSelf(fName, context);
                ROrthoGrid* self = dynamic_cast<ROrthoGrid*>(selfBase);
                //return REcmaHelper::scriptValueTo<ROrthoGrid >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("ROrthoGrid.%1(): "
                    "This object is not a ROrthoGrid").arg(fName),
                    context);
            }

            return self;
            


        }
        