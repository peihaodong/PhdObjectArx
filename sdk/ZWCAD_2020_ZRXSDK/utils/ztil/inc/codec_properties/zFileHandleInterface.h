#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif

#ifndef ZFILESPECIFIER_H
namespace Ztil { class FileSpecifier; }
#endif


#ifndef ZFILEHANDLEINTERFACE_H
#define ZFILEHANDLEINTERFACE_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif
namespace Ztil
{
 
/// <summary>
/// This class has no purpose at this time. It may be used in the future.
/// </summary>
///
class DllImpExp FileHandleInterface 
{
public:
    enum Basis { 
        /// <summary> Not used. </summary>
        kBegin, 
        /// <summary> Not used. </summary>
        kCurrent, 
        /// <summary> Not used. </summary>
        kEnd 
    };

public:
    /// <summary> Not used. </summary>
    virtual ~FileHandleInterface ();
    /// <summary> Not used. </summary>
    /// <returns> Not used. </returns>
    virtual const FileSpecifier& name () = 0;
    /// <summary> Not used. </summary>
    /// <returns> Not used. </returns>
    virtual Int64 size () = 0;
    /// <summary> Not used. </summary>
    /// <param name="nOffset" Not used. </param>
    /// <param name="from" Not used. </param>
    /// <returns> Not used. </returns>
    virtual Int64 seek (Int64 nOffset, enum Basis from) = 0;
    /// <summary> Not used. </summary>
    /// <returns> Not used. </returns>
    virtual Int64 position () = 0;
    /// <summary> Not used. </summary>
    /// <param name="pBuffer"> Not used. </param>
    /// <param name="bytesToRead"> Not used. </param>
    /// <returns> Not used. </returns>
    virtual Int64 read (Byte* pBuffer, Int64 bytesToRead) = 0;
    /// <summary> Not used. </summary>
    /// <param name="pData"> Not used. </param>
    /// <param name="bytesToWrite"> Not used. </param>
    /// <returns> Not used. </returns>
    virtual Int64 write (const Byte* pData, Int64 bytesToWrite) = 0;
};

} // end of namespace Ztil
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif
#endif
