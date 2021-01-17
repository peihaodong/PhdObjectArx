

#ifndef _zrxsrvice_h
#define _zrxsrvice_h 1

#include "zrxobject.h"
#pragma pack (push, 8)

extern "C" {
    typedef ZcRx::AppRetCode (*DepFuncPtr)(ZcRx::AppMsgCode, void*);
}

class ZcRxServicePrototype;
class ZcRxService;

class ZcRxService: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxService);
    ZcRxService();
    virtual ~ZcRxService();

    ZcRxObject* getSysInfo() const;
    void        setSysInfo(ZcRxObject* sysInfoObj);

    void        addDependency();
    void        removeDependency();

    ZSoft::Boolean unloadable() const;

    DepFuncPtr dependencyFunctionPtr();
    void setDependencyFunctionPtr(DepFuncPtr);

private:
    ZcRxServicePrototype* mpImpService;
};

#pragma pack (pop)
#endif
