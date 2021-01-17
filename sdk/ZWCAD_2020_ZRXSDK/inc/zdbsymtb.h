

#ifndef ZD_DBSYMTB_H
#define ZD_DBSYMTB_H

#include "zdbmain.h"
#include "zdbdict.h"
#include "zdbdate.h"
#include "zdbbackground.h"
#include "zgevec2d.h"
#include "zacgiviewport.h"
#include "zacgivisualstyle.h"

#pragma pack(push, 8)

#ifdef target
# undef target 
#endif

class ZcDbSortentsTable;
class ZcDbSymbolTableIterator;
class ZcDbSymbolTableRecord;
class ZcDbAnnotationScale;
class ZcGsView;
class ZcString;

class ZSOFT_NO_VTABLE ZcDbSymbolTable: public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbSymbolTable);
    ZcDbSymbolTable();
    virtual ~ZcDbSymbolTable();

    typedef ZcDbSymbolTableRecord RecordType;

    Zcad::ErrorStatus getAt (const ZTCHAR* entryName,
                             ZcDbSymbolTableRecord*& pRec,
                             ZcDb::OpenMode openMode,
                             bool openErasedRec = false) const;
    Zcad::ErrorStatus getAt (const ZTCHAR* entryName,
                             ZcDbObjectId& recordId,
                             bool getErasedRecord = false) const;
    bool              has(const ZTCHAR* name) const;
    bool              has(ZcDbObjectId id) const;
    Zcad::ErrorStatus newIterator(ZcDbSymbolTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Zcad::ErrorStatus add(ZcDbSymbolTableRecord* pRecord);
    Zcad::ErrorStatus add(ZcDbObjectId& recordId, ZcDbSymbolTableRecord* pRecord);

};

class ZcDbBlockTableRecord;
class ZcDbBlockTableIterator;

class ZcDbBlockTable: public ZcDbSymbolTable
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbBlockTable);
    ZcDbBlockTable();
    virtual ~ZcDbBlockTable();

    typedef ZcDbBlockTableRecord RecordType;

    Zcad::ErrorStatus getAt (const ZTCHAR* entryName,
                             ZcDbBlockTableRecord*& pRec,
                             ZcDb::OpenMode openMode,
                             bool openErasedRec = false) const;
    Zcad::ErrorStatus getAt (const ZTCHAR* entryName,
                             ZcDbObjectId& recordId,
                             bool getErasedRec = false) const;
    bool              has   (const ZTCHAR* name) const;
    bool              has   (ZcDbObjectId id) const;
    Zcad::ErrorStatus newIterator(ZcDbBlockTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Zcad::ErrorStatus add   (ZcDbBlockTableRecord* pRecord);
    Zcad::ErrorStatus add   (ZcDbObjectId& recordId, ZcDbBlockTableRecord* pRecord);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class ZcDbLayerTableRecord;
class ZcDbLayerTableIterator;

class ZcDbLayerTable: public ZcDbSymbolTable
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbLayerTable);
    ZcDbLayerTable();
    virtual ~ZcDbLayerTable();

    typedef ZcDbLayerTableRecord RecordType;

    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbLayerTableRecord*& pRec,
                            ZcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbObjectId& recordId,
                            bool getErasedRecord = false) const;
    bool              has  (const ZTCHAR* name) const;
    bool              has  (ZcDbObjectId id) const;
    Zcad::ErrorStatus newIterator(ZcDbLayerTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Zcad::ErrorStatus add (ZcDbLayerTableRecord* pRecord);
    Zcad::ErrorStatus add (ZcDbObjectId& recordId, ZcDbLayerTableRecord* pRecord);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

    void generateUsageData();

    bool hasUnreconciledLayers() const;
    Zcad::ErrorStatus getUnreconciledLayers(ZcDbObjectIdArray& idArray) const;
};

class ZcDbTextStyleTableRecord;
class ZcDbTextStyleTableIterator;

class ZcDbTextStyleTable: public ZcDbSymbolTable
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbTextStyleTable);
    ZcDbTextStyleTable();
    virtual ~ZcDbTextStyleTable();

    typedef ZcDbTextStyleTableRecord RecordType;

    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbTextStyleTableRecord*& pRec,
                            ZcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Zcad::ErrorStatus getAt (const ZTCHAR* entryName,
                             ZcDbObjectId& recordId,
                             bool getErasedRecord = false) const;
    bool              has   (const ZTCHAR* name) const;
    bool              has   (ZcDbObjectId id) const;
    Zcad::ErrorStatus newIterator(ZcDbTextStyleTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Zcad::ErrorStatus add   (ZcDbTextStyleTableRecord* pRecord);
    Zcad::ErrorStatus add   (ZcDbObjectId&  recordId,
        ZcDbTextStyleTableRecord* pRecord);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class ZcDbLinetypeTableRecord;
class ZcDbLinetypeTableIterator;

class ZcDbLinetypeTable: public ZcDbSymbolTable
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbLinetypeTable);
    ZcDbLinetypeTable();
    virtual ~ZcDbLinetypeTable();

    typedef ZcDbLinetypeTableRecord RecordType;

    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbLinetypeTableRecord*& pRec,
                            ZcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbObjectId& recordId,
                            bool getErasedRec = false) const;
    bool              has  (const ZTCHAR* name) const;
    bool              has  (ZcDbObjectId id) const;
    Zcad::ErrorStatus newIterator(ZcDbLinetypeTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Zcad::ErrorStatus add  (ZcDbLinetypeTableRecord* pRecord);
    Zcad::ErrorStatus add  (ZcDbObjectId& recordId,
        ZcDbLinetypeTableRecord* pRecord);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class ZcDbAbstractViewTableRecord;
class ZcDbAbstractViewTableIterator;

class ZSOFT_NO_VTABLE ZcDbAbstractViewTable: public ZcDbSymbolTable
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbAbstractViewTable);
    ZcDbAbstractViewTable();
    virtual ~ZcDbAbstractViewTable();
    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbAbstractViewTableRecord*& pRec,
                            ZcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbObjectId& recordId,
                            bool getErasedRecord = false) const;
    bool              has  (const ZTCHAR* name) const;
    bool              has  (ZcDbObjectId id) const;
    Zcad::ErrorStatus newIterator(ZcDbAbstractViewTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Zcad::ErrorStatus add  (ZcDbAbstractViewTableRecord* pRecord);
    Zcad::ErrorStatus add  (ZcDbObjectId&  recordId,
        ZcDbAbstractViewTableRecord* pRecord);
};

class ZcDbViewTableRecord;
class ZcDbViewTableIterator;

class ZcDbViewTable: public ZcDbAbstractViewTable
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbViewTable);
    ZcDbViewTable();
    virtual ~ZcDbViewTable();

    typedef ZcDbViewTableRecord RecordType;

    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbViewTableRecord*& pRec,
                            ZcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbObjectId& recordId,
                            bool getErasedRec = false) const;
    bool              has  (const ZTCHAR* name) const;
    bool              has  (ZcDbObjectId id) const;
    Zcad::ErrorStatus newIterator(ZcDbViewTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Zcad::ErrorStatus add  (ZcDbViewTableRecord* pRecord);
    Zcad::ErrorStatus add  (ZcDbObjectId&  recordId,
        ZcDbViewTableRecord* pRecord);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class ZcDbUCSTableRecord;
class ZcDbUCSTableIterator;

class ZcDbUCSTable: public ZcDbSymbolTable
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbUCSTable);
    ZcDbUCSTable();
    virtual ~ZcDbUCSTable();

    typedef ZcDbUCSTableRecord RecordType;

    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbUCSTableRecord*& pRec,
                            ZcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbObjectId& recordId,
                            bool getErasedRecord = false) const;
    bool              has  (const ZTCHAR* name) const;
    bool              has  (ZcDbObjectId id) const;
    Zcad::ErrorStatus newIterator(ZcDbUCSTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Zcad::ErrorStatus add  (ZcDbUCSTableRecord* pRecord);
    Zcad::ErrorStatus add  (ZcDbObjectId&  recordId,
        ZcDbUCSTableRecord* pRecord);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class ZcDbViewportTableRecord;
class ZcDbViewportTableIterator;

class ZcDbViewportTable: public ZcDbAbstractViewTable
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbViewportTable);
    ZcDbViewportTable();
    virtual ~ZcDbViewportTable();

    typedef ZcDbViewportTableRecord RecordType;

    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbViewportTableRecord*& pRec,
                            ZcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbObjectId& recordId,
                            bool getErasedRecord = false) const;
    bool              has  (const ZTCHAR* name) const;
    bool              has  (ZcDbObjectId id) const;
    Zcad::ErrorStatus newIterator(ZcDbViewportTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Zcad::ErrorStatus add  (ZcDbViewportTableRecord* pRecord);
    Zcad::ErrorStatus add  (ZcDbObjectId& recordId,
        ZcDbViewportTableRecord* pRecord);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class ZcDbRegAppTableRecord;
class ZcDbRegAppTableIterator;

class ZcDbRegAppTable: public ZcDbSymbolTable
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbRegAppTable);
    ZcDbRegAppTable();
    virtual ~ZcDbRegAppTable();

    typedef ZcDbRegAppTableRecord RecordType;

    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbRegAppTableRecord*& pRec,
                            ZcDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbObjectId& recordId,
                            bool getErasedRec = false) const;
    bool              has  (const ZTCHAR* name) const;
    bool              has  (ZcDbObjectId id) const;
    Zcad::ErrorStatus newIterator(ZcDbRegAppTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    Zcad::ErrorStatus   add     (ZcDbRegAppTableRecord* pRecord);
    Zcad::ErrorStatus   add     (ZcDbObjectId&  recordId,
        ZcDbRegAppTableRecord* pRecord);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class ZcDbDimStyleTableRecord;
class ZcDbDimStyleTableIterator;

class ZcDbDimStyleTable: public ZcDbSymbolTable
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDimStyleTable);
    ZcDbDimStyleTable();
    virtual ~ZcDbDimStyleTable();

    typedef ZcDbDimStyleTableRecord RecordType;

    Zcad::ErrorStatus   getAt   (const ZTCHAR* entryName,
                                 ZcDbDimStyleTableRecord*& pRec,
                                 ZcDb::OpenMode openMode,
                                 bool openErasedRec = false) const;
    Zcad::ErrorStatus   getAt   (const ZTCHAR* entryName,
                                 ZcDbObjectId& recordId,
                                 bool getErasedRec = false) const;
    bool                has     (const ZTCHAR* name) const;
    bool                has     (ZcDbObjectId id) const;
    Zcad::ErrorStatus   newIterator(ZcDbDimStyleTableIterator*& pIterator,
                                    bool atBeginning = true,
                                    bool skipDeleted = true) const;
    Zcad::ErrorStatus   add     (ZcDbDimStyleTableRecord* pRecord);
    Zcad::ErrorStatus   add     (ZcDbObjectId&  recordId,
        ZcDbDimStyleTableRecord* pRecord);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class ZcDbSymbolTableIterator
{
public:
    virtual ~ZcDbSymbolTableIterator();

    void                start   (bool atBeginning = true,
                                 bool skipDeleted = true);

    bool                done    () const;

    Zcad::ErrorStatus   getRecordId(ZcDbObjectId& id) const;

    Zcad::ErrorStatus   getRecord(ZcDbSymbolTableRecord*& pRecord,
                                 ZcDb::OpenMode openMode,
                                 bool openErasedRec = false) const;

    void                step    (bool forward = true,
                                 bool skipDeleted = true);

    Zcad::ErrorStatus   seek    (ZcDbObjectId id);

    Zcad::ErrorStatus   seek    (const ZcDbSymbolTableRecord* pRecord);
protected:
    void* mpImp;
    ZcDbSymbolTableIterator();
    friend class ZcDbSymbolTable;
};

class ZcDbBlockTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbBlockTableRecord*& pRecord,
        ZcDb::OpenMode openMode, bool openErasedRec = false) const;
    Zcad::ErrorStatus seek(ZcDbObjectId id);
    Zcad::ErrorStatus seek(const ZcDbBlockTableRecord* pRecord);

protected:
    ZcDbBlockTableIterator();
    friend class ZcDbBlockTable;
};

class ZcDbLayerTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbLayerTableRecord*& pRecord,
        ZcDb::OpenMode openMode, bool openErasedRec = false) const;
    Zcad::ErrorStatus seek(ZcDbObjectId id);
    Zcad::ErrorStatus seek(const ZcDbLayerTableRecord* pRecord);
    bool getSkipHidden() const;
    void setSkipHidden(bool value);
    bool getSkipReconciled() const;
    void setSkipReconciled(bool value);
protected:
    ZcDbLayerTableIterator();
    friend class ZcDbLayerTable;
};

class ZcDbTextStyleTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbTextStyleTableRecord*& pRecord,
        ZcDb::OpenMode openMode, bool openErasedRec = false) const;
    Zcad::ErrorStatus seek(ZcDbObjectId id);
    Zcad::ErrorStatus seek(const ZcDbTextStyleTableRecord* pRecord);

protected:
    ZcDbTextStyleTableIterator();
    friend class ZcDbTextStyleTable;
};

class ZcDbLinetypeTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbLinetypeTableRecord*& pRecord,
        ZcDb::OpenMode openMode, bool openErasedRec = false) const;
    Zcad::ErrorStatus seek(ZcDbObjectId id);
    Zcad::ErrorStatus seek(const ZcDbLinetypeTableRecord* pRecord);

protected:
    ZcDbLinetypeTableIterator();
    friend class ZcDbLinetypeTable;
};

class ZcDbAbstractViewTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbAbstractViewTableRecord*& pRecord,
        ZcDb::OpenMode openMode, bool openErasedRec = false) const;
    Zcad::ErrorStatus seek(ZcDbObjectId id);
    Zcad::ErrorStatus seek(const ZcDbAbstractViewTableRecord* pRecord);

protected:
    ZcDbAbstractViewTableIterator();
    friend class ZcDbAbstractViewTable;
};

class ZcDbViewTableIterator : public ZcDbAbstractViewTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbViewTableRecord*& pRecord,
        ZcDb::OpenMode openMode, bool openErasedRec = false) const;
    Zcad::ErrorStatus seek(ZcDbObjectId id);
    Zcad::ErrorStatus seek(const ZcDbViewTableRecord* pRecord);

protected:
    ZcDbViewTableIterator();
    friend class ZcDbViewTable;
};

class ZcDbUCSTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbUCSTableRecord*& pRecord,
        ZcDb::OpenMode openMode, bool openErasedRec = false) const;
    Zcad::ErrorStatus seek(ZcDbObjectId id);
    Zcad::ErrorStatus seek(const ZcDbUCSTableRecord* pRecord);

protected:
    ZcDbUCSTableIterator();
    friend class ZcDbUCSTable;
};

class ZcDbViewportTableIterator : public ZcDbAbstractViewTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbViewportTableRecord*& pRecord,
        ZcDb::OpenMode openMode, bool openErasedRec = false) const;
    Zcad::ErrorStatus seek(ZcDbObjectId id);
    Zcad::ErrorStatus seek(const ZcDbViewportTableRecord* pRecord);

protected:
    ZcDbViewportTableIterator();
    friend class ZcDbViewportTable;
};

class ZcDbRegAppTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbRegAppTableRecord*& pRecord,
        ZcDb::OpenMode openMode, bool openErasedRec = false) const;
    Zcad::ErrorStatus seek(ZcDbObjectId id);
    Zcad::ErrorStatus seek(const ZcDbRegAppTableRecord* pRecord);

protected:
    ZcDbRegAppTableIterator();
    friend class ZcDbRegAppTable;
};

class ZcDbDimStyleTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbDimStyleTableRecord*& pRecord,
        ZcDb::OpenMode openMode, bool openErasedRec = false) const;
    Zcad::ErrorStatus seek(ZcDbObjectId id);
    Zcad::ErrorStatus seek(const ZcDbDimStyleTableRecord* pRecord);

protected:
    ZcDbDimStyleTableIterator();
    friend class ZcDbDimStyleTable;
};

