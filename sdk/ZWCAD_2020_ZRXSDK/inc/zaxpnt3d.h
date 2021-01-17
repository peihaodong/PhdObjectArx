

#ifndef __ZXPNT3D_H_
#define __ZXPNT3D_H_

#include "zgept3dar.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"
#pragma pack (push, 8)

#ifndef ZXAUTOEXP
#ifdef ZXAUTO_DLL
	#define ZXAUTOEXP __declspec(dllexport)
#else
	#define ZXAUTOEXP __declspec(dllimport)
#endif
#endif

#pragma warning(disable : 4290) 

class ZXAUTOEXP ZcAxPoint3d : public ZcGePoint3d
{
public:
    
    ZcAxPoint3d();
    ZcAxPoint3d(double x, double y, double z);
    ZcAxPoint3d(const ZcGePoint3d& pt);
    ZcAxPoint3d(const ZcGeVector3d& pt);
   	ZcAxPoint3d(const VARIANT* var) throw(HRESULT);
   	ZcAxPoint3d(const VARIANT& var) throw(HRESULT);
   	ZcAxPoint3d(const SAFEARRAY* safeArrayPt) throw(HRESULT);

   	ZcAxPoint3d& operator=(const ZcGePoint3d& pt);
   	ZcAxPoint3d& operator=(const ZcGeVector3d& pt);
   	ZcAxPoint3d& operator=(const VARIANT* var) throw(HRESULT);
   	ZcAxPoint3d& operator=(const VARIANT& var) throw(HRESULT);
   	ZcAxPoint3d& operator=(const SAFEARRAY* safeArrayPt) throw(HRESULT);

    VARIANT* asVariantPtr() const throw(HRESULT);
    SAFEARRAY* asSafeArrayPtr() const throw(HRESULT);

    VARIANT& setVariant(VARIANT& var) const throw(HRESULT);
    VARIANT* setVariant(VARIANT* var) const throw(HRESULT);

private:
    ZcAxPoint3d& fromSafeArray(const SAFEARRAY* safeArrayPt) throw(HRESULT);
};

#pragma warning(disable : 4275) 

class ZXAUTOEXP ZcAxPoint3dArray : public ZcGePoint3dArray
{
public:
    
   	ZcAxPoint3dArray& append(const ZcGePoint3d& pt);
   	ZcAxPoint3dArray& append(const VARIANT* var) throw(HRESULT);
   	ZcAxPoint3dArray& append(const VARIANT& var) throw(HRESULT);
   	ZcAxPoint3dArray& append(const SAFEARRAY* safeArrayPt) throw(HRESULT);

    SAFEARRAY* asSafeArrayPtr() const throw(HRESULT);

    VARIANT& setVariant(VARIANT& var) const throw(HRESULT);
    VARIANT* setVariant(VARIANT* var) const throw(HRESULT);

private:
    ZcAxPoint3dArray& fromSafeArray(const SAFEARRAY* safeArrayPt) throw(HRESULT);
};

#pragma pack (pop)
#endif
