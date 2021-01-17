

#ifndef ZASI_ASICONST_H
#define ZASI_ASICONST_H asiconsth

#ifdef _
#undef _
#endif 
#ifdef PROTOTYPES
#define _(x) x
#else 
#define _(x) ()
#endif  

#if defined(__cplusplus)
extern "C" {
#endif  

#define ASI_MAX(x,y) ((x)>(y)?(x):(y))
#define ASI_MIN(x,y) ((x)<(y)?(x):(y))

#include "zcsptypes.h"
#pragma pack (push, 8)

typedef unsigned char  uchar;         
#if !defined(hpux) || !defined(_SYS_TYPES_INCLUDED)
typedef unsigned short ushort;        
typedef unsigned int   uint;          
#endif 
typedef unsigned long  ulong;         
typedef double         real;          
typedef long           integer;       
typedef short          smallint;      

typedef struct asi_year {
    long        sign;       
    ulong       years;      
} ASI_IYEAR;

typedef struct asi_yeartomonth {
    long        sign;       
    ulong       years;      
    ulong       months;     
} ASI_IYEARTOMONTH;

typedef struct asi_month {
    long        sign;       
    ulong       months;     
} ASI_IMONTH;

typedef struct asi_day  {
    long        sign;       
    ulong       days;       
} ASI_IDAY;

typedef struct asi_daytohour  {
    long        sign;       
    ulong       days;       
    ulong       hours;      
} ASI_IDAYTOHOUR;

typedef struct asi_daytominute {
    long        sign;       
    ulong       days;       
    ulong       hours;      
    ulong       minutes;    
} ASI_IDAYTOMINUTE;

typedef struct asi_daytosecond {
    double      seconds;    
    long        sign;       
    ulong       days;       
    ulong       hours;      
    ulong       minutes;    
} ASI_IDAYTOSECOND;

typedef struct asi_hour {
    long        sign;       
    ulong       hours;      
} ASI_IHOUR;

typedef struct asi_hourtominute {
    long        sign;       
    ulong       hours;      
    ulong       minutes;    
} ASI_IHOURTOMINUTE;

typedef struct asi_hourtosecond {
    double      seconds;    
    long        sign;       
    ulong       hours;      
    ulong       minutes;    
} ASI_IHOURTOSECOND;

typedef struct asi_minute {
    long        sign;       
    ulong       minutes;    
} ASI_IMINUTE;

typedef struct asi_minuteitosecond {
    double      seconds;    
    long        sign;       
    ulong       minutes;    
} ASI_IMINUTETOSECOND;

typedef struct asi_second {
    double      seconds;    
    long        sign;       
} ASI_ISECOND;

typedef struct asi_date {  
    ushort year;             
    ushort month;            
    ushort day;              
    short  pad;              
} ASI_DTDATE;

typedef struct asi_time {       
    double            second;   
    ASI_IHOURTOMINUTE timezone; 
    ushort            hour;     
    ushort            minute;   
} ASI_DTTIME;

typedef struct asi_timestamp {  
    ASI_DTTIME   time;          
    ASI_DTDATE   date;          
} ASI_DTTIMESTAMP; 

typedef enum {
    kAsiUnknown = -1,           
    kAsiFalse = 0,
    kAsiTrue = 1,
    kAsiBad = 0,
    kAsiGood = 1
} EAsiBoolean;

#define EAsiFlag EAsiBoolean

typedef enum {
    kAsiVector      = -2,       
    kAsiImplDefined = -1,       
    kAsiTUnknown = 0,
    kAsiChar = 1,
    kAsiNumeric,
    kAsiDecimal,
    kAsiInteger,
    kAsiSmallInt,
    kAsiFloat,
    kAsiReal,
    kAsiDouble,
    kAsiDateTime,
    kAsiInterval,
    kAsiCharVar = 12,
    kAsiBit = 14,
    kAsiBitVar,
    kAsiPoint,	
	kAsiBlob
} EAsiDataType;

typedef enum {
    kAsiDTUnknown = 0,
    kAsiDate = 1,
    kAsiTime,
    kAsiTimeStamp,
    kAsiTimeTZ,
    kAsiTimeStampTZ
} EAsiDTType;

typedef enum {
    kAsiIUnknown = 0,
    kAsiYear = 1,
    kAsiMonth,
    kAsiDay,
    kAsiHour,
    kAsiMinute,
    kAsiSecond,
    kAsiYear2Month,
    kAsiDay2Hour,
    kAsiDay2Minute,
    kAsiDay2Second,
    kAsiHour2Minute,
    kAsiHour2Second,
    kAsiMinute2Second
} EAsiIType;

typedef unsigned int uint;

typedef enum {
  kAsiLeading = 0,
  kAsiTrailing,
  kAsiBoth
} EAsiTrimSpec;

typedef enum {
    kAsiHnull  = 0,           
    kAsiHshort = 1,           
    kAsiHlong,                
    kAsiHfloat,               
    kAsiHreal,                
    kAsiHchar,                
    kAsiHunicode,             
    kAsiHbinary,              
    kAsiHdate,                
    kAsiHtime,                
    kAsiHtimestamp,           
    kAsiHyear,                
    kAsiHyeartomonth,         
    kAsiHmonth,               
    kAsiHday,                 
    kAsiHdaytohour,           
    kAsiHdaytominute,         
    kAsiHdaytosecond,         
    kAsiHhour,                
    kAsiHhourtominute,        
    kAsiHhourtosecond,        
    kAsiHminute,              
    kAsiHminutetosecond,      
    kAsiHsecond               
} EAsiHostType;

typedef enum {
   kAsiStatUsername       = (int)0x00000001      
  ,kAsiStatPassword       = (int)0x00000002      
  ,kAsiStatCatalog        = (int)0x00000004      
  ,kAsiStatSchema         = (int)0x00000008      
  ,kAsiStatTimeZone       = (int)0x00000010      
  ,kAsiStatNames          = (int)0x00000020      
  ,kAsiStatTranslation    = (int)0x00000040      
  ,kAsiStatInfoSchema     = (int)0x00000080      
  ,kAsiStatCDCatalog      = (int)0x00000100      
  ,kAsiStatCDSchema       = (int)0x00000200      
  ,kAsiStatCDTable        = (int)0x00000400      
  ,kAsiStatCDView         = (int)0x00000800      
  ,kAsiStatCDIndex        = (int)0x00001000      
  ,kAsiStatCDTranslation  = (int)0x00002000      
  ,kAsiStatCDAssertion    = (int)0x00004000      
  ,kAsiStatCDCharset      = (int)0x00008000      
  ,kAsiStatCDCollation    = (int)0x00010000      
  ,kAsiStatCDDomain       = (int)0x00020000      
  ,kAsiStatADomain        = (int)0x00040000      
  ,kAsiStatATable         = (int)0x00080000      
  ,kAsiStatPrivileges     = (int)0x00100000      
  ,kAsiStatCommitRollback = (int)0x00200000      
  ,kAsiStatSetTrans       = (int)0x00400000      
  ,kAsiStatSetConstr      = (int)0x00800000      
  ,kAsiStatCursor         = (int)0x01000000      
  ,kAsiStatFetch          = (int)0x02000000      
  ,kAsiStatSingSelect     = (int)0x04000000      
  ,kAsiStatDeletePos      = (int)0x08000000      
  ,kAsiStatUpdatePos      = (int)0x10000000      
  ,kAsiStatDeleteSearch   = (int)0x20000000      
  ,kAsiStatUpdateSearch   = (int)0x40000000      
  ,kAsiStatInsert         = (int)0x80000000      

} EAsiDrvStatus;

typedef enum {
    kAsiSDImplDefined = (int)0x00000001,
    kAsiSDChar        = (int)0x00000002,
    kAsiSDNumeric     = (int)0x00000004,
    kAsiSDDecimal     = (int)0x00000008,
    kAsiSDInteger     = (int)0x00000010,
    kAsiSDSmallInt    = (int)0x00000020,
    kAsiSDFloat       = (int)0x00000040,
    kAsiSDReal        = (int)0x00000080,
    kAsiSDDouble      = (int)0x00000100,
    kAsiSDDate        = (int)0x00000200,
    kAsiSDTime        = (int)0x00000400,
    kAsiSDTimeTZ      = (int)0x00000800,
    kAsiSDTimestamp   = (int)0x00001000,
    kAsiSDTimestampTZ = (int)0x00002000,
    kAsiSDYM          = (int)0x00004000,
    kAsiSDDT          = (int)0x00008000,
    kAsiSDCharVar     = (int)0x00010000,
    kAsiSDBit         = (int)0x00020000,
    kAsiSDBitVar      = (int)0x00040000,
	kAsiSDBLOB		  = (int)0x00080000,
	kAsiSDCharAsStr	  = (int)0x00100000

} EAsiSIDataType;

typedef enum {
	kAsiTSUndefined = (int )0,		 	
									 
	kAsiTSRWRC = (int)0x00000001,    
	kAsiTSRWRR = (int)0x00000002,    
	kAsiTSRWSR = (int)0x00000004,    
	kAsiTSRORU = (int)0x00000008,    
	kAsiTSRORC = (int)0x00000010,    
	kAsiTSRORR = (int)0x00000020,    
	kAsiTSROSR = (int)0x00000040     

} EAsiSITransactionType;

typedef enum {
   kAsiSISupportedFeatures            
  ,kAsiSITransaction                  
  ,kAsiSICsrState                     
  ,kAsiSICsrSns                       
  ,kAsiSICsrScr                       
  ,kAsiSICsrPos                       
  ,kAsiSICsrUpd                       
  ,kAsiSIDataType                     
  ,kAsiSIBindDataType                 
  ,kAsiSITransactionType              
} EAsiStatInfo;

#ifdef A

typedef enum {
    kAsiTYPE_UNDEFINED = 0,   
    kAsiALLOC_CURSOR,         
    kAsiALLOC_STATEMENT,      
    kAsiALTER_DOMAIN,         
    kAsiALTER_TABLE,          
    kAsiCREATE_ASSERTION,     
    kAsiCREATE_CATALOG,       
    kAsiCREATE_CHARACTER_SET, 
    kAsiCREATE_COLLATION,     
    kAsiCREATE_DOMAIN,        
    kAsiCLOSE_CURSOR,         
    kAsiCOMMIT,               
    kAsiCONNECT,              
    kAsiCREATE_SCHEMA,        
    kAsiCREATE_TABLE,         
    kAsiCREATE_VIEW,          
    kAsiCREATE_INDEX,         
    kAsiCREATE_TRANSLATION,   
    kAsiCURSOR,               
    kAsiDELETE_CURSOR,        
    kAsiDELETE_WHERE,         
    kAsiDEALLOCATE_STATEMENT, 
    kAsiDISCONNECT,           
    kAsiDROP_ASSERTION,       
    kAsiDROP_CATALOG,         
    kAsiDROP_CHARACTER_SET,   
    kAsiDROP_COLLATION,       
    kAsiDROP_DOMAIN,          
    kAsiDROP_SCHEMA,          
    kAsiDROP_TABLE,           
    kAsiDROP_TRANSLATION,     
    kAsiDROP_VIEW,            
    kAsiDROP_INDEX,           
    kAsiEXECUTE_IMMEDIATE,    
    kAsiEXECUTE,              
    kAsiFETCH,                
    kAsiGRANT,                
    kAsiINSERT,               
    kAsiOPEN,                 
    kAsiPREPARE,              
    kAsiREVOKE,               
    kAsiROLLBACK,             
    kAsiSELECT,               
    kAsiSET_CATALOG,          
    kAsiSET_SCHEMA,           
    kAsiSET_TIME_ZONE,        
    kAsiSET_NAMES,            
    kAsiSET_TRANSACTION,      
    kAsiSET_CONSTRAINT,       
    kAsiSET_AUTHORIZATION,    
    kAsiUPDATE_CURSOR,        
    kAsiUPDATE_WHERE          
} EAsiStatement;
#endif

typedef enum {
    kAsiTIUndefined = 0,
    kAsiReadUncommitted = 1,
    kAsiReadCommitted,
    kAsiRepeatableRead,
    kAsiSerializable
} EAsiTILevel;

typedef enum {
    kAsiTMUndefined = 0,
    kAsiTReadOnly = 1,
    kAsiTReadWrite
} EAsiTMode;

#define  DefaultDiagSize 32

typedef enum {
  kAsiCDefer = 1,
  kAsiCImmediate
} EAsiConstrCheck;

typedef enum {
    kAsiNonScroll = 0,
    kAsiScroll = 1
} EAsiCurScr;

typedef enum {
    kAsiSnsUndef = 0,      
    kAsiInsensitive = 1
} EAsiCurSns;

typedef enum {
    kAsiNext = 1,
    kAsiPrior,
    kAsiFirst,
    kAsiLast,
    kAsiAbsolute,
    kAsiRelative
} EAsiDirection;

typedef enum {
    kAsiCPUnknown = 0,     
    kAsiTos       = 1,     
    kAsiEos       = 2,     
    kAsiBnr       = 3,     
    kAsiOcr       = 4      
} EAsiCurPos;

typedef enum {
   kAsiCACoercible = 0,    
   kAsiCAImplicit  = 1,    
   kAsiNoCollation = 2,    
   kAsiCAExplicit  = 3     
} EAsiCAttr;

typedef enum {
     kAsiISUnknown					= 0

	,kAsiIS_ASSERTIONS				= 1
	,kAsiIS_CHARACTER_SETS			= 2
	,kAsiIS_CHECK_CONSTRAINTS		= 3
	,kAsiIS_COLLATIONS				= 4
	,kAsiIS_COLUMN_DOMAIN_USAGE		= 5
	,kAsiIS_COLUMN_PRIVILEGES		= 6
	,kAsiIS_COLUMNS					= 7
	,kAsiIS_CONSTRAINT_COLUMN_USAGE	= 8
	,kAsiIS_CONSTRAINT_TABLE_USAGE	= 9
	,kAsiIS_FOREIGN_KEYS			= 10
	,kAsiIS_KEY_COLUMN_USAGE		= 11
	,kAsiIS_PRIMARY_KEYS			= 12
	,kAsiIS_PROCEDURE_COLUMNS		= 13
	,kAsiIS_PROCEDURE_PARAMETERS   	= 14
	,kAsiIS_PROCEDURES             	= 15
	,kAsiIS_REFERENTIAL_CONSTRAINTS	= 16
	,kAsiIS_SCHEMATA               	= 17
	,kAsiIS_SQL_LANGUAGES          	= 18
	,kAsiIS_TABLE_CONSTRAINTS      	= 19
	,kAsiIS_TABLE_PRIVILEGES       	= 20
	,kAsiIS_TABLES                 	= 21
	,kAsiIS_TRANSLATIONS           	= 22
	,kAsiIS_USAGE_PRIVILEGES       	= 23
	,kAsiIS_VIEW_COLUMN_USAGE      	= 24
	,kAsiIS_VIEW_TABLE_USAGE       	= 25
	,kAsiIS_VIEWS                  	= 26

	,kAsiIS_CATALOGS				= 27
	,kAsiIS_INDEXES					= 28
	,kAsiIS_PROVIDER_TYPES			= 29
	,kAsiIS_STATISTICS				= 30

} EAsiInfSchTab;

typedef enum {
    kAsiDSSOURCETYPE_BOTH       = 0,
    kAsiDSSOURCETYPE_DATASOURCE = 1,
    kAsiDSSOURCETYPE_ENUMERATOR = 2
} EAsiDataSourceType;

#define MaxCharLength             256
#define DefaultCharLength         1

#define MaxBinaryLength           (256*8)
#define DefaultBinaryLength       1

#define SmallIntPrecision         6

#define IntegerPrecision          10

#define MaxNumericPrecision       32
#define MaxNumericScale           MaxNumericPrecision
#define DefaultNumericPrecision   18
#define DefaultNumericScale       0

#define MaxDecimalPrecision       32
#define MaxDecimalScale           MaxDecimalPrecision
#define DefaultDecimalPrecision   18
#define DefaultDecimalScale       0

#define MaxFloatPrecision         32
#define DefaultFloatPrecision     16

#define RealPrecision             32

#define DoublePrecision           64

#define MaxLeadingFieldPrec       6    
#define MaxFracSecondPrec         8
#define MinLeadingFieldPrec       2
#define MinFracSecondPrec         0
#define DefaultLeadingFieldPrec   4
#define DefaultFracSecondPrec     0

#define MaxTimePrecision          6
#define DefaultTimePrecision      0

#define MaxTimeStampPrecision     6
#define DefaultTimeStampPrecision 6

#define MaxIdentLength            256

#define DefaultPointDimension     3

#define AsiImplDefFxdMin          0000 
#define AsiImplDefFxdUser         2000 
#define AsiImplDefFxdMax          3999
#define AsiImplDefRawMin          4000 
#define AsiImplDefRawUser         6000 
#define AsiImplDefRawMax          8000

typedef enum {                
    kAsiConditionNumber = 1,  
    kAsiMessageLength,        
    kAsiMessageOctetLength,   

    kAsiHRESULT          =  4,

    kAsiConditionStrings = 20,
    kAsiReturnedSQLSTATE,     
    kAsiClassOrigin,          
    kAsiSubClassOrigin,       
    kAsiServerName,           
    kAsiConnectionName,       
    kAsiConstraintCatalog,    
    kAsiConstraintSchema,     
    kAsiConstraintName,       
    kAsiCatalogName,          
    kAsiSchemaName,           
    kAsiTableName,            
    kAsiColumnName,           
    kAsiCursorName,           
    kAsiMessageText,          

    kAsiInterface        = 35   

} EAsiDiag;

typedef unsigned int AsiDiag;
#define MinUserDefDiagParam         0x0400

typedef enum {
    kAsiErrUndefined = -1

   ,kAsiNoError = 0   
   ,kAsiOKAY = 0

   ,kAsiSQLWARN =           0x0100  
   ,kAsiSQLWARNCUROP                
   ,kAsiSQLWARNDISC                 
   ,kAsiSQLNULLSET                  
   ,kAsiSQLWARNRTRUNC               
   ,kAsiSQLWARNINSUFDESC            
   ,kAsiSQLWARNREVOKE               
   ,kAsiSQLWARNGRANT                
   ,kAsiSQLWARNBITPAD               
   ,kAsiSQLWARNLONGCOND             
   ,kAsiSQLWARNLONGEXPR             

   ,kAsiSQLNODATA =         0x0200  
   ,kAsiSQLNDSearchStm              
   ,kAsiSQLNDSingSelect             
   ,kAsiSQLNDEOS                    
   ,kAsiSQLNDTOS                    

   ,kAsiSQLDYN    =         0x0700  
   ,kAsiSQLDYNUPMISMATCH            
   ,kAsiSQLDYNUTMISMATCH            
   ,kAsiSQLDYNEXECUR                
   ,kAsiSQLDYNUSINGMIS              
   ,kAsiSQLDYNNOTCURSOR             
   ,kAsiSQLDYNAVIOLATION            
   ,kAsiSQLDYNINTOMIS               
   ,kAsiSQLDYNINVDSCCOUN            
   ,kAsiSQLDYNINVDSCIDX             
   ,kAsiSQLDYNNOTPREPARED           
   ,kAsiSQLDYNAlreadyBound          
   
   ,kAsiSQLCON     =        0x0800  
   ,kAsiSQLCONCLIENT                
   ,kAsiSQLCONNAMEUSE               
   ,kAsiSQLCONNOTEXIST              
   ,kAsiSQLCONSERVER                
   ,kAsiSQLCONOPENOBJS				
   ,kAsiSQLCONFAILURE               
   ,kAsiSQLCONTRANS                 
                                    
   ,kAsiSQLCURCONFLICT =    0x0900  
   
   ,kAsiSQLNOTSUPPORTED =   0x0A00  
   ,kAsiSQLMULTRANS                 
   
   ,kAsiSQLCARVIOLATION  =  0x2100  
   
   ,kAsiSQLDATA          =  0x2200  
   ,kAsiSQLDATASRTRUN               
   ,kAsiSQLDATANOIND                 
   ,kAsiSQLDATANUMRANGE             
   ,kAsiSQLDATANUMTRUNC             
   ,kAsiSQLDATAASSIGN               
   ,kAsiSQLDATAFETSEQ               
   ,kAsiSQLDATADTFORMAT             
   ,kAsiSQLDATADTOVF                
   ,kAsiSQLDATATZDISP               
   ,kAsiSQLDATA10                   
   ,kAsiSQLDATASUBSTRERR            
   ,kAsiSQLDATAZERODIV              
   ,kAsiSQLDATA13                   
   ,kAsiSQLDATAINFORMAT             
   ,kAsiSQLINTEROVF                 
   ,kAsiSQLColRO                    
   ,kAsiSQLDATA17                   
   ,kAsiSQLDATACHARCAST             
   ,kAsiSQLDATAESCCHAR              
   ,kAsiSQLDATA20                   
   ,kAsiSQLDATACHAR                 
   ,kAsiSQLDATAINDIVF               
   ,kAsiSQLDATAPARVAL               
   ,kAsiSQLDATACSTR                 
   ,kAsiSQLDATAESCSEQ               
   ,kAsiSQLDATASTRLEN               
   ,kAsiSQLDATATRIMERR              
   ,kAsiSQLDATADTUNDF               

   ,kAsiSQLINTCONSTR     =  0x2300  
   
   ,kAsiSQLINVCURSTATE   =  0x2400  
   ,kAsiSQLICSDeallocStm =  0x2401  
   ,kAsiSQLICSClose      =  0x2402  
   ,kAsiSQLICSNotScroll  =  0x2403  
   ,kAsiSQLICSReadOnly   =  0x2404  
   ,kAsiSQLICSNoCurRow   =  0x2405  
   ,kAsiSQLICSOpen       =  0x2406  
   
   ,kAsiSQLINVTRSTATE    =  0x2500  
   ,kAsiSQLITSActive     =  0x2501  
   ,kAsiSQLITSNotActive  =  0x2502  
   ,kAsiSQLITSSetTrans   =  0x2503  
   ,kAsiSQLINVTSTabRO    =  0x2504  
   ,kAsiSQLINVTSTrsRO    =  0x2505  
   ,kAsiSQLINVTSAuth     =  0x2506

   ,kAsiSQLINVSTMNAME    =  0x2600  
   
   ,kAsiSQLTRIGCHNVIOL   =  0x2700  
   
   ,kAsiSQLINVAUTHID     =  0x2800  
   
   ,kAsiSQLDIRSYNACS     =  0x2A00  
   
   ,kAsiSQLPRIVEXIST     =  0x2B00  
   
   ,kAsiSQLINVCHARSET    =  0x2C00  
   
   ,kAsiSQLINVTRTERM     =  0x2D00  
   
   ,kAsiSQLINVDESC       =  0x3300  
   
   ,kAsiSQLINVCURNAME    =  0x3400  
   
   ,kAsiSQLINVCONDNUM    =  0x3500  
   
   ,kAsiSQLDYNSYNACS     =  0x3700  
    
   ,kAsiErSynWrStr                  
   ,kAsiErSynLongStr                
   ,kAsiErSynMisQuot                
   ,kAsiErSynHexDigit               
   ,kAsiErSynBinDigit               
   ,kAsiErSynInterval               
   ,kAsiErSynTypeMatch              
   ,kAsiErSynCollate                
   ,kAsiErSynWrTimeZone             
   ,kAsiErSynMisZone                
   ,kAsiErSynNotTimeZone            
   ,kAsiErSynUnbalPar               
   ,kAsiErSynExprEx                 
   ,kAsiErSynMisCol                 
   ,kAsiErSynWrColSpec              
   ,kAsiErSynNoLeftPar              
   ,kAsiErSynMlStar                 
   ,kAsiErSynMisIn                  
   ,kAsiErSynWrDTField              
   ,kAsiErSynMisFrom                
   ,kAsiErSynMisUsing               
   ,kAsiErSynFOUorTR                
   ,kAsiErSynMisTimePrec            
   ,kAsiErSynWrCollName             
   ,kAsiErSynWrSetSq                
   ,kAsiErSynNoComma                
   ,kAsiErSynNoWhen                 
   ,kAsiErSynMisThen                
   ,kAsiErSynMisEnd                 
   ,kAsiErSynWrNot                  
   ,kAsiErSynNull                   
   ,kAsiErSynCompare                
   ,kAsiErSynWrComma                
   ,kAsiErSynMask                   
   ,kAsiErSynEsc                    
   ,kAsiErSynMisSq                  
   ,kAsiErSynAndBet                 
   ,kAsiErSynNotJoin                
   ,kAsiErSynMisJoin                
   ,kAsiErSynWrNatural              
   ,kAsiErSynMisJoinSpec            
   ,kAsiErSynMisCorName             
   ,kAsiErSynWrTabSpec              
   ,kAsiErSynEmptyList              
   ,kAsiErSynNoJoinSpec             
   ,kAsiErSynMisName                
   ,kAsiErSynMisQueryPrimary        
   ,kAsiErSynEEEEEEEEEEEEEEE        
   ,kAsiErSynNotJoinedTable         
   ,kAsiErSynMisTabValConstr        
   ,kAsiErSynMisSelect              
   ,kAsiErSynMisColName             
   ,kAsiErSynMisGroup               
                                    
   ,kAsiErSynNotScalar              
   ,kAsiErSynElementInParen         
   ,kAsiErSynOvrlDegree             
   ,kAsiErSynDegreeViolation        
   ,kAsiErSynMisAs                  
   ,kAsiErSynWrongCast              
   ,kAsiErSynInvalidDomain          
   ,kAsiErSynCharExpected           
   ,kAsiErSynTypeExpected           
   ,kAsiErSynWrongPrecLength        
   ,kAsiErSynScaleExpected          
   ,kAsiErSynWrongScale             
   ,kAsiErSynWithTimeZoneExpected   
   ,kAsiErSynNoVarLength            
   ,kAsiErSynOrderByExpected        
   ,kAsiErSynReadOnlyExpected       
   ,kAsiErSynWrongSortKey           
   ,kAsiErSynEmptySortList          
   ,kAsiErSynWrongToken             
   ,kAsiErSynWrTabName              
   ,kAsiErSynMisOf                  
   ,kAsiErSynMisCursorName          
   ,kAsiErSynMisSet                 
   ,kAsiErSynMisBecome              
   ,kAsiErSynMisInto                
   ,kAsiErSynMisValues              
   ,kAsiErSynMisTarget              
   ,kAsiErSynDubTransMode           
   ,kAsiErSynMisSize                
   ,kAsiErSynWrDiagSize             
   ,kAsiErSynMisTransMode           
   ,kAsiErSynInCompLevelMode        
   ,kAsiErSynWrConstrChkMode        
   ,kAsiErSynWrConstrName           
   ,kAsiErSynMisRead                
   ,kAsiErSynMisAuthorization       
   ,kAsiErSynMisTemporary           
   ,kAsiErSynMisTable               
   ,kAsiErSynOnCommit               
   ,kAsiErSynNotTemporary           
   ,kAsiErSynWrComBehaviour         
   ,kAsiErSynMisRows                
   ,kAsiErSynMisTableName           
   ,kAsiErSynWrCheckTime            
   ,kAsiErSynMisDeferrable          
   ,kAsiErSynWrNotDefer             
   ,kAsiErSynNotNull                
   ,kAsiErSynPrimaryKey             
   ,kAsiErSynMisConstr              
   ,kAsiErSynMisRefSpec             
   ,kAsiErSynMisRefTable            
   ,kAsiErSynWrMatchType            
   ,kAsiErSynSetAction              
   ,kAsiErSynDuplAction             
   ,kAsiErSynMisTrigRule            
   ,kAsiErSynForeignKey             
   ,kAsiErSynNoColDef               
   ,kAsiErSynMisAlterAction         
   ,kAsiErSynDropDefault            
   ,kAsiErSynSetDefault             
   ,kAsiErSynMisDropBehaviour       
   ,kAsiErSynNotCheckConstr         
   ,kAsiErSynMisCheckOption         
   ,kAsiErSynMisCharSet             
   ,kAsiErSynMisCharSetSource       
   ,kAsiErSynCharSetExp             
   ,kAsiErSynPadAttr                
   ,kAsiErSynMisTransName           
   ,kAsiErSynCollationExp           
   ,kAsiErSynMisExternColl          
   ,kAsiErSynMisTo                  
   ,kAsiErSynMisOn                  
   ,kAsiErSynMisGrantOption         
   ,kAsiErSynMisFor                 
   ,kAsiErSynMisObjectName          
   ,kAsiErSynMisGrantee             
   ,kAsiErSynAllPrivileges          
   ,kAsiErSynMisIndex               
   ,kAsiErSynAuthorExpected         
   ,kAsiSynErDublColumnName         
   ,kAsiSynErAmbTabRef              
   ,kAsiSynErTableNotFound          
   ,kAsiSynErColumnNotFound         
   ,kAsiSynErAmbColRef              
   ,kAsiSynErWrongParameterUsage    
   ,kAsiSynErLocalCol               
   ,kAsiSynErOuterCol               
   ,kAsiSynErDuplDistinct           
   ,kAsiSynErArgNotColumn           
   ,kAsiSynErNoCorrColumns          
   ,kAsiSynErWrongCorrColumn        
   ,kAsiSynErMustBeGroupCol         
   ,kAsiErSynMisLeadSetFunc         
   ,kAsiErSynWrongEscLength         
   ,kAsiErSynSimpleValue            
   ,kAsiErSynInvOrderSpec           
   ,kAsiErSynMustBeOnlyCol          
   ,kAsiErSynCursorNotFound         
   ,kAsiErSynUpdateColDupl          
   ,kAsiErSynDefaultUse             
   ,kAsiErSynWrColInsert            
   ,kAsiErSynNotCastable            
   ,kAsiErSynMisDefValue            
   ,kAsiErSynMisServerName          
   ,kAsiErSynMisCorNameForRemote    
   ,kAsiErSynWrongForUpdateColSpec  
   ,kAsiErSynNotUpdateCol           
   ,kAsiErSynTransMode              
   ,kAsiErSynMisLevel               
   ,kAsiErSynUncommComm             
   ,kAsiErSynDubIsoLevel            
   ,kAsiErSynDubDiagSize            
   ,kAsiErSynMisIsoLevel            
   ,kAsiErSynCharSetUsage           
   ,kAsiErSynCollatingSeq           
   ,kAsiErSynNotCharCollate         
   ,kAsiErSynColCharSetMisMatch     
   ,kAsiErSynDuplJoinCol            
   ,kAsiSynErCorrJoinColNotFound    
   ,kAsiSynErFunctionNotExists      
   ,kAsiSynErNoMatchFunction        
   ,kAsiSynErWrongBoolFuncUsage     
   ,kAsiSynErWrongValueFuncUsage    

   ,kAsiSQLAMBCURSOR     =  0x3C00  
   
   ,kAsiSQLINVCATNAME    =  0x3D00  
   
   ,kAsiSQLINVSCHNAME    =  0x3F00  
   
   ,kAsiSQLTR            =  0x4000  
   ,kAsiSQLTRINTEGRITY              
   ,kAsiSQLTRSER                    
   ,kAsiSQLTRSTMCOMP                
   
   ,kAsiSQLSYNACS        =  0x4200  
   
   ,kAsiSQLCHECKOPT      =  0x4400  
   
   ,kAsiSQLRDA           =  0x8000

   ,kAsiEXCP             =  0xA000  
   ,kAsiEXCPINIT                    
   ,kAsiEXCPTERM                    
   ,kAsiEXCPDUPLINIT                
   ,kAsiEXCPNOTINIT                 
   ,kAsiEXCPBADINI                  
   ,kAsiEXCPWRONGENV                
   ,kAsiEXCPWRENVPAR                
   ,kAsiNoMemory                    
   ,kAsiErStkOvrFlw                 
   ,kAsiErStkUnrFlw                 
   ,kAsiInvalidParam                
   ,kAsiInternalError               
   ,kAsiFunctionNotSupported        
   ,kAsiTryTableOverflow
   ,kAsiOperationNotSupported
   ,kAsiCannotOpenTable
   ,kAsiOutOfRange
   ,kAsiInvalidUcObject
   ,kAsiInvalidDDAObject            
   ,kAsiErrEofFound                 
   ,kAsiErrFileLocked               
   ,kAsiRecLocked                   
   ,kAsiTableLocked                 
   ,kAsiNativePrepare               
   ,kAsiNativeExecute               
   ,kAsiRemoteTabModification       
   ,kAsiInterDBExecution            
   ,kAsiErrCodePageNotDefined       
   ,kAsiErrCodePageFileNotFound     
   ,kAsiErrCodePageFormat           
   ,kAsiErrCollationNotDefined      
   ,kAsiErrCollationFileNotFound    
   ,kAsiErrCollationFormat          
   ,kAsiErrAsilocNotFound

   ,kAsiErrDrv          = 0xB000    
   ,kAsiErrOpenDrv                  
   ,kAsiErrPathNotFound             
   ,kAsiErrProvNotSpecified         
   ,kAsiErrToManyFileOpen           
   ,kAsiErrAccessDenied             
   ,kAsiErrFileHandle               
   ,kAsiErrSrvNotReg				
   ,kAsiErrCannotRegSrv				
   ,kAsiErrCannotFindSrv            
   ,kAsiErrNoRegEntryPoint 			
   ,kAsiErrCannotLoadSrvDll         
   ,kAsiErrOutPhysicalMemory        
   ,kAsiErrOutSwapSpace             
   ,kAsiErrOLEDB20NotInstalled      
   ,kAsiErrOLENotInit				
   ,kAsiErrNoVirtualMemory          
   ,kAsiErrNoConvMemory             
   ,kAsiErrMDLNotFound              
   ,kAsiErrOpenIni                  
   ,kAsiErrNoEnv                    
   ,kAsiErrIncompEnv                
   ,kAsiErrNoPath                   
   ,kAsiErrLostConnection           
   ,kAsiErrToManyDrivers            
   ,kAsiErrInvalidName              
   ,kAsiErrNotAsiDrv                
   ,kAsiErrOsEnv                    
   ,kAsiErrDrvInit                  
   ,kAsiErrDrvThunk                 
   ,kAsiErrComBuf                   
   ,kAsiErrBlockByTSR               
   ,kAsiErrNoDrv                    
   ,kAsiErrMemoryAccess             
   ,kAsiErrOS                       
   ,kAsiErrDrvOld                   
   
   ,kAsiErrDBMSServer =  0xCF00     
   ,kAsiErrHRESULT                  
   
} EAsiError;

typedef unsigned int AsiError;

#define MinUserDefErrorCode         0xE000

#pragma pack (pop)

#if defined(__cplusplus)
}
#endif  

#endif 