class ZSOFT_NO_VTABLE ZcDbSymbolTableRecord: public  ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbSymbolTableRecord);
    ZcDbSymbolTableRecord();
    virtual ~ZcDbSymbolTableRecord();

    typedef ZcDbSymbolTable TableType;

    Zcad::ErrorStatus getName(ZTCHAR*& pName) const;
    Zcad::ErrorStatus getName(ZcString & sName) const;
    Zcad::ErrorStatus getName(const ZTCHAR*& pName) const;
    Zcad::ErrorStatus setName(const ZTCHAR* pName);

    bool isDependent() const;

    bool isResolved() const;
};

class ZcDbBlockTableRecordIterator
{
public:
    virtual ~ZcDbBlockTableRecordIterator();

    void              start (bool atBeginning = true,
                             bool skipDeleted = true);

    bool              done  () const;

    Zcad::ErrorStatus getEntityId (ZcDbObjectId& entityId) const;

    Zcad::ErrorStatus getEntity(ZcDbEntity*& pEntity, ZcDb::OpenMode openMode,
                                bool openErasedEntity = false) const;

    ZcDbBlockTableRecord* blockTableRecord() const;

    void              step (bool forward = true,
                            bool skipDeleted = true);

    Zcad::ErrorStatus seek (ZcDbObjectId id);

    Zcad::ErrorStatus seek (const ZcDbEntity* pEntity);

protected:
    class ZcDbImpBlockTableRecordIterator * mpImp;
private:
    ZcDbBlockTableRecordIterator();
	friend class ZcDbImpBlockTableRecord;
};

class ZcDbBlockReferenceIdIterator
{
public:
    ~ZcDbBlockReferenceIdIterator();

    void              start () { mPos = 0; }
        
    bool              done  () const { return mPos >= mAry.length(); }

    Zcad::ErrorStatus getBlockReferenceId (ZcDbObjectId& id) const;

    Zcad::ErrorStatus getDatabase (ZcDbDatabase*& pDb) const;

    Zcad::ErrorStatus getBlockReference(ZcDbBlockReference*& pBlkRef,
                        ZcDb::OpenMode openMode, bool openErasedEntity = false) const;

    void              step () { mPos++; }

    Zcad::ErrorStatus seek (ZcDbObjectId id);

private:
    ZcDbBlockReferenceIdIterator();
    friend class ZcDbBlockTableRecord;

    int               mPos;
    ZcDbObjectIdArray mAry;
};

class ZcDbBlockTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbBlockTableRecord);

    ZcDbBlockTableRecord();
    virtual ~ZcDbBlockTableRecord();

    typedef ZcDbBlockTable TableType;
    typedef ZcArray<ZSoft::UInt8> PreviewIcon;

    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;

    Zcad::ErrorStatus appendZcDbEntity(ZcDbEntity* pEntity);

    Zcad::ErrorStatus appendZcDbEntity(ZcDbObjectId& pOutputId,
        ZcDbEntity* pEntity);

    Zcad::ErrorStatus newIterator(
        ZcDbBlockTableRecordIterator*& pIterator,
        bool atBeginning = true,
        bool skipDeleted = true) const;

    Zcad::ErrorStatus comments(ZTCHAR*& pString) const;
    Zcad::ErrorStatus comments(const ZTCHAR*& pString) const;
    Zcad::ErrorStatus setComments(const ZTCHAR* pString);

    Zcad::ErrorStatus pathName(ZTCHAR*& pPath) const;
    Zcad::ErrorStatus pathName(const ZTCHAR*& pPath) const;
    Zcad::ErrorStatus setPathName(const ZTCHAR* pathStr);
 
    ZcGePoint3d       origin() const;
    Zcad::ErrorStatus setOrigin(const ZcGePoint3d& pt);

    Zcad::ErrorStatus openBlockBegin(ZcDbBlockBegin*& pBlockBegin,
                                     ZcDb::OpenMode   openMode);
 
    Zcad::ErrorStatus openBlockEnd(ZcDbBlockEnd*& pBlockEnd,
                                   ZcDb::OpenMode openMode);

    bool              hasAttributeDefinitions() const;

    bool              hasPreviewIcon() const;
    Zcad::ErrorStatus getPreviewIcon(PreviewIcon &previewIcon) const;
    Zcad::ErrorStatus setPreviewIcon(const PreviewIcon &previewIcon);

    bool              isAnonymous() const;

    bool              isFromExternalReference() const;

    bool              isFromOverlayReference() const;

    bool              isLayout() const;

    ZcDbObjectId      getLayoutId() const;
    Zcad::ErrorStatus setLayoutId(ZcDbObjectId);

    Zcad::ErrorStatus newBlockReferenceIdIterator(
        ZcDbBlockReferenceIdIterator*& pIter) const;

    Zcad::ErrorStatus getBlockReferenceIds(ZcDbObjectIdArray& ids,
                                           bool bDirectOnly = true,
                                           bool bForceValidity = false) const;

    Zcad::ErrorStatus getErasedBlockReferenceIds(ZcDbObjectIdArray&);

    Zcad::ErrorStatus
    getSortentsTable(ZcDbSortentsTable*& pSortents,
                     ZcDb::OpenMode openMode,
                     bool createIfNecessary=false);

    ZcDbDatabase*     xrefDatabase(bool incUnres = false) const;

    bool              isUnloaded() const;
    Zcad::ErrorStatus setIsUnloaded(bool isUnloaded);

    ZcDb::XrefStatus  xrefStatus() const;

    ZcGiDrawable*     drawable();
    ZSoft::UInt32     setAttributes(ZcGiDrawableTraits* pTraits);
    ZSoft::Boolean    worldDraw(ZcGiWorldDraw* pWd);
    void              viewportDraw(ZcGiViewportDraw* pVd);
    void              setGsNode(ZcGsNode* pNode);
    ZcGsNode*         gsNode() const;

    virtual Zcad::ErrorStatus decomposeForSave(ZcDb::ZcDbDwgVersion ver,
                                               ZcDbObject*& replaceObj,
                                               ZcDbObjectId& replaceId,
                                               ZSoft::Boolean& exchangeXData);
    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

    virtual Zcad::ErrorStatus assumeOwnershipOf(ZcArray <ZcDbObjectId> entitiesToMove);

	enum BlockScaling {
		kAny,
		kUniform
	};

	ZcDbBlockTableRecord::BlockScaling blockScaling () const;
    Zcad::ErrorStatus  setBlockScaling (
                        ZcDbBlockTableRecord::BlockScaling blockScaling);

	Zcad::ErrorStatus setExplodable (bool bExplodable);
	bool              explodable () const;

	Zcad::ErrorStatus setBlockInsertUnits(ZcDb::UnitsValue insunits);
	ZcDb::UnitsValue blockInsertUnits() const;

    Zcad::ErrorStatus postProcessAnnotativeBTR(int& stripCnt, const bool bqueryOnly = false,
                                               const bool bScale = true);
	Zcad::ErrorStatus addAnnoScalestoBlkRefs(const bool bScale = false);

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const;
};

class ZcDbLayerTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbLayerTableRecord);

    ZcDbLayerTableRecord();
    virtual ~ZcDbLayerTableRecord();

    typedef ZcDbLayerTable TableType;

    bool              isFrozen() const;
    Zcad::ErrorStatus setIsFrozen(bool frozen);

    bool              isOff() const;
    void              setIsOff(bool off);

    bool              VPDFLT() const;
    void              setVPDFLT(bool frozen);

    bool              isLocked() const;
    void              setIsLocked(bool locked);

    ZcCmColor         color() const;
    void              setColor(const ZcCmColor &color);
    ZcCmEntityColor   entityColor(void) const;

    ZcCmTransparency  transparency(void) const;
    Zcad::ErrorStatus setTransparency(const ZcCmTransparency& trans);

    ZcDbObjectId      linetypeObjectId() const;
    void              setLinetypeObjectId(ZcDbObjectId id);

    ZcDbObjectId      materialId() const;
    Zcad::ErrorStatus setMaterialId(ZcDbObjectId id);

    enum { kDxfLayerPlotBit = ZcDb::kDxfBool };
    bool              isPlottable() const;
    Zcad::ErrorStatus setIsPlottable(bool plot);

    ZcDb::LineWeight  lineWeight() const;
    Zcad::ErrorStatus setLineWeight(ZcDb::LineWeight weight);

    ZTCHAR*            plotStyleName() const;
    ZcDbObjectId      plotStyleNameId() const;
    Zcad::ErrorStatus setPlotStyleName(const ZTCHAR* newName);
    Zcad::ErrorStatus setPlotStyleName(const ZcDbObjectId& newId);

    ZcGiDrawable*     drawable();
    ZSoft::UInt32     setAttributes(ZcGiDrawableTraits* pTraits);
    ZSoft::Boolean    worldDraw(ZcGiWorldDraw* pWd);
    void              viewportDraw(ZcGiViewportDraw* pVd);
    void              setGsNode(ZcGsNode* pNode);
    ZcGsNode*         gsNode() const;

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

    bool              isInUse() const;
    ZTCHAR*            description() const;
    Zcad::ErrorStatus setDescription(const ZTCHAR* description);

    bool              isHidden() const;
    Zcad::ErrorStatus setIsHidden(bool on);
    static bool isHidden(ZcDbObjectId);
    ZcCmColor         color(const ZcDbObjectId& viewportId, bool& isOverride) const;
    Zcad::ErrorStatus setColor(const ZcCmColor& color, 
                               const ZcDbObjectId& viewportId);

    ZcDbObjectId      linetypeObjectId(const ZcDbObjectId& viewportId, bool& isOverride) const;
    Zcad::ErrorStatus setLinetypeObjectId(const ZcDbObjectId& id, 
                                          const ZcDbObjectId& viewportId);

    ZcDb::LineWeight  lineWeight(const ZcDbObjectId& viewportId, bool& isOverride) const;
    Zcad::ErrorStatus setLineWeight(ZcDb::LineWeight weight, 
                                    const ZcDbObjectId& viewportId);

    ZTCHAR*            plotStyleName(const ZcDbObjectId& viewportId, bool& isOverride) const;
    ZcDbObjectId      plotStyleNameId(const ZcDbObjectId& viewportId, bool& isOverride) const;
    Zcad::ErrorStatus setPlotStyleName(const ZTCHAR* newName,
                                       const ZcDbObjectId& viewportId);
    Zcad::ErrorStatus setPlotStyleName(const ZcDbObjectId& newId, 
                                       const ZcDbObjectId& viewportId);

    Zcad::ErrorStatus removeColorOverride(const ZcDbObjectId& viewportId);
    Zcad::ErrorStatus removeLinetypeOverride(const ZcDbObjectId& viewportId);
    Zcad::ErrorStatus removeLineWeightOverride(const ZcDbObjectId& viewportId);
    Zcad::ErrorStatus removePlotStyleOverride(const ZcDbObjectId& viewportId);
    Zcad::ErrorStatus removeViewportOverrides(const ZcDbObjectId& viewportId);
    Zcad::ErrorStatus removeAllOverrides();

    bool              hasOverrides(const ZcDbObjectId& viewportId) const;
    bool              hasAnyOverrides() const;

    bool              isReconciled() const;
    Zcad::ErrorStatus setIsReconciled(bool bReconcile = true);
    static bool       isReconciled(const ZcDbObjectId& id);
};

