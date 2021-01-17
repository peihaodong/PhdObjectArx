
#pragma once

#include "zAcFdUi.h"

class ZcTcUiSystemInternals;
class ZCFDUI_PORT CZcFdUiFormatList : public CZdUiListBox
{
	DECLARE_DYNAMIC(CZcFdUiFormatList)

public:
	CZcFdUiFormatList(void);
	virtual ~CZcFdUiFormatList(void);

    void			SetRootKey              (LPCTSTR pszKey);
    void			SetPersistency			(BOOL bPersist);
    CString			GetFormatType			(void) const;
    BOOL			SetFormatType			(LPCTSTR pszFormatType);
    int				GetCurrentFormat		(CString& sDisplayName,
											 CString& sFormatString) const;
    BOOL			SetCurrentFormat		(LPCTSTR pszDisplayName,
											 LPCTSTR pszFormatString);
    BOOL			Refresh					(void);

protected:
    afx_msg int     OnCreate                (LPCREATESTRUCT lpCreateStruct);
    afx_msg void 	OnDestroy				(void);

	DECLARE_MESSAGE_MAP()

protected:
    void            *   mpImpObj;

private:
    friend class ZcFdUiSystemInternals;
};
