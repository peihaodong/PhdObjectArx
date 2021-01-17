
#include "zAdAChar.h"
#ifndef ZMGDHOST_H
#define ZMGDHOST_H 1
#pragma once

class ZcDbManagedHost
{
public:
    virtual int version() { return 1;}
    virtual Zcad::ErrorStatus load(const ZTCHAR * fname)=0;
};

ZcDbManagedHost* ZSOFT_STDCALL zcdbGetManagedHost();
Zcad::ErrorStatus ZSOFT_STDCALL zcdbSetManagedHost(ZcDbManagedHost* pHost);

ZCDB_PORT HRESULT ZSOFT_STDCALL zcdbInitializeManagedLayer();
ZCDB_PORT HRESULT ZSOFT_STDCALL zcdbTerminateManagedLayer();

#endif 