Zcad::ErrorStatus applyCurDwgLayerTableChanges();

class ZcDbTextStyleTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbTextStyleTableRecord);

    ZcDbTextStyleTableRecord();
    virtual ~ZcDbTextStyleTableRecord();

    typedef ZcDbTextStyleTable TableType;

    ZSoft::Boolean isShapeFile() const;
    void setIsShapeFile(ZSoft::Boolean shape);

    ZSoft::Boolean isVertical() const;
    void setIsVertical(ZSoft::Boolean vertical);

    double textSize() const;
    Zcad::ErrorStatus setTextSize(double size);

    double xScale() const;
    Zcad::ErrorStatus setXScale(double xScale);

    double obliquingAngle() const;
    Zcad::ErrorStatus setObliquingAngle(double obliquingAngle);

    ZSoft::UInt8 flagBits() const;
    void setFlagBits(ZSoft::UInt8 flagBits);

    double priorSize() const;
    Zcad::ErrorStatus setPriorSize(double priorSize);

    Zcad::ErrorStatus fileName(ZTCHAR*& fileName) const;
    Zcad::ErrorStatus fileName(const ZTCHAR*& fileName) const;
    Zcad::ErrorStatus setFileName(const ZTCHAR* fileName);

    Zcad::ErrorStatus bigFontFileName(ZTCHAR*& fileName) const;
    Zcad::ErrorStatus bigFontFileName(const ZTCHAR*& fileName) const;
    Zcad::ErrorStatus setBigFontFileName(const ZTCHAR* fileName);

    Zcad::ErrorStatus setFont(const ZTCHAR* pTypeface, ZSoft::Boolean bold,
        ZSoft::Boolean italic, int charset, int pitchAndFamily);
    Zcad::ErrorStatus font   (ZTCHAR*& pTypeface, ZSoft::Boolean& bold, ZSoft::Boolean& italic,
                              int& charset, int& pitchAndFamily) const;
    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class ZcDbLinetypeTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbLinetypeTableRecord);

    ZcDbLinetypeTableRecord();
    virtual ~ZcDbLinetypeTableRecord();

    typedef ZcDbLinetypeTable TableType;

    Zcad::ErrorStatus comments(ZTCHAR*& pString) const;
    Zcad::ErrorStatus comments(const ZTCHAR*& pString) const;
    Zcad::ErrorStatus setComments(const ZTCHAR* pString);

    Zcad::ErrorStatus asciiDescription(ZTCHAR*& pString) const
                      { return comments(pString); }
    Zcad::ErrorStatus asciiDescription(const ZTCHAR*& pString) const
                      { return comments(pString); }
    Zcad::ErrorStatus setAsciiDescription(const ZTCHAR* pString)
                      { return setComments(pString); }

    double patternLength() const;
    void   setPatternLength(double patternLength);

    int    numDashes() const;
    void   setNumDashes(int count);

    double dashLengthAt(int index) const;
    void   setDashLengthAt(int index , double value);

    ZcDbObjectId shapeStyleAt(int index) const;
    void         setShapeStyleAt(int index, ZcDbObjectId id);

    int    shapeNumberAt(int index) const;
    void   setShapeNumberAt(int index, int shapeNumber);

    ZcGeVector2d shapeOffsetAt(int index) const;
    void         setShapeOffsetAt(int index, const ZcGeVector2d& offset);

    double shapeScaleAt(int index) const;
    void   setShapeScaleAt(int index, double scale);

    bool isScaledToFit() const;
    void           setIsScaledToFit(bool scaledToFit);

    bool shapeIsUcsOrientedAt(int index) const;
    void           setShapeIsUcsOrientedAt(int index, bool isUcsOriented);

    double         shapeRotationAt(int index) const;
    void           setShapeRotationAt(int index, double rotation);

    Zcad::ErrorStatus textAt(int index, ZTCHAR*& text) const;
    Zcad::ErrorStatus textAt(int index, const ZTCHAR*& text) const;
    Zcad::ErrorStatus setTextAt(int index, const ZTCHAR* text);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
    ZcGiDrawable*     drawable();
    ZSoft::UInt32     setAttributes(ZcGiDrawableTraits* pTraits);
    ZSoft::Boolean    worldDraw(ZcGiWorldDraw* pWd);
    void              viewportDraw(ZcGiViewportDraw* pVd);
    void              setGsNode(ZcGsNode* pNode);
    ZcGsNode*         gsNode() const;
};

