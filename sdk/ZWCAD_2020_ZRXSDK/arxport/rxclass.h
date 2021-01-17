
#ifndef __RXCLASS_H__
#define __RXCLASS_H__

#include "rxobject.h"
#include "AdAChar.h"

#include "../inc/zrxclass.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AcRx
#define AcRx		ZcRx
#endif //#ifndef AcRx

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif //#ifndef AcRxClass

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef acrxBuildClassHierarchy
#define acrxBuildClassHierarchy		zcrxBuildClassHierarchy
#endif //#ifndef acrxBuildClassHierarchy

#ifndef deleteAcRxClass
#define deleteAcRxClass		deleteZcRxClass
#endif //#ifndef deleteAcRxClass

#ifndef newAcRxClass
#define newAcRxClass		newZcRxClass
#endif //#ifndef newAcRxClass

#endif //#ifndef __RXCLASS_H__
