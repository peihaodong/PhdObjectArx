
#ifndef __ACEXTENSIONMODULE_H__
#define __ACEXTENSIONMODULE_H__

#include "acdocman.h"

#include "../inc/zAcExtensionModule.h"

#ifndef AC_DECLARE_EXTENSION_MODULE
#define AC_DECLARE_EXTENSION_MODULE		ZC_DECLARE_EXTENSION_MODULE
#endif //#ifndef AC_DECLARE_EXTENSION_MODULE

#ifndef AC_IMPLEMENT_EXTENSION_MODULE
#define AC_IMPLEMENT_EXTENSION_MODULE		ZC_IMPLEMENT_EXTENSION_MODULE
#endif //#ifndef AC_IMPLEMENT_EXTENSION_MODULE

#ifndef CAcExtensionModule
#define CAcExtensionModule		CZcExtensionModule
#endif //#ifndef CAcExtensionModule

#ifndef CAcModuleResourceOverride
#define CAcModuleResourceOverride		CZcModuleResourceOverride
#endif //#ifndef CAcModuleResourceOverride

#ifndef acDocManager
#define acDocManager		zcDocManager
#endif //#ifndef acDocManager

#endif //#ifndef __ACEXTENSIONMODULE_H__
