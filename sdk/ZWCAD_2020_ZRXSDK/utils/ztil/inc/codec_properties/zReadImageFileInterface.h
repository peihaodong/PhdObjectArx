#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif
#ifndef ZIMAGEFORMATCODEC_H
namespace Ztil { class ImageFormatCodec; }
#endif
#ifndef ZFILESPECIFIER_H
namespace Ztil { class FileSpecifier; }
#endif
#ifndef ZREADIMAGEFILEFRAMEINTERFACE_H
namespace Ztil { class ReadImageFileFrameInterface; }
#endif

#ifndef ZREADIMAGEFILEINTERFACE_H
#define ZREADIMAGEFILEINTERFACE_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{

///<summary>This interface class is the base class for image file handlers to implement image file reading.</summary>
class DllImpExp ReadImageFileInterface 
{
public:
    ///<summary>The destructor.</summary>
    virtual ~ReadImageFileInterface ();

    ///<summary>This queries the <c>ImageFormatCodec</c> instance that created this instance.</summary>
    ///<returns>This will return the <c>ImageFormatCodec</c> instance that created the instance.</returns>   
    virtual const ImageFormatCodec* formatCodec () const = 0;

    ///<summary>This queuries the name of the image file that is opened.</summary>
    ///<returns>This returns a const reference to a <c>FileSpecifier</c> that points to the image source.</returns>
    ///<remarks><c>FileSpecifier</c> can hold references to sources other than file paths.</remarks>
    virtual const FileSpecifier& fileName () const = 0;

    ///<summary>This queuries the number of files that are opened to read the image.</summary>
    ///<returns>The integer count of files that are opened.</returns>
    ///<remarks>Some formats consist of multiple files. This call exposes that.</remarks>
    virtual int numFilesInClosureSet () const = 0;

    ///<summary>This queuries the file name of the open file.</summary>
    ///<param name='nMemberIndex'>The integer index of the file path to return.</param>
    ///<returns>This returns the <c>FileSpecifier</c> holding the name and path of the file.</returns>
    virtual FileSpecifier getClosureSetMember (int nMemberIndex) const = 0;

    ///<summary>This queuries the number of images within the open image file source.</summary>
    ///<returns>This returns the integer count of images in the file.</returns>
    ///<remarks>ZTIL refers to images within a file as "frames".</remarks>
	virtual int numFrames () const = 0;

    ///<summary>This retrieves a <c>ReadImageFileFrameInterface</c> to read a frame image from the file.</summary>
    ///<param name='nFrameIndex'>The integer index of the image frame to retrieve where 0 is the first image frame in a file.</param>
    ///<returns>This returns a pointer to a <c>ReadImageFileFrameInterface</c> instance that represents the image frame.</returns>
    virtual ReadImageFileFrameInterface* getFrame (int nFrameIndex) = 0;
};

} //end of namespace
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif



