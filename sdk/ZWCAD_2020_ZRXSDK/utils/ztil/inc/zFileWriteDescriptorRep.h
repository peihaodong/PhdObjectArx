#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif
#ifndef ZFORMATCODECPROPERTYINTERFACE_H
#include "zFormatCodecPropertyInterface.h"
#endif
#ifndef ZDATASTREAMINTERFACE_H
namespace Ztil { class DataStreamInterface; }
#endif
#ifndef ZIMAGEFORMATCODEC_H
namespace Ztil { class ImageFormatCodec; }
#endif
#ifndef ZFORMATCODECPROPERTYSETITERATOR_H
namespace Ztil { class FormatCodecPropertySetIterator; }
#endif
#ifndef ZROWPROVIDERINTERFACE_H
namespace Ztil { class RowProviderInterface; }
#endif
#ifndef ZFILESPECIFIER_H
namespace Ztil { class FileSpecifier; }
#endif
#ifndef ZFILEREADDESCRIPTOR_H
namespace Ztil { class FileReadDescriptor; }
#endif
#ifndef ZDATAMODEL_H
namespace Ztil { class DataModel; }
#endif
#ifndef ZSIZE_H
namespace Ztil { class Size; }
#endif

#ifndef ZFILEWRITEDESCRIPTORREP_H
#define ZFILEWRITEDESCRIPTORREP_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{

/// <summary>
/// This class serves as an abstract base class for the <c>FileWriteDescriptor</c>.
/// </summary>
class DllImpExp FileWriteDescriptorRep 
{
public:
    /// <summary>
    /// See <c>FileWriteDescriptor</c>. <see cref="Ztil::FileWriteDescriptor"/>
    /// </summary>
    virtual ~FileWriteDescriptorRep ();

    /// <summary>
    /// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
    /// </summary>
	/// 
	/// <param name= "codec">
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </param>
	/// 
    virtual void construct (const ImageFormatCodec* codec) = 0;

    /// <summary>
    /// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
    /// </summary>
	/// 
	/// <returns>
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </returns>
	///
    virtual const ImageFormatCodec* formatCodec () const = 0;

    /// <summary>
    /// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
    /// </summary>
	/// 
	/// <param name= "fs">
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </param>
	/// 
    virtual void getFileSpecifier (FileSpecifier& fs) const = 0;

    /// <summary>
    /// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
    /// </summary>
	/// 
	/// <param name= "fs">
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </param>
	/// 
	/// <returns>
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </returns>
	///
    virtual bool setFileSpecifier (const FileSpecifier& fs) = 0;

    /// <summary>
    /// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
    /// </summary>
	/// 
	/// <param name= "pdsStream">
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </param>
	/// 
    virtual void setOutputStream (DataStreamInterface* pdsStream) = 0;

    /// <summary>
    /// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
    /// </summary>
	/// 
	/// <param name= "dataModel">
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </param>
	/// 
	/// <param name= "size">
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </param>
	/// 
    virtual void createImageFrame (const DataModel& dataModel, Size size) = 0;
    
    /// <summary>
    /// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
    /// </summary>
	/// 
	/// <returns>
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </returns>
	///
    virtual bool requiredPropertiesSet () const = 0;

    /// <summary>
    /// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
    /// </summary>
	/// 
	/// <returns>
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </returns>
	///
    virtual FormatCodecPropertySetIterator* newPropertySetIterator () = 0;

    /// <summary>
    /// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
    /// </summary>
	/// 
	/// <param name= "id">
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </param>
	/// 
	/// <returns>
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </returns>
	///
    virtual FormatCodecPropertyInterface* getProperty ( FormatCodecPropertyInterface::PropertyIdentifier id ) const = 0;

    /// <summary>
    /// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
    /// </summary>
	/// 
	/// <param name= "sbPropertyName">
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </param>
	/// 
	/// <returns>
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </returns>
	///
    virtual FormatCodecPropertyInterface* getProperty ( StringBuffer sbPropertyName ) const = 0;

    /// <summary>
    /// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
    /// </summary>
	/// 
	/// <param name= "pProperty">
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </param>
	/// 
	/// <returns>
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </returns>
	///
    virtual bool setProperty ( const FormatCodecPropertyInterface* pProperty ) = 0;

    /// <summary>
    /// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
    /// </summary>
	/// 
	/// <param name= "fd">
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </param>
	/// 
	/// <returns>
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </returns>
	///
    virtual bool setProperties (const FileReadDescriptor* fd) = 0;

    /// <summary>
    /// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
    /// </summary>
	/// 
	/// <param name= "rowProvider">
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </param>
	/// 
	/// <returns>
	/// See <c>FileWriteDescriptor</c>. <see cref="FileWriteDescriptor"/>
	/// </returns>
	///
    virtual int writeImageFrame (RowProviderInterface* rowProvider) = 0;

    /// <summary>Commits any pending writes and closes the written file </summary>
    /// <remarks>This is also called at class destruction.</remarks>
    virtual void closeFile() = 0;
};

} // end of namespace Ztil
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
