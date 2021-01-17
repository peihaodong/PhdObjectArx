

#ifndef ZD_DBMAIN_H
#define ZD_DBMAIN_H

#include <stddef.h>
#include "zadesk.h"
#ifdef _ZSOFT_WINDOWS_
#include <share.h>
#endif
#include "zgepnt3d.h"
#include "zgevec3d.h"
#include "zgeline3d.h"
#include "zAcHeapOpers.h"
#include "zadesk.h"
#include "zrxobject.h"
#include "zrxdlinkr.h"
#include "zrxiter.h"
#include "zrxditer.h"
#include "zrxsrvice.h"
#include "zdbptrar.h"
#include "zdbcolor.h"
#include "zdbidar.h"
#include "zdrawable.h"
#include "zdbsecurity.h"

class ZcCmEntityColor;
class ZcCmColor;
class ZcDbBlockBegin;
class ZcDbBlockEnd;
class ZcDbDatabase;
class ZcDbDatabaseIterator;
class ZcDbDatabaseReactor;
class ZcDbEntity;
class ZcDbEntityReactor;
class ZcDbImpDatabase;
class ZcDbImpObject;
class ZcDbObject;
class ZcDbObjectReactor;
class ZcDbServices;
class ZcDbSpaceIterator;
class ZcDbSystemInternals;
class ZcDbXObject;
class ZcDbBlockReference;
class ZcDbSymbolTable;
class ZcDbBlockTable;
class ZcDbBlockTableRecord;    
class ZcDbLayerTable;
class ZcDbTextStyleTable;
class ZcDbLinetypeTable;
class ZcDbAbstractViewTable;
class ZcDbViewTable;
class ZcDbUCSTable;
class ZcDbViewportTable;
class ZcDbRegAppTable;
class ZcDbDimStyleTable;
class ZcDbDimStyleTableRecord;
class ZcDbIdMapping;
class ZcDbDictionary;
class ZcDbDictionaryWithDefault;
class ZcDbMline;
class ZcDbMlineStyle;
class ZcDbCurve;
class ZcDbEllipse;
class ZcDbSpline;
class ZcDbRegion;
class ZcDb3dSolid;
class ZcDbBody;
class ZcDbDate;
class ZcDbExtents;
class ZcDbAuditInfo;
class ZcDbUndoController;
class ZcDbTransactionManager;
class ZcDbSpatialFilter;
class ZcDbLayerFilter;
class ZcGeFastTransform;
class ZcGsNode;
class ZcGsModel;
class ZcGiContext;
class ZcDbObjectIdGraph;
class ZcDbLayerStateManager;
class ZcDwgFileHandle;
class ZcFileDependencyManager;
class ZcDbTableStyle;
class ZcFdFieldValue;
class ZcDbField;
class ZcDbSectionManager;
class ZcDbDataLinkManager;
class ZcGiMapper;
class ZcDbAnnotationScale;

#include "zacdb.h"
#include "zdbhandle.h"
#include "zdbfiler.h"
#include "zads.h"
#include "zgept3dar.h"
#include "zdbintar.h"
#include "zdbsubeid.h"
#include "zdbaudita.h"
#include "ZRXExports.h"

#pragma pack(push, 8)

#ifndef _ZSOFT_WINDOWS_
#define _SH_DENYRW      0x10    /* deny read/write mode */
#define _SH_DENYWR      0x20    /* deny write mode */
#define _SH_DENYRD      0x30    /* deny read mode */
#define _SH_DENYNO      0x40    /* deny none mode */
#define _SH_SECURE      0x80    /* secure mode */
#endif

struct _GUID;
typedef struct _GUID CLSID;

class ZcDbGripData;
typedef ZcArray<ZcDbGripData*, ZcArrayMemCopyReallocator<ZcDbGripData*>> ZcDbGripDataPtrArray;
typedef ZcArray<ZcDbFullSubentPath,
        ZcArrayObjectCopyReallocator<ZcDbFullSubentPath> > ZcDbFullSubentPathArray;

ZRX_DB_EXPORT_GLOBAL extern const ZcDbFullSubentPath kNullSubent;

ZcDbServices* zcdbServices();

ZcDb::DwgDataType zcdbGroupCodeToType(ZcDb::DxfCode pCode);
void              zcdbFreeResBufContents(resbuf* pField);
bool              zcdbIsPersistentReactor(void *pSomething);
ZcDbObjectId      zcdbPersistentReactorObjectId(void *pSomething);

bool   zcdbDisplayPreviewFromDwg(const ZTCHAR *pszDwgfilename,
                                 void* pPreviewWnd,
                                 const ZSoft::UInt32* pBgColor = nullptr);

bool zcdbIsCustomObject(const ZcDbObjectId& id);

ZCDB_PORT Zcad::ErrorStatus 
zcdbOpenObject(ZcDbObject*& pObj, ZcDbObjectId id, ZcDb::OpenMode mode,
				bool openErased = false, const ZcRxClass *pClass = nullptr);
Zcad::ErrorStatus
zcdbOpenZcDbObject(ZcDbObject*& pObj, ZcDbObjectId id, ZcDb::OpenMode mode,
                   bool openErasedObject = false);
 
Zcad::ErrorStatus ZSOFT_STDCALL
zcdbOpenZcDbObject(ZcDbObject*& pObj, ZcDbObjectId id, ZcDb::OpenMode mode,
                   const ZcRxClass *pClass, bool openErasedObject = false);
 
Zcad::ErrorStatus
zcdbOpenZcDbEntity(ZcDbEntity*& pEnt, ZcDbObjectId id, ZcDb::OpenMode mode,
                   bool openErasedEntity = false);

template<class T_OBJECT> inline Zcad::ErrorStatus
zcdbOpenObject(
    T_OBJECT *& pObj, ZcDbObjectId id, ZcDb::OpenMode mode,
    bool openErased = false)
{
    return ::zcdbOpenObject((ZcDbObject * &)pObj, id, mode,
                                openErased, T_OBJECT::desc());
}
ZCDB_PORT Zcad::ErrorStatus zcdbOpenObject(ZcDbEntity *& pEnt, ZcDbObjectId id, ZcDb::OpenMode mode, bool openErased = false);

Zcad::ErrorStatus zcdbResurrectMeNow(const ZcDbObjectId& id);

Zcad::ErrorStatus zcdbGetZdsName(zds_name&  objName, ZcDbObjectId objId);
Zcad::ErrorStatus zcdbValKey(const zds_name name);
Zcad::ErrorStatus zcdbGetObjectId(ZcDbObjectId& objId,
                                         const zds_name objName);

Zcad::ErrorStatus zcdbSetReferenced(ZcDbObjectId objId);

ZcDbVoidPtrArray* zcdbActiveDatabaseArray();

class ZcDbViewTableRecord;
class ZcDbViewport;
class ZcDbObjectContextManager;

Zcad::ErrorStatus zcdbLoadMlineStyleFile(
                const ZTCHAR *sname, const ZTCHAR *fname);

Zcad::ErrorStatus zcdbLoadLineTypeFile(const ZTCHAR *ltname,
                                       const ZTCHAR *fname,
                                       ZcDbDatabase *pDb);

void* zcdbAlloc(size_t);
void* zcdbRealloc(void *, size_t);
#ifdef MEM_DEBUG
void*             zcdbAlloc_dbg(size_t ZCDBG_PARAM_DEC);
void*             zcdbRealloc_dbg(void *, size_t ZCDBG_PARAM_DEC);
#define zcdbAlloc(a) zcdbAlloc_dbg(a, /*__FILE__*/"", /*__LINE__*/1)
#define zcdbRealloc(a, b) zcdbRealloc_dbg(a, b, /*__FILE__*/"", /*__LINE__*/1)
#endif
void  zcdbFree(void*);

Zcad::ErrorStatus zcdbValidateSetup(ZSoft::Int32 lcid);

Zcad::ErrorStatus zcdbCleanUp();

const ZTCHAR* zcdbOriginalXrefFullPathFor(const ZcDbDatabase*);

ZcGiContext * zcdbSetDefaultZcGiContext(ZcGiContext *);

Zcad::ErrorStatus 
zcdbGetThumbnailBitmapFromDxfFile(const ZTCHAR* filename, void*& pBitmap);

Zcad::ErrorStatus zcdbSaveAs2004(ZcDbDatabase* pDb, const ZTCHAR* fileName);

Zcad::ErrorStatus zcdbSaveAs2000(ZcDbDatabase* pDb, const ZTCHAR* fileName);

Zcad::ErrorStatus zcdbDxfOutAs2004(ZcDbDatabase* pDb, const ZTCHAR* fileName,
                                         const int precision = 16);
Zcad::ErrorStatus zcdbDxfOutAs2000(ZcDbDatabase* pDb, const ZTCHAR* fileName,
                                         const int precision = 16);
Zcad::ErrorStatus zcdbDxfOutAsR12(ZcDbDatabase* pDb, const ZTCHAR* fileName,
                                         const int precision = 16);
Zcad::ErrorStatus zcdbSaveAsR14(ZcDbDatabase* pDb, const ZTCHAR* fileName);

long zcdbSetDbmod(ZcDbDatabase* pDatabase, long lNewVal);

class ZSOFT_NO_VTABLE ZcDbServices: public ZcRxService
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbServices);
};

