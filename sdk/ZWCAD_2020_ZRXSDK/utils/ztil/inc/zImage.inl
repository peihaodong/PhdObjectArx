#ifndef ZIMAGEREP_H
#include "zImageRep.h"
#endif
#ifndef ZSIZE_H
#include "zSize.h"
#endif

#ifndef ZIMAGE_INL
#define ZIMAGE_INL
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

// As the Ztil::Image class uses the "Letter/Envelope" or "Bridge" design pattern
// the "envelope" class is a very thin pass through to the implementation class. 
// To facilitate performance by lowering the impact of the call indirection the
// forwarding calls are inlined by this header which is included by the parent header
// image.h.
//
namespace Ztil
{

/// <summary>
/// This method will return the Image's size.
/// </summary>
///
inline const Size& Image::size () const
{
    return mImplementation->size();
}
/// <summary>
/// This method will return the Image's tile size.
/// </summary>
///
inline Size Image::tileSize () const
{
    return mImplementation->tileSize();
}
/// <summary>
/// This method will return the Image's data model.
/// </summary>
///
inline const DataModel& Image::dataModel () const
{
    return mImplementation->dataModel();
}
/// <summary>
/// This method will return the Image's FileReadDescriptor.
/// </summary>
///
inline const FileReadDescriptor* Image::fileReadDescriptor () const
{
    return mImplementation->fileReadDescriptor();
}
/// <summary>
/// This method will return the number of tiles in the Image.
/// </summary>
///
inline int Image::numTiles (int& nRows, int& nColumns) const
{
    return mImplementation->numTiles(nRows, nColumns);
}
/// <summary>
/// This method will return the Image's clear color.
/// </summary>
///
inline const ImagePixel& Image::clearColor () const
{
    return mImplementation->clearColor();
}
/// <summary>
/// This method will set the Image's clear color. 
/// </summary>
///
/// <remarks>
/// The clear color is the color that will be return for any pixel which is not
/// set with a value by the constructed image. 
/// </remarks>
///
inline void Image::setClearColor (ImagePixel value)
{
    mImplementation->setClearColor(value);
}
/// <summary>
/// This method will set the Image's data model. Setting a data model onto an
/// existing image has restrictions. 
/// </summary>
///
/// <exception cref="ZTILException">An exception will be thrown if the data type of the
/// image is incompatible with the data model instance being set.
/// <see cref="ImageConstructionException"/>.
/// </exception>
///
inline void Image::setDataModel ( const DataModel& dataModel )
{
    mImplementation->setDataModel( dataModel );
}
/// <summary>
/// This method is similar to <c>Image::paste</c> but differs in that
/// an alpha blend value for the source is specified. 
/// </summary>
///
inline void Image::blend (RowProviderInterface* pPipe, const Offset& at,
    int nAlphaValue, bool bRespectTransparency )
{
    mImplementation->blend(pPipe, at, nAlphaValue, bRespectTransparency);
}
/// <summary>
/// The read method is the favor method for accessing pixels in an image.
/// Returning a <c>RowProviderInterface</c> instance it will supply rows of image
/// data. <see cref="RowProviderInterface"/>
/// </summary>
///
inline RowProviderInterface* Image::read (const Size& size, const Offset& offset) const
{
    return mImplementation->read(size, offset);
}
/// <summary>
/// The read method is the favor method for accessing pixels in an image.
/// Returning a <c>RowProviderInterface</c> instance it will supply rows of image
/// data. <see cref="RowProviderInterface"/>
/// </summary>
///
inline RowProviderInterface* Image::read (const Size& size, const Offset& offset, Orientation orient) const
{
    return mImplementation->read(size, offset, (int)orient);
}
/// <summary>
/// This method will disable the Image's per tile locking. This can be a benefit to performance
/// but care must be taken if multiple threads will access the image.
/// </summary>
///
inline bool Image::disablePerTileLocking (bool bDisable)
{
    return mImplementation->disablePerTileLocking(bDisable);
}
/// <summary>
/// This method will cause all the pixels of an image to be set to the clear value.
/// <seealso cref="setClearColor"/>
/// </summary>
///
inline void Image::clear ()
{
    mImplementation->clear();
}
/// <summary>
/// This method will return true the contents of the Image are valid (non-NULL).
/// </summary>
///
inline bool Image::isValid () const
{
    return (mImplementation != NULL && mImplementation->isValid());
}
/// <summary>
/// This method will return true if <c>Image::paste</c>, <c>Image::blend</c>,
/// or an <c>ImageContext</c> has been opened for write.
/// </summary>
///
inline bool Image::isModified () const
{
    return mImplementation->isModified();
}
/// <summary>
/// This method will return true if the user buffer constructor was used to construct
/// this image instance.
/// </summary>
///
inline bool Image::usesUserBuffer () const
{
    return mImplementation->usesUserBuffer();
}
/// <summary> This method adds an instance of an abstract class that will be called when
/// the image is modified. </summary>
inline void Image::addReactor( ImageReactorInterface* pReactor ) 
{
    mImplementation->addReactor(pReactor);
}

/// <summary> This method removes an instance of an abstract class that is be called when
/// the image is modified. </summary>
inline void Image::removeReactor( ImageReactorInterface* pReactor )
{
    mImplementation->removeReactor(pReactor);
}

} //end of namespace
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
