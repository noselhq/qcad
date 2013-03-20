


	// ***** AUTOGENERATED CODE, DO NOT EDIT *****
    
        #ifndef RECMASHELLSNAPDISTANCE_H
        #define RECMASHELLSNAPDISTANCE_H

        #include <QScriptEngine>
        #include <QScriptValue>
        #include <QScriptContextInfo>
        #include <QDebug>

        
                #include "RSnapDistance.h"
            

        /**
         * \ingroup scripting_ecmaapi
         */
        class REcmaShellSnapDistance : public RSnapDistance {

        public:
      
    // Destructor:
    
            ~REcmaShellSnapDistance();
        static RSnapDistance* getSelf(const QString& fName, QScriptContext* context)
    ;static REcmaShellSnapDistance* getSelfShell(const QString& fName, QScriptContext* context)
    ;
    
    
    // Constructors:
    
      REcmaShellSnapDistance(
                
            );
        
    
    
      void showUiOptions(
                
            );
        
    
    
      void hideUiOptions(
                
            );
        
    
    
      void setDistance(
                double d
            );
        
    
    
      QList < RVector > snapEntity(
                QSharedPointer < REntity > entity, const RVector & point, const RBox & queryBox, RGraphicsView & view
            );
        
    
  
        // methods of 1st level base class RSnapEntityBase:
        
      RVector snap(
                const RVector & position, RGraphicsView & view, double range
        = RNANDOUBLE
            );
        
      RVector snap(
                const RVector & position, RGraphicsView & view, const QSet < REntity::Id > & candidates, const RBox & queryBox
            );
        
    
            // methods of 2nd level base class RSnap:
            
      QSet < REntity::Id > getEntityIds(
                
            );
        
    
      RSnap::Status getStatus(
                
            );
        
    
      RVector getLastSnap(
                
            );
        
    
      void reset(
                
            );
        
    

    // protected methods (only available for ECMA shell classes) (generated by xsl2xpp.xsl):
	static  QScriptValue
        snapEntity
        (QScriptContext* context, QScriptEngine* engine) 
        ;QScriptValue __qtscript_self;
            };
            Q_DECLARE_METATYPE(REcmaShellSnapDistance*)
        
	#endif
    