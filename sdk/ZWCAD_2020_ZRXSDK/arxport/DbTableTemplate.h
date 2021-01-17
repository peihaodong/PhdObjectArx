

#ifndef __DBTABLETEMPLATE_H__
#define __DBTABLETEMPLATE_H__

#include "DbTableContent.h"

#include "../inc/zDbTableTemplate.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbDwgFiler
#define AcDbDwgFiler		ZcDbDwgFiler
#endif //#ifndef AcDbDwgFiler

#ifndef AcDbDxfFiler
#define AcDbDxfFiler		ZcDbDxfFiler
#endif //#ifndef AcDbDxfFiler

#ifndef AcDbTable
#define AcDbTable		ZcDbTable
#endif //#ifndef AcDbTable

#ifndef AcDbTableContent
#define AcDbTableContent		ZcDbTableContent
#endif //#ifndef AcDbTableContent

#ifndef AcDbTableTemplate
#define AcDbTableTemplate		ZcDbTableTemplate
#endif //#ifndef AcDbTableTemplate

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#endif //#ifndef __DBTABLETEMPLATE_H__
