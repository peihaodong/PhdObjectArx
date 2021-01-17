
#pragma once
#include "zadesk.h"
#include "zAdAChar.h"

#pragma pack (push, 8)

#ifdef ZCUTIL_INTERNAL
#include <tchar.h>
#include <afx.h>
#ifdef ZDUI_PORT
#undef ZDUI_PORT
#endif
#define ZDUI_PORT
#endif

#include "zaduipathenums.h"

enum FS_TYPE {
    NOFS,        
    UKFS,        
    NTFS,        
    FAT,         
    VFAT,        
    HPFS,        
    CDFS,        
    HFS,         
    UFS          
};
#ifdef _ZSOFT_WINDOWS_
extern __declspec(selectany) const ZTCHAR kBackslash =  ZCRX_T( '\\' );
extern __declspec(selectany) const ZTCHAR kColon =      ZCRX_T( ':' );
extern __declspec(selectany) const ZTCHAR kDoubleQuote= ZCRX_T( '"' );
extern __declspec(selectany) const ZTCHAR kEOS =        ZCRX_T( '\0' );
extern __declspec(selectany) const ZTCHAR kPeriod =     ZCRX_T( '.' );
extern __declspec(selectany) const ZTCHAR kSlash =      ZCRX_T( '/' );
extern __declspec(selectany) const ZTCHAR kSpace =      ZCRX_T( ' ' );
extern __declspec(selectany) const ZTCHAR kAsterisk =   ZCRX_T( '*' );
extern __declspec(selectany) const ZTCHAR kQuestionmark = ZCRX_T( '?' );
extern __declspec(selectany) const ZTCHAR kZero =       ZCRX_T( '0' );
#else
extern const ZTCHAR kBackslash;
extern const ZTCHAR kColon;
extern const ZTCHAR kDoubleQuote;
extern const ZTCHAR kEOS;
extern const ZTCHAR kPeriod;
extern const ZTCHAR kSlash;
extern const ZTCHAR kSpace;
extern const ZTCHAR kAsterisk;
extern const ZTCHAR kQuestionmark;
extern const ZTCHAR kZero;
#endif

class ZDUI_PORT CZdUiVolumeDescriptor {

friend class CZdUiPathname;

public:

    CZdUiVolumeDescriptor();
    CZdUiVolumeDescriptor(const CString&);
    virtual ~CZdUiVolumeDescriptor();

    virtual inline BOOL CheckReadOnly() const {return m_d_readonly==1;};

    virtual BOOL ValidateFilename( const CString*,
                         const BOOL wildcard_ok = false ) const =0;

    virtual BOOL ValidateSegment( const CString*,
                         const BOOL wildcard_ok = false ) const =0;

    virtual BOOL IsCaseSensitive(void) const;

    virtual BOOL PreservesCase(void) const;

    virtual BOOL AllowsCaseSensitiveLookup(void) const;

    virtual void VolCase( CString& ) const;

    virtual BOOL VolMatch( const ZTCHAR * a, const CString* b ) const;
    virtual BOOL VolMatch( const CString* a, const CString* b) const;

    virtual inline const CString* GetLocalName() const { return m_vol_localname;};

    virtual LONG GetVolFreeSpace() const;

    virtual BOOL WillFit(DWORD) const;

    virtual BOOL VolumeValid() const;

#ifdef _DEBUG
    
    virtual void debug_dump(FILE*) const;
#endif

    inline BOOL IsRemote() const { return m_d_remote == 1; }

    inline BOOL IsRemovable() const { return m_d_removable == 1; }

protected:

    void GetConnectionName( void );
    int Find(const CString& str, UINT ch) const;
    int IsControl(int c) const;

    FS_TYPE m_vol_fs_type;

    typedef unsigned flagbits;

    flagbits m_d_fixed:    1;
    flagbits m_d_removable: 1;
    flagbits m_d_cdrom: 1;
    flagbits m_d_remote: 1;
    flagbits m_d_ramdisk: 1;
    flagbits m_d_readonly: 1;
    flagbits m_d_caseSensitive: 1;

    CString* m_vol_localname;

    int    m_max_component_size;

    int    m_max_path_length;

    ZTCHAR    m_vol_slash;

    BOOL     m_amodeMultiByte;    
    DWORD    m_vol_serial;
    DWORD    m_fsflags;
    CString* m_vol_label;
    CString* m_connection_name;
    const ZTCHAR * m_doubleslash;
};

class ZDUI_PORT CZdUiNTFSVolumeDescriptor : public CZdUiVolumeDescriptor {

    public:

        CZdUiNTFSVolumeDescriptor(const CString&);
        ~CZdUiNTFSVolumeDescriptor(){};

        BOOL ValidateFilename( const CString*,
                               const BOOL wildcard_ok = false ) const;
        BOOL ValidateSegment( const CString*,
                              const BOOL wildcard_ok = false ) const;

};

class ZDUI_PORT CZdUiVFATVolumeDescriptor : public CZdUiVolumeDescriptor {

    public:

        CZdUiVFATVolumeDescriptor(const CString&);
        ~CZdUiVFATVolumeDescriptor(){};

        BOOL ValidateFilename( const CString*,
                               const BOOL wildcard_ok = false ) const;
        BOOL ValidateSegment( const CString*,
                              const BOOL wildcard_ok = false ) const;

};

class ZDUI_PORT CZdUiHPFSVolumeDescriptor : public CZdUiVolumeDescriptor {

    public:

        CZdUiHPFSVolumeDescriptor(const CString&);
        ~CZdUiHPFSVolumeDescriptor(){};

        BOOL ValidateFilename( const CString*,
                               const BOOL wildcard_ok = false ) const;
        BOOL ValidateSegment( const CString*,
                              const BOOL wildcard_ok = false ) const;

};

class ZDUI_PORT CZdUiCDFSVolumeDescriptor : public CZdUiVolumeDescriptor {

    public:

        CZdUiCDFSVolumeDescriptor(const CString&);
        ~CZdUiCDFSVolumeDescriptor(){};

        BOOL ValidateFilename( const CString*,
                               const BOOL wildcard_ok = false ) const;
        BOOL ValidateSegment( const CString*,
                              const BOOL wildcard_ok = false ) const;

};

class ZDUI_PORT CZdUiFATVolumeDescriptor : public CZdUiVolumeDescriptor {

    public:

        CZdUiFATVolumeDescriptor(const CString&);
        ~CZdUiFATVolumeDescriptor(){};

        BOOL ValidateFilename( const CString*,
                               const BOOL wildcard_ok = false ) const;
        BOOL ValidateSegment( const CString*,
                              const BOOL wildcard_ok = false ) const;
    protected:
        
        int m_segc;
};

class ZDUI_PORT CZdUiUFSVolumeDescriptor : public CZdUiVolumeDescriptor {

    public:

        CZdUiUFSVolumeDescriptor(const CString&);
        ~CZdUiUFSVolumeDescriptor(){};

        BOOL ValidateFilename( const CString*,
                               const BOOL wildcard_ok = false ) const;
        BOOL ValidateSegment( const CString*,
                              const BOOL wildcard_ok = false ) const;

};

class ZDUI_PORT CZdUiNOFSVolumeDescriptor : public CZdUiVolumeDescriptor {

    public:

        CZdUiNOFSVolumeDescriptor(const CString&);
        ~CZdUiNOFSVolumeDescriptor(){};

        BOOL ValidateFilename( const CString*,
                               const BOOL wildcard_ok = false ) const;
        BOOL ValidateSegment( const CString*,
                              const BOOL wildcard_ok = false ) const;

};

#pragma pack (pop)

