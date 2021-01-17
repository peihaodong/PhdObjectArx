
#ifndef __DBIMAGE_H__
#define __DBIMAGE_H__

#include "dbmain.h"
#include "acgi.h"

#include "../inc/zdbimage.h"

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbImage
#define AcDbImage		ZcDbImage
#endif //#ifndef AcDbImage

#ifndef AcGiRequestScanLines
#define AcGiRequestScanLines		ZcGiRequestScanLines
#endif //#ifndef AcGiRequestScanLines

#ifndef AcGiSentScanLines
#define AcGiSentScanLines		ZcGiSentScanLines
#endif //#ifndef AcGiSentScanLines

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#endif //#ifndef __DBIMAGE_H__
