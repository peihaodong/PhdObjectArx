
#ifndef __ACEDSUBSEL_H__
#define __ACEDSUBSEL_H__

#include "acarray.h"
#include "acdb.h"
#include "adsdef.h"

#include "../inc/zacedsubsel.h"

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbFullSubentPath
#define AcDbFullSubentPath		ZcDbFullSubentPath
#endif //#ifndef AcDbFullSubentPath

#ifndef acedSSSetSubentTypes
#define acedSSSetSubentTypes		zcedSSSetSubentTypes
#endif //#ifndef acedSSSetSubentTypes

#ifndef acedSSSubentAdd
#define acedSSSubentAdd		zcedSSSubentAdd
#endif //#ifndef acedSSSubentAdd

#ifndef acedSSSubentDel
#define acedSSSubentDel		zcedSSSubentDel
#endif //#ifndef acedSSSubentDel

#ifndef acedSSSubentLength
#define acedSSSubentLength		zcedSSSubentLength
#endif //#ifndef acedSSSubentLength

#ifndef acedSSSubentMemb
#define acedSSSubentMemb		zcedSSSubentMemb
#endif //#ifndef acedSSSubentMemb

#ifndef acedSSSubentName
#define acedSSSubentName		zcedSSSubentName
#endif //#ifndef acedSSSubentName

#ifndef acedSSSubentNameX
#define acedSSSubentNameX		zcedSSSubentNameX
#endif //#ifndef acedSSSubentNameX

#ifndef ads_name
#define ads_name		zds_name
#endif //#ifndef ads_name

#endif //#ifndef __ACEDSUBSEL_H__
