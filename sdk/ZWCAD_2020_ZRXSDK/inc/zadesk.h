

#ifndef   _ZSOFT_H
#define   _ZSOFT_H

#include <stdint.h>
#include "zAdAChar.h" 

#if __LP64__
#define ZSoft_Boolean_is_bool 1
#define ZSoft_Int32_is_int 1
#endif

#pragma pack (push, 8)

#if defined(_MSC_VER)
#define _ZSOFT_WINDOWS_ 1
#else
#include <stdint.h>
#if defined(__APPLE__) && defined(__MACH__)
#define _ZSOFT_MAC_
#else
#define _ZSOFT_LINUX_
#endif

#define __w64

#if __LP64__
	#define _ZC64
#endif //__LP64__

#endif //_MSC_VER

struct ZSoft
{

    typedef int8_t			Int8;
    typedef int16_t			Int16;

    typedef uint8_t			UInt8;
    typedef uint16_t		UInt16;

#ifdef ZSoft_Int32_is_int
	typedef int32_t			Int32;
	typedef uint32_t		UInt32;
#ifndef ZSoft_Boolean_is_bool
#error Boolean_is_bool must be defined if Int32_is_int
#endif
#else
	typedef unsigned long  UInt32;
	typedef long           Int32;
#endif //__LP64__

#ifndef _ZSOFT_WINDOWS_
	typedef int64_t				Int64;
	typedef uint64_t			UInt64;

#else
	typedef __int64				Int64;
	typedef unsigned __int64	UInt64;
#endif //_ZSOFT_WINDOWS_


    typedef unsigned char  uchar;
    typedef unsigned short ushort;
    typedef unsigned int   uint;


#if !defined(_WIN64) && !defined (_ZC64)
	static_assert(sizeof(long) == 4, "long size in 32-bit windows build ?");
	static_assert(sizeof(void*) == 4, "pointer size in 32-bit windows build ?");

    typedef __w64 long          LongPtr;
    typedef __w64 unsigned long ULongPtr;
    
    typedef __w64 int           IntPtr;
    typedef __w64 unsigned int  UIntPtr;
#else //_WIN64 || _ZC64
	static_assert(sizeof(void*) == 8, "pointer size in 64-bit build ?");

#ifndef _ZSOFT_WINDOWS_
	typedef int64_t             LongPtr;
	typedef uint64_t            ULongPtr;
	typedef int64_t             IntPtr;
	typedef uint64_t            UIntPtr;
#else
	typedef __int64             LongPtr;
	typedef unsigned __int64    ULongPtr;
	typedef __int64             IntPtr;
	typedef unsigned __int64    UIntPtr;
#endif // _ZSOFT_WINDOWS_

#endif //_WIN64 || _ZC64

    typedef LongPtr IntDbId;
    typedef IntPtr GsMarker;

#ifdef ZSoft_Boolean_is_bool
	typedef bool       Boolean;
	static const bool kFalse = false;
	static const bool kTrue = true;
#else
	typedef int        Boolean;
	enum           { kFalse = 0, kTrue = 1 };
#endif
};

#ifndef NULL
#define NULL 0
#endif

#pragma pack (pop)


#if defined(_MSC_VER)
#define ZSOFT_NO_VTABLE __declspec(novtable)
#define ZSOFT_STDCALL   __stdcall
#define ZSOFT_DEPRECATED __declspec(deprecated)
#define ZSOFT_DLLEXPORT	__declspec(dllexport)
#define ZSOFT_DLLIMPORT __declspec(dllimport)
#define ZSOFT_FORCE_INLINE __forceinline
#else //_MSC_VER
#define ZSOFT_NO_VTABLE 
#define ZSOFT_STDCALL   __attribute__((stdcall))
#define ZSOFT_DEPRECATED 
#define ZSOFT_DLLEXPORT	__attribute__((visibility("default")))
#define ZSOFT_DLLIMPORT __attribute__((visibility("default")))
#define ZSOFT_FORCE_INLINE inline
#endif //_MSC_VER


#ifdef _MSC_EXTENSIONS
#define ZSOFT_OVERRIDE  override
#define ZSOFT_SEALED	sealed
#else //_MSC_EXTENSIONS
#define ZSOFT_OVERRIDE
#define ZSOFT_SEALED 
#endif //_MSC_EXTENSIONS

#define MIGRATION_ERRORS

#if defined(_MSC_VER) && defined (MIGRATION_ERRORS)
	#define ZSOFT_SEALED_VIRTUAL virtual
	#if !defined(ZSOFT_SEALED)
		#define ZSOFT_SEALED sealed
	#endif //ZSOFT_SEALED
#else //MIGRATION_ERRORS
	#define ZSOFT_SEALED_VIRTUAL 
	#define ZSOFT_SEALED
#endif //MIGRATION_ERRORS


#ifdef _ZSOFT_WINDOWS_
#define VA_ARG_WCHAR(ap, t)      va_arg(ap, wchar_t)
#else
#define VA_ARG_WCHAR(ap, t)      va_arg(ap, int)
#endif

#endif
