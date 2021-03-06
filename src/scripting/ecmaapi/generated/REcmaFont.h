// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #ifndef RECMAFONT_H
        #define RECMAFONT_H

        #include "ecmaapi_global.h"

        #include <QScriptEngine>
        #include <QScriptValue>
        #include <QScriptContextInfo>
        #include <QDebug>

        
                #include "RFont.h"
            

        /**
         * \ingroup scripting_ecmaapi
         */
        class QCADECMAAPI_EXPORT REcmaFont {

        public:
      static  void initEcma(QScriptEngine& engine, QScriptValue* proto 
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
        isValid
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getFileName
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getEncoding
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getNames
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getAuthors
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getLetterSpacing
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getWordSpacing
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getLineSpacingFactor
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        load
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        isLoaded
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue toString
    (QScriptContext *context, QScriptEngine *engine)
    ;static  QScriptValue destroy(QScriptContext *context, QScriptEngine *engine)
    ;static RFont* getSelf(const QString& fName, QScriptContext* context)
    ;static RFont* getSelfShell(const QString& fName, QScriptContext* context)
    ;};
    #endif
    