#ifndef ZFORMATCODECPROPERTYSETITERATOR_H
#include <zFormatCodecPropertySetIterator.h>
#endif
#ifndef ZIMAGEFORMATCODEC_H
#include <zImageFormatCodec.h>
#endif
#ifndef ZFILESPECIFIER_H
#include <zFileSpecifier.h>
#endif
#ifndef ZFINDFILEINTERFACE_H
namespace Ztil { class FindFileInterface; }
#endif

#ifndef ZCORRELATIONPROPERTYSETITERATOR_H
#define ZCORRELATIONPROPERTYSETITERATOR_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif
/// <summary>
/// This class is the typed implementation of the <c>FormatCodecPropertySetIterator</c>
/// base class. It holds properties related to intrafile and external correlation sources.</summary>
class DllImpExp CorrelationPropertySetIterator : public Ztil::FormatCodecPropertySetIterator
{
public:
    /// <summary>Describes how the class will be used.</summary>
    enum Mode { 
        /// <summary>Opened for read.</summary>
        kForRead, 
        /// <summary>Opened for writing.</summary>
        kForWrite 
    };

    /// <summary> The constructor. </summary>
    /// <param name="mode">The description of the usage of the instance.</param>
    /// <param name="requestingCodec">A const reference to the <c>ImageFormatCodec</c> of the image
    ///file that is acquiring or writing the properties.</param>
    /// <param name="fsImage">A const reference to a <c>FileSpecifier</c> instance that 
    ///holds the name of the image file for reference to possible sources of correlation.</param>
    /// <param name="pFFI">The NULL defaulted pointer to an instance of the <c>FindFileInterface</c> 
    /// which can be used to locate files that may have correlation information.</param>
    CorrelationPropertySetIterator (Mode mode, const Ztil::ImageFormatCodec& requestingCodec, 
        const Ztil::FileSpecifier& fsImage, Ztil::FindFileInterface* pFFI = (Ztil::FindFileInterface*) NULL);
};
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
