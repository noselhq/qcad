

    // ***** AUTOGENERATED CODE, DO NOT EDIT *****
    
            // ***** This class is not copyable.
        
        #ifndef RECMASNAPRESTRICTION_H
        #define RECMASNAPRESTRICTION_H

        #include <QScriptEngine>
        #include <QScriptValue>
        #include <QScriptContextInfo>
        #include <QDebug>

        
                #include "REcmaShellSnapRestriction.h"
            

        /**
         * \ingroup scripting_ecmaapi
         */
        class REcmaSnapRestriction {

        public:
      static  void init(QScriptEngine& engine, QScriptValue* proto 
    =NULL
    ) 
    ;static  QScriptValue create(QScriptContext* context, QScriptEngine* engine) 
    ;

    // conversion functions for base classes:
    

    // returns class name:
    static  QScriptValue getClassName(QScriptContext *context, QScriptEngine *engine) 
        ;

    // returns all base classes (in case of multiple inheritance):
    static  QScriptValue getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        ;

    // properties:
    

    // public methods:
    static  QScriptValue
        restrictSnap
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        showUiOptions
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        hideUiOptions
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getLastSnap
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        reset
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue toString
    (QScriptContext *context, QScriptEngine *engine)
    ;static  QScriptValue destroy(QScriptContext *context, QScriptEngine *engine)
    ;static RSnapRestriction* getSelf(const QString& fName, QScriptContext* context)
    ;static REcmaShellSnapRestriction* getSelfShell(const QString& fName, QScriptContext* context)
    ;};
    #endif
    