

#pragma once

#include "zAcTcUiToolPalette.h"

class CZcTcUiImpToolPaletteGroup;
class CZcTcUiImpToolPaletteSet;

class ZCTCUI_PORT CZcTcUiToolPaletteGroup : public CObject
{
    DECLARE_DYNAMIC(CZcTcUiToolPaletteGroup);

public:
    CZcTcUiToolPaletteGroup();
    virtual ~CZcTcUiToolPaletteGroup();

    BOOL			Reset					(void);
    CString         GetName                 (void) const;
    BOOL			SetName					(LPCTSTR pszName);
    CString			GetDescription			(void) const;
    BOOL			SetDescription			(LPCTSTR pszDesc);
    BOOL			IsItemPalette			(int iIndex) const;
    int				AddItem					(CZcTcUiToolPalette* pPalette);
    int				AddItem					(CZcTcUiToolPaletteGroup* pGroup);
    int				InsertItem				(int iIndex, 
											 CZcTcUiToolPalette* pPalette);
    int				InsertItem				(int iIndex, 
											 CZcTcUiToolPaletteGroup* pGroup);
    int				GetItemCount			(void) const;
    BOOL			GetItem					(int iIndex, 
											 CZcTcUiToolPalette*& pPalette) const;
    BOOL			GetItem					(int iIndex, 
											 CZcTcUiToolPaletteGroup*& pGroup) const;
    BOOL			DeleteItem				(CZcTcUiToolPalette* pPalette, 
											 BOOL bRecursive = FALSE);
    BOOL			DeleteItem				(CZcTcUiToolPaletteGroup* pGroup);
    BOOL			RemoveItem				(CZcTcUiToolPalette* pPalette, 
											 BOOL bRecursive = FALSE);
    BOOL			RemoveItem				(CZcTcUiToolPaletteGroup* pGroup);
    BOOL			DeleteAllPalettes		(void);
    BOOL			DeleteAllItems			(void);
    int				GetActivePalette	    (void) const;
    BOOL			SetActivePalette        (int nIndex);
    BOOL            GetCustomData           (IUnknown** ppUnknown);
    virtual BOOL 	Load					(IUnknown* pUnk);
    virtual BOOL 	Save					(IUnknown* pUnk);
    virtual BOOL 	Clone					(CZcTcUiToolPaletteGroup*& pClone);
    CZcTcUiToolPaletteGroup* FindGroup      (LPCTSTR pszGroup,
                                             BOOL bRecursive = TRUE);
    CZcTcUiToolPalette* FindPalette         (LPCTSTR pszPalName,
                                             CZcTcUiToolPaletteGroup** ppGroup,
                                             BOOL bRecursive = TRUE) const;

protected:
    void            *   mpImpObj;

private:
    friend class ZcTcUiSystemInternals;
};

