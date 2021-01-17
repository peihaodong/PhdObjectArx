#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif

#ifndef ZFILESPECIFIER_H
namespace Ztil { class FileSpecifier; }
#endif
#ifndef ZIMAGEFORMATCODEC_H
namespace Ztil { class ImageFormatCodec; }
#endif

#ifndef ZSTRINGBUFFER_H
namespace Ztil { class StringBuffer; }
#endif

#ifndef ZFINDFILEINTERFACE_H
#define ZFINDFILEINTERFACE_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{

/// <summary>
/// This class acts as an interface that developers can implement and register
/// with <c>ZTILSettingsInterface</c> <see cref="ZTILSettingsInterface"/>. When
/// opening an image file for read this API if registered may be called by 
/// <c>ImageFormatCodec</c> implementations to aid in searching for files that 
/// may be needed in order to decode an image file. If it is not desirable to
/// register the callback, it can be provided to <c>FileReadDescriptor</c> on
/// construction for use in that instance <see cref="FileReadDescriptor"/>.
/// </summary>
///
/// <remarks>
/// This call back is most often used to find files that hold correlation data
/// such as IST resource files and ESRI world files that are associated with an
/// image being read in. There are some formats such as GeoSPOT which are composed
/// of multiple files such that this call back can often be called to help locate
/// some of the files that make up the totality of the image format.
/// </remarks>
///
class DllImpExp FindFileInterface 
{
public:
    /// <summary>
    /// Trivial virtual destructor.
    /// </summary>
    ///
    virtual ~FindFileInterface ();

    /// <summary>
    /// This method is called during image file load to help locate files.
    /// </summary>
    ///
    /// <param name="pRequestingCodec">
    /// A const reference to an <c>ImageFormatCodec</c> instance that is decoding 
    /// the image and making the request to find the file.
    /// </param>
    /// 
    /// <param name="fsAssociatedImage"> 
    /// A const reference to a <c>FileSpecifier</c> that holds the name of the
    /// file being decoded.
    /// </param>
    ///
    /// <param name="fsFindMe">
    /// A const reference to a <c>FileSpecifier</c> that holds the name of the
    /// file being decoded.
    /// </param>
    ///
    /// <param name="fsWhatWasFound">
    /// A reference to a <c>FileSpecifier</c> that should be set to the location
    /// and name that the is the answer to the findFile request.
    /// </param>
    /// 
    /// <returns>
    /// A true return indicates that a valid file path can be found in fsWhatWasFound
    /// that satisfies the request for a given file.
    /// </returns>
    ///
    virtual bool findFile (const ImageFormatCodec& pRequestingCodec,
        const FileSpecifier& fsAssociatedImage, const FileSpecifier& fsFindMe,
        FileSpecifier& fsWhatWasFound) = 0;

    /// <summary>
    /// This method is called during image file load to help locate files.
    /// </summary>
    ///
    /// <param name="pRequestingCodec">
    /// A const reference to an <c>ImageFormatCodec</c> instance that is decoding 
    /// the image and making the request to find the file.
    /// </param>
    /// 
    /// <param name="fsAssociatedImage"> 
    /// A const reference to a <c>FileSpecifier</c> that holds the name of the
    /// file being decoded.
    /// </param>
    ///
    /// <param name="sbExtension">
    /// A const reference to a <c>StringBuffer</c> that holds an extension
    /// that indicates the type of file to return.
    /// </param>
    ///
    /// <param name="fsWhatWasFound">
    /// A reference to a <c>FileSpecifier</c> that should be set to the location
    /// and name that the is the answer to the findFile request.
    /// </param>
    /// 
    /// <returns>
    /// A true return indicates that a valid file path can be found in fsWhatWasFound
    /// that satisfies the request for a given file.
    /// </returns>
    ///
    virtual bool findFile (const ImageFormatCodec& pRequestingCodec,
        const FileSpecifier& fsAssociatedImage, const StringBuffer& sbExtension,
        FileSpecifier& fsWhatWasFound) = 0;
};


} // end of namespace Ztil
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif


