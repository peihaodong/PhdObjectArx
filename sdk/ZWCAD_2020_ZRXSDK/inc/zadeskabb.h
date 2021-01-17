
#ifndef   _ZWSOFTABB_H
#define   _ZWSOFTABB_H

#include "zadesk.h"


typedef ZSoft::Int8	    	Int8;
typedef ZSoft::Int16	    Int16;
typedef ZSoft::Int32	    Int32;
typedef ZSoft::Int64	    Int64; 
typedef ZSoft::UInt8	    UInt8;
typedef ZSoft::UInt16	    UInt16;
typedef ZSoft::UInt32	    UInt32;
typedef ZSoft::UInt64	    UInt64; 
typedef ZSoft::uchar	    uchar;
typedef ZSoft::ushort	    ushort;
typedef ZSoft::uint	    uint;

typedef ZSoft::Boolean	    ZdBoolean;

#ifdef ZSoft_Boolean_is_bool
const bool kFalse = false;
const bool kTrue = true;
#else
typedef enum
{
    kTrue                   = ZSoft::kTrue,
    kFalse                  = ZSoft::kFalse,
};
#endif //ZSoft_Boolean_is_bool

#endif 