class ZSOFT_NO_VTABLE ZcDbAbstractViewTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbAbstractViewTableRecord);

    ZcDbAbstractViewTableRecord();
    virtual ~ZcDbAbstractViewTableRecord();

    enum RenderMode {
        k2DOptimized,
        kWireframe,
        kHiddenLine,
        kFlatShaded,
        kGouraudShaded,
        kFlatShadedWithWireframe,
        kGouraudShadedWithWireframe
    };

    ZcGePoint2d    centerPoint() const;
    void           setCenterPoint(const ZcGePoint2d&);

    double         height() const;
    void           setHeight(double height);

    double         width() const;
    void           setWidth(double width);

    ZcGePoint3d    target() const;
    void           setTarget(const ZcGePoint3d& target);

    ZcGeVector3d   viewDirection() const;
    void           setViewDirection(const ZcGeVector3d& viewDirection);

    double         viewTwist() const;
    void           setViewTwist(double angle);

    double         lensLength() const;
    void           setLensLength(double length);

    double         frontClipDistance() const;
    void           setFrontClipDistance(double distance);

    double         backClipDistance() const;
    void           setBackClipDistance(double distance);

    bool           perspectiveEnabled() const;
    void           setPerspectiveEnabled(bool enabled);

    bool           frontClipEnabled() const;
    void           setFrontClipEnabled(bool enabled);

    bool           backClipEnabled() const;
    void           setBackClipEnabled(bool enabled);

    bool           frontClipAtEye() const;
    void           setFrontClipAtEye(bool atEye);

    void           setRenderMode(RenderMode mode);
    RenderMode     renderMode() const;
    const ZcDbObjectId&  background() const;
    ZcDbObjectId&       background();
    Zcad::ErrorStatus   setBackground(const ZcDbObjectId& backgroundId);
    ZcDbObjectId visualStyle() const;
    Zcad::ErrorStatus   setVisualStyle(const ZcDbObjectId& visualStyleId);
    bool                isDefaultLightingOn() const;
    Zcad::ErrorStatus   setDefaultLightingOn(bool on);
    ZcGiViewportTraits::DefaultLightingType defaultLightingType() const;
    Zcad::ErrorStatus   setDefaultLightingType(ZcGiViewportTraits::DefaultLightingType typ);
    double              brightness() const;
    Zcad::ErrorStatus   setBrightness(double);

    double              contrast() const;
    Zcad::ErrorStatus   setContrast(double);

    ZcCmColor           ambientLightColor() const;
    Zcad::ErrorStatus   setAmbientLightColor(const ZcCmColor& clr);
    ZcDbObjectId        sunId() const;
    Zcad::ErrorStatus   setSun(ZcDbObjectId& retId, ZcDbObject* pSun);
    Zcad::ErrorStatus toneOperatorParameters(ZcGiToneOperatorParameters& params) const;
    Zcad::ErrorStatus setToneOperatorParameters(const ZcGiToneOperatorParameters& params);
    Zcad::ErrorStatus getUcs            ( ZcGePoint3d& origin,
                                          ZcGeVector3d& xAxis,
                                          ZcGeVector3d& yAxis ) const;
    bool              isUcsOrthographic ( ZcDb::OrthographicView& view ) const;
    ZcDbObjectId      ucsName           () const;
    double            elevation         () const;

    Zcad::ErrorStatus setUcs        ( const ZcGePoint3d& origin,
                                      const ZcGeVector3d& xAxis,
                                      const ZcGeVector3d& yAxis );
    Zcad::ErrorStatus setUcs        ( ZcDb::OrthographicView view );
    Zcad::ErrorStatus setUcs        ( const ZcDbObjectId& ucsId );
    Zcad::ErrorStatus setUcsToWorld ();
    Zcad::ErrorStatus setElevation  ( double elev );

    bool              isViewOrthographic ( ZcDb::OrthographicView& view ) const;
    Zcad::ErrorStatus setViewDirection   ( ZcDb::OrthographicView view );
};

class ZcDbViewTableRecord: public  ZcDbAbstractViewTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbViewTableRecord);

    ZcDbViewTableRecord();
    virtual ~ZcDbViewTableRecord();

    typedef ZcDbViewTable TableType;

    Zcad::ErrorStatus setParametersFromViewport(ZcDbObjectId objId);

    bool isPaperspaceView() const;
    void setIsPaperspaceView(bool pspace);
    
    bool    isUcsAssociatedToView   () const;
    Zcad::ErrorStatus disassociateUcsFromView ();

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

    Zcad::ErrorStatus getCategoryName(ZTCHAR *& categoryName) const;
    Zcad::ErrorStatus setCategoryName(const ZTCHAR * categoryName);

    Zcad::ErrorStatus getLayerState(ZTCHAR*& layerStateName) const;
    Zcad::ErrorStatus setLayerState(const ZTCHAR *layerStateName);
 
    Zcad::ErrorStatus getLayout (ZcDbObjectId& layoutId) const;
    Zcad::ErrorStatus setLayout(ZcDbObjectId layoutId);

    bool              isViewAssociatedToViewport () const;
    Zcad::ErrorStatus setViewAssociatedToViewport (bool bVPflag);

    bool              isCameraPlottable () const;
    Zcad::ErrorStatus setIsCameraPlottable (bool plottable);
    ZcDbObjectId      liveSection() const;
    Zcad::ErrorStatus setLiveSection(const ZcDbObjectId& liveSectionId);

#ifdef _WINDOWS_
    Zcad::ErrorStatus getThumbnail (BITMAPINFO*& thumbnail) const;
    Zcad::ErrorStatus setThumbnail(const BITMAPINFO * thumbnail);
#endif
    ZcDbObjectId      camera          () const;
    Zcad::ErrorStatus setCamera(ZcDbObjectId cameraId);
    ZcDbAnnotationScale* annotationScale() const;
    Zcad::ErrorStatus setAnnotationScale(const ZcDbAnnotationScale* pScaleObj);
    ZcDbObjectId      sunId() const;
    Zcad::ErrorStatus setSun(ZcDbObjectId& retId, ZcDbObject* pSun);
};

class ZcDbUCSTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbUCSTableRecord);

    ZcDbUCSTableRecord();
    virtual ~ZcDbUCSTableRecord();

    typedef ZcDbUCSTable TableType;

    ZcGePoint3d  origin() const;
    void         setOrigin(const ZcGePoint3d& newOrigin);

    ZcGeVector3d xAxis() const;
    void         setXAxis(const ZcGeVector3d& xAxis);

    ZcGeVector3d yAxis() const;
    void         setYAxis(const ZcGeVector3d& yAxis);

    ZcGePoint3d       ucsBaseOrigin    ( ZcDb::OrthographicView view ) const;
    Zcad::ErrorStatus setUcsBaseOrigin ( const ZcGePoint3d& origin,
                                         ZcDb::OrthographicView view );
    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class ZcDbViewportTableRecord: public  ZcDbAbstractViewTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbViewportTableRecord);

    ZcDbViewportTableRecord();
    virtual ~ZcDbViewportTableRecord();

    typedef ZcDbViewportTable TableType;

    ZSoft::Int16   number()  const;

    ZcGePoint2d    lowerLeftCorner() const;
    void           setLowerLeftCorner(const ZcGePoint2d& pt);

    ZcGePoint2d    upperRightCorner() const;
    void           setUpperRightCorner(const ZcGePoint2d& pt);

    bool           ucsFollowMode() const;
    void           setUcsFollowMode(bool enabled);

    ZSoft::UInt16  circleSides() const;
    void           setCircleSides(ZSoft::UInt16 circleSides);

	bool           fastZoomsEnabled() const { return true; }
	void           setFastZoomsEnabled(bool enabled) { }

    bool           iconEnabled() const;
    void           setIconEnabled(bool enabled);

    bool           iconAtOrigin() const;
    void           setIconAtOrigin(bool atOrigin);

    bool           gridEnabled() const;
    void           setGridEnabled(bool enabled);

    ZcGePoint2d    gridIncrements() const;
    void           setGridIncrements(const ZcGePoint2d& base);

    bool           snapEnabled() const;
    void           setSnapEnabled(bool enabled);

    bool           isometricSnapEnabled() const;
    void           setIsometricSnapEnabled(bool enabled);

    ZSoft::Int16   snapPair() const;
    void           setSnapPair(ZSoft::Int16 pairType);

    double         snapAngle() const;
    void           setSnapAngle(double angle);

    ZcGePoint2d    snapBase() const;
    void           setSnapBase(const ZcGePoint2d& base);

    ZcGePoint2d    snapIncrements() const;
    void           setSnapIncrements(const ZcGePoint2d& base);

    void           setGsView(ZcGsView* pView);
    ZcGsView*      gsView() const;

    bool           isUcsSavedWithViewport () const;
    void           setUcsPerViewport ( bool ucsvp );
    bool           isGridBoundToLimits() const;
    void           setGridBoundToLimits(bool enabled);

    bool           isGridAdaptive() const;
    void           setGridAdaptive(bool enabled);

    bool           isGridSubdivisionRestricted() const;
    void           setGridSubdivisionRestricted(bool enabled);

    bool           isGridFollow() const;
    void           setGridFollow(bool enabled);

    ZSoft::Int16   gridMajor() const;
    void           setGridMajor(ZSoft::Int16 value);
    Zcad::ErrorStatus   setBackground(const ZcDbObjectId& backgroundId);
    ZcDbObjectId        previousBackground(ZcGiDrawable::DrawableType type
                                           = ZcGiDrawable::kGeometry) const;
    Zcad::ErrorStatus   setPreviousBackground(ZcDbObjectId backgroundId,
                                              ZcGiDrawable::DrawableType type
                                              = ZcGiDrawable::kGeometry);
    ZcGiDrawable*  drawable();
    ZSoft::UInt32  setAttributes(ZcGiDrawableTraits* pTraits);
    ZSoft::Boolean worldDraw(ZcGiWorldDraw* pWd);     
    void           setGsNode(ZcGsNode* pNode);
    ZcGsNode*      gsNode() const;

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class ZcDbRegAppTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbRegAppTableRecord);

    ZcDbRegAppTableRecord();
    virtual ~ZcDbRegAppTableRecord();

    typedef ZcDbRegAppTable TableType;

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class ZcDbDimStyleTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDimStyleTableRecord);

    ZcDbDimStyleTableRecord();
    virtual ~ZcDbDimStyleTableRecord();

    typedef ZcDbDimStyleTable TableType;

    #undef ZDBDIMVAR_H         
    #include "zdbdimvar.h"

    ZcDbObjectId      arrowId(ZcDb::DimArrowFlags whichArrow) const;

    Zcad::ErrorStatus getDimpost(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus getDimapost(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus getDimblk(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus getDimblk1(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus getDimblk2(ZTCHAR*& pOutput) const;

    int dimfit() const;
    int dimunit() const;

    Zcad::ErrorStatus setDimfit(int fit);
    Zcad::ErrorStatus setDimunit(int unit);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
    bool isModifiedForRecompute() const;    
};

#pragma pack(pop)

#endif
