

#ifndef   _ZRXDEFS_H_
#define   _ZRXDEFS_H_

#include "zadesk.h"
#pragma pack (push, 8)

#ifdef _ZSOFT_WINDOWS_
#define NULLFCN static_cast<ZSoft::IntPtr>(0)
#else
#define NULLFCN nullptr
#endif

#define ZCRX_ULONG_MAX 0xFFFFFFFF

#define ZCRX_ASCII_MAX 255  
#define ZCRX_EOS 0          

struct ZcRx {

    typedef void (*FcnPtr) ();

    enum         DictIterType { kDictSorted   = 0,
                                kDictCollated = 1 };

    enum         Ordering     { kLessThan     = -1,
                                kEqual        = 0,
                                kGreaterThan  = 1,
                                kNotOrderable = 2 };

    enum         AppMsgCode   { kNullMsg         = 0,
                                kInitAppMsg      = 1,
                                kUnloadAppMsg    = 2,
                                kLoadDwgMsg      = 3,
                                kUnloadDwgMsg    = 4,
                                kInvkSubrMsg     = 5,
                                kCfgMsg          = 6,
                                kEndMsg          = 7,
                                kQuitMsg         = 8,
                                kSaveMsg         = 9,
                                kDependencyMsg   = 10,
                                kNoDependencyMsg = 11,
                                kOleUnloadAppMsg = 12,
                                kPreQuitMsg      = 13,
                                kInitDialogMsg   = 14,
                                kEndDialogMsg    = 15,                                
								kSuspendMsg      = 16,
								kInitTabGroupMsg = 17,
								kEndTabGroupMsg  = 18 };

    enum        AppRetCode   { kRetOK          = 0,
                                kRetError       = 3 };
};

#ifndef kLoadZDSMsg
#define kLoadZDSMsg kLoadDwgMsg
#define kUnloadZDSMsg kUnloadDwgMsg
#endif

class ZcRxClass;
typedef void (*AppNameChangeFuncPtr)(const ZcRxClass* classObj,
                ZTCHAR *& newAppName, int saveVer);

#pragma pack (pop)

#endif
