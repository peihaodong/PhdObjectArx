

#ifndef _ZOPMIMP_H
#define _ZOPMIMP_H

#pragma push_macro("_USE_ANSI_CPP")
#define _USE_ANSI_CPP
#include <vector>
#pragma pop_macro("_USE_ANSI_CPP")

#include <comdef.h>
#include "zAdAChar.h"
#include "zAcpi.h"
#include "zcategory.h"
#pragma pack (push, 8)

struct ZCAD_OPMPROPMAP_ENTRY
{
    UINT nDescID;                  
    DISPID dispid;                 
    PROPCAT  catid;                
    UINT nCatNameID;               
    UINT nElementStrID;            
    UINT nPredefinedStrID;         
    const ZTCHAR *  predefinedValues;
    unsigned short grouping;       
    bool      editable;            
    const CLSID* pclsidOther;      
    const CLSID* pclsidPropPage;   
    const IID* piidDispatch;       
    LPCOLESTR szEllipsesTxt;       
};

#define BEGIN_OPMPROP_MAP()                                 \
    static ZCAD_OPMPROPMAP_ENTRY* GetOPMPropertyMap()               \
    {                                                               \
        static ZCAD_OPMPROPMAP_ENTRY pPropMap[] =                   \
        {

#define OPMPROP_ENTRY(nDesID, dpid, ctid, ctNameID, elementsID, predefID, vals, grp, editable, other, clsid, ellipsesTxt)      \
        {nDesID, dpid, ctid, ctNameID, elementsID, predefID, vals, grp, editable, &other, &clsid, &IID_IDispatch, OLESTR(ellipsesTxt)},
#ifdef _UNICODE
#define OPMPROP_CAT_ENTRY(nDesID, dpid, ctid, ctNameID)      \
        {nDesID, dpid, ctid, ctNameID, 0, 0, _ZCRX_T(""), 0, 1, &IID_NULL, &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_DESC_ENTRY(nDesID, dpid)      \
        {nDesID, dpid, -2, 0, 0, 0, _ZCRX_T(""), 0, 1, &IID_NULL, &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_PREDEFINED_ENTRY(nDesID, dpid, predefID, values, other)      \
        {nDesID, dpid, -2, 0, 0, predefID, values, 0, 1, &other, &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_ELEMENT_ENTRY(dpid, ctid, ctNameID, elementsID, grouping)      \
        {0, dpid, ctid, ctNameID, elementsID, 0, _ZCRX_T(""), grouping, 1, &IID_NULL, &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_PAGE(nDesID, dpid, ctid, ctNameID, clsid)      \
        {nDesID, dpid, ctid, ctNameID, 0, 0, _ZCRX_T(""), 0, 1, &IID_NULL, &clsid, &IID_IDispatch, OLESTR("")},
#else
#define OPMPROP_CAT_ENTRY(nDesID, dpid, ctid, ctNameID)      \
		{nDesID, dpid, ctid, ctNameID, 0, 0, ZCRX_T(""), 0, 1, &IID_NULL, &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_DESC_ENTRY(nDesID, dpid)      \
		{nDesID, dpid, -2, 0, 0, 0, ZCRX_T(""), 0, 1, &IID_NULL, &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_PREDEFINED_ENTRY(nDesID, dpid, predefID, values, other)      \
		{nDesID, dpid, -2, 0, 0, predefID, values, 0, 1, &other, &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_ELEMENT_ENTRY(dpid, ctid, ctNameID, elementsID, grouping)      \
		{0, dpid, ctid, ctNameID, elementsID, 0, ZCRX_T(""), grouping, 1, &IID_NULL, &IID_NULL, &IID_IDispatch, OLESTR("")},

#define OPMPROP_PAGE(nDesID, dpid, ctid, ctNameID, clsid)      \
		{nDesID, dpid, ctid, ctNameID, 0, 0, ZCRX_T(""), 0, 1, &IID_NULL, &clsid, &IID_IDispatch, OLESTR("")},
#endif
#define END_OPMPROP_MAP()                                           \
            {0, 0, 0, 0, 0, 0, NULL, 0, 0, NULL, NULL, &IID_NULL, NULL}            \
        };                                                          \
        return pPropMap;                                            \
    }

typedef BOOL (*BUTTONPROC)(IZcPiCommandButton* pButton, VARIANT Objects);
typedef int PROPCAT;

struct PER_PROP_DISP_ENTRY
{
    DISPID    m_dispid;
    const ZTCHAR * m_ProgID;
    const ZTCHAR * m_lpLeftIconRes;
    UINT      m_nLeftIconType;
    const ZTCHAR * m_lpEllipsisBmpRes;
    UINT      m_nEllipsisBmpType;
    COLORREF  m_TextColor;
    bool      m_bFullView;
    DWORD     m_dwIntegralHeight;
    long      m_nWeight;

};

#define BEGIN_PERPROPDISPLAY_MAP()                                                            \
    static PER_PROP_DISP_ENTRY* GetPerPropDisplayArray()                                    \
    {                                                                                        \
        static PER_PROP_DISP_ENTRY pPerPropDisplayArray[] =                                 \
        {
                                                                                            
#define PROP_DISP_ENTRY(dispid, progid, lpLeftIconRes, lpLeftIconType,                        \
    lpEllipsisBmpRes, lpEllipsisBmpType, textcolor,                                          \
    bFullView, dwIntegralHeight, nWeight)                                                    \
        {dispid, progid, lpLeftIconRes, lpLeftIconType, lpEllipsisBmpRes,                    \
        lpEllipsisBmpType, textcolor, bFullView,                                             \
        dwIntegralHeight, nWeight},                                                            \
                                                                                            
#define END_PERPROPDISPLAY_MAP()                                                            \
        {-1, NULL, NULL, PICTYPE_UNINITIALIZED, NULL, PICTYPE_UNINITIALIZED, 0x80000008, false, -1, -1}                    \
        };                                                                                    \
        return pPerPropDisplayArray;                                                        \
    }

struct CATCMDBTN_ENTRY
{
    PROPCAT     m_CatID;
    UINT        m_nBtnNameId;
    const ZTCHAR * m_lpEnBtnBmpRes;
    UINT        m_nEnBtnBmpType;
    const ZTCHAR * m_lpDisBtnBmpRes;
    UINT        m_nDisBtnBmpType;
    long        m_nStyle;
    BUTTONPROC  m_pfnBtnProc;
};

#define BEGIN_CATCMDBTN_MAP()                                                               \
    static CATCMDBTN_ENTRY * GetCmdBtnArray()                                               \
    {                                                                                       \
        static CATCMDBTN_ENTRY pCatCmdBtnArray[] =                                          \
        {

#define CATCMDBTN_MAP_ENTRY(nId, NameId,                                                    \
                            lpEnBtnBmpRes, lpEnBtnBmpType, lpDisBtnBmpRes, lpDisBtnBmpType, \
                            nStyle, pfnBtnProc)                                             \
            {nId, NameId, lpEnBtnBmpRes, lpEnBtnBmpType, lpDisBtnBmpRes, lpDisBtnBmpType, nStyle, pfnBtnProc},                        
                                                                                            
#define END_CATCMDBTN_MAP()                                                                 \
            {-1, 0, NULL, PICTYPE_UNINITIALIZED, NULL, PICTYPE_UNINITIALIZED, NULL, NULL}   \
        };                                                                                  \
        return pCatCmdBtnArray;                                                             \
    }

struct CMDBTN_ENTRY
{
    UINT        m_nBtnNameId;
    const ZTCHAR * m_lpEnBtnBmpRes;
    UINT        m_nEnBtnBmpType;
    const ZTCHAR * m_lpDisBtnBmpRes;
    UINT        m_nDisBtnBmpType;
    long        m_nStyle;
    BUTTONPROC  m_pfnBtnProc; 
};

#define BEGIN_CMDBTN_MAP()                                                              \
    static CMDBTN_ENTRY * GetPropCmdBtnArray()                                          \
    {                                                                                   \
        static CMDBTN_ENTRY pCmdBtnArray[] =                                            \
        {

#define CMDBTN_MAP_ENTRY(NameId, lpEnBtnBmpRes, lpEnBtnBmpType,                         \
                         lpDisBtnBmpRes, lpDisBtnBmpType, nStyle, pfnBtnProc)             \
            {NameId, lpEnBtnBmpRes, lpEnBtnBmpType, lpDisBtnBmpRes, lpDisBtnBmpType, nStyle, pfnBtnProc},                        
                                                                                            
#define END_CMDBTN_MAP()                                                                \
            {0, NULL, PICTYPE_UNINITIALIZED, NULL, PICTYPE_UNINITIALIZED, NULL, NULL}   \
        };                                                                              \
        return pCmdBtnArray;                                                            \
    }

struct CATEGORY_ENTRY
{
    PROPCAT   m_CatID;
    UINT      m_nNameId;
    UINT      m_nDescId;
    PROPCAT   m_ParentCatID;
    long      m_nWeight;
};

#define BEGIN_CAT_MAP()                                                                        \
    static CATEGORY_ENTRY*  GetCatArray()                                                    \
    {                                                                                        \
        static CATEGORY_ENTRY pCatArray[] =                                                 \
        {

#define CATEGORY_MAP_ENTRY(nId, NameId, DescId, nParentId, nWeight)              \
            {nId, NameId, DescId, nParentId, nWeight}, 

#define END_CAT_MAP()                                                                        \
            {-1, 0, 0, -1, -1}                                                  \
        };                                                                                    \
        return pCatArray;                                                                    \
    }

typedef std::vector<PER_PROP_DISP_ENTRY> PROP_DISP_VECTOR;
typedef std::vector<CATCMDBTN_ENTRY> CATCMDBTN_VECTOR;
typedef std::vector<CATEGORY_ENTRY> CATEGORY_VECTOR;
typedef std::vector<CMDBTN_ENTRY> CMDBTN_VECTOR;

#pragma pack (pop)
#include "opmdrvr.h"

#endif 
