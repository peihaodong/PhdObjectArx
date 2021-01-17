

#ifndef ZC_GELIBVERSION_H
#define ZC_GELIBVERSION_H

#include "zadesk.h"
#include "zgedll.h"
#pragma pack (push, 8)

#define IMAGE_MAJOR_VER          2
#define IMAGE_MINOR_VER          0
#define IMAGE_CORRECTIVE_VER     0
#define IMAGE_INTERNAL_VER       0

class 
GE_DLLEXPIMPORT
ZcGeLibVersion {
public:

    ZcGeLibVersion();
    ZcGeLibVersion(const ZcGeLibVersion&);
    ZcGeLibVersion(ZSoft::UInt8 major, ZSoft::UInt8 minor,
                   ZSoft::UInt8 corrective,
                   ZSoft::UInt8 internal_version);

    ZSoft::UInt8     majorVersion        () const;
    ZSoft::UInt8     minorVersion        () const;
    ZSoft::UInt8     correctiveVersion   () const;
    ZSoft::UInt8     schemaVersion       () const;

    ZcGeLibVersion&     setMajorVersion        (ZSoft::UInt8 val);
    ZcGeLibVersion&     setMinorVersion        (ZSoft::UInt8 val);
    ZcGeLibVersion&     setCorrectiveVersion   (ZSoft::UInt8 val);
    ZcGeLibVersion&     setSchemaVersion       (ZSoft::UInt8 val);

    ZSoft::Boolean operator ==      (const ZcGeLibVersion&) const; 
    ZSoft::Boolean operator !=      (const ZcGeLibVersion&) const; 
    ZSoft::Boolean operator <       (const ZcGeLibVersion&) const; 
    ZSoft::Boolean operator <=      (const ZcGeLibVersion&) const; 
    ZSoft::Boolean operator >       (const ZcGeLibVersion&) const; 
    ZSoft::Boolean operator >=      (const ZcGeLibVersion&) const;

    static const ZcGeLibVersion kRelease0;

    static const ZcGeLibVersion kReleaseSed;

    static const ZcGeLibVersion kReleaseTah;

private:
    ZSoft::UInt8   mVersion[10];
};

#pragma pack (pop)
#endif
