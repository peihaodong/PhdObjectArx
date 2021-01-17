
#ifndef __DBLYFILT_H__
#define __DBLYFILT_H__

#include "dbfilter.h"
#include "AdAChar.h"

#include "../inc/zdblyfilt.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcDbFilter
#define AcDbFilter		ZcDbFilter
#endif //#ifndef AcDbFilter

#ifndef AcDbLayerFilter
#define AcDbLayerFilter		ZcDbLayerFilter
#endif //#ifndef AcDbLayerFilter

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif //#ifndef AcRxClass

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#endif //#ifndef __DBLYFILT_H__
