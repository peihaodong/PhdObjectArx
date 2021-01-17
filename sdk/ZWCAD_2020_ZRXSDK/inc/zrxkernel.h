

#ifndef _zrxkernel_h
#define _zrxkernel_h 1

#include "zrxsrvice.h"
#pragma pack (push, 8)

class ZcRxClass;
class ZcRxDictionary;

class ZSOFT_NO_VTABLE ZcRxKernel : public ZcRxService
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxKernel);
    ZcRxKernel();
    virtual ~ZcRxKernel();

    virtual
    ZcRxDictionary* newZcRxDictionary(ZSoft::Boolean sorted = ZSoft::kTrue,
                                      ZSoft::Boolean ignoreCase
                                                           = ZSoft::kFalse) = 0;

    virtual
    ZcRxDictionary* newZcRxDictionary(ZSoft::UInt32 length,
                                      ZSoft::Boolean delObjects,
                                      ZSoft::Boolean sorted = ZSoft::kTrue,
                                      ZSoft::Boolean ignoreCase
                                                           = ZSoft::kFalse) = 0;

    virtual
    ZcRxDictionary* newZcRxDictionary(const ZcRxClass * filter) = 0;
};

#define zcrxKernel \
    ZcRxKernel::cast(ZcRxDictionary::cast(\
    zcrxSysRegistry()->at(ZCRX_SERVICE_DICTIONARY))->at(ZCRX_KERNEL_SERVICES))

#pragma pack (pop)
#endif
