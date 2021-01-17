
#ifndef _ZASECLASS_H
#define _ZASECLASS_H

#include "zasiappl.h"
#include "zaseconst.h"
#include "zdbmain.h"
#include "zadsdef.h"

#define CASEAPPL(x)       ((CAseAppl*)x)
#define CASELINKPATH(x)   ((CAseLinkPath*)x)
#define CASELINK(x)       ((CAseLink*)x)
#define CASELINKSEL(x)    ((CAseLinkSel*)x)

#define ASE_THROW(x)  {((CAseApiObj*)x)->appThrow() ;}
#define WORKINGDWG()  NULL

#pragma pack (push, 8)
#if defined(__cplusplus)

class CAseApiErr ;
class CAseApiObj ;
  class CAseAppl ;
  class CAseLinkPath ;
  class CAseLinkSel ;
  class CAseReactor ;

class CAseApiObj 
{
  public:
                         CAseApiObj(CAseApiObj *pObj) ;
                         CAseApiObj(CAseApiObj &Obj) ;
  virtual                ~CAseApiObj() ;
  virtual EAsiBoolean    init() ;
  virtual EAseApiClassId isA() const = 0 ;
  virtual CAseApiObj    *clone() const = 0 ;
  virtual EAsiBoolean    copyFrom(const CAseApiObj *pObj) ;
  virtual CAseApiObj&    operator=(const CAseApiObj &Obj) ;
  virtual int            operator==(const CAseApiObj *pObj) const = 0 ;
  virtual int            operator==(const CAseApiObj &Obj) const = 0 ;
  virtual EAsiBoolean    isInit() const ;
  const ZTCHAR            *version() const ;
  const CAsiException   *errGet() const ;
  int                    errQty() const ;
  EAseErrDsc             errDsc(int ErrNum) const ;
  int                    errCode(int ErrNum) const ;
  EAsiBoolean            errMsg(int ErrNum,
                                ZTCHAR *pBuf,
                                int BufLen) const;
  EAsiBoolean            errClear() ;
  void                   appThrow() const ;
  const ZTCHAR            *errDiagParNameCode(int ParNum,
                                            int *pParCode,
                                            int *pIsStr) const ;
  EAsiBoolean            errDiagPar(int ErrNum, 
                                    int ParCode,
                                    int *pIntValue) const ;
  EAsiBoolean            errDiagPar(int ErrNum, 
                                    int ParCode,
                                    ZTCHAR *pStrValue,
                                    int BufLen) const ;

  EAsiBoolean            errInitAsi(CAsiException *pErr) ;
  EAsiBoolean            errInitAsi(CAsiSQLObject *pSQLObj) ;
  EAsiBoolean            errInitAsi(CAsiSQLObject &sqlObj) ;

  friend class CAseApiErr ;
  friend class CAseAppl ;
  protected:
  struct resbuf         *getLast(const struct resbuf *bufptr) const ;
  struct resbuf         *allocAttr(EAseLinkAttr attr, const ZTCHAR *pStr=NULL) const ;
  struct resbuf         *copyBuf(const struct resbuf *bufptr, 
                                 const struct resbuf *pBorder=NULL) const ;
  struct resbuf         *nextAttr(const struct resbuf *bufptr) const ;
  struct resbuf         *getAttrType(const struct resbuf *bufptr,
                                     EAseLinkAttr lattr) const ;
  const struct resbuf   *getAttrPtr(const struct resbuf *bufptr,
                                    EAseLinkAttr lattr) const ;
  EAsiBoolean            setAttrPtr(struct resbuf *bufptr,
                                    EAseLinkAttr LinkAttr,
                                    struct resbuf *pAttrValue) const ;
  struct resbuf         *delAttrPtr(struct resbuf *bufptr,
                                    struct resbuf *pAttr) const ;
  EAsiBoolean            parseLisp(struct resbuf *bufptr) ;
  CAseAppl              *getAppl() const ;
  void                   freeStr(struct resbuf *pBuf) const ;
  EAsiBoolean            isDiffChar() const ;

  void                  *mpErr ;       
} ;

