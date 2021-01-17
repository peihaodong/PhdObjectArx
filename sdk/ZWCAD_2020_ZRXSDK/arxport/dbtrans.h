
#ifndef __DBTRANS_H__
#define __DBTRANS_H__

#include "dbapserv.h"

#include "../inc/zdbtrans.h"

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbTransactionManager
#define AcDbTransactionManager		ZcDbTransactionManager
#endif //#ifndef AcDbTransactionManager

#ifndef AcDbVoidPtrArray
#define AcDbVoidPtrArray		ZcDbVoidPtrArray
#endif //#ifndef AcDbVoidPtrArray

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef AcTransaction
#define AcTransaction		ZcTransaction
#endif //#ifndef AcTransaction

#ifndef AcTransactionReactor
#define AcTransactionReactor		ZcTransactionReactor
#endif //#ifndef AcTransactionReactor

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef acdbHostApplicationServices
#define acdbHostApplicationServices		zcdbHostApplicationServices
#endif //#ifndef acdbHostApplicationServices

#ifndef acdbTransactionManager
#define acdbTransactionManager		zcdbTransactionManager
#endif //#ifndef acdbTransactionManager

#ifndef acdbTransactionManagerPtr
#define acdbTransactionManagerPtr		zcdbTransactionManagerPtr
#endif //#ifndef acdbTransactionManagerPtr

#endif //#ifndef __DBTRANS_H__
