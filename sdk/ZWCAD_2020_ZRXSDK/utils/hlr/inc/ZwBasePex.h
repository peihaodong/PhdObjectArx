
#pragma once

#include "ZwHlr.h"
#include <map>

#pragma warning (disable: 4275)


class DllImpExp ZsdkHiddenLineBase: public ZcRxObject {

protected:
	std::map<ZcDbEntity *, ZcDbVoidPtrArray *> m_entityBodies ;

public:
	ZCRX_DECLARE_MEMBERS (ZsdkHiddenLineBase) ;

	//----- Function to append BODY objects to the list
	//----- If required, then it also indicates which objects the
	//----- body was created from ( important for blocks )
	virtual Zcad::ErrorStatus prepare (ZcDbEntity *pEnt, ZcDbVoidPtrArray &bodies, int control, const ZcDbViewport *pVp) ;
	virtual Zcad::ErrorStatus getBody (void *pBodyData, int control) ;

	static Zcad::ErrorStatus saveData (ZcDbEntity *pEnt, void *pBodyData) ;
	static ZSoft::Boolean retrieveData (ZcDbEntity *pEnt, ZcDbVoidPtrArray &bodies, const ZcDbViewport *pVp =NULL) ;
	
	static void clear () ;
	static void clear (ZcDbEntity *pEnt) ;
	static void clear (ZcDbEntity *pEnt, ZcDbViewport *pVp) ;

    // This method is a specific feature in ZWCAD HLR.
    static bool setDebugMode(bool bDebugMode);
    static bool debugMode();
} ;