class CAseAppl : public CAseApiObj 
{
  public:
                         CAseAppl(CAseApiObj *pObj=NULL) ;
                         CAseAppl(CAseApiObj &Obj) ;
  virtual                ~CAseAppl() ;
  virtual EAsiBoolean    init() ;
  virtual EAseApiClassId isA() const ;
  virtual CAseApiObj    *clone() const ;
  virtual EAsiBoolean    copyFrom(const CAseApiObj *pObj) ;
  virtual CAseApiObj&    operator=(const CAseApiObj &Obj) ;
  virtual int            operator==(const CAseApiObj *pObj) const ;
  virtual int            operator==(const CAseApiObj &Obj) const ;
  virtual EAsiBoolean    isInit() const ;
  void                   term() ;

  LPCTSTR                 getZcadDsPath();

  EAsiBoolean            getAseErr() ;
    
  EAsiBoolean            clearAseErr();

  CAsiSession*           connectAse(CAsiAppl *pAppl,
                                    const TCHAR *pEnvName,
                                    const ZTCHAR *pUserName=NULL,
                                    const ZTCHAR *pPassWord=NULL,
									EAsiBoolean fPrompt = kAsiFalse) ;

  EAsiBoolean            isIndexExist(ZcDbDatabase *pDwg=NULL);                                  
  EAsiBoolean            isIndexUpToDate(ZcDbDatabase *pDwg=WORKINGDWG());
    
  EAsiBoolean            createIndex(ZcDbDatabase *pDwg=WORKINGDWG());
    
  EAsiBoolean            removeIndex(ZcDbDatabase *pDwg=WORKINGDWG());

  int					 setIndexSaveMode (int mode);
  
  EAsiBoolean            openDwg(ZcDbDatabase *pDwg=WORKINGDWG()) ;
  EAsiBoolean            openLazyDwg(ZcDbDatabase *pDwg=WORKINGDWG()) ;
  EAsiBoolean            isDwgOpened(ZcDbDatabase *pDwg=WORKINGDWG()) ;
  EAsiBoolean            isDwgLazyOpened(ZcDbDatabase *pDwg=WORKINGDWG()) ;
  EAsiBoolean            closeDwg(ZcDbDatabase *pDwg=WORKINGDWG()) ;

  EAsiBoolean            swapEntIds(ZcDbObjectId objectId, 
                                    ZcDbObjectId otherId,
                                    ZcDbDatabase *pDwg=WORKINGDWG());

  EAsiBoolean            swapBTRIds(ZcDbObjectId blockId, 
                                    ZcDbObjectId otherId,
                                    ZcDbDatabase *pDwg=WORKINGDWG());

  EAsiBoolean            loadLinks(ZcDbEntity *pObj);
  EAsiBoolean            loadLinks(ZcDbObjectId objId);
  EAsiBoolean            translateDataSource(DatasourceTranslationCode xCode,
                                             unsigned int buflen,
                                             const ZTCHAR * szFromEnv,
                                             const ZTCHAR * szFromCat,
                                             const ZTCHAR * szFromSchema,
                                             const ZTCHAR * szFromTable,
                                             const ZTCHAR * szFromLpn,
                                             ZTCHAR * szToEnv,
                                             ZTCHAR * szToCat,
                                             ZTCHAR * szToSchema,
                                             ZTCHAR * szToTable,
                                             ZTCHAR * szToLpn);

  EAsiBoolean           beginAseTransaction();
  EAsiBoolean           commitAseTransaction();
  EAsiBoolean           abortAseTransaction();
 
  typedef enum {
      kTransAutomatic = 0,      
      kTransUserManaged,        
  } ETransactionMode;

  void                  setAseTransactionMode( ETransactionMode eMode );
  ETransactionMode      getAseTransactionMode();

  protected:

  struct resbuf *        aseiCallAse(int funCode,
                                     struct resbuf* pParms,
                                     void *pErr,
                                     void *pZcDbDatabase=NULL,
                                     EAsiBoolean needFullOpen=kAsiFalse)  ;

  struct resbuf *        ase_invoke(int funCode,
                                    struct resbuf* pParms,
                                    void *pErr,
                                    void *pAse)  ;
  struct resbuf *        ase_fromAse(struct resbuf *pBuf) ;
  EAsiBoolean            ase_toAse(struct resbuf *pBuf) ;
  EAsiBoolean            addObj(const CAseApiObj *pObj) ;
  EAsiBoolean            remObj(const CAseApiObj *pObj) ;

  EAsiBoolean            mapErrFromAse(void *pAse, void *pErr);
  
  friend class CAseApiObj ;
  friend class CAseLinkPath ;
  friend class CAseLink ;
  friend class CAseLinkSel ;
  friend class CAseApiErr ;
  TCHAR                  *mpVersion ;
  void                  *mpRes ;        
  void                  *mpObjs ;       
  EAsiBoolean            mIsDiffChar ;  
                                        
  TCHAR                  *mpDefChar ;
                                        
  ETransactionMode      meTransMode;

} ;

class CAseLinkPath : public CAseApiObj
{
  public:
                         CAseLinkPath(CAseApiObj *pObj) ;
                         CAseLinkPath(CAseApiObj &Obj) ;
  virtual                ~CAseLinkPath() ;
  virtual EAsiBoolean    init() ;
  virtual EAseApiClassId isA() const ;
  virtual CAseApiObj    *clone() const ;
  virtual EAsiBoolean    copyFrom(const CAseApiObj *pObj) ;
  virtual CAseApiObj&    operator=(const CAseApiObj &Obj) ;
  virtual int            operator==(const CAseApiObj *pObj) const ;
  virtual int            operator==(const CAseApiObj &Obj) const ;
  virtual EAsiBoolean    isInit() const ;

  EAsiBoolean            initPath(const ZTCHAR *pPath) ;
  EAsiBoolean            initName(const ZTCHAR *pName) ;
  EAsiBoolean            initCurrent() ;
  EAsiBoolean            reInit();
  EAsiBoolean            setName(const ZTCHAR *pName,
                                 EAseDoNameCode NameCode=kAseLpnCode) ;
  EAsiBoolean            getName(ZTCHAR *pBuf, int BufLen,
                                 EAseDoNameCode NameCode=kAseLpnCode) const ;
  int                    getNameSize(EAseDoNameCode NameCode=kAseLpnCode) const;
  int                    cmpName(const ZTCHAR *pName,
                                 EAseDoNameCode NameCode=kAseLpnCode) const ;
  int                    cmpName(const CAseLinkPath *pLinkPath, 
                                 EAseDoNameCode NameCode=kAseLpnCode) const ;
  EAseDoNameCode         getPathCode() const;
  int                    getStatus() const;
  EAsiBoolean            isUpdatable() const ;
  EAsiBoolean            getKeyDsc(CAsiRow **pKeyDsc) const;
  EAsiBoolean            getKeyDsc(CAsiColumn **pKeyDsc[], int *pColQty) const;
  EAsiBoolean            create(const CAsiRow *pKeyDsc) ;
  EAsiBoolean            create(const CAsiRow &KeyDsc) ;
  EAsiBoolean            create(const CAsiColumn *pKeyDsc[], int ColQty) ;
  EAsiBoolean            erase() ;
  EAsiBoolean            rename(const ZTCHAR *pLinkPathName) ;
  EAsiBoolean            setCurrent() const ;
  struct resbuf         *getLinkNames() const ;
  struct resbuf         *getPaths(int Status) const ;

  EAsiBoolean            connectAse(const ZTCHAR *pUsername=NULL,
                                    const ZTCHAR *pPassword=NULL,
									EAsiBoolean fPrompt=kAsiFalse) ;

  EAsiBoolean            connectAseIniString (const ZTCHAR *pIniString);

  EAsiBoolean            disconnectAse();

  EAsiBoolean            checkOp(ulong status) const;

  EAsiBoolean            getTableDsc(CAsiRow **pColumns) const;  
  EAsiBoolean            getTableDsc(CAsiColumn **pKeyDsc[], 
                                     int *pColQty) const;
    
  EAsiBoolean            createTable(const CAsiRow *pCols);
  EAsiBoolean            createTable(const CAsiColumn *pCols[],
                                     int colNum);
    
  EAsiBoolean            dropTable();

  EAsiBoolean            updRow(const CAsiRow *pKey,
                                const CAsiRow *pValue,
                                long *pRowsQty=NULL) const;
  EAsiBoolean            updRow(const CAsiColumn *pKey[],
                                int numKeys,
                                const CAsiColumn *pValue[],
                                int numValues,
                                long *pRowsQty=NULL) const;
    
  EAsiBoolean            delRow(const CAsiRow *pValue,
                                long *pRowsQty=NULL) const;
  EAsiBoolean            delRow(const CAsiColumn *pValue[],
                                int numKeys,
                                long *pRowsQty=NULL) const;
    
  EAsiBoolean            addRow(const CAsiRow *pValue) const;
  EAsiBoolean            addRow(const CAsiColumn *pValue[],
                                int numValues) const;

  EAsiBoolean            getRow(const CAsiRow *pKeyValue,
                                CAsiRow *pRowBuffer) const;

  EAsiBoolean            setDwg(const ZcDbDatabase *pDwg=WORKINGDWG()) ;

  const ZcDbDatabase*    getDwg() const ;

  EAsiBoolean            allocCursor(const CAsiRow *pKeyDsc,
                                     const CAsiRow *pRow,
                                     long *pCursorNum) const;

  EAsiBoolean            getCursorRow(long cursorNum,
                                      const CAsiRow *pKeyValue,
                                      CAsiRow *pRow) const;                           
    
  EAsiBoolean            delCursor(long cursorNum) const;

  protected:
  void                   *mpPath ;    
  void                   *mpDwg ;     
} ;

class CAseLink : public CAseApiObj
{
  public:
                         CAseLink(CAseApiObj *pObj) ;
                         CAseLink(CAseApiObj &Obj) ;
  virtual                ~CAseLink() ;
  virtual EAsiBoolean    init() ;
  EAsiBoolean            initType(EAseLinkType lType) ;
  EAsiBoolean            initId(LinkID linkId) ;
  EAsiBoolean            initEnt(const ZTCHAR *pName,
                                 const CAsiRow *pKeyValue, 
                                 zds_name EntName) ;
  EAsiBoolean            initEnt(const ZTCHAR *pName,
                                 const CAsiRow &KeyValue, 
                                 zds_name EntName) ;
  EAsiBoolean            initEnt(const ZTCHAR *pName,
                                 const CAsiColumn *pKeyValue[],
                                 int ColQty,
                                 zds_name EntName) ;
  EAsiBoolean            initDA(const ZTCHAR *pName,
                                const CAsiRow *pKeyValue,
                                const CAsiRow *pDACols,
                                const struct resbuf *pDAParms) ;
  EAsiBoolean            initDA(const ZTCHAR *pName,
                                const CAsiRow &KeyValue,
                                const CAsiRow &DACols,
                                const struct resbuf *pDAParms) ;
  EAsiBoolean            initDA(const ZTCHAR *pName,
                                const CAsiColumn *pKeyValue[],
                                int ColQty,
                                const CAsiColumn *pDACols[],
                                int DAColQty,
                                const struct resbuf *pDAParms) ;
  virtual EAseApiClassId isA() const ;
  virtual CAseApiObj    *clone() const ;
  virtual EAsiBoolean    copyFrom(const CAseApiObj *pObj) ;
  virtual CAseApiObj&    operator=(const CAseApiObj &Obj) ;
  virtual int            operator==(const CAseApiObj *pObj) const ;
  virtual int            operator==(const CAseApiObj &Obj) const ;
  virtual EAsiBoolean    isInit() const ;

  LinkID                 getId () const ;
  EAseLinkType           getType() const ;
  EAsiBoolean            getName(ZTCHAR *pBuf, int len) const;
  int                    getNameSize() const ;
  EAsiBoolean            setName(const ZTCHAR *pName) ;
  EAsiBoolean            getEntity(zds_name EntName) const ;
  EAsiBoolean            setEntity(zds_name EntName) ;
  EAsiBoolean            getKey(CAsiRow *pKeyValue) const ;
  EAsiBoolean            getKey(CAsiRow &KeyValue) const ;
  EAsiBoolean            getKey(CAsiColumn *pKeyValue[], int ColQty) const ;
  EAsiBoolean            setKey(const CAsiRow *pKeyValue) ;
  EAsiBoolean            setKey(const CAsiRow &KeyValue) ;
  EAsiBoolean            setKey(const CAsiColumn *pKeyValue[], int ColQty) ;
  EAsiBoolean            setDACols (const CAsiRow *pCols) ;
  EAsiBoolean            setDACols (const CAsiRow &Cols) ;
  EAsiBoolean            setDACols(CAsiColumn *pCols[], int ColQty) ;
  EAsiBoolean            getDACols (CAsiRow **pCols) const ;
  EAsiBoolean            getDACols(CAsiColumn **pCols[], int *pColQty) const ;
  EAsiBoolean            setDAParms(const struct resbuf *pParms) ;
  EAsiBoolean            setDAValues(const CAsiRow *pDAValues) ;
  EAsiBoolean            setDAValues(const CAsiRow &DAValues) ;
  EAsiBoolean            setDAValues(CAsiColumn *pCols[], int ColQty) ;
  EAsiBoolean            create () ;
  EAsiBoolean            remove () ;
  EAsiBoolean            update () ;
  EAsiBoolean            getXName(ZTCHAR *pBuf, int len) const ;
  EAsiBoolean            isUpdatable() const ;

  EAsiBoolean            setDwg(const ZcDbDatabase *pDwg=WORKINGDWG()) ;

  const ZcDbDatabase*    getDwg() const ;

  struct resbuf         *getAttr(EAseLinkAttr LinkAttr) const ;
  EAsiBoolean            setAttr(EAseLinkAttr LinkAttr,
                                 const struct resbuf *pAttrValue) ;
  private:
  struct resbuf      *mpBuf ;    
  void               *mpDwg ;     
} ;

class CAseLinkSel : public CAseApiObj 
{
  public:
                         CAseLinkSel(CAseApiObj *pObj) ;
                         CAseLinkSel(CAseApiObj &Obj) ;
  virtual                ~CAseLinkSel() ;
  virtual EAsiBoolean    init() ;
  EAsiBoolean            initType(EAseLinkType LinkType) ;
  EAsiBoolean            initSel(zds_name EntSelName,
                                 EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initEnt(zds_name EntName,
                                 EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initXName(const ZTCHAR *pXName,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLp(const ZTCHAR *pName,
                                EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLp(const CAseLinkPath *pLinkPath,
                                EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLp(const CAseLinkPath &LinkPath,
                                EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpEnt(const ZTCHAR *pName,
                                   zds_name EntName,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpEnt(const CAseLinkPath *pLinkPath,
                                   zds_name EntName,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpEnt(const CAseLinkPath &LinkPath,
                                   zds_name EntName,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpKey(const ZTCHAR *pName,
                                   const CAsiRow *pKeyValue,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpKey(const ZTCHAR *pName,
                                   const CAsiRow &KeyValue,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpKey(const CAseLinkPath *pLinkPath, 
                                   const CAsiRow *pKeyValue,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpKey(const CAseLinkPath &LinkPath, 
                                   const CAsiRow &KeyValue,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpKey(const ZTCHAR *pName,
                                   const CAsiColumn *pKeyValue[],
                                   int ColQty,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpKey(const CAseLinkPath *pLinkPath, 
                                   const CAsiColumn *pKeyValue[],
                                   int ColQty,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpCond(const ZTCHAR *pName,
                                    const ZTCHAR *pTextCondition,
                                    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpCond(const CAseLinkPath *pLinkPath, 
                                    const ZTCHAR *pTextCondition,
                                    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpCond(const CAseLinkPath &LinkPath, 
                                    const ZTCHAR *pTextCondition,
                                    EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpSel(const ZTCHAR *pName,
                                   zds_name EntSelName,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpSel(const CAseLinkPath *pLinkPath, 
                                   zds_name EntSelName,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initLpSel(const CAseLinkPath &LinkPath, 
                                   zds_name EntSelName,
                                   EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initPartialKey(const ZTCHAR *pName,
                                        const CAsiRow *pKeyValue,
                                        EAseLinkType LinkType=kAseUnknownLinkType) ;
  EAsiBoolean            initPartialKey(const CAseLinkPath *pLinkPath, 
                                        const CAsiRow *pKeyValue,
                                        EAseLinkType LinkType=kAseUnknownLinkType) ;

  virtual EAseApiClassId isA() const ;
  virtual CAseApiObj    *clone() const ;
  virtual EAsiBoolean    copyFrom(const CAseApiObj *pObj) ;
  virtual CAseApiObj&    operator=(const CAseApiObj &Obj) ;
  virtual int            operator==(const CAseApiObj *pObj) const ;
  virtual int            operator==(const CAseApiObj &Obj) const ;
  virtual EAsiBoolean    isInit() const ;
  EAsiBoolean            isUpdatable() const ;

  long                   getQty() const ;
  LinkID                 getId(long ItemNum) const ;
  EAsiBoolean            addId(LinkID linkId) ;
  EAsiBoolean            delId(long ItemNum) ;
  long                   membId(LinkID linkId) const ;
  
  EAsiBoolean            unite(const CAseLinkSel *pSel) ;
  EAsiBoolean            unite(const CAseLinkSel &Sel) ;
  EAsiBoolean            subtract(const CAseLinkSel *pSel) ;
  EAsiBoolean            subtract(const CAseLinkSel &Sel) ;
  EAsiBoolean            intersect(const CAseLinkSel *pSel) ;
  EAsiBoolean            intersect(const CAseLinkSel &Sel) ;

  EAsiBoolean            intersectType(EAseLinkType LinkType) ;
  EAsiBoolean            intersectEnt(zds_name EntName) ;
  EAsiBoolean            intersectSel(zds_name EntSelName) ;
  EAsiBoolean            intersectXName(const ZTCHAR *pXName) ;
  EAsiBoolean            intersectLp(const ZTCHAR *pName) ;
  EAsiBoolean            intersectLp(const CAseLinkPath *pLinkPath) ;
  EAsiBoolean            intersectLp(const CAseLinkPath &LinkPath) ;
  EAsiBoolean            intersectLpKey(const ZTCHAR *pName,
                                        const CAsiRow *pKeyValue) ;
  EAsiBoolean            intersectLpKey(const ZTCHAR *pName,
                                        const CAsiRow &KeyValue) ;
  EAsiBoolean            intersectLpKey(const CAseLinkPath *pLinkPath, 
                                        const CAsiRow *pKeyValue) ;
  EAsiBoolean            intersectLpKey(const CAseLinkPath &LinkPath, 
                                        const CAsiRow &KeyValue) ;
  EAsiBoolean            intersectLpKey(const ZTCHAR *pName,
                                        const CAsiColumn *pKeyValue[],
                                        int ColQty) ;
  EAsiBoolean            intersectLpKey(const CAseLinkPath *pLinkPath, 
                                        const CAsiColumn *pKeyValue[],
                                        int ColQty);
  EAsiBoolean            intersectLpCond(const ZTCHAR *pName,
                                         const ZTCHAR *pTextCondition) ;
  EAsiBoolean            intersectLpCond(const CAseLinkPath *pLinkPath, 
                                         const ZTCHAR *pTextCondition) ;
  EAsiBoolean            intersectLpCond(const CAseLinkPath &LinkPath, 
                                         const ZTCHAR *pTextCondition) ;

  EAsiBoolean            intersectPartialKey(const ZTCHAR *pName,
                                             const CAsiRow *pKeyValue) ;
  EAsiBoolean            intersectPartialKey(const CAseLinkPath *pLinkPath, 
                                             const CAsiRow *pKeyValue) ;

  EAsiBoolean            getLinkName(long ItemNum,
                                     TCHAR *pNameBuf,
                                     int nameBufLen) const;

  EAsiBoolean            getLinkKey(long ItemNum, CAsiRow *pKeyValue);

  EAsiBoolean            getLinkEnt(long ItemNum, zds_name ename);

  int                    getIdArray(ZcDbObjectIdArray *pLinkedEntities) const;

  EAsiBoolean            getLinkEnt(long ItemNum, ZcDbObjectId *pId);

  EAsiBoolean            setDwg(const ZcDbDatabase *pDwg=WORKINGDWG()) ;

  const ZcDbDatabase*    getDwg() const ;

  struct resbuf         *getXNames() const ;
  struct resbuf         *getLinkNames() const ;
  EAsiBoolean            getEntSel(zds_name EntSelName) const ;
  EAsiBoolean            erase() ;

  virtual EAsiBoolean    initFilter(struct resbuf *pLinkFilter,
                                    EAsiBoolean needFullOpen=kAsiFalse) ;

  virtual EAsiBoolean    intersectFilter(const struct resbuf *pLinkFilter) ;

  protected:
  void                   freeSel() ;
  struct resbuf         *makeFilter(EAseLinkType LinkType,
                                    const ZTCHAR *pXName,
                                    zds_name EntName,
                                    zds_name EntSelName,
                                    const ZTCHAR *pName,
                                    const CAseLinkPath *pLinkPath,
                                    const CAsiRow *pKeyValue,
                                    const ZTCHAR *pTextCondition,
                                    const CAsiRow *pParKeyValue = NULL) ;

  LinkSelID              mSelId ;    
  void                   *mpDwg ;     
} ;

#endif 
#pragma pack (pop)
#endif 

