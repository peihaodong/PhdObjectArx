
#ifndef __ACTRANS_H__
#define __ACTRANS_H__

#include "rxnames.h"
#include "aced.h"
#include "dbptrar.h"
#include "dbtrans.h"
#include "acdocman.h"

#include "../inc/zactrans.h"

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AcDbTransactionManager
#define AcDbTransactionManager		ZcDbTransactionManager
#endif //#ifndef AcDbTransactionManager

#ifndef AcTransactionManager
#define AcTransactionManager		ZcTransactionManager
#endif //#ifndef AcTransactionManager

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef acDocManager
#define acDocManager		zcDocManager
#endif //#ifndef acDocManager

#ifndef acTransactionManagerPtr
#define acTransactionManagerPtr		zcTransactionManagerPtr
#endif //#ifndef acTransactionManagerPtr

#ifndef aced
#define aced		zced
#endif //#ifndef aced

#ifndef actrTransactionManager
#define actrTransactionManager		zctrTransactionManager
#endif //#ifndef actrTransactionManager

#endif //#ifndef __ACTRANS_H__
