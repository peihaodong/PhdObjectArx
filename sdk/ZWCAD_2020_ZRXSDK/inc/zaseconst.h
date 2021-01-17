
#ifndef _ZASECONST_H
#define _ZASECONST_H

#pragma pack(push, 8)

#define        ASE_DO_CURRENT       0x01  
#define        ASE_DO_REG           0x02  
#define        ASE_DO_EXIST         0x04  
#define        ASE_DO_CON           0x08  
#define        ASE_DO_UNKNOWN       0x10  
#define        ASE_DO_WRONGKEY      0x20  
                                          
#define        ASE_DO_WRONGKEYTYPE  0x40

#ifndef NULL
#define NULL 0L
#endif 

#define        LINKID_NULL	 -1L
#define        LINKSELID_NULL	 -1L

typedef long LinkSelID ;     
typedef LONG_PTR LinkID ;

typedef enum {
  kAseUnknownLinkType = 0,
  kAseEntityLink=1,  
  kAseDALink=2,	     
  kAseLeaderLink=3	     
} EAseLinkType ;

typedef enum  {
  
  kAseAttrAll=0,	 
  kAseAttrId=1, 	 
  kAseAttrType=2,	 
  kAseAttrStatus=3,	 
  kAseAttrEnt=4,	 
  kAseAttrName=5,	 
  kAseAttrKeyValue=6,	 
  kAseAttrDAColumns=7,	 
  kAseAttrDAParms=8,	 
  kAseAttrDAValues=9,	 
  kAseAttrXName=10,	 
  kAseAttrReserved1=11,  
  kAseAttrParKeyValue=12,

  kAseExtAttrTextCond=-1,
  kAseExtAttrEntities=-2,
  kAseExtAttrDoPath=-3	 
} EAseLinkAttr;

typedef enum {
  kAseUnknownNameCode=0, 
  kAseEnvCode=1,	     
  kAseCatCode=2,	     
  kAseSchemaCode=3,	     
  kAseTableCode=4,	     
  kAseLpnCode=5,	     
  kAsePathCode=6,	     
  kAseDOCode=7, 	     
  kAseSQLCode=8 	     
} EAseDoNameCode ;

#define eAseErrEntry   (MinUserDefErrorCode+1)

#define isAseErr(x)   (x == eAseErrEntry ? kAsiTrue : kAsiFalse)

#define			ASEPATH_STAT_EMPTY		0		

#define			ASEPATH_STAT_TABLE		0x01 	
#define			ASEPATH_STAT_QUERY		0x02 	

typedef enum {

    eAseEDscUnknown = 0, 

    eAseEDscInternal = 1,

    eAseEDscAse = 2,	   

    eAseEDscFile = 3,	   

    eAseEDscAsi = 4,	   

    eAseEDscDb = 5,	   

    eAseEDscDwg = 6,	   

    eAseEDscDlg = 7,	   

    eAseEDscApi = 8,	   

    eAseEDscLink = 9	   
			   
} EAseErrDsc ;

typedef enum {
    eAseErrUnknown=0,	   
    eAseErrInternal=1,	   
			   
    eAseErrMemory=2,	   
    eAseErrInfo=3,	   
    eAseErrMaxQty=4,	   

    eAseErrNoReg=10,	      
    eAseErrDoReg=11,	      
    eAseErrEnvNotConnected=12,	 
    eAseErrNoLpn=13,	      
    eAseErrNoEnvName=14,      
    eAseErrNoCatName=15,      
    eAseErrNoSchemaName=16,   
    eAseErrNoTableName=17,    
    eAseErrLpnExist=18,       
    eAseErrWrongKey=19,       
    eAseErrWrongKeyType=20,

    eAseErrNoSelEnts=21,      
    eAseErrNoSelLinks=22,     
    eAseErrNoSelDALinks=23,   
    eAseErrNoDoLinks=24,      
    eAseErrDAUpd=25,	       

    eAseErrWrongDoName=26,  
    eAseErrWrongResbuf=27,  
    eAseErrBadR12DOR=28,    
    eAseErrWrongLPN=29,     
    eAseErrWrongPath=30,    
    eAseErrLinkUpd=31,	    
    eAseErrLinkSynch=32,    
    eAseErrLPSynch=33,	    
    eAseErrCharSet=34	    

} EAseErrCodes ;

typedef enum {
    eAseFileErrUnknown=400,   
    eAseFileNotFound,	      
    eAseFileErrOpen,	      
    eAseFileErrRead,	      
    eAseFileErrWrite	      
} EAseFileErrCodes;

typedef enum {
    eAseDbErrUnknown=500,    
    eAseDbErrSyntax=501,     
    eAseDbErrPrepare=502,    
    eAseDbErrExecute=503,    
    eAseDbErrOpenCsr=504,    
    eAseDbErrEntry=505,      
			     
    eAseDbErrIni=506,	     
    eAseDbErrFetch=507	     
} EAseDbErrCodes ;

typedef enum {
   eAseDwgErrUnknown		 = 700,
   eAseDwgErrOpenReadEntity	 = 701,

   eAseDwgErrTranslateHandle	 = 702,

   eAseDwgErrAdsNameId		 = 703,

   eAseDwgErrXEDAppidNotFound	 = 704,

   eAseDwgErrXEDCorrupt 	 = 705,

   eAseDwgErrUpdateXED		 = 706,

   eAseDwgErrParcingLink	 = 707,

   eAseDwgErrParcingLPN 	 = 708,

   eAseDwgErrOpenWriteEntity	 = 709,

   eAseDwgErrConvertingLink	 = 710,

   eAseDwgErrOpenBlockTable	 = 711,

   eAseDwgErrAppendBlockTable	 = 712,

   eAseDwgErrAppendObjBlockTable = 713,

   eAseDwgErrOpenBlock		 = 714,

   eAseDwgErrDelSelSet		 = 715,

   eAseDwgErrFilterSelSet	 = 716,

   eAseDwgErrCreateLPNTable	 = 717,

   eAseDwgErrFindLPNTable	 = 718,

   eAseDwgErrFindAppid		 = 719,

   eAseDwgErrOpenLPNDict	 = 720,

   eAseDwgErrAddEntry		 = 721,

   eAseDwgErrRemoveEntry	 = 722,

   eAseDwgErrUnexpSymb		 = 723,

   eAseDwgErrDwgInit		 = 724,

   eAseDwgErrBlockIterator	 = 725,

   eAseDwgErrTransOpen		 = 726,

   eAseDwgErrTransClose 	 = 727,

   eAseDwgErrGrips		 = 728,

   eAseDwgErrFindBlock		 = 729,

   eAseDwgErrOpenRegapTable	 = 730,

   eAseDwgErrRegisterAppid	 = 731,

   eAseDwgErrInitObject 	 = 732,

   eAseDwgErrAddLink		 = 733,

   eAseDwgErrAddLPN		 = 734,

   eAseDwgErrDelLink		 = 735,

   eAseDwgErrDelLPN		 = 736,

   eAseDwgErrUpdLink		 = 737,

   eAseDwgErrUpdLPN		 = 738,

   eAseDwgErrDeleteObj		 = 739,

   eAseDwgErrCorruptDA		 = 740,

   eAseDwgErrErasedObj		 = 741,

   eAseDwgErrOpenNotify 	 = 742,

   eAseDwgErrOpenUndo		 = 743,

   eAseDwgErrOpenWrite		 = 744,

   eAseDwgErrOpenRead		 = 744,

   eAseDwgErrOpenXref		 = 745,

   eAseDwgErrOpenLocked 	 = 746,

   eAseDwgErrDelR12DOMesh	 = 747,

   eAseDwgErrDelR12LinkMesh	 = 748,

   eAseDwgErrReadLTypeTable	 = 749,

   eAseDwgErrReadLayerTable	 = 750,

   eAseDwgErrReadStyleTable	    = 751,

   eAseDwgErrOpenLPNEntry	 = 752,

   eAseDwgErrAppendBlkBlockHierarchy= 753,

   eAseDwgErrAppendRefBlockHierarchy= 754,

   eAseDwgErrFindBlkBlockHierarchy= 755,

   eAseDwgErrDelBlkBlockHierarchy   = 756,

   eAseDwgErrInvR12Mesh 	 = 757,

   eAseDwgErrEOR		 = 758,

   eAseDwgErrBraceExpected	 = 758,

   eAseDwgErrBlockName		 = 759,

   eAseDwgErrOpenLayer		 = 760

} EAseDwgErrCodes ;

typedef enum {
    eAseDlgErrUnknown=800,	
    eAseDlgWrongObj,
    eAseDlgNoDsc,
    eAseDlgMakeKey,
    eAseDlgReadStyleTable
} EAseDlgErrCodes ;

typedef enum {
    eAseApiErrUnknown=900,     
    eAseApiErrWrongData=901,	   
    eAseApiErrInitObj=902,	   
    eAseApiErrInitApp=903,	   
    eAseApiErrWrongAttr=904,	   
    eAseApiErrXmx=905,		   
    eAseApiErrWrongFunc=906,	   
    eAseApiErrEmptyList=907,	   
    eAseApiErrMissingTable=908,    
    eAseApiErrLinkNotFound=909,    
    eAseApiErrLinkMake=910,	   
    eAseApiErrLinkUpdate=911,	   
    eAseApiErrLinkDelete=912,	   
    eAseApiErrMissingLinkType=913, 
    eAseApiErrWrongLinkType=914,   
    eAseApiErrMissingLinkID=915,   
    eAseApiErrWrongLinkID=916,	   
    eAseApiErrMissingEntName=917,  
    eAseApiErrWrongEntName=918,    
    eAseApiErrMissingLpn=919,	   
    eAseApiErrWrongLpn=920,	   
    eAseApiErrMissingKeyVal=921,   
    eAseApiErrWrongKeyVal=922,	   
    eAseApiErrSelNotFound=923,	   
    eAseApiErrSelAddLink=924,	   
    eAseApiErrSelDelLink=925,	   
    eAseApiErrSelFree=926,	   
    eAseApiErrSelEmpty=927,	   
    eAseApiErrMissingKeyNames=928, 
    eAseApiErrWrongKeyNames=929,   
    eAseApiErrKeyNameNotFound=930, 
    eAseApiErrDupKeyNames=931,	   
    eAseApiErrLpnNew=932,	   
    eAseApiErrLpnDel=933,	   
    eAseApiErrLpnNotFound=934,	   
    eAseApiErrLpnRen=935,	   
    eAseApiErrWrongEntSel=936,	   
    eAseApiErrWrongBlock=937,	   
    eAseApiErrWrongWhere=938,	   
    eAseApiErrSelUnite=939,	   
    eAseApiErrSelSubtract=940,	   
    eAseApiErrSelIntersect=941,    
    eAseApiErrSelErase=942,	   
    eAseApiErrSelEraseLinks=943,   
    eAseApiErrCurrent=944,	   
    eAseApiErrWrongRowVal=945,	   
    eAseApiErrDuplicatedLink=946,  
    eAseApiErrMissingDANames=947,  
    eAseApiErrWrongDANames=948,    
    eAseApiErrWrongDAVal=949,	   
    eAseApiErrMissingDAPar=950,    
    eAseApiErrWrongDAPar=951,	   
    eAseApiErrMakeDA=952	   
} EAseApiErrCodes ;

typedef enum {
eAseLinkErrUnknown		= 1000, 
eAseLinkErrWrongRegPath 	= 1001,

eAseLinkErrWrongRegDsc		= 1002,

eAseLinkErrWrongPath12		= 1003,

eAseLinkErrWrongTypeDsc 	= 1005,

eAseLinkErrWrongLsAddOp 	= 1007,

eAseLinkErrWrongLsSubOp 	= 1008,

eAseLinkErrWrongLsId		= 1009,

eAseLinkErrWrongEntityId	= 1010,

eAseLinkErrUndefDa		= 1011,

eAseLinkErrNoMemForLs		= 1012,

eAseLinkErrWrongPtrToLnk	= 1013,

eAseLinkErrNoLinkInLMem 	= 1014,

eAseLinkErrNoEntityForLink	= 1016,

eAseLinkErrWrongPtrToLs 	= 1017,

eAseLinkErrNoLsInLMem		= 1018,

eAseLinkErrMLsNotValid		= 1019,

eAseLinkErrMLinkNotValid	= 1020,

eAseLinkErrTabNoChanges 	= 1021,

eAseLinkErrRnmWrongOldLPN	= 1022,

eAseLinkErrRnmWrongNewLPN	= 1023,

eAseLinkErrRnmNoUpd		= 1024,

eAseLinkErrLLinkNotValid	= 1025,

eAseLinkErrLLinkNotUpdate	= 1026,

eAseLinkErrLLinkNoMakeDup	= 1027,

eAseLinkErrLLinkNoMakeKey	= 1029,

eAseLinkErrLLinkNoMakeStore	= 1030,

eAseLinkErrLLinkWrongId 	= 1031,

eAseLinkErrLLinkWrongType	= 1032,

eAseLinkErrLLinkManyLinks	= 1033,

eAseLinkErrLLinkNoMake		= 1034,

eAseLinkErrLLinkNoDel		= 1035,

eAseLinkErrLLinkNoUpd		= 1036,

eAseLinkErrLLinkNoDATab 	= 1037,

eAseLinkErrLLinkNoDAEnt 	= 1038,

eAseLinkErrLLinkWrongEnt	= 1039,

eAseLinkErrLLinkWrongDA 	= 1040,

eAseLinkErrLLinkAbsent		= 1041,

eAseLinkErrLSWrongFilter	= 1042,

eAseLinkErrInLMem		= 1045,

eAseLinkErrKeyNotValid		= 1046,

eAseLinkErrWrongKeyVal		= 1047,

eAseLinkErrCantStoreKeyVal	= 1048,

eAseLinkErrWrongDsc		= 1049,

eAseLinkErrWrongKeyInit 	= 1050,

eAseLinkErrValid		= 1051,

eAseLinkErrStart		= 1052,

eAseLinkErrLMemWrongId		= 1053,

eAseLinkErrLMemInternal 	= 1054,

eAseLinkErrLMemRBack		= 1055,

eAseLinkErrWrongTransForUpd	= 1056,

eAseLinkErrEnameEIdConvert	= 1059,

eAseLinkErrEntNoUpd		= 1060,

eAseLinkErrContainerItem	= 1061,

eAseLinkErrNtfEraseUnlinkedEntity = 1062,

eAseLinkErrNtfCopyUnlinkedEntity = 1063,

eAseLinkErrNtfCanTProcess	= 1064,

eAseLinkErrNtfUnXED		= 1065,

eAseLinkErrNtfUnKey		= 1066,

eAseLinkErrNtfUnDA		= 1067,

eAseLinkErrNtfUnErase		= 1069,

eAseLinkErrInternal		= 1070,

eAseLinkErrWrongRecordLpnPos	= 1071,

eAseLinkErrWrongLpnSyntax	= 1073,

eAseLinkErrCantRegLink		= 1076,

eAseLinkErrCantInitKey		= 1077,

eAseLinkErrWrongLinkNumber	= 1078,

eAseLinkErrDuplicateReg 	= 1079,

eAseLinkErrTrRbackUndel 	= 1081,

eAseLinkErrTrRbackTable 	= 1082,

eAseLinkErrTrRback		= 1083,

eAseLinkErrTrCommit		= 1084,

eAseLinkErrTrCommitTable	= 1085,

eAseLinkErrTrCommitDelLink	= 1086,

eAseLinkErrTrCommitAddLink	= 1087,

eAseLinkErrLnkDestroed		= 1088,

eAseLinkErrDupUpdLnk		= 1090,

eAseLinkErrRubbNoMem		= 1091,

eAseLinkErrCommitNoMem		= 1092,

eAseLinkErrCommit		= 1093,

eAseLinkErrTrExportLpn		= 1094,

eAseLinkErrLostLink		= 1095,

eAseLinkErrLinkToLeaderLink		= 1096

} EAseLinkErrCodes ;

typedef enum {
    kAseDiagErrDsc    =	 MinUserDefDiagParam+1, 
    kAseDiagErrCode   =	 MinUserDefDiagParam+2, 
    kAseDiagErrMsg    =	 MinUserDefDiagParam+3, 
    kAseDiagStatement =  MinUserDefDiagParam+4, 
    kAseDiagSynErrPos =  MinUserDefDiagParam+5, 
    kAseDiagLPName    =	 MinUserDefDiagParam+6, 
    kAseDiagEnvName   =	 MinUserDefDiagParam+7, 
    kAseDiagEntHandle =  MinUserDefDiagParam+8, 
    kAseDiagBlockName =  MinUserDefDiagParam+9, 
    kAseDiagLayerName =  MinUserDefDiagParam+10,
    kAseDiagLabelName =  MinUserDefDiagParam+11,
    kAseDiagZcApDoc   =  MinUserDefDiagParam+12,
    kAseDiagGroupName =  MinUserDefDiagParam+13,
    kAseDiagQueryName =  MinUserDefDiagParam+14,
    kAseDiagTableName =  MinUserDefDiagParam+15 
} EAseDiagParms ;

typedef enum {
    kAseApiUnknownId,
    kAseApiAppl,	 
    kAseApiLinkPath, 
    kAseApiLink,	 
    kAseApiLinkSel	 
} EAseApiClassId ;

enum DatasourceTranslationCode {
    kTranslateFromR14toR15 = 0,   
    kTranslateFromR15toR14
};  

#pragma pack (pop)
#endif 
