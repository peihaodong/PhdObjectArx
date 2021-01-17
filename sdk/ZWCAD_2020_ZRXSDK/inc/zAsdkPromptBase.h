

#pragma once

#include <string.h>
#include "zdbjig.h"
#include "zadscodes.h"

#define IDR_ASDKPROMPTBASE	700

BOOL zcedSetIUnknownForCurrentCommand (const LPUNKNOWN) ;

struct PROMPT_MAP_ENTRY {
	LPCWSTR m_szDesc ;
	DISPID m_dispId ;
	int m_promptType ;
	int m_cronly ;
	int m_nInitget ;
	UINT m_nKeywords ;
	UINT m_nDefaultValue ;
	UINT m_nPrompt ;
	bool m_bJigThisProperty ;
	bool m_bGotThisProperty ;
	VARTYPE m_paramType ;
	VARIANT m_vValue ;
} ;

template <typename T, const GUID *TCLSIDWrapper>
class ATL_NO_VTABLE ZsdkPromptBase :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<ZsdkPromptBase<T,TCLSIDWrapper>, NULL>,
	public IPropertyNotifySink,
	public ZcEdJig
{

protected:
	CComPtr<T> m_pWrapperObject ;
	CLSID m_CLSID_ObjectWrapper ;
	ZcDbObject *m_pDbrObject ;
	DWORD m_dConnectionID ;
	CComQIPtr<IZcadBaseObject2> m_pBaseObj ;
	CComPtr<IConnectionPoint> m_pConPt ;
	ZcDbDatabase *m_pDb ;
	ZcApDocument *m_pDoc ;

	ZcGePoint3d m_cursor3dPos, m_pos3d ;
	ZcGePoint2d m_cursorPos, m_pos ;
	double m_cursorDist, m_dist ;
	double m_cursorAngle, m_angle ;
	TCHAR *m_szCursorString, *m_szString ;

	ZcEdJig::CursorType m_jigCursorType ;
	ZcEdJig::UserInputControls m_jigUserInputControls ;

	volatile LONG m_cRef ;

protected:
	ZsdkPromptBase () : ZcEdJig (),
		m_cursor3dPos(), m_pos3d(), m_cursorPos(), m_pos(),
		m_cursorDist(0), m_dist(0), m_cursorAngle(0), m_angle(0),
		m_szCursorString(NULL), m_szString(NULL)
	{
		m_CLSID_ObjectWrapper =*TCLSIDWrapper ;
	}

	virtual ~ZsdkPromptBase () {}

	DECLARE_REGISTRY_RESOURCEID(IDR_ASDKPROMPTBASE)
	DECLARE_PROTECT_FINAL_CONSTRUCT()

	BEGIN_COM_MAP(ZsdkPromptBase)
		COM_INTERFACE_ENTRY(IPropertyNotifySink)
	END_COM_MAP()

	HRESULT FinalConstruct () { return (S_OK) ; }
	void FinalRelease () {}
	virtual HINSTANCE GetResourceInstance () =0 ;
	void SetDocument (ZcApDocument *pDoc) { m_pDoc =pDoc ; }
	int GetPromptMapSize () {
		PROMPT_MAP_ENTRY *pPromptMap =GetPromptMap () ;
		int i =0 ;
		while ( pPromptMap [i].m_szDesc )
			i++ ;
		return (i) ;
	}
	virtual PROMPT_MAP_ENTRY *GetPromptMap () =0 ;
	virtual VARTYPE propertyTypeCallback (int index, VARTYPE varType) { return (varType) ; }
	virtual void setProperty (int index, VARIANT &var, long val) {
		if ( V_VT(&var) == VT_I4 )
			V_I4(&var) =val ;
		else if ( V_VT(&var) == VT_I2 )
			V_I2(&var) =static_cast<short>(val) ;
	}
	virtual void setProperty (int index, VARIANT &var, short val) {
		if ( V_VT(&var) == VT_I4 )
			V_I4(&var) =static_cast<long>(val) ;
		else if ( V_VT(&var) == VT_I2 )
			V_I2(&var) =val ;
	}
	virtual void setProperty (int index, VARIANT &var, double val) {
		if ( V_VT(&var) == VT_R8 )
			V_R8(&var) =val ;
		else if ( V_VT(&var) == VT_R4 )
			V_R4(&var) =static_cast<float>(val) ;
	}
	virtual void setProperty (int index, VARIANT &var, float val) {
		if ( V_VT(&var) == VT_R8 )
			V_R8(&var) =static_cast<double>(val) ;
		else if ( V_VT(&var) == VT_R4 )
			V_R4(&var) =val ;
	}
	virtual void setProperty (int index, VARIANT &var, TCHAR *val) {
		V_BSTR(&var) =_bstr_t (val).copy () ;
	}
	virtual void setProperty (int index, VARIANT &var, ZcGePoint3d &val) {
		ZcAxPoint3d pt (val) ;
		pt.setVariant (var) ;
	}
	virtual void setProperty (int index, VARIANT &var, ZcGePoint2d &val) {
		ZcAxPoint2d pt (val) ;
		pt.setVariant (var) ;
	}
	HRESULT GetPropertyTypeInfo () {
		PROMPT_MAP_ENTRY *pPromptMap =GetPromptMap () ;

		unsigned int count =0 ;
		if ( !SUCCEEDED(m_pWrapperObject->GetTypeInfoCount (&count)) )
			return (E_FAIL) ;

		if ( !count )
			return (E_FAIL) ;

		CComPtr<ITypeInfo> pTypeInfo ;
		if ( !SUCCEEDED (m_pWrapperObject->GetTypeInfo (0, NULL, &pTypeInfo)) )
			return (E_FAIL) ;

		TYPEATTR *pTypeAttr ;
		if ( !SUCCEEDED (pTypeInfo->GetTypeAttr (&pTypeAttr)) )
			return (E_FAIL) ;
		int numFuncs =pTypeAttr->cFuncs ;
		pTypeInfo->ReleaseTypeAttr (pTypeAttr) ;

		for ( int i =0 ; i < numFuncs ; i++ ) {

			FUNCDESC *pFuncDesc ;
			if ( !SUCCEEDED (pTypeInfo->GetFuncDesc (i, &pFuncDesc)) )
				return (E_FAIL) ;

			MEMBERID memberID ;
			memberID =pFuncDesc->memid ;
			int ii =0 ;
			for ( int ii =0 ; ii < GetPromptMapSize () ; ii++ ) {
				if ( memberID == pPromptMap [ii].m_dispId ) {
					UINT nNamesArraySize =pFuncDesc->cParams + 1, nReturnedNames ;
					BSTR *pBstrNames =new BSTR [nNamesArraySize] ;
					if ( !SUCCEEDED (pTypeInfo->GetNames (memberID, pBstrNames, nNamesArraySize, &nReturnedNames)) )
						return (E_FAIL) ;
					delete [] pBstrNames ;
					if ( nReturnedNames < 1 )
						continue ;
					if ( pFuncDesc->invkind == INVOKE_PROPERTYGET )
						continue ;
					pPromptMap [ii].m_paramType =propertyTypeCallback (ii, pFuncDesc->lprgelemdescParam [nReturnedNames - 1].tdesc.vt) ;
				}
			}
		}
		return (S_OK) ;
	}

	HRESULT PutProperty (int index) {
		static bool bDontLoop =false ;
		WORD wflags =DISPATCH_PROPERTYPUT ;
		DISPID putid =DISPID_PROPERTYPUT ;

		CComPtr<IDispatch> pDisp ;
		m_pWrapperObject.QueryInterface (&pDisp) ;
		PROMPT_MAP_ENTRY *pPromptMap =GetPromptMap () ;
		DISPPARAMS dispparams ;
		dispparams.rgvarg =&pPromptMap [index].m_vValue ;
		dispparams.rgdispidNamedArgs =&putid ;
		dispparams.cArgs =1 ;
		dispparams.cNamedArgs =1 ;
		HRESULT hr=pDisp->Invoke (
			pPromptMap [index].m_dispId, IID_NULL, LOCALE_USER_DEFAULT,
			wflags, &dispparams, NULL, NULL, NULL
		) ;
		if ( hr != S_OK && !bDontLoop ) {
			bDontLoop =true ;
			setPropertyDefault (index) ;
			bDontLoop =false ;
		}
		return (hr) ;
	}
	STDMETHODIMP OnChanged (DISPID dispId) {
		PROMPT_MAP_ENTRY *pPromptMap=GetPromptMap () ;
		int i =0 ;
		while ( pPromptMap [i].m_szDesc ) {
			if ( dispId == pPromptMap [i].m_dispId ) {
				pPromptMap [i].m_bGotThisProperty =true ;
				break ;
			}
			i++ ;
		}
		if ( m_pDoc != NULL )
			zcDocManager->sendModelessInterrupt (m_pDoc) ;
		return (S_OK) ;
	}

	STDMETHODIMP OnRequestEdit (DISPID dispID) { return (S_OK) ; }
	virtual void setPropertyDefaults (int index =-1) {
		PROMPT_MAP_ENTRY *pPromptMap =GetPromptMap () ;
		if ( index == -1) {
			for ( int i =0 ; pPromptMap [i].m_szDesc ; i++ )
				setPropertyDefault (i) ;
		} else {
			setPropertyDefault (index) ;
		}
	}
	void setPropertyDefault (int i) {
		PROMPT_MAP_ENTRY *pPromptMap =GetPromptMap () ;
		pPromptMap [i].m_vValue.vt =pPromptMap [i].m_paramType ;
		TCHAR szDefaultValue [256] ;
		if ( defaultValueCallback (i, szDefaultValue) == false )
			LoadString (pPromptMap [i].m_nDefaultValue, szDefaultValue) ;
		switch ( pPromptMap [i].m_paramType ) {
			case VT_I4:

				setProperty (i, pPromptMap [i].m_vValue, _ttol (szDefaultValue)) ;
				break;
			case VT_I2:

				setProperty (i, pPromptMap [i].m_vValue, static_cast<short>(_ttoi (szDefaultValue))) ;
				break;
			case VT_ARRAY | VT_R8: {
				TCHAR seps [] =L" ," ;
				TCHAR szDefault [MAX_PATH] ;
				wcscpy (szDefault, szDefaultValue) ;
				ZcGePoint3d defPt ;
				TCHAR *token =wcstok (szDefault, seps) ;
				for ( long index =0 ; token ; index++ ) {
					if ( index < 3 )
						defPt [index] =_tstof (token) ;
					token =wcstok (NULL, seps) ;
				}
				setProperty (i, pPromptMap [i].m_vValue, defPt) ;
				break ;
			}
			case VT_BSTR:

				setProperty (i, pPromptMap [i].m_vValue, szDefaultValue) ;
				break ;
			case VT_R8:

				setProperty (i, pPromptMap [i].m_vValue, _tstof (szDefaultValue)) ;
				break ;
			case VT_R4:

				setProperty (i, pPromptMap [i].m_vValue, static_cast<float>(_tstof (szDefaultValue))) ;
				break ;
		}
		if ( pPromptMap [i].m_dispId )
			PutProperty (i) ;
		pPromptMap [i].m_bGotThisProperty =false ;
	}
	virtual void initSampler () =0 ;

	virtual ZcEdJig::DragStatus sampler () {
		setSpecialCursorType (m_jigCursorType) ;
		setUserInputControls (m_jigUserInputControls) ;
		ZcEdJig::DragStatus stat =ZcEdJig::kCancel ;
		PROMPT_MAP_ENTRY *pPromptMap =GetPromptMap () ;
		int i =0 ;
		while ( pPromptMap [i].m_szDesc ) {
			if ( pPromptMap [i].m_bJigThisProperty && !pPromptMap [i].m_bGotThisProperty ) {
				bool compareChange =false ;
				if ( pPromptMap [i].m_nKeywords != 0 ) {
					TCHAR szKeywords [256] ;
					LoadString (pPromptMap [i].m_nKeywords, szKeywords) ;
					setKeywordList (szKeywords) ;
				}
				stat =samplerCallback (i, compareChange) ;
				if ( stat >= ZcEdJig::kKW1 )
					keywordCallback (i, (TCHAR *)&stat, NULL) ;
				if ( stat == ZcEdJig::kOther ) {
					switch ( pPromptMap [i].m_promptType ) {
						case RTPOINT: {
							ZcGePoint3d pos ;
							stat =acquirePoint (pos) ;
							m_cursorPos.x =pos.x ;
							m_cursorPos.y =pos.y ;
							if ( stat >= ZcEdJig::kKW1 )
								keywordCallback (i, (TCHAR *)&stat, &m_pos) ;
							compareChange =(m_cursorPos.isEqualTo (m_pos) ? true : false) ;
							break ;
						}
						case RT3DPOINT:
							stat =acquirePoint (m_cursor3dPos) ;
							if ( stat >= ZcEdJig::kKW1 )
								keywordCallback (i, (TCHAR *)&stat, &m_cursor3dPos) ;
							compareChange =(m_cursor3dPos.isEqualTo (m_pos3d) ? true : false) ;
							break ;
						case RTREAL:
							stat =acquireDist (m_cursorDist) ;
							if ( stat >= ZcEdJig::kKW1 )
								keywordCallback (i, (TCHAR *)&stat, &m_cursorDist) ;
							compareChange =(m_cursorDist != m_dist) ;
							break ;
						case RTANG:
							stat =acquireAngle (m_cursorAngle) ;
							if ( stat >= ZcEdJig::kKW1 )
								keywordCallback (i, (TCHAR *)&stat, &m_cursorAngle) ;
							compareChange =(m_cursorAngle != m_angle) ;
							break ;
						case RTSTR:
							stat =acquireString (m_szCursorString) ;
							if ( stat >= ZcEdJig::kKW1 )
								keywordCallback (i, (TCHAR *)&stat, &m_szCursorString) ;
							compareChange =(m_szCursorString != m_szString) ;
							break ;
					}
					if ( stat == ZcEdJig::kNull )
						pPromptMap [i].m_bGotThisProperty =true ;
				}
				if ( stat == ZcEdJig::kCancel )
					return (stat) ;
				if ( !compareChange ) {

					return (stat == ZcEdJig::kNull ? stat : ZcEdJig::kNoChange) ;
				} else {
					m_pos =m_cursorPos ;
					m_pos3d =m_cursor3dPos ;
					m_dist =m_cursorDist ;
					m_angle =m_cursorAngle ;
					m_szString =m_szCursorString ;

					return (stat) ;
				}
			}
			i++ ;
		}
		return (stat) ;
	}

	virtual ZcDbEntity *entity () const {
		if ( m_pDbrObject == NULL )
			m_pBaseObj->GetObject ((ZcDbObject *&)m_pDbrObject) ;
		return ((ZcDbEntity *)m_pDbrObject) ;
	}

	virtual ZSoft::Boolean update () {
		PROMPT_MAP_ENTRY *pPromptMap =GetPromptMap () ;
		for ( int i =0 ; pPromptMap [i].m_szDesc ; i++ ) {
			if ( pPromptMap [i].m_bJigThisProperty && !pPromptMap [i].m_bGotThisProperty ) {
				if ( updateCallback (i) == false ) {
					switch ( pPromptMap [i].m_promptType ) {
						case RTPOINT: {
							setProperty (i, pPromptMap [i].m_vValue, m_cursorPos) ;
							break ;
						}
						case RT3DPOINT: {
							setProperty (i, pPromptMap [i].m_vValue, m_cursor3dPos) ;
							break ;
						}
						case RTREAL:

							setProperty (i, pPromptMap [i].m_vValue, m_cursorDist) ;
							break ;
						case RTANG:

							setProperty (i, pPromptMap [i].m_vValue, m_cursorAngle) ;
							break ;
						case RTSTR:

							setProperty (i, pPromptMap [i].m_vValue, m_szCursorString) ;
							break ;
						default:
							zcutPrintf (L"Type %s not handled by Jig mechanism!\n", pPromptMap [i].m_szDesc) ;
							break ;
					}
					PutProperty (i) ;
					pPromptMap [i].m_bGotThisProperty =false ;
					break ;
				}
			}
		}
		return (ZSoft::kTrue) ;
	}
	virtual void constructorCallback () {}
	virtual int promptCallback (int index) { return (RTINPUTTRUNCATED) ; }
	virtual ZcEdJig::DragStatus samplerCallback (int index, bool &compareChange) { return (kOther) ; }
	virtual bool updateCallback (int index) { return (false) ; }
	virtual bool keywordCallback (int index, TCHAR *kword, void *value) { return (false) ; }
	virtual bool defaultValueCallback (int index, LPWSTR szDefaultVal) { return (false) ; }
	int LoadString (UINT uID, LPWSTR szString, int nBufferMax =255) {
		int ret =0 ;
		*szString =L'\0' ;
		if ( uID != 0 && uID != (UINT)-1 )
			ret =::LoadString (GetResourceInstance (), uID, szString, nBufferMax) ;
		return (ret) ;
	}

	LPCWSTR BuildPromptString (int index) {
		PROMPT_MAP_ENTRY *pPromptMap =GetPromptMap () ;

		static TCHAR szPrompt [256] ;
		LoadString (pPromptMap [index].m_nPrompt, szPrompt) ;

		TCHAR szDefaultVal [256] ;
		*szDefaultVal =L'\0' ;
		if ( defaultValueCallback (index, szDefaultVal) == false )
			LoadString (pPromptMap [index].m_nDefaultValue, szDefaultVal) ;
		if ( *szDefaultVal != L'\0' ) {
			wcscat (szPrompt, L" <") ;
			wcscat (szPrompt, szDefaultVal) ;
			wcscat (szPrompt, L">") ;
		}
		wcscat (szPrompt, L": ") ;
		return (szPrompt) ;
	}

public:
	virtual ZcDbObjectId promptLoop () {
		setPropertyDefaults (-1) ;
		DragStatus stat =kNormal ;
		int retval =RTNORM ;
		PROMPT_MAP_ENTRY *pPromptMap =GetPromptMap () ;
		int i =0 ;
		while ( true ) {
			bool done =true ;
			while ( pPromptMap [i].m_szDesc ) {
				if ( !pPromptMap [i].m_bJigThisProperty && !pPromptMap [i].m_bGotThisProperty ) {
					done =false ;
					retval =promptCallback (i) ;
					if ( retval == RTCAN )
						break ;
					if ( retval == RTINPUTTRUNCATED ) {
						TCHAR szKeyword [133] ;
						if ( pPromptMap [i].m_nKeywords != 0 ) {
							LoadString (pPromptMap [i].m_nKeywords, szKeyword, 132) ;
							zcedInitGet (pPromptMap [i].m_nInitget, szKeyword) ;
						}
						LPCWSTR szPrompt =BuildPromptString (i) ;
						switch ( pPromptMap [i].m_promptType ) {
							case RTPOINT: {
								zds_point point ;
								retval =zcedGetPoint (NULL, szPrompt, point) ;
								if ( retval == RTKWORD ) {
									zcedGetInput (szKeyword) ;
									if ( keywordCallback (i, szKeyword, point) == true )
										retval =RTNORM ;
								}
								if ( retval == RTNORM ) {
									ZcGePoint2d pt2d (point [X], point [Y]) ;
									setProperty (i, pPromptMap [i].m_vValue, pt2d) ;
									PutProperty (i) ;
								}
								break ;
							}
							case RT3DPOINT: {
								zds_point point ;
								retval =zcedGetPoint (NULL, szPrompt, point) ;
								if ( retval == RTKWORD ) {
									zcedGetInput (szKeyword) ;
									if ( keywordCallback (i, szKeyword, point) == true )
										retval =RTNORM ;
								}
								if ( retval == RTNORM ) {
									ZcGePoint3d pt3d (point [0], point [1], point [2]) ;
									setProperty (i, pPromptMap [i].m_vValue, pt3d) ;
									PutProperty (i) ;
								}
								break ;
							}
							case RTREAL: {
								double dist =0 ;
								retval =zcedGetReal (szPrompt, &dist) ;
								if ( retval == RTKWORD ) {
									zcedGetInput (szKeyword) ;
									if ( keywordCallback (i, szKeyword, &dist) == true )
										retval =RTNORM ;
								}
								if ( retval == RTNORM ) {

									setProperty (i, pPromptMap [i].m_vValue, dist) ;
									PutProperty (i) ;
								}
								break ;
							}
							case RTANG: {
								double angle =0 ;
								retval =zcedGetAngle (NULL, szPrompt, &angle) ;
								if ( retval == RTKWORD ) {
									zcedGetInput (szKeyword) ;
									if ( keywordCallback (i, szKeyword, &angle) == true )
										retval =RTNORM ;
								}
								if ( retval == RTNORM ) {

									setProperty (i, pPromptMap [i].m_vValue, angle) ;
									PutProperty (i) ;
								}
								break ;
							}
							case RTSTR: {
								TCHAR szBuffer [132] ;
								*szBuffer =L'\0' ;
								retval =zcedGetString (pPromptMap [i].m_cronly, szPrompt, szBuffer) ;
								if ( retval == RTKWORD ) {
									zcedGetInput (szKeyword) ;
									if ( keywordCallback (i, szKeyword, szBuffer) == true )
										retval =RTNORM ;
								}
								if ( retval == RTNORM ) {
									if ( wcslen (szBuffer) )

										setProperty (i, pPromptMap [i].m_vValue, szBuffer) ;
									PutProperty (i) ;
								}
								break ;
							}
							case RTLONG: {
								int _int =0 ;
								retval =zcedGetInt (szPrompt, &_int) ;
								if ( retval == RTKWORD ) {
									zcedGetInput (szKeyword) ;
									if ( keywordCallback (i, szKeyword, &_int) == true )
										retval =RTNORM ;
								}
								if ( retval == RTNORM ) {

									setProperty (i, pPromptMap [i].m_vValue, static_cast<long>(_int)) ;
									PutProperty (i) ;
								}
								break ;
							}
							case RTSHORT: {
								int _int =0 ;
								retval =zcedGetInt (szPrompt, &_int) ;
								if ( retval == RTKWORD ) {
									zcedGetInput (szKeyword) ;
									if ( keywordCallback (i, szKeyword, &_int) == true )
										retval =RTNORM ;
								}
								if ( retval == RTNORM ) {

									setProperty (i, pPromptMap [i].m_vValue, static_cast<short>(_int)) ;
									PutProperty (i) ;
								}
								break ;
							}
							case RTENAME: {
								zds_name ename ;
								zds_point pt ;
								retval =zcedEntSel (szPrompt, ename, pt) ;
								if ( retval == RTKWORD ) {
									zcedGetInput (szKeyword) ;
									if ( keywordCallback (i, szKeyword, ename) == true )
										retval =RTNORM ;
								}
								if ( retval == RTNORM ) {

									setProperty (i, pPromptMap [i].m_vValue, static_cast<long>(ename [0])) ;
									PutProperty (i) ;
								}
								break ;
							}
						}
					}
					if ( retval == RTNONE )
						pPromptMap [i].m_bGotThisProperty =true ;
					if ( retval == RTCAN ) {
						done =true ;
						break ;
					}
					if ( pPromptMap [i].m_bGotThisProperty == true )
						i++ ;
				} else {
					i++ ;
				}
			}
			if ( done )
				break ;
			else
				i =0 ;
		}
		if ( retval == RTCAN )
			return (ZcDbObjectId::kNull) ;
		i =0 ;
		while ( true ) {
			bool done =true ;
			while( pPromptMap [i].m_szDesc ) {
				if ( pPromptMap [i].m_bJigThisProperty && !pPromptMap [i].m_bGotThisProperty ) {
					done =false ;
					retval =promptCallback (i) ;
					if ( retval == RTINPUTTRUNCATED ) {
						setDispPrompt (BuildPromptString (i)) ;
						stat =drag () ;
						if ( stat == ZcEdJig::kNormal ) {
							switch ( pPromptMap [i].m_promptType ) {
								case RTPOINT: {
									setProperty (i, pPromptMap [i].m_vValue, m_cursorPos) ;
									PutProperty (i) ;
									break ;
								}
								case RT3DPOINT: {
									setProperty (i, pPromptMap [i].m_vValue, m_cursor3dPos) ;
									PutProperty (i) ;
									break ;
								}
								case RTREAL:

									setProperty (i, pPromptMap [i].m_vValue, m_cursorDist) ;
									PutProperty (i) ;
									break ;
								case RTANG:

									setProperty (i, pPromptMap [i].m_vValue, m_cursorAngle) ;
									PutProperty (i) ;
									break ;
								case RTSTR:

									setProperty (i, pPromptMap [i].m_vValue, m_szCursorString) ;
									PutProperty (i) ;
									break ;
							}
						}
						if ( stat == ZcEdJig::kCancel ) {
							done =true ;
							break ;
						}
					}
					if ( retval == RTCAN || retval == ZcEdJig::kCancel ) {
						stat =ZcEdJig::kCancel ;
						done =true ;
						break ;
					}
					if ( pPromptMap [i].m_bGotThisProperty == true )
						i++ ;
				} else {
					i++ ;
				}
			}
			if ( done )
				break ;
			else
				i =0 ;
		}
		if ( stat != ZcEdJig::kCancel ) {
			if ( m_pBaseObj )
				m_pBaseObj->GetObject (m_pDbrObject) ;
			return (append ()) ;
		}
		return (ZcDbObjectId::kNull) ;
	}
} ;

