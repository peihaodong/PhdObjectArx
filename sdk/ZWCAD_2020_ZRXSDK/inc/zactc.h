
#include "zAdAChar.h"

#pragma once

#ifdef  _ZCTC_BUILD
#  define   ZCTC_PORT  __declspec(dllexport)
#else
#  define   ZCTC_PORT  
#endif

class ZcTcTool;
class ZcTcStockTool;
class ZcTcCatalog;
class ZcTcCatalogItem;
class ZcTcScheme;
class ZcTcCatalogSet;
class ZcTcSystemInternals;
class ZcTcImpCatalogItem;
class ZcTcCatalogItemReactor;

#define ZCTC_IMAGE_NORMAL                   (0x1 << 0)
#define ZCTC_IMAGE_SELECTED                 (0x1 << 1)
#define ZCTC_IMAGE_HALO                     (0x1 << 2)
#define ZCTC_IMAGE_SHADOW                   (0x1 << 3)

#define ZCTC_MAX_CATALOG_ITEM_NAME          256
#define ZCTC_MAX_CATALOG_ITEM_DESCRIPTION   2048
#define ZCTC_MAX_CATALOG_ITEM_KEYWORDS      1024
#define ZCTC_MAX_CATALOG_ITEM_TOOLTIP_TEXT  1024
#define ZCTC_MAX_CATALOG_ITEM_LINK_NAME     256
#define ZCTC_MAX_SCHEME_NAME                256
#define ZCTC_MAX_TOOL_NAME                  ZCTC_MAX_CATALOG_ITEM_NAME
#define ZCTC_MAX_STOCKTOOL_NAME             ZCTC_MAX_CATALOG_ITEM_NAME
#define ZCTC_MAX_PALETTE_NAME               ZCTC_MAX_CATALOG_ITEM_NAME
#define ZCTC_MAX_PACKAGE_NAME               ZCTC_MAX_CATALOG_ITEM_NAME
#define ZCTC_MAX_CATEGORY_NAME              ZCTC_MAX_CATALOG_ITEM_NAME
#define ZCTC_MAX_CATALOG_NAME               ZCTC_MAX_CATALOG_ITEM_NAME
#define ZCTC_MAX_URL                        1024
#define ZCTC_MAX_PATH                       MAX_PATH
#define ZCTC_MAX_COMMAND_NAME               256
#define ZCTC_MAX_COMMAND_ARGS               1024
#define ZCTC_MAX_HELPINFO_FILE              ZCTC_MAX_URL
#define ZCTC_MAX_HELPINFO_COMMAND           256
#define ZCTC_MAX_HELPINFO_DATA              ZCTC_MAX_URL
#define ZCTC_MAX_PARENT_DOCUMENT_NAME       256
#define ZCTC_MAX_PUBLISHER_NAME             256
#define ZCTC_MAX_PRODUCT_NAME               256
#define ZCTC_MAX_LOCALE                     512
#define ZCTC_POSTDOWNLOADCMD_EXECUTE        ZCRX_T("Execute")

#define ZCTC_DEFAULTDIR_IMAGE               ZCRX_T("Images")
#define ZCTC_DEFAULTFILE_IMAGE              ZCRX_T("Image")

namespace ZcTc
{
    enum AccessRight
    {
        kAccessRead             = (0x1 << 0),
        kAccessReadWrite        = (0x1 << 1),
        kAccessReadOnlyFile     = (0x1 << 2),
        kAccessMultiple         = (0x1 << 3),
		kAccessNewerVersion     = (0x1 << 4),
    };

    enum CatalogItemType
    {
        kItemUnknown            = 0,
        kItemTool               = (0x1 << 0),
        kItemPackage            = (0x1 << 1),
        kItemPalette            = (0x1 << 2),
        kItemCategory           = (0x1 << 3),
        kItemCatalog            = (0x1 << 4),
        kItemStockTool          = (0x1 << 5),
    };

    enum ReferencePath
    {
        kLoadRefPath            = 1,
        kSaveRefPath            = 2,
    };

    enum ImageType
    {
        kImageTypeUninitialized = -1,
        kImageTypeBitmap        = 1,
        kImageTypeMetaFile      = 2,
        kImageTypeIcon          = 3,
        kImageTypeEnhMetaFile   = 4,
        kImageTypeJpeg          = 5,
        kImageTypePng           = 6,
        kImageTypeGif           = 7,
        kImageTypeTif           = 8
    };

    enum ImageOption
    {
        kImageOptionNone                = 0x0,
        kImageOptionRenderBitmapOpaque  = (0x1 << 0),
        kImageOptionUserOverride        = (0x1 << 1),
    };

    enum LoadOption
    {
        kLoadLinks              = (0x1 << 0),
        kLoadImages             = (0x1 << 1),
        kLoadOverlayImages      = (0x1 << 2),
        kDoNotNotifyReactor     = (0x1 << 3),
    };

    enum SaveOption
    {
        kSaveLinksAsLinks       = (0x1 << 0),
        kSaveLinksAsEmbedded    = (0x1 << 1),
        kSaveImages             = (0x1 << 2),
        kSaveAs                 = (0x1 << 3),
        kSaveOverlayImages      = (0x1 << 4),
        kSaveAnsi               = (0x1 << 5),
    };

    enum DownloadOption
    {
        kDownloadItem           = (0x1 << 0),
        kDownloadLinkedItem     = (0x1 << 1),
        kDownloadImage          = (0x1 << 2),
        kDownloadStockTool      = (0x1 << 3),
        kDownloadChildren       = (0x1 << 4),
        kDownloadAll            = kDownloadItem | kDownloadLinkedItem |
                                  kDownloadImage | kDownloadStockTool |
                                  kDownloadChildren,
        kDownloadCleanDownloadDir = (0x1 << 5),
        kDownloadShowProgress   = (0x1 << 6),
        kDownloadUseNewIds      = (0x1 << 7),
        kDownloadNotifyTool     = (0x1 << 12)

    };

    enum RefreshOption
    {
        kRefreshItem            = kDownloadItem,
        kRefreshLinkedItem      = kDownloadLinkedItem,
        kRefreshImage           = kDownloadImage,
        kRefreshStockTool       = kDownloadStockTool,
        kRefreshChildren        = kDownloadChildren,
        kRefreshAll             = kDownloadAll,
        kRefreshShowProgress    = kDownloadShowProgress,
        kRefreshNotifyTool      = (0x1 << 16)

    };

    enum CatalogType
    {
        kCatalog                = (0x1 << 0),
        kStockToolCatalog       = (0x1 << 1),
        kShapeCatalog           = (0x1 << 2)
    };

    enum ToolType
    {
        kToolNormal             = 1,
        kToolFlyout             = 2,
        kToolText               = 3,
        kToolSeparator          = 4,
    };

    enum SortOption
    {
        kSortByName             = (0x1 << 0),
        kSortByStockTool        = (0x1 << 1),
        kSortByCustom           = (0x1 << 2),
        kAscending              = (0x1 << 3),
        kDescending             = (0x1 << 4),
    };

    enum ItemOption
    {
        kItemOptionNone                 = 0x0,
        kItemOptionSupportsAutoImage    = (0x1 << 0),
        kItemOptionSupportsUserImage    = (0x1 << 1),
        kItemOptionMenuUpdateImage      = (0x1 << 2),
        kItemOptionMenuSetImage         = (0x1 << 3),
        kItemOptionMenuRemoveImage      = (0x1 << 4),
    };
};

using namespace ZcTc;

struct ZCTC_IMAGE_INFO
{
    SIZE                mSize;
    ZTCHAR               mszResourceName[MAX_PATH];
    ZTCHAR               mszSourceFile[MAX_PATH];
};
struct ZCTC_TARGET_PRODUCT_INFO
{
    ZTCHAR               mszProductName[ZCTC_MAX_PRODUCT_NAME];
    ZTCHAR               mszLocaleIds[ZCTC_MAX_LOCALE];
    DWORD               mdwMinVersion;
    DWORD               mdwMaxVersion;
};

