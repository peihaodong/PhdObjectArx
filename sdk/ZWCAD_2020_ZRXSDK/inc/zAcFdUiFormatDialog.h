
#pragma once

#include "zadui.h"
#include "zAcFdUi.h"

class ZcTcUiSystemInternals;
class CZcFdUiFormatList;
#define ZCFDUI_UM_FORMAT_CHANGED        (WM_APP + 100)
#define ZCFDUI_UM_BEGIN_FORMATEX_DIALOG (WM_APP + 101)
#define ZCFDUI_UM_END_FORMATEX_DIALOG   (WM_APP + 102)
#define ZCFDUI_FDSTYLE_SIMPLE       (0x1 << 1)
#define ZCFDUI_FDSTYLE_FILENAME     (0x1 << 2)
#define ZCFDUI_FDSTYLE_DOUBLE       (0x1 << 3)
#define ZCFDUI_FDSTYLE_DOUBLE_POINT (0x1 << 4)
#define ZCFDUI_FDSTYLE_ALL          (0x1 << 5)

class ZCFDUI_PORT CZcFdUiFormatDialog : public CZdUiDialog
{
	DECLARE_DYNAMIC(CZcFdUiFormatDialog)

public:
	CZcFdUiFormatDialog(CWnd* pParent, BOOL bNew);
	virtual ~CZcFdUiFormatDialog();

    virtual BOOL 	Create					(CWnd* pParent);

    CZcFdUiFormatList* GetFormatList	(void);
    CString			GetFormatType			(void) const;
    BOOL			SetFormatType			(LPCTSTR pszFormatType);
    int				GetCurrentFormat		(CString& sDisplayName,
											 CString& sFormatString,
                                             CString& sVersion) const;
    BOOL			SetCurrentFormat		(LPCTSTR pszDisplayName,
											 LPCTSTR pszFormatString);
    BOOL			SetFormatPreviewReadOnly(BOOL bReadOnly = TRUE);
    BOOL			SetFormatPreviewLabel	(LPCTSTR pszText);
    BOOL            SetFormatPreviewText    (LPCTSTR pszPreviewText,
                                             const ZcValue& fieldValue);
    BOOL            SetDialogStyle          (int nStyle);

protected:
	virtual void    DoDataExchange          (CDataExchange* pDX);
    afx_msg void    OnDestroy               (void);
    afx_msg void    OnLbnSelChangeFormatList(void);
    afx_msg void 	OnEnChangePreview		(void);
    afx_msg void    OnBnClickedFilenameOnly (void);
    afx_msg void    OnBnClickedPathOnly     (void);
    afx_msg void    OnBnClickedPathAndFilename(void);
    afx_msg void    OnBnClickedIncludeExtension(void);
    afx_msg void    OnBnClickedFormatEx     (void);
    afx_msg void    OnCbnSelChangePrecision (void);
    afx_msg void    OnCbnSelChangeDecimalSeparator(void);
    afx_msg void    OnCbnSelChangeListSeparator(void);
    afx_msg void    OnCbnEditChangeListSeparator(void);
    afx_msg void    OnBnClickedPointX       (void);
    afx_msg void    OnBnClickedPointY       (void);
    afx_msg void    OnBnClickedPointZ       (void);
	afx_msg void	OnBnClickedAdditionalFormat(void);
    afx_msg void    OnBnClickedAppendSymbol (void);
    afx_msg void    OnCbnSelChangeCurrencySymbol(void);
    afx_msg void    OnLbnSelChangeNegativeNumberList(void);

	DECLARE_MESSAGE_MAP()

protected:
    void            *   mpImpObj;

private:
    friend class ZcFdUiSystemInternals;
};