#define BEGIN_PROMPT_MAP(CLASSNAME) \
	public: \
	CLASSNAME () { \
		HRESULT hr =S_OK ; \
		if ( FAILED(hr =m_pWrapperObject.CoCreateInstance (m_CLSID_ObjectWrapper)) ) { \
			zcutPrintf (L"Unable to Create Wrapper Class\n") ; \
			throw hr ; \
		} \
		m_pBaseObj =m_pWrapperObject ; \
		if ( FAILED (hr =m_pBaseObj->CreateObject ()) ) \
			throw hr ; \
		SetDocument (curDoc ()) ; \
		CComPtr<IUnknown> pUnkCmd ; \
		hr =QueryInterface (IID_IUnknown, (void **)&pUnkCmd) ; \
		if ( FAILED(hr) ) \
			throw hr ; \
		CComQIPtr<IConnectionPointContainer> pPtContainer ; \
		pPtContainer =m_pWrapperObject ; \
		hr =pPtContainer->FindConnectionPoint (IID_IPropertyNotifySink, &m_pConPt) ; \
		if ( FAILED(hr) ) \
			throw hr ; \
		\
		if ( FAILED(hr =GetPropertyTypeInfo ()) ) { \
			zcutPrintf (L"Unable to Obtain Correct Type Information from the Wrapper Class\n") ; \
			throw hr ; \
		} \
		if ( FAILED(hr =m_pConPt->Advise (pUnkCmd, &m_dConnectionID)) ) \
			throw hr ; \
		\
		BOOL bRet =zcedSetIUnknownForCurrentCommand (m_pWrapperObject) ; \
		m_pDb =zcdbHostApplicationServices ()->workingDatabase () ; \
		\
		ZcDbObject *pObj =NULL ; \
		m_pBaseObj->GetObject (pObj) ; \
		m_pDbrObject =pObj ; \
		ZcDbEntity *pEnt=(ZcDbEntity *)ZcDbEntity::cast (pObj) ; \
		if ( pEnt ) \
			pEnt->setDatabaseDefaults () ; \
		m_pBaseObj->SetObject (pObj) ; \
		constructorCallback () ; \
		initSampler () ; \
	} \
	~CLASSNAME () { \
		m_pConPt->Unadvise (m_dConnectionID) ; \
		if ( m_pBaseObj ) \
			m_pBaseObj->GetObject (m_pDbrObject) ; \
	} \
	HRESULT STDMETHODCALLTYPE QueryInterface (REFIID refiid, void **ppv) { \
		if ( refiid == IID_IUnknown || refiid == IID_IPropertyNotifySink ) \
			*ppv =this ; \
		else \
			return (E_NOINTERFACE) ; \
		static_cast<IUnknown *>(this)->AddRef () ; \
		return (S_OK) ; \
	} \
	ULONG STDMETHODCALLTYPE AddRef () { \
		return (InterlockedIncrement (&m_cRef)) ; \
	} \
	ULONG STDMETHODCALLTYPE Release () { \
		ULONG ul =InterlockedDecrement (&m_cRef) ; \
		return (ul) ; \
	} \
	virtual PROMPT_MAP_ENTRY* GetPromptMap () { \
		static PROMPT_MAP_ENTRY pPromptMap [] = {

#define PROMPT_ENTRY(szDesc,dispId,promptType,defaultValueId,promptId,bJigThisProperty) \
	{ szDesc, dispId, promptType, 1, 0, 0, defaultValueId, promptId, bJigThisProperty },

#define PROMPT_ENTRY_INITGET(szDesc,dispId,promptType,initget,keywordsId,defaultValueId,promptId,bJigThisProperty) \
	{ szDesc, dispId, promptType, 1, initget, keywordsId, defaultValueId, promptId, bJigThisProperty },

#define PROMPT_ENTRY_SYMBOL(szDesc,dispId,defaultValueId,promptId,bJigThisProperty) \
	{ szDesc, dispId, RTSTR, 0, 0, 0, defaultValueId, promptId, bJigThisProperty },

#define END_PROMPT_MAP \
			{ NULL, 0, 0, 0, 0, 0, 0, false, false, VT_EMPTY } \
		} ; \
		return (pPromptMap) ; \
	}

#define DEFINE_SAMPLER(CURSORTYPE,USERINPUTCONTROLS) \
	virtual void initSampler () { \
		m_jigCursorType =CURSORTYPE ; \
		m_jigUserInputControls =USERINPUTCONTROLS ; \
	}
	
