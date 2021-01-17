

#ifndef ZASI_ASIUCODE_H
#define ZASI_ASIUCODE_H asiucodeh

#include <asisys.h>

#ifndef _MSUC_
#define _MSUC_
#endif

#define LC_ASCII      0xffffffff
    
#define ASI_ASCII_CODEPAGE  1252

#define ASI_UNSUPPORTED_CODEPAGE_ID 0xFFFFFFFE
    
#define ASI_UNSUPPORTED_LOCALE_ID   0xFFFFFFFE

typedef wchar_t             AsiUcChar;
typedef AsiUcChar*     AsiUcStr;
typedef const AsiUcChar*    AsiCUcStr;
typedef unsigned long  AsiUcIdCCT;    
typedef const char*    AsiUcNmCCT;    
typedef unsigned long  AsiUcIdCLT;    
                                      
typedef const char*    AsiUcNmCLT;    

#pragma pack (push, 8)
#if defined(__cplusplus)

class DLLScope CAsiUcStr;
class DLLScope CAsiUcChar;

class CAsiUcStr
{
public:

    CAsiUcStr();                        
    CAsiUcStr(const char*,AsiUcNmCCT);
    CAsiUcStr(const char*,AsiUcIdCCT);  
    CAsiUcStr(const char*);             
    CAsiUcStr(AsiCUcStr);
    CAsiUcStr(const CAsiUcStr&);        
    CAsiUcStr(const CAsiUcStr*);        

   ~CAsiUcStr();

    void		   Clear(void);                
    const		   AsiUcStr UcStr(void) const; 

    int            Size(void) const;      
    int            Length(void) const;    
    int            Chlen(void) const;
    int            Chlen(AsiUcNmCCT) const;
    int            Chlen(AsiUcIdCCT) const;
    int            MultibyteLen() const;
    int            MultibyteLen(AsiUcNmCCT) const;
    int            MultibyteLen(AsiUcIdCCT) const;
    int            ChlenChk(void) const;
    int            ChlenChk(AsiUcNmCCT) const;
    int            ChlenChk(AsiUcIdCCT) const;
    void           Update(int,int);
    void           Update(int,int,AsiUcNmCCT);
    void           Update(int,int,AsiUcIdCCT);
    void           Update(int,AsiUcChar);
    void           Update(int,const CAsiUcChar&);
    void           Update(int,const CAsiUcChar*);
    void           toLower(void);         
    void           toUpper(void);         

    double         Atof(void) const;
    int            Atoi(void) const;
    long           Atol(void) const;
    double         Strtod(int*) const;
    long           Strtol(int*,int) const;
    int            Sprintf(const AsiUcStr,...);

    char*          getToChar(char*,int) const;
    char*          getToChar(char*,int,AsiUcNmCCT) const;
    char*          getToChar(char*,int,AsiUcIdCCT) const;
    wchar_t*       getToChar(wchar_t*,int) const;
    wchar_t*       getToChar(wchar_t*,int,AsiUcNmCCT) const;
    wchar_t*       getToChar(wchar_t*,int,AsiUcIdCCT) const;
    char*          getToCharChk(char*,int) const;
    char*          getToCharChk(char*,int,AsiUcNmCCT) const;
    char*          getToCharChk(char*,int,AsiUcIdCCT) const;
    AsiUcStr       getToUcChar(AsiUcStr,int) const;

    void           Append(const char*);
    void           Append(const char*,AsiUcNmCCT);
    void           Append(const char*,AsiUcIdCCT);
    void           Append(const wchar_t*,AsiUcNmCCT);
    void           Append(const wchar_t*,AsiUcIdCCT);
    void           Append(const AsiUcStr);
    void           Append(const CAsiUcStr&);
    void           Append(const CAsiUcStr*);
    void           Append(const char*,int);
    void           Append(const char*,int,AsiUcNmCCT);
    void           Append(const char*,int,AsiUcIdCCT);
    void           Append(const wchar_t*,int,AsiUcNmCCT);
    void           Append(const wchar_t*,int,AsiUcIdCCT);
    void           Append(const AsiUcStr,int);
    void           Append(const CAsiUcStr&,int);
    void           Append(const CAsiUcStr*,int);
    void           Append(int);
    void           Append(int,AsiUcNmCCT);
    void           Append(int,AsiUcIdCCT);
    void           Append(AsiUcChar);
    void           Append(const CAsiUcChar&);
    void           Append(const CAsiUcChar*);

