
#ifndef __ACCFILEWRAPPERS_H__
#define __ACCFILEWRAPPERS_H__

#include "AdCharFmt.h"

#include "../inc/zAcCFileWrappers.h"


#ifndef AcCFile
#define AcCFile		ZcCFile
#endif //#ifndef AcCFile

#ifndef AcCFile_Assert
#define AcCFile_Assert		ZcCFile_Assert
#endif //#ifndef AcCFile_Assert

#ifndef AcCStdioFile
#define AcCStdioFile		ZcCStdioFile
#endif //#ifndef AcCStdioFile

#ifndef AcOutputBufMgr
#define AcOutputBufMgr		ZcOutputBufMgr
#endif //#ifndef AcOutputBufMgr

#ifndef acByteSwap
#define acByteSwap		zcByteSwap
#endif //#ifndef acByteSwap

#ifndef acCheckCFileCharFormat
#define acCheckCFileCharFormat		zcCheckCFileCharFormat
#endif //#ifndef acCheckCFileCharFormat

#ifndef acReadAnsiCharFromCFile
#define acReadAnsiCharFromCFile		zcReadAnsiCharFromCFile
#endif //#ifndef acReadAnsiCharFromCFile

#ifndef acReadCIFFromCFile
#define acReadCIFFromCFile		zcReadCIFFromCFile
#endif //#ifndef acReadCIFFromCFile

#ifndef acReadUtf16CharFromCFile
#define acReadUtf16CharFromCFile		zcReadUtf16CharFromCFile
#endif //#ifndef acReadUtf16CharFromCFile

#ifndef acReadUtf8CharFromCFile
#define acReadUtf8CharFromCFile		zcReadUtf8CharFromCFile
#endif //#ifndef acReadUtf8CharFromCFile

#ifndef acWriteWCharToCFile
#define acWriteWCharToCFile		zcWriteWCharToCFile
#endif //#ifndef acWriteWCharToCFile

#endif //#ifndef __ACCFILEWRAPPERS_H__
