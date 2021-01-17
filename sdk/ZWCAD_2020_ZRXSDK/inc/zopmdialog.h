

#ifndef _ZOPMDIALOG_H
#define _ZOPMDIALOG_H

DEFINE_GUID(IID_IOPMPropertyDialog, 0x63042eae, 0x7c21, 0x468e, 0xa7, 0xad, 0x74, 0xc5, 0x13, 0x46, 0x61, 0x99);

interface DECLSPEC_UUID("63042EAE-7C21-468E-A7AD-74C513466199") IOPMPropertyDialog : public IUnknown
{
    BEGIN_INTERFACE
    
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(DoModal)(THIS_  BSTR* propValueString, ZcDbObjectIdArray* ObjectIdArray) PURE;
};

typedef IOPMPropertyDialog FAR* LPPROPERTYDIALOG;

DEFINE_GUID(IID_IOPMPropertyDialog2, 0xc9645c1e, 0x2870, 0x4907, 0x89, 0xb8, 0x19, 0x4b, 0x95, 0x37, 0x7e, 0xeb);

interface DECLSPEC_UUID("C9645C1E-2870-4907-89B8-194B95377EEB")  IOPMPropertyDialog2 : public IUnknown
{
    BEGIN_INTERFACE
    
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(DoModal)(THIS_  BSTR* propValueString, VARIANT ObjectUnknownArray) PURE;
};

typedef IOPMPropertyDialog2 FAR* LPPROPERTYDIALOG2;

#endif 
