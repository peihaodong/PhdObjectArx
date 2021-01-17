

#ifndef ZASI_ASICLASS_HH
#define ZASI_ASICLASS_HH asiclasshh

#include "zasisdata.h"

#include "zavoidtry.h" 

#define ASI_TRY           { CAsiExceptionHandler AsiExceptionHandler; try {  

#define ASI_CATCH(x)      } catch(CAsiException* x) { x=x;

#define ASI_END_CATCH     }}
#define ASI_THROW(x)      AsiExceptionThrow(x);
#define ASI_THROW_LAST    AsiExceptionThrow(0);

#pragma pack (push, 8)

class DLLScope CAsiObject;                  
    class CAsiHostBuffer;                   
        class CAsiParameter;                
  
    class CAsiException;                    

    class CAsiSQLObject;                    
        class CAsiSession;                  
        class CAsiStm;                      
            class CAsiExecStm;              
			class CAsiCsr;                  
				class CAsiCsrTable;         
					class CAsiCsrRegTable;  
					class CAsiCsrInfSchema; 
					class CAsiEnumerator;   
        class CAsiBinding;                  

	class CAsiDSProperties;
class CAsiTACond;
class CAsiTCCond;

class CAsiExceptionHandler;                 

typedef enum {
    kOpNodeUndefined = 0,

    kOpNot,                     
    kOpOr,                      
    kOpAnd,                     
    kOpTest,

    kOpNull,                    
    kOpGtr,                     
    kOpGeq,                     
    kOpEq,                      
    kOpLeq,                     
    kOpLss,                     
    kOpNeq                      
} EAsiCompType;

class CAsiExceptionHandler

{
public:

    CAsiExceptionHandler(void);
    ~CAsiExceptionHandler(void);

    CAsiException*        pException;
    CAsiExceptionHandler* pPrevHandler;
    EAsiBoolean           wasThrown;
};

class CAsiException : public CAsiObject

{
	friend class CAsiSQLObject;
public:
    
							CAsiException (void);
    virtual					~CAsiException (void);

    int						CondQty    (void) const;       
    AsiError				Err        (int d = 0) const;  
    CAsiUcStr		*		ErrMsg     (int d = 0) const;  
    char			*		SQLSTATE   (int d = 0) const;  

	int						ErrPosition (void) const;

    EAsiBoolean				getDiagPar (int, AsiDiag, integer *) const;
    EAsiBoolean				getDiagPar (int, AsiDiag, CAsiUcStr *) const;

    EAsiBoolean				setErr      (AsiError);           
    EAsiBoolean				setErrMsg   (const CAsiUcStr &);  
    EAsiBoolean				setSQLSTATE (const char *);

    EAsiBoolean				setDiagPar	(AsiDiag, integer);
    EAsiBoolean				setDiagPar	(AsiDiag, const CAsiUcStr &);

    EAsiBoolean				pushCond	(void);       
    EAsiBoolean				flushCond	(void);

    void			*  		getDiagData (void) const;
	void					setErrPosition (int);

    virtual CAsiObject *	duplicate	(void) const;         

private:
    void		*			pExceptionBody;
};

class CAsiSQLObject : public CAsiObject

{
friend class CAsiCsr;
friend class CAsiExecStm;
friend class CAsiBinding;
public:

protected:
                                CAsiSQLObject   ();
                                            
protected:
    virtual EAsiBoolean         setErr      (EAsiError);           
    virtual EAsiBoolean         setErrMsg   (const CAsiUcStr &);  
    virtual EAsiBoolean         setSQLSTATE (const char *);

    virtual EAsiBoolean         setDiagPar (EAsiDiag, integer);
    virtual EAsiBoolean         setDiagPar (EAsiDiag, const CAsiUcStr &);

    virtual EAsiBoolean			pushCond   (void);       
    virtual EAsiBoolean			flushCond  (void); 

    virtual EAsiBoolean			pushErr    (EAsiError);     
    virtual EAsiBoolean			pushHResult(HRESULT);		

public:
    virtual                     ~CAsiSQLObject  ();

    EAsiStatement               StmType         (void) const;    
    LONG_PTR                    RowCount        (void) const;

    virtual EAsiBoolean         IsRowset        (void) const;

    virtual int                 ErrPosition     (void) const;

    virtual int                 CondQty         (void) const;       
    virtual EAsiError           Err             (int d = 0) const;  
    virtual CAsiUcStr       *   ErrMsg          (int d = 0);        
    virtual char            *   SQLSTATE        (int d = 0);

    virtual EAsiBoolean         getDiagPar      (int d,       
                                                EAsiDiag,
                                                integer *) const;
    virtual EAsiBoolean         getDiagPar      (int d,       
                                                EAsiDiag,
                                                CAsiUcStr *) const;

    EAsiBoolean                 DBMS            (CAsiUcStr *) const;            
    EAsiBoolean                 SQLObject       (CAsiUcStr *) const;            
    EAsiBoolean                 DrvMessage      (CAsiUcStr *) const;            
    EAsiBoolean                 CheckOp         (ulong);                     
    virtual EAsiBoolean         GetStatus       (EAsiStatInfo, ULONG_PTR *);

    const char             *    Version         (void) const;

protected:
    EAsiBoolean                 isInit      (void) const;
    EAsiBoolean                 InitErrorInfo (HRESULT, IUnknown *, GUID);
    void                        ReleaseErrorInfo ();
	void						InheritStatusInfo (const CAsiSQLObject &);

protected:
    
    IErrorInfo          *       m_pIErrorInfo;      
    HRESULT                     m_HResult;

private:

    static const char   *       m_pAsiVersion;
    CAsiException               m_Except;

protected:
    EAsiBoolean                 m_CSP;

protected:
    EAsiStatement               m_eStmType;
	LONG_PTR                m_lRowCount;

	CAsiDSProperties	   *	m_pDSProperties;

};

class CAsiAppl: public CAsiSQLObject
{
friend class CAsiSession;
friend class CAsiEnumerator;
friend class CAsiCsr;
public:

                                CAsiAppl        ();  
      virtual                   ~CAsiAppl       ();

      EAsiBoolean               Init            (void);  
      EAsiBoolean               Term            (void);  
      EAsiBoolean               Abort           (void);  
      EAsiBoolean               DisconnectAll   (void);  

protected:
      EAsiBoolean               addConnection   (CAsiSession *);
      EAsiBoolean               removeConnection(CAsiSession *);

private: 
      EAsiBoolean               rollbackAll     (void);

private:
	  IClassFactory		*		m_pIClassFactory;		
	  IDataInitialize	*		m_pIDataInitialize;		
	  IDataConvert		*		m_pIDataConvert;		
      CAsiObject        *       m_pSessions;            
};

class CAsiSession: public CAsiSQLObject
{
friend class CAsiStm;
friend class CAsiCsr;
friend class CAsiExecStm;
friend class CAsiAppl;
friend class CAsiCsrTable;
friend class CAsiCsrInfSchema;
friend class CAsiCsrRegTable;
public:

                            CAsiSession         (CAsiAppl *);
    virtual                 ~CAsiSession        ();

    EAsiBoolean             Connect             (const CAsiUcStr & LinkFile, 
                                                 const CAsiUcStr & Username,
                                                 const CAsiUcStr & Password,
												 EAsiBoolean	   fPrompt = kAsiFalse);

	EAsiBoolean				ConnectIniString	(const CAsiUcStr & IniString);

	EAsiBoolean				GetConnectionString (CAsiUcStr *);
    EAsiBoolean             Disconnect          (void);

    EAsiBoolean             SetCatalog          (const CAsiUcStr &);
    EAsiBoolean             SetSchema           (const CAsiUcStr &);
    EAsiBoolean             SetNames            (const CAsiUcStr &);
    EAsiBoolean             SetTimeZone         (const CAsiDT &);
    EAsiBoolean             SetTimeZone         (void);          
    EAsiBoolean             SetAuthor           (const CAsiUcStr &);

    EAsiBoolean             SetTrans            (EAsiTILevel, EAsiTMode, uint dSize = 64);  
    EAsiBoolean             DeferrConstr        (CAsiIdent * cnst = 0);   
    EAsiBoolean             ImmConstr           (CAsiIdent * cnst = 0);   

    EAsiBoolean             Commit              (void);                   
    EAsiBoolean             Rollback            (void);

    const CAsiUcStr      &  Name                (void) const;             
    virtual EAsiBoolean     GetStatus			(EAsiStatInfo, ULONG_PTR *);

protected:
    EAsiBoolean             Disconnect          (CAsiObject *);
	EAsiBoolean				GetCatalog			(CAsiUcStr *);

private:
    virtual CAsiObject  *   duplicate           (void) const;             
	EAsiBoolean				CreateSession		(IDBInitialize *);

    EAsiBoolean             Execute             (const CAsiUcStr &);      

	EAsiBoolean				CheckForNotNull		(EAsiInfSchTab, int);
	EAsiBoolean				CanRetrieveCatalogs	(void);
	EAsiBoolean				CanRetrieveSchemas	(void);
	void					GetProviderTypes	(void);
	EAsiBoolean				GetStatusInfo 		();

	void					AttachStm			(CAsiExecStm *);
	void					DetachStm			(CAsiExecStm *);
	void					DetachAllStm 		(void);
	void					DeallocateAllStm	(void);

	void					AttachCsr			(CAsiCsr *);
	void					DetachCsr 			(CAsiCsr *);
	void					DetachAllCsr 		(void);

	EAsiBoolean				HasOpenedObjects	(void);

private: 
    CAsiAppl            *   m_pAppl;                    
    CAsiUcStr               m_LinkFileName ;			
	CAsiUcStr				m_ConnectionString;			
    IUnknown            *   m_pISession;                
	CAsiUcStr				m_ucCatalog;	   			

    ULONG                   m_BLOBStorage;              

	CAsiList			*	m_pStms;					
	CAsiList			*	m_pCsrs;					
};

class CAsiStm: public CAsiSQLObject

{
friend class CAsiSession;

public:

                                CAsiStm         (void);
    virtual                     ~CAsiStm        (void);

            void                SetSession      (CAsiSession *);

    virtual int                 ParamQty        (void) const; 
    virtual CAsiParameter   *   ParamDsc        (int) const;

    virtual EAsiBoolean         Bind            (int, CAsiData *);    
    virtual EAsiBoolean         Bind            (int, void *, short *,
                                                 int, EAsiHostType);

    virtual EAsiBoolean         Bind            (const CAsiIdent &, CAsiData *); 
    virtual EAsiBoolean         Bind            (const CAsiIdent &, void *, short *,
                                                 int, EAsiHostType);

    virtual int                 ColQty          (void) const;      
    virtual CAsiColumn *        ColDsc          (int) const;

    virtual EAsiBoolean         Sob             (int, CAsiData *);    
    virtual EAsiBoolean         Sob             (int, void *, short *,
                                                 int, EAsiHostType);

    virtual EAsiBoolean         Cvl             (int, CAsiData *);    
    virtual EAsiBoolean         Cvl             (int, void *, short *,
                                                 int, EAsiHostType);

protected:
    EAsiBoolean                 CvlInt          (int, CAsiData *) const;    
    EAsiBoolean                 pInput          (void);
	EAsiBoolean					InitColsDsc		();

protected:
    CAsiBinding             *   m_pInput;		
    CAsiBinding             *   m_pOutput;		

    CAsiSession             *   m_pSession;

    ULONG_PTR                   m_lColNumber;
    DBCOLUMNINFO            *   m_pColumnInfo;
    OLECHAR                 *   m_pStringBuff;
    CAsiRow                 *   m_pAsiRow;

};

class CAsiExecStm: public CAsiStm

{
friend class CAsiCsr;
friend class CAsiSession;
public:

                                CAsiExecStm         (void);
    virtual                     ~CAsiExecStm        (void);

    virtual EAsiBoolean         IsRowset            (void) const;

    virtual EAsiBoolean         Prepare             (CAsiSession *, 
                                                     const CAsiUcStr &, 
                                                     EAsiBoolean trans = kAsiTrue);
    virtual EAsiBoolean         Deallocate          (void);

    virtual EAsiBoolean         Execute             (void);
    virtual EAsiBoolean         ImmediateExecute    (CAsiSession *, 
                                                     const CAsiUcStr &,
                                                     EAsiBoolean trans = kAsiTrue);
    EAsiBoolean					Cancel              (void);

    virtual int                 ParamQty            (void) const; 
    virtual CAsiParameter   *   ParamDsc            (int) const;  

    virtual EAsiBoolean         Bind                (int, CAsiData *);
    virtual EAsiBoolean         Bind                (int, void *, short *, int, EAsiHostType);
    virtual EAsiBoolean         Bind                (const CAsiIdent &, CAsiData *);
    virtual EAsiBoolean         Bind                (const CAsiIdent &, void *, short *, int, EAsiHostType);

    virtual int                 ColQty              (void) const;
    virtual CAsiColumn *        ColDsc              (int) const; 

    virtual EAsiBoolean			GetStatus			(EAsiStatInfo, ULONG_PTR *);

private:
    virtual CAsiObject      *   duplicate           (void) const;

    EAsiBoolean                 Prepare             (void);

	EAsiBoolean					IsPrepared			(void) const;
	void						AttachCsr			(CAsiCsr *);
	void						DetachCsr			(CAsiCsr *);
	void						DetachAllCsr 		(void);
	void						CloseAllCsr			(void);

protected:
    ICommandText            *   m_pICommand;

    ULONG                       m_lParNumber;
    DBPARAMINFO             *   m_pParamInfo;
    OLECHAR                 *   m_pStringBuffParam;

	CAsiList				*	m_pCsrs;
};  

class CAsiCsr: public CAsiStm
{
friend class CAsiExecStm;
public:

                                CAsiCsr             (void);
    virtual                     ~CAsiCsr            (void);

    EAsiBoolean                 Allocate            (CAsiExecStm * csrspec,      
                                                     const CAsiIdent & csrname, 
                                                     EAsiCurScr sc = kAsiNonScroll,     
                                                     EAsiCurSns sn = kAsiSnsUndef,      
                                                     EAsiBoolean upd = kAsiUnknown,		
													 EAsiBoolean fIns = kAsiFalse);

    virtual int                 ParamQty            (void) const; 
    virtual CAsiParameter   *   ParamDsc            (int) const;  

    virtual EAsiBoolean         Bind                (int, CAsiData *);
    virtual EAsiBoolean         Bind                (int, void *, short *, int, EAsiHostType);
    virtual EAsiBoolean         Bind                (const CAsiIdent &, CAsiData *);
    virtual EAsiBoolean         Bind                (const CAsiIdent &, void *, short *, int, EAsiHostType);

    virtual EAsiBoolean         Sob                 (int, CAsiData *);
    virtual EAsiBoolean         Sob                 (int, void *, short *, int, EAsiHostType);

    virtual EAsiBoolean         Open                (void);     
    virtual EAsiBoolean         Close               (void);     
    EAsiBoolean					Cancel              (void);

    virtual EAsiBoolean         Fetch               (void);     
    virtual EAsiBoolean         FetchPrior          (void);     
    virtual EAsiBoolean         FetchFirst          (void);     
    virtual EAsiBoolean         FetchLast           (void);     
    virtual EAsiBoolean         FetchRelative       (long);     
    virtual EAsiBoolean         FetchAbsolute       (long);     
    virtual EAsiBoolean         CheckCCondition     (CAsiData **);

    CAsiRow             *       getCurrentRow       (void);

    virtual EAsiBoolean         Delete              (void);            
    virtual EAsiBoolean         Update              (const CAsiRow &);

	virtual EAsiBoolean			Insert				(const CAsiRow &);
	virtual EAsiBoolean			Insert				(void);			   

    virtual int                 ColQty              (void) const;
    virtual CAsiColumn *        ColDsc              (int) const; 

    virtual EAsiBoolean         Cvl                 (int, CAsiData *);
    virtual EAsiBoolean         Cvl                 (int, void *, short *,
                                                     int, EAsiHostType);

    virtual EAsiBoolean			GetStatus			(EAsiStatInfo, ULONG_PTR *);
    virtual EAsiBoolean         IsRowset            (void) const;
    virtual EAsiBoolean         is_updatable        (void) const;       
    virtual EAsiBoolean         is_insertable       (void) const;       
    virtual EAsiBoolean         is_scrollable       (void) const;       
    virtual EAsiBoolean         is_insensitive      (void) const;       
    virtual EAsiBoolean         is_open             (void) const;       
    virtual EAsiCurPos          position            (void) const;       

private:
    virtual CAsiObject  *       duplicate           (void) const;

protected:
    EAsiBoolean                 InitOutputBind      ();
    EAsiBoolean                 MakeCursorProp      (DBPROPSET  * pRowsetPropSet);
    EAsiBoolean                 QueryCursorProp     (void);
    EAsiBoolean					SobValues           (void);
    EAsiBoolean					Svl                 (int);
    EAsiBoolean                 ReadData            (void);
    EAsiBoolean                 GetColValue         (int, CAsiData *);
	EAsiBoolean					StoreValueFromDBType(CAsiData *, DBTYPE, void *);
	EAsiBoolean					InitAccessor		(ULONG_PTR, DBCOLUMNINFO *, const CAsiRow &,
													 ULONG *, DBBINDING	**,	HACCESSOR *,
													 EAsiBoolean);

	EAsiBoolean					DoChangeErrors		(HRESULT hr, ULONG, DBBINDING *);
    EAsiBoolean                 UpdateRow           (ULONG_PTR, DBCOLUMNINFO *, const CAsiRow &);
    EAsiBoolean                 InsertRow           (ULONG_PTR, DBCOLUMNINFO *, const CAsiRow &);

protected:
    CAsiExecStm         *       m_pCursorSpec;      
    IRowset             *       m_pIRowset;         
    IRowsetChange       *       m_pIRowsetChange;
    IRowsetLocate       *       m_pIRowsetLocate;

    IAccessor           *       m_pIAccessor;
    HACCESSOR                   m_hAccessor;
    DWORD                       m_lRowCount; 
    DWORD                       m_lCurrRow;

    IDataConvert		*		m_pIDataConvert;		

    HROW                *       m_rghRows;
    BYTE                *       m_pData;

    DWORD                       m_dwOffset;
    DBBINDING           *       m_rgBind;
    int                         m_iNumBind;
    EAsiBoolean                 m_fDataRead;    

	EAsiBoolean					m_fBlkStorObj;  
    EAsiBoolean                 m_fBLOBExpected;
	IUnknown			*		m_pIUnknown;

    CAsiIdent                   m_CsrName;      
    EAsiCurScr                  m_ScrFlag;      
    EAsiCurSns                  m_SnsFlag;      
    EAsiBoolean                 m_fUpd;         
    EAsiBoolean                 m_fIns;         
	EAsiBoolean					m_fOwnInserts;	
	EAsiBoolean					m_fOwnUpdates;	

	EAsiBoolean					m_fIsOpen;		

    EAsiCurPos                  m_CsrPos;

    ULONG_PTR                   m_ulColumns;
    ULONG                       m_ulCurrentRowNo;
    ULONG                       m_ulMaxRowNo;
    ULONG                       m_ulRows;

    CAsiTCCond              *   m_pTCCond;
};

class CAsiCsrTable : public CAsiCsr
{
public:
                                CAsiCsrTable        (void);
    virtual                     ~CAsiCsrTable       (void);

    virtual int                 ColQty              (void) const;
    virtual CAsiColumn *        ColDsc              (int) const; 

    virtual EAsiBoolean         Open                (void);
    virtual EAsiBoolean         Close               (void);

    virtual EAsiBoolean         Update              (const CAsiRow &); 

    virtual EAsiBoolean         Cvl                 (int, CAsiData *);
    virtual EAsiBoolean         Cvl                 (int, void *, short *,
                                                     int, EAsiHostType); 

    virtual EAsiBoolean         SetFilter           (CAsiTCCond *);
    virtual EAsiBoolean         SetOrder            ();

protected:
    void                        DeallocCsr          (void);

protected:
};

class CAsiCsrRegTable : public CAsiCsrTable
{
public:
                                CAsiCsrRegTable     (void);
    virtual                     ~CAsiCsrRegTable    (void);

    EAsiBoolean                 Allocate            (CAsiSession * ses, 
                                                     const CAsiUcStr & catalog,    
                                                     const CAsiUcStr & schema,   
                                                     const CAsiUcStr & table,
                                                     EAsiCurScr    sc = kAsiNonScroll,      
                                                     EAsiBoolean   upd = kAsiUnknown		
                                                     ); 

protected:
    CAsiUcStr                   m_pCatalog ;
    CAsiUcStr                   m_pSchema;
    CAsiUcStr                   m_pName;

};

class CAsiCsrInfSchema : public CAsiCsrTable
{
public:
                                CAsiCsrInfSchema    (void);
    virtual                     ~CAsiCsrInfSchema   (void);

    EAsiBoolean                 Allocate            (CAsiSession * ses,
                                                     EAsiInfSchTab ischema,
                                                     EAsiCurScr    sc = kAsiNonScroll   
                                                     );

protected:
    EAsiInfSchTab               m_istType;
};

class CAsiEnumerator: public CAsiCsrTable
{
public:
                                CAsiEnumerator      (void);
    virtual                     ~CAsiEnumerator     (void);

    EAsiBoolean                 Allocate            (CAsiAppl *);
    EAsiBoolean                 Allocate            (CAsiAppl *, CLSID & clsidEnum);

    void                        SetFilter           (EAsiDataSourceType dst,
                                                     const CAsiUcStr & pName,
                                                     EAsiBoolean isParent = kAsiUnknown);

    virtual EAsiBoolean         Fetch               (void);

protected:
    CLSID                       m_clsidEnum;  
    EAsiDataSourceType          m_eDsType;
    CAsiUcStr                   m_pName;
    EAsiBoolean                 m_fIsParent;

};

class CAsiTACond: public CAsiObject

{
    friend class CAsiTCCond;

public:
                                CAsiTACond          (void);
                                CAsiTACond          (const CAsiTACond &);
    virtual                      ~CAsiTACond        (void);

    virtual CAsiObject      *   duplicate           (void) const;

    CAsiData                *   m_pData;            
    int                         m_cColnum;          
    EAsiCompType                m_CompOp;           
};

class CAsiTCCond: public CAsiObject

{
public:
                                CAsiTCCond          (void);
                                CAsiTCCond          (int);
                                CAsiTCCond          (const CAsiTCCond &);
    virtual                     ~CAsiTCCond         (void);

            int                 Count               (void) const;           
            void                Append              (const CAsiTACond &);

            CAsiTACond      &   operator []         (int);                  

    virtual CAsiObject      *   duplicate           (void) const;

private:
    int                         m_cQnty;            
    CAsiList                    m_Conds;            
};

EAsiBoolean AsiAllocateDSEnumerator (
	CAsiAppl		*		pAppl,			
    const GUID      *       guidEnum,       
    const CAsiUcStr &       pDS,            
    CAsiEnumerator  **      pEnum           
);

EAsiBoolean AsiGetDSEnumerator (
	CAsiAppl		*		pAppl,			
    const GUID      *       guidEnum,       
    const CAsiUcStr &       pDS,            
    GUID            *       guidDsEnum      
);

extern "C" {
void                      AsiExceptionThrow (CAsiException*);
}

#pragma pack (pop)
#endif 

