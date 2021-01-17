#ifndef AECMODELER_INC_ENTITY_H
#define AECMODELER_INC_ENTITY_H
#include "zglobal.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwEntity
{
public:

    ZwEntity() : mFlags(0) {}
    virtual ~ZwEntity()    {}

    Flag flags     ()           const { return mFlags;               }
    void setFlags  (Flag flags)       { mFlags = flags;              }
    bool isFlagOn  (Flag flag)  const { return (mFlags & flag) != 0; }
    bool isFlagOff (Flag flag)  const { return (mFlags & flag) == 0; }
    void setFlagOn (Flag flag)        { mFlags |=  flag;             }
    void setFlagOff(Flag flag)        { mFlags &= ~flag;             }
    void flipFlag  (Flag flag)        { mFlags ^=  flag;             }

private:
    Flag mFlags;  // Set of flags (unsigned int)

}; // class Entity


AECMODELER_NAMESPACE_END
#endif