    int            FindFirst(const char*) const;
    int            FindFirst(const char*,AsiUcNmCCT) const;
    int            FindFirst(const char*,AsiUcIdCCT) const;
    int            FindFirst(const AsiUcStr) const;
    int            FindFirst(const CAsiUcStr&) const;
    int            FindFirst(const CAsiUcStr*) const;

    int            FindLast(const char*) const;
    int            FindLast(const char*,AsiUcNmCCT) const;
    int            FindLast(const char*,AsiUcIdCCT) const;
    int            FindLast(const AsiUcStr) const;
    int            FindLast(const CAsiUcStr&) const;
    int            FindLast(const CAsiUcStr*) const;

    int            FindFirst(int) const;
    int            FindFirst(int,AsiUcNmCCT) const;
    int            FindFirst(int,AsiUcIdCCT) const;
    int            FindFirst(AsiUcChar) const;
    int            FindFirst(const CAsiUcChar&) const;
    int            FindFirst(const CAsiUcChar*) const;
    int            FindLast(int) const;
    int            FindLast(int,AsiUcNmCCT) const;
    int            FindLast(int,AsiUcIdCCT) const;
    int            FindLast(AsiUcChar) const;
    int            FindLast(const CAsiUcChar&) const;
    int            FindLast(const CAsiUcChar*) const;
    int            Comp(const char*) const;
    int            Comp(const char*,AsiUcNmCCT) const;
    int            Comp(const char*,AsiUcIdCCT) const;
    int            Comp(const AsiUcStr) const;
    int            Comp(const CAsiUcStr&) const;
    int            Comp(const CAsiUcStr*) const;

    int            Comp(const char*,int) const;
    int            Comp(const char*,int,AsiUcNmCCT) const;
    int            Comp(const char*,int,AsiUcIdCCT) const;
    int            Comp(const AsiUcStr,int) const;
    int            Comp(const CAsiUcStr&,int) const;
    int            Comp(const CAsiUcStr*,int) const;

    int            Compi(const char*) const;
    int            Compi(const char*,AsiUcNmCCT) const;
    int            Compi(const char*,AsiUcIdCCT) const;
    int            Compi(const wchar_t*,AsiUcNmCCT) const;
    int            Compi(const wchar_t*,AsiUcIdCCT) const;
    int            Compi(const AsiUcStr) const;
    int            Compi(const CAsiUcStr&) const;
    int            Compi(const CAsiUcStr*) const;

    int            Compi(const char*,int) const;
    int            Compi(const char*,int,AsiUcNmCCT) const;
    int            Compi(const char*,int,AsiUcIdCCT) const;
    int            Compi(const wchar_t*,int,AsiUcNmCCT) const;
    int            Compi(const wchar_t*,int,AsiUcIdCCT) const;
    int            Compi(const AsiUcStr,int) const;
    int            Compi(const CAsiUcStr&,int) const;
    int            Compi(const CAsiUcStr*,int) const;

    void           Copy(const char*);
    void           Copy(const char*,AsiUcNmCCT);
    void           Copy(const char*,AsiUcIdCCT);
    void           Copy(const wchar_t*);
    void           Copy(const wchar_t*,AsiUcNmCCT);
    void           Copy(const wchar_t*,AsiUcIdCCT);
    void           Copy(const AsiUcStr);
    void           Copy(const CAsiUcStr&);
    void           Copy(const CAsiUcStr*);

    void           Copy(const char*,int);
    void           Copy(const char*,int,AsiUcNmCCT);
    void           Copy(const char*,int,AsiUcIdCCT);
    void           Copy(const wchar_t*,int,AsiUcNmCCT);
    void           Copy(const wchar_t*,int,AsiUcIdCCT);
    void           Copy(const AsiUcStr,int);
    void           Copy(const CAsiUcStr&,int);
    void           Copy(const CAsiUcStr*,int);

    const CAsiUcChar & operator [] (int) const;

    CAsiUcStr&  operator =  (const char*);
    CAsiUcStr&  operator =  (const AsiUcStr);
    CAsiUcStr&  operator =  (const CAsiUcStr &);
    CAsiUcStr&  operator =  (const CAsiUcStr *);

    friend int DLLScope operator == (const CAsiUcStr&, const char*);
    friend int DLLScope operator == (const char*, const CAsiUcStr&);
    friend int DLLScope operator == (const CAsiUcStr&, const CAsiUcStr&);
    friend int DLLScope operator == (const CAsiUcStr*, const CAsiUcStr&);
    friend int DLLScope operator == (const AsiUcStr, const CAsiUcStr&);
    friend int DLLScope operator == (const CAsiUcStr&, const CAsiUcStr*);
    friend int DLLScope operator == (const CAsiUcStr&, const AsiUcStr);

    friend int DLLScope operator != (const CAsiUcStr&, const char*);
    friend int DLLScope operator != (const char*, const CAsiUcStr&);
    friend int DLLScope operator != (const CAsiUcStr&, const CAsiUcStr&);
    friend int DLLScope operator != (const CAsiUcStr*, const CAsiUcStr&);
    friend int DLLScope operator != (const AsiUcStr, const CAsiUcStr&);
    friend int DLLScope operator != (const CAsiUcStr&, const CAsiUcStr*);
    friend int DLLScope operator != (const CAsiUcStr&, const AsiUcStr);

    friend int DLLScope operator >  (const CAsiUcStr&, const char*);
    friend int DLLScope operator >  (const char*, const CAsiUcStr&);
    friend int DLLScope operator >  (const CAsiUcStr&, const CAsiUcStr&);
    friend int DLLScope operator >  (const CAsiUcStr*, const CAsiUcStr&);
    friend int DLLScope operator >  (const AsiUcStr, const CAsiUcStr&);
    friend int DLLScope operator >  (const CAsiUcStr&, const CAsiUcStr*);
    friend int DLLScope operator >  (const CAsiUcStr&, const AsiUcStr);

    friend int DLLScope operator <  (const CAsiUcStr&, const char*);
    friend int DLLScope operator <  (const char*, const CAsiUcStr&);
    friend int DLLScope operator <  (const CAsiUcStr&, const CAsiUcStr&);
    friend int DLLScope operator <  (const CAsiUcStr*, const CAsiUcStr&);
    friend int DLLScope operator <  (const AsiUcStr, const CAsiUcStr&);
    friend int DLLScope operator <  (const CAsiUcStr&, const CAsiUcStr*);
    friend int DLLScope operator <  (const CAsiUcStr&, const AsiUcStr);

    friend int DLLScope operator >= (const CAsiUcStr&, const char*);
    friend int DLLScope operator >= (const char*, const CAsiUcStr&);
    friend int DLLScope operator >= (const CAsiUcStr&, const CAsiUcStr&);
    friend int DLLScope operator >= (const CAsiUcStr*, const CAsiUcStr&);
    friend int DLLScope operator >= (const AsiUcStr, const CAsiUcStr&);
    friend int DLLScope operator >= (const CAsiUcStr&, const CAsiUcStr*);
    friend int DLLScope operator >= (const CAsiUcStr&, const AsiUcStr);

    friend int DLLScope operator <= (const CAsiUcStr&, const char*);
    friend int DLLScope operator <= (const char*, const CAsiUcStr&);
    friend int DLLScope operator <= (const CAsiUcStr&, const CAsiUcStr&);
    friend int DLLScope operator <= (const CAsiUcStr*, const CAsiUcStr&);
    friend int DLLScope operator <= (const AsiUcStr, const CAsiUcStr&);
    friend int DLLScope operator <= (const CAsiUcStr&, const CAsiUcStr*);
    friend int DLLScope operator <= (const CAsiUcStr&, const AsiUcStr);

#ifdef ibmrs
    void* operator new(unsigned long);
#else
    void* operator new(size_t);
#endif
    void operator delete(void*);
#if defined(__WATCOMC__)
    void* operator new[](unsigned int);
    void operator delete[](void*);
#endif 

private:
    void *pUcStrData;
};

class CAsiUcChar
{
public:

    AsiUcChar Symbol;

    int       isUpper(void) const;
    int       isLower(void) const;
    int       isAlpha(void) const;
    int       isDigit(void) const;
    int       isXdigit(void) const;
    int       isSpace(void) const;
    int       isPunct(void) const;
    int       isAlnum(void) const;
    int       isGraph(void) const;
    int       isPrint(void) const;
    int       isCntrl(void) const;

    void      setUpper(void);
    void      setLower(void);
    void      setChar(int,AsiUcIdCCT);
    void      setChar(int,AsiUcNmCCT);
    void      setChar(AsiUcChar);

    int       getChar(void) const;
    int       getChar(AsiUcIdCCT) const;
    int       getChar(AsiUcNmCCT) const;
    AsiUcChar getUcChar(void) const;

    CAsiUcChar Upper(void) const;
    CAsiUcChar Lower(void) const;

    int  Comp(int) const;
    int  Comp(int,AsiUcIdCCT) const;
    int  Comp(int,AsiUcNmCCT) const;
    int  Comp(AsiUcChar) const;
    int  Comp(CAsiUcChar*) const;
    int  Comp(const CAsiUcChar&) const;
    int  Compi(int) const;
    int  Compi(int,AsiUcIdCCT) const;
    int  Compi(int,AsiUcNmCCT) const;
    int  Compi(AsiUcChar) const;
    int  Compi(CAsiUcChar*) const;
    int  Compi(const CAsiUcChar&) const;

    CAsiUcChar&  operator =  (const char);
    CAsiUcChar&  operator =  (const AsiUcChar);
    CAsiUcChar&  operator =  (const CAsiUcChar&);

    friend DLLScope int operator == (const CAsiUcChar&, const char);
    friend DLLScope int operator == (const char, const CAsiUcChar&);
    friend DLLScope int operator == (const CAsiUcChar&, const AsiUcChar);
    friend DLLScope int operator == (const AsiUcChar, const CAsiUcChar&);
    friend DLLScope int operator == (const CAsiUcChar&, const CAsiUcChar&);
		                 
    friend DLLScope int operator != (const CAsiUcChar&, const char);
    friend DLLScope int operator != (const char, const CAsiUcChar&);
    friend DLLScope int operator != (const CAsiUcChar&, const AsiUcChar);
    friend DLLScope int operator != (const AsiUcChar, const CAsiUcChar&);
    friend DLLScope int operator != (const CAsiUcChar&, const CAsiUcChar&);
		                 
    friend DLLScope int operator >  (const CAsiUcChar&, const char);
    friend DLLScope int operator >  (const char, const CAsiUcChar&);
    friend DLLScope int operator >  (const CAsiUcChar&, const AsiUcChar);
    friend DLLScope int operator >  (const AsiUcChar, const CAsiUcChar&);
    friend DLLScope int operator >  (const CAsiUcChar&, const CAsiUcChar&);
		                 
    friend DLLScope int operator <  (const CAsiUcChar&, const char);
    friend DLLScope int operator <  (const char, const CAsiUcChar&);
    friend DLLScope int operator <  (const CAsiUcChar&, const AsiUcChar);
    friend DLLScope int operator <  (const AsiUcChar, const CAsiUcChar&);
    friend DLLScope int operator <  (const CAsiUcChar&, const CAsiUcChar&);
		                 
    friend DLLScope int operator >= (const CAsiUcChar&, const char);
    friend DLLScope int operator >= (const char, const CAsiUcChar&);
    friend DLLScope int operator >= (const CAsiUcChar&, const AsiUcChar);
    friend DLLScope int operator >= (const AsiUcChar, const CAsiUcChar&);
    friend DLLScope int operator >= (const CAsiUcChar&, const CAsiUcChar&);
		                 
    friend DLLScope int operator <= (const CAsiUcChar&, const char);
    friend DLLScope int operator <= (const char, const CAsiUcChar&);
    friend DLLScope int operator <= (const CAsiUcChar&, const AsiUcChar);
    friend DLLScope int operator <= (const AsiUcChar, const CAsiUcChar&);
    friend DLLScope int operator <= (const CAsiUcChar&, const CAsiUcChar&);

#ifdef ibmrs
    void* operator new(unsigned long);
#else
    void* operator new(size_t);
#endif
    void operator delete(void*);
#if defined(__WATCOMC__)
    void* operator new[](unsigned int);
    void operator delete[](void*);
#endif 
};

#endif 

DLLScope int		 AsiUcIsAlnum      (AsiUcChar);
DLLScope int 	     AsiUcIsAlpha      (AsiUcChar);
DLLScope int 	     AsiUcIsCntrl      (AsiUcChar);
DLLScope int 	     AsiUcIsDigit      (AsiUcChar);
DLLScope int 	     AsiUcIsGraph      (AsiUcChar);
DLLScope int 	     AsiUcIsLower      (AsiUcChar);
DLLScope int 	     AsiUcIsPrint      (AsiUcChar);
DLLScope int 	     AsiUcIsPunct      (AsiUcChar);
DLLScope int 	     AsiUcIsSpace      (AsiUcChar);
DLLScope int 	     AsiUcIsUpper      (AsiUcChar);
DLLScope int 	     AsiUcIsXdigit     (AsiUcChar);

DLLScope AsiUcChar  AsiUcToLower      (AsiUcChar);
DLLScope AsiUcChar  AsiUcToUpper      (AsiUcChar);

DLLScope int        AsiUcSprintf      (AsiUcStr,const AsiUcStr, ...);

DLLScope double     AsiUcAtof         (const AsiUcStr);
DLLScope int        AsiUcAtoi         (const AsiUcStr);
DLLScope long       AsiUcAtol         (const AsiUcStr);
DLLScope double     AsiUcStrtod       (const AsiUcStr,AsiUcStr*);
DLLScope long       AsiUcStrtol       (const AsiUcStr,AsiUcStr*,int);

DLLScope AsiUcStr   AsiUcStrcpy       (AsiUcStr,const AsiUcStr);
DLLScope AsiUcStr   AsiUcStrncpy      (AsiUcStr,const AsiUcStr,int);
DLLScope AsiUcStr   AsiUcStrcat       (AsiUcStr,const AsiUcStr);
DLLScope AsiUcStr   AsiUcStrncat      (AsiUcStr,const AsiUcStr,int);

DLLScope int        AsiUcCmpUCandUC   (const AsiUcStr,const AsiUcStr);
DLLScope int        AsiUcStrcmp       (const AsiUcStr,const AsiUcStr);
DLLScope int        AsiUcStrncmp      (const AsiUcStr,const AsiUcStr,int);
DLLScope int        AsiUcStricmp      (const AsiUcStr,const AsiUcStr);
DLLScope int        AsiUcStrnicmp     (const AsiUcStr,const AsiUcStr,int);

DLLScope AsiUcStr   AsiUcStrstr       (const AsiUcStr,const AsiUcStr);
DLLScope AsiUcStr   AsiUcStrrstr      (const AsiUcStr,const AsiUcStr);
DLLScope AsiUcStr   AsiUcStrchr       (const AsiUcStr,AsiUcChar);
DLLScope AsiUcStr   AsiUcStrrchr      (const AsiUcStr,AsiUcChar);

DLLScope AsiUcStr   AsiUcStrLower     (AsiUcStr);
DLLScope AsiUcStr   AsiUcStrUpper     (AsiUcStr);

DLLScope char	    *AsiUcStrUc2Ch     (char*,int,const AsiUcStr,int,AsiUcNmCCT);
DLLScope AsiUcStr   AsiUcStrCh2Uc     (AsiUcStr,int,const char*,int,AsiUcNmCCT);
DLLScope int        AsiUcUc2ChCCT     (char*,int,const AsiUcStr,int,AsiUcIdCCT);
DLLScope int        AsiUcCh2UcCCT     (AsiUcStr,int,const char*,int,AsiUcIdCCT);

DLLScope int        AsiUc2Ch          (AsiUcChar,AsiUcNmCCT);
DLLScope AsiUcChar  AsiCh2Uc          (int,AsiUcNmCCT);

DLLScope int        AsiUcStrlen       (const AsiUcStr);
DLLScope int        AsiUcStrsize      (const AsiUcStr);
DLLScope int        AsiUcStrchln      (const AsiUcStr,AsiUcNmCCT);
DLLScope int        AsiUcStrchlnIdCCT (const AsiUcStr,AsiUcIdCCT);
DLLScope int        AsiChStrUclnIdCCT (const char*,AsiUcIdCCT);
              
DLLScope AsiUcIdCCT AsiUcGetIdCCT     (AsiUcNmCCT);
              
DLLScope AsiUcNmCCT AsiUcGetNmCCT     (AsiUcIdCCT);
DLLScope AsiUcNmCCT AsiUcDefaultCCT   (void);
              
DLLScope AsiUcIdCLT AsiUcGetIdCLT     (AsiUcNmCLT);
DLLScope AsiUcNmCLT AsiUcGetNmCLT     (AsiUcIdCLT);
DLLScope AsiUcNmCLT AsiUcDefaultCLT   (void);
              
DLLScope int        AsiUcCnChcmp      (AsiUcNmCLT,AsiUcChar,AsiUcChar);
DLLScope int        AsiUcCnStrcmp     (AsiUcNmCLT,const AsiUcStr,const AsiUcStr);
DLLScope int        AsiUcCnStrncmp    (AsiUcNmCLT,const AsiUcStr,const AsiUcStr,int);
              
DLLScope int        AsiUcCiStrweight  (AsiUcIdCLT,const AsiUcStr,unsigned char *,int);
DLLScope int        AsiUcCiChcmp      (AsiUcIdCLT,AsiUcChar,AsiUcChar);
DLLScope int        AsiUcCiStrcmp     (AsiUcIdCLT,const AsiUcStr,const AsiUcStr);
              
DLLScope int        AsiUcCiStrIcmp    (AsiUcIdCLT,const AsiUcStr,const AsiUcStr);
              
DLLScope int        AsiUcCiStrncmp    (AsiUcIdCLT,const AsiUcStr,const AsiUcStr,int);
DLLScope int        AsiUcCiUcChStrcmp (AsiUcIdCLT,AsiUcIdCCT,const AsiUcStr,const char*);
DLLScope int        AsiUcCiStrStrcmpA (AsiUcIdCLT,AsiUcIdCCT,const char*,const char*);
DLLScope int        AsiUcCiStrStrIcmpA(AsiUcIdCLT,AsiUcIdCCT,const char*,const char*);
DLLScope int        AsiUcCiStrStrcmpW (AsiUcIdCLT,AsiUcIdCCT,const wchar_t*,const wchar_t*);
DLLScope int        AsiUcCiStrStrIcmpW(AsiUcIdCLT,AsiUcIdCCT,const wchar_t*,const wchar_t*);

#ifndef UNICODE
#define AsiUcCiStrStrcmp    AsiUcCiStrStrcmpA
#else
#define AsiUcCiStrStrcmp    AsiUcCiStrStrcmpW
#endif

#pragma pack (pop)

#endif 

