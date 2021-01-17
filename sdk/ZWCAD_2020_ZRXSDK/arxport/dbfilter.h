
#ifndef __DBFILTER_H__
#define __DBFILTER_H__

#include "dbmain.h"

#include "../inc/zdbfilter.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef AcDbFilter
#define AcDbFilter		ZcDbFilter
#endif //#ifndef AcDbFilter

#ifndef AcDbFilteredBlockIterator
#define AcDbFilteredBlockIterator		ZcDbFilteredBlockIterator
#endif //#ifndef AcDbFilteredBlockIterator

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif //#ifndef AcRxClass

#endif //#ifndef __DBFILTER_H__
