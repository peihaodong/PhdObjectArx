

#ifndef __ZACTCUISCHEME_H__
#define __ZACTCUISCHEME_H__

#if _MSC_VER > 1000
#pragma once
#endif

#include "zAcTcUiToolPaletteSet.h"
#include "zAcTcUi.h"

class ZcTcUiSystemInternals;

class ZCTCUI_PORT CZcTcUiScheme : public CObject
{
public:
    enum RefreshScope {
        kAllPalettes                    = (0x1 << 0),
        kRefreshEnabledPalettes         = (0x1 << 1),
        kAutoRefreshEnabledPalettes     = (0x1 << 2),
    };

    enum ShowOption {
        kShow                           = (0x1 << 0),
        kHide                           = (0x1 << 1),
		kSaveState						= (0x1 << 2),
        kRestoreState                   = (0x1 << 3),
    };

    CZcTcUiScheme(ZcTcScheme* pScheme);
	virtual ~CZcTcUiScheme();

    BOOL                Load                (IUnknown* pUnknown);
    BOOL                Save                (IUnknown* pUnknown);
    BOOL                Unload              (void);
    CZcTcUiToolPaletteSet* CreatePaletteSet (LPCTSTR pszPalSetName);
    CZcTcUiToolPaletteSet* GetPaletteSet    (void);
    BOOL                FindPalette         (const ZcTcCatalogItem* pItem,
                                             CZcTcUiToolPalette** ppToolPalette) const;
    BOOL                FindPalette         (const ZcTcCatalogItem* pItem,
                                             CZcTcUiToolPalette** ppToolPalette,
                                             CZcTcUiToolPaletteSet** ppToolPaletteSet) const;
    BOOL                FindPalette         (const GUID& itemId,
                                             CZcTcUiToolPalette** ppToolPalette) const;
    BOOL                FindPalette         (const GUID& itemId,
                                             CZcTcUiToolPalette** ppToolPalette,
                                             CZcTcUiToolPaletteSet** ppToolPaletteSet) const;
    BOOL                Export              (LPCTSTR pszFile);
    BOOL                Export              (LPCTSTR pszFile,
                                             const ZcTcUiToolPaletteArray* palettes);
    BOOL                Import              (LPCTSTR pszFile);
    BOOL                Refresh             (RefreshScope nScope);
    BOOL                Refresh             (RefreshScope nScope,
                                             DWORD dwRefreshFlag);
    BOOL                Show                (ShowOption nOption,
											 LONG_PTR lKey);

protected:
    void            *   mpImpObj;

private:
    friend class ZcTcUiSystemInternals;
};
#endif 
