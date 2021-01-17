

#ifndef ZOPM_CATEGORY_H
#define ZOPM_CATEGORY_H

#include "zadesk.h"

#ifdef _ZSOFT_WINDOWS_
DEFINE_GUID(IID_ICategorizeProperties, 0x6dc29a56, 0xf5b9, 0x4ed1, 0xb7, 0xb9, 0xde, 0x76, 0xc2, 0x47, 0x20, 0xfa);
#endif

#define PROPCAT_Nil -1
#define PROPCAT_Misc -2
#define PROPCAT_Font -3
#define PROPCAT_Position -4
#define PROPCAT_Appearance -5
#define PROPCAT_Behavior -6
#define PROPCAT_Data -7
#define PROPCAT_List -8
#define PROPCAT_Text -9
#define PROPCAT_Scale -10
#define PROPCAT_DDE -11
#define PROPCAT_General -12
#define PROPCAT_Mass -13
#define PROPCAT_Pattern -14
#define PROPCAT_DataPoints -15
#define PROPCAT_Mesh -16
#define PROPCAT_ImageAdjust -17
#define PROPCAT_ControlPoints -18
#define PROPCAT_PrimaryUnits -19
#define PROPCAT_AltUnits -20
#define PROPCAT_Fit -21
#define PROPCAT_LinesArrows -22
#define PROPCAT_Tolerances -23
#define PROPCAT_Table     -24
#define PROPCAT_Geometry -25
#define PROPCAT_Section -26
#define PROPCAT_UnderlayAdjust -27
#define PROPCAT_Solid_History -28
#define PROPCAT_Fillet -29
#define PROPCAT_Chamfer -30
#define PROPCAT_3DVisualization -31
#define PROPCAT_Table_Breaks -32
#define PROPCAT_Leaders	-33
#define PROPCAT_Blocks	-34

#ifdef _ZSOFT_WINDOWS_
typedef int PROPCAT;

#undef  INTERFACE
#define INTERFACE  ICategorizeProperties
interface DECLSPEC_UUID("6DC29A56-F5B9-4ED1-B7B9-DE76C24720FA") ICategorizeProperties : public IUnknown
{
    BEGIN_INTERFACE
    
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(MapPropertyToCategory)(THIS_ 
                                      DISPID dispid,
                                      PROPCAT* ppropcat) PURE;
    
    STDMETHOD(GetCategoryName)(THIS_
                                PROPCAT propcat, 
                                LCID lcid,
                                BSTR* pbstrName) PURE;
};

typedef ICategorizeProperties FAR* LPCATEGORIZEPROPERTIES;
#endif

#endif
