

    // ***** AUTOGENERATED CODE, DO NOT EDIT *****
    
            // ***** This class is not copyable.
        
        #include "REcmaSharedPointerDimLinearEntity.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
                #include "RDocument.h"
            
                #include "RExporter.h"
            
            
        // includes for base ecma wrapper classes
        
                  #include "REcmaSharedPointerDimensionEntity.h"
                 void REcmaSharedPointerDimLinearEntity::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (RDimLinearEntityPointer*) 0)));
        protoCreated = true;
    }

    
        // primary base class RDimensionEntity:
        
            proto->setPrototype(engine.defaultPrototype(
            qMetaTypeId<RDimensionEntityPointer>()));
          
        /*
        
        */
    

    QScriptValue fun;

    // toString:
    REcmaHelper::registerFunction(&engine, proto, toString, "toString");
    
        // shared pointer support:
        REcmaHelper::registerFunction(&engine, proto, data, "data");
        

        REcmaHelper::registerFunction(&engine, proto, isNull, "isNull");
        

    // destroy:
    REcmaHelper::registerFunction(&engine, proto, destroy, "destroy");
    
        // conversion for base class RDimensionEntity
        REcmaHelper::registerFunction(&engine, proto, getRDimensionEntity, "getRDimensionEntity");
        
        // conversion for base class REntity
        REcmaHelper::registerFunction(&engine, proto, getREntity, "getREntity");
        
        // conversion for base class RObject
        REcmaHelper::registerFunction(&engine, proto, getRObject, "getRObject");
        

    // get class name
    REcmaHelper::registerFunction(&engine, proto, getClassName, "getClassName");
    

    // conversion to all base classes (multiple inheritance):
    REcmaHelper::registerFunction(&engine, proto, getBaseClasses, "getBaseClasses");
    

    // properties:
    

    // methods:
    
            REcmaHelper::registerFunction(&engine, proto, setProperty, "setProperty");
            
            REcmaHelper::registerFunction(&engine, proto, getProperty, "getProperty");
            
            REcmaHelper::registerFunction(&engine, proto, getData, "getData");
            
            REcmaHelper::registerFunction(&engine, proto, setExtensionPoint1, "setExtensionPoint1");
            
            REcmaHelper::registerFunction(&engine, proto, getExtensionPoint1, "getExtensionPoint1");
            
            REcmaHelper::registerFunction(&engine, proto, setExtensionPoint2, "setExtensionPoint2");
            
            REcmaHelper::registerFunction(&engine, proto, getExtensionPoint2, "getExtensionPoint2");
            
        engine.setDefaultPrototype(
            qMetaTypeId<RDimLinearEntityPointer>(), *proto);
      
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    
            REcmaHelper::registerFunction(&engine, &ctor, init, "init");
            

    // static properties:
    
            ctor.setProperty("PropertyCustom",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyCustom),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyHandle",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyHandle),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyType",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyType),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyBlock",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyBlock),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyLayer",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyLayer),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyLinetype",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyLinetype),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyLineweight",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyLineweight),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyColor",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyColor),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyDrawOrder",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyDrawOrder),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyMiddleOfTextX",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyMiddleOfTextX),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyMiddleOfTextY",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyMiddleOfTextY),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyMiddleOfTextZ",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyMiddleOfTextZ),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyText",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyText),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyUpperTolerance",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyUpperTolerance),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyLowerTolerance",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyLowerTolerance),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyDimensionLinePosX",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyDimensionLinePosX),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyDimensionLinePosY",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyDimensionLinePosY),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyDimensionLinePosZ",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyDimensionLinePosZ),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyExtensionPoint1X",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyExtensionPoint1X),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyExtensionPoint1Y",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyExtensionPoint1Y),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyExtensionPoint1Z",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyExtensionPoint1Z),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyExtensionPoint2X",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyExtensionPoint2X),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyExtensionPoint2Y",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyExtensionPoint2Y),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            
            ctor.setProperty("PropertyExtensionPoint2Z",
                qScriptValueFromValue(&engine, RDimLinearEntity::PropertyExtensionPoint2Z),
                QScriptValue::SkipInEnumeration | QScriptValue::ReadOnly);
            

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("RDimLinearEntityPointer",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaSharedPointerDimLinearEntity::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
           return REcmaHelper::throwError("Abstract class RDimLinearEntity: Cannot be constructed.",
               context); 
    }
    

    // conversion functions for base classes:
     QScriptValue REcmaSharedPointerDimLinearEntity::getRDimensionEntity(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                RDimensionEntity* cppResult =
                    qscriptvalue_cast<RDimLinearEntity*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
             QScriptValue REcmaSharedPointerDimLinearEntity::getREntity(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                REntity* cppResult =
                    qscriptvalue_cast<RDimLinearEntity*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
             QScriptValue REcmaSharedPointerDimLinearEntity::getRObject(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                RObject* cppResult =
                    qscriptvalue_cast<RDimLinearEntity*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
            

    // returns class name:
     QScriptValue REcmaSharedPointerDimLinearEntity::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("RDimLinearEntity"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaSharedPointerDimLinearEntity::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        
        list.append("RDimensionEntity");
    
        list.append("REntity");
    
        list.append("RObject");
    

        return qScriptValueFromSequence(engine, list);
    }
    

    // properties:
    

    // public methods:
     QScriptValue
        REcmaSharedPointerDimLinearEntity::init
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDimLinearEntity::init", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDimLinearEntity::init";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'void'
    RDimLinearEntity::
       init();
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDimLinearEntity.init().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDimLinearEntity::init", context, engine);
            return result;
        }
         QScriptValue
        REcmaSharedPointerDimLinearEntity::setProperty
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDimLinearEntity::setProperty", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDimLinearEntity::setProperty";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDimLinearEntity* self = 
                        getSelf("setProperty", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    2 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RPropertyTypeId */
     && (
            context->argument(1).isVariant() || 
            context->argument(1).isQObject() || 
            context->argument(1).isNumber() || 
            context->argument(1).isString() || 
            context->argument(1).isBool() || 
            context->argument(1).isArray() || 
            context->argument(1).isNull()
        ) /* type: QVariant */
    
    ){
    // prepare arguments:
    
                    // argument isCopyable and has default constructor and isSimpleClass 
                    RPropertyTypeId*
                    ap0 =
                    qscriptvalue_cast<
                    RPropertyTypeId*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if (ap0 == NULL) {
                           return REcmaHelper::throwError("RDimLinearEntity: Argument 0 is not of type RPropertyTypeId.",
                               context);                    
                    }
                    RPropertyTypeId 
                    a0 = 
                    *ap0;
                
                    // argument isCopyable or pointer
                    QVariant
                    a1 =
                    qscriptvalue_cast<
                    QVariant
                        >(
                        context->argument(
                        1
                        )
                    );
                
    // end of arguments

    // call C++ function:
    // return type 'bool'
    bool cppResult =
        
               self->setProperty(a0
        ,
    a1);
        // return type: bool
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDimLinearEntity.setProperty().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDimLinearEntity::setProperty", context, engine);
            return result;
        }
         QScriptValue
        REcmaSharedPointerDimLinearEntity::getProperty
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDimLinearEntity::getProperty", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDimLinearEntity::getProperty";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDimLinearEntity* self = 
                        getSelf("getProperty", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RPropertyTypeId */
    
    ){
    // prepare arguments:
    
                    // argument isCopyable and has default constructor and isSimpleClass 
                    RPropertyTypeId*
                    ap0 =
                    qscriptvalue_cast<
                    RPropertyTypeId*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if (ap0 == NULL) {
                           return REcmaHelper::throwError("RDimLinearEntity: Argument 0 is not of type RPropertyTypeId.",
                               context);                    
                    }
                    RPropertyTypeId 
                    a0 = 
                    *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'QPair < QVariant , RPropertyAttributes >'
    QPair < QVariant , RPropertyAttributes > cppResult =
        
               self->getProperty(a0);
        // return type: QPair < QVariant , RPropertyAttributes >
                // Pair of ...:
                //result = REcmaHelper::pairToScriptValue(engine, cppResult);
                QVariantList vl;
                QVariant v;
                
                    // first type of pair is variant:
                    if (QString(cppResult.first.typeName())=="RLineweight::Lineweight") {
                        v.setValue((int)cppResult.first.value<RLineweight::Lineweight>());
                    }
                    else {
                        v.setValue(cppResult.first);
                    }
                  

                vl.append(v);
                v.setValue(cppResult.second);
                vl.append(v);
                result = qScriptValueFromValue(engine, vl);
            
    } else


        
    
    if( context->argumentCount() ==
    2 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RPropertyTypeId */
     && (
            context->argument(1).isBool()
        ) /* type: bool */
    
    ){
    // prepare arguments:
    
                    // argument isCopyable and has default constructor and isSimpleClass 
                    RPropertyTypeId*
                    ap0 =
                    qscriptvalue_cast<
                    RPropertyTypeId*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if (ap0 == NULL) {
                           return REcmaHelper::throwError("RDimLinearEntity: Argument 0 is not of type RPropertyTypeId.",
                               context);                    
                    }
                    RPropertyTypeId 
                    a0 = 
                    *ap0;
                
                    // argument isStandardType
                    bool
                    a1 =
                    (bool)
                    
                    context->argument( 1 ).
                    toBool();
                
    // end of arguments

    // call C++ function:
    // return type 'QPair < QVariant , RPropertyAttributes >'
    QPair < QVariant , RPropertyAttributes > cppResult =
        
               self->getProperty(a0
        ,
    a1);
        // return type: QPair < QVariant , RPropertyAttributes >
                // Pair of ...:
                //result = REcmaHelper::pairToScriptValue(engine, cppResult);
                QVariantList vl;
                QVariant v;
                
                    // first type of pair is variant:
                    if (QString(cppResult.first.typeName())=="RLineweight::Lineweight") {
                        v.setValue((int)cppResult.first.value<RLineweight::Lineweight>());
                    }
                    else {
                        v.setValue(cppResult.first);
                    }
                  

                vl.append(v);
                v.setValue(cppResult.second);
                vl.append(v);
                result = qScriptValueFromValue(engine, vl);
            
    } else


        
    
    if( context->argumentCount() ==
    3 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RPropertyTypeId */
     && (
            context->argument(1).isBool()
        ) /* type: bool */
     && (
            context->argument(2).isBool()
        ) /* type: bool */
    
    ){
    // prepare arguments:
    
                    // argument isCopyable and has default constructor and isSimpleClass 
                    RPropertyTypeId*
                    ap0 =
                    qscriptvalue_cast<
                    RPropertyTypeId*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if (ap0 == NULL) {
                           return REcmaHelper::throwError("RDimLinearEntity: Argument 0 is not of type RPropertyTypeId.",
                               context);                    
                    }
                    RPropertyTypeId 
                    a0 = 
                    *ap0;
                
                    // argument isStandardType
                    bool
                    a1 =
                    (bool)
                    
                    context->argument( 1 ).
                    toBool();
                
                    // argument isStandardType
                    bool
                    a2 =
                    (bool)
                    
                    context->argument( 2 ).
                    toBool();
                
    // end of arguments

    // call C++ function:
    // return type 'QPair < QVariant , RPropertyAttributes >'
    QPair < QVariant , RPropertyAttributes > cppResult =
        
               self->getProperty(a0
        ,
    a1
        ,
    a2);
        // return type: QPair < QVariant , RPropertyAttributes >
                // Pair of ...:
                //result = REcmaHelper::pairToScriptValue(engine, cppResult);
                QVariantList vl;
                QVariant v;
                
                    // first type of pair is variant:
                    if (QString(cppResult.first.typeName())=="RLineweight::Lineweight") {
                        v.setValue((int)cppResult.first.value<RLineweight::Lineweight>());
                    }
                    else {
                        v.setValue(cppResult.first);
                    }
                  

                vl.append(v);
                v.setValue(cppResult.second);
                vl.append(v);
                result = qScriptValueFromValue(engine, vl);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDimLinearEntity.getProperty().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDimLinearEntity::getProperty", context, engine);
            return result;
        }
         QScriptValue
        REcmaSharedPointerDimLinearEntity::getData
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDimLinearEntity::getData", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDimLinearEntity::getData";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDimLinearEntity* self = 
                        getSelf("getData", context);
                  

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
    // return type 'RDimLinearData &'
    RDimLinearData & cppResult =
        
               self->getData();
        // return type: RDimLinearData &
                // reference
                result = engine->newVariant(
                QVariant::fromValue(&cppResult));
            
    } else


        
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'RDimLinearData &'
    RDimLinearData & cppResult =
        
               self->getData();
        // return type: RDimLinearData &
                // reference
                result = engine->newVariant(
                QVariant::fromValue(&cppResult));
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDimLinearEntity.getData().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDimLinearEntity::getData", context, engine);
            return result;
        }
         QScriptValue
        REcmaSharedPointerDimLinearEntity::setExtensionPoint1
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDimLinearEntity::setExtensionPoint1", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDimLinearEntity::setExtensionPoint1";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDimLinearEntity* self = 
                        getSelf("setExtensionPoint1", context);
                  

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
                           return REcmaHelper::throwError("RDimLinearEntity: Argument 0 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a0 = 
                    *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->setExtensionPoint1(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDimLinearEntity.setExtensionPoint1().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDimLinearEntity::setExtensionPoint1", context, engine);
            return result;
        }
         QScriptValue
        REcmaSharedPointerDimLinearEntity::getExtensionPoint1
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDimLinearEntity::getExtensionPoint1", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDimLinearEntity::getExtensionPoint1";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDimLinearEntity* self = 
                        getSelf("getExtensionPoint1", context);
                  

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
        
               self->getExtensionPoint1();
        // return type: RVector
                // not standard type nor reference
                result = qScriptValueFromValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDimLinearEntity.getExtensionPoint1().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDimLinearEntity::getExtensionPoint1", context, engine);
            return result;
        }
         QScriptValue
        REcmaSharedPointerDimLinearEntity::setExtensionPoint2
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDimLinearEntity::setExtensionPoint2", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDimLinearEntity::setExtensionPoint2";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDimLinearEntity* self = 
                        getSelf("setExtensionPoint2", context);
                  

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
                           return REcmaHelper::throwError("RDimLinearEntity: Argument 0 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a0 = 
                    *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->setExtensionPoint2(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDimLinearEntity.setExtensionPoint2().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDimLinearEntity::setExtensionPoint2", context, engine);
            return result;
        }
         QScriptValue
        REcmaSharedPointerDimLinearEntity::getExtensionPoint2
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSharedPointerDimLinearEntity::getExtensionPoint2", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSharedPointerDimLinearEntity::getExtensionPoint2";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RDimLinearEntity* self = 
                        getSelf("getExtensionPoint2", context);
                  

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
        
               self->getExtensionPoint2();
        // return type: RVector
                // not standard type nor reference
                result = qScriptValueFromValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RDimLinearEntity.getExtensionPoint2().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSharedPointerDimLinearEntity::getExtensionPoint2", context, engine);
            return result;
        }
         QScriptValue REcmaSharedPointerDimLinearEntity::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RDimLinearEntity* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("RDimLinearEntityPointer(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaSharedPointerDimLinearEntity::destroy(QScriptContext *context, QScriptEngine *engine)
    
    {

        RDimLinearEntity* self = getSelf("RDimLinearEntity", context);
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
    RDimLinearEntity* REcmaSharedPointerDimLinearEntity::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RDimLinearEntity* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RDimLinearEntityPointer >(context->thisObject())
                
                    ->data()
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("RDimLinearEntity.%1(): "
                        "This object is not a RDimLinearEntity").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        RDimLinearEntity* REcmaSharedPointerDimLinearEntity::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          RDimLinearEntity* selfBase = getSelf(fName, context);
                RDimLinearEntity* self = dynamic_cast<RDimLinearEntity*>(selfBase);
                //return REcmaHelper::scriptValueTo<RDimLinearEntity >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("RDimLinearEntity.%1(): "
                    "This object is not a RDimLinearEntity").arg(fName),
                    context);
            }

            return self;
            


        }
         QScriptValue REcmaSharedPointerDimLinearEntity::data
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RDimLinearEntity* self = getSelf("data", context);
    return qScriptValueFromValue(engine, self);
    }
     QScriptValue REcmaSharedPointerDimLinearEntity::isNull
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RDimLinearEntityPointer* self = REcmaHelper::scriptValueTo<RDimLinearEntityPointer >(context->thisObject());

    //RDimLinearEntity* self = getSelf("isNull", context);
    //Q_ASSERT(self!=NULL);
    if (self==NULL) {
        return REcmaHelper::throwError("self is NULL", context);
    }
    return qScriptValueFromValue(engine, self->isNull());
    }
    