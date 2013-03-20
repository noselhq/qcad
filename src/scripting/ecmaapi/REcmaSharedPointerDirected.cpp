

    // ***** AUTOGENERATED CODE, DO NOT EDIT *****
    
            // ***** This class is not copyable.
        
        #include "REcmaSharedPointerDirected.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
            
        // includes for base ecma wrapper classes
         void REcmaSharedPointerDirected::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (RDirectedPointer*) 0)));
        protoCreated = true;
    }

    

    QScriptValue fun;

    // toString:
    REcmaHelper::registerFunction(&engine, proto, toString, "toString");
    
        // shared pointer support:
        REcmaHelper::registerFunction(&engine, proto, data, "data");
        

        REcmaHelper::registerFunction(&engine, proto, isNull, "isNull");
        

    // destroy:
    REcmaHelper::registerFunction(&engine, proto, destroy, "destroy");
    

    // get class name
    REcmaHelper::registerFunction(&engine, proto, getClassName, "getClassName");
    

    // conversion to all base classes (multiple inheritance):
    REcmaHelper::registerFunction(&engine, proto, getBaseClasses, "getBaseClasses");
    

    // properties:
    

    // methods:
    
            REcmaHelper::registerFunction(&engine, proto, getDirection1, "getDirection1");
            
            REcmaHelper::registerFunction(&engine, proto, getDirection2, "getDirection2");
            
            REcmaHelper::registerFunction(&engine, proto, getStartPoint, "getStartPoint");
            
            REcmaHelper::registerFunction(&engine, proto, getEndPoint, "getEndPoint");
            
            REcmaHelper::registerFunction(&engine, proto, reverse, "reverse");
            
            REcmaHelper::registerFunction(&engine, proto, trimStartPoint, "trimStartPoint");
            
            REcmaHelper::registerFunction(&engine, proto, trimEndPoint, "trimEndPoint");
            
            REcmaHelper::registerFunction(&engine, proto, getTrimEnd, "getTrimEnd");
            
            REcmaHelper::registerFunction(&engine, proto, getDistanceFromStart, "getDistanceFromStart");
            
        engine.setDefaultPrototype(
            qMetaTypeId<RDirectedPointer>(), *proto);
      
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    

    // static properties:
    

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("RDirectedPointer",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaSharedPointerDirected::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
           return REcmaHelper::throwError("Abstract class RDirected: Cannot be constructed.",
               context); 
    }
    

    // conversion functions for base classes:
    

    // returns class name:
     QScriptValue REcmaSharedPointerDirected::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("RDirected"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaSharedPointerDirected::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        

        return qScriptValueFromSequence(engine, list);
    }
    

    // properties:
    

    // public methods:
     QScriptValue
        REcmaSharedPointerDirected::getDirection1
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDirected::getDirection1", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDirected::getDirection1";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDirected* self = 
                        getSelf("getDirection1", context);
                  

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
    // return type 'double'
    double cppResult =
        
               self->getDirection1();
        // return type: double
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDirected.getDirection1().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDirected::getDirection1", context, engine);
            return result;
        }
         QScriptValue
        REcmaSharedPointerDirected::getDirection2
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDirected::getDirection2", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDirected::getDirection2";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDirected* self = 
                        getSelf("getDirection2", context);
                  

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
    // return type 'double'
    double cppResult =
        
               self->getDirection2();
        // return type: double
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDirected.getDirection2().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDirected::getDirection2", context, engine);
            return result;
        }
         QScriptValue
        REcmaSharedPointerDirected::getStartPoint
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDirected::getStartPoint", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDirected::getStartPoint";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDirected* self = 
                        getSelf("getStartPoint", context);
                  

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
    // return type 'RVector'
    RVector cppResult =
        
               self->getStartPoint();
        // return type: RVector
                // not standard type nor reference
                result = qScriptValueFromValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDirected.getStartPoint().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDirected::getStartPoint", context, engine);
            return result;
        }
         QScriptValue
        REcmaSharedPointerDirected::getEndPoint
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDirected::getEndPoint", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDirected::getEndPoint";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDirected* self = 
                        getSelf("getEndPoint", context);
                  

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
    // return type 'RVector'
    RVector cppResult =
        
               self->getEndPoint();
        // return type: RVector
                // not standard type nor reference
                result = qScriptValueFromValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDirected.getEndPoint().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDirected::getEndPoint", context, engine);
            return result;
        }
         QScriptValue
        REcmaSharedPointerDirected::reverse
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDirected::reverse", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDirected::reverse";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDirected* self = 
                        getSelf("reverse", context);
                  

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
        
               self->reverse();
        // return type: bool
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDirected.reverse().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDirected::reverse", context, engine);
            return result;
        }
         QScriptValue
        REcmaSharedPointerDirected::trimStartPoint
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDirected::trimStartPoint", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDirected::trimStartPoint";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDirected* self = 
                        getSelf("trimStartPoint", context);
                  

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
                           return REcmaHelper::throwError("RDirected: Argument 0 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a0 = 
                    *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->trimStartPoint(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDirected.trimStartPoint().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDirected::trimStartPoint", context, engine);
            return result;
        }
         QScriptValue
        REcmaSharedPointerDirected::trimEndPoint
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDirected::trimEndPoint", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDirected::trimEndPoint";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDirected* self = 
                        getSelf("trimEndPoint", context);
                  

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
                           return REcmaHelper::throwError("RDirected: Argument 0 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a0 = 
                    *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->trimEndPoint(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDirected.trimEndPoint().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDirected::trimEndPoint", context, engine);
            return result;
        }
         QScriptValue
        REcmaSharedPointerDirected::getTrimEnd
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDirected::getTrimEnd", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDirected::getTrimEnd";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDirected* self = 
                        getSelf("getTrimEnd", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    2 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RVector */
     && (
            context->argument(1).isVariant() || 
            context->argument(1).isQObject() || 
            context->argument(1).isNull()
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
                           return REcmaHelper::throwError("RDirected: Argument 0 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a0 = 
                    *ap0;
                
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
                           return REcmaHelper::throwError("RDirected: Argument 1 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a1 = 
                    *ap1;
                
    // end of arguments

    // call C++ function:
    // return type 'RS::Ending'
    RS::Ending cppResult =
        
               self->getTrimEnd(a0
        ,
    a1);
        // return type: RS::Ending
                // not standard type nor reference
                result = qScriptValueFromValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDirected.getTrimEnd().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDirected::getTrimEnd", context, engine);
            return result;
        }
         QScriptValue
        REcmaSharedPointerDirected::getDistanceFromStart
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDirected::getDistanceFromStart", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDirected::getDistanceFromStart";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDirected* self = 
                        getSelf("getDistanceFromStart", context);
                  

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
                           return REcmaHelper::throwError("RDirected: Argument 0 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a0 = 
                    *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'double'
    double cppResult =
        
               self->getDistanceFromStart(a0);
        // return type: double
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDirected.getDistanceFromStart().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDirected::getDistanceFromStart", context, engine);
            return result;
        }
         QScriptValue REcmaSharedPointerDirected::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RDirected* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("RDirectedPointer(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaSharedPointerDirected::destroy(QScriptContext *context, QScriptEngine *engine)
    
    {

        RDirected* self = getSelf("RDirected", context);
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
    RDirected* REcmaSharedPointerDirected::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RDirected* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RDirectedPointer >(context->thisObject())
                
                    ->data()
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("RDirected.%1(): "
                        "This object is not a RDirected").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        RDirected* REcmaSharedPointerDirected::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          RDirected* selfBase = getSelf(fName, context);
                RDirected* self = dynamic_cast<RDirected*>(selfBase);
                //return REcmaHelper::scriptValueTo<RDirected >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("RDirected.%1(): "
                    "This object is not a RDirected").arg(fName),
                    context);
            }

            return self;
            


        }
         QScriptValue REcmaSharedPointerDirected::data
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RDirected* self = getSelf("data", context);
    return qScriptValueFromValue(engine, self);
    }
     QScriptValue REcmaSharedPointerDirected::isNull
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RDirectedPointer* self = REcmaHelper::scriptValueTo<RDirectedPointer >(context->thisObject());

    //RDirected* self = getSelf("isNull", context);
    //Q_ASSERT(self!=NULL);
    if (self==NULL) {
        return REcmaHelper::throwError("self is NULL", context);
    }
    return qScriptValueFromValue(engine, self->isNull());
    }
    