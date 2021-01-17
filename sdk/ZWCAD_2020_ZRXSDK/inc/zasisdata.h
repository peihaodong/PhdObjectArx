

#ifndef ZASI_SDATA_HH
#define ZASI_SDATA_HH asisdata.hh

#include <oledb.h>

#if _MSC_VER < 1300
  #include <largeint.h>
#else
  #include <winnt.h>
#endif

#include "zasisys.h"

class DLLScope CAsiObject;                   
	class DLLScope CAsiIdent;                
	class DLLScope CAsiData;                 
		class DLLScope CAsiNum;              
			class DLLScope CAsiExactNum;     
                class DLLScope CAsiSmallInt; 
                class DLLScope CAsiInt;      
                class DLLScope CAsiNumeric;  
                class DLLScope CAsiDecimal;  
            class DLLScope CAsiApproxNum;    
                class DLLScope CAsiFloat;    
                class DLLScope CAsiReal;     
                class DLLScope CAsiDouble;   
        class DLLScope CAsiChar;             
        class DLLScope CAsiBinary;           
        class DLLScope CAsiIQualifier;       
            class DLLScope CAsiInterval;     
                class DLLScope CAsiYM;       
                class DLLScope CAsiDT;       
        class DLLScope CAsiDatetime;         
            class DLLScope CAsiDate;         
            class DLLScope CAsiTime;         
            class DLLScope CAsiTimeStamp;    
        class DLLScope CAsiBlob;             

    class DLLScope CAsiColumn;               
    class DLLScope CAsiRow;                  
    class DLLScope CAsiHostBuffer;           
        class DLLScope CAsiParameter;        
    class DLLScope CAsiImplDefFunc;

    class DLLScope CAsiIRow;                 
    class DLLScope CAsiList;                 

    class DLLScope CAsiUcStr;                
    class DLLScope CAsiUcChar;               

    class DLLScope CAsiObjPack;              

typedef char ASIBCD [34];

#include "zasiconst.h"
#include "zasiucode.h"

#pragma pack (push, 8)

class CAsiObject
{
public:
            CAsiObject                (void);
    virtual ~CAsiObject               (void);

            void*         operator new    (size_t);
            void          operator delete (void*);
#if defined(__WATCOMC__)
            void*         operator new[]    (unsigned int);
            void          operator delete[] (void*);
#endif

     virtual CAsiObject  * duplicate  (void) const;

     virtual void          Clear      (void);

     virtual unsigned long packSize        (void) const;
     virtual unsigned long packTo          (CAsiObjPack *) const;
     virtual EAsiBoolean   unpackFrom      (CAsiObjPack *);

     virtual unsigned long packValueSize   (void) const;
     virtual unsigned long packValueTo     (CAsiObjPack *) const;
     virtual EAsiBoolean   unpackValueFrom (CAsiObjPack *);
};

class CAsiIdent : public CAsiObject
{
public:

                            CAsiIdent       (void);
                            CAsiIdent       (const char *);
                            CAsiIdent       (const AsiUcStr);
                            CAsiIdent       (const CAsiUcStr &);
                            CAsiIdent       (const CAsiUcStr &, const CAsiUcStr &);
                            CAsiIdent       (const CAsiIdent &);
    virtual                 ~CAsiIdent      (void);

    void                    set             (EAsiBoolean,
                                            const CAsiUcStr &,
                                            const CAsiUcStr &);

    void                    setDelimited    (EAsiBoolean);
    void                    setDelimited    (void);
    void                    setCharSet      (const CAsiUcStr &);

    void                    setBody         (const CAsiUcStr &, EAsiBoolean fParse = kAsiTrue);

    EAsiBoolean             isDelimited     (void) const;   
    const CAsiUcStr         & CharSet       (void) const;
    const CAsiUcStr         & Body          (void) const;

    int                     Length          (void) const;

    virtual void            Clear           (void);

    CAsiIdent       &       operator=       (const CAsiIdent &);  
    CAsiIdent       &       operator=       (const CAsiUcStr &);  

    int                     operator==      (const CAsiIdent &) const;

    void                    ToString        (CAsiUcStr *) const;

    virtual CAsiObject   *  duplicate       (void) const;

    virtual unsigned long   packSize        (void) const;
    virtual unsigned long   packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean     unpackFrom      (CAsiObjPack *);

private:
    EAsiBoolean             isDelim;      
    CAsiUcStr               charset;      
    CAsiUcStr               ident;        
};

class CAsiData : public CAsiObject
{
friend class CAsiColumn;

public:

            CAsiData  (void);
    virtual ~CAsiData (void);

    virtual EAsiDataType    Type                (void) const = 0;  
    virtual EAsiDTType      DateTimeType        (void) const; 
    virtual EAsiIType       IntervalType        (void) const; 
    virtual int             ImplDataType        (void) const; 
    virtual uint            Length              (void) const; 
    virtual uint            Precision           (void) const; 
    virtual uint            Scale               (void) const; 
    virtual uint            TimePrec            (void) const; 
    virtual uint            TimeStampPrec       (void) const; 
    virtual uint            LeadFieldPrec       (void) const; 
    virtual uint            FracSecPrec         (void) const; 
    virtual uint            ReturnLength        (void) const;

    virtual EAsiBoolean     is_numeric          (void) const;
    virtual EAsiBoolean     is_exactnumeric     (void) const;
    virtual EAsiBoolean     is_approxnumeric    (void) const;
    virtual EAsiBoolean     is_character        (void) const;
    virtual EAsiBoolean     is_binary           (void) const;
    virtual EAsiBoolean     is_datetime         (void) const;
    virtual EAsiBoolean     is_interval         (void) const;
    virtual EAsiBoolean     is_yminterval       (void) const;
    virtual EAsiBoolean     is_dtinterval       (void) const;
    virtual EAsiBoolean     is_implement        (void) const;

    virtual EAsiBoolean     is_comparable       (const CAsiData *) const;
    virtual EAsiBoolean     is_storable         (const CAsiData *) const;
    virtual EAsiBoolean     is_castable         (const CAsiData *) const;

    virtual CAsiData *      checkAdd            (const CAsiData *) const;
    virtual CAsiData *      checkSub            (const CAsiData *) const;
    virtual CAsiData *      checkMul            (const CAsiData *) const;
    virtual CAsiData *      checkDiv            (const CAsiData *) const;
    virtual CAsiData *      checkCat            (const CAsiData *) const;
    virtual CAsiData *      checkSet            (const CAsiData *) const;

    virtual EAsiBoolean     isEqualTo           (const CAsiData &) const;
    virtual EAsiBoolean     isGreaterThan       (const CAsiData &) const;

    virtual CAsiImplDefFunc *  getFuncDsc       (const CAsiIdent &, const CAsiRow &) const;

    virtual void            setNull             (void);            
    virtual EAsiBoolean     isNull              (void) const;

    virtual EAsiBoolean     storeValue          (real);                 
    virtual EAsiBoolean     storeValue          (integer);              
    virtual EAsiBoolean     storeValue          (smallint);             
    virtual EAsiBoolean     storeValue          (char *, uint);         
    virtual EAsiBoolean     storeValue          (const CAsiUcStr &);    
    virtual EAsiBoolean     storeValue          (char *, uint, uint *); 
    virtual EAsiBoolean     storeValue          (const CAsiData &);     
    virtual EAsiBoolean     storeValue          (const AsiUcStr);       
    virtual EAsiBoolean		storeValue			(const DECIMAL &);
    virtual EAsiBoolean		storeValue			(const DB_NUMERIC *);
    virtual EAsiBoolean		storeValue			(const DBDATE *);
    virtual EAsiBoolean		storeValue			(const DBTIME *);
    virtual EAsiBoolean		storeValue			(const DBTIMESTAMP *);

    virtual EAsiBoolean     getValue            (real *) const;               
    virtual EAsiBoolean     getValue            (integer *) const;            
    virtual EAsiBoolean     getValue            (smallint *) const;           
    virtual EAsiBoolean     getValue            (char *, uint) const;         
    virtual EAsiBoolean     getValue            (CAsiUcStr *) const;          
    virtual EAsiBoolean     getValue            (char *, uint, uint *) const; 
    virtual EAsiBoolean     getValue            (AsiUcStr, uint) const;       
    virtual EAsiBoolean     getValue            (CAsiData &) const;           
    virtual EAsiBoolean		getValue			(DECIMAL *) const;
    virtual EAsiBoolean		getValue			(DB_NUMERIC *) const;
    virtual EAsiBoolean		getValue			(DBDATE *) const;
    virtual EAsiBoolean		getValue			(DBTIME *) const;
    virtual EAsiBoolean		getValue			(DBTIMESTAMP *) const;

    virtual EAsiBoolean     SQLType             (CAsiUcStr *) const = 0;    
    virtual EAsiBoolean     SQLLiteral          (CAsiUcStr *) const = 0;

    static CAsiData *       MapColumnInfoToAsi  (DBCOLUMNINFO * pColumnInfo);
    static CAsiData *       MapParamInfoToAsi	(DBPARAMINFO * pParamInfo);

    virtual DBCOLUMNINFO *  MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *   MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual CAsiObject*     duplicate           (void) const = 0;

    virtual void            Clear               (void);

protected:
    EAsiBoolean             isnull;                           
};

class CAsiNum : public CAsiData
{
friend class CAsiLex;
protected:
								CAsiNum ();           
public:
    virtual						~CAsiNum ();

    virtual uint                Precision       (void) const;
    virtual uint                Scale           (void) const;

        virtual EAsiBoolean     is_numeric      (void) const;
    virtual EAsiBoolean         is_exactnumeric (void) const;
    virtual EAsiBoolean         is_approxnumeric(void) const;
    virtual EAsiBoolean         is_comparable   (const CAsiData *) const;
    virtual EAsiBoolean         is_storable     (const CAsiData *) const;
    virtual EAsiBoolean         is_castable     (const CAsiData *) const;

    virtual CAsiData    *       checkAdd        (const CAsiData *) const;
    virtual CAsiData    *       checkSub        (const CAsiData *) const;
    virtual CAsiData    *       checkMul        (const CAsiData *) const;
    virtual CAsiData    *       checkDiv        (const CAsiData *) const;

    virtual integer             intValue        (void) const;
    virtual real                realValue       (void) const;

    virtual int                 operator>  (const CAsiSmallInt &) const;
    virtual int                 operator>  (const CAsiInt &)      const;
    virtual int                 operator>  (const CAsiNumeric &)  const;
    virtual int                 operator>  (const CAsiDecimal &)  const;
    virtual int                 operator>  (const CAsiFloat &)    const;
    virtual int                 operator>  (const CAsiReal &)     const;
    virtual int                 operator>  (const CAsiDouble &)   const;
    virtual int                 operator>  (const smallint)       const;
    virtual int                 operator>  (const integer)        const;
    virtual int                 operator>  (const real)           const;
    virtual int                 operator>  (const int)            const;

    virtual int                 operator>= (const CAsiSmallInt &) const;
    virtual int                 operator>= (const CAsiInt &)      const;
    virtual int                 operator>= (const CAsiNumeric &)  const;
    virtual int                 operator>= (const CAsiDecimal &)  const;
    virtual int                 operator>= (const CAsiFloat &)    const;
    virtual int                 operator>= (const CAsiReal &)     const;
    virtual int                 operator>= (const CAsiDouble &)   const;
    virtual int                 operator>= (const smallint)       const;
    virtual int                 operator>= (const integer)        const;
    virtual int                 operator>= (const real)           const;
    virtual int                 operator>= (const int)            const;

    virtual int                 operator== (const CAsiSmallInt &) const;
    virtual int                 operator== (const CAsiInt &)      const;
    virtual int                 operator== (const CAsiNumeric &)  const;
    virtual int                 operator== (const CAsiDecimal &)  const;
    virtual int                 operator== (const CAsiFloat &)    const;
    virtual int                 operator== (const CAsiReal &)     const;
    virtual int                 operator== (const CAsiDouble &)   const;
    virtual int                 operator== (const smallint)       const;
    virtual int                 operator== (const integer)        const;
    virtual int                 operator== (const real)           const;
    virtual int                 operator== (const int)            const;

    virtual int                 operator<= (const CAsiSmallInt &) const;
    virtual int                 operator<= (const CAsiInt &)      const;
    virtual int                 operator<= (const CAsiNumeric &)  const;
    virtual int                 operator<= (const CAsiDecimal &)  const;
    virtual int                 operator<= (const CAsiFloat &)    const;
    virtual int                 operator<= (const CAsiReal &)     const;
    virtual int                 operator<= (const CAsiDouble &)   const;
    virtual int                 operator<= (const smallint)       const;
    virtual int                 operator<= (const integer)        const;
    virtual int                 operator<= (const real)           const;
    virtual int                 operator<= (const int)            const;

    virtual int                 operator<  (const CAsiSmallInt &) const;
    virtual int                 operator<  (const CAsiInt &)      const;
    virtual int                 operator<  (const CAsiNumeric &)  const;
    virtual int                 operator<  (const CAsiDecimal &)  const;
    virtual int                 operator<  (const CAsiFloat &)    const;
    virtual int                 operator<  (const CAsiReal &)     const;
    virtual int                 operator<  (const CAsiDouble &)   const;
    virtual int                 operator<  (const smallint)       const;
    virtual int                 operator<  (const integer)        const;
    virtual int                 operator<  (const real)           const;
    virtual int                 operator<  (const int)            const;

    virtual int                 operator!= (const CAsiSmallInt &) const;
    virtual int                 operator!= (const CAsiInt &)      const;
    virtual int                 operator!= (const CAsiNumeric &)  const;
    virtual int                 operator!= (const CAsiDecimal &)  const;
    virtual int                 operator!= (const CAsiFloat &)    const;
    virtual int                 operator!= (const CAsiReal &)     const;
    virtual int                 operator!= (const CAsiDouble &)   const;
    virtual int                 operator!= (const smallint)       const;
    virtual int                 operator!= (const integer)        const;
    virtual int                 operator!= (const real)           const;
    virtual int                 operator!= (const int)            const;

protected:
    uint        precision;
    uint        scale;

};

class CAsiExactNum : public CAsiNum
{
protected:
							CAsiExactNum ();
public:
    virtual					~CAsiExactNum ();

    virtual EAsiBoolean		is_exactnumeric       (void) const;
    CAsiData              * checkAdd                      (const CAsiData *) const;

    virtual int         operator>  (const CAsiSmallInt &) const;
    virtual int         operator>  (const CAsiInt &)      const;
    virtual int         operator>  (const CAsiNumeric &)  const;
    virtual int         operator>  (const CAsiDecimal &)  const;
    virtual int         operator>  (const CAsiFloat &)    const;
    virtual int         operator>  (const CAsiReal &)     const;
    virtual int         operator>  (const CAsiDouble &)   const;
    virtual int         operator>  (const smallint)       const;
    virtual int         operator>  (const integer)        const;
    virtual int         operator>  (const real)           const;
    virtual int         operator>  (const int)            const;

    virtual int         operator>= (const CAsiSmallInt &) const;
    virtual int         operator>= (const CAsiInt &)      const;
    virtual int         operator>= (const CAsiNumeric &)  const;
    virtual int         operator>= (const CAsiDecimal &)  const;
    virtual int         operator>= (const CAsiFloat &)    const;
    virtual int         operator>= (const CAsiReal &)     const;
    virtual int         operator>= (const CAsiDouble &)   const;
    virtual int         operator>= (const smallint)       const;
    virtual int         operator>= (const integer)        const;
    virtual int         operator>= (const real)           const;
    virtual int         operator>= (const int)            const;

    virtual int         operator== (const CAsiSmallInt &) const;
    virtual int         operator== (const CAsiInt &)      const;
    virtual int         operator== (const CAsiNumeric &)  const;
    virtual int         operator== (const CAsiDecimal &)  const;
    virtual int         operator== (const CAsiFloat &)    const;
    virtual int         operator== (const CAsiReal &)     const;
    virtual int         operator== (const CAsiDouble &)   const;
    virtual int         operator== (const smallint)       const;
    virtual int         operator== (const integer)        const;
    virtual int         operator== (const real)           const;
    virtual int         operator== (const int)            const;

    virtual int         operator<= (const CAsiSmallInt &) const;
    virtual int         operator<= (const CAsiInt &)      const;
    virtual int         operator<= (const CAsiNumeric &)  const;
    virtual int         operator<= (const CAsiDecimal &)  const;
    virtual int         operator<= (const CAsiFloat &)    const;
    virtual int         operator<= (const CAsiReal &)     const;
    virtual int         operator<= (const CAsiDouble &)   const;
    virtual int         operator<= (const smallint)       const;
    virtual int         operator<= (const integer)        const;
    virtual int         operator<= (const real)           const;
    virtual int         operator<= (const int)            const;

    virtual int         operator<  (const CAsiSmallInt &) const;
    virtual int         operator<  (const CAsiInt &)      const;
    virtual int         operator<  (const CAsiNumeric &)  const;
    virtual int         operator<  (const CAsiDecimal &)  const;
    virtual int         operator<  (const CAsiFloat &)    const;
    virtual int         operator<  (const CAsiReal &)     const;
    virtual int         operator<  (const CAsiDouble &)   const;
    virtual int         operator<  (const smallint)       const;
    virtual int         operator<  (const integer)        const;
    virtual int         operator<  (const real)           const;
    virtual int         operator<  (const int)            const;

    virtual int         operator!= (const CAsiSmallInt &) const;
    virtual int         operator!= (const CAsiInt &)      const;
    virtual int         operator!= (const CAsiNumeric &)  const;
    virtual int         operator!= (const CAsiDecimal &)  const;
    virtual int         operator!= (const CAsiFloat &)    const;
    virtual int         operator!= (const CAsiReal &)     const;
    virtual int         operator!= (const CAsiDouble &)   const;
    virtual int         operator!= (const smallint)       const;
    virtual int         operator!= (const integer)        const;
    virtual int         operator!= (const real)           const;
    virtual int         operator!= (const int)            const;

protected:
            int         cmpeqlen(const  CAsiExactNum *)   const;
            int         cmpeqlan(const  CAsiNum *)        const;
            int         cmpeqlenC(const real)             const;
            int         cmpneqen(const  CAsiExactNum *)   const;
            int         cmpneqan(const  CAsiNum *)        const;
            int         cmpneqenC(const real)             const;
            int         cmpltren(const  CAsiExactNum *)   const;
            int         cmpltran(const  CAsiNum *)        const;
            int         cmpltrenC(const real)             const;
            int         cmplteen(const  CAsiExactNum *)   const;
            int         cmpltean(const  CAsiNum *)        const;
            int         cmplteenC(const real)             const;
            int         cmpgtren(const  CAsiExactNum *)   const;
            int         cmpgtran(const  CAsiNum *)        const;
            int         cmpgtrenC(const real)             const;
            int         cmpgteen(const  CAsiExactNum *)   const;
            int         cmpgtean(const  CAsiNum *)        const;
            int         cmpgteenC(const real)             const;

};

class CAsiApproxNum : public CAsiNum
{
protected:
						CAsiApproxNum ();     
public:
    virtual				~CAsiApproxNum ();

    virtual EAsiBoolean is_approxnumeric    (void) const;

    virtual int         operator>  (const CAsiSmallInt &) const;
    virtual int         operator>  (const CAsiInt &)      const;
    virtual int         operator>  (const CAsiNumeric &)  const;
    virtual int         operator>  (const CAsiDecimal &)  const;
    virtual int         operator>  (const CAsiFloat &)    const;
    virtual int         operator>  (const CAsiReal &)     const;
    virtual int         operator>  (const CAsiDouble &)   const;
    virtual int         operator>  (const smallint)       const;
    virtual int         operator>  (const integer)        const;
    virtual int         operator>  (const real)           const;
    virtual int         operator>  (const int)            const;

    virtual int         operator>= (const CAsiSmallInt &) const;
    virtual int         operator>= (const CAsiInt &)      const;
    virtual int         operator>= (const CAsiNumeric &)  const;
    virtual int         operator>= (const CAsiDecimal &)  const;
    virtual int         operator>= (const CAsiFloat &)    const;
    virtual int         operator>= (const CAsiReal &)     const;
    virtual int         operator>= (const CAsiDouble &)   const;
    virtual int         operator>= (const smallint)       const;
    virtual int         operator>= (const integer)        const;
    virtual int         operator>= (const real)           const;
    virtual int         operator>= (const int)            const;

    virtual int         operator== (const CAsiSmallInt &) const;
    virtual int         operator== (const CAsiInt &)      const;
    virtual int         operator== (const CAsiNumeric &)  const;
    virtual int         operator== (const CAsiDecimal &)  const;
    virtual int         operator== (const CAsiFloat &)    const;
    virtual int         operator== (const CAsiReal &)     const;
    virtual int         operator== (const CAsiDouble &)   const;
    virtual int         operator== (const smallint)       const;
    virtual int         operator== (const integer)        const;
    virtual int         operator== (const real)           const;
    virtual int         operator== (const int)            const;

    virtual int         operator<= (const CAsiSmallInt &) const;
    virtual int         operator<= (const CAsiInt &)      const;
    virtual int         operator<= (const CAsiNumeric &)  const;
    virtual int         operator<= (const CAsiDecimal &)  const;
    virtual int         operator<= (const CAsiFloat &)    const;
    virtual int         operator<= (const CAsiReal &)     const;
    virtual int         operator<= (const CAsiDouble &)   const;
    virtual int         operator<= (const smallint)       const;
    virtual int         operator<= (const integer)        const;
    virtual int         operator<= (const real)           const;
    virtual int         operator<= (const int)            const;

    virtual int         operator<  (const CAsiSmallInt &) const;
    virtual int         operator<  (const CAsiInt &)      const;
    virtual int         operator<  (const CAsiNumeric &)  const;
    virtual int         operator<  (const CAsiDecimal &)  const;
    virtual int         operator<  (const CAsiFloat &)    const;
    virtual int         operator<  (const CAsiReal &)     const;
    virtual int         operator<  (const CAsiDouble &)   const;
    virtual int         operator<  (const smallint)       const;
    virtual int         operator<  (const integer)        const;
    virtual int         operator<  (const real)           const;
    virtual int         operator<  (const int)            const;

    virtual int         operator!= (const CAsiSmallInt &) const;
    virtual int         operator!= (const CAsiInt &)      const;
    virtual int         operator!= (const CAsiNumeric &)  const;
    virtual int         operator!= (const CAsiDecimal &)  const;
    virtual int         operator!= (const CAsiFloat &)    const;
    virtual int         operator!= (const CAsiReal &)     const;
    virtual int         operator!= (const CAsiDouble &)   const;
    virtual int         operator!= (const smallint)       const;
    virtual int         operator!= (const integer)        const;
    virtual int         operator!= (const real)           const;
    virtual int         operator!= (const int)            const;

protected:

};

class CAsiSmallInt : public CAsiExactNum
{
public:
						CAsiSmallInt (void);
						CAsiSmallInt (const CAsiSmallInt &);
    virtual				~CAsiSmallInt (void);

    virtual EAsiDataType Type           (void) const;
    virtual uint         ReturnLength   (void) const;

    virtual EAsiBoolean  isEqualTo      (const CAsiData &) const;
    virtual EAsiBoolean  isGreaterThan  (const CAsiData &) const;

    virtual CAsiData *   checkAdd       (const CAsiData *) const;
    virtual CAsiData *   checkSub       (const CAsiData *) const;
    virtual CAsiData *   checkMul       (const CAsiData *) const;
    virtual CAsiData *   checkDiv       (const CAsiData *) const;
    virtual CAsiData *   checkSet       (const CAsiData *) const;

    virtual EAsiBoolean   storeValue (real) ;
    virtual EAsiBoolean   storeValue (integer) ;
    virtual EAsiBoolean   storeValue (smallint) ;
    virtual EAsiBoolean   storeValue (char *, uint) ;
    virtual EAsiBoolean   storeValue (const CAsiUcStr &) ;
    virtual EAsiBoolean   storeValue (const CAsiData &);

    virtual EAsiBoolean   storeValue (char *, uint, uint *);
    virtual EAsiBoolean   storeValue (const AsiUcStr);

    virtual integer       intValue  (void) const;
    virtual real          realValue (void) const;

    virtual EAsiBoolean   getValue (real *) const;
    virtual EAsiBoolean   getValue (integer *) const;
    virtual EAsiBoolean   getValue (smallint *) const;
    virtual EAsiBoolean   getValue (char *, uint) const;
    virtual EAsiBoolean   getValue (CAsiUcStr *) const;

    virtual EAsiBoolean   getValue (char *, uint, uint *) const; 
    virtual EAsiBoolean   getValue (AsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue (CAsiData &) const;

    virtual DBCOLUMNINFO *  MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *   MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean   SQLType    (CAsiUcStr *) const;        
    virtual EAsiBoolean   SQLLiteral (CAsiUcStr *) const;

    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (CAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (CAsiObjPack *) ;

    virtual CAsiObject   *duplicate (void) const;

            CAsiSmallInt &operator= (const CAsiSmallInt &);
            CAsiSmallInt &operator= (const CAsiInt &);
            CAsiSmallInt &operator= (const CAsiNumeric &);
            CAsiSmallInt &operator= (const CAsiDecimal &);
            CAsiSmallInt &operator= (const CAsiFloat &);
            CAsiSmallInt &operator= (const CAsiReal &);
            CAsiSmallInt &operator= (const CAsiDouble &);
            CAsiSmallInt &operator= (const smallint);
            CAsiSmallInt &operator= (const integer);
            CAsiSmallInt &operator= (const real);
            CAsiSmallInt &operator= (const int);

            CAsiSmallInt &operator+= (const CAsiSmallInt &);
            CAsiSmallInt &operator+= (const CAsiInt &);
            CAsiSmallInt &operator+= (const CAsiNumeric &);
            CAsiSmallInt &operator+= (const CAsiDecimal &);
            CAsiSmallInt &operator+= (const CAsiFloat &);
            CAsiSmallInt &operator+= (const CAsiReal &);
            CAsiSmallInt &operator+= (const CAsiDouble &);
            CAsiSmallInt &operator+= (const smallint);
            CAsiSmallInt &operator+= (const integer);
            CAsiSmallInt &operator+= (const real);
            CAsiSmallInt &operator+= (const int);

            CAsiSmallInt &operator-= (const CAsiSmallInt &);
            CAsiSmallInt &operator-= (const CAsiInt &);
            CAsiSmallInt &operator-= (const CAsiNumeric &);
            CAsiSmallInt &operator-= (const CAsiDecimal &);
            CAsiSmallInt &operator-= (const CAsiFloat &);
            CAsiSmallInt &operator-= (const CAsiReal &);
            CAsiSmallInt &operator-= (const CAsiDouble &);
            CAsiSmallInt &operator-= (const smallint);
            CAsiSmallInt &operator-= (const integer);
            CAsiSmallInt &operator-= (const real);
            CAsiSmallInt &operator-= (const int);

            CAsiSmallInt &operator*= (const CAsiSmallInt &);
            CAsiSmallInt &operator*= (const CAsiInt &);
            CAsiSmallInt &operator*= (const CAsiNumeric &);
            CAsiSmallInt &operator*= (const CAsiDecimal &);
            CAsiSmallInt &operator*= (const CAsiFloat &);
            CAsiSmallInt &operator*= (const CAsiReal &);
            CAsiSmallInt &operator*= (const CAsiDouble &);
            CAsiSmallInt &operator*= (const smallint);
            CAsiSmallInt &operator*= (const integer);
            CAsiSmallInt &operator*= (const real);
            CAsiSmallInt &operator*= (const int);

            CAsiSmallInt &operator/= (const CAsiSmallInt &);
            CAsiSmallInt &operator/= (const CAsiInt &);
            CAsiSmallInt &operator/= (const CAsiNumeric &);
            CAsiSmallInt &operator/= (const CAsiDecimal &);
            CAsiSmallInt &operator/= (const CAsiFloat &);
            CAsiSmallInt &operator/= (const CAsiReal &);
            CAsiSmallInt &operator/= (const CAsiDouble &);
            CAsiSmallInt &operator/= (const smallint);
            CAsiSmallInt &operator/= (const integer);
            CAsiSmallInt &operator/= (const real);
            CAsiSmallInt &operator/= (const int);

            CAsiDouble operator+ (const CAsiSmallInt &) const;
            CAsiDouble operator+ (const smallint)       const;
            CAsiDouble operator+ (const integer)        const;
            CAsiDouble operator+ (const real)           const;
            CAsiDouble operator+ (const int)            const;
     friend CAsiDouble DLLScope operator+ (const smallint, const CAsiSmallInt &);
     friend CAsiDouble DLLScope operator+ (const integer,  const CAsiSmallInt &);
     friend CAsiDouble DLLScope operator+ (const real,     const CAsiSmallInt &);
     friend CAsiDouble DLLScope operator+ (const int,      const CAsiSmallInt &);

            CAsiDouble operator- (const CAsiSmallInt &) const;
            CAsiDouble operator- (const smallint)       const;
            CAsiDouble operator- (const integer)        const;
            CAsiDouble operator- (const real)           const;
            CAsiDouble operator- (const int)            const;
     friend CAsiDouble DLLScope operator- (const smallint, const CAsiSmallInt &);
     friend CAsiDouble DLLScope operator- (const integer,  const CAsiSmallInt &);
     friend CAsiDouble DLLScope operator- (const real,     const CAsiSmallInt &);
     friend CAsiDouble DLLScope operator- (const int,      const CAsiSmallInt &);

            CAsiDouble operator* (const CAsiSmallInt &) const;
            CAsiDouble operator* (const smallint)       const;
            CAsiDouble operator* (const integer)        const;
            CAsiDouble operator* (const real)           const;
            CAsiDouble operator* (const int)            const;
     friend CAsiDouble DLLScope operator* (const smallint, const CAsiSmallInt &);
     friend CAsiDouble DLLScope operator* (const integer,  const CAsiSmallInt &);
     friend CAsiDouble DLLScope operator* (const real,     const CAsiSmallInt &);
     friend CAsiDouble DLLScope operator* (const int,      const CAsiSmallInt &);

            CAsiDouble operator/ (const CAsiSmallInt &) const;
            CAsiDouble operator/ (const smallint)  const;
            CAsiDouble operator/ (const integer)   const;
            CAsiDouble operator/ (const real)      const;
            CAsiDouble operator/ (const int)       const;
     friend CAsiDouble DLLScope operator/ (const smallint, const CAsiSmallInt &);
     friend CAsiDouble DLLScope operator/ (const integer,  const CAsiSmallInt &);
     friend CAsiDouble DLLScope operator/ (const real,     const CAsiSmallInt &);
     friend CAsiDouble DLLScope operator/ (const int,      const CAsiSmallInt &);

            CAsiSmallInt &operator-- (void);
            CAsiSmallInt &operator++ (void);

            CAsiSmallInt &operator-  (void);

private:
    smallint sivalue;
};

class CAsiInt : public CAsiExactNum
{
public:
						CAsiInt ();
						CAsiInt (const CAsiInt &);
    virtual				~CAsiInt ();

    virtual EAsiDataType Type           (void) const;
    virtual uint         ReturnLength   (void) const;

    virtual CAsiData *   checkAdd       (const CAsiData *) const;
    virtual CAsiData *   checkSub       (const CAsiData *) const;
    virtual CAsiData *   checkMul       (const CAsiData *) const;
    virtual CAsiData *   checkDiv       (const CAsiData *) const;
    virtual CAsiData *   checkSet       (const CAsiData *) const;

    virtual EAsiBoolean  isEqualTo      (const CAsiData &) const;
    virtual EAsiBoolean  isGreaterThan  (const CAsiData &) const;

    virtual EAsiBoolean   storeValue (real);
    virtual EAsiBoolean   storeValue (integer);
    virtual EAsiBoolean   storeValue (smallint);
    virtual EAsiBoolean   storeValue (char *, uint);
    virtual EAsiBoolean   storeValue (const CAsiUcStr &);
    virtual EAsiBoolean   storeValue (const CAsiData &);

    virtual EAsiBoolean   storeValue (char *, uint, uint *);
    virtual EAsiBoolean   storeValue (const AsiUcStr);

    virtual integer       intValue  (void) const;
    virtual real          realValue (void) const;

    virtual EAsiBoolean   getValue (real *) const;
    virtual EAsiBoolean   getValue (integer *) const;
    virtual EAsiBoolean   getValue (smallint *) const;
    virtual EAsiBoolean   getValue (char *, uint) const;
    virtual EAsiBoolean   getValue (CAsiUcStr *) const;

    virtual EAsiBoolean   getValue (char *, uint, uint *) const; 
    virtual EAsiBoolean   getValue (AsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue (CAsiData &) const;

    virtual DBCOLUMNINFO *  MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *   MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean   SQLType    (CAsiUcStr *) const;        
    virtual EAsiBoolean   SQLLiteral (CAsiUcStr *) const;

    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (CAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (CAsiObjPack *) ;

    virtual CAsiObject   *duplicate (void) const;

            CAsiInt &operator= (const CAsiSmallInt &);
            CAsiInt &operator= (const CAsiInt &);
            CAsiInt &operator= (const CAsiNumeric &);
            CAsiInt &operator= (const CAsiDecimal &);
            CAsiInt &operator= (const CAsiFloat &);
            CAsiInt &operator= (const CAsiReal &);
            CAsiInt &operator= (const CAsiDouble &);
            CAsiInt &operator= (const smallint);
            CAsiInt &operator= (const integer);
            CAsiInt &operator= (const real);
            CAsiInt &operator= (const int);

            CAsiInt &operator+= (const CAsiSmallInt &);
            CAsiInt &operator+= (const CAsiInt &);
            CAsiInt &operator+= (const CAsiNumeric &);
            CAsiInt &operator+= (const CAsiDecimal &);
            CAsiInt &operator+= (const CAsiFloat &);
            CAsiInt &operator+= (const CAsiReal &);
            CAsiInt &operator+= (const CAsiDouble &);
            CAsiInt &operator+= (const smallint);
            CAsiInt &operator+= (const integer);
            CAsiInt &operator+= (const real);
            CAsiInt &operator+= (const int);

            CAsiInt &operator-= (const CAsiSmallInt &);
            CAsiInt &operator-= (const CAsiInt &);
            CAsiInt &operator-= (const CAsiNumeric &);
            CAsiInt &operator-= (const CAsiDecimal &);
            CAsiInt &operator-= (const CAsiFloat &);
            CAsiInt &operator-= (const CAsiReal &);
            CAsiInt &operator-= (const CAsiDouble &);
            CAsiInt &operator-= (const smallint);
            CAsiInt &operator-= (const integer);
            CAsiInt &operator-= (const real);
            CAsiInt &operator-= (const int);

            CAsiInt &operator*= (const CAsiSmallInt &);
            CAsiInt &operator*= (const CAsiInt &);
            CAsiInt &operator*= (const CAsiNumeric &);
            CAsiInt &operator*= (const CAsiDecimal &);
            CAsiInt &operator*= (const CAsiFloat &);
            CAsiInt &operator*= (const CAsiReal &);
            CAsiInt &operator*= (const CAsiDouble &);
            CAsiInt &operator*= (const smallint);
            CAsiInt &operator*= (const integer);
            CAsiInt &operator*= (const real);
            CAsiInt &operator*= (const int);

            CAsiInt &operator/= (const CAsiSmallInt &);
            CAsiInt &operator/= (const CAsiInt &);
            CAsiInt &operator/= (const CAsiNumeric &);
            CAsiInt &operator/= (const CAsiDecimal &);
            CAsiInt &operator/= (const CAsiFloat &);
            CAsiInt &operator/= (const CAsiReal &);
            CAsiInt &operator/= (const CAsiDouble &);
            CAsiInt &operator/= (const smallint);
            CAsiInt &operator/= (const integer);
            CAsiInt &operator/= (const real);
            CAsiInt &operator/= (const int);

            CAsiDouble operator+ (const CAsiSmallInt &) const;
     friend CAsiDouble DLLScope operator+ (const CAsiSmallInt &, const CAsiInt &);
            CAsiDouble operator+ (const CAsiInt &) const;
            CAsiDouble operator+ (const smallint)  const;
     friend CAsiDouble DLLScope operator+ (const smallint, const CAsiInt &);
            CAsiDouble operator+ (const integer) const;
     friend CAsiDouble DLLScope operator+ (const integer, const CAsiInt &);
            CAsiDouble operator+ (const real) const;
     friend CAsiDouble DLLScope operator+ (const real, const CAsiInt &);
            CAsiDouble operator+ (const int) const;
     friend CAsiDouble DLLScope operator+ (const int, const CAsiInt &);

            CAsiDouble operator- (const CAsiSmallInt &) const;
     friend CAsiDouble DLLScope operator- (const CAsiSmallInt &, const CAsiInt &);
            CAsiDouble operator- (const CAsiInt &) const;
            CAsiDouble operator- (const smallint)  const;
     friend CAsiDouble DLLScope operator- (const smallint, const CAsiInt &);
            CAsiDouble operator- (const integer) const;
     friend CAsiDouble DLLScope operator- (const integer, const CAsiInt &);
            CAsiDouble operator- (const real) const;
     friend CAsiDouble DLLScope operator- (const real, const CAsiInt &);
            CAsiDouble operator- (const int) const;
     friend CAsiDouble DLLScope operator- (const int, const CAsiInt &);

            CAsiDouble operator* (const CAsiSmallInt &) const;
     friend CAsiDouble DLLScope operator* (const CAsiSmallInt &, const CAsiInt &);
            CAsiDouble operator* (const CAsiInt &) const;
            CAsiDouble operator* (const smallint)  const;
     friend CAsiDouble DLLScope operator* (const smallint, const CAsiInt &);
            CAsiDouble operator* (const integer) const;
     friend CAsiDouble DLLScope operator* (const integer, const CAsiInt &);
            CAsiDouble operator* (const real) const;
     friend CAsiDouble DLLScope operator* (const real, const CAsiInt &);
            CAsiDouble operator* (const int) const;
     friend CAsiDouble DLLScope operator* (const int, const CAsiInt &);

            CAsiDouble operator/ (const CAsiSmallInt &) const;
     friend CAsiDouble DLLScope operator/ (const CAsiSmallInt &, const CAsiInt &);
            CAsiDouble operator/ (const CAsiInt &) const;
            CAsiDouble operator/ (const smallint) const;
     friend CAsiDouble DLLScope operator/ (const smallint, const CAsiInt &);
            CAsiDouble operator/ (const integer) const;
     friend CAsiDouble DLLScope operator/ (const integer, const CAsiInt &);
            CAsiDouble operator/ (const real) const;
     friend CAsiDouble DLLScope operator/ (const real, const CAsiInt &);
            CAsiDouble operator/ (const int) const;
     friend CAsiDouble DLLScope operator/ (const int, const CAsiInt &);

            CAsiInt &operator-- (void);
            CAsiInt &operator++ (void);

            CAsiInt &operator-  (void);

private:
    integer ivalue;
};

class CAsiNumeric: public CAsiExactNum
{
friend class CAsiDecimal;
private:
    
            EAsiBoolean SetNumeric (real);

public:
                                CAsiNumeric     (uint, uint);
                                CAsiNumeric     (uint);
                                CAsiNumeric     (const CAsiNumeric &);
                                CAsiNumeric     (void);
    virtual                     ~CAsiNumeric    (void);

    virtual EAsiDataType Type           (void) const;
    virtual uint         ReturnLength   (void) const;

    virtual CAsiData *   checkAdd       (const CAsiData *) const;
    virtual CAsiData *   checkSub       (const CAsiData *) const;
    virtual CAsiData *   checkMul       (const CAsiData *) const;
    virtual CAsiData *   checkDiv       (const CAsiData *) const;
    virtual CAsiData *   checkSet       (const CAsiData *) const;

    virtual EAsiBoolean  isEqualTo      (const CAsiData &) const;
    virtual EAsiBoolean  isGreaterThan  (const CAsiData &) const;

    virtual EAsiBoolean   storeValue (real);
    virtual EAsiBoolean   storeValue (integer);
    virtual EAsiBoolean   storeValue (smallint);
    virtual EAsiBoolean   storeValue (char *, uint);
    virtual EAsiBoolean   storeValue (const CAsiUcStr &);
    virtual EAsiBoolean   storeValue (const CAsiData &);
    virtual EAsiBoolean   storeValue (const DB_NUMERIC *);

    virtual EAsiBoolean   storeValue (char *, uint, uint *);
    virtual EAsiBoolean   storeValue (const AsiUcStr);

    virtual DBCOLUMNINFO *  MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *   MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean   SQLType    (CAsiUcStr *) const;        
    virtual EAsiBoolean   SQLLiteral (CAsiUcStr *) const;

    virtual integer       intValue  (void) const;
    virtual real          realValue (void) const;

    virtual EAsiBoolean   getValue (real *) const;
    virtual EAsiBoolean   getValue (integer *) const;
    virtual EAsiBoolean   getValue (smallint *) const;
    virtual EAsiBoolean   getValue (char *, uint) const;
    virtual EAsiBoolean   getValue (CAsiUcStr *) const;
    virtual EAsiBoolean   getValue (DB_NUMERIC *) const;

    virtual EAsiBoolean   getValue (char *, uint, uint *) const; 
    virtual EAsiBoolean   getValue (AsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue (CAsiData &) const;

    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (CAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (CAsiObjPack *) ;

    virtual CAsiObject     *duplicate (void) const;

            CAsiNumeric &operator= (const CAsiSmallInt &);
            CAsiNumeric &operator= (const CAsiInt &);
            CAsiNumeric &operator= (const CAsiNumeric &);
            CAsiNumeric &operator= (const CAsiDecimal &);
            CAsiNumeric &operator= (const CAsiFloat &);
            CAsiNumeric &operator= (const CAsiReal &);
            CAsiNumeric &operator= (const CAsiDouble &);
            CAsiNumeric &operator= (const smallint);
            CAsiNumeric &operator= (const integer);
            CAsiNumeric &operator= (const real);
            CAsiNumeric &operator= (const int);

            CAsiNumeric &operator+= (const CAsiSmallInt &);
            CAsiNumeric &operator+= (const CAsiInt &);
            CAsiNumeric &operator+= (const CAsiNumeric &);
            CAsiNumeric &operator+= (const CAsiDecimal &);
            CAsiNumeric &operator+= (const CAsiFloat &);
            CAsiNumeric &operator+= (const CAsiReal &);
            CAsiNumeric &operator+= (const CAsiDouble &);
            CAsiNumeric &operator+= (const smallint);
            CAsiNumeric &operator+= (const integer);
            CAsiNumeric &operator+= (const real);
            CAsiNumeric &operator+= (const int);

            CAsiNumeric &operator-= (const CAsiSmallInt &);
            CAsiNumeric &operator-= (const CAsiInt &);
            CAsiNumeric &operator-= (const CAsiNumeric &);
            CAsiNumeric &operator-= (const CAsiDecimal &);
            CAsiNumeric &operator-= (const CAsiFloat &);
            CAsiNumeric &operator-= (const CAsiReal &);
            CAsiNumeric &operator-= (const CAsiDouble &);
            CAsiNumeric &operator-= (const smallint);
            CAsiNumeric &operator-= (const integer);
            CAsiNumeric &operator-= (const real);
            CAsiNumeric &operator-= (const int);

            CAsiNumeric &operator*= (const CAsiSmallInt &);
            CAsiNumeric &operator*= (const CAsiInt &);
            CAsiNumeric &operator*= (const CAsiNumeric &);
            CAsiNumeric &operator*= (const CAsiDecimal &);
            CAsiNumeric &operator*= (const CAsiFloat &);
            CAsiNumeric &operator*= (const CAsiReal &);
            CAsiNumeric &operator*= (const CAsiDouble &);
            CAsiNumeric &operator*= (const smallint);
            CAsiNumeric &operator*= (const integer);
            CAsiNumeric &operator*= (const real);
            CAsiNumeric &operator*= (const int);

            CAsiNumeric &operator/= (const CAsiSmallInt &);
            CAsiNumeric &operator/= (const CAsiInt &);
            CAsiNumeric &operator/= (const CAsiNumeric &);
            CAsiNumeric &operator/= (const CAsiDecimal &);
            CAsiNumeric &operator/= (const CAsiFloat &);
            CAsiNumeric &operator/= (const CAsiReal &);
            CAsiNumeric &operator/= (const CAsiDouble &);
            CAsiNumeric &operator/= (const smallint);
            CAsiNumeric &operator/= (const integer);
            CAsiNumeric &operator/= (const real);
            CAsiNumeric &operator/= (const int);

            CAsiDouble operator+ (const CAsiSmallInt &) const;
            CAsiDouble operator+ (const CAsiInt &)      const;
            CAsiDouble operator+ (const CAsiNumeric &)  const;
     friend CAsiDouble DLLScope operator+ (const CAsiSmallInt &, const CAsiNumeric &);
     friend CAsiDouble DLLScope operator+ (const CAsiInt &, const CAsiNumeric &);
            CAsiDouble operator+ (const smallint) const;
            CAsiDouble operator+ (const integer)  const;
            CAsiDouble operator+ (const real)     const;
            CAsiDouble operator+ (const int)      const;
     friend CAsiDouble DLLScope operator+ (const smallint, const CAsiNumeric &);
     friend CAsiDouble DLLScope operator+ (const integer, const CAsiNumeric &);
     friend CAsiDouble DLLScope operator+ (const real, const CAsiNumeric &);
     friend CAsiDouble DLLScope operator+ (const int, const CAsiNumeric &);

            CAsiDouble operator- (const CAsiSmallInt &) const;
            CAsiDouble operator- (const CAsiInt &)      const;
            CAsiDouble operator- (const CAsiNumeric &)  const;
     friend CAsiDouble DLLScope operator- (const CAsiSmallInt &, const CAsiNumeric &);
     friend CAsiDouble DLLScope operator- (const CAsiInt &, const CAsiNumeric &);
            CAsiDouble operator- (const smallint) const;
            CAsiDouble operator- (const integer)  const;
            CAsiDouble operator- (const real)     const;
            CAsiDouble operator- (const int)      const;
     friend CAsiDouble DLLScope operator- (const smallint, const CAsiNumeric &);
     friend CAsiDouble DLLScope operator- (const integer, const CAsiNumeric &);
     friend CAsiDouble DLLScope operator- (const real, const CAsiNumeric &);
     friend CAsiDouble DLLScope operator- (const int, const CAsiNumeric &) ;

            CAsiDouble operator* (const CAsiSmallInt &) const;
            CAsiDouble operator* (const CAsiInt &)      const;
            CAsiDouble operator* (const CAsiNumeric &)  const;
     friend CAsiDouble DLLScope operator* (const CAsiSmallInt &, const CAsiNumeric &);
     friend CAsiDouble DLLScope operator* (const CAsiInt &, const CAsiNumeric &);
            CAsiDouble operator* (const smallint) const;
            CAsiDouble operator* (const integer)  const;
            CAsiDouble operator* (const real)     const;
            CAsiDouble operator* (const int)      const;
     friend CAsiDouble DLLScope operator* (const smallint, const CAsiNumeric &);
     friend CAsiDouble DLLScope operator* (const integer, const CAsiNumeric &) ;
     friend CAsiDouble DLLScope operator* (const real, const CAsiNumeric &)    ;
     friend CAsiDouble DLLScope operator* (const int, const CAsiNumeric &)     ;

            CAsiDouble operator/ (const CAsiSmallInt &) const;
            CAsiDouble operator/ (const CAsiInt &)      const;
            CAsiDouble operator/ (const CAsiNumeric &)  const;
     friend CAsiDouble DLLScope operator/ (const CAsiSmallInt &, const CAsiNumeric &);
     friend CAsiDouble DLLScope operator/ (const CAsiInt &, const CAsiNumeric &)     ;
            CAsiDouble operator/ (const smallint) const;
            CAsiDouble operator/ (const integer)  const;
            CAsiDouble operator/ (const real)     const;
            CAsiDouble operator/ (const int)      const;
     friend CAsiDouble DLLScope operator/ (const smallint, const CAsiNumeric &);
     friend CAsiDouble DLLScope operator/ (const integer, const CAsiNumeric &) ;
     friend CAsiDouble DLLScope operator/ (const real, const CAsiNumeric &)    ;
     friend CAsiDouble DLLScope operator/ (const int, const CAsiNumeric &)     ;

            CAsiNumeric &operator++ (void);
            CAsiNumeric &operator-- (void);

            CAsiNumeric &operator- (void);

private:
        ASIBCD  bcdvalue;

};

class CAsiDecimal: public CAsiExactNum
{
friend class CAsiNumeric;
private:
    
            EAsiBoolean SetDecimal (real);

public:
            CAsiDecimal  (uint, uint);
            CAsiDecimal  (uint);
            CAsiDecimal  (const CAsiDecimal &);
            CAsiDecimal  (void);
    virtual ~CAsiDecimal (void);

    virtual EAsiDataType Type          (void) const;
    virtual uint         ReturnLength  (void) const;

    virtual CAsiData *   checkAdd      (const CAsiData *) const;
    virtual CAsiData *   checkSub      (const CAsiData *) const;
    virtual CAsiData *   checkMul      (const CAsiData *) const;
    virtual CAsiData *   checkDiv      (const CAsiData *) const;
    virtual CAsiData *   checkSet      (const CAsiData *) const;

    virtual EAsiBoolean  isEqualTo     (const CAsiData &) const;
    virtual EAsiBoolean  isGreaterThan (const CAsiData &) const;

    virtual EAsiBoolean   storeValue (real);
    virtual EAsiBoolean   storeValue (integer);
    virtual EAsiBoolean   storeValue (smallint);
    virtual EAsiBoolean   storeValue (char *, uint);
    virtual EAsiBoolean   storeValue (const CAsiUcStr &);
    virtual EAsiBoolean   storeValue (const CAsiData &);
    virtual EAsiBoolean   storeValue (LARGE_INTEGER);
    virtual EAsiBoolean   storeValue (ULARGE_INTEGER);
    virtual EAsiBoolean   storeValue (const DECIMAL &);

    virtual EAsiBoolean   storeValue (char *, uint, uint *);
    virtual EAsiBoolean   storeValue (const AsiUcStr);

    virtual DBCOLUMNINFO *  MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *   MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean   SQLType    (CAsiUcStr *) const;        
    virtual EAsiBoolean   SQLLiteral (CAsiUcStr *) const;

    virtual integer       intValue  (void) const;
    virtual real          realValue (void) const;

    virtual EAsiBoolean   getValue (real *) const;
    virtual EAsiBoolean   getValue (integer *) const;
    virtual EAsiBoolean   getValue (smallint *) const;
    virtual EAsiBoolean   getValue (char *, uint) const;
    virtual EAsiBoolean   getValue (CAsiUcStr *) const;
    virtual EAsiBoolean   getValue (LARGE_INTEGER *) const;
    virtual EAsiBoolean   getValue (ULARGE_INTEGER *) const;
    virtual EAsiBoolean   getValue (DECIMAL *) const;

    virtual EAsiBoolean   getValue (char *, uint, uint *) const; 
    virtual EAsiBoolean   getValue (AsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue (CAsiData &) const;

    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (CAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (CAsiObjPack *);

    virtual CAsiObject   *duplicate (void) const;

            CAsiDecimal &operator= (const CAsiSmallInt &);
            CAsiDecimal &operator= (const CAsiInt &);
            CAsiDecimal &operator= (const CAsiNumeric &);
            CAsiDecimal &operator= (const CAsiDecimal &);
            CAsiDecimal &operator= (const CAsiFloat &);
            CAsiDecimal &operator= (const CAsiReal &);
            CAsiDecimal &operator= (const CAsiDouble &);
            CAsiDecimal &operator= (const smallint);
            CAsiDecimal &operator= (const integer);
            CAsiDecimal &operator= (const real);
            CAsiDecimal &operator= (const int);

            CAsiDecimal &operator+= (const CAsiSmallInt &);
            CAsiDecimal &operator+= (const CAsiInt &);
            CAsiDecimal &operator+= (const CAsiNumeric &);
            CAsiDecimal &operator+= (const CAsiDecimal &);
            CAsiDecimal &operator+= (const CAsiFloat &);
            CAsiDecimal &operator+= (const CAsiReal &);
            CAsiDecimal &operator+= (const CAsiDouble &);
            CAsiDecimal &operator+= (const smallint);
            CAsiDecimal &operator+= (const integer);
            CAsiDecimal &operator+= (const real);
            CAsiDecimal &operator+= (const int);

            CAsiDecimal &operator-= (const CAsiSmallInt &);
            CAsiDecimal &operator-= (const CAsiInt &);
            CAsiDecimal &operator-= (const CAsiNumeric &);
            CAsiDecimal &operator-= (const CAsiDecimal &);
            CAsiDecimal &operator-= (const CAsiFloat &);
            CAsiDecimal &operator-= (const CAsiReal &);
            CAsiDecimal &operator-= (const CAsiDouble &);
            CAsiDecimal &operator-= (const smallint);
            CAsiDecimal &operator-= (const integer);
            CAsiDecimal &operator-= (const real);
            CAsiDecimal &operator-= (const int);

            CAsiDecimal &operator*= (const CAsiSmallInt &);
            CAsiDecimal &operator*= (const CAsiInt &);
            CAsiDecimal &operator*= (const CAsiNumeric &);
            CAsiDecimal &operator*= (const CAsiDecimal &);
            CAsiDecimal &operator*= (const CAsiFloat &);
            CAsiDecimal &operator*= (const CAsiReal &);
            CAsiDecimal &operator*= (const CAsiDouble &);
            CAsiDecimal &operator*= (const smallint);
            CAsiDecimal &operator*= (const integer);
            CAsiDecimal &operator*= (const real);
            CAsiDecimal &operator*= (const int);

            CAsiDecimal &operator/= (const CAsiSmallInt &);
            CAsiDecimal &operator/= (const CAsiInt &);
            CAsiDecimal &operator/= (const CAsiNumeric &);
            CAsiDecimal &operator/= (const CAsiDecimal &);
            CAsiDecimal &operator/= (const CAsiFloat &);
            CAsiDecimal &operator/= (const CAsiReal &);
            CAsiDecimal &operator/= (const CAsiDouble &);
            CAsiDecimal &operator/= (const smallint);
            CAsiDecimal &operator/= (const integer);
            CAsiDecimal &operator/= (const real);
            CAsiDecimal &operator/= (const int);

            CAsiDouble operator+ (const CAsiSmallInt &) const;
            CAsiDouble operator+ (const CAsiInt &)      const;
            CAsiDouble operator+ (const CAsiNumeric &)  const;
            CAsiDouble operator+ (const CAsiDecimal &)  const;
     friend CAsiDouble DLLScope operator+ (const CAsiSmallInt &, const CAsiDecimal &);
     friend CAsiDouble DLLScope operator+ (const CAsiInt &, const CAsiDecimal &)     ;
     friend CAsiDouble DLLScope operator+ (const CAsiNumeric &, const CAsiDecimal &) ;
            CAsiDouble operator+ (const smallint) const;
            CAsiDouble operator+ (const integer)  const;
            CAsiDouble operator+ (const real)     const;
     friend CAsiDouble DLLScope operator+ (const smallint, const CAsiDecimal &);
     friend CAsiDouble DLLScope operator+ (const integer, const CAsiDecimal &) ;
     friend CAsiDouble DLLScope operator+ (const real, const CAsiDecimal &)    ;
            CAsiDouble operator+ (const int) const;
     friend CAsiDouble operator+ (const int, const CAsiDecimal &);

            CAsiDouble operator- (const CAsiSmallInt &) const;
            CAsiDouble operator- (const CAsiInt &)      const;
            CAsiDouble operator- (const CAsiNumeric &)  const;
            CAsiDouble operator- (const CAsiDecimal &)  const;
     friend CAsiDouble DLLScope operator- (const CAsiSmallInt &, const CAsiDecimal &);
     friend CAsiDouble DLLScope operator- (const CAsiInt &, const CAsiDecimal &);
     friend CAsiDouble DLLScope operator- (const CAsiNumeric &, const CAsiDecimal &);
            CAsiDouble operator- (const smallint) const;
            CAsiDouble operator- (const integer)  const;
            CAsiDouble operator- (const real)     const;
     friend CAsiDouble DLLScope operator- (const smallint, const CAsiDecimal &);
     friend CAsiDouble DLLScope operator- (const integer, const CAsiDecimal &) ;
     friend CAsiDouble DLLScope operator- (const real, const CAsiDecimal &)    ;
            CAsiDouble operator- (const int) const;
     friend CAsiDouble DLLScope operator- (const int, const CAsiDecimal &);

            CAsiDouble operator* (const CAsiSmallInt &) const;
            CAsiDouble operator* (const CAsiInt &)      const;
            CAsiDouble operator* (const CAsiNumeric &)  const;
            CAsiDouble operator* (const CAsiDecimal &)  const;
     friend CAsiDouble DLLScope operator* (const CAsiSmallInt &, const CAsiDecimal &);
     friend CAsiDouble DLLScope operator* (const CAsiInt &, const CAsiDecimal &)     ;
     friend CAsiDouble DLLScope operator* (const CAsiNumeric &, const CAsiDecimal &) ;
            CAsiDouble operator* (const smallint) const;
            CAsiDouble operator* (const integer)  const;
            CAsiDouble operator* (const real)     const;
     friend CAsiDouble DLLScope operator* (const smallint, const CAsiDecimal &);
     friend CAsiDouble DLLScope operator* (const integer, const CAsiDecimal &) ;
     friend CAsiDouble DLLScope operator* (const real, const CAsiDecimal &)    ;
            CAsiDouble operator* (const int) const                         ;
     friend CAsiDouble DLLScope operator* (const int, const CAsiDecimal &)     ;

            CAsiDouble operator/ (const CAsiSmallInt &) const;
            CAsiDouble operator/ (const CAsiInt &)      const;
            CAsiDouble operator/ (const CAsiNumeric &)  const;
            CAsiDouble operator/ (const CAsiDecimal &)  const;
     friend CAsiDouble DLLScope operator/ (const CAsiSmallInt &, const CAsiDecimal &);
     friend CAsiDouble DLLScope operator/ (const CAsiInt &, const CAsiDecimal &);
     friend CAsiDouble DLLScope operator/ (const CAsiNumeric &, const CAsiDecimal &);
            CAsiDouble operator/ (const smallint) const;
            CAsiDouble operator/ (const integer)  const;
            CAsiDouble operator/ (const real)     const;
     friend CAsiDouble DLLScope operator/ (const smallint, const CAsiDecimal &);
     friend CAsiDouble DLLScope operator/ (const integer, const CAsiDecimal &) ;
     friend CAsiDouble DLLScope operator/ (const real, const CAsiDecimal &)    ;
            CAsiDouble operator/ (const int) const;
     friend CAsiDouble DLLScope operator/ (const int, const CAsiDecimal &);

            CAsiDecimal &operator++ (void);
            CAsiDecimal &operator-- (void);
            CAsiDecimal &operator- (void);

private:
    EAsiBoolean fmt;
    ASIBCD      bcdvalue;
    double      realvalue;

};

class CAsiFloat: public CAsiApproxNum
{
public:
                                CAsiFloat               (void);
                                CAsiFloat               (uint);
                                CAsiFloat               (const CAsiFloat &);
    virtual                     ~CAsiFloat              (void);

    virtual EAsiDataType Type           (void) const;
    virtual uint         ReturnLength   (void) const;

    virtual CAsiData *   checkAdd       (const CAsiData *) const;
    virtual CAsiData *   checkSub       (const CAsiData *) const;
    virtual CAsiData *   checkMul       (const CAsiData *) const;
    virtual CAsiData *   checkDiv       (const CAsiData *) const;
    virtual CAsiData *   checkSet       (const CAsiData *) const;

    virtual EAsiBoolean  isEqualTo      (const CAsiData &) const;
    virtual EAsiBoolean  isGreaterThan  (const CAsiData &) const;

    virtual EAsiBoolean   storeValue    (real);
    virtual EAsiBoolean   storeValue    (integer);
    virtual EAsiBoolean   storeValue    (smallint);
    virtual EAsiBoolean   storeValue    (char *, uint);
    virtual EAsiBoolean   storeValue    (const CAsiUcStr &);
    virtual EAsiBoolean   storeValue    (const CAsiData &);

    virtual EAsiBoolean   storeValue    (char *, uint, uint *);
    virtual EAsiBoolean   storeValue    (const AsiUcStr);

    virtual DBCOLUMNINFO *MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO * MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean   SQLType       (CAsiUcStr *) const;        
    virtual EAsiBoolean   SQLLiteral    (CAsiUcStr *) const;

    virtual integer       intValue      (void) const;
    virtual real          realValue     (void) const;

    virtual EAsiBoolean   getValue              (real *) const;
    virtual EAsiBoolean   getValue              (integer *) const;
    virtual EAsiBoolean   getValue              (smallint *) const;
    virtual EAsiBoolean   getValue              (char *, uint) const;
    virtual EAsiBoolean   getValue              (CAsiUcStr *) const;

    virtual EAsiBoolean   getValue              (char *, uint, uint *) const; 
    virtual EAsiBoolean   getValue              (AsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue              (CAsiData &) const;

    virtual unsigned long packSize      (void) const;
    virtual unsigned long packTo        (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom    (CAsiObjPack *);

    virtual unsigned long packValueSize (void)  const;
    virtual unsigned long packValueTo   (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (CAsiObjPack *);

    virtual CAsiObject   *duplicate     (void) const;

            CAsiFloat &operator= (const CAsiSmallInt &);
            CAsiFloat &operator= (const CAsiInt &);
            CAsiFloat &operator= (const CAsiNumeric &);
            CAsiFloat &operator= (const CAsiDecimal &);
            CAsiFloat &operator= (const CAsiFloat &);
            CAsiFloat &operator= (const CAsiReal &);
            CAsiFloat &operator= (const CAsiDouble &);
            CAsiFloat &operator= (const smallint);
            CAsiFloat &operator= (const integer);
            CAsiFloat &operator= (const real);
            CAsiFloat &operator= (const int);

            CAsiFloat &operator+= (const CAsiSmallInt &);
            CAsiFloat &operator+= (const CAsiInt &);
            CAsiFloat &operator+= (const CAsiNumeric &);
            CAsiFloat &operator+= (const CAsiDecimal &);
            CAsiFloat &operator+= (const CAsiFloat &);
            CAsiFloat &operator+= (const CAsiReal &);
            CAsiFloat &operator+= (const CAsiDouble &);
            CAsiFloat &operator+= (const smallint);
            CAsiFloat &operator+= (const integer);
            CAsiFloat &operator+= (const real);
            CAsiFloat &operator+= (const int);

            CAsiFloat &operator-= (const CAsiSmallInt &);
            CAsiFloat &operator-= (const CAsiInt &);
            CAsiFloat &operator-= (const CAsiNumeric &);
            CAsiFloat &operator-= (const CAsiDecimal &);
            CAsiFloat &operator-= (const CAsiFloat &);
            CAsiFloat &operator-= (const CAsiReal &);
            CAsiFloat &operator-= (const CAsiDouble &);
            CAsiFloat &operator-= (const smallint);
            CAsiFloat &operator-= (const integer);
            CAsiFloat &operator-= (const real);
            CAsiFloat &operator-= (const int);

            CAsiFloat &operator*= (const CAsiSmallInt &);
            CAsiFloat &operator*= (const CAsiInt &);
            CAsiFloat &operator*= (const CAsiNumeric &);
            CAsiFloat &operator*= (const CAsiDecimal &);
            CAsiFloat &operator*= (const CAsiFloat &);
            CAsiFloat &operator*= (const CAsiReal &);
            CAsiFloat &operator*= (const CAsiDouble &);
            CAsiFloat &operator*= (const smallint);
            CAsiFloat &operator*= (const integer);
            CAsiFloat &operator*= (const real);
            CAsiFloat &operator*= (const int);

            CAsiFloat &operator/= (const CAsiSmallInt &);
            CAsiFloat &operator/= (const CAsiInt &);
            CAsiFloat &operator/= (const CAsiNumeric &);
            CAsiFloat &operator/= (const CAsiDecimal &);
            CAsiFloat &operator/= (const CAsiFloat &);
            CAsiFloat &operator/= (const CAsiReal &);
            CAsiFloat &operator/= (const CAsiDouble &);
            CAsiFloat &operator/= (const smallint);
            CAsiFloat &operator/= (const integer);
            CAsiFloat &operator/= (const real);
            CAsiFloat &operator/= (const int);

            CAsiFloat operator+ (const CAsiSmallInt &) const;
            CAsiFloat operator+ (const CAsiInt &)      const;
            CAsiFloat operator+ (const CAsiNumeric &)  const;
            CAsiFloat operator+ (const CAsiDecimal &)  const;
            CAsiFloat operator+ (const CAsiFloat &)    const;
     friend CAsiFloat DLLScope operator+ (const CAsiSmallInt &, const CAsiFloat &);
     friend CAsiFloat DLLScope operator+ (const CAsiInt &, const CAsiFloat &)     ;
     friend CAsiFloat DLLScope operator+ (const CAsiNumeric &, const CAsiFloat &) ;
     friend CAsiFloat DLLScope operator+ (const CAsiDecimal &, const CAsiFloat &) ;
            CAsiFloat operator+ (const smallint) const;
            CAsiFloat operator+ (const integer)  const;
            CAsiFloat operator+ (const real)     const;
     friend CAsiFloat DLLScope operator+ (const smallint, const CAsiFloat &);
     friend CAsiFloat DLLScope operator+ (const integer, const CAsiFloat &) ;
     friend CAsiFloat DLLScope operator+ (const real, const CAsiFloat &)    ;
            CAsiFloat operator+ (const int) const;
     friend CAsiFloat DLLScope operator+ (const int, const CAsiFloat &);

            CAsiFloat operator- (const CAsiSmallInt &) const;
            CAsiFloat operator- (const CAsiInt &)      const;
            CAsiFloat operator- (const CAsiNumeric &)  const;
            CAsiFloat operator- (const CAsiDecimal &)  const;
            CAsiFloat operator- (const CAsiFloat &)    const;
     friend CAsiFloat DLLScope operator- (const CAsiSmallInt &, const CAsiFloat &);
     friend CAsiFloat DLLScope operator- (const CAsiInt &, const CAsiFloat &);
     friend CAsiFloat DLLScope operator- (const CAsiNumeric &, const CAsiFloat &);
     friend CAsiFloat DLLScope operator- (const CAsiDecimal &, const CAsiFloat &);
            CAsiFloat operator- (const smallint) const;
            CAsiFloat operator- (const integer)  const;
            CAsiFloat operator- (const real)     const;
     friend CAsiFloat DLLScope operator- (const smallint, const CAsiFloat &);
     friend CAsiFloat DLLScope operator- (const integer, const CAsiFloat &);
     friend CAsiFloat DLLScope operator- (const real, const CAsiFloat &);
            CAsiFloat operator- (const int) const;
     friend CAsiFloat DLLScope operator- (const int, const CAsiFloat &);

            CAsiFloat operator* (const CAsiSmallInt &) const;
            CAsiFloat operator* (const CAsiInt &)      const;
            CAsiFloat operator* (const CAsiNumeric &)  const;
            CAsiFloat operator* (const CAsiDecimal &)  const;
            CAsiFloat operator* (const CAsiFloat &)    const;
     friend CAsiFloat DLLScope operator* (const CAsiSmallInt &, const CAsiFloat &);
     friend CAsiFloat DLLScope operator* (const CAsiInt &, const CAsiFloat &);
     friend CAsiFloat DLLScope operator* (const CAsiNumeric &, const CAsiFloat &);
     friend CAsiFloat DLLScope operator* (const CAsiDecimal &, const CAsiFloat &);
            CAsiFloat operator* (const smallint) const;
            CAsiFloat operator* (const integer)  const;
            CAsiFloat operator* (const real)     const;
     friend CAsiFloat DLLScope operator* (const smallint, const CAsiFloat &);
     friend CAsiFloat DLLScope operator* (const integer, const CAsiFloat &);
     friend CAsiFloat DLLScope operator* (const real, const CAsiFloat &);
            CAsiFloat operator* (const int) const;
     friend CAsiFloat DLLScope operator* (const int, const CAsiFloat &);

            CAsiFloat operator/ (const CAsiSmallInt &) const;
            CAsiFloat operator/ (const CAsiInt &)      const;
            CAsiFloat operator/ (const CAsiNumeric &)  const;
            CAsiFloat operator/ (const CAsiDecimal &)  const;
            CAsiFloat operator/ (const CAsiFloat &)    const;
     friend CAsiFloat DLLScope operator/ (const CAsiSmallInt &, const CAsiFloat &);
     friend CAsiFloat DLLScope operator/ (const CAsiInt &, const CAsiFloat &);
     friend CAsiFloat DLLScope operator/ (const CAsiNumeric &, const CAsiFloat &);
     friend CAsiFloat DLLScope operator/ (const CAsiDecimal &, const CAsiFloat &);
            CAsiFloat operator/ (const smallint) const;
            CAsiFloat operator/ (const integer)  const;
            CAsiFloat operator/ (const real)     const;
     friend CAsiFloat DLLScope operator/ (const smallint, const CAsiFloat &);
     friend CAsiFloat DLLScope operator/ (const integer, const CAsiFloat &);
     friend CAsiFloat DLLScope operator/ (const real, const CAsiFloat &)   ;
            CAsiFloat operator/ (const int) const;
     friend CAsiFloat DLLScope operator/ (const int, const CAsiFloat &);

            CAsiFloat &operator++ (void);
            CAsiFloat &operator-- (void);
            CAsiFloat &operator- (void);

private:
    real fvalue;
};

class CAsiReal: public CAsiApproxNum

{
public:
                                CAsiReal                (void);
                                CAsiReal                (const CAsiReal &);
        virtual                 ~CAsiReal               (void);

    virtual EAsiDataType        Type                    (void) const;
    virtual uint                ReturnLength    (void) const;

    virtual CAsiData *          checkAdd        (const CAsiData *) const;
    virtual CAsiData *          checkSub        (const CAsiData *) const;
    virtual CAsiData *          checkMul        (const CAsiData *) const;
    virtual CAsiData *          checkDiv        (const CAsiData *) const;
    virtual CAsiData *          checkSet        (const CAsiData *) const;

    virtual EAsiBoolean         isEqualTo       (const CAsiData &) const;
    virtual EAsiBoolean         isGreaterThan   (const CAsiData &) const;

    virtual EAsiBoolean         storeValue              (real);
    virtual EAsiBoolean         storeValue              (integer);
    virtual EAsiBoolean         storeValue              (smallint);
    virtual EAsiBoolean         storeValue              (char *, uint);
    virtual EAsiBoolean         storeValue              (const CAsiUcStr &);
    virtual EAsiBoolean         storeValue              (const CAsiData &);

    virtual EAsiBoolean         storeValue              (char *, uint, uint *);
    virtual EAsiBoolean         storeValue              (const AsiUcStr);

    virtual EAsiBoolean         SQLType                 (CAsiUcStr *) const;        
    virtual EAsiBoolean         SQLLiteral              (CAsiUcStr *) const;

    virtual integer             intValue                (void) const;
    virtual real                realValue               (void) const;

    virtual EAsiBoolean         getValue                (real *) const;
    virtual EAsiBoolean         getValue                (integer *) const;
    virtual EAsiBoolean         getValue                (smallint *) const;
    virtual EAsiBoolean         getValue                (char *, uint) const;
    virtual EAsiBoolean         getValue                (CAsiUcStr *) const;

    virtual EAsiBoolean         getValue                (char *, uint, uint *) const; 
    virtual EAsiBoolean         getValue                (AsiUcStr, uint) const;       
    virtual EAsiBoolean         getValue                (CAsiData &) const;

    virtual DBCOLUMNINFO *		MapAsiToColumnInfo		(DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *		MapAsiToParamInfo		(DBPARAMINFO *) const;

    virtual unsigned long       packSize        (void) const;
    virtual unsigned long       packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean         unpackFrom      (CAsiObjPack *);

    virtual unsigned long       packValueSize   (void)  const;
    virtual unsigned long       packValueTo     (CAsiObjPack *) const;
    virtual EAsiBoolean         unpackValueFrom (CAsiObjPack *);

    virtual CAsiObject   *      duplicate               (void) const;

            CAsiReal &operator= (const CAsiSmallInt &);
            CAsiReal &operator= (const CAsiInt &);
            CAsiReal &operator= (const CAsiNumeric &);
            CAsiReal &operator= (const CAsiDecimal &);
            CAsiReal &operator= (const CAsiFloat &);
            CAsiReal &operator= (const CAsiReal &);
            CAsiReal &operator= (const CAsiDouble &);
            CAsiReal &operator= (const smallint);
            CAsiReal &operator= (const integer);
            CAsiReal &operator= (const real);
            CAsiReal &operator= (const int);

            CAsiReal &operator+= (const CAsiSmallInt &);
            CAsiReal &operator+= (const CAsiInt &);
            CAsiReal &operator+= (const CAsiNumeric &);
            CAsiReal &operator+= (const CAsiDecimal &);
            CAsiReal &operator+= (const CAsiFloat &);
            CAsiReal &operator+= (const CAsiReal &);
            CAsiReal &operator+= (const CAsiDouble &);
            CAsiReal &operator+= (const smallint);
            CAsiReal &operator+= (const integer);
            CAsiReal &operator+= (const real);
            CAsiReal &operator+= (const int);

            CAsiReal &operator-= (const CAsiSmallInt &);
            CAsiReal &operator-= (const CAsiInt &);
            CAsiReal &operator-= (const CAsiNumeric &);
            CAsiReal &operator-= (const CAsiDecimal &);
            CAsiReal &operator-= (const CAsiFloat &);
            CAsiReal &operator-= (const CAsiReal &);
            CAsiReal &operator-= (const CAsiDouble &);
            CAsiReal &operator-= (const smallint);
            CAsiReal &operator-= (const integer);
            CAsiReal &operator-= (const real);
            CAsiReal &operator-= (const int);

            CAsiReal &operator*= (const CAsiSmallInt &);
            CAsiReal &operator*= (const CAsiInt &);
            CAsiReal &operator*= (const CAsiNumeric &);
            CAsiReal &operator*= (const CAsiDecimal &);
            CAsiReal &operator*= (const CAsiFloat &);
            CAsiReal &operator*= (const CAsiReal &);
            CAsiReal &operator*= (const CAsiDouble &);
            CAsiReal &operator*= (const smallint);
            CAsiReal &operator*= (const integer);
            CAsiReal &operator*= (const real);
            CAsiReal &operator*= (const int);

            CAsiReal &operator/= (const CAsiSmallInt &);
            CAsiReal &operator/= (const CAsiInt &);
            CAsiReal &operator/= (const CAsiNumeric &);
            CAsiReal &operator/= (const CAsiDecimal &);
            CAsiReal &operator/= (const CAsiFloat &);
            CAsiReal &operator/= (const CAsiReal &);
            CAsiReal &operator/= (const CAsiDouble &);
            CAsiReal &operator/= (const smallint);
            CAsiReal &operator/= (const integer);
            CAsiReal &operator/= (const real);
            CAsiReal &operator/= (const int);

            CAsiReal operator+ (const CAsiSmallInt &) const;
            CAsiReal operator+ (const CAsiInt &)      const;
            CAsiReal operator+ (const CAsiNumeric &)  const;
            CAsiReal operator+ (const CAsiDecimal &)  const;
            CAsiReal operator+ (const CAsiFloat &)    const;
            CAsiReal operator+ (const CAsiReal &)     const;
     friend CAsiReal DLLScope operator+ (const CAsiSmallInt &, const CAsiReal &);
     friend CAsiReal DLLScope operator+ (const CAsiInt &, const CAsiReal &);
     friend CAsiReal DLLScope operator+ (const CAsiNumeric &, const CAsiReal &);
     friend CAsiReal DLLScope operator+ (const CAsiDecimal &, const CAsiReal &);
     friend CAsiReal DLLScope operator+ (const CAsiFloat &, const CAsiReal &)  ;
            CAsiReal operator+ (const smallint) const;
            CAsiReal operator+ (const integer)  const;
            CAsiReal operator+ (const real)     const;
     friend CAsiReal DLLScope operator+ (const smallint, const CAsiReal &);
     friend CAsiReal DLLScope operator+ (const integer, const CAsiReal &) ;
     friend CAsiReal DLLScope operator+ (const real, const CAsiReal &)    ;
            CAsiReal operator+ (const int) const;
     friend CAsiReal DLLScope operator+ (const int, const CAsiReal &);

            CAsiReal operator- (const CAsiSmallInt &) const;
            CAsiReal operator- (const CAsiInt &)      const;
            CAsiReal operator- (const CAsiNumeric &)  const;
            CAsiReal operator- (const CAsiDecimal &)  const;
            CAsiReal operator- (const CAsiFloat &)    const;
            CAsiReal operator- (const CAsiReal &)     const;
     friend CAsiReal DLLScope operator- (const CAsiSmallInt &, const CAsiReal &);
     friend CAsiReal DLLScope operator- (const CAsiInt &, const CAsiReal &);
     friend CAsiReal DLLScope operator- (const CAsiNumeric &, const CAsiReal &);
     friend CAsiReal DLLScope operator- (const CAsiDecimal &, const CAsiReal &);
     friend CAsiReal DLLScope operator- (const CAsiFloat &, const CAsiReal &)  ;
            CAsiReal operator- (const smallint) const;
            CAsiReal operator- (const integer)  const;
            CAsiReal operator- (const real)     const;
     friend CAsiReal DLLScope operator- (const smallint, const CAsiReal &);
     friend CAsiReal DLLScope operator- (const integer, const CAsiReal &);
     friend CAsiReal DLLScope operator- (const real, const CAsiReal &);
            CAsiReal operator- (const int) const;
     friend CAsiReal DLLScope operator- (const int, const CAsiReal &);

            CAsiReal operator* (const CAsiSmallInt &) const;
            CAsiReal operator* (const CAsiInt &)      const;
            CAsiReal operator* (const CAsiNumeric &)  const;
            CAsiReal operator* (const CAsiDecimal &)  const;
            CAsiReal operator* (const CAsiFloat &)    const;
            CAsiReal operator* (const CAsiReal &)     const;
     friend CAsiReal DLLScope operator* (const CAsiSmallInt &, const CAsiReal &);
     friend CAsiReal DLLScope operator* (const CAsiInt &, const CAsiReal &);
     friend CAsiReal DLLScope operator* (const CAsiNumeric &, const CAsiReal &);
     friend CAsiReal DLLScope operator* (const CAsiDecimal &, const CAsiReal &);
     friend CAsiReal DLLScope operator* (const CAsiFloat &, const CAsiReal &)  ;
            CAsiReal operator* (const smallint) const;
            CAsiReal operator* (const integer)  const;
            CAsiReal operator* (const real)     const;
     friend CAsiReal DLLScope operator* (const smallint, const CAsiReal &);
     friend CAsiReal DLLScope operator* (const integer, const CAsiReal &) ;
     friend CAsiReal DLLScope operator* (const real, const CAsiReal &)    ;
            CAsiReal operator* (const int) const;
     friend CAsiReal DLLScope operator* (const int, const CAsiReal &);

            CAsiReal operator/ (const CAsiSmallInt &) const;
            CAsiReal operator/ (const CAsiInt &)      const;
            CAsiReal operator/ (const CAsiNumeric &)  const;
            CAsiReal operator/ (const CAsiDecimal &)  const;
            CAsiReal operator/ (const CAsiFloat &)    const;
            CAsiReal operator/ (const CAsiReal &)     const;
     friend CAsiReal DLLScope operator/ (const CAsiSmallInt &, const CAsiReal &);
     friend CAsiReal DLLScope operator/ (const CAsiInt &, const CAsiReal &);
     friend CAsiReal DLLScope operator/ (const CAsiNumeric &, const CAsiReal &);
     friend CAsiReal DLLScope operator/ (const CAsiDecimal &, const CAsiReal &);
     friend CAsiReal DLLScope operator/ (const CAsiFloat &, const CAsiReal &)  ;
            CAsiReal operator/ (const smallint) const;
            CAsiReal operator/ (const integer)  const;
            CAsiReal operator/ (const real)     const;
     friend CAsiReal DLLScope operator/ (const smallint, const CAsiReal &);
     friend CAsiReal DLLScope operator/ (const integer, const CAsiReal &) ;
     friend CAsiReal DLLScope operator/ (const real, const CAsiReal &);
            CAsiReal operator/ (const int) const;
     friend CAsiReal DLLScope operator/ (const int, const CAsiReal &);

            CAsiReal &operator++ (void);
            CAsiReal &operator-- (void);
            CAsiReal &operator- (void);

private:
    real rvalue;
};

class CAsiDouble: public CAsiApproxNum
{
public:
                                CAsiDouble              (void);
                                CAsiDouble              (const CAsiDouble &);
    virtual                     ~CAsiDouble     (void);

    virtual EAsiDataType Type           (void) const;
    virtual uint         ReturnLength   (void) const;

    virtual CAsiData *   checkAdd       (const CAsiData *) const;
    virtual CAsiData *   checkSub       (const CAsiData *) const;
    virtual CAsiData *   checkMul       (const CAsiData *) const;
    virtual CAsiData *   checkDiv       (const CAsiData *) const;
    virtual CAsiData *   checkSet       (const CAsiData *) const;

    virtual EAsiBoolean  isEqualTo      (const CAsiData &) const;
    virtual EAsiBoolean  isGreaterThan  (const CAsiData &) const;

    virtual EAsiBoolean   storeValue    (real);
    virtual EAsiBoolean   storeValue    (integer);
    virtual EAsiBoolean   storeValue    (smallint);
    virtual EAsiBoolean   storeValue    (char *, uint);
    virtual EAsiBoolean   storeValue    (const CAsiUcStr &);
    virtual EAsiBoolean   storeValue    (const CAsiData &);

    virtual EAsiBoolean   storeValue    (char *, uint, uint *);
    virtual EAsiBoolean   storeValue    (const AsiUcStr);

    virtual integer       intValue      (void) const;
    virtual real          realValue     (void) const;

    virtual EAsiBoolean   getValue              (real *) const;
    virtual EAsiBoolean   getValue              (integer *) const;
    virtual EAsiBoolean   getValue              (smallint *) const;
    virtual EAsiBoolean   getValue              (char *, uint) const;
    virtual EAsiBoolean   getValue              (CAsiUcStr *) const;

    virtual EAsiBoolean   getValue              (char *, uint, uint *) const; 
    virtual EAsiBoolean   getValue              (AsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue              (CAsiData &) const;

    virtual DBCOLUMNINFO *  MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *   MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean   SQLType       (CAsiUcStr *) const;        
    virtual EAsiBoolean   SQLLiteral    (CAsiUcStr *) const;

    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (CAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (CAsiObjPack *);

    virtual CAsiObject   *duplicate (void) const;

            CAsiDouble &operator= (const CAsiSmallInt &);
            CAsiDouble &operator= (const CAsiInt &);
            CAsiDouble &operator= (const CAsiNumeric &);
            CAsiDouble &operator= (const CAsiDecimal &);
            CAsiDouble &operator= (const CAsiFloat &);
            CAsiDouble &operator= (const CAsiReal &);
            CAsiDouble &operator= (const CAsiDouble &);
            CAsiDouble &operator= (const smallint);
            CAsiDouble &operator= (const integer);
            CAsiDouble &operator= (const real);
            CAsiDouble &operator= (const int);

            CAsiDouble &operator+= (const CAsiSmallInt &);
            CAsiDouble &operator+= (const CAsiInt &);
            CAsiDouble &operator+= (const CAsiNumeric &);
            CAsiDouble &operator+= (const CAsiDecimal &);
            CAsiDouble &operator+= (const CAsiFloat &);
            CAsiDouble &operator+= (const CAsiReal &);
            CAsiDouble &operator+= (const CAsiDouble &);
            CAsiDouble &operator+= (const smallint);
            CAsiDouble &operator+= (const integer);
            CAsiDouble &operator+= (const real);
            CAsiDouble &operator+= (const int);

            CAsiDouble &operator-= (const CAsiSmallInt &);
            CAsiDouble &operator-= (const CAsiInt &);
            CAsiDouble &operator-= (const CAsiNumeric &);
            CAsiDouble &operator-= (const CAsiDecimal &);
            CAsiDouble &operator-= (const CAsiFloat &);
            CAsiDouble &operator-= (const CAsiReal &);
            CAsiDouble &operator-= (const CAsiDouble &);
            CAsiDouble &operator-= (const smallint);
            CAsiDouble &operator-= (const integer);
            CAsiDouble &operator-= (const real);
            CAsiDouble &operator-= (const int);

            CAsiDouble &operator*= (const CAsiSmallInt &);
            CAsiDouble &operator*= (const CAsiInt &);
            CAsiDouble &operator*= (const CAsiNumeric &);
            CAsiDouble &operator*= (const CAsiDecimal &);
            CAsiDouble &operator*= (const CAsiFloat &);
            CAsiDouble &operator*= (const CAsiReal &);
            CAsiDouble &operator*= (const CAsiDouble &);
            CAsiDouble &operator*= (const smallint);
            CAsiDouble &operator*= (const integer);
            CAsiDouble &operator*= (const real);
            CAsiDouble &operator*= (const int);

            CAsiDouble &operator/= (const CAsiSmallInt &);
            CAsiDouble &operator/= (const CAsiInt &);
            CAsiDouble &operator/= (const CAsiNumeric &);
            CAsiDouble &operator/= (const CAsiDecimal &);
            CAsiDouble &operator/= (const CAsiFloat &);
            CAsiDouble &operator/= (const CAsiReal &);
            CAsiDouble &operator/= (const CAsiDouble &);
            CAsiDouble &operator/= (const smallint);
            CAsiDouble &operator/= (const integer);
            CAsiDouble &operator/= (const real);
            CAsiDouble &operator/= (const int);

            CAsiDouble operator+ (const CAsiSmallInt &) const;
            CAsiDouble operator+ (const CAsiInt &)      const;
            CAsiDouble operator+ (const CAsiNumeric &)  const;
            CAsiDouble operator+ (const CAsiDecimal &)  const;
            CAsiDouble operator+ (const CAsiFloat &)    const;
            CAsiDouble operator+ (const CAsiReal &)     const;
            CAsiDouble operator+ (const CAsiDouble &)   const;
     friend CAsiDouble DLLScope operator+ (const CAsiSmallInt &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator+ (const CAsiInt &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator+ (const CAsiNumeric &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator+ (const CAsiDecimal &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator+ (const CAsiFloat &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator+ (const CAsiReal &, const CAsiDouble &);
            CAsiDouble operator+ (const smallint) const;
            CAsiDouble operator+ (const integer)  const;
            CAsiDouble operator+ (const real)     const;
     friend CAsiDouble DLLScope operator+ (const smallint, const CAsiDouble &);
     friend CAsiDouble DLLScope operator+ (const integer, const CAsiDouble &) ;
     friend CAsiDouble DLLScope operator+ (const real, const CAsiDouble &)    ;
            CAsiDouble operator+ (const int) const;
     friend CAsiDouble DLLScope operator+ (const int, const CAsiDouble &);

            CAsiDouble operator- (const CAsiSmallInt &) const;
            CAsiDouble operator- (const CAsiInt &)      const;
            CAsiDouble operator- (const CAsiNumeric &)  const;
            CAsiDouble operator- (const CAsiDecimal &)  const;
            CAsiDouble operator- (const CAsiFloat &)    const;
            CAsiDouble operator- (const CAsiReal &)     const;
            CAsiDouble operator- (const CAsiDouble &)   const;
     friend CAsiDouble DLLScope operator- (const CAsiSmallInt &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator- (const CAsiInt &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator- (const CAsiNumeric &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator- (const CAsiDecimal &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator- (const CAsiFloat &, const CAsiDouble &)  ;
     friend CAsiDouble DLLScope operator- (const CAsiReal &, const CAsiDouble &);
            CAsiDouble operator- (const smallint) const;
            CAsiDouble operator- (const integer)  const;
            CAsiDouble operator- (const real)     const;
     friend CAsiDouble DLLScope operator- (const smallint, const CAsiDouble &);
     friend CAsiDouble DLLScope operator- (const integer, const CAsiDouble &);
     friend CAsiDouble DLLScope operator- (const real, const CAsiDouble &);
            CAsiDouble operator- (const int) const;
     friend CAsiDouble DLLScope operator- (const int, const CAsiDouble &);

            CAsiDouble operator* (const CAsiSmallInt &) const;
            CAsiDouble operator* (const CAsiInt &)      const;
            CAsiDouble operator* (const CAsiNumeric &)  const;
            CAsiDouble operator* (const CAsiDecimal &)  const;
            CAsiDouble operator* (const CAsiFloat &)    const;
            CAsiDouble operator* (const CAsiReal &)     const;
            CAsiDouble operator* (const CAsiDouble &)   const;
     friend CAsiDouble DLLScope operator* (const CAsiSmallInt &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator* (const CAsiInt &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator* (const CAsiNumeric &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator* (const CAsiDecimal &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator* (const CAsiFloat &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator* (const CAsiReal &, const CAsiDouble &);
            CAsiDouble operator* (const smallint) const;
            CAsiDouble operator* (const integer) const;
            CAsiDouble operator* (const real) const;
     friend CAsiDouble DLLScope operator* (const smallint, const CAsiDouble &);
     friend CAsiDouble DLLScope operator* (const integer, const CAsiDouble &);
     friend CAsiDouble DLLScope operator* (const real, const CAsiDouble &);
            CAsiDouble operator* (const int) const;
     friend CAsiDouble DLLScope operator* (const int, const CAsiDouble &);

            CAsiDouble operator/ (const CAsiSmallInt &) const;
            CAsiDouble operator/ (const CAsiInt &)      const;
            CAsiDouble operator/ (const CAsiNumeric &)  const;
            CAsiDouble operator/ (const CAsiDecimal &)  const;
            CAsiDouble operator/ (const CAsiFloat &)    const;
            CAsiDouble operator/ (const CAsiReal &)     const;
            CAsiDouble operator/ (const CAsiDouble &)   const;
     friend CAsiDouble DLLScope operator/ (const CAsiSmallInt &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator/ (const CAsiInt &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator/ (const CAsiNumeric &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator/ (const CAsiDecimal &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator/ (const CAsiFloat &, const CAsiDouble &);
     friend CAsiDouble DLLScope operator/ (const CAsiReal &, const CAsiDouble &);
            CAsiDouble operator/ (const smallint) const;
            CAsiDouble operator/ (const integer)  const;
            CAsiDouble operator/ (const real)     const;
     friend CAsiDouble DLLScope operator/ (const smallint, const CAsiDouble &);
     friend CAsiDouble DLLScope operator/ (const integer, const CAsiDouble &);
     friend CAsiDouble DLLScope operator/ (const real, const CAsiDouble &);
            CAsiDouble operator/ (const int) const;
     friend CAsiDouble DLLScope operator/ (const int, const CAsiDouble &);

            CAsiDouble &operator++ (void);
            CAsiDouble &operator-- (void);
            CAsiDouble &operator- (void);

private:
    real dvalue;
};

class CAsiChar: public CAsiData
{
friend class CAsiTempTable;
public:

                                        CAsiChar                ();
                                        CAsiChar                (uint);
                                        CAsiChar                (const CAsiChar &);
        virtual                                 ~CAsiChar               ();

    void                                setVarying      (void);
    void                                setNational     (void);
    void                                setCharSet      (const CAsiUcStr &);
    void                                setDefCharSet   (void);
    void                                setCollName     (const CAsiUcStr &);
    void                                setCollIdent    (AsiUcIdCLT);
    void                                setCoerc        (EAsiCAttr);

    virtual EAsiDataType    Type                (void) const;
    virtual uint            Length              (void) const;
    virtual uint            ReturnLength        (void) const;

    uint                        ByteSize        (void) const;
    const CAsiUcStr   &         CollName        (void) const;
    const CAsiUcStr   &         CharSetName     (void) const;
    AsiUcIdCLT                  CollIdent       (void) const;
    AsiUcIdCCT                  CharSetIdent    (void) const;
    EAsiCAttr                   Coercibility    (void) const;

    virtual EAsiBoolean         is_character    (void) const;
    virtual EAsiBoolean         is_comparable   (const CAsiData *) const;
    virtual EAsiBoolean         is_storable     (const CAsiData *) const;
    virtual EAsiBoolean         is_castable     (const CAsiData *) const;
            EAsiBoolean         is_national     (void) const;

    virtual CAsiData *          checkCat        (const CAsiData *) const;
    virtual CAsiData *          checkSet        (const CAsiData *) const;

    virtual EAsiBoolean         isEqualTo       (const CAsiData &) const;
    virtual EAsiBoolean         isGreaterThan   (const CAsiData &) const;

    virtual EAsiBoolean         storeValue              (real);
    virtual EAsiBoolean         storeValue              (integer);
    virtual EAsiBoolean         storeValue              (smallint);
    virtual EAsiBoolean         storeValue              (char *, uint);
            EAsiBoolean         storeValue              (char *, uint, AsiUcIdCCT);
    virtual EAsiBoolean         storeValue              (const CAsiUcStr &);
    virtual EAsiBoolean         storeValue              (const CAsiData &);
    virtual EAsiBoolean         storeValue              (const AsiUcStr);
            EAsiBoolean         storeValue              (GUID *);
    virtual EAsiBoolean         storeValue              (char *, uint, uint *);

        const CAsiUcStr  &      charValue (void) const;   

    virtual EAsiBoolean         getValue                (real *) const;
    virtual EAsiBoolean         getValue                (integer *) const;
    virtual EAsiBoolean         getValue                (smallint *) const;
    virtual EAsiBoolean         getValue                (char *, uint) const;
    virtual EAsiBoolean         getValue                (CAsiUcStr *) const;
    virtual EAsiBoolean         getValue                (char *, uint, uint *) const; 
    virtual EAsiBoolean         getValue                (AsiUcStr, uint) const;       
    virtual EAsiBoolean         getValue                (CAsiData &) const;
            EAsiBoolean         getValue                (GUID *) const;

    virtual DBCOLUMNINFO *		MapAsiToColumnInfo		(DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *		MapAsiToParamInfo		(DBPARAMINFO *) const;

    virtual EAsiBoolean         SQLType                 (CAsiUcStr *) const;        
    virtual EAsiBoolean         SQLLiteral              (CAsiUcStr *) const;

    virtual unsigned long       packSize        (void)  const;
    virtual unsigned long       packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean         unpackFrom      (CAsiObjPack *);

    virtual unsigned long       packValueSize   (void)  const;
    virtual unsigned long       packValueTo     (CAsiObjPack *) const;
    virtual EAsiBoolean         unpackValueFrom (CAsiObjPack *);

    virtual CAsiObject   *      duplicate               (void) const;

    virtual void                Clear                   (void);

    EAsiBoolean                         Like                    (const CAsiChar &, const CAsiChar &) const;
    CAsiChar                            Substring               (uint) const;
    CAsiChar                            Substring               (uint, uint) const;
    CAsiChar                            Upper                   (void) const;
    CAsiChar                            Lower                   (void) const;
    CAsiChar                            Trim                    (EAsiTrimSpec, const CAsiChar &) const;
    CAsiNumeric                         Position                (const CAsiChar &) const;

            CAsiChar  & operator=  (const CAsiChar &);
            CAsiChar  & operator=  (const CAsiUcStr &);

            CAsiChar    operator+  (const CAsiChar &) const;
            CAsiChar    operator+  (const CAsiUcStr &) const;

            int         operator>  (const CAsiChar &) const;
            int         operator>  (const CAsiUcStr &) const;
     friend int         DLLScope operator>  (const CAsiUcStr &, const CAsiChar &);

            int         operator>=  (const CAsiChar &) const;
            int         operator>=  (const CAsiUcStr &) const;
     friend int         DLLScope operator>=  (const CAsiUcStr &, const CAsiChar &);

            int         operator==  (const CAsiChar &) const;
            int         operator==  (const CAsiUcStr &) const;
     friend int         DLLScope operator==  (const CAsiUcStr &, const CAsiChar &);

            int         operator<=  (const CAsiChar &) const;
            int         operator<=  (const CAsiUcStr &) const;
     friend int         DLLScope operator<=  (const CAsiUcStr &, const CAsiChar &);

            int         operator<  (const CAsiChar &) const;
            int         operator<  (const CAsiUcStr &) const;
     friend int         DLLScope operator<  (const CAsiUcStr &, const CAsiChar &);

            int         operator!=  (const CAsiChar &) const;
            int         operator!=  (const CAsiUcStr &) const;
     friend int         DLLScope operator!=  (const CAsiUcStr &, const CAsiChar &);

private:

    EAsiBoolean     isCompColSet(const AsiUcIdCLT, EAsiCAttr) const;
    AsiUcIdCLT      CompColSet(const AsiUcIdCLT, EAsiCAttr) const;
    EAsiBoolean     isDyadicOpColSet(const AsiUcIdCLT, EAsiCAttr) const;
    AsiUcIdCLT      DyadicOpColSet(const AsiUcIdCLT, EAsiCAttr *, EAsiCAttr) const;

private:

    uint                maxlength;              
    uint                retlength;              
    CAsiUcStr           chvalue;                

    short           mod;                
    AsiUcIdCCT      CharSetId;          
    CAsiUcStr       CharSet;            
    AsiUcIdCLT      ColId;              
    CAsiUcStr       CName;              
    EAsiCAttr       coercibility;       
};

class CAsiBinary: public CAsiData
{
friend class CAsiTempTable;
public:

            CAsiBinary  ();
            CAsiBinary  (uint);
            CAsiBinary  (const CAsiBinary &);
    virtual ~CAsiBinary ();

           void          setVarying    (void);

    virtual EAsiDataType Type         (void) const;
    virtual uint         Length       (void) const; 
    virtual uint         ReturnLength (void) const;

    virtual EAsiBoolean   is_binary     (void) const;
    virtual EAsiBoolean   is_comparable (const CAsiData *) const;
    virtual EAsiBoolean   is_storable   (const CAsiData *) const;
    virtual EAsiBoolean   is_castable   (const CAsiData *) const;

    virtual CAsiData *    checkCat      (const CAsiData *) const;
    virtual CAsiData *    checkSet      (const CAsiData *) const;

    virtual EAsiBoolean   isEqualTo     (const CAsiData &) const;
    virtual EAsiBoolean   isGreaterThan (const CAsiData &) const;

            EAsiBoolean   storeHexValue (char *, uint, uint *);
            EAsiBoolean   storeHexValue (const CAsiUcStr &);
            EAsiBoolean   storeBinValue (char *, uint, uint *);
            EAsiBoolean   storeBinValue (const CAsiUcStr &);
    virtual EAsiBoolean   storeValue    (char *, uint);
    virtual EAsiBoolean   storeValue    (char *, uint, uint *);
    virtual EAsiBoolean   storeValue    (const CAsiData &);

    virtual EAsiBoolean   storeValue (real);                 
    virtual EAsiBoolean   storeValue (integer);              
    virtual EAsiBoolean   storeValue (smallint);             
    virtual EAsiBoolean   storeValue (const CAsiUcStr &);    
    virtual EAsiBoolean   storeValue (const AsiUcStr);

            EAsiBoolean   getHexValue (char *, uint, uint *) const;
            EAsiBoolean   getHexValue (CAsiUcStr *) const;
            EAsiBoolean   getBinValue (char *, uint, uint *) const;
            EAsiBoolean   getBinValue (CAsiUcStr *) const;
    virtual EAsiBoolean   getValue    (char *, uint) const;
    virtual EAsiBoolean   getValue    (char *, uint, uint *) const;

    virtual EAsiBoolean   getValue (real *) const;               
    virtual EAsiBoolean   getValue (integer *) const;            
    virtual EAsiBoolean   getValue (smallint *) const;           
    virtual EAsiBoolean   getValue (CAsiUcStr *) const;          
    virtual EAsiBoolean   getValue (AsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue (CAsiData &) const;

    virtual DBCOLUMNINFO *MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO * MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean   SQLType    (CAsiUcStr *) const;        
    virtual EAsiBoolean   SQLLiteral (CAsiUcStr *) const;

    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (CAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (CAsiObjPack *);

    virtual CAsiObject   *duplicate(void) const;

    virtual void          Clear     (void);

    CAsiBinary Substring(uint);
    CAsiBinary Substring(uint,uint);

            CAsiBinary   &operator= (const CAsiBinary &);

            CAsiBinary  operator+  (const CAsiBinary &) const;

            int         operator>  (const CAsiBinary &) const;
            int         operator>= (const CAsiBinary &) const;
            int         operator== (const CAsiBinary &) const;
            int         operator<= (const CAsiBinary &) const;
            int         operator<  (const CAsiBinary &) const;
            int         operator!= (const CAsiBinary &) const;

private:
    uint       blength;   
    uint       alength;   
    uint       buflen;    
    uchar    * value;     
    short      mod;       
};

class CAsiIQualifier : public CAsiData
{
friend class CAsiInterval;
friend class CAsiDatetime;

public:

               CAsiIQualifier (void);
               CAsiIQualifier (EAsiIType);
               CAsiIQualifier (EAsiIType, uint);
               CAsiIQualifier (EAsiIType, uint, uint);
               CAsiIQualifier (const CAsiIQualifier &);
    virtual   ~CAsiIQualifier (void);

    virtual EAsiBoolean  setIType         (EAsiIType);    
            void         setLeadFieldPrec (uint);         
            void         setFracSecPrec   (uint);

    virtual EAsiDataType Type          (void) const;
    virtual EAsiIType    IntervalType  (void) const;
    virtual uint         LeadFieldPrec (void) const;
    virtual uint         FracSecPrec   (void) const;
    virtual uint         ReturnLength  (void) const;

    virtual EAsiBoolean  is_interval     (void) const;
    virtual EAsiBoolean  is_yminterval   (void) const;
    virtual EAsiBoolean  is_dtinterval   (void) const;
    virtual EAsiBoolean  is_storable     (const CAsiData *) const;
    virtual EAsiBoolean  is_comparable   (const CAsiData *) const;
            EAsiBoolean  is_moreaccurate (const CAsiIQualifier *) const;

    virtual EAsiBoolean  SQLType       (CAsiUcStr *) const;        

private:
    virtual EAsiBoolean  SQLLiteral    (CAsiUcStr *) const;    

public:
    
            CAsiIQualifier &operator= (const CAsiIQualifier &);

    virtual CAsiObject   *duplicate(void) const;

protected:
    EAsiIType itype;                 
    uint lfp;                        
    uint fsp;                        
};

class CAsiInterval : public CAsiIQualifier

{
friend class CAsiDate;
friend class CAsiTime;
friend class CAsiTimeStamp;

public:

            CAsiInterval                (void);
    virtual ~CAsiInterval               (void);

    virtual EAsiBoolean   SQLType       (CAsiUcStr *)      const;

    virtual CAsiData *    checkAdd      (const CAsiData *) const;
    virtual CAsiData *    checkSub      (const CAsiData *) const;
    virtual CAsiData *    checkMul      (const CAsiData *) const;
    virtual CAsiData *    checkDiv      (const CAsiData *) const;
    virtual CAsiData *    checkSet      (const CAsiData *) const;

            void          setSign  (EAsiBoolean);
            EAsiBoolean   Sign          (void)             const;

protected:
    EAsiBoolean sign;     
};

class CAsiYM : public CAsiInterval

{
friend class CAsiDate;
friend class CAsiTime;
friend class CAsiTimeStamp;
friend class CAsiTempTable;

public:

            CAsiYM (void);
            CAsiYM (EAsiIType);
            CAsiYM (EAsiIType, uint);
            CAsiYM (const CAsiYM &);
    virtual ~CAsiYM (void);

    virtual EAsiBoolean   setIType      (EAsiIType);    

    virtual EAsiBoolean   is_castable   (const CAsiData *) const;

    virtual EAsiBoolean   isEqualTo     (const CAsiData &) const;
    virtual EAsiBoolean   isGreaterThan (const CAsiData &) const;

    virtual EAsiBoolean   storeValue (integer);
    virtual EAsiBoolean   storeValue (smallint);
    virtual EAsiBoolean   storeValue (char *, uint);
    virtual EAsiBoolean   storeValue (const CAsiUcStr &);
    virtual EAsiBoolean   storeValue (const CAsiData &);

    virtual EAsiBoolean   storeValue (real);                 
    virtual EAsiBoolean   storeValue (char *, uint, uint *); 
    virtual EAsiBoolean   storeValue (const AsiUcStr);

       EAsiBoolean   set       (ASI_IYEAR *);
       EAsiBoolean   set       (ASI_IYEARTOMONTH *);
       EAsiBoolean   set       (ASI_IMONTH *);
       EAsiBoolean   set       (EAsiBoolean, uint, uint);
       EAsiBoolean   setYears  (uint);
       EAsiBoolean   setMonths (uint);

    virtual EAsiBoolean   getValue (integer *) const;
    virtual EAsiBoolean   getValue (smallint *) const;
    virtual EAsiBoolean   getValue (char *, uint) const;
    virtual EAsiBoolean   getValue (CAsiUcStr *) const;

    virtual EAsiBoolean   getValue (real *) const;               
    virtual EAsiBoolean   getValue (char *, uint, uint *) const; 
    virtual EAsiBoolean   getValue (AsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue (CAsiData &) const;

    virtual DBCOLUMNINFO *MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO * MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean   SQLLiteral (CAsiUcStr *) const;        

            EAsiBoolean   get       (ASI_IYEAR *)        const;
            EAsiBoolean   get       (ASI_IYEARTOMONTH *) const;
            EAsiBoolean   get       (ASI_IMONTH *)       const;
            EAsiBoolean   get       (EAsiBoolean *, uint *, uint *) const;
            EAsiBoolean   getYears  (uint *) const;
            EAsiBoolean   getMonths (uint *) const;

    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (CAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (CAsiObjPack *);

    virtual CAsiObject   *duplicate (void) const;

        CAsiYM       &operator=  (const CAsiYM &);
        CAsiYM       &operator=  (const CAsiSmallInt &);
        CAsiYM       &operator=  (const CAsiInt &);
        CAsiYM       &operator=  (const CAsiNumeric &);
        CAsiYM       &operator=  (const CAsiDecimal &);
        CAsiYM       &operator=  (integer);

        CAsiYM       operator+  (const CAsiYM &) const;
friend  CAsiDate DLLScope operator+  (const CAsiYM &, const CAsiDate &);
        CAsiYM       operator-  (const CAsiYM &) const;

       CAsiYM       operator*  (const CAsiSmallInt &) const;
       CAsiYM       operator*  (const CAsiInt &) const;
       CAsiYM       operator*  (const CAsiNumeric &) const;
       CAsiYM       operator*  (const CAsiDecimal &) const;
       CAsiYM       operator*  (integer) const;
friend CAsiYM DLLScope operator*  (const CAsiSmallInt &,const CAsiYM &);
friend CAsiYM DLLScope operator*  (const CAsiInt &,     const CAsiYM &);
friend CAsiYM DLLScope operator*  (const CAsiNumeric &, const CAsiYM &);
friend CAsiYM DLLScope operator*  (const CAsiDecimal &, const CAsiYM &);
friend CAsiYM DLLScope operator*  (integer,             const CAsiYM &);

        CAsiYM       operator/  (const CAsiSmallInt &) const;
        CAsiYM       operator/  (const CAsiInt &)      const;
        CAsiYM       operator/  (const CAsiNumeric &)  const;
        CAsiYM       operator/  (const CAsiDecimal &)  const;
        CAsiYM       operator/  (integer)              const;

        CAsiYM       &operator-  (void);

       int           operator>  (const CAsiYM &) const;
       int           operator>= (const CAsiYM &) const;
       int           operator== (const CAsiYM &) const;
       int           operator<= (const CAsiYM &) const;
       int           operator<  (const CAsiYM &) const;
       int           operator!= (const CAsiYM &) const;
private:
       char *        getYMString (char *, size_t) const;

protected:
    ulong ivalue;         

};

class CAsiDT : public CAsiInterval
{
    
friend class CAsiDate;
friend class CAsiTime;
friend class CAsiTimeStamp;
friend class CAsiTempTable;

private:

                void        ChkMul     (real);
                void        ChkDiv     (real);
                int         cmpDTI     (const CAsiDT&) const;
                EAsiBoolean ChkSet     (double);
                void        ChkSet2    (double);
                double      LocalToUTC (double) const;
                double      UTCToLocal (double) const;

public:

            CAsiDT (void);
            CAsiDT (EAsiIType);
            CAsiDT (EAsiIType, uint);
            CAsiDT (EAsiIType, uint, uint);
            CAsiDT (const CAsiDT &);
    virtual ~CAsiDT (void);

    virtual EAsiBoolean   setIType      (EAsiIType);    

    virtual EAsiBoolean   is_castable   (const CAsiData *) const;

    virtual EAsiBoolean   isEqualTo     (const CAsiData &) const;
    virtual EAsiBoolean   isGreaterThan (const CAsiData &) const;

    virtual EAsiBoolean   storeValue (integer);
    virtual EAsiBoolean   storeValue (smallint);
    virtual EAsiBoolean   storeValue (char *, uint);
    virtual EAsiBoolean   storeValue (const CAsiUcStr &);
    virtual EAsiBoolean   storeValue (const CAsiData &);

    virtual EAsiBoolean   storeValue (real);                 
    virtual EAsiBoolean   storeValue (char *, uint, uint *); 
    virtual EAsiBoolean   storeValue (const AsiUcStr);

            EAsiBoolean   set        (ASI_IDAY *);
            EAsiBoolean   set        (ASI_IHOUR *);
            EAsiBoolean   set        (ASI_IMINUTE *);
            EAsiBoolean   set        (ASI_ISECOND *);
            EAsiBoolean   set        (ASI_IDAYTOHOUR *);
            EAsiBoolean   set        (ASI_IDAYTOMINUTE *);
            EAsiBoolean   set        (ASI_IDAYTOSECOND *);
            EAsiBoolean   set        (ASI_IHOURTOMINUTE *);
            EAsiBoolean   set        (ASI_IHOURTOSECOND *);
            EAsiBoolean   set        (ASI_IMINUTETOSECOND *);
            EAsiBoolean   set        (EAsiBoolean, uint, uint, uint, double);
            EAsiBoolean   setDays    (uint);
            EAsiBoolean   setHours   (uint);
            EAsiBoolean   setMinutes (uint);
            EAsiBoolean   setSeconds (double);

    virtual EAsiBoolean   getValue   (integer *)      const;
    virtual EAsiBoolean   getValue   (smallint *)     const;
    virtual EAsiBoolean   getValue   (char *, uint)   const;
    virtual EAsiBoolean   getValue   (CAsiUcStr *)    const;

    virtual EAsiBoolean   getValue (real *) const;               
    virtual EAsiBoolean   getValue (char *, uint, uint *) const; 
    virtual EAsiBoolean   getValue (AsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue (CAsiData &) const;

    virtual DBCOLUMNINFO *MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO * MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean   SQLLiteral (CAsiUcStr *) const;        

            EAsiBoolean   get        (ASI_IDAY *)            const;
            EAsiBoolean   get        (ASI_IHOUR *)           const;
            EAsiBoolean   get        (ASI_IMINUTE *)         const;
            EAsiBoolean   get        (ASI_ISECOND *)         const;
            EAsiBoolean   get        (ASI_IDAYTOHOUR *)      const;
            EAsiBoolean   get        (ASI_IDAYTOMINUTE *)    const;
            EAsiBoolean   get        (ASI_IDAYTOSECOND *)    const;
            EAsiBoolean   get        (ASI_IHOURTOMINUTE *)   const;
            EAsiBoolean   get        (ASI_IHOURTOSECOND *)   const;
            EAsiBoolean   get        (ASI_IMINUTETOSECOND *) const;
            EAsiBoolean   get        (EAsiBoolean *, uint *, uint *, uint *,
                                      double *) const;
            EAsiBoolean   getDays    (uint *) const;
            EAsiBoolean   getHours   (uint *) const;
            EAsiBoolean   getMinutes (uint *) const;
            EAsiBoolean   getSeconds (double *) const;

    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (CAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (CAsiObjPack *);

    virtual CAsiObject   *duplicate (void) const;

            CAsiDT       &operator=  (const CAsiDT &);

            CAsiDT       &operator=  (const CAsiSmallInt &);
            CAsiDT       &operator=  (const CAsiInt &);
            CAsiDT       &operator=  (const CAsiNumeric &);
            CAsiDT       &operator=  (const CAsiDecimal &);
            CAsiDT       &operator=  (integer);

            CAsiDT       operator+  (const CAsiDT &) const;
            CAsiDT       operator-  (const CAsiDT &) const;
            CAsiDT       operator*  (const CAsiSmallInt &) const;
            CAsiDT       operator*  (const CAsiInt &)      const;
            CAsiDT       operator*  (const CAsiNumeric &)  const;
            CAsiDT       operator*  (const CAsiDecimal &)  const;
            CAsiDT       operator*  (integer)              const;
     friend CAsiDT DLLScope operator*  (const CAsiSmallInt &,const CAsiDT &);
     friend CAsiDT DLLScope operator*  (const CAsiInt &,     const CAsiDT &);
     friend CAsiDT DLLScope operator*  (const CAsiNumeric &, const CAsiDT &);
     friend CAsiDT DLLScope operator*  (const CAsiDecimal &, const CAsiDT &);
     friend CAsiDT DLLScope operator*  (integer,             const CAsiDT &);

            CAsiDT       operator/  (const CAsiSmallInt &) const;
            CAsiDT       operator/  (const CAsiInt &)      const;
            CAsiDT       operator/  (const CAsiNumeric &)  const;
            CAsiDT       operator/  (const CAsiDecimal &)  const;
            CAsiDT       operator/  (integer)              const;

            CAsiDT       &operator-  (void);

            int           operator>  (const CAsiDT &) const;
            int           operator>= (const CAsiDT &) const;
            int           operator== (const CAsiDT &) const;
            int           operator<= (const CAsiDT &) const;
            int           operator<  (const CAsiDT &) const;
            int           operator!= (const CAsiDT &) const;

private:
            char        * getDTString (char *, size_t) const;

protected:
    double ivalue;        

};

class CAsiDatetime : public CAsiData
{
public:

            CAsiDatetime ();
    virtual ~CAsiDatetime ();

    virtual EAsiDataType Type          (void) const;

    virtual EAsiBoolean   is_datetime   (void) const;
    virtual EAsiBoolean   is_comparable (const CAsiData *) const;

    virtual CAsiData *    checkAdd      (const CAsiData *) const;
    virtual CAsiData *    checkSub      (const CAsiData *) const;
    virtual CAsiData  *   checkSet      (const CAsiData *) const;

    virtual ushort Year                 (void) const = 0;
    virtual ushort Month                (void) const = 0;
    virtual ushort Day                  (void) const = 0;
    virtual ushort Hour                 (void) const = 0;
    virtual ushort Minute               (void) const = 0;
    virtual double Second               (void) const = 0;

protected:

};

class CAsiDate: public CAsiDatetime
{
friend class CAsiTimeStamp;
friend class CAsiTempTable;

public:

            CAsiDate ();
            CAsiDate (const CAsiDate &);
    virtual ~CAsiDate (void);

    virtual EAsiDTType   DateTimeType  (void) const;
    virtual uint         ReturnLength  (void) const;

    virtual EAsiBoolean  is_storable   (const CAsiData *) const;
    virtual EAsiBoolean  is_castable   (const CAsiData *) const;

    virtual EAsiBoolean   isEqualTo     (const CAsiData &) const;
    virtual EAsiBoolean   isGreaterThan (const CAsiData &) const;

    virtual EAsiBoolean  storeValue (char *, uint);
    virtual EAsiBoolean  storeValue (const CAsiUcStr &);
    virtual EAsiBoolean  storeValue (const CAsiData &);
    virtual EAsiBoolean  storeValue (const DBDATE *);
    virtual EAsiBoolean  storeValue (DATE);

    virtual EAsiBoolean   storeValue (integer);              
    virtual EAsiBoolean   storeValue (smallint);             
    virtual EAsiBoolean   storeValue (char *, uint, uint *); 
    virtual EAsiBoolean   storeValue (const AsiUcStr);

            EAsiBoolean  set      (ASI_DTDATE *);
            EAsiBoolean  set      (const DBDATE *);
            EAsiBoolean  set      (ushort, ushort, ushort);
            EAsiBoolean  setYear  (ushort);
            EAsiBoolean  setMonth (ushort);
            EAsiBoolean  setDay   (ushort);

            EAsiBoolean  get      (ASI_DTDATE *)  const;
            EAsiBoolean  get      (DBDATE *)      const;
    virtual EAsiBoolean  getValue (char *, uint)  const;
    virtual EAsiBoolean  getValue (CAsiUcStr *)   const;
    virtual EAsiBoolean  getValue (DBDATE *)      const;         
    virtual EAsiBoolean  getValue (DATE *)        const;

    virtual EAsiBoolean   getValue (integer *) const;            
    virtual EAsiBoolean   getValue (smallint *) const;           
    virtual EAsiBoolean   getValue (char *, uint, uint *) const; 
    virtual EAsiBoolean   getValue (AsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue (CAsiData &) const;

    virtual DBCOLUMNINFO *MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO * MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean  SQLType    (CAsiUcStr *) const;        
    virtual EAsiBoolean  SQLLiteral (CAsiUcStr *) const;        

    virtual ushort       Year      (void) const;
    virtual ushort       Month     (void) const;
    virtual ushort       Day       (void) const;
    virtual ushort       Hour      (void) const;
    virtual ushort       Minute    (void) const;
    virtual double       Second    (void) const;

    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (CAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (CAsiObjPack *);

    virtual CAsiObject   *duplicate (void) const;

            CAsiDate    &operator=     (const CAsiDate &);

            CAsiDate     operator+     (const CAsiYM &) const;
            CAsiDate     operator+     (const CAsiDT &) const;
     friend CAsiDate DLLScope operator+     (const CAsiYM &, const CAsiDate &);
     friend CAsiDate DLLScope operator+     (const CAsiDT &, const CAsiDate &);

            CAsiDate     operator-     (const CAsiYM &) const;
            CAsiDate     operator-     (const CAsiDT &) const;

            CAsiYM YMDiff (const CAsiDate &, const CAsiYM &)   const;
            CAsiDT DTDiff (const CAsiDate &, const CAsiDT &)   const;

            int          operator>     (const CAsiDate &)      const;
            int          operator>=    (const CAsiDate &)      const;
            int          operator==    (const CAsiDate &)      const;
            int          operator<=    (const CAsiDate &)      const;
            int          operator<     (const CAsiDate &)      const;
            int          operator!=    (const CAsiDate &)      const;

protected:
    ulong month;      
    ushort day;       

};

class CAsiTime : public CAsiDatetime
{
friend class CAsiTimeStamp;
friend class CAsiTempTable;

public:

            CAsiTime  (void);
            CAsiTime  (const CAsiDT&);
            CAsiTime  (uint);
            CAsiTime  (uint, const CAsiDT&);
            CAsiTime  (const CAsiTime &);
    virtual ~CAsiTime (void);

            void         setWithTimeZone (EAsiBoolean f = kAsiTrue );

    virtual EAsiDTType    DateTimeType  (void) const;
    virtual uint          TimePrec      (void) const;
    virtual uint          ReturnLength  (void) const;

    virtual EAsiBoolean   is_storable   (const CAsiData *) const;
    virtual EAsiBoolean   is_castable   (const CAsiData *) const;

    virtual EAsiBoolean   isEqualTo     (const CAsiData &) const;
    virtual EAsiBoolean   isGreaterThan (const CAsiData &) const;

    virtual EAsiBoolean  storeValue   (char *, uint);
    virtual EAsiBoolean  storeValue   (const CAsiUcStr &);
    virtual EAsiBoolean  storeValue   (const CAsiData &);
    virtual EAsiBoolean  storeValue   (const DBTIME *);

    virtual EAsiBoolean   storeValue (real);                 
    virtual EAsiBoolean   storeValue (integer);              
    virtual EAsiBoolean   storeValue (smallint);             
    virtual EAsiBoolean   storeValue (char *, uint, uint *); 
    virtual EAsiBoolean   storeValue (const AsiUcStr);

            EAsiBoolean  set           (ASI_DTTIME *);
            EAsiBoolean  set           (const DBTIME *);
            EAsiBoolean  set           (ushort, ushort, double);
            EAsiBoolean  setHour       (ushort);
            EAsiBoolean  setMinute     (ushort);
            EAsiBoolean  setSecond     (double);
            EAsiBoolean  setTimeZone   (const CAsiDT &);

            EAsiBoolean  get          (ASI_DTTIME *) const;
            EAsiBoolean  get          (DBTIME *)     const;
    virtual EAsiBoolean  getValue     (char *, uint) const;
    virtual EAsiBoolean  getValue     (CAsiUcStr *)  const;
    virtual EAsiBoolean  getValue     (DBTIME *)     const;

    virtual EAsiBoolean   getValue (real *) const;               
    virtual EAsiBoolean   getValue (integer *) const;            
    virtual EAsiBoolean   getValue (smallint *) const;           
    virtual EAsiBoolean   getValue (char *, uint, uint *) const; 
    virtual EAsiBoolean   getValue (AsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue (CAsiData &) const;

    virtual DBCOLUMNINFO *MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO * MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean  SQLType      (CAsiUcStr *) const;        
    virtual EAsiBoolean  SQLLiteral   (CAsiUcStr *) const;        

    virtual ushort       Year         (void) const {return 0;};
    virtual ushort       Month        (void) const {return 0;};
    virtual ushort       Day          (void) const {return 0;};
    virtual ushort       Hour         (void) const;
    virtual ushort       Minute       (void) const;
    virtual double       Second       (void) const;
      const CAsiDT      &TimeZone     (void) const;

    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (CAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (CAsiObjPack *);

    virtual CAsiObject  *duplicate (void) const;

            CAsiTime    &operator=     (const CAsiTime &);

            CAsiTime     operator+     (const CAsiDT &) const;
     friend CAsiTime DLLScope operator+     (const CAsiDT &, const CAsiTime &);
            CAsiTime     operator-     (const CAsiDT &) const;

            CAsiDT       DTDiff        (const CAsiTime &,const CAsiDT &) const;

            int          operator>     (const CAsiTime &) const;
            int          operator>=    (const CAsiTime &) const;
            int          operator==    (const CAsiTime &) const;
            int          operator<=    (const CAsiTime &) const;
            int          operator<     (const CAsiTime &) const;
            int          operator!=    (const CAsiTime &) const;

private:

    ushort timeprec;   
    double seconds;    
    short  mod;        
    CAsiDT timezone;
};

class CAsiTimeStamp: public CAsiDatetime
{
friend class CAsiDate;
friend class CAsiTime;
friend class CAsiTempTable;
public:

						CAsiTimeStamp ();
						CAsiTimeStamp (uint);
						CAsiTimeStamp (const CAsiDT &);
						CAsiTimeStamp (uint, const CAsiDT &);
						CAsiTimeStamp (const CAsiTimeStamp &);
    virtual				~CAsiTimeStamp (void);

    virtual void         setNull         (void);            
            void         setWithTimeZone (EAsiBoolean f = kAsiTrue );

    virtual EAsiDTType   DateTimeType  (void) const;
    virtual uint         TimeStampPrec (void) const;
    virtual uint         ReturnLength  (void) const;

    virtual EAsiBoolean  is_storable   (const CAsiData *) const;
    virtual EAsiBoolean  is_castable   (const CAsiData *) const;

    virtual EAsiBoolean  isEqualTo     (const CAsiData &) const;
    virtual EAsiBoolean  isGreaterThan (const CAsiData &) const;

    virtual EAsiBoolean  storeValue  (char *, uint);
    virtual EAsiBoolean  storeValue  (const CAsiUcStr &);
    virtual EAsiBoolean  storeValue  (const CAsiData &);
    virtual EAsiBoolean  storeValue  (const DBTIMESTAMP *);

    virtual EAsiBoolean   storeValue (real);                 
    virtual EAsiBoolean   storeValue (integer);              
    virtual EAsiBoolean   storeValue (smallint);             
    virtual EAsiBoolean   storeValue (char *, uint, uint *); 
    virtual EAsiBoolean   storeValue (const AsiUcStr);

            EAsiBoolean  set         (ASI_DTTIMESTAMP *);
            EAsiBoolean  set         (const DBTIMESTAMP *);
            EAsiBoolean  set         (const CAsiDate &, const CAsiTime &);
            EAsiBoolean  set         (ushort, ushort, ushort, ushort,
                                      ushort, double);
            EAsiBoolean  setYear     (ushort);
            EAsiBoolean  setMonth    (ushort);
            EAsiBoolean  setDay      (ushort);
            EAsiBoolean  setHour     (ushort);
            EAsiBoolean  setMinute   (ushort);
            EAsiBoolean  setSecond   (double);
            EAsiBoolean  setTimeZone (const CAsiDT &);

            EAsiBoolean  get           (ASI_DTTIMESTAMP *) const;
            EAsiBoolean  get           (DBTIMESTAMP *)     const;
    virtual EAsiBoolean  getValue      (char *, uint)      const;
    virtual EAsiBoolean  getValue      (CAsiUcStr *)       const;
    virtual EAsiBoolean  getValue      (DBTIMESTAMP *)     const;

    virtual EAsiBoolean   getValue (real *) const;               
    virtual EAsiBoolean   getValue (integer *) const;            
    virtual EAsiBoolean   getValue (smallint *) const;           
    virtual EAsiBoolean   getValue (char *, uint, uint *) const; 
    virtual EAsiBoolean   getValue (AsiUcStr, uint) const;       
    virtual EAsiBoolean   getValue (CAsiData &) const;

    virtual DBCOLUMNINFO *MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO * MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean  SQLType       (CAsiUcStr *) const;        
    virtual EAsiBoolean  SQLLiteral    (CAsiUcStr *) const;        

    virtual ushort       Year          (void) const;
    virtual ushort       Month         (void) const;
    virtual ushort       Day           (void) const;
    virtual ushort       Hour          (void) const;
    virtual ushort       Minute        (void) const;
    virtual double       Second        (void) const;
      const CAsiDT      &TimeZone      (void) const;

    virtual unsigned long packSize        (void) const;
    virtual unsigned long packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackFrom      (CAsiObjPack *);

    virtual unsigned long packValueSize   (void)  const;
    virtual unsigned long packValueTo     (CAsiObjPack *) const;
    virtual EAsiBoolean   unpackValueFrom (CAsiObjPack *);

    virtual CAsiObject  *duplicate (void) const;

            CAsiTimeStamp    &operator=     (const CAsiTimeStamp &);
            CAsiTimeStamp    &operator=     (const CAsiDate &);
            CAsiTimeStamp    &operator=     (const CAsiTime &);

            CAsiTimeStamp    operator+     (const CAsiYM &) const;
            CAsiTimeStamp    operator+     (const CAsiDT &) const;
     friend CAsiTimeStamp DLLScope operator+     (const CAsiYM &, CAsiTimeStamp &);
     friend CAsiTimeStamp DLLScope operator+     (const CAsiDT &, CAsiTimeStamp &);

            CAsiTimeStamp    operator-     (const CAsiYM &) const;
            CAsiTimeStamp    operator-     (const CAsiDT &) const;

            CAsiYM    YMDiff (const CAsiTimeStamp &, const CAsiYM &) const;
            CAsiDT    DTDiff (const CAsiTimeStamp &, const CAsiDT &) const;

            int               operator>     (const CAsiTimeStamp &) const;
            int               operator>=    (const CAsiTimeStamp &) const;
            int               operator==    (const CAsiTimeStamp &) const;
            int               operator<=    (const CAsiTimeStamp &) const;
            int               operator<     (const CAsiTimeStamp &) const;
            int               operator!=    (const CAsiTimeStamp &) const;

private:
    CAsiTime time;
    CAsiDate date;
};

class CAsiBlob : public CAsiData
{
public:

    typedef enum {
        kUnknown        = 0,
        kBlob,
        kIPersist,
        kNonIPersist,
        kADT
    } EBlobType;

    typedef enum {
        kUnk            = 0,
        kHex,
        kDec,
        kChr,
        kOct,
        kBin
    } EBlobFormat;

                            CAsiBlob        ();
                            CAsiBlob        (const CAsiBlob &);
    virtual                 ~CAsiBlob       ();

            void            SetType         (EBlobType);
            EBlobType       GetType         ()                      const;

    virtual EAsiDataType    Type            ()                      const;
    virtual uint            Length          ()                      const;
    virtual uint            ReturnLength    ()                      const;

    virtual EAsiBoolean     storeValue      (real);
    virtual EAsiBoolean     storeValue      (integer);
    virtual EAsiBoolean     storeValue      (smallint);
    virtual EAsiBoolean     storeValue      (char *, uint);
    virtual EAsiBoolean     storeValue      (const CAsiUcStr &);
    virtual EAsiBoolean     storeValue      (const CAsiData &);
    virtual EAsiBoolean     storeValue      (char *, uint, uint *); 

            EAsiBoolean     set             (IUnknown *);

    virtual EAsiBoolean     getValue        (real *)                const;
    virtual EAsiBoolean     getValue        (integer *)             const;
    virtual EAsiBoolean     getValue        (smallint *)            const;
    virtual EAsiBoolean     getValue        (char *, uint)          const;
    virtual EAsiBoolean     getValue        (CAsiUcStr *)           const;
    virtual EAsiBoolean     getValue        (CAsiData &)            const;
            EAsiBoolean     get             (IUnknown **);

    virtual DBCOLUMNINFO *  MapAsiToColumnInfo  (DBCOLUMNINFO *) const;
    virtual DBPARAMINFO *   MapAsiToParamInfo   (DBPARAMINFO *) const;

    virtual EAsiBoolean     SQLType         (CAsiUcStr *)           const;  
    virtual EAsiBoolean     SQLLiteral      (CAsiUcStr *)           const;

    virtual unsigned long   packSize        (void)                  const;
    virtual unsigned long   packTo          (CAsiObjPack *)         const;
    virtual EAsiBoolean     unpackFrom      (CAsiObjPack *);
    virtual unsigned long   packValueSize   ()                      const;
    virtual unsigned long   packValueTo     (CAsiObjPack *)         const;
    virtual EAsiBoolean     unpackValueFrom (CAsiObjPack *);

    virtual CAsiObject  *   duplicate       ()                      const;

    virtual void            Clear           ();

            HRESULT         Read            (void *, ulong, ulong *);
            HRESULT         Write           (void *, ulong, ulong *);

            void            SetFormat       (EBlobFormat);
            void            SetPrintLen     (int);
            HRESULT         ReadHead        ();

private:
    IUnknown            *   m_pIUnknown;            

    EBlobType               m_eBlobType;
    EBlobFormat             m_eBlobFormat;
    int                     m_iHeadLen;
    char                    m_cBlobHead[MaxCharLength];
};

class CAsiColumn : public CAsiObject
{
public:
                            CAsiColumn      (void);
                            CAsiColumn      (const CAsiIdent &);
                            CAsiColumn      (const CAsiIdent &, const CAsiSmallInt &);
                            CAsiColumn      (const CAsiIdent &, const CAsiInt &);
                            CAsiColumn      (const CAsiIdent &, const CAsiNumeric &);
                            CAsiColumn      (const CAsiIdent &, const CAsiDecimal &);
                            CAsiColumn      (const CAsiIdent &, const CAsiFloat &);
                            CAsiColumn      (const CAsiIdent &, const CAsiReal &);
                            CAsiColumn      (const CAsiIdent &, const CAsiDouble &);
                            CAsiColumn      (const CAsiIdent &, const CAsiChar &);
                            CAsiColumn      (const CAsiIdent &, const CAsiBinary &);
                            CAsiColumn      (const CAsiIdent &, const CAsiDate &);
                            CAsiColumn      (const CAsiIdent &, const CAsiTime &);
                            CAsiColumn      (const CAsiIdent &, const CAsiTimeStamp &);
                            CAsiColumn      (const CAsiIdent &, const CAsiYM &);
                            CAsiColumn      (const CAsiIdent &, const CAsiDT &);
                            CAsiColumn      (const CAsiIdent &, const CAsiIdent &); 
                            CAsiColumn      (const CAsiIdent &, CAsiData *);        
                            CAsiColumn      (const CAsiColumn &);                   
                            CAsiColumn      (const DBCOLUMNINFO *);

    virtual                 ~CAsiColumn     ();

    void                    setName         (const CAsiIdent &);  
    void                    setNullable     (EAsiBoolean);        
    void                    setNative       (EAsiBoolean);        
    void                    setCollation    (const CAsiUcStr &);  
    void                    setDefault      (CAsiData *);         
    void                    setDomain       (const CAsiIdent &);  
    void                    setDataDsc      (CAsiData *);         
    void                    setOffset       (uint);

    const CAsiIdent     &   Name            (void) const;         
    EAsiBoolean             Nullable        (void) const;         
    EAsiBoolean             Native          (void) const;         
    const CAsiUcStr     *   Collation       (void) const;         
    CAsiData            *   Default         (void) const;         
    const CAsiIdent     &   Domain          (void) const;         
    uint                    Offset          (void) const;         
    EAsiBoolean             IsBookmark      (void) const;
    unsigned long           ColumnFlags     (void) const;         
	const DBCOLUMNINFO	&	ColumnInfo		(void) const;

    CAsiData          *     getData         (void) const;

    CAsiColumn      &       operator=       (const CAsiColumn &);
    CAsiColumn      &       operator=       (CAsiData *);

    virtual unsigned long   packSize        (void) const;
    virtual unsigned long   packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean     unpackFrom      (CAsiObjPack *);

    virtual unsigned long   packValueSize   (void)  const;
    virtual unsigned long   packValueTo     (CAsiObjPack *) const;
    virtual EAsiBoolean     unpackValueFrom (CAsiObjPack *);

    virtual CAsiObject  *   duplicate       (void) const;

    virtual void            Clear           (void);

private:
	static void				setColumn		(CAsiColumn * t, const CAsiIdent & colname,
										     CAsiData *   datadsc);

protected:
    CAsiIdent               m_idName;           
    CAsiData            *   m_pData;            

    EAsiBoolean             m_fNullable;        
    EAsiBoolean             m_fNative;          
    CAsiData            *   m_pDefval;          
    CAsiIdent               m_idDomain;         
    uint                    m_uiOffset;         
    unsigned long           m_dwColFlags;       
	DBCOLUMNINFO			m_sColumnInfo;		
};

class CAsiRow : public CAsiObject
{
public:
							CAsiRow			(int ColNum);
							CAsiRow			(const CAsiRow &);
	virtual					~CAsiRow		();

    int						ColNum			(void) const;
    CAsiColumn			&	operator []		(int) const;
    int						findCol			(const CAsiIdent &) const;
    EAsiBoolean				isDistinct		(void) const;

    virtual CAsiObject	*	duplicate		(void) const;
    virtual void			Clear			(void);

private:
    CAsiColumn			*	m_pColumns;		
    int						m_iColnum;	  	
};

class CAsiHostBuffer: public CAsiObject

{
friend class CAsiCsr;
friend class CAsiStm;

public:

						CAsiHostBuffer ();
    virtual				~CAsiHostBuffer ();

    virtual EAsiBoolean getBind (CAsiData **) const;

protected:

    virtual EAsiBoolean setBind (CAsiData *);

protected:
    CAsiData *pData;      
};

class CAsiParameter: public CAsiHostBuffer

{

friend class CAsiParser;
friend class CAsiStm;
friend class CAsiDDAParams;
friend class CAsiHostLink;
friend class CAsiInterDBCursor;
friend class CAsiEmulCursor;
friend class CAsiEmulTable;

public:
							CAsiParameter ();
							CAsiParameter (const DBPARAMINFO *);

    virtual					~CAsiParameter ();

protected:

    virtual EAsiBoolean		setBind     (CAsiData *);

public:

	void					setName     (const CAsiIdent &);  
    void					setNullable (EAsiBoolean);        
    void					setDsc      (CAsiData*);

    const CAsiIdent  &		Name        (void) const;  
	EAsiBoolean				isNullable  (void) const;  
    CAsiData		*		Dsc         (void) const;

    virtual unsigned long	packSize        (void) const;
    virtual unsigned long	packTo          (CAsiObjPack *) const;
    virtual EAsiBoolean		unpackFrom      (CAsiObjPack *);

private:
    virtual CAsiObject *	duplicate   (void) const;
    
    virtual void			Clear        (void);

private:
    CAsiIdent				ucParName;       
    CAsiData			*	pDataDescriptor; 
    EAsiBoolean				eNul;          
};

struct ListItem {
  struct ListItem *next;
  CAsiObject *item;
};

typedef ULONG_PTR ASILISTPOS;

class CAsiList: public CAsiObject
{
public:

                            CAsiList ();
     virtual              ~ CAsiList ();

             EAsiBoolean    addFirst (CAsiObject *);    
             EAsiBoolean    addLast  (CAsiObject *);

             EAsiBoolean    del         (CAsiObject *); 
             EAsiBoolean    del         (int);          
             EAsiBoolean    detach      (CAsiObject *); 
             EAsiBoolean    detach      (int);          
             EAsiBoolean    delFirst    (void);         
             EAsiBoolean    delLast     (void);         
             EAsiBoolean    delTail     (int);          
             EAsiBoolean    detachFirst (void);         
             EAsiBoolean    detachLast  (void);         
             EAsiBoolean    detachTail  (int);

             EAsiBoolean    replace     (int,           
                                         CAsiObject *); 
             EAsiBoolean    overwrite   (int,           
                                         CAsiObject *);

             CAsiObject   * first      (void);          
             CAsiObject   * next       (void);          
             CAsiObject   * next       (ASILISTPOS);    
             CAsiObject   * last       (void);          
             int            qnty       (void) const;    
             void           detachAll  (void);          
             ASILISTPOS     position   (void) const;    
             CAsiObject   * getCurrent (void) const;    
             CAsiObject   * getAt      (ASILISTPOS) const;

             CAsiObject    *operator [] (int);

     virtual  CAsiObject   *duplicate () const;
     virtual  void          Clear     (void);          

private:
     struct ListItem *head;
     struct ListItem *tail;
     struct ListItem *current;

};

class CAsiIRow : public CAsiObject
{
public:
                            CAsiIRow    (void);
                            CAsiIRow    (const int);
                            CAsiIRow    (const CAsiIRow &);
    virtual                 ~CAsiIRow   (void);

    int                     Quantity    (void) const;       

    EAsiBoolean             setItem     (int, CAsiData *);

            CAsiData    *   operator [] (const int item) const;

    virtual CAsiObject  *   duplicate (void) const;
    virtual void            Clear (void);

private:
    CAsiData **values;      
    int        items;       
};

#pragma pack (pop)

#endif 
