// SignEntity.cpp : Implementation of CSignEntity

#include "stdafx.h"
#include "SignEntity.h"
#include "../SignDb/ZsdkSign.h"

#include "axpnt3d.h"
#include "dbproxy.h"
#include "dbxutil.h"
#include "geassign.h"
#include "AcPExCtl.h"
#include "AcPExCtl_i.c"
#include "acadi_i.c"


#define AXEntityDocLock(objId)                              \
    AcAxDocLock docLock(objId, AcAxDocLock::kNormal);       \
    if(docLock.lockStatus() != Acad::eOk)                   \
        throw docLock.lockStatus();

#define CHECKOUTPARAM(x) if (x==NULL) return E_POINTER;

ACRX_DEFINE_MEMBERS(ZsdkSign);

// CSignEntity

STDMETHODIMP CSignEntity::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_ISignEntity
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CSignEntity::get_Normal(VARIANT* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CHECKOUTPARAM(pVal);
    try
    {
        Acad::ErrorStatus es;
        AcDbObjectPointer<ZsdkSign> pSign(m_objId, AcDb::kForRead, Adesk::kTrue);
	    if((es = pSign.openStatus()) != Acad::eOk)
            throw es;
        AcAxPoint3d pt = pSign->normal();
        pt.setVariant(pVal);
    }
    catch(const Acad::ErrorStatus)
    {
        return Error(L"Failed to open object.", IID_ISignEntity, E_FAIL);
    }
    catch(const HRESULT hr)
    {
        return Error(L"Invalid argument.", IID_ISignEntity, hr);
    }

	return S_OK;
}


STDMETHODIMP CSignEntity::put_Normal(VARIANT newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	try
    {
        AcAxPoint3d pt = newVal;
        AXEntityDocLock(m_objId);

        Acad::ErrorStatus es;
        AcDbObjectPointer<ZsdkSign> pSign(m_objId,AcDb::kForWrite,Adesk::kTrue);
	    if((es = pSign.openStatus()) != Acad::eOk)
            throw es;
        
        pSign->setNormal(pt.asVector());
    }
    catch(const Acad::ErrorStatus)
    {
        return Error(L"Failed to open object.", IID_ISignEntity, E_FAIL);
    }
    catch(const HRESULT hr)
    {
        return Error(L"Invalid argument.", IID_ISignEntity, hr);
    }

	return S_OK;
}


STDMETHODIMP CSignEntity::get_Center(VARIANT* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CHECKOUTPARAM(pVal);
	try
	{
		Acad::ErrorStatus es;
		AcDbObjectPointer<ZsdkSign> pSign(m_objId,AcDb::kForRead,Adesk::kTrue);
		if((es=pSign.openStatus()) != Acad::eOk)
			throw es;
		AcAxPoint3d pt = pSign->center();
		pt.setVariant(pVal);
	}
	catch(const Acad::ErrorStatus)
	{
		return Error(L"Failed to open object.", IID_ISignEntity, E_FAIL);
	}
	catch(const HRESULT hr)
	{
		return Error(L"Invalid argument.", IID_ISignEntity, hr);
	}

	return S_OK;
}


STDMETHODIMP CSignEntity::put_Center(VARIANT newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	try
    {
        AcAxPoint3d pt = newVal;
        AXEntityDocLock(m_objId);

        Acad::ErrorStatus es;
        AcDbObjectPointer<ZsdkSign> pSign(m_objId,AcDb::kForWrite,Adesk::kTrue);
	    if((es=pSign.openStatus()) != Acad::eOk)
            throw es;
        
        pSign->setCenter(pt);
    }
    catch(const Acad::ErrorStatus)
    {
        return Error(L"Failed to open object.", IID_ISignEntity, E_FAIL);
    }
    catch(const HRESULT hr)
    {
        return Error(L"Invalid argument.", IID_ISignEntity, hr);
    }

	return S_OK;
}


STDMETHODIMP CSignEntity::get_Radius(DOUBLE* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CHECKOUTPARAM(pVal);
    try
    {
        Acad::ErrorStatus es;
        AcDbObjectPointer<ZsdkSign> pSign(m_objId, AcDb::kForRead, Adesk::kTrue);
	    if((es=pSign.openStatus()) != Acad::eOk)
            throw es;
        
        *pVal = pSign->radius();
    }
    catch(const Acad::ErrorStatus)
    {
        return Error(L"Failed to open object.", IID_ISignEntity, E_FAIL);
    }

	return S_OK;
}


STDMETHODIMP CSignEntity::put_Radius(DOUBLE newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	try
    {
        AXEntityDocLock(m_objId);

        Acad::ErrorStatus es;
        AcDbObjectPointer<ZsdkSign> pSign(m_objId, AcDb::kForWrite, Adesk::kTrue);
	    if((es = pSign.openStatus()) != Acad::eOk)
            throw es;
        
        pSign->setRadius(newVal);
    }
    catch(const Acad::ErrorStatus)
    {
        return Error(L"Failed to open object.", IID_ISignEntity, E_FAIL);
    }

	return S_OK;
}


STDMETHODIMP CSignEntity::get_TextTrueColor(IAcadAcCmColor** pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CHECKOUTPARAM(pVal);
    try
    {
        AXEntityDocLock(m_objId);

        Acad::ErrorStatus es;
        AcDbObjectPointer<ZsdkSign> pSign(m_objId, AcDb::kForRead, Adesk::kTrue);
	    if((es=pSign.openStatus()) != Acad::eOk)
            throw es;
        
        AcCmColor color = pSign->textTrueColor();
		
		CComPtr<IAcadAcCmColor> pLocalColor;
		_com_util::CheckError(pLocalColor.CoCreateInstance(CLSID_AcadAcCmColor));

		_com_util::CheckError(pLocalColor->put_EntityColor(color.color()));
		USES_CONVERSION;
		_com_util::CheckError(pLocalColor->SetNames(BSTR(T2OLE((TCHAR*)color.colorName())), BSTR(T2OLE((TCHAR*)color.bookName()))));

		_com_util::CheckError(pLocalColor.CopyTo(pVal));
    }
    catch(const Acad::ErrorStatus)
    {
        return Error(L"Failed to open object.", IID_ISignEntity, E_FAIL);
    }
    catch(const HRESULT hr)
    {
        return Error(L"Invalid argument.", IID_ISignEntity, hr);
    }

	return S_OK;
}


STDMETHODIMP CSignEntity::put_TextTrueColor(IAcadAcCmColor* newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CHECKOUTPARAM(newVal);
    try
    {
        AXEntityDocLock(m_objId);

        Acad::ErrorStatus es;
        AcDbObjectPointer<ZsdkSign> pSign(m_objId,AcDb::kForWrite,Adesk::kTrue);
	    if((es=pSign.openStatus()) != Acad::eOk)
            throw es;
        
        AcCmColor color;
		long eColor;
		_com_util::CheckError(newVal->get_EntityColor(&eColor));
		color.setColor(eColor);
		BSTR bstr;
		_com_util::CheckError(newVal->get_ColorName(&bstr));
		_bstr_t colorName(bstr, false);
		_com_util::CheckError(newVal->get_BookName(&bstr));
		_bstr_t bookName(bstr, false);
		USES_CONVERSION;
		color.setNames(AcString(W2T(colorName)), AcString(W2T(bookName)));
		
        pSign->setTextTrueColor(color);
    }
    catch(const Acad::ErrorStatus)
    {
        return Error(L"Failed to open object.", IID_ISignEntity, E_FAIL);
    }
    catch(const HRESULT hr)
    {
        return Error(L"Invalid argument.", IID_ISignEntity, hr);
    }

	return S_OK;
}


STDMETHODIMP CSignEntity::get_Text(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CHECKOUTPARAM(pVal);
    try
    {
        Acad::ErrorStatus es;
        AcDbObjectPointer<ZsdkSign> pSign(m_objId, AcDb::kForRead, Adesk::kTrue);
	    if((es = pSign.openStatus()) != Acad::eOk)
            throw es;
        
		USES_CONVERSION;
		_bstr_t bstr = A2W(pSign->text());
		*pVal = bstr.copy();
    }
    catch(const Acad::ErrorStatus)
    {
        return Error(L"Failed to open object.", IID_ISignEntity, E_FAIL);
    }

	return S_OK;
}


