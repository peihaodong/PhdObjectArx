

#ifndef ZcDbHostApplicationServices_INC
#define ZcDbHostApplicationServices_INC

#include "zadesk.h"
#include "zacdb.h"
#include "zacarray.h"
#include "zcodepgid.h"

#include "zinetstrc.h"
#include "zrxdlinkr.h"

#pragma pack (push, 8)

class ZcDbAuditInfo;
class ZcDbDatabase;
class ZcDbUndoController;
class ZcDbTransactionManager;
class ZcDbGlobals;
class ZcDbAppSystemVariables;
class COleClientItem;
class CArchive;
class ZcadInternalServices;
struct flagmat;

class ZcDbAbstractClipBoundaryDefinition;
class ClipBoundaryArray;

class ZcDbPlotSettingsValidator;
class ZcDbLayoutManager;
class ZcPwdCache;

struct _EXCEPTION_POINTERS;

#ifndef ZCUTIL_API
#    ifdef ZCUTIL_INTERNAL
#        define ZCUTIL_API ZSOFT_DLLEXPORT
#    else
#        define ZCUTIL_API ZSOFT_DLLIMPORT
#    endif
#endif

#ifdef __LP64__
typedef ZSoft::UInt32 LCID;
#else
typedef unsigned long LCID;
#endif

enum  ZcSDIValues {
    kMDIEnabled = 0,
    kSDIUserEnforced,
    kSDIAppEnforced,
    kSDIUserAndAppEnforced
};

enum ProdIdCode {
    kProd_ZCAD = 1,
    kProd_LT,
    kProd_OEM  = 3,
    kProd_ZcDb = 4,
};


int zcdbHostAppMinorVersion();

class ZcDbHostApplicationProgressMeter{
public:
    ZcDbHostApplicationProgressMeter();
    virtual ~ZcDbHostApplicationProgressMeter();

    virtual void start(const ZTCHAR * displayString = NULL);
    virtual void stop();
    
    virtual void meterProgress();

    virtual void setLimit(int max);

	virtual int setStatusBarProgressMeterPos(int nPos){ return -1; }
};

typedef Zcad::ErrorStatus (*SELECTFILEPROC )( short *userCancel, 
                                              ZTCHAR *& chosenPath,
                                             void* h, 
                                             const int nFlags,
                                             const ZTCHAR * prompt,
                                             const ZTCHAR * dir,
                                             const ZTCHAR * name,
                                             const ZTCHAR * type,
                                             int* pnChoice,
                                             bool* pbReadOnly,
                                             const ZTCHAR * pszWSTags,
                                             void* pReserved);

typedef Zcad::ErrorStatus (* REMAPPROC) ( ZTCHAR *& newName,
                                         const ZTCHAR * filename,
                                         int context,
                                         void* pReserved);

typedef void (* MAPFILENOTIFYPROC) (const ZTCHAR * filename,
                                    const ZTCHAR * newName,
                                    int context,
                                    void* pReserved);

class ZSOFT_NO_VTABLE ZcDbHostApplicationServices : public ZcRxObject
{
    friend class ZcadInternalServices;
public:    
    ZCRX_DECLARE_MEMBERS(ZcDbHostApplicationServices);
    ZcDbHostApplicationServices( int createGlobals = 1 );
    virtual ~ZcDbHostApplicationServices();

    enum FindFileHint
    {
        kDefault = 0,
        kFontFile,              
        kCompiledShapeFile,     
        kTrueTypeFontFile,      
        kEmbeddedImageFile,
        kXRefDrawing,
        kPatternFile,
        kZRXApplication,
        kFontMapFile,
		kUnderlayFile,
		kDataLinkFile,
		kPhotometricWebFile,
		kMaterialMapFile,
		kCloudOrProjectFile,
    };
    
    enum RemapFileContext
    {
        kDrawingOpen,
        kXrefResolution,
        kRasterResolution,
        kAfterXrefResolution
    };

    virtual Zcad::ErrorStatus findFile(ZTCHAR * pcFullPathOut,
                 int   nBufferLength,
                 const ZTCHAR * pcFilename,
                 ZcDbDatabase * pDb = NULL, 
                                            
                 ZcDbHostApplicationServices::FindFileHint hint = kDefault) = 0;

    virtual Zcad::ErrorStatus getRoamableRootFolder(const ZTCHAR *& folder);
    virtual Zcad::ErrorStatus getLocalRootFolder(const ZTCHAR *& folder);
	virtual Zcad::ErrorStatus getAllUsersRootFolder(const ZTCHAR*& folder);
	virtual Zcad::ErrorStatus getGraphicsCacheFolder(const ZTCHAR *& folder);

    virtual Zcad::ErrorStatus   selectFile(short *userCancel, 
                                           ZTCHAR *& chosenPath,
                                           void* h, 
                                           const int nFlags,
                                           const ZTCHAR * prompt,
                                           const ZTCHAR * dir,
                                           const ZTCHAR * name,
                                           const ZTCHAR * type,
                                           int* pnChoice,
                                           bool* pbReadOnly,
                                           const ZTCHAR * pszWSTags,
                                           void* pReserved) ;
    virtual Zcad::ErrorStatus   registerSelectFileCallback(const ZTCHAR * appName,
                                                   SELECTFILEPROC proc, 
                                                   bool unRegister = false, 
                                                   bool asPrimary  = false);
    virtual const ZTCHAR *       primaryClientForSelectFileCallback();
    virtual Zcad::ErrorStatus   getRegisteredSelectFileClients(
                                            ZcArray<const ZTCHAR *>& clients);

    virtual Zcad::ErrorStatus   mapFile( ZTCHAR *& newName,
                                        const ZTCHAR * filename,
                                        int context,
                                        void* pReserved);
    virtual Zcad::ErrorStatus   registerMapFileCallback(const ZTCHAR * appName,
                                                REMAPPROC  proc,
                                                bool unRegister = false, 
                                                bool asPrimary  = false);
    virtual const ZTCHAR *       primaryClientForMapFileCallback();
    virtual bool                setMapFlag(bool setIt);
    virtual Zcad::ErrorStatus   getRegisteredFileMapClients(
                                            ZcArray<const ZTCHAR *>& clients);
    virtual Zcad::ErrorStatus   registerMapFileNotification(const ZTCHAR * appName,
                                                MAPFILENOTIFYPROC,
                                                bool unRegister = false);

    virtual void fatalError(const ZTCHAR *format, ...);

    virtual void reportUnhandledZrxException(const _EXCEPTION_POINTERS *pExcPtrs,
                                             const ZTCHAR *pAppName);

    virtual ZSoft::Boolean userBreak(bool updCtrlsWhenEnteringIdle = true) const;

    virtual void displayChar(ZTCHAR c) const;
    virtual void displayString(const ZTCHAR* string, int count) const;

    virtual ZSoft::Boolean readyToDisplayMessages();

    virtual void enableMessageDisplay(ZSoft::Boolean);

    virtual ZSoft::Boolean doFullCRCCheck();

    virtual unsigned int getTempPath(ZSoft::UInt32 lBufferSize, 
                                                ZTCHAR* pcBuffer);

    virtual const ZTCHAR* getEnv(const ZTCHAR * var);

    virtual ZcDbHostApplicationProgressMeter* newProgressMeter();

    void setWorkingProgressMeter(ZcDbHostApplicationProgressMeter* pNewMeter);

    virtual ZcDbAbstractClipBoundaryDefinition* newClipBoundaryRectangular();
    virtual ZcDbAbstractClipBoundaryDefinition* newClipBoundaryPolygonal();
    virtual ClipBoundaryArray* newClipBoundaryArray();

    ZcDbDatabase* workingDatabase() const;
    void setWorkingDatabase(ZcDbDatabase* pDatabase);

    virtual ZcDbUndoController* defaultUndoController();
    void setDefaultUndoController(ZcDbUndoController* pUndoCtrl);

    virtual ZcDbTransactionManager* workingTransactionManager();
    void setWorkingTransactionManager(ZcDbTransactionManager* pTM);

    virtual ZcDbGlobals * createWorkingGlobals();
    ZcDbGlobals * workingGlobals() const;
    void setWorkingGlobals(ZcDbGlobals* pGlobals);
    
    ZcDbAppSystemVariables * workingAppSysvars() const;
    void setWorkingAppSysvars(ZcDbAppSystemVariables* pSysvars);

    virtual const ZTCHAR * program ();
    virtual const ZTCHAR * product ();
    virtual const ZTCHAR * companyName();
    virtual const ProdIdCode prodcode();
    virtual const ZTCHAR * releaseMajorMinorString();
    virtual int   releaseMajorVersion();
    virtual int   releaseMinorVersion();
    virtual const ZTCHAR * versionString();
	ZCDB_PORT virtual const ZTCHAR* getMachineRegistryProductRootKey();
	ZCDB_PORT virtual const ZTCHAR* getUserRegistryProductRootKey();
	virtual const ZTCHAR* releaseMarketVersion();

    virtual LCID  getRegistryProductLCID() ;
    virtual bool  supportsMultiRedo() const;
    enum ModelerFlavor {kModelerFull=0, kModelerRegionsOnly=1, kModelerObjectsOnly=2};
    virtual ModelerFlavor  getModelerFlavor() const;

    code_page_id getSystemCodePage() const;

    virtual ZcadInternalServices* zcadInternalServices();

    void * zcadInternalGetvar (const ZTCHAR *name);

    virtual ZSoft::Boolean isURL(const ZTCHAR * pszURL) const;

    virtual ZSoft::Boolean isRemoteFile(const ZTCHAR * pszLocalFile,
                                          ZTCHAR * pszURL, size_t urlLen) const;
	template<size_t N> ZSoft::Boolean isRemoteFile(const ZTCHAR * pszLocalFile,
		ZTCHAR (&pszURL)[N]) const
	{
		return isRemoteFile(pszLocalFile, pszURL, N);
	}
    virtual Zcad::ErrorStatus getRemoteFile(const ZTCHAR * pszURL,
     ZTCHAR * pszLocalFile, size_t localFileLen, ZSoft::Boolean bIgnoreCache) const;
	template<size_t N> 
	Zcad::ErrorStatus getRemoteFile(const ZTCHAR * pszURL, ZTCHAR (&pszLocalFile)[N]) const
	{
		return this->getRemoteFile(pszURL, pszLocalFile, N, false);
	}
	template<size_t N> 
	Zcad::ErrorStatus getRemoteFile(const ZTCHAR * pszURL, ZTCHAR (&pszLocalFile)[N], bool bIgnoreCache) const
	{
		return this->getRemoteFile(pszURL, pszLocalFile, N, bIgnoreCache);
	}
    virtual Zcad::ErrorStatus putRemoteFile(const ZTCHAR * pszURL,
        const ZTCHAR * pszLocalFile) const;

	virtual ZSoft::Boolean isCloudFile(const ZTCHAR* pszCloudFile) const;

    virtual ZSoft::Boolean launchBrowserDialog(
                 ZTCHAR *          pszSelectedURL,
				 size_t            selectedUrlLen,
                 const ZTCHAR *    pszDialogTitle,
                 const ZTCHAR *    pszOpenButtonCaption,
                 const ZTCHAR *    pszStartURL,
                 const ZTCHAR *    pszRegistryRootKey = 0,
                 ZSoft::Boolean bOpenButtonAlwaysEnabled = ZSoft::kFalse) const;
	template<size_t N> ZSoft::Boolean launchBrowserDialog(
		ZTCHAR          (&pszSelectedURL)[N],
		const ZTCHAR*    pszDialogTitle,
		const ZTCHAR*    pszOpenButtonCaption,
		const ZTCHAR*    pszStartURL, 
		const ZTCHAR*    pszRegistryRootKey = 0,
		ZSoft::Boolean bOpenButtonAlwaysEnabled = ZSoft::kFalse) const
	{
		return launchBrowserDialog(pszSelectedURL,N,pszDialogTitle,
			pszOpenButtonCaption,pszStartURL,
			pszRegistryRootKey,bOpenButtonAlwaysEnabled);
	}
    virtual void drawOleOwnerDrawItem(COleClientItem* pItem,
                                      ZSoft::LongPtr hdc,
        ZSoft::Int32 left,  ZSoft::Int32 top,  ZSoft::Int32 right,  ZSoft::Int32 bottom);

    virtual Zcad::ErrorStatus getNewOleClientItem(COleClientItem*& pItem);

    virtual Zcad::ErrorStatus serializeOleItem(COleClientItem* pItem,
        CArchive*);

    virtual ZSoft::Boolean _entToWorldTransform(double normal[3], 
                                                flagmat *tran);

    virtual void terminateScript();
    virtual ZSoft::Boolean getSubstituteFont(ZTCHAR **pFileName,
                                             const ZTCHAR *prompt,
                                             int type, int fontAlt); 
	virtual ZSoft::Boolean getSubstituteFont(ZTCHAR **pFileName,
											ZTCHAR *prompt,
											int type, int fontAlt) sealed
	{
		const ZTCHAR* pPrompt = prompt;
		return this->getSubstituteFont(pFileName, pPrompt, type, fontAlt);
	}
    virtual void alert(const ZTCHAR * string) const;

    virtual void auditPrintReport(ZcDbAuditInfo * pAuditInfo,
                                             const ZTCHAR *    line,
                                             int             both) const;

    virtual ZTCHAR * getAlternateFontName() const;

    virtual ZTCHAR * getFontMapFileName() const;

    virtual bool cacheSymbolIndices() const { return false; }

    virtual ZcDbPlotSettingsValidator* plotSettingsValidator() const; 
    virtual ZcDbLayoutManager* layoutManager() const;
    virtual bool loadApp(const ZTCHAR * appName,
                         ZcadApp::LoadReasons why, 
                         bool printit, 
                         bool asCmd);
    virtual bool getDefaultPlotCfgInfo(ZTCHAR * plotDeviceName, size_t nDevNameLen,
                                       ZTCHAR * plotStyleName, size_t nStyleNameLen);
	template<size_t nDevNameLen, size_t nStyleNameLen>
	bool getDefaultPlotCfgInfo(ZTCHAR (&plotDeviceName)[nDevNameLen], ZTCHAR (&plotStyleName)[nStyleNameLen])
	{
		return getDefaultPlotCfgInfo(plotDeviceName, nDevNameLen, plotStyleName, nStyleNameLen);
	}
    virtual Zcad::ErrorStatus signingComplete(Zcad::ErrorStatus es,
                                              const ZTCHAR * msg,
                                              bool* result);

	enum PasswordOptions {kPasswordOptionDefault = 0, kPasswordOptionUpperCase =1, kPasswordOptionIsExternalReference = 2};
	virtual bool getPassword(const ZTCHAR* dwgName,
                             PasswordOptions options,
                             wchar_t *password, 
                             const size_t bufSize);

    virtual void usedPasswordFromCacheMsg(const ZTCHAR *dwgName);
    virtual void missingCryptoProviderMsg();

    virtual const ZTCHAR * getColorBookLocation() const;

    ZcPwdCache * getPasswordCache() const;
	virtual short getKeyState(int nVirtKey) const;

	enum RequiredVersionFlags 
	{
		kNoOpen       = 0,
		kReadOnly     = 1,
		kWriteAllowed = 2
	};
	virtual bool requiredVersionNotAvailable(ZcDbHostApplicationServices::RequiredVersionFlags flags, ZcDbDatabase* pDb)const;
	virtual bool notifyCorruptDrawingFoundOnOpen(ZcDbObjectId id, Zcad::ErrorStatus es) { return false; }
	//Deprecated: the following method will be removed in future.
	ZSoft::Boolean isRemoteFile(const ZTCHAR * pszLocalFile,ZTCHAR * pszURL) const;
	Zcad::ErrorStatus getRemoteFile(const ZTCHAR * pszURL, ZTCHAR * pszLocalFile, ZSoft::Boolean bIgnoreCache) const;
	ZSoft::Boolean launchBrowserDialog(ZTCHAR* pszSelectedURL,
		const ZTCHAR *    pszDialogTitle,
		const ZTCHAR *    pszOpenButtonCaption,
		const ZTCHAR *    pszStartURL,
		const ZTCHAR *    pszRegistryRootKey = 0,
		ZSoft::Boolean bOpenButtonAlwaysEnabled = ZSoft::kFalse) const;
	bool getDefaultPlotCfgInfo(ZTCHAR * plotDeviceName, ZTCHAR * plotStyleName);
	//

protected:

    Zcad::ErrorStatus mapInetStatusToZcadStatus(
        const ZcadInet::Status status) const;

protected:

    void * mp_sessionVars;

    void zcadInternalSetvar (const ZTCHAR *name, void * var);

private:

    ZcDbDatabase* mpWorkingDatabase;
    ZcDbUndoController* mpDefaultUndoController;
    ZcDbTransactionManager* mpWorkingTransactionManager;
    ZcDbGlobals * mpWorkingGlobals;
    ZcDbAppSystemVariables * mpWorkingAppSysvars;

    code_page_id m_eSystemCodePage;

    ZSoft::Boolean mbDisplayMessages;

    ZcPwdCache * mpPasswordCache;
};

Zcad::ErrorStatus zcdbSetHostApplicationServices(ZcDbHostApplicationServices * pServices);

ZcDbHostApplicationServices* zcdbHostApplicationServices();

Zcad::ErrorStatus zcdbSendInitialDwgFileOpenComplete(ZcDbDatabase* pDb);

extern ZcDbGlobals* getDefaultGlobals();

inline ZcDbGlobals *
ZcDbHostApplicationServices::workingGlobals() const
{
    return mpWorkingGlobals ? mpWorkingGlobals : getDefaultGlobals();
}

inline code_page_id
ZcDbHostApplicationServices::getSystemCodePage() const
{
    return this->m_eSystemCodePage;
}

inline ZcDbTransactionManager *
ZcDbHostApplicationServices::workingTransactionManager()
{
    return mpWorkingTransactionManager;
}

inline ZcDbDatabase *
ZcDbHostApplicationServices::workingDatabase() const
{
    return mpWorkingDatabase;
}

inline ZcDbAppSystemVariables * 
ZcDbHostApplicationServices::workingAppSysvars() const
{
    return mpWorkingAppSysvars;
}

inline void 
ZcDbHostApplicationServices::setWorkingAppSysvars(ZcDbAppSystemVariables* pSysvars)
{
    mpWorkingAppSysvars = pSysvars;
}

inline ZcPwdCache * 
ZcDbHostApplicationServices::getPasswordCache() const
{
    return mpPasswordCache;
}

void zcdbTriggerZcadOctTreeReclassification();

Zcad::ErrorStatus zcdbSetBreak3dQueueForRegen(bool);

class ZSOFT_NO_VTABLE ZcDbPasswordedFile
{
protected:
    virtual Zcad::ErrorStatus tryPassword(const wchar_t* wzPassword) = 0;
    virtual const ZTCHAR* getFullPath() = 0;
public:
    Zcad::ErrorStatus open(const wchar_t* wszPassword, ZcDbHostApplicationServices::PasswordOptions options);
};

#pragma pack (pop)

#endif


