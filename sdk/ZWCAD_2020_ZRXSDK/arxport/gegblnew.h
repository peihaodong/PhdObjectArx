
#ifndef __GEGBLNEW_H__
#define __GEGBLNEW_H__

#ifdef GE_LOCATED_NEW
#include "gegblge.h"
#include "gegetmti.h"
#endif

#include "../inc/zgegblnew.h"

#ifndef AcGe
#define AcGe		ZcGe
#endif //#ifndef AcGe

#ifndef AcGeGetMetaTypeIndex
#define AcGeGetMetaTypeIndex		ZcGeGetMetaTypeIndex
#endif //#ifndef AcGeGetMetaTypeIndex

#endif //#ifndef __GEGBLNEW_H__