STDMETHODIMP CSignEntity::put_Text(BSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	try
    {
        AXEntityDocLock(m_objId);

        Acad::ErrorStatus es;
        AcDbObjectPointer<ZsdkSign> pSign(m_objId, AcDb::kForWrite, Adesk::kTrue);
	    if((es = pSign.openStatus()) != Acad::eOk)
            throw es;

		USES_CONVERSION;
		pSign->setText(AcString(W2T(newVal)));
    }
    catch(const Acad::ErrorStatus)
    {
        return Error(L"Failed to open object.", IID_ISignEntity, E_FAIL);
    }

	return S_OK;
}

/////////////////////////////////////////////////////////////////
// IAcadBaseObjectImpl
HRESULT CSignEntity::CreateNewObject(AcDbObjectId& objId, AcDbObjectId& ownerId, TCHAR* keyName)
{
    try 
    {
        AXEntityDocLock(ownerId);
        Acad::ErrorStatus es;
        ZsdkSign *pSign = (ZsdkSign*)ZsdkSign::desc()->create();
        if ( NULL == pSign )
            throw Acad::eOutOfMemory;
        AcDbDatabase* pDb = ownerId.database();
        pSign->setDatabaseDefaults(pDb);
        AcDbBlockTableRecordPointer pBlockTableRecord(ownerId, AcDb::kForWrite);
        if((es = pBlockTableRecord.openStatus()) != Acad::eOk)
		{
			delete pSign;
            throw es;
		}
        if((es = pBlockTableRecord->appendAcDbEntity(objId, pSign)) != Acad::eOk)
		{
			delete pSign;
            throw es;
		}
		pSign->close();
    }
    catch(const Acad::ErrorStatus)
    {
        return Error(L"Failed to create Smiley through entity interface.", IID_ISignEntity, E_FAIL);
    }
    return S_OK;
}

/////////////////////////////////////////////////////////////////
// IOPMPropertyExtensionImpl

HINSTANCE CSignEntity::GetResourceInstance()
{
	return AfxGetApp()->m_hInstance;
}

/////////////////////////////////////////////////////////////////
// IOPMPropertyExpander

