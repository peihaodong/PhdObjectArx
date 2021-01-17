

#ifndef __ZXPNT2D_H_
#define __ZXPNT2D_H_

#include "zgept2dar.h"
#include "zgepnt2d.h"
#include "zgevec2d.h"
#pragma pack (push, 8)

#ifndef ZXAUTOEXP
#ifdef ZXAUTO_DLL
	#define ZXAUTOEXP __declspec(dllexport)
#else
	#define ZXAUTOEXP __declspec(dllimport)
#endif
#endif

#pragma warning(disable : 4290) 

class ZXAUTOEXP ZcAxPoint2d : public ZcGePoint2d
{
public:
    
    ZcAxPoint2d();
    ZcAxPoint2d(double x, double y);
    ZcAxPoint2d(const ZcGePoint2d& pt);
    ZcAxPoint2d(const ZcGeVector2d& pt);
   	ZcAxPoint2d(const VARIANT* var) throw(HRESULT);
   	ZcAxPoint2d(const VARIANT& var) throw(HRESULT);
   	ZcAxPoint2d(const SAFEARRAY* safeArrayPt) throw(HRESULT);

   	ZcAxPoint2d& operator=(const ZcGePoint2d& pt);
   	ZcAxPoint2d& operator=(const ZcGeVector2d& pt);
   	ZcAxPoint2d& operator=(const VARIANT* var) throw(HRESULT);
   	ZcAxPoint2d& operator=(const VARIANT& var) throw(HRESULT);
   	ZcAxPoint2d& operator=(const SAFEARRAY* safeArrayPt) throw(HRESULT);

    VARIANT* asVariantPtr() const throw(HRESULT);
    SAFEARRAY* asSafeArrayPtr() const throw(HRESULT);

    VARIANT& setVariant(VARIANT& var) const throw(HRESULT);
    VARIANT* setVariant(VARIANT* var) const throw(HRESULT);

private:
    ZcAxPoint2d& fromSafeArray(const SAFEARRAY* safeArrayPt) throw(HRESULT);
};

#pragma warning(disable : 4275) 

class ZXAUTOEXP ZcAxPoint2dArray : public ZcGePoint2dArray
{
public:
    
   	ZcAxPoint2dArray& append(const ZcGePoint2d& pt);
   	ZcAxPoint2dArray& append(const VARIANT* var) throw(HRESULT);
   	ZcAxPoint2dArray& append(const VARIANT& var) throw(HRESULT);
   	ZcAxPoint2dArray& append(const SAFEARRAY* safeArrayPt) throw(HRESULT);

    SAFEARRAY* asSafeArrayPtr() const throw(HRESULT);

    VARIANT& setVariant(VARIANT& var) const throw(HRESULT);
    VARIANT* setVariant(VARIANT* var) const throw(HRESULT);

private:
    ZcAxPoint2dArray& fromSafeArray(const SAFEARRAY* safeArrayPt) throw(HRESULT);
};

#pragma pack (pop)
#endif
