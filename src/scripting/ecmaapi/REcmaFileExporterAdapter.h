

    // ***** AUTOGENERATED CODE, DO NOT EDIT *****
    
            // ***** This class is not copyable.
        
        #ifndef RECMAFILEEXPORTERADAPTER_H
        #define RECMAFILEEXPORTERADAPTER_H

        #include <QScriptEngine>
        #include <QScriptValue>
        #include <QScriptContextInfo>
        #include <QDebug>

        
                #include "REcmaShellFileExporterAdapter.h"
            

        /**
         * \ingroup scripting_ecmaapi
         */
        class REcmaFileExporterAdapter {

        public:
      static  void init(QScriptEngine& engine, QScriptValue* proto 
    =NULL
    ) 
    ;static  QScriptValue create(QScriptContext* context, QScriptEngine* engine) 
    ;

    // conversion functions for base classes:
    static  QScriptValue getRFileExporter(QScriptContext *context,
            QScriptEngine *engine)
        ;static  QScriptValue getRExporter(QScriptContext *context,
            QScriptEngine *engine)
        ;

    // returns class name:
    static  QScriptValue getClassName(QScriptContext *context, QScriptEngine *engine) 
        ;

    // returns all base classes (in case of multiple inheritance):
    static  QScriptValue getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        ;

    // properties:
    

    // public methods:
    static  QScriptValue
        getCorrectedFileName
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        exportFile
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        exportPoint
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        exportArcSegment
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        exportLineSegment
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        exportTriangle
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getPatternFactor
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue toString
    (QScriptContext *context, QScriptEngine *engine)
    ;static  QScriptValue destroy(QScriptContext *context, QScriptEngine *engine)
    ;static RFileExporterAdapter* getSelf(const QString& fName, QScriptContext* context)
    ;static REcmaShellFileExporterAdapter* getSelfShell(const QString& fName, QScriptContext* context)
    ;};
    #endif
    