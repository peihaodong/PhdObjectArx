
#ifndef __OLEAPROT_H__
#define __OLEAPROT_H__

#include "dbmain.h"
#include <wtypes.h>

#include "../inc/zoleaprot.h"

#ifndef AcAxGetOleLinkManager
#define AcAxGetOleLinkManager		ZcAxGetOleLinkManager
#endif //#ifndef AcAxGetOleLinkManager

#ifndef AcAxOleLinkManager
#define AcAxOleLinkManager		ZcAxOleLinkManager
#endif //#ifndef AcAxOleLinkManager

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbSubentId
#define AcDbSubentId		ZcDbSubentId
#endif //#ifndef AcDbSubentId

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#endif //#ifndef __OLEAPROT_H__