class ZcDbDatabase: public ZcRxObject, public ZcHeapOperators
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDatabase);

    ZcDbDatabase(bool buildDefaultDrawing = true,
                 bool noDocument = false);
    virtual ~ZcDbDatabase();
    Zcad::ErrorStatus addZcDbObject(ZcDbObject*    pObj);
    Zcad::ErrorStatus addZcDbObject(ZcDbObjectId&  objId,
                                    ZcDbObject*    pObj);

    static Zcad::ErrorStatus markObjectNonPersistent(ZcDbObjectId id, bool value);
    static bool isObjectNonPersistent(ZcDbObjectId id);

    Zcad::ErrorStatus getBlockTable     (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getLayerTable     (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getTextStyleTable (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getLinetypeTable  (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getViewTable      (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getUCSTable       (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getViewportTable  (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getRegAppTable    (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getDimStyleTable  (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode);

    Zcad::ErrorStatus getSymbolTable    (ZcDbBlockTable*&     pTable,
                                         ZcDb::OpenMode       mode);
    Zcad::ErrorStatus getSymbolTable    (ZcDbLayerTable*&     pTable,
                                         ZcDb::OpenMode       mode);
    Zcad::ErrorStatus getSymbolTable    (ZcDbTextStyleTable*& pTable,
                                         ZcDb::OpenMode       mode);
    Zcad::ErrorStatus getSymbolTable    (ZcDbLinetypeTable*&  pTable,
                                         ZcDb::OpenMode       mode);
    Zcad::ErrorStatus getSymbolTable    (ZcDbViewTable*&      pTable,
                                         ZcDb::OpenMode       mode);
    Zcad::ErrorStatus getSymbolTable    (ZcDbUCSTable*&       pTable,
                                         ZcDb::OpenMode       mode);
    Zcad::ErrorStatus getSymbolTable    (ZcDbViewportTable*&  pTable,
                                         ZcDb::OpenMode       mode);
    Zcad::ErrorStatus getSymbolTable    (ZcDbRegAppTable*&    pTable,
                                         ZcDb::OpenMode       mode);
    Zcad::ErrorStatus getSymbolTable    (ZcDbDimStyleTable*&  pTable,
                                         ZcDb::OpenMode       mode);

    Zcad::ErrorStatus getGroupDictionary   (ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode);
    Zcad::ErrorStatus getMLStyleDictionary (ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode);
    Zcad::ErrorStatus getLayoutDictionary  (ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode);
    Zcad::ErrorStatus getPlotStyleNameDictionary(
                                            ZcDbDictionaryWithDefault*& pDict,
                                            ZcDb::OpenMode mode);
    Zcad::ErrorStatus getMaterialDictionary(ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode);
    Zcad::ErrorStatus getVisualStyleDictionary(ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode);
    Zcad::ErrorStatus getColorDictionary   (ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode);
	
	Zcad::ErrorStatus getScaleListDictionary(ZcDbDictionary*& pDict,
											ZcDb::OpenMode mode);
	
    Zcad::ErrorStatus getNamedObjectsDictionary(
                                            ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode);

    Zcad::ErrorStatus getBlockTable     (ZcDbBlockTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getLayerTable     (ZcDbLayerTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getTextStyleTable (ZcDbTextStyleTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getLinetypeTable  (ZcDbLinetypeTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getViewTable      (ZcDbViewTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getUCSTable       (ZcDbUCSTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getViewportTable  (ZcDbViewportTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getRegAppTable    (ZcDbRegAppTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getDimStyleTable  (ZcDbDimStyleTable*& pTable,
                                         ZcDb::OpenMode    mode);
    Zcad::ErrorStatus getPlotSettingsDictionary(ZcDbDictionary*& pTable,
                                         ZcDb::OpenMode    mode);
    ZcDbObjectId      getSectionManager (void) const;
    Zcad::ErrorStatus getSectionManager (ZcDbSectionManager*& pMgr,
                                         ZcDb::OpenMode mode) const;
    ZcDbObjectId    dataLinkDictionaryId(void) const;
    Zcad::ErrorStatus getDataLinkDictionary(ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode);
    ZcDbDataLinkManager*getDataLinkManager(void) const;
    Zcad::ErrorStatus updateDataLink    (ZcDb::UpdateDirection nDir,
                                         ZcDb::UpdateOption nOption);
    ZCDB_PORT ZcDbObjectId  blockTableId() const;
    ZCDB_PORT ZcDbObjectId  layerTableId() const;
    ZCDB_PORT ZcDbObjectId  textStyleTableId() const;
    ZCDB_PORT ZcDbObjectId  linetypeTableId() const;
    ZCDB_PORT ZcDbObjectId  viewTableId() const;
    ZCDB_PORT ZcDbObjectId  UCSTableId() const;
    ZCDB_PORT ZcDbObjectId  viewportTableId() const;
    ZCDB_PORT ZcDbObjectId  regAppTableId() const;
    ZCDB_PORT ZcDbObjectId  dimStyleTableId() const;
    ZCDB_PORT ZcDbObjectId  mLStyleDictionaryId() const;
    ZCDB_PORT ZcDbObjectId  groupDictionaryId() const;
    ZCDB_PORT ZcDbObjectId  layoutDictionaryId() const;
    ZCDB_PORT ZcDbObjectId  plotStyleNameDictionaryId() const;
    ZCDB_PORT ZcDbObjectId  materialDictionaryId() const;
    ZCDB_PORT ZcDbObjectId  visualStyleDictionaryId() const;
    ZCDB_PORT ZcDbObjectId  colorDictionaryId() const;
    ZCDB_PORT ZcDbObjectId  scaleListDictionaryId() const;
    ZCDB_PORT ZcDbObjectId  namedObjectsDictionaryId() const;
    ZCDB_PORT ZcDbObjectId  plotSettingsDictionaryId() const;

    ZcDbObjectId layerZero() const;
    ZcDbObjectId continuousLinetype() const;
    ZcDbObjectId byLayerLinetype() const;
    ZcDbObjectId byBlockLinetype() const;

    ZcDbObjectId globalMaterial() const;
    ZcDbObjectId byLayerMaterial() const;
    ZcDbObjectId byBlockMaterial() const;

    ZcDbObjectId paperSpaceVportId() const;
    ZcDbObjectId currentSpaceId() const;

    Zcad::ErrorStatus purge(ZcDbObjectIdArray& ids);
    Zcad::ErrorStatus purge(ZcDbObjectIdGraph& idGraph);
    Zcad::ErrorStatus countHardReferences(const ZcDbObjectIdArray& ids,
                                          ZSoft::UInt32* pCount);

    Zcad::ErrorStatus getZcDbObjectId(ZcDbObjectId& retId,
                                      bool createIfNotFound,
                                      const ZcDbHandle& objHandle,
                                      ZSoft::UInt32 xRefId = 0);

    const ZTCHAR* classDxfName(const ZcRxClass* pClass);

	enum OpenMode {
		kForReadAndReadShare =    1, 
		kForReadAndWriteNoShare = 2, 
		kForReadAndAllShare =     3, 
		kTryForReadShare =        4 
	};
	Zcad::ErrorStatus readDwgFile(const ZTCHAR* fileName,
		OpenMode openmode,
		bool bAllowCPConversion = false,
		const wchar_t* wszPassword = nullptr);
    Zcad::ErrorStatus readDwgFile(const ZTCHAR* fileName,
                                  const int shmode = _SH_DENYWR,
                                  bool bAllowCPConversion = false,
                                  const wchar_t* wszPassword = nullptr);
    Zcad::ErrorStatus readDwgFile(ZcDwgFileHandle *pDwgFile,
                                  bool bAllowCPConversion = false,
                                  const wchar_t* wszPassword = nullptr);

    ZCDB_PORT void           setFullSaveRequired();
	inline Zcad::ErrorStatus saveAs(const ZTCHAR* fileName,
									const SecurityParams* pSecParams = 0)
	{
		return saveAs(fileName, true, ZcDb::kDHL_CURRENT, pSecParams);
	}

	Zcad::ErrorStatus saveAs(const ZTCHAR* fileName,
							 const bool bBakAndRename,
							 const ZcDb::ZcDbDwgVersion dwgVer = ZcDb::kDHL_CURRENT,
							 const SecurityParams* pSecParams = 0);

    Zcad::ErrorStatus save();
    Zcad::ErrorStatus dxfIn(const ZTCHAR* dxfFilename,
                            const ZTCHAR* logFilename=nullptr);
	Zcad::ErrorStatus dxfOut(const ZTCHAR* fileName,
							int precision = 16,
							ZcDb::ZcDbDwgVersion dwgVer = ZcDb::kDHL_CURRENT,
							bool saveThumbnailImage = false);

    Zcad::ErrorStatus closeInput(bool bCloseFile = false);

    int approxNumObjects() const;
    ZSoft::Int32 numberOfSaves() const;
    const ZTCHAR * originalFileName() const;
    ZcDb::ZcDbDwgVersion lastSavedAsVersion() const;
    ZcDb::ZcDbDwgVersion originalFileVersion() const;
    ZcDb::ZcDbDwgVersion originalFileSavedByVersion() const;
    ZcDb::MaintenanceReleaseVersion lastSavedAsMaintenanceVersion() const;
    ZcDb::MaintenanceReleaseVersion originalFileMaintenanceVersion() const;
    ZcDb::MaintenanceReleaseVersion originalFileSavedByMaintenanceVersion() const;

    ZcDwgFileHandle * inputFiler() const;

    Zcad::ErrorStatus wblock(ZcDbDatabase*& pOutputDb,
                             const ZcDbObjectIdArray& outObjIds,
                             const ZcGePoint3d& basePoint);

    Zcad::ErrorStatus wblock(ZcDbDatabase* pOutputDb,  
                             const ZcDbObjectIdArray& outObjIds,
                             const ZcGePoint3d& basePoint,
                             ZcDb::DuplicateRecordCloning drc);  

    Zcad::ErrorStatus wblock(ZcDbDatabase*& pOutputDb, ZcDbObjectId blockId);
    Zcad::ErrorStatus wblock(ZcDbDatabase*& pOutputDb);

    void              forceWblockDatabaseCopy();

    Zcad::ErrorStatus insert(ZcDbObjectId& blockId, const ZTCHAR* pBlockName,
        ZcDbDatabase* pDb,
        bool preserveSourceDatabase = true);

    Zcad::ErrorStatus insert(const ZcGeMatrix3d& xform, ZcDbDatabase* pDb,
        bool preserveSourceDatabase = true);

    Zcad::ErrorStatus insert(ZcDbObjectId& blockId, 
        const ZTCHAR* pSourceBlockName,
        const ZTCHAR* pDestinationBlockName,
        ZcDbDatabase* pDb,
        bool preserveSourceDatabase = true);

    Zcad::ErrorStatus deepCloneObjects(ZcDbObjectIdArray& objectIds,
        ZcDbObjectId& owner, ZcDbIdMapping& idMap,
        bool deferXlation = false);
       
    Zcad::ErrorStatus wblockCloneObjects(ZcDbObjectIdArray& objectIds,
        ZcDbObjectId& owner, ZcDbIdMapping& idMap,
        ZcDb::DuplicateRecordCloning drc,
        bool deferXlation = false);

    void              abortDeepClone(ZcDbIdMapping& idMap);

    void              addReactor(ZcDbDatabaseReactor* pReactor) const;
    void              removeReactor(ZcDbDatabaseReactor* pReactor) const;

    Zcad::ErrorStatus audit(ZcDbAuditInfo* pInfo);
    Zcad::ErrorStatus auditXData(ZcDbAuditInfo* pInfo);

    ZcDbUndoController* undoController() const;
    void              disableUndoRecording(bool disable);
    bool              undoRecording() const ;

    ZcDbTransactionManager* transactionManager() const;

    ZcFileDependencyManager* fileDependencyManager() const;

    ZSoft::UInt8      maintenanceReleaseVersion() const;

    Zcad::ErrorStatus restoreOriginalXrefSymbols();
    Zcad::ErrorStatus restoreForwardingXrefSymbols();

    ZcDbObjectId      xrefBlockId() const;

    void*             thumbnailBitmap() const;
    Zcad::ErrorStatus setThumbnailBitmap(void* pBmp);
    bool              retainOriginalThumbnailBitmap() const;
    void              setRetainOriginalThumbnailBitmap(bool retain);
    bool              isEMR() const;

    bool                  setSecurityParams(const SecurityParams* pSecParams,
                                            bool bSetDbMod = true);
    const SecurityParams* cloneSecurityParams();
    static void           disposeSecurityParams(const SecurityParams* pSecParams);

    bool dimaso() const;
    Zcad::ErrorStatus setDimaso(bool aso);

    bool dimsho() const;
    Zcad::ErrorStatus setDimsho(bool sho);

    bool plinegen() const;
    Zcad::ErrorStatus setPlinegen(bool gen);

    bool orthomode() const;
    Zcad::ErrorStatus setOrthomode(bool mode);

    bool regenmode() const;
    Zcad::ErrorStatus setRegenmode(bool mode);

    bool fillmode() const;
    Zcad::ErrorStatus setFillmode(bool mode);

    bool qtextmode() const;
    Zcad::ErrorStatus setQtextmode(bool mode);

    bool psltscale() const;
    Zcad::ErrorStatus setPsltscale(bool scale);

    bool limcheck() const;
    Zcad::ErrorStatus setLimcheck(bool check);

    bool blipmode() const;
    Zcad::ErrorStatus setBlipmode(bool mode);

    ZSoft::Int16 saveproxygraphics() const;
    Zcad::ErrorStatus setSaveproxygraphics(ZSoft::Int16 saveimg);

    ZSoft::Int16 delUsedObj() const;
    Zcad::ErrorStatus setDelUsedObj(ZSoft::Int16 deleteObj);

    bool dispSilh() const;
    Zcad::ErrorStatus setDispSilh(bool silh);

    bool plineEllipse() const;
    Zcad::ErrorStatus setPlineEllipse(bool pline);

    bool usrtimer() const;
    Zcad::ErrorStatus setUsrtimer(bool timer);

    bool skpoly() const;
    Zcad::ErrorStatus setSkpoly(bool asPoly);

    bool angdir() const;
    Zcad::ErrorStatus setAngdir(bool dir);

    bool splframe() const;
    Zcad::ErrorStatus setSplframe(bool disp);

    ZSoft::UInt8 xclipFrame() const;
    Zcad::ErrorStatus setXclipFrame(ZSoft::UInt8 disp);

    bool attreq() const;
    Zcad::ErrorStatus setAttreq(bool req);

    bool attdia() const;
    Zcad::ErrorStatus setAttdia(bool dia);

    bool mirrtext() const;
    Zcad::ErrorStatus setMirrtext(bool mirror);

    bool worldview() const;
    Zcad::ErrorStatus setWorldview(bool view);

    bool tilemode() const;
    Zcad::ErrorStatus setTilemode(bool mode);

    bool plimcheck() const;
    Zcad::ErrorStatus setPlimcheck(bool check);

    bool visretain() const;
    Zcad::ErrorStatus setVisretain(bool retain);

    ZSoft::Int16 dragmode() const;
    Zcad::ErrorStatus setDragmode(ZSoft::Int16 mode);

    ZSoft::Int16 treedepth() const;
    Zcad::ErrorStatus setTreedepth(ZSoft::Int16 depth);

    ZSoft::Int16 lunits() const;
    Zcad::ErrorStatus setLunits(ZSoft::Int16 lunits);

    ZSoft::Int16 luprec() const;
    Zcad::ErrorStatus setLuprec(ZSoft::Int16 prec);

    ZSoft::Int16 aunits() const;
    Zcad::ErrorStatus setAunits(ZSoft::Int16 aunits);

    ZSoft::Int16 auprec() const;
    Zcad::ErrorStatus setAuprec(ZSoft::Int16 auprec);

    ZSoft::Int16 attmode() const;
    Zcad::ErrorStatus setAttmode(ZSoft::Int16 mode);

    ZSoft::Int16 coords() const;
    Zcad::ErrorStatus setCoords(ZSoft::Int16 coords);

    ZSoft::Int16 pdmode() const;
    Zcad::ErrorStatus setPdmode(ZSoft::Int16 mode);

    ZSoft::Int16 pickstyle() const;
    Zcad::ErrorStatus setPickstyle(ZSoft::Int16 style);

    ZSoft::Int16 useri1() const;
    Zcad::ErrorStatus setUseri1(ZSoft::Int16 val);

    ZSoft::Int16 useri2() const;
    Zcad::ErrorStatus setUseri2(ZSoft::Int16 val);

    ZSoft::Int16 useri3() const;
    Zcad::ErrorStatus setUseri3(ZSoft::Int16 val);

    ZSoft::Int16 useri4() const;
    Zcad::ErrorStatus setUseri4(ZSoft::Int16 val);

    ZSoft::Int16 useri5() const;
    Zcad::ErrorStatus setUseri5(ZSoft::Int16 val);

    ZSoft::Int16 splinesegs() const;
    Zcad::ErrorStatus setSplinesegs(ZSoft::Int16 segs);

    ZSoft::Int16 surfu() const;
    Zcad::ErrorStatus setSurfu(ZSoft::Int16 u);

    ZSoft::Int16 surfv() const;
    Zcad::ErrorStatus setSurfv(ZSoft::Int16 v);

    ZSoft::Int16 surftype() const;
    Zcad::ErrorStatus setSurftype(ZSoft::Int16 type);

    ZSoft::Int16 surftab1() const;
    Zcad::ErrorStatus setSurftab1(ZSoft::Int16 tab1);

    ZSoft::Int16 surftab2() const;
    Zcad::ErrorStatus setSurftab2(ZSoft::Int16 tab2);

    ZSoft::Int16 splinetype() const;
    Zcad::ErrorStatus setSplinetype(ZSoft::Int16 type);

    ZSoft::Int16 shadedge() const;
    Zcad::ErrorStatus setShadedge(ZSoft::Int16 mode);

    ZSoft::Int16 shadedif() const;
    Zcad::ErrorStatus setShadedif(ZSoft::Int16 dif);

    ZcDb::MeasurementValue measurement() const;
    Zcad::ErrorStatus setMeasurement(ZcDb::MeasurementValue type);

    ZSoft::Int16 unitmode() const;
    Zcad::ErrorStatus setUnitmode(ZSoft::Int16 mode);

    ZSoft::Int16 maxactvp() const;
    Zcad::ErrorStatus setMaxactvp(ZSoft::Int16 max);

    ZSoft::Int16 isolines() const;
    Zcad::ErrorStatus setIsolines(ZSoft::Int16 isolines);

    ZSoft::UInt8 dwfframe() const;
    Zcad::ErrorStatus setDwfframe(ZSoft::UInt8);

    ZSoft::UInt8 dgnframe() const;
    Zcad::ErrorStatus setDgnframe(ZSoft::UInt8);

	ZSoft::Int8 pdfframe() const;
	Zcad::ErrorStatus setPdfframe(ZSoft::Int8 val);

    double ltscale() const;
    Zcad::ErrorStatus setLtscale(double scale);

    double textsize() const;
    Zcad::ErrorStatus setTextsize(double size);

    double tracewid() const;
    Zcad::ErrorStatus setTracewid(double width);

    double sketchinc() const;
    Zcad::ErrorStatus setSketchinc(double inc);

    double filletrad() const;
    Zcad::ErrorStatus setFilletrad(double radius);

    double thickness() const;
    Zcad::ErrorStatus setThickness(double thickness);

    ZcDb::LineWeight  celweight() const;
    Zcad::ErrorStatus setCelweight(ZcDb::LineWeight weight);

    static bool       isValidLineWeight(int weight);
    static ZcDb::LineWeight getNearestLineWeight(int weight);

    ZcDb::EndCaps endCaps() const;
    Zcad::ErrorStatus setEndCaps(ZcDb::EndCaps type);

    ZcDb::JoinStyle joinStyle() const;
    Zcad::ErrorStatus setJoinStyle(ZcDb::JoinStyle style);

    bool lineWeightDisplay() const;
    Zcad::ErrorStatus setLineWeightDisplay(bool display);

    bool xrefEditEnabled() const;
    Zcad::ErrorStatus setXrefEditEnabled(bool enable);

    bool oleStartUp() const;
    Zcad::ErrorStatus setOleStartUp(bool val);

    double angbase() const;
    Zcad::ErrorStatus setAngbase(double angle);

    double pdsize() const;
    Zcad::ErrorStatus setPdsize(double size);

    double plinewid() const;
    Zcad::ErrorStatus setPlinewid(double width);

    double userr1() const;
    Zcad::ErrorStatus setUserr1(double val);

    double userr2() const;
    Zcad::ErrorStatus setUserr2(double val);

    double userr3() const;
    Zcad::ErrorStatus setUserr3(double val);

    double userr4() const;
    Zcad::ErrorStatus setUserr4(double val);

    double userr5() const;
    Zcad::ErrorStatus setUserr5(double val);

    double chamfera() const;
    Zcad::ErrorStatus setChamfera(double val);

    double chamferb() const;
    Zcad::ErrorStatus setChamferb(double val);

    double chamferc() const;
    Zcad::ErrorStatus setChamferc(double val);

    double chamferd() const;
    Zcad::ErrorStatus setChamferd(double val);

    double facetres() const;
    Zcad::ErrorStatus setFacetres(double facetres);
    double get3dDwfPrec() const;
    Zcad::ErrorStatus set3dDwfPrec(double DwfPrec);

    Zcad::ErrorStatus getMenu(ZTCHAR*& pOutput) const;

    bool hpInherit() const;
    Zcad::ErrorStatus setHpInherit(const bool inherit);

    ZcGePoint2d hpOrigin() const;
    Zcad::ErrorStatus setHpOrigin(const ZcGePoint2d& origin);

    const ZcDbDate tdcreate() const;     
    const ZcDbDate tdupdate() const;

    const ZcDbDate tducreate() const;    
    const ZcDbDate tduupdate() const;

    const ZcDbDate tdindwg() const;      
    const ZcDbDate tdusrtimer() const;

    ZcCmColor cecolor() const;
    Zcad::ErrorStatus setCecolor(const ZcCmColor& color);

    ZcDbHandle handseed() const;
    Zcad::ErrorStatus setHandseed(const ZcDbHandle& handle);

    ZcDbObjectId clayer() const;
    Zcad::ErrorStatus setClayer(ZcDbObjectId objId);

    ZcDb::PlotStyleNameType getCePlotStyleNameId(ZcDbObjectId& id) const;
    Zcad::ErrorStatus       setCePlotStyleName(ZcDb::PlotStyleNameType,
                            ZcDbObjectId newId = ZcDbObjectId::kNull);
    
    ZcDbObjectId textstyle() const;
    Zcad::ErrorStatus setTextstyle(ZcDbObjectId objId);

    ZcDbObjectId celtype() const;
    Zcad::ErrorStatus setCeltype(ZcDbObjectId objId);

    ZcDbObjectId cmaterial() const;
    Zcad::ErrorStatus setCmaterial(ZcDbObjectId objId);

    ZcDbObjectId dimstyle() const;
    Zcad::ErrorStatus setDimstyle(ZcDbObjectId styleId);

    Zcad::ErrorStatus getDimstyleData(ZcDbDimStyleTableRecord*& pRec) const;
    Zcad::ErrorStatus getDimstyleChildData(const ZcRxClass *pDimClass,
                                           ZcDbDimStyleTableRecord*& pRec,
                                           ZcDbObjectId &style) const;
    ZcDbObjectId getDimstyleChildId(const ZcRxClass *pDimClass,
                                    ZcDbObjectId &parentStyle) const;

    ZcDbObjectId getDimstyleParentId(ZcDbObjectId &childStyle) const;
                                           
    Zcad::ErrorStatus setDimstyleData(ZcDbDimStyleTableRecord* pRec);
    Zcad::ErrorStatus setDimstyleData(ZcDbObjectId id);

    ZcDbObjectId cmlstyleID() const;
    Zcad::ErrorStatus setCmlstyleID(ZcDbObjectId objId);

    ZSoft::Int16 cmljust() const;
    Zcad::ErrorStatus setCmljust(ZSoft::Int16 just);

    double cmlscale() const;
    Zcad::ErrorStatus setCmlscale(double scale);

    double celtscale() const;
    Zcad::ErrorStatus setCeltscale(double scale);

    ZcGePoint3d pinsbase() const;
    Zcad::ErrorStatus setPinsbase(const ZcGePoint3d& base);

    ZcGePoint3d pextmin() const;

    ZcGePoint3d pextmax() const;

    Zcad::ErrorStatus setPextmin(const ZcGePoint3d& min);
    Zcad::ErrorStatus setPextmax(const ZcGePoint3d& max);

    ZcGePoint2d plimmin() const;
    Zcad::ErrorStatus setPlimmin(const ZcGePoint2d& min);

    ZcGePoint2d plimmax() const;
    Zcad::ErrorStatus setPlimmax(const ZcGePoint2d& max);

    double pelevation() const;
    Zcad::ErrorStatus setPelevation(double elev);

    ZcGePoint3d pucsorg() const;

    ZcGeVector3d pucsxdir() const;

    ZcGeVector3d pucsydir() const;

    ZcDbObjectId pucsname() const;

    ZcDbObjectId pucsBase() const;
    Zcad::ErrorStatus setPucsBase(const ZcDbObjectId &ucsid);

    ZcGePoint3d worldPucsBaseOrigin(ZcDb::OrthographicView orthoView) const;
    Zcad::ErrorStatus setWorldPucsBaseOrigin(const ZcGePoint3d& origin,
                                             ZcDb::OrthographicView orthoView);

    bool isPucsOrthographic(ZcDb::OrthographicView& orthoView) const;

    double cameraHeight() const;
    Zcad::ErrorStatus setCameraHeight(const double cameraHeight);

    double lensLength() const;
    Zcad::ErrorStatus setLensLength(const double lensLength);

    bool cameraDisplay() const;
    Zcad::ErrorStatus setCameraDisplay(const bool cameraDisplay);

    double stepsPerSec() const;
    Zcad::ErrorStatus setStepsPerSec(double stepsPerSec);

    double stepSize() const;
    Zcad::ErrorStatus setStepSize(double stepSize);

    bool realWorldScale() const;
    Zcad::ErrorStatus setRealWorldScale(const bool realWorldScale);
    ZcGePoint3d insbase() const;
    Zcad::ErrorStatus setInsbase(const ZcGePoint3d& base);

    ZcGePoint3d extmin() const;

    ZcGePoint3d extmax() const;

    Zcad::ErrorStatus updateExt(bool doBestFit = FALSE);

    Zcad::ErrorStatus setExtmin(const ZcGePoint3d& min);
    Zcad::ErrorStatus setExtmax(const ZcGePoint3d& max);

    ZcGePoint2d limmin() const;
    Zcad::ErrorStatus setLimmin(const ZcGePoint2d& min);

    ZcGePoint2d limmax() const;
    Zcad::ErrorStatus setLimmax(const ZcGePoint2d& max);

    double elevation() const;
    Zcad::ErrorStatus setElevation(double elev);

    ZcGePoint3d ucsorg() const;

    ZcGeVector3d ucsxdir() const;

    ZcGeVector3d ucsydir() const;

    ZcDbObjectId ucsname() const;

    ZcDbObjectId ucsBase() const;
    Zcad::ErrorStatus setUcsBase(ZcDbObjectId ucsid);

    ZcGePoint3d worldUcsBaseOrigin(ZcDb::OrthographicView orthoView) const;
    Zcad::ErrorStatus setWorldUcsBaseOrigin(const ZcGePoint3d& origin,
                                            ZcDb::OrthographicView orthoView);

    bool isUcsOrthographic(ZcDb::OrthographicView& orthoView) const;

    #undef ZDBDIMVAR_H                   
    #include "zdbdimvar.h"

    Zcad::ErrorStatus getDimpost(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus getDimapost(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus getDimblk(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus getDimblk1(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus getDimblk2(ZTCHAR*& pOutput) const;

    int dimfit() const;
    int dimunit() const;

    Zcad::ErrorStatus setDimfit(int fit);
    Zcad::ErrorStatus setDimunit(int unit);

    Zcad::ErrorStatus getDimRecentStyleList(ZcDbObjectIdArray& objIds) const;

    Zcad::ErrorStatus loadLineTypeFile(const ZTCHAR *ltn, const ZTCHAR *filename);

    Zcad::ErrorStatus getProjectName(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus setProjectName(const ZTCHAR*);
    Zcad::ErrorStatus getHyperlinkBase(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus setHyperlinkBase(const ZTCHAR*);
    Zcad::ErrorStatus getStyleSheet(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus setStyleSheet(const ZTCHAR*);
    Zcad::ErrorStatus getFilename(const ZTCHAR* & pOutput) const;

    bool              isPartiallyOpened() const;
    Zcad::ErrorStatus applyPartialOpenFilters(
        const ZcDbSpatialFilter* pSpatialFilter,
        const ZcDbLayerFilter* pLayerFilter);

    void              disablePartialOpen();

    Zcad::ErrorStatus getFingerprintGuid(ZTCHAR*& guidString) const;
    Zcad::ErrorStatus setFingerprintGuid(const ZTCHAR *pNewGuid);

    Zcad::ErrorStatus getVersionGuid(ZTCHAR*& guidString) const;
    Zcad::ErrorStatus setVersionGuid(const ZTCHAR *pNewGuid);

    int tstackalign() const;
    Zcad::ErrorStatus setTStackAlign(int val);

    int tstacksize() const;
    Zcad::ErrorStatus setTStackSize(int val);

    ZcDb::UnitsValue insunits() const;
    Zcad::ErrorStatus setInsunits(const ZcDb::UnitsValue units);

    void                setGsModel(ZcGsModel*);
    ZcGsModel*          gsModel() const;

    void                setGsHighlightModel(ZcGsModel*);
    ZcGsModel*          gsHighlightModel() const;
    bool           plotStyleMode() const;

    double viewportScaleDefault() const;
    Zcad::ErrorStatus setViewportScaleDefault(double newDefaultVPScale);

    bool           dwgFileWasSavedByZwSoftSoftware() const;

    ZcDbLayerStateManager *getLayerStateManager() const;
    ZcDbObjectContextManager* objectContextManager() const;
    ZSoft::UInt8        sortEnts() const;
    Zcad::ErrorStatus   setSortEnts(ZSoft::UInt8 sortEnts);

    ZSoft::UInt8        drawOrderCtl() const;
    Zcad::ErrorStatus   setDrawOrderCtl(ZSoft::UInt8 val);
    
    ZSoft::UInt8        dimAssoc() const;
    Zcad::ErrorStatus setDimAssoc(ZSoft::UInt8 val);

    ZSoft::UInt8 hideText() const;
    Zcad::ErrorStatus setHideText(ZSoft::UInt8 val);

    ZSoft::UInt8  haloGap() const;
    Zcad::ErrorStatus setHaloGap(ZSoft::UInt8 val);

    ZSoft::UInt16 obscuredColor() const;
    Zcad::ErrorStatus setObscuredColor(ZSoft::UInt16 val);

    ZSoft::UInt8 obscuredLineType() const;
    Zcad::ErrorStatus setObscuredLineType(ZSoft::UInt8 val);

    ZSoft::UInt8  intersectDisplay() const;
    Zcad::ErrorStatus setIntersectDisplay(ZSoft::UInt8 val);

    ZSoft::UInt16 intersectColor() const;
    Zcad::ErrorStatus setIntersectColor(ZSoft::UInt16 val);

    Zcad::ErrorStatus getTableStyleDictionary(ZcDbDictionary*& pDict,
                                              ZcDb::OpenMode mode);
    ZcDbObjectId  tableStyleDictionaryId() const;

    ZcDbObjectId tablestyle() const;
    Zcad::ErrorStatus setTablestyle(ZcDbObjectId objId);
    Zcad::ErrorStatus getMLeaderStyleDictionary(ZcDbDictionary*& pDict,
                                              ZcDb::OpenMode mode);
    ZcDbObjectId  mleaderStyleDictionaryId() const;
    ZcDbObjectId mleaderstyle() const;
    Zcad::ErrorStatus setMLeaderstyle(ZcDbObjectId objId);

    Zcad::ErrorStatus evaluateFields(int nContext,
                                     const ZTCHAR* pszPropName= nullptr,
                                     ZcDbDatabase* pDb      = nullptr,
                                     int* pNumFound         = nullptr,
                                     int* pNumEvaluated     = nullptr);
    Zcad::ErrorStatus getViewportArray(ZcDbObjectIdArray& vportIds,
                                       bool bGetPaperspaceVports = true) const;
    Zcad::ErrorStatus getVisualStyleList(ZcArray<const ZTCHAR*> & vstyleList);

    ZSoft::UInt8  solidHist() const;
    Zcad::ErrorStatus setSolidHist(ZSoft::UInt8 val);

    ZSoft::UInt8  showHist() const;
    Zcad::ErrorStatus setShowHist(ZSoft::UInt8 val);

    double psolWidth() const;
    Zcad::ErrorStatus setPsolWidth(double width);
    double psolHeight() const;
    Zcad::ErrorStatus setPsolHeight(double height);

    ZSoft::UInt16 loftParam() const;
    Zcad::ErrorStatus setLoftParam(ZSoft::UInt16 flags);
    ZSoft::UInt8 loftNormals() const;
    Zcad::ErrorStatus setLoftNormals(ZSoft::UInt8 value);
    double loftAng1() const;
    Zcad::ErrorStatus setLoftAng1(double ang1);
    double loftAng2() const;
    Zcad::ErrorStatus setLoftAng2(double ang2);
    double loftMag1() const;
    Zcad::ErrorStatus setLoftMag1(double mag1);
    double loftMag2() const;
    Zcad::ErrorStatus setLoftMag2(double mag2);
    double latitude() const;
    Zcad::ErrorStatus setLatitude(double lat);
    double longitude() const;
    Zcad::ErrorStatus setLongitude(double lng);
    double northDirection() const;
    Zcad::ErrorStatus setNorthDirection(double northdir);
    ZcDb::TimeZone timeZone() const;
    Zcad::ErrorStatus setTimeZone(ZcDb::TimeZone tz);

    Zcad::ErrorStatus getTimeZoneInfo(ZcDb::TimeZone tz, double& offset, ZcString& desc) const;
    Zcad::ErrorStatus setTimeZoneAsUtcOffset(double offset);

    ZSoft::UInt8 lightGlyphDisplay() const;
    Zcad::ErrorStatus setLightGlyphDisplay(ZSoft::UInt8 val);
    ZSoft::UInt8 tileModeLightSynch() const;
    Zcad::ErrorStatus setTileModeLightSynch(ZSoft::UInt8 val);

    ZcCmColor interfereColor() const;
    Zcad::ErrorStatus setInterfereColor(const ZcCmColor& color);

    ZcDbObjectId interfereObjVisStyle() const;
    Zcad::ErrorStatus setInterfereObjVisStyle(ZcDbObjectId id);

    ZcDbObjectId interfereVpVisStyle() const;
    Zcad::ErrorStatus setInterfereVpVisStyle(ZcDbObjectId id);

    ZcDbObjectId dragVisStyle() const;
    Zcad::ErrorStatus setDragVisStyle(ZcDbObjectId id);

    ZSoft::UInt8 cshadow() const;
    Zcad::ErrorStatus setCshadow(ZSoft::UInt8 val);

    double shadowPlaneLocation() const;
    Zcad::ErrorStatus setShadowPlaneLocation(double val);

    ZcDbAnnotationScale* cannoscale() const;
    Zcad::ErrorStatus setCannoscale(ZcDbAnnotationScale*);

    bool annoAllVisible() const;
    Zcad::ErrorStatus setAnnoAllVisible(bool allvis);

    bool annotativeDwg() const;
    Zcad::ErrorStatus setAnnotativeDwg(bool ao);

    bool msltscale() const;
    Zcad::ErrorStatus setMsltscale(bool val);

    ZSoft::UInt8 lightingUnits() const;
    Zcad::ErrorStatus setLightingUnits(ZSoft::UInt8 val);

    bool lightsInBlocks() const;
    Zcad::ErrorStatus setLightsInBlocks(bool val);

    ZSoft::Int16 dxeVal() const;
    Zcad::ErrorStatus setDxeVal(ZSoft::Int16 val);

private:
    friend class ZcDbSystemInternals;
    ZcDbImpDatabase* mpImpDb;
};

class ZcDbObjectIterator: public ZcRxObject, public ZcHeapOperators
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbObjectIterator);
    virtual ~ZcDbObjectIterator();

    bool           done() const;
    void           step(bool backwards = false, bool skipDeleted = true);
    void           setPosition(ZcDbEntity*  pEnt);
    void           setPosition(ZcDbObjectId  pObj);
    void           start(bool atEnd = false);
    ZcDbEntity*    entity();
    ZcDbObjectId   objectId();

private:
    friend class ZcDbSystemInternals;
    ZcDbObjectIterator();
    ZcDbSpaceIterator* mpImpIterator;
};

class ZSOFT_NO_VTABLE ZcDbObject: public ZcGiDrawable, public ZcHeapOperators
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbObject);

    virtual ~ZcDbObject();

    ZcDbObjectId      objectId() const;
    ZcDbObjectId      ownerId() const;
    virtual Zcad::ErrorStatus setOwnerId(ZcDbObjectId objId);
    void              getZcDbHandle(ZcDbHandle& handle) const;
    ZcDbDatabase*     database() const;
    Zcad::ErrorStatus createExtensionDictionary();
    ZcDbObjectId      extensionDictionary() const;
    Zcad::ErrorStatus releaseExtensionDictionary();

    Zcad::ErrorStatus upgradeOpen();
    Zcad::ErrorStatus upgradeFromNotify(ZSoft::Boolean& wasWritable);
    Zcad::ErrorStatus downgradeOpen();
    Zcad::ErrorStatus downgradeToNotify(ZSoft::Boolean wasWritable);
    virtual Zcad::ErrorStatus subOpen(ZcDb::OpenMode mode);

    Zcad::ErrorStatus cancel();
    virtual Zcad::ErrorStatus subCancel();

    Zcad::ErrorStatus close();
    Zcad::ErrorStatus closeAndPage(ZSoft::Boolean onlyWhenClean = true);
    virtual Zcad::ErrorStatus subClose();

    Zcad::ErrorStatus erase(ZSoft::Boolean erasing = true);
    virtual Zcad::ErrorStatus subErase(ZSoft::Boolean erasing);

    Zcad::ErrorStatus handOverTo(ZcDbObject* newObject,
                                 ZSoft::Boolean keepXData = true,
                                 ZSoft::Boolean keepExtDict = true);
    virtual Zcad::ErrorStatus subHandOverTo(ZcDbObject* newObject);

    Zcad::ErrorStatus swapIdWith(ZcDbObjectId otherId, 
                                 ZSoft::Boolean swapXdata = false,
                                 ZSoft::Boolean swapExtDict = false);
    virtual Zcad::ErrorStatus subSwapIdWith(ZcDbObjectId otherId,
                                 ZSoft::Boolean swapXdata = false,
                                 ZSoft::Boolean swapExtDict = false);

    virtual Zcad::ErrorStatus swapReferences (const ZcDbIdMapping& idMap);

    virtual Zcad::ErrorStatus audit(ZcDbAuditInfo* pAuditInfo);

    Zcad::ErrorStatus         dwgIn       (ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler* pFiler);
    Zcad::ErrorStatus         dwgOut      (ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;

    Zcad::ErrorStatus         dxfIn       (ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler* pFiler);
    Zcad::ErrorStatus         dxfOut      (ZcDbDxfFiler* pFiler,
                                           ZSoft::Boolean allXdFlag,
                                           ZSoft::uchar* regAppTable) const;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;

    virtual ZcDb::DuplicateRecordCloning mergeStyle () const;

    virtual resbuf*           xData   (const ZTCHAR* regappName = nullptr) const;
    virtual Zcad::ErrorStatus setXData(const resbuf* xdata);
            Zcad::ErrorStatus xDataTransformBy(const ZcGeMatrix3d& xform);

    Zcad::ErrorStatus         setBinaryData(const ZTCHAR * key,
                                            ZSoft::Int32         size,
                                            const char * data);
    Zcad::ErrorStatus         getBinaryData(const ZTCHAR * key,
                                            ZSoft::Int32 &       size,
                                            char *&      data) const;

    ZSoft::Boolean isEraseStatusToggled() const;
    ZSoft::Boolean isErased() const;
    ZSoft::Boolean isReadEnabled() const;
    ZSoft::Boolean isWriteEnabled() const;
    ZSoft::Boolean isNotifyEnabled() const;
    ZSoft::Boolean isModified() const;
    ZSoft::Boolean isModifiedXData() const;
    ZSoft::Boolean isModifiedGraphics() const;
    ZSoft::Boolean isNewObject() const;
    ZSoft::Boolean isNotifying() const;
    ZSoft::Boolean isUndoing() const;
    ZSoft::Boolean isCancelling() const;
    ZSoft::Boolean isReallyClosing() const;
    ZSoft::Boolean isTransactionResident() const;

    ZSoft::Boolean isAProxy() const;

    void assertReadEnabled() const;
    void assertWriteEnabled(ZSoft::Boolean autoUndo = true,
                            ZSoft::Boolean recordModified = true);
    void assertNotifyEnabled() const;

    void                      disableUndoRecording(ZSoft::Boolean disable);
    ZcDbDwgFiler*             undoFiler();
    virtual Zcad::ErrorStatus applyPartialUndo(ZcDbDwgFiler* undoFiler,
                                               ZcRxClass*    classObj);

    void                      addReactor(ZcDbObjectReactor* newObj) const;
    void                      removeReactor(ZcDbObjectReactor* newObj) const;
    virtual void              addPersistentReactor(ZcDbObjectId objId);
    virtual Zcad::ErrorStatus removePersistentReactor(ZcDbObjectId objId);
    bool                      hasPersistentReactor(ZcDbObjectId objId) const;
    ZcDbVoidPtrArray*         reactors();
    const ZcDbVoidPtrArray*   reactors() const;

    virtual void              recvPropagateModify(const ZcDbObject* subObj);
    virtual void              xmitPropagateModify() const;

    virtual Zcad::ErrorStatus deepClone(ZcDbObject* pOwnerObject,
                                        ZcDbObject*& pClonedObject,
                                        ZcDbIdMapping& idMap,
                                        ZSoft::Boolean isPrimary = true) const;
 
    virtual Zcad::ErrorStatus wblockClone(ZcRxObject* pOwnerObject,
                                          ZcDbObject*& pClonedObject,
                                          ZcDbIdMapping& idMap,
                                          ZSoft::Boolean isPrimary = true) const;

    void              setZcDbObjectIdsInFlux();
    ZSoft::Boolean    isZcDbObjectIdsInFlux() const;

    virtual void cancelled       (const ZcDbObject* dbObj);
    virtual void copied          (const ZcDbObject* dbObj,
                                  const ZcDbObject* newObj);
    virtual void erased          (const ZcDbObject* dbObj,
                                  ZSoft::Boolean pErasing = true);
    virtual void goodbye         (const ZcDbObject* dbObj);
    virtual void openedForModify (const ZcDbObject* dbObj);
    virtual void modified        (const ZcDbObject* dbObj);
    virtual void subObjModified  (const ZcDbObject* dbObj,
                                  const ZcDbObject* subObj);
    virtual void modifyUndone    (const ZcDbObject* dbObj);
    virtual void modifiedXData   (const ZcDbObject* dbObj);
    virtual void unappended      (const ZcDbObject* dbObj);
    virtual void reappended      (const ZcDbObject* dbObj);
    virtual void objectClosed    (const ZcDbObjectId objId);
    virtual void modifiedGraphics(const ZcDbEntity* dbEnt);

    virtual ZcRxObject*        clone() const;
    virtual Zcad::ErrorStatus  copyFrom(const ZcRxObject* pSrc);

    bool       hasSaveVersionOverride();
    void       setHasSaveVersionOverride(bool bSetIt);

    virtual Zcad::ErrorStatus getObjectSaveVersion(const ZcDbDwgFiler* pFiler, 
                                 ZcDb::ZcDbDwgVersion& ver,
                                 ZcDb::MaintenanceReleaseVersion& maintVer);
    virtual Zcad::ErrorStatus getObjectSaveVersion(const ZcDbDxfFiler* pFiler, 
                                 ZcDb::ZcDbDwgVersion& ver,
                                 ZcDb::MaintenanceReleaseVersion& maintVer);
            Zcad::ErrorStatus getObjectBirthVersion(
                                 ZcDb::ZcDbDwgVersion& ver,
                                 ZcDb::MaintenanceReleaseVersion& maintVer);

    virtual Zcad::ErrorStatus   decomposeForSave(
                                ZcDb::ZcDbDwgVersion ver,
                                ZcDbObject*& replaceObj,
                                ZcDbObjectId& replaceId,
                                ZSoft::Boolean& exchangeXData);

    virtual ZcGiDrawable*       drawable();

    virtual ZSoft::UInt32       setAttributes(ZcGiDrawableTraits* pTraits);
    virtual ZSoft::Boolean      worldDraw(ZcGiWorldDraw* pWd);
    virtual void                viewportDraw(ZcGiViewportDraw* pVd);
    virtual ZSoft::Boolean      isPersistent() const;
    virtual ZcDbObjectId        id() const;
    virtual void                setGsNode(ZcGsNode* pNode);
    virtual ZcGsNode*           gsNode() const;

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

    bool              hasFields(void) const;
    Zcad::ErrorStatus getField(const ZTCHAR* pszPropName,
                               ZcDbObjectId& fieldId) const;
    Zcad::ErrorStatus getField(const ZTCHAR* pszPropName, ZcDbField*& pField,
                               ZcDb::OpenMode mode) const;

    virtual Zcad::ErrorStatus setField(const ZTCHAR* pszPropName, ZcDbField* pField,
                               ZcDbObjectId& fieldId);

    virtual Zcad::ErrorStatus removeField(ZcDbObjectId fieldId);
    virtual Zcad::ErrorStatus removeField(const ZTCHAR* pszPropName, ZcDbObjectId& returnId);
    virtual Zcad::ErrorStatus removeField(const ZTCHAR* pszPropName);
    ZcDbObjectId      getFieldDictionary(void) const;
    Zcad::ErrorStatus getFieldDictionary(ZcDbDictionary*& pFieldDict, 
                             ZcDb::OpenMode mode) const;
protected:
    ZcDbObject();
private:
    friend class ZcDbSystemInternals;
    ZcDbImpObject*            mpImpObject;

	ZcDbObject (const ZcDbObject & );
	ZcDbObject & operator = (const ZcDbObject & );
};

class ZSOFT_NO_VTABLE ZcDbXObject: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbXObject);

    virtual Zcad::ErrorStatus audit(ZcDbAuditInfo* pAuditInfo);

    Zcad::ErrorStatus dwgIn(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    Zcad::ErrorStatus dwgOut(ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;

    Zcad::ErrorStatus dxfIn(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
    Zcad::ErrorStatus dxfOut(ZcDbDxfFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;

    protected:
    ZcDbXObject();
};

class ZcCmComplexColor: public  ZcDbXObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcCmComplexColor); 

    virtual ZcCmComplexColor* incReference();
    virtual void              decReference();

    virtual Zcad::ErrorStatus getDescription(ZTCHAR*& desc) const;
    virtual Zcad::ErrorStatus getExplanation(ZTCHAR*& expl) const;

    virtual ZcCmEntityColor::ColorMethod  colorMethod() const;
    virtual Zcad::ErrorStatus setColorMethod(
        ZcCmEntityColor::ColorMethod eColorMethod);

    virtual bool              isByColor() const;
    virtual bool              isByLayer() const;
    virtual bool              isByBlock() const;
    virtual bool              isByACI()   const;
    virtual bool              isByPen ()  const;
    virtual bool              isForeground()   const;

    virtual ZSoft::UInt32     color() const;
    virtual Zcad::ErrorStatus setColor(ZSoft::UInt32 color);

    virtual Zcad::ErrorStatus setRGB  (ZSoft::UInt8 red, 
                                       ZSoft::UInt8 green, 
                                       ZSoft::UInt8 blue);
    virtual Zcad::ErrorStatus setRed  (ZSoft::UInt8 red);
    virtual Zcad::ErrorStatus setGreen(ZSoft::UInt8 green);
    virtual Zcad::ErrorStatus setBlue (ZSoft::UInt8 blue);
    virtual ZSoft::UInt8      red  () const;
    virtual ZSoft::UInt8      green() const;
    virtual ZSoft::UInt8      blue () const;

    virtual ZSoft::UInt16     colorIndex() const;
    virtual Zcad::ErrorStatus setColorIndex(ZSoft::UInt16 colorIndex);
    virtual ZSoft::UInt16     penIndex() const;   
    virtual Zcad::ErrorStatus setPenIndex (ZSoft::UInt16 penIndex);

    virtual Zcad::ErrorStatus copyFrom(const ZcRxObject*);

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
    virtual Zcad::ErrorStatus audit(ZcDbAuditInfo* pAuditInfo);

private:
    ZSoft::UInt16 refCount;
    ZcCmEntityColor mColor;
};

class ZcCmColor : public ZcCmColorBase
{
public:
    ZcCmColor();
    ZcCmColor(const ZcCmColor&);
    ZcCmColor(const ZcCmColorBase&);
    ZcCmColor& operator=(const ZcCmColor& inputColor);
    ZcCmColor& operator=(const ZcCmColorBase& inputColor);
    virtual ~ZcCmColor();

    bool operator ==(const ZcCmColor& color) const;
    bool operator !=(const ZcCmColor& color) const;
    bool operator ==(const ZcCmColorBase& color) const;
    bool operator !=(const ZcCmColorBase& color) const;
    
    Zcad::ErrorStatus getDescription(ZTCHAR*& desc) const;
    Zcad::ErrorStatus getExplanation(ZTCHAR*& expl) const;

    virtual ZcCmEntityColor::ColorMethod  colorMethod() const;
    virtual Zcad::ErrorStatus setColorMethod(ZcCmEntityColor::ColorMethod eColorMethod);

    virtual bool    isByColor() const;
    virtual bool    isByLayer() const;
    virtual bool    isByBlock() const;
    virtual bool    isByACI()   const;
    virtual bool    isByPen () const;
    virtual bool    isForeground()   const;

    bool            isNone() const;

    virtual ZSoft::UInt32     color() const;
    virtual Zcad::ErrorStatus setColor(ZSoft::UInt32 color);

    virtual Zcad::ErrorStatus setRGB  (ZSoft::UInt8 red, 
                               ZSoft::UInt8 green, 
                               ZSoft::UInt8 blue);
    virtual Zcad::ErrorStatus setRed  (ZSoft::UInt8 red);
    virtual Zcad::ErrorStatus setGreen(ZSoft::UInt8 green);
    virtual Zcad::ErrorStatus setBlue (ZSoft::UInt8 blue);
    virtual ZSoft::UInt8      red  () const;
    virtual ZSoft::UInt8      green() const;
    virtual ZSoft::UInt8      blue () const;

    virtual ZSoft::UInt16     colorIndex() const;
    virtual Zcad::ErrorStatus setColorIndex(ZSoft::UInt16 colorIndex);
    virtual ZSoft::UInt16     penIndex() const;   
    virtual Zcad::ErrorStatus setPenIndex (ZSoft::UInt16 penIndex);

    virtual Zcad::ErrorStatus setNames(const ZTCHAR *colorName,
                                       const ZTCHAR *bookName = NULL);
    virtual const ZTCHAR *      colorName(void) const;
    virtual const ZTCHAR *      bookName(void) const;
    virtual const ZTCHAR *      colorNameForDisplay(void);
    virtual bool              hasColorName(void) const;
    virtual bool              hasBookName(void) const;

    ZcCmEntityColor           entityColor(void) const;
    int                       dictionaryKeyLength(void) const;
	void					  getDictionaryKey(ZTCHAR *pKey, size_t nLen) const;
	void					  getDictionaryKey(ZTCHAR *pKey) const;//Deprecated: will be removed in future.
    Zcad::ErrorStatus         setNamesFromDictionaryKey(const ZTCHAR *);

    Zcad::ErrorStatus dwgIn(ZcDbDwgFiler* pInputFiler);
    Zcad::ErrorStatus dwgOut(ZcDbDwgFiler *pOutputFiler) const;

    Zcad::ErrorStatus dxfIn(ZcDbDxfFiler* pFiler, int groupCodeOffset = 0);
    Zcad::ErrorStatus dxfOut(ZcDbDxfFiler* pFiler, int groupCodeOffset = 0) const;

    Zcad::ErrorStatus audit(ZcDbAuditInfo* pAuditInfo);

    Zcad::ErrorStatus serializeOut(void *pBuff, int *pBuflen,
                    ZcDb::ZcDbDwgVersion ver = ZcDb::kDHL_CURRENT) const;

    Zcad::ErrorStatus serializeIn(const void *pBuff, int *pBuflen);

    static const ZSoft::UInt16 MaxColorIndex; 

    ZcCmComplexColor* complexColor() const;
    void setComplexColor(ZcCmComplexColor* pComplex);

    Zcad::ErrorStatus dwgInAsTrueColor(ZcDbDwgFiler* pInputFiler); 
    Zcad::ErrorStatus dwgOutAsTrueColor(ZcDbDwgFiler *pOutputFiler) const; 

private:

    enum NameFlags {    kNoNames            = 0x00,
                        kHasColorName       = 0x01,
                        kHasBookName        = 0x02
                    };

    static const ZSoft::UInt16 ComplexColorFlag; 
    bool isComplex() const;

    ZcCmEntityColor::RGBM   mRGBM;
    ZTCHAR *                  mColorName;
    ZTCHAR *                  mBookName;
    ZSoft::UInt8            mNameFlags;

};

Zcad::ErrorStatus zccmGetColorFromACIName(ZcCmColor& clr, const ZTCHAR *pInput);
Zcad::ErrorStatus zccmGetColorFromRGBName(ZcCmColor& clr, const ZTCHAR *pInput);
Zcad::ErrorStatus zccmGetColorFromColorBookName(ZcCmColor& clr, const ZTCHAR *pBookName, const ZTCHAR *pColorName);

void zccmGetLocalizedColorNames( const ZTCHAR* colors[9] );

class ZcDbColor: public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbColor);

    ZcDbColor();
    virtual ~ZcDbColor();

    void getColor(ZcCmColor& color) const;
    void setColor(const ZcCmColor& color);
    const ZcCmEntityColor& entityColor(void) const;

    virtual Zcad::ErrorStatus   decomposeForSave(
                                ZcDb::ZcDbDwgVersion ver,
                                ZcDbObject*& replaceObj,
                                ZcDbObjectId& replaceId,
                                ZSoft::Boolean& exchangeXData);

    virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const;

    virtual Zcad::ErrorStatus wblockClone(ZcRxObject* pOwnerObject,
                                          ZcDbObject*& pClonedObject,
                                          ZcDbIdMapping& idMap,
                                          ZSoft::Boolean isPrimary
                                          = true) const;
    
private:

    ZcCmColor           m_color;    
    ZcCmEntityColor     m_ecol;     

};

class ZSOFT_NO_VTABLE ZcDbEntity: public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbEntity);

    virtual ~ZcDbEntity();

    ZcDbObjectId                blockId() const;

    ZcCmColor                   color() const;
    virtual Zcad::ErrorStatus   setColor(const ZcCmColor& color,
                                  ZSoft::Boolean doSubents = true);
    ZSoft::UInt16               colorIndex() const;
    virtual Zcad::ErrorStatus   setColorIndex(ZSoft::UInt16 color,
                                  ZSoft::Boolean doSubents = true);
    ZcCmEntityColor             entityColor() const;

    ZcCmTransparency            transparency() const;
    virtual Zcad::ErrorStatus   setTransparency(const ZcCmTransparency& trans,
                                  ZSoft::Boolean doSubents = true);

    ZTCHAR*                       plotStyleName() const;
    ZcDb::PlotStyleNameType     getPlotStyleNameId(ZcDbObjectId& id) const;
    virtual Zcad::ErrorStatus   setPlotStyleName(const ZTCHAR* newName,
                                  ZSoft::Boolean doSubents = true);
    virtual Zcad::ErrorStatus   setPlotStyleName(ZcDb::PlotStyleNameType,
                                ZcDbObjectId newId = ZcDbObjectId::kNull,
                                ZSoft::Boolean doSubents = true);
    
    ZTCHAR*                       layer() const;
    ZcDbObjectId                layerId() const;
    virtual Zcad::ErrorStatus   setLayer(const ZTCHAR* newVal,
                                  ZSoft::Boolean doSubents = true,
                                  bool allowHiddenLayer = false);
    virtual Zcad::ErrorStatus   setLayer(ZcDbObjectId newVal,
                                  ZSoft::Boolean doSubents = true,
                                  bool allowHiddenLayer = false);

    ZTCHAR*                       linetype() const;
    ZcDbObjectId                linetypeId() const;
    virtual Zcad::ErrorStatus   setLinetype(const ZTCHAR* newVal,
                                  ZSoft::Boolean doSubents = true);
    virtual Zcad::ErrorStatus   setLinetype(ZcDbObjectId newVal,
                                  ZSoft::Boolean doSubents = true);

    ZTCHAR*                        material() const;
    ZcDbObjectId                materialId() const;
    virtual Zcad::ErrorStatus   setMaterial(const ZTCHAR* newVal, ZSoft::Boolean doSubents = true);
    virtual Zcad::ErrorStatus   setMaterial(ZcDbObjectId newVal, ZSoft::Boolean doSubents = true);

	enum VisualStyleType 
	{
		kFullVisualStyle,
		kFaceVisualStyle,
		kEdgeVisualStyle
	};
	virtual Zcad::ErrorStatus   setVisualStyle  (ZcDbObjectId visualStyleId, VisualStyleType vsType = kFullVisualStyle,  ZSoft::Boolean doSubents = true);
	ZcDbObjectId                visualStyleId   (VisualStyleType vsType = kFullVisualStyle) const;

    virtual Zcad::ErrorStatus getMaterialMapper(ZcGiMapper& mapper) const;
    virtual Zcad::ErrorStatus setMaterialMapper(const ZcGiMapper& mapper, ZSoft::Boolean doSubents = true);

    double                      linetypeScale() const;
    virtual Zcad::ErrorStatus   setLinetypeScale(double newval,
                                  ZSoft::Boolean doSubents = true);

    ZcDb::Visibility            visibility() const;
    virtual Zcad::ErrorStatus   setVisibility(ZcDb::Visibility newVal,
                                  ZSoft::Boolean doSubents = true);

    ZcDb::LineWeight            lineWeight() const;
    virtual Zcad::ErrorStatus   setLineWeight(ZcDb::LineWeight newVal,
                                  ZSoft::Boolean doSubents = true);

    virtual ZcDb::CollisionType collisionType() const;

    virtual bool                castShadows() const;
    virtual void                setCastShadows(bool newVal);
    virtual bool                receiveShadows() const;
    virtual void                setReceiveShadows(bool newVal);

    Zcad::ErrorStatus           setPropertiesFrom(const ZcDbEntity* pEntity,
                                  ZSoft::Boolean doSubents = true);

    virtual ZSoft::Boolean      isPlanar() const { return false; }
    virtual Zcad::ErrorStatus   getPlane(ZcGePlane&, ZcDb::Planarity&) const
                                    { return Zcad::eNotApplicable; }

    virtual void                getEcs(ZcGeMatrix3d& retVal) const;

    virtual Zcad::ErrorStatus   getGeomExtents(ZcDbExtents& extents) const;
    virtual  Zcad::ErrorStatus addSubentPaths(
                                  const ZcDbFullSubentPathArray& newPaths);

    virtual  Zcad::ErrorStatus deleteSubentPaths(
                                  const ZcDbFullSubentPathArray& paths);

    virtual  Zcad::ErrorStatus getSubentClassId(
                                  const ZcDbFullSubentPath& path,
                                  CLSID*                    clsId) const;

    virtual  Zcad::ErrorStatus transformSubentPathsBy(
                                  const ZcDbFullSubentPathArray& paths,
                                  const ZcGeMatrix3d&            xform);

    virtual  Zcad::ErrorStatus getGripPointsAtSubentPath(
                                  const ZcDbFullSubentPath&      path,
                                  ZcDbGripDataPtrArray&          grips,
                                  const double                   curViewUnitSize,
                                  const int                      gripSize,
                                  const ZcGeVector3d&            curViewDir,
                                  const int                      bitflags) const;

    virtual  Zcad::ErrorStatus moveGripPointsAtSubentPaths(
                                  const ZcDbFullSubentPathArray& paths,
                                  const ZcDbVoidPtrArray&        gripAppData,
                                  const ZcGeVector3d&            offset,
                                  const int                      bitflags);

    virtual  Zcad::ErrorStatus getSubentPathGeomExtents(
                                  const ZcDbFullSubentPath&      path,
                                  ZcDbExtents&                   extents) const;

    virtual  Zcad::ErrorStatus getSubentPathsAtGsMarker(
                                  ZcDb::SubentType       type,
                                  ZSoft::GsMarker        gsMark,
                                  const ZcGePoint3d&     pickPoint,
                                  const ZcGeMatrix3d&    viewXform, 
                                  int&                   numPaths,
                                  ZcDbFullSubentPath*&   subentPaths, 
                                  int                    numInserts = 0,
                                  ZcDbObjectId*          entAndInsertStack
                                                           = nullptr) const;

    virtual  Zcad::ErrorStatus getSubentPathsAtGsMarker(
                                  ZcDb::SubentType       type,
                                  ZSoft::GsMarker        gsMark,
                                  const ZcGePoint3d&     pickPoint,
                                  const ZcGeFastTransform&  viewXform, 
                                  int&                   numPaths,
                                  ZcDbFullSubentPath*&   subentPaths, 
                                  int                    numInserts = 0,
                                  ZcDbObjectId*          entAndInsertStack
                                                           = NULL) const;

    virtual  Zcad::ErrorStatus getGsMarkersAtSubentPath(
                               const ZcDbFullSubentPath& subPath, 
                               ZcArray<ZSoft::GsMarker>& gsMarkers) const;

    virtual Zcad::ErrorStatus highlight(const ZcDbFullSubentPath& subId 
                                        = kNullSubent, const ZSoft::Boolean highlightAll 
                        = false) const;
    virtual Zcad::ErrorStatus unhighlight(const ZcDbFullSubentPath& subId 
                                        = kNullSubent, const ZSoft::Boolean highlightAll  
                        = false) const;
    virtual ZcDbEntity*       subentPtr(const ZcDbFullSubentPath& id) const;
 
    virtual Zcad::ErrorStatus   getOsnapPoints(
                                 ZcDb::OsnapMode     osnapMode,
                                 ZSoft::GsMarker     gsSelectionMark,
                                 const ZcGePoint3d&  pickPoint,
                                 const ZcGePoint3d&  lastPoint,
                                 const ZcGeMatrix3d& viewXform,
                                 ZcGePoint3dArray&   snapPoints,
                                 ZcDbIntArray&       geomIds) const;

    virtual Zcad::ErrorStatus   getOsnapPoints(
                                 ZcDb::OsnapMode     osnapMode,
                                 ZSoft::GsMarker     gsSelectionMark,
                                 const ZcGePoint3d&  pickPoint,
                                 const ZcGePoint3d&  lastPoint,
                                 const ZcGeFastTransform& viewXform,
                                 ZcGePoint3dArray&   snapPoints,
                                 ZcDbIntArray&       geomIds) const;

    virtual Zcad::ErrorStatus   getOsnapPoints(
                                 ZcDb::OsnapMode     osnapMode,
                                 ZSoft::GsMarker     gsSelectionMark,
                                 const ZcGePoint3d&  pickPoint,
                                 const ZcGePoint3d&  lastPoint,
                                 const ZcGeMatrix3d& viewXform,
                                 ZcGePoint3dArray&   snapPoints,
                                 ZcDbIntArray&       geomIds,
                                 const ZcGeMatrix3d& insertionMat) const;

    virtual Zcad::ErrorStatus   getOsnapPoints(
                                 ZcDb::OsnapMode     osnapMode,
                                 ZSoft::GsMarker     gsSelectionMark,
                                 const ZcGePoint3d&  pickPoint,
                                 const ZcGePoint3d&  lastPoint,
                                 const ZcGeFastTransform& viewXform,
                                 ZcGePoint3dArray&   snapPoints,
                                 ZcDbIntArray&       geomIds,
                                 const ZcGeMatrix3d& insertionMat) const;

    virtual Zcad::ErrorStatus   getGripPoints(
                                   ZcGePoint3dArray&  gripPoints,
                                   ZcDbIntArray&  osnapModes,
                                   ZcDbIntArray&  geomIds) const;

    virtual  Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray& indices,
        const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus   getGripPoints(ZcDbGripDataPtrArray& grips,
        const double curViewUnitSize, const int gripSize, 
        const ZcGeVector3d& curViewDir, const int bitflags) const;

    virtual  Zcad::ErrorStatus moveGripPointsAt(const ZcDbVoidPtrArray& gripAppData,
        const ZcGeVector3d& offset, const int bitflags);
    
    virtual Zcad::ErrorStatus getStretchPoints(
        ZcGePoint3dArray& stretchPoints) const;
    virtual Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray& indices,
        const ZcGeVector3d& offset);

    virtual  Zcad::ErrorStatus intersectWith(const ZcDbEntity* pEnt,
                                    ZcDb::Intersect intType, 
                                    ZcGePoint3dArray& points,
                                    ZSoft::GsMarker thisGsMarker = 0,
                                    ZSoft::GsMarker otherGsMarker = 0) const;
 
    virtual  Zcad::ErrorStatus intersectWith(const ZcDbEntity* pEnt,
                                             ZcDb::Intersect intType, 
                                             const ZcGePlane& projPlane,
                                             ZcGePoint3dArray& points, 
                                             ZSoft::GsMarker thisGsMarker = 0,
                                             ZSoft::GsMarker otherGsMarker = 0) const;

    Zcad::ErrorStatus          boundingBoxIntersectWith(
                                             const ZcDbEntity*   pEnt,
                                             ZcDb::Intersect     intType,
                                             ZcGePoint3dArray&   points,
                                             ZSoft::GsMarker     thisGsMarker,
                                             ZSoft::GsMarker     otherGsMarker) const;

    Zcad::ErrorStatus          boundingBoxIntersectWith(
                                             const ZcDbEntity*   pEnt,
                                             ZcDb::Intersect     intType,
                                             const ZcGePlane&    projPlane,
                                             ZcGePoint3dArray&   points,
                                             ZSoft::GsMarker     thisGsMarker,
                                             ZSoft::GsMarker     otherGsMarker) const;

    virtual void                list() const;

    virtual Zcad::ErrorStatus   transformBy(const ZcGeMatrix3d& xform);
    virtual Zcad::ErrorStatus   transformBy(const ZcGeFastTransform& xform);
    virtual Zcad::ErrorStatus   getTransformedCopy(const ZcGeMatrix3d& xform,
                                                   ZcDbEntity*& pEnt) const;
    virtual Zcad::ErrorStatus   explode(ZcDbVoidPtrArray& entitySet) const;

    void                        recordGraphicsModified(
                                    ZSoft::Boolean setModified = true);

    Zcad::ErrorStatus           draw();
    virtual ZSoft::Boolean      worldDraw(ZcGiWorldDraw*        mode);
    virtual void                viewportDraw(ZcGiViewportDraw*  mode);
    virtual void                saveAs(ZcGiWorldDraw* mode, ZcDb::SaveType st);

    virtual Zcad::ErrorStatus   getCompoundObjectTransform(ZcGeMatrix3d & xMat) const;

    void                        setDatabaseDefaults();
    void                        setDatabaseDefaults(ZcDbDatabase* pDb);
    virtual void                subSetDatabaseDefaults(ZcDbDatabase* pDb);

    virtual Zcad::ErrorStatus   applyPartialUndo(ZcDbDwgFiler* undoFiler,
                                                 ZcRxClass*    classObj);

    virtual Zcad::ErrorStatus   audit(ZcDbAuditInfo* pAuditInfo);

    virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const;

    virtual ZcGiDrawable*       drawable();

    virtual ZSoft::UInt32       setAttributes(ZcGiDrawableTraits* pTraits);
    virtual void                setGsNode(ZcGsNode* pNode);
    virtual ZcGsNode*           gsNode() const;
	virtual bool                bounds(ZcDbExtents& bounds) const;

    virtual ZSoft::Boolean      cloneMeForDragging();
    virtual bool                hideMeForDragging() const;

    virtual void                dragStatus(const ZcDb::DragStat status);
    virtual void                gripStatus(const ZcDb::GripStat status);
    virtual void                subentGripStatus(
                                    const ZcDb::GripStat      status,
                                    const ZcDbFullSubentPath& subentity);
    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

    virtual Zcad::ErrorStatus getGripEntityUCS(const void* pGripAppData,
        ZcGeVector3d& normalVec, ZcGePoint3d& origin, ZcGeVector3d& xAxis) const;

protected:
    
    ZcDbEntity();

private:
	ZcDbEntity (const ZcDbEntity& );
	ZcDbEntity & operator = (const ZcDbEntity& );
};

inline ZcDbEntity::~ZcDbEntity()
{
    
}

class ZSOFT_NO_VTABLE ZcDbObjectReactor: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbObjectReactor);

    virtual void cancelled      (const ZcDbObject* dbObj);
    virtual void copied         (const ZcDbObject* dbObj,
                                 const ZcDbObject* newObj);
    virtual void erased         (const ZcDbObject* dbObj,
                                 ZSoft::Boolean pErasing = true);
    virtual void goodbye        (const ZcDbObject* dbObj);
    virtual void openedForModify(const ZcDbObject* dbObj);
    virtual void modified       (const ZcDbObject* dbObj);
    virtual void subObjModified (const ZcDbObject* dbObj,
                                 const ZcDbObject* subObj);
    virtual void modifyUndone   (const ZcDbObject* dbObj);
    virtual void modifiedXData  (const ZcDbObject* dbObj);
    virtual void unappended     (const ZcDbObject* dbObj);
    virtual void reappended     (const ZcDbObject* dbObj);
    virtual void objectClosed   (const ZcDbObjectId objId);

protected:
    ZcDbObjectReactor();
};

class ZSOFT_NO_VTABLE ZcDbEntityReactor: public ZcDbObjectReactor
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbEntityReactor);
    virtual void modifiedGraphics(const ZcDbEntity* dbObj);
    virtual void dragCloneToBeDeleted (const ZcDbEntity* pOriginalObj,
                                       const ZcDbEntity* pClone);
protected:
    ZcDbEntityReactor();
};

class ZSOFT_NO_VTABLE ZcDbDatabaseReactor: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDatabaseReactor);

    virtual void objectAppended       (const ZcDbDatabase* dwg, const ZcDbObject* dbObj);
    virtual void objectUnAppended     (const ZcDbDatabase* dwg, const ZcDbObject* dbObj);
    virtual void objectReAppended     (const ZcDbDatabase* dwg, const ZcDbObject* dbObj);
    virtual void objectOpenedForModify(const ZcDbDatabase* dwg, const ZcDbObject* dbObj);
    virtual void objectModified       (const ZcDbDatabase* dwg, const ZcDbObject* dbObj);
    virtual void objectErased         (const ZcDbDatabase* dwg, const ZcDbObject* dbObj,
                                        ZSoft::Boolean bErased);
    virtual void headerSysVarWillChange(const ZcDbDatabase* dwg, const ZTCHAR* name);
    virtual void headerSysVarChanged   (const ZcDbDatabase* dwg, const ZTCHAR* name,
                                        ZSoft::Boolean bSuccess);
    virtual void proxyResurrectionCompleted(const ZcDbDatabase* dwg,
                                            const ZTCHAR* appname,
                                            ZcDbObjectIdArray& objects);
    virtual void goodbye              (const ZcDbDatabase* dwg);
};

class ZcDbExtents2d : public ZcHeapOperators
{
public:
	ZcDbExtents2d();                                      
	ZcDbExtents2d(const ZcDbExtents2d& src);           
	ZcDbExtents2d(const ZcGePoint2d& min, const ZcGePoint2d& max);  

	ZcGePoint2d       minPoint() const { return mMinPoint; }
	ZcGePoint2d       maxPoint() const { return mMaxPoint; }
	Zcad::ErrorStatus set(const ZcGePoint2d& min, const ZcGePoint2d& max);

	bool              operator==(const ZcDbExtents2d& other);

private:
	ZcGePoint2d    mMinPoint;
	ZcGePoint2d    mMaxPoint;
};

class ZcDbExtents : public ZcHeapOperators
{
public:
    ZcDbExtents();                                      
    ZcDbExtents(const ZcDbExtents& src);           
    ZcDbExtents(const ZcGePoint3d& min, const ZcGePoint3d& max);  
 
    ZcGePoint3d       minPoint() const { return mMinPoint; }
    ZcGePoint3d       maxPoint() const { return mMaxPoint; }
    Zcad::ErrorStatus set(const ZcGePoint3d& min, const ZcGePoint3d& max);

    void              addPoint (const ZcGePoint3d& pt);
    void              addExt   (const ZcDbExtents& src);
    Zcad::ErrorStatus addBlockExt(ZcDbBlockTableRecord* pBTR);

    void expandBy(const ZcGeVector3d& vec);
    void transformBy(const ZcGeMatrix3d& mat);

	bool              operator==(const ZcDbExtents& other);
private:
    ZcGePoint3d    mMinPoint;
    ZcGePoint3d    mMaxPoint;
};

inline Zcad::ErrorStatus
ZcDbDatabase::getBlockTable(
    ZcDbBlockTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getLayerTable(
    ZcDbLayerTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getTextStyleTable(
    ZcDbTextStyleTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getLinetypeTable(
    ZcDbLinetypeTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getViewTable(
    ZcDbViewTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getUCSTable(
    ZcDbUCSTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getViewportTable(
    ZcDbViewportTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getRegAppTable(
    ZcDbRegAppTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getDimStyleTable(
    ZcDbDimStyleTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

#define ZC_SRCH_BLOCK         0x01
#define ZC_SRCH_DIM_TEXT      0x02
#define ZC_SRCH_TEXT          0x04
#define ZC_SRCH_LINK_DESC     0x08
#define ZC_SRCH_LINK_URL      0x10
#define ZC_SRCH_MATCH_CASE    0x20
#define ZC_SRCH_WHOLE_WORD    0x40

#define ZC_SRCH_DEFAULT       0x1F

bool zcdbTextFind(ZcDbDatabase* pDatabase,
                  ZcDbObjectIdArray& resultSet,
                  const ZTCHAR* findString,
                  const ZTCHAR* replaceString = nullptr,
                  ZSoft::UInt8 searchOptions = ZC_SRCH_DEFAULT,
                  const ZcDbObjectIdArray& selSet = 0);

#pragma pack(pop)

#endif
