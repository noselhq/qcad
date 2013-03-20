

    // ***** AUTOGENERATED CODE, DO NOT EDIT *****
    
            // ***** This class is not copyable.
        
        #include "REcmaMoveReferencePointOperation.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
                #include "REntity.h"
            
            
        // includes for base ecma wrapper classes
        
                  #include "REcmaOperation.h"
                 void REcmaMoveReferencePointOperation::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (RMoveReferencePointOperation*) 0)));
        protoCreated = true;
    }

    
        // primary base class ROperation:
        
            QScriptValue dpt = engine.defaultPrototype(
                qMetaTypeId<ROperation*>());

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
    
        // conversion for base class ROperation
        REcmaHelper::registerFunction(&engine, proto, getROperation, "getROperation");
        

    // get class name
    REcmaHelper::registerFunction(&engine, proto, getClassName, "getClassName");
    

    // conversion to all base classes (multiple inheritance):
    REcmaHelper::registerFunction(&engine, proto, getBaseClasses, "getBaseClasses");
    

    // properties:
    

    // methods:
    
            REcmaHelper::registerFunction(&engine, proto, apply, "apply");
            
        engine.setDefaultPrototype(
            qMetaTypeId<RMoveReferencePointOperation*>(), *proto);

        
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    

    // static properties:
    

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("RMoveReferencePointOperation",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaMoveReferencePointOperation::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
    if (context->thisObject().strictlyEquals(
       engine->globalObject())) {
       return REcmaHelper::throwError(
       QString::fromLatin1("RMoveReferencePointOperation(): Did you forget to construct with 'new'?"),
           context);
    }

    QScriptValue result;
        
            // generate constructor variants:
            
    if( context->argumentCount() ==
        2
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
                ) /* type: RVector */
            
                && (
                
                        context->argument(
                        1
                        ).isVariant()
                        ||
                    
                        context->argument(
                        1
                        ).isQObject()
                        ||
                    
                        context->argument(
                        1
                        ).isNull()
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
                           return REcmaHelper::throwError("RMoveReferencePointOperation: Argument 0 is not of type RVector.",
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
                           return REcmaHelper::throwError("RMoveReferencePointOperation: Argument 1 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a1 = 
                    *ap1;
                
    // end of arguments

    // call C++ constructor:
    
            // non-copyable class:
            RMoveReferencePointOperation
                    * cppResult =
                    new
                    RMoveReferencePointOperation
                    (
                    a0
        ,
    a1
                    );
                
                    // TODO: triggers: Warning: QScriptEngine::newVariant(): changing class of non-QScriptObject not supported:
                    result = engine->newVariant(context->thisObject(), qVariantFromValue(cppResult));
                
    } else 

    {
       return REcmaHelper::throwError(
       QString::fromLatin1("RMoveReferencePointOperation(): no matching constructor found."),
           context);
    }
    
    return result;
    }
    

    // conversion functions for base classes:
     QScriptValue REcmaMoveReferencePointOperation::getROperation(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                ROperation* cppResult =
                    qscriptvalue_cast<RMoveReferencePointOperation*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
            

    // returns class name:
     QScriptValue REcmaMoveReferencePointOperation::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("RMoveReferencePointOperation"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaMoveReferencePointOperation::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        
        list.append("ROperation");
    

        return qScriptValueFromSequence(engine, list);
    }
    

    // properties:
    

    // public methods:
     QScriptValue
        REcmaMoveReferencePointOperation::apply
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaMoveReferencePointOperation::apply", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaMoveReferencePointOperation::apply";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RMoveReferencePointOperation* self = 
                        getSelf("apply", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RDocument */
    
    ){
    // prepare arguments:
    
                    // argument is reference
                    RDocument*
                    ap0 =
                    qscriptvalue_cast<
                    RDocument*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if( ap0 == NULL ){
                           return REcmaHelper::throwError("RMoveReferencePointOperation: Argument 0 is not of type RDocument*.",
                               context);                    
                    }
                    RDocument& a0 = *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'RTransaction'
    RTransaction cppResult =
        
               self->apply(a0);
        // return type: RTransaction
                // not standard type nor reference
                result = qScriptValueFromValue(engine, cppResult);
            
    } else


        
    
    if( context->argumentCount() ==
    2 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RDocument */
     && (
            context->argument(1).isBool()
        ) /* type: bool */
    
    ){
    // prepare arguments:
    
                    // argument is reference
                    RDocument*
                    ap0 =
                    qscriptvalue_cast<
                    RDocument*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if( ap0 == NULL ){
                           return REcmaHelper::throwError("RMoveReferencePointOperation: Argument 0 is not of type RDocument*.",
                               context);                    
                    }
                    RDocument& a0 = *ap0;
                
                    // argument isStandardType
                    bool
                    a1 =
                    (bool)
                    
                    context->argument( 1 ).
                    toBool();
                
    // end of arguments

    // call C++ function:
    // return type 'RTransaction'
    RTransaction cppResult =
        
               self->apply(a0
        ,
    a1);
        // return type: RTransaction
                // not standard type nor reference
                result = qScriptValueFromValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RMoveReferencePointOperation.apply().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaMoveReferencePointOperation::apply", context, engine);
            return result;
        }
         QScriptValue REcmaMoveReferencePointOperation::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RMoveReferencePointOperation* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("RMoveReferencePointOperation(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaMoveReferencePointOperation::destroy(QScriptContext *context, QScriptEngine *engine)
    
    {

        RMoveReferencePointOperation* self = getSelf("RMoveReferencePointOperation", context);
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
    RMoveReferencePointOperation* REcmaMoveReferencePointOperation::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RMoveReferencePointOperation* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RMoveReferencePointOperation >(context->thisObject())
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("RMoveReferencePointOperation.%1(): "
                        "This object is not a RMoveReferencePointOperation").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        RMoveReferencePointOperation* REcmaMoveReferencePointOperation::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          RMoveReferencePointOperation* selfBase = getSelf(fName, context);
                RMoveReferencePointOperation* self = dynamic_cast<RMoveReferencePointOperation*>(selfBase);
                //return REcmaHelper::scriptValueTo<RMoveReferencePointOperation >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("RMoveReferencePointOperation.%1(): "
                    "This object is not a RMoveReferencePointOperation").arg(fName),
                    context);
            }

            return self;
            


        }
        