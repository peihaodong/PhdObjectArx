
#ifndef __DBLAYMGRRCTR_H__
#define __DBLAYMGRRCTR_H__

#include "rxobject.h"
#include "dbid.h"
#include "AdAChar.h"

#include "../inc/zdblaymgrrctr.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AcDbLayoutManagerReactor
#define AcDbLayoutManagerReactor		ZcDbLayoutManagerReactor
#endif //#ifndef AcDbLayoutManagerReactor

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#endif //#ifndef __DBLAYMGRRCTR_H__