HRESULT STDMETHODCALLTYPE CSignEntity::GetElementValue(
	DISPID dispID,
	DWORD dwCookie,
	VARIANT * pVarOut)
{
	CHECKOUTPARAM(pVarOut);
	if ( 0x01 == dispID || 0x02 == dispID )
	{
		try
		{
			if( dwCookie > 2 )
				throw Acad::eInvalidInput;
			Acad::ErrorStatus es;
			AcDbObjectPointer<ZsdkSign> pSign(m_objId, AcDb::kForRead, Adesk::kTrue);
			if(( es = pSign.openStatus()) != Acad::eOk)
				throw es;

			AcAxPoint3d pt;
			switch( dispID )
			{
			case 0x02:
				pt = pSign->center();
				break;
			case 0x01:
				pt = pSign->normal();
				break;
			default:
				throw Acad::eInvalidInput;
			}
			acdbWcs2Ucs( asDblArray( pt ), asDblArray( pt ), Adesk::kTrue );
			::VariantCopy( pVarOut, &CComVariant( pt[dwCookie] ));
		}
		catch( const Acad::ErrorStatus )
		{
			return Error( L"Failed to open object", IID_ISignEntity, E_FAIL );
		}
		catch( const HRESULT hr )
		{
			return Error( L"Invalid argument.", IID_ISignEntity, hr );
		}
	}
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CSignEntity::SetElementValue(
	DISPID dispID,
	DWORD dwCookie,
	VARIANT VarIn)
{
	if ( 0x01 == dispID || 0x02 == dispID )
	{
		try
		{
			if ( dwCookie > 2 )
				throw Acad::eInvalidInput;
			Acad::ErrorStatus es;
			AcDbObjectPointer<ZsdkSign> pSign( m_objId, AcDb::kForWrite, Adesk::kTrue );
			if(( es = pSign.openStatus()) != Acad::eOk )
				throw es;

			AcAxPoint3d pt;
			switch( dispID )
			{
			case 0x02:
				pt = pSign->center();
				break;
			case 0x01:
				pt = pSign->normal();
				break;
			default:
				throw Acad::eInvalidInput;
			}
			//translate from wcs to ucs
			acdbEcs2Ucs(asDblArray(pt), asDblArray(pt), asDblArray(pSign->normal()), Adesk::kTrue);

			pt[dwCookie] = V_R8(&VarIn);

			acdbUcs2Wcs(asDblArray(pt), asDblArray(pt), Adesk::kTrue);

			switch ( dispID )
			{
			case 0x02:
				pSign->setCenter( pt );
				break;
			case 0x01:
				pSign->setNormal( pt.asVector() );
				break;
			}
		}
		catch(const Acad::ErrorStatus)
		{
			return Error(L"Failed to open object", IID_ISignEntity, E_FAIL);
		}
		catch(const HRESULT hr)
		{
			return Error(L"Invalid argument.", IID_ISignEntity, hr);
		}

	}
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CSignEntity::GetElementStrings( 
	DISPID dispID,
	OPMLPOLESTR __RPC_FAR *pCaStringsOut,
	OPMDWORD __RPC_FAR *pCaCookiesOut)
{
	if ( 0x01 == dispID || 0x02 == dispID )
    {
        long size = 3;
        pCaStringsOut->pElems = (LPOLESTR *)::CoTaskMemAlloc(sizeof(LPOLESTR) * size);
        pCaCookiesOut->pElems = (DWORD *)::CoTaskMemAlloc(sizeof(DWORD) * size);
        for ( long i=0; i<size; i++)
            pCaCookiesOut->pElems[i] = i;
        pCaStringsOut->cElems = size;
        pCaCookiesOut->cElems = size;

		switch ( dispID )
        {
			case 0x02:
				pCaStringsOut->pElems[0] = ::SysAllocString(L"Center X");
				pCaStringsOut->pElems[1] = ::SysAllocString(L"Center Y");
				pCaStringsOut->pElems[2] = ::SysAllocString(L"Center Z");
				break;
			case 0x01:
				pCaStringsOut->pElems[0] = ::SysAllocString(L"Normal X");
				pCaStringsOut->pElems[1] = ::SysAllocString(L"Normal Y");
				pCaStringsOut->pElems[2] = ::SysAllocString(L"Normal Z");
				break;
		}
    }

    return S_OK;
}

HRESULT STDMETHODCALLTYPE CSignEntity::GetElementGrouping(
	DISPID dispID,
	short *groupingNumber)
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CSignEntity::GetGroupCount(
	DISPID dispID,
	long *nGroupCnt)
{
	return E_NOTIMPL;
}

/////////////////////////////////////////////////////////////////
// IPerPropertyDisplay

HRESULT STDMETHODCALLTYPE CSignEntity::GetCustomPropertyCtrl(
	VARIANT Id,
	LCID lcid,
	BSTR *pProgId)
{
	LPOLESTR pOleStr = NULL;
    HRESULT hr = E_NOTIMPL;
    if (Id.lVal == 12) 
        hr = ProgIDFromCLSID(CLSID_PropertyEditorColor, &pOleStr);

    if (SUCCEEDED(hr)) {
        if (pOleStr) {
            CComBSTR bstrStr(pOleStr);
            *pProgId = bstrStr.Copy();
            CoTaskMemFree(pOleStr);
        } else {
            hr = E_POINTER;
        }
    }
    return hr;
}

HRESULT STDMETHODCALLTYPE CSignEntity::GetPropertyIcon(
	VARIANT Id,
	IUnknown **pIcon)
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CSignEntity::GetPropTextColor(
	VARIANT Id,
	OLE_COLOR *pTextColor)
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CSignEntity::IsFullView(
	VARIANT Id,
	VARIANT_BOOL *pbVisible,
	DWORD *pIntegralHeight)
{
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CSignEntity::GetPropertyWeight(
	VARIANT Id,
	long *pPropertyWeight)
{
	return E_NOTIMPL;
}
