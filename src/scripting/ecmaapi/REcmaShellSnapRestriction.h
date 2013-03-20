


	// ***** AUTOGENERATED CODE, DO NOT EDIT *****
    
        #ifndef RECMASHELLSNAPRESTRICTION_H
        #define RECMASHELLSNAPRESTRICTION_H

        #include <QScriptEngine>
        #include <QScriptValue>
        #include <QScriptContextInfo>
        #include <QDebug>

        
                #include "RSnapRestriction.h"
            

        /**
         * \ingroup scripting_ecmaapi
         */
        class REcmaShellSnapRestriction : public RSnapRestriction {

        public:
      
    // Destructor:
    
            ~REcmaShellSnapRestriction();
        static RSnapRestriction* getSelf(const QString& fName, QScriptContext* context)
    ;static REcmaShellSnapRestriction* getSelfShell(const QString& fName, QScriptContext* context)
    ;
    
    // Constructors:
    
      REcmaShellSnapRestriction(
                RDocumentInterface & documentInterface
            );
        
    
    
      RVector restrictSnap(
                const RVector & position, const RVector & relativeZero
            );
        
    
    
      void showUiOptions(
                
            );
        
    
    
      void hideUiOptions(
                
            );
        
    
    
      RVector getLastSnap(
                
            );
        
    
    
      void reset(
                
            );
        
    
  

    // protected methods (only available for ECMA shell classes) (generated by xsl2xpp.xsl):
	QScriptValue __qtscript_self;
            };
            Q_DECLARE_METATYPE(REcmaShellSnapRestriction*)
        
	#endif
    