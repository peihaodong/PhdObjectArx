#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif
#ifndef ZFILEREADDESCRIPTOR_H
#include "zFileReadDescriptor.h"
#endif
#ifndef ZDATASTREAMINTERFACE_H
#include "zDataStreamInterface.h"
#endif
#ifndef ZTRANSFORMS_H
#include "zTransforms.h"
#endif

#ifndef ZSIZE_H
namespace Ztil { class Size; }
#endif
#ifndef ZFILESPECIFIER_H
namespace Ztil { class FileSpecifier; }
#endif
#ifndef ZDATAMODEL_H
namespace Ztil { class DataModel; }
#endif
#ifndef ZROWPROVIDERINTERFACE_H
namespace Ztil { class RowProviderInterface; }
#endif
#ifndef ZIMAGEFORMATCODEC_H
namespace Ztil { class ImageFormatCodec; }
#endif
#ifndef ZFORMATCODECPROPERTYSETITERATOR_H
namespace Ztil { class FormatCodecPropertySetIterator; }
#endif
#ifndef ZFINDFILEINTERFACE_H
namespace Ztil { class FindFileInterface; }
#endif

#ifndef ZFILEREADDESCRIPTORREP_H
#define ZFILEREADDESCRIPTORREP_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{

/// <summary>
/// This class serves as an abstract base class for the <c>FileReadDescriptor</c>.
/// </summary>
class DllImpExp FileReadDescriptorRep 
{
public:
    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <param name= 'fs'>   
	/// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
	/// </param>
	///
	/// <param name= 'pFF'>
	/// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
	/// </param>
	/// 
    virtual void construct (const FileSpecifier& fs, FindFileInterface* pFF ) = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	/// <param name= 'fs'> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </param>
	/// <param name= 'useThisCodec'> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </param>
	/// <param name= 'pFF'> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/> 
    /// </param>
	/// 
    virtual void construct (const FileSpecifier& fs, const ImageFormatCodec* useThisCodec, FindFileInterface* pFF ) = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <param name= 'pdsStream'> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </param>
	/// <param name= 'useThisCodec'> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </param>
	/// 
    virtual void construct (DataStreamInterface* pdsStream, const ImageFormatCodec* useThisCodec) = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <param name= 'pCloneRep'> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </param>
	/// 
    virtual void construct (FileReadDescriptorRep* pCloneRep) = 0;
    
    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
    virtual void open () const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
    virtual void close () const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <param name= 'fs'> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </param>
	///
    virtual void getFileSpecifier (FileSpecifier& fs) const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <param name= 'size'> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </param>
	///
    virtual void getDataSize (Size& size) const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <returns> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </returns>
	///
    virtual Ztil::Orientation dataOrientation() const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	/// 
	/// <param name= 'size'> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </param>
	/// 
    virtual void getOrientedSize (Size& size) const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <returns> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </returns>
	///
    virtual const DataModel& dataModel () const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <returns> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </returns>
	///
    virtual const ImageFormatCodec * formatCodec () const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <returns> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </returns>
	///
    virtual int numFrames () const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	/// 
	/// <returns> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </returns>
	///
    virtual int selectedFrame () const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <param name= 'frame'> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </param> 
	///
	/// <returns> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </returns>
	///
    virtual bool setFrame (int frame) = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <returns> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </returns> 
	///
    virtual FileReadDescriptor::MethodType loadMethod () const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <returns> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/> 
    /// </returns> 
	///
    virtual FormatCodecPropertySetIterator* newPropertySetIterator () const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <param name= 'id'> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </param>
	///
	/// <returns> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </returns> 
	/// 
    virtual FormatCodecPropertyInterface* getProperty ( FormatCodecPropertyInterface::PropertyIdentifier id ) const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <param name= 'sbPropertyName'> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </param>
	///
	/// <returns> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </returns> 
	///
    virtual FormatCodecPropertyInterface* getProperty ( StringBuffer sbPropertyName ) const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
    /// 
	/// <returns> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </returns> 
	///
    virtual RowProviderInterface* read () = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <param name= 'dScale'> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </param>
	/// <param name= 'filterMethod'> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </param>
	///
	/// <returns> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </returns> 
	///
    virtual RowProviderInterface* scaledRead (const double& dScale, Resample::FilterTypes filterMethod) = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
    ///
    /// <returns> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </returns>
	///
    virtual int numClosureSetFiles () const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
	///
	/// <param name= 'nIndex'> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </param>
	///
	/// <returns> See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </returns> 
	///
    virtual FileSpecifier getClosureSetFilename (int nIndex) const = 0;

    /// <summary>
    /// See <c>FileReadDescriptor</c>. <see cref="FileReadDescriptor"/>
    /// </summary>
    virtual ~FileReadDescriptorRep ();

};

} // end of namespace Ztil
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif

