

#ifndef _zduiRegistryAccess_h
#define _zduiRegistryAccess_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

#ifdef ZCUTIL_INTERNAL
#include <tchar.h>
#include <afx.h>
#ifdef ZDUI_PORT
#undef ZDUI_PORT
#endif
#ifdef ZCCORE_BUILD
#define ZDUI_PORT __declspec(dllexport)
#else
#define ZDUI_PORT
#endif
#endif

#ifndef ZDUI_PORT
#define ZDUI_PORT
#endif

class ZDUI_PORT CZdUiRegistryAccess 
{
public:
    
    CZdUiRegistryAccess();
    CZdUiRegistryAccess(HKEY hKey,const CString& sSubkey); 
    virtual ~CZdUiRegistryAccess();

    operator HKEY() const;

    virtual BOOL Open(HKEY hKey,const CString &sSubkey);
    virtual void Close();
    BOOL IsOpen();

    BOOL EnumKeyNames(DWORD dwEntryIndex,CString& sKeyName);
    BOOL EnumValueNames(DWORD dwEntryIndex,CString& sValueName,LPDWORD lpdwType = NULL);

    DWORD   ValueType(const CString& sValueName,LPDWORD lpdwSize = NULL);

    CString GetString(const CString& sValueName);

    DWORD   GetDWord(const CString&  sValueName);

protected:
    
    void CommonConstruction();

    HKEY    m_hKey;
    CString m_sSubkey;
};

class ZDUI_PORT CZdUiRegistryWriteAccess: public CZdUiRegistryAccess

{
public:
    
    CZdUiRegistryWriteAccess();
    CZdUiRegistryWriteAccess(HKEY hKey,const CString& sSubkey);
    virtual ~CZdUiRegistryWriteAccess();

    virtual BOOL Open(HKEY hKey,const CString& sSubkey);

    BOOL    SetString(const CString& sValueName,const CString& sValue); 
    BOOL    SetDWord(const CString&  sValueName,DWORD dwValue);
};

class ZDUI_PORT CZdUiRegistryDeleteAccess: public CZdUiRegistryWriteAccess

{
public:
    CZdUiRegistryDeleteAccess();
    CZdUiRegistryDeleteAccess(HKEY hKey,const CString& sSubkey);
    virtual ~CZdUiRegistryDeleteAccess();

    BOOL    DeleteValue(const CString& sValueName);

    BOOL    DeleteAllValues();

    BOOL    DeleteKey(const CString&  sKeyName);

    BOOL    DeleteKeyAndSubkeys(const CString&  sKeyName);

    BOOL    DeleteAllKeys(); 

};

#pragma pack (pop)
#endif


