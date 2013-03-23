

    // ***** AUTOGENERATED CODE, DO NOT EDIT *****
    
            // ***** This class is not copyable.
        
        #include "REcmaDirected.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
            
        // includes for base ecma wrapper classes
         void REcmaDirected::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (RDirected*) 0)));
        protoCreated = true;
    }

    

    QScriptValue fun;

    // toString:
    REcmaHelper::registerFunction(&engine, proto, toString, "toString");
    

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
            qMetaTypeId<RDirected*>(), *proto);

        
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    

    // static properties:
    

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("RDirected",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaDirected::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
           return REcmaHelper::throwError("Abstract class RDirected: Cannot be constructed.",
               context); 
    }
    

    // conversion functions for base classes:
    

    // returns class name:
     QScriptValue REcmaDirected::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("RDirected"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaDirected::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        

        return qScriptValueFromSequence(engine, list);
    }
    

    // properties:
    

    // public methods:
     QScriptValue
        REcmaDirected::getDirection1
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaDirected::getDirection1", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaDirected::getDirection1";
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
            //REcmaHelper::functionEnd("REcmaDirected::getDirection1", context, engine);
            return result;
        }
         QScriptValue
        REcmaDirected::getDirection2
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaDirected::getDirection2", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaDirected::getDirection2";
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
            //REcmaHelper::functionEnd("REcmaDirected::getDirection2", context, engine);
            return result;
        }
         QScriptValue
        REcmaDirected::getStartPoint
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaDirected::getStartPoint", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaDirected::getStartPoint";
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
            //REcmaHelper::functionEnd("REcmaDirected::getStartPoint", context, engine);
            return result;
        }
         QScriptValue
        REcmaDirected::getEndPoint
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaDirected::getEndPoint", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaDirected::getEndPoint";
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
            //REcmaHelper::functionEnd("REcmaDirected::getEndPoint", context, engine);
            return result;
        }
         QScriptValue
        REcmaDirected::reverse
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaDirected::reverse", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaDirected::reverse";
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
            //REcmaHelper::functionEnd("REcmaDirected::reverse", context, engine);
            return result;
        }
         QScriptValue
        REcmaDirected::trimStartPoint
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaDirected::trimStartPoint", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaDirected::trimStartPoint";
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
            //REcmaHelper::functionEnd("REcmaDirected::trimStartPoint", context, engine);
            return result;
        }
         QScriptValue
        REcmaDirected::trimEndPoint
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaDirected::trimEndPoint", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaDirected::trimEndPoint";
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
            //REcmaHelper::functionEnd("REcmaDirected::trimEndPoint", context, engine);
            return result;
        }
         QScriptValue
        REcmaDirected::getTrimEnd
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaDirected::getTrimEnd", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaDirected::getTrimEnd";
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
            //REcmaHelper::functionEnd("REcmaDirected::getTrimEnd", context, engine);
            return result;
        }
         QScriptValue
        REcmaDirected::getDistanceFromStart
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaDirected::getDistanceFromStart", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaDirected::getDistanceFromStart";
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
            //REcmaHelper::functionEnd("REcmaDirected::getDistanceFromStart", context, engine);
            return result;
        }
         QScriptValue REcmaDirected::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RDirected* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("RDirected(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaDirected::destroy(QScriptContext *context, QScriptEngine *engine)
    
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
    RDirected* REcmaDirected::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RDirected* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RDirected >(context->thisObject())
                
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
        RDirected* REcmaDirected::getSelfShell(const QString& fName, QScriptContext* context)
    
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
        