

#ifndef __ZAXMAT3D_H_
#define __ZAXMAT3D_H_

#include "zgemat3d.h"
#pragma pack (push, 8)

#ifndef ZXAUTOEXP
#ifdef ZXAUTO_DLL
	#define ZXAUTOEXP __declspec(dllexport)
#else
	#define ZXAUTOEXP __declspec(dllimport)
#endif
#endif

class ZXAUTOEXP ZcAxMatrix3d : public ZcGeMatrix3d
{
public:
    
    ZcAxMatrix3d();
    ZcAxMatrix3d(const VARIANT* var) throw(HRESULT);
    ZcAxMatrix3d(const VARIANT& var) throw(HRESULT);
    ZcAxMatrix3d(const SAFEARRAY* safeArrayPt) throw(HRESULT);

    ZcAxMatrix3d& operator=(const VARIANT* var) throw(HRESULT);
    ZcAxMatrix3d& operator=(const VARIANT& var) throw(HRESULT);
    ZcAxMatrix3d& operator=(const SAFEARRAY* safeArrayPt) throw(HRESULT);

private:
    ZcAxMatrix3d& fromSafeArray(const SAFEARRAY* safeArrayPt) throw(HRESULT);
};

#pragma pack (pop)
#endif

