
#ifndef __ASECLASS_H__
#define __ASECLASS_H__

#include <asiappl.h>
#include <aseconst.h>
#include <dbmain.h>
#include "adsdef.h"

#include "../inc/zaseclass.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef ads_name
#define ads_name		zds_name
#endif //#ifndef ads_name

#ifndef getAcadDsPath
#define getAcadDsPath		getZcadDsPath
#endif //#ifndef getAcadDsPath

#ifndef pAcDbDatabase
#define pAcDbDatabase		pZcDbDatabase
#endif //#ifndef pAcDbDatabase

#endif //#ifndef __ASECLASS_H__