class ZCTC_PORT ZcTcImage
{
public:
    ZcTcImage();
    ZcTcImage(const ZcTcImage& srcImage);
    virtual ~ZcTcImage();

    ZcTcImage&          operator=           (const ZcTcImage& zcTcImage);
    BOOL                Load                (LPCTSTR pszFile);
    BOOL                Load                (HBITMAP hBitmap);
    BOOL                Load                (IStream* pStream);
    BOOL                Save                (LPCTSTR pszFile);
    BOOL                Save                (LPCTSTR sFileName,
                                             ZcTc::ImageType nSaveAsType);
    BOOL                Save                (IStream* pStream);
    BOOL                Render              (HDC hDC,
                                             int xPos,
                                             int yPos,
                                             int nWidth,
                                             int nHeight,
                                             UINT nStyle = ZCTC_IMAGE_NORMAL,
                                             BOOL bTransparentBitmap = TRUE);
    BOOL                GetSize             (LPSIZE pSize) const;
    ZcTc::ImageType     GetType             (void) const;
    BOOL                IsImageLoaded       (void) const;
    BOOL                GetHICON            (HICON &hIcon);
    BOOL                GetHBITMAP          (COLORREF cBackGroundColor,
                                             HBITMAP& hBitmap);
    ZcTc::ImageType     GetSaveType         (void) const;
    BOOL                SetSaveType         (ZcTc::ImageType nSaveType);
    BOOL                ConvertTo           (ZcTc::ImageType nToImageType,
                                             BOOL bTransparent);

protected:
    void            *   mpImpObj;

private:
    friend class ZcTcSystemInternals;
};

class ZCTC_PORT ZcTcImageList
{
    friend class ZcTcImpCatalogItem;
public:
    virtual ~ZcTcImageList();

    ZcTcImageList&      operator=           (const ZcTcImageList& zcTcImageList);
    INT_PTR             GetImageCount       (void) const;
    BOOL                GetImageInfo        (INT_PTR iIndex,
                                             ZCTC_IMAGE_INFO* pImageInfo,
											 BOOL bUseDarkTheme = FALSE) const;
	BOOL                GetEditImageInfo    (INT_PTR iIndex,
                                             ZCTC_IMAGE_INFO* pImageInfo,
                                             BOOL bUseDarkTheme = FALSE);
    BOOL                SetImageInfo        (INT_PTR iIndex,
                                             const ZCTC_IMAGE_INFO* pImageInfo,
											 BOOL bUseDarkTheme = FALSE);
    ZcTcImage*          GetImage            (INT_PTR iIndex, BOOL bUseDarkTheme = FALSE);
    INT_PTR             SetImage            (INT_PTR iIndex,
                                             const ZcTcImage* pImage, BOOL bUseDarkTheme = FALSE);
    INT_PTR             Add                 (const ZcTcImage* pImage, BOOL bUseDarkTheme = FALSE);
    INT_PTR             Add                 (const ZCTC_IMAGE_INFO* pImageInfo);
    INT_PTR             UpdateImage         (const ZcTcImage* pImage, BOOL bUseDarkTheme = FALSE);
    BOOL                Delete              (INT_PTR iIndex);
    BOOL                DeleteAllImages     (void);
    BOOL                LoadImage           (INT_PTR iIndex, BOOL bUseDarkTheme = FALSE);
    INT_PTR             GetImageIndex       (const SIZE* pSize,
                                             BOOL bExactMatch = FALSE,
											 BOOL bUseDarkTheme = FALSE);
    ZcTc::ImageOption   GetOption           (void) const;
    BOOL                SetOption           (ZcTc::ImageOption nOption);

protected:
    ZcTcImageList(ZcTcCatalogItem* pCatalogItem);
    void            *   mpImpObj;

private:
    friend class ZcTcSystemInternals;

};

class ZCTC_PORT ZcTcManager
{
public:
    ZcTcManager();
    virtual ~ZcTcManager();

    INT_PTR             GetStockToolCatalogCount(void) const;
    ZcTcCatalogItem *   GetStockToolCatalog (int nIndex) const;
    ZcTcStockTool   *   FindStockTool       (const GUID& id) const;

    INT_PTR             GetCatalogCount     (void) const;
    ZcTcCatalogItem *   GetCatalog          (int nIndex) const;
    ZcTcCatalogItem *   FindItem            (const GUID& id) const;

    int                 GetCatalogPath      (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetCatalogPath      (LPCTSTR pszPath);
    int                 GetStockToolCatalogPath(LPTSTR pszString,
                                                int cchSize) const;
    BOOL                SetStockToolCatalogPath(LPCTSTR pszPath);
    int                 GetShapeCatalogFile (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetShapeCatalogFile (LPCTSTR pszFile);
    INT_PTR             AddStockToolCatalog (ZcTcCatalogItem* pCatalogItem);
    INT_PTR             AddCatalog          (ZcTcCatalogItem* pCatalogItem);
    BOOL                LoadCatalogs        (DWORD dwCatalogType= kCatalog | kStockToolCatalog,
                                             DWORD dwLoadOption = kLoadLinks);
    BOOL                UnloadCatalogs      (DWORD dwCatalogType= kCatalog | kStockToolCatalog);
    BOOL                SaveCatalogs        (DWORD dwCatalogType= kCatalog | kStockToolCatalog,
                                             DWORD dwSaveOption = kSaveLinksAsLinks);
    ZcTcCatalogItem*    GetShapeCatalog     (void);
    ZcTcCatalogItem *   GetShapePackage     (LPCTSTR lpszName = NULL) const;
    INT_PTR             InsertStockToolCatalog(INT_PTR nIndex,
                                             ZcTcCatalogItem* pCatalog);
    ZcTcCatalogItem*    RemoveStockToolCatalog(int nIndex);

    INT_PTR             GetSchemeCount      (void) const;
    ZcTcScheme      *   GetScheme           (int nIndex) const;
    ZcTcScheme      *   GetScheme           (LPCTSTR pszSchemeName) const;
    INT_PTR             AddScheme           (ZcTcScheme* pScheme);
    BOOL                RemoveScheme        (ZcTcScheme* pScheme);

protected:
    void            *   mpImpObj;

private:
    friend class ZcTcSystemInternals;
};

class ZCTC_PORT ZcTcScheme
{
public:
    ZcTcScheme(LPCTSTR pszSchemeName);
    virtual ~ZcTcScheme();

    int                 GetName             (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetName             (LPCTSTR pszString);

    ZcTcCatalogSet  *   GetCatalogSet       (DWORD dwCatalogType) const;

    ZcTcCatalogItem *   FindItem            (const GUID& id) const;
    ZcTcCatalogItem *   FindItem            (const GUID& id,
                                             DWORD dwCatalogType) const;

    BOOL                LoadCatalogs        (void);
    BOOL                LoadCatalogs        (DWORD dwCatalogType,
                                             DWORD dwLoadOption);
    BOOL                UnloadCatalogs      (void);
    BOOL                UnloadCatalogs      (DWORD dwCatalogType);
    BOOL                SaveCatalogs        (void);
    BOOL                SaveCatalogs        (DWORD dwCatalogType,
                                             DWORD dwSaveOption);

protected:
    void            *   mpImpObj;

private:
    friend class ZcTcSystemInternals;
};

class ZCTC_PORT ZcTcCatalogSet
{
public:
    virtual ~ZcTcCatalogSet();

    ZcTcScheme      *   GetScheme           (void) const;

    INT_PTR             GetCatalogCount     (void) const;
    ZcTcCatalogItem *   GetCatalog          (int nIndex) const;

    ZcTcCatalogItem *   FindItem            (const GUID& id) const;

    int                 GetCatalogPath      (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetCatalogPath      (LPCTSTR pszPath);

    INT_PTR             AddCatalog          (ZcTcCatalogItem* pCatalog);
    INT_PTR             InsertCatalog       (INT_PTR nIndex,
                                             ZcTcCatalogItem* pCatalog);
    ZcTcCatalogItem*    RemoveCatalog       (int nIndex);

    BOOL                LoadCatalogs        (void);
    BOOL                LoadCatalogs        (DWORD dwLoadOption);
    BOOL                UnloadCatalogs      (void);
    BOOL                SaveCatalogs        (void);
    BOOL                SaveCatalogs        (DWORD dwSaveOption);

protected:

    ZcTcCatalogSet(DWORD dwCatalogType);

protected:
    void            *   mpImpObj;

private:
    friend class ZcTcSystemInternals;
};

class ZCTC_PORT ZcTcCatalogItem
{

    friend class ZcTcImpCatalogItem;

public:
    static ZcTcCatalogItem * FromFile       (LPCTSTR pszFile,
                                             BOOL bLoad         = FALSE,
                                             DWORD dwLoadOption = kLoadLinks);
    static CatalogItemType   GetType        (LPCTSTR pszFile);

public:
    virtual ~ZcTcCatalogItem();

    BOOL                Load                (LPCTSTR pszUrl,
                                             DWORD dwLoadOption = kLoadLinks);
    BOOL                LoadLink            (void);
    BOOL                Save                (LPCTSTR pszUrl,
                                             DWORD dwSaveOption = kSaveLinksAsLinks);
    INT_PTR             AddChild            (ZcTcCatalogItem* pNewItem);
    INT_PTR             InsertChild         (INT_PTR iIndex,
                                             ZcTcCatalogItem* pNewItem);
    BOOL                DeleteChild         (ZcTcCatalogItem* pItem);
    BOOL                DetachChild         (ZcTcCatalogItem* pItem);
    INT_PTR             GetChildCount       (void) const;
    INT_PTR             GetChildCount       (CatalogItemType nType) const;
    ZcTcCatalogItem *   GetChild            (INT_PTR iIndex) const;
    ZcTcCatalogItem *   GetNextChild        (int iIndex,
                                             CatalogItemType nType) const;
    BOOL                DeleteAllChildren   (void);
    BOOL                HasChildren         (void) const;

    BOOL                GetID               (GUID* pId) const;
    BOOL                SetID               (const GUID* pId);
    ZcTc::AccessRight   GetAccessRight      (void) const;
    BOOL                SetAccessRight      (ZcTc::AccessRight nAccessRight);
    BOOL                IsReadOnly          (void) const;
    int                 GetName             (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetName             (LPCTSTR pszString);
    int                 GetDescription      (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetDescription      (LPCTSTR pszString);
    int                 GetToolTipText      (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetToolTipText      (LPCTSTR pszString);
    INT_PTR             GetImageFilePath    (INT_PTR iIndex,
                                             LPTSTR pszString,
                                             size_t cchSize) const;
    BOOL                GetHelpInfo         (LPTSTR pszFile,
                                             LPTSTR pszCommand,
                                             LPTSTR pszData) const;
    BOOL                SetHelpInfo         (LPCTSTR pszFile,
                                             LPCTSTR pszCommand,
                                             LPCTSTR pszData);
    int                 GetKeywords         (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetKeywords         (LPCTSTR pszString);
    int                 GetLinkUrl          (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetLinkUrl          (LPCTSTR pszString);
    int                 GetSourceUrl        (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetSourceUrl        (LPCTSTR pszString);
    int                 GetParentDocumentName(LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetParentDocumentName(LPCTSTR pszString);
    int                 GetParentDocumentDescription(LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetParentDocumentDescription(LPCTSTR pszString);
    int                 GetParentDocumentUrl(LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetParentDocumentUrl(LPCTSTR pszString);
    int                 GetPublisherName    (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetPublisherName    (LPCTSTR pszString);
    int                 GetPublisherDescription(LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetPublisherDescription(LPCTSTR pszString);
    int                 GetPublisherCountry (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetPublisherCountry (LPCTSTR pszString);
    int                 GetPublisherEmail   (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetPublisherEmail   (LPCTSTR pszString);
    int                 GetPublisherUrl     (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetPublisherUrl     (LPCTSTR pszString);
    int                 GetUrl              (LPTSTR pszString,
                                             int cchSize) const;
    int                 GetLocalFile        (LPTSTR pszString,
                                             int cchSize) const;
    ZcTcCatalogItem *   GetRoot             (void) const;
    ZcTcScheme      *   GetScheme           (void) const;
    ZcTcCatalogItem *   GetParent           (void) const;
    BOOL                SetParent           (ZcTcCatalogItem* pParent);
    BOOL                IsRoot              (void) const;
    BOOL                IsLink              (void) const;
    BOOL                IsLinkLoaded        (void) const;
    ZcTcImageList   *   GetImageList        (void) const;
    ZcTcImage       *   GetImage            (const SIZE* pSize, BOOL bUseDarkTheme=FALSE);
    int                 GetXml              (LPTSTR pszString,
                                             int cchSize,
                                             DWORD dwSaveOption = kSaveLinksAsLinks);
    virtual ZcTcCatalogItem* FindInChildren (const GUID& id,
                                             BOOL bRecursive = TRUE);
    ZcTcCatalogItem *   FindInChildren      (LPCTSTR pszName);
    ZcTcCatalogItem *   FindInChildren      (LPCTSTR pszName,
                                             BOOL bRecursive);
    BOOL                GetTime             (time_t* pCreated,
                                             time_t* pLastModified,
                                             time_t* pLastRefreshed) const;
    BOOL                SetTime             (const time_t* pCreated,
                                             const time_t* pLastModified,
                                             const time_t* pLastRefreshed);
    BOOL                CanRefresh          (void) const;
    BOOL                SetRefresh          (BOOL bRefresh);
    BOOL                GetRefresh          (void) const;
    virtual BOOL        Refresh             (DWORD dwRefreshFlag    = kRefreshAll);
    virtual BOOL        Download            (LPCTSTR pszUrl,
                                             DWORD dwDownloadFlag  = kDownloadAll,
                                             LPCTSTR pszDownloadPath        = NULL);
    BOOL                SetAutoRefresh       (BOOL bAutoRefresh);
    BOOL                GetAutoRefresh      (void) const;
    int                 GetReferencePath    (LPTSTR pszString,
                                             int cchSize,
                                             int nFlag) const;
    BOOL                SetReferencePath    (LPCTSTR pszString,
                                             int nFlag);
    BOOL                GetCustomData       (IUnknown** ppCustomData);
    BOOL                SetNewID            (BOOL bRecursive = FALSE);
    BOOL                DeleteImageFile     (BOOL bRecursive = FALSE);
    int                 GetLinkFilePath     (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                DeleteLinkFile      (BOOL bRecursive = FALSE);
    BOOL                GetSourceID         (GUID* pId) const;
    BOOL                SetSourceID         (const GUID* pId);
    ZcTcImage       *   GetOverlayImage     (BOOL bUseDarkTheme = FALSE) const;
    BOOL                SetOverlayImage     (const ZcTcImage* pImage, BOOL bUseDarkTheme = FALSE);
    BOOL                GetOverlayImageInfo (ZCTC_IMAGE_INFO* pImageInfo, BOOL bUseDarkTheme = FALSE) const;
    BOOL                SetOverlayImageInfo (const ZCTC_IMAGE_INFO* pImageInfo);
    INT_PTR             GetOverlayImageFilePath(LPTSTR pszString,
                                             size_t cchSize,
											 BOOL bUseDarkTheme = FALSE) const;
    BOOL                DeleteOverlayImageFile(BOOL bRecursive = FALSE);
    INT_PTR             GetTargetProductCount(void) const;
    BOOL                GetTargetProduct    (INT_PTR iIndex,
                                             ZCTC_TARGET_PRODUCT_INFO* pProductInfo) const;
    INT_PTR             AddTargetProduct    (const ZCTC_TARGET_PRODUCT_INFO* pProductInfo);
    BOOL                DeleteTargetProduct (int iIndex);
    BOOL                IsValidForProduct   (LPCTSTR pszProductName,
                                             int nMajorVersion,
                                             int nMinorVersion,
                                             DWORD dwLocaleId = 0);
    BOOL                AddReactor          (ZcTcCatalogItemReactor* pReactor);
    BOOL                RemoveReactor       (ZcTcCatalogItemReactor* pReactor);
    BOOL                Sort                (int nSortOption,
                                             BOOL bRecursive);
    BOOL                SetItemOrder        (ZcTcCatalogItem** pItems,
                                             INT_PTR nNumItems);
    ZcTc::ItemOption    GetOption           (void) const;
    BOOL                SetOption           (ZcTc::ItemOption nOption);

public:

    virtual ZcTcCatalogItem&    operator=   (const ZcTcCatalogItem& srcItem);
    virtual BOOL        Reset               (void);

    virtual CatalogItemType GetType         (void) const;
    virtual int         GetTypeString       (LPTSTR pszString,
                                             int cchSize,
                                             BOOL bLocalized    = FALSE,
                                             BOOL bPluralForm   = FALSE) const;
    virtual int         GetTagName          (LPTSTR pszString,
                                             int cchSize) const;

    virtual BOOL        Load                (IUnknown* pUnknown,
                                             DWORD dwLoadOption = kLoadLinks);
    virtual BOOL        Load                (IStream* pStream,
                                             DWORD dwLoadOption = kLoadLinks);
    virtual BOOL        Save                (IUnknown* pUnknown,
                                             DWORD dwSaveOption = kSaveLinksAsLinks);
    virtual BOOL        Save                (IStream* pStream,
                                             DWORD dwSaveOption = kSaveLinksAsLinks);
    virtual BOOL        Clone               (BOOL bDeep,
                                             ZcTcCatalogItem*& pClone,
                                             BOOL bCopyId = FALSE) const;
    virtual BOOL        CopyFrom            (const ZcTcCatalogItem* pSrcItem,
                                             BOOL bCopyId = FALSE);
    virtual BOOL        IsValidChild        (const CatalogItemType nType) const;

protected:

    virtual ZcTcCatalogItem * CreateObject  (void) const;

protected:

    ZcTcCatalogItem(ZcTcSystemInternals*);

protected:
    void            *   mpImpObj;

private:
    friend class ZcTcSystemInternals;
};

class ZCTC_PORT ZcTcCategory : public ZcTcCatalogItem
{
public:
    ZcTcCategory();
    ZcTcCategory(const ZcTcCategory& srcItem);
    virtual ~ZcTcCategory();

protected:

    ZcTcCategory(ZcTcSystemInternals*);
};

class ZCTC_PORT ZcTcCatalog : public ZcTcCategory
{
public:
    ZcTcCatalog();
    ZcTcCatalog(const ZcTcCatalog& srcItem);
    virtual ~ZcTcCatalog();

protected:

    ZcTcCatalog(ZcTcSystemInternals*);
};

class ZCTC_PORT ZcTcStockTool : public ZcTcCatalogItem
{
public:
    ZcTcStockTool();
    ZcTcStockTool(const ZcTcStockTool& srcItem);
    virtual ~ZcTcStockTool();

    ZcTcTool        *   CreateTool          (BOOL bSetDefaults = TRUE);

    BOOL                CreateZcadStockTool (IUnknown** ppStockTool);
    BOOL                CreateZcadTool      (IUnknown** ppUnknown);

    BOOL                GetComClassID       (CLSID& clsid) const;
    BOOL                SetComClassID       (const  CLSID& clsid);
    int                 GetModuleFileName   (LPTSTR pszString,
                                            int cchSize) const;
    BOOL                SetModuleFileName   (LPCTSTR pszString);
    int                 GetModuleInstallUrl (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetModuleInstallUrl (LPCTSTR pszString);
    int                 GetModuleInstallArguments(LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetModuleInstallArguments(LPCTSTR pszString);

protected:

    ZcTcStockTool(ZcTcSystemInternals*);

private:
    friend class ZcTcSystemInternals;
};

class  ZCTC_PORT ZcTcTool : public ZcTcCatalogItem
{
public:
    ZcTcTool();
    ZcTcTool(const ZcTcTool& srcItem);
    virtual ~ZcTcTool();

    virtual BOOL        Execute             (int nFlag,
                                             HWND hWnd,
                                             POINT point,
                                             DWORD dwKeyState);
    BOOL                GetToolData         (IUnknown** ppUnknown);
    ZcTcStockTool *     GetStockTool        (void) const;
    BOOL                CreateZcadTool      (IUnknown** ppTool,
                                             BOOL bLoadData = TRUE);
    BOOL                GetStockToolID      (GUID* pId) const;
    BOOL                SetStockToolID      (const GUID* pId);
    int                 GetStockToolFileUrl (LPTSTR pszString,
                                             int cchSize) const;
    BOOL                SetStockToolFileUrl (LPCTSTR pszString);
    ToolType            GetToolType         (void) const;
    BOOL                SetToolType         (ToolType nToolType);
    BOOL                IsFlyoutEnabled     (void) const;
    BOOL                EnableFlyout        (BOOL bUseFlyout);
    ZcTcCatalogItem*    GetShapePackage     (void) const;
    BOOL                SetShapePackage     (ZcTcCatalogItem* pPackage);
    ZcTcTool*           GetCurrentShape     (void) const;
    BOOL                SetCurrentShape     (ZcTcTool* pTool);
    BOOL                SetCurrentShape     (const GUID& id);
    BOOL                GetActiveShapes     (ZcTcCatalogItem** pItems,
                                             INT_PTR & nNumItems);
    BOOL                SetActiveShapes     (ZcTcCatalogItem** pItems,
                                             int nNumItems);
protected:

    ZcTcTool(ZcTcSystemInternals*);
};

class ZCTC_PORT ZcTcPackage : public ZcTcCatalogItem
{
public:
    ZcTcPackage();
    ZcTcPackage(const ZcTcPackage& srcItem);
    virtual ~ZcTcPackage();

protected:

    ZcTcPackage(ZcTcSystemInternals*);
};

class ZCTC_PORT ZcTcPalette : public ZcTcPackage
{
public:
    ZcTcPalette();
    ZcTcPalette(const ZcTcPalette& srcItem);
    virtual ~ZcTcPalette();

protected:

    ZcTcPalette(ZcTcSystemInternals*);
};

class ZCTC_PORT ZcTcCatalogItemReactor
{
public:
    virtual ~ZcTcCatalogItemReactor(void);

    BOOL                Enable              (BOOL bEnable);
    BOOL                IsEnabled           (void) const;

    virtual void        ChildAdded          (ZcTcCatalogItem* pChild);
    virtual void        ChildDeleted        (ZcTcCatalogItem* pChild);
    virtual void        ChildDetached       (ZcTcCatalogItem* pChild);

protected:
    void            *   mpImpObj;

protected:

    ZcTcCatalogItemReactor();

private:
    friend class ZcTcSystemInternals;
};

ZCTC_PORT BOOL ZcTcInitialize   (void);
ZCTC_PORT BOOL ZcTcUninitialize (void);
ZCTC_PORT ZcTcManager* ZcTcGetManager(void);
ZCTC_PORT BOOL ZcTcDownloadItem (LPCTSTR pszUrl,
                                 ZcTcCatalogItem*& pNewItem,
                                 DWORD dwItemTypes      = -1,
                                 DWORD dwDownloadFlag   = kDownloadAll,
                                 LPCTSTR pszDownloadPath= NULL);
ZCTC_PORT int ZcTcDownloadItem  (LPTSTR* pUrls,
                                 int nNumUrls,
                                 ZcTcCatalogItem** pItems,
                                 DWORD dwItemTypes      = -1,
                                 DWORD dwDownloadFlag   = kDownloadAll,
                                 LPCTSTR pszDownloadPath= NULL);
ZCTC_PORT BOOL ZcTcRefreshItem  (ZcTcCatalogItem** pItems,
                                 int nNumItems,
                                 DWORD dwItemTypes      = -1,
                                 DWORD dwRefreshFlag    = kRefreshAll);
ZCTC_PORT BOOL ZcTcSort         (ZcTcCatalogItem** pItems,
                                 int nNumItems,
                                 int nSortOption);

