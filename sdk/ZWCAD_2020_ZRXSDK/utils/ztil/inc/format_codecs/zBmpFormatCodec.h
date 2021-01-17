#ifndef  ZIMAGEFORMATCODEC_H
#include <zImageFormatCodec.h>
#endif

#ifndef ZFORMATCODECAPIVERSIONINTERFACE_H
namespace Ztil { class FormatCodecApiVersionInterface; }
#endif

#ifndef ZBMPFORMATCODEC_H
#define ZBMPFORMATCODEC_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif
extern "C"
{
    /// <summary>
    /// This method is required to be exported as part of the ZTIL Format codec interface.
    /// It is used for checking the version of the library the format codec API the 
    /// implementation is based.
    /// </summary>
    ///
    /// <returns>
    /// An instance of the <c>FormatCodecApiVersionInterface</c> class.
    /// </returns>
    ///
    ZTIL_GCC_DEFAULT const Ztil::FormatCodecApiVersionInterface* ZTIL_EXPORT bmpApiVersion ();
}

/// <summary>
/// The implementation of the <c>Ztil::ImageFormatCodec</c> API for the purpose of reading
/// Windows BMP/DIB bitmap files.
/// </summary>
///
class DllImpExp BmpFormatCodec : public Ztil::ImageFormatCodec, public Ztil::ImageFormatCodecStreamingInterface
{
public:
    /// <summary>
    /// The simple constructor.
    /// </summary>
    /// 
    BmpFormatCodec ();

    /// <summary>
    /// The virtual destructor.
    /// </summary>
    ///
    virtual ~BmpFormatCodec ();

    /// <summary>
    /// This method allows the <c>BmpFormatCodec</c> to return it's version
    /// information. 
    /// </summary>
    ///
    /// <param name="nLibMajor">An unsigned integer reference that should be 
    /// assigned the major version number for the <c>BmpFormatCodec</c>.
    /// </param>
    ///
    /// <param name="nLibMinor">An unsigned integer reference that should be 
    /// assigned the minor version number for the <c>BmpFormatCodec</c>.
    /// </param>
    ///
    /// <param name="nRelease">An unsigned integer reference that should be 
    /// assigned the Release number for this build of the <c>ImageFormatCodec</c>.</param>
    ///
    /// <param name="nBranch">An unsigned integer reference that should be 
    /// assigned the Branch number for this build of the <c>ImageFormatCodec</c>.</param>
    ///
    /// <param name="nBuild">An unsigned integer reference that should be 
    /// assigned the build number for the <c>ImageFormatCodec</c>.
    /// </param>
    ///
    virtual void getLibVersionInfo (unsigned int& nLibMajor, unsigned int& nLibMinor
        , unsigned int& nRelease, unsigned int& nBranch, unsigned int& nBuild) const;

    /// <summary>
    /// ZTIL defines version numbers that are used to track the revisions to the
    /// the API defined by <c>ImageFormatCodec</c> and other classes that are used
    /// to interface between ZTIL and the format codecs.  When an <c>ImageFormatCodec</c>
    /// is created it will have these version numbers encoded within it. They
    /// are then returned in this call to ZTIL which can check for compatibility with
    /// the codec compiled version.
    /// </summary>
    ///
    /// <param name="nMajor">An unsigned integer reference that should be 
    /// assigned the major version number for the <c>BmpFormatCodec</c> API.
    /// </param>
    ///
    /// <param name="nMinor">An unsigned integer reference that should be 
    /// assigned the minor version number for the <c>BmpFormatCodec</c> API.
    /// </param>
    ///
    virtual void getApiVersionInfo (unsigned int& nMajor, unsigned int& nMinor) const;

    /// <summary>
    /// This query returns the appropriate value from the <c>CodecCapability</c> 
    /// <see cref="ImageFormatCodec::CodecCapability"/> 
    /// </summary>
    ///
	/// <returns>
	/// This returns a value from the <c>CodecCapability</c> enum.
	/// </returns>
	///
    virtual Ztil::ImageFormatCodec::CodecCapability codecCapability () const;

    /// <summary>
    /// This method is used to verify that a filename selected is valid and 
    /// can be written to. As the <c>FileSpecifier</c> argument can encode both 
    /// <c>kFilePath</c> and <c>kOther</c>, the implementation of this method may 
    /// do more than verify the validity of File I/O queries.
    /// </summary>
    ///
    /// <param name="fs">A const reference to a <c>FileSpecifier</c><see cref="FileSpecifier"/>
    /// instance that holds the "file" that will be potentially written to.
    /// </param>
    ///
	/// <returns>
	/// This method returns true if the file can be created.
	/// </returns>
	///
    virtual bool isValidFileName (const Ztil::FileSpecifier& fs) const;

    /// <summary>
    /// This query returns the appropriate value for the format from the 
    /// <c>FormatType</c><see cref="FormatType"/> enum.
    /// </summary>
    ///
	/// <returns>
	/// This returns an entry from the <c>FormatType</c> enum.
	/// </returns>
	///
    virtual Ztil::ImageFormatCodec::FormatType getFormatDecodabilityType () const;

    /// <summary>
    /// This query returns the appropriate value for the format from the 
    /// <c>FormatOrganization</c><see cref="FormatOrganization"/> enum.
    /// </summary>
    ///
	/// <returns>
	/// This query returns a value from <c>FormatOrganization</c> enum.
	/// </returns>
	///
    virtual FormatOrganization getFormatOrganization () const;

    /// <summary>
    /// This query returns the appropriate value for the format from the 
    /// <c>FormatFrameType</c><see cref="FormatFrameType"/> enum.
    /// </summary>
    ///
	/// <returns>
	/// This query returns a value from <c>FormatFrameType</c> enum.
	/// </returns>
	///
    virtual FormatFrameType getFormatFrameType () const;

    /// <summary>
    /// This query returns the appropriate value for the format from the 
    /// <c>FormatFeature</c><see cref="FormatFeature"/> enum.
    /// </summary>
    ///
    /// <param name="feature">An enum entry indicating the <c>FormatFeature</c>
    /// being queried.
    /// </param>
    ///
    /// <returns>
    /// This will return true if the <c>FormatFeature</c> is supported.
    /// </returns>
    ///
    virtual bool isFormatFeature ( FormatFeature feature ) const;

    /// <summary>
    /// This method allows the application to test for the ability
    /// to read or write a property to or from a file.
    /// </summary>
    ///
    /// <param name="propId">A definition from the <c>FormatCodecPropertyInterface::PropertyIdentifier</c>
    /// that indicates the property that is of interest.
    /// </param>
    ///
    /// <param name="pCustomPropertyName">A <c>String buffer pointer</c> (or NULL) that
    /// holds the "name" of a property. This string match system can be used
    /// to query for non-ZTIL defined properties.
    /// </param>
    ///
    /// <returns>
    /// This will return true if the property is supported by the codec.
    /// </returns>
    ///
    virtual bool isSupportedProperty (
        Ztil::FormatCodecPropertyInterface::PropertyIdentifier propId,
		Ztil::StringBuffer* pCustomPropertyName = (Ztil::StringBuffer*) NULL ) const;

    /// <summary>
    /// If a format as one or more extensions (ie .bmp, .dib, etc.) then it
    /// should return the number of extensions that it wants to associate with this format.
    /// </summary>
    ///
	/// <returns>
	/// This returns the integer number of extensions.
	/// </returns>
	///
    /// <remarks>
    /// ZTIL does not use the extensions (letters after the . within the file name) to 
    /// identify an image file encoding. Each registered <c>ImageFormatCodec</c> instance
    /// will have a chance to claim the file as it's format until the file has been claimed.
    /// </remarks>
    ///
    virtual int getNumExtensions () const;

    /// <summary>
    /// This method provides a description of each extension that is supported for use
    /// by the application and maybe displayed to the user. Such descriptions are common
    /// elements of Windows(tm) file browsing dialogs. (ie .bmp, .dib, etc.)
    /// </summary>
    ///
    /// <param name="nExtensionIndex">The integer index of the extension description to
    /// retrieve. It ranges from zero to <c>getNumeExtensions() - 1</c>.
    /// </param>
    ///
    /// <param name="sbExtension">A reference to a <c>StringBuffer</c> instance that will
    /// be set to the extension text.
    /// </param>
    ///
    virtual void getExtensionText (int nExtensionIndex,
        Ztil::StringBuffer& sbExtension) const;

    /// <summary>
    /// This method returns the full name of the format that the <c>ImageFormatCodec</c> handles.
    /// It may be used by the caller and displayed in the UI for the application.
    /// </summary>
    ///
    /// <param name="sbFormatName">A reference to a <c>StringBuffer</c> instance that will
    /// be set to the format name text.
    /// </param>
    ///
    virtual void getFormatName (Ztil::StringBuffer& sbFormatName) const;

    /// <summary>
    /// This method returns a description of the format. 
    /// It may be used by the caller and displayed in the UI for the application.
    /// </summary>
    ///
    /// <param name="sbDescription">A reference to a <c>StringBuffer</c> instance that will
    /// be set to the format description text.
    /// </param>
    ///
    virtual void getDescriptionText (Ztil::StringBuffer& sbDescription) const;

    /// <summary>
    /// This method returns any copyright information of the format or source code used
    /// in the implementation of the <c>ImageFormatCodec</c>. It may be used by the caller
    /// and displayed in the UI for the application.
    /// </summary>
    ///
    /// <param name="sbCopyright">A reference to a <c>StringBuffer</c> instance that will
    /// be set to the format copyright text.
    /// </param>
    ///
    virtual void getCopyrightText (Ztil::StringBuffer& sbCopyright) const;

    /// <summary>
    /// This method is used by <c>FileReadDescriptor</c> to check the readability of a given file. 
    /// It applies only to this format handler. It is not meant to be used by application developers. 
    /// </summary>
    ///
    /// <param name="fileSpecifier">A constant <c>FileSpecifier</c> instance that holds
    /// the "path" of the encoded image is to be tested.
    /// </param>
    /// 
    /// <param name="ff">A pointer to a <c>FindFileInterface</c> derived class or NULL. 
    /// </param>
    ///
	/// <returns>
	/// This query returns a value from <c>FormatDecodability</c> enum.
	/// </returns>
	///
    /// <remarks>
    /// The <c>FileReadDescriptor</c> exposes a static method should be used by applications
    /// to determine if a file is a 'decodable' image file.
    /// </remarks>
    ///
    virtual Ztil::ImageFormatCodec::FormatDecodability isDecodableFile (
        const Ztil::FileSpecifier& fileSpecifier, Ztil::FindFileInterface * ff = NULL ) const;

    /// <summary>
    /// This method is used by <c>FileWriteDescriptor</c> to check the write ability of a 
    /// given image. It tests the type and size of an image's encode ability in the format.
    /// It is not meant to be used by application developers. 
    /// </summary>
    ///
    /// <param name="allAboutImageData">A const reference to a <c>DataModelAttributes</c>
    /// instance that describes the color and image type of the data to be encoded.
    /// </param>
    /// 
    /// <param name="size">The size in pixels of the data to be encoded.
    /// </param>
    ///
	/// <returns>
	/// This returns true of the codec can encode the data being queried.
	/// </returns>
	///
    /// <remarks>
    /// The <c>FileWriteDescriptor</c> class exposes static methods should be used by 
    /// application developers to test the ability of a <c>ImageFormatCodec</c> to 
    /// encode the image type.
    /// </remarks>
    ///
    virtual bool isEncodableImage (const Ztil::DataModelAttributes& allAboutImageData,
        Ztil::Size size ) const;

    /// <summary>
    /// This method is used by <c>FileReadDescriptor</c> to open an image file for decoding.
    /// </summary>
    /// 
    /// <param name="fsThisImage">A constant <c>FileSpecifier</c> instance that holds
    /// the "path" of the encoded image is to be opened.
    /// </param>
    ///  
    /// <returns>
    /// This method returns an instance (pointer to) of the <c>ReadImageFileInterface</c>
    /// for use by the <c>FileReadDescriptor</c> in decoding the image data.
    /// </returns>
    /// 
    /// <remarks>
    /// This method is not for use by application developers. It is an internal ZTIL method.
    /// </remarks>
    ///
    virtual Ztil::ReadImageFileInterface* openImage (
        const Ztil::FileSpecifier* fsThisImage) const;

    /// <summary>
    /// This method is used by <c>FileReadDescriptor</c> to open an image file for decoding.
    /// </summary>
    /// 
    /// <param name="fsThisImage">A constant <c>FileSpecifier</c> instance that holds
    /// the "path" of the encoded image is to be opened.
    /// </param>
    /// 
    /// <param name="ff">An instance of a <c>FindFileInterface</c> derived class. 
    /// </param>
    ///
    /// <returns>
    /// This method returns an instance (pointer to) of the <c>ReadImageFileInterface</c>
    /// for use by the <c>FileReadDescriptor</c> in decoding the image data.
    /// </returns>
    /// 
    /// <remarks>
    /// This method is not for use by application developers. It is an internal ZTIL method.
    /// </remarks>
    ///
    virtual Ztil::ReadImageFileInterface * openImage (
        const Ztil::FileSpecifier* fsThisImage, Ztil::FindFileInterface& ff) const;

    /// <summary>
    /// This method is used by <c>FileReadDescriptor</c> to open an image file for decoding.
    /// </summary>
    /// 
    /// <param name="pdsStream">An pointer to a <c>Ztil::SeekableDataStreamInterface</c> derived class 
    /// that provides a stream of data to be encoded.
    /// </param>
    /// 
    /// <returns>
    /// This method returns an instance (pointer to) of the <c>ReadImageFileInterface</c>
    /// for use by the <c>FileReadDescriptor</c> in decoding the image data.
    /// </returns>
    /// 
    /// <remarks>
    /// The DataStreamInterface classes must be <c>Ztil::SeekableDataStreamInterface</c>  class.
    /// </remarks>
    ///
    virtual Ztil::ReadImageFileInterface* openImage (Ztil::DataStreamInterface* pdsStream) const;

    /// <summary>
    /// This method is used by <c>FileWriteDescriptor</c> to open a file for image encoding.
    /// </summary>
    /// 
    /// <returns>
    /// This method returns an instance (pointer to) of the <c>WriteImageFileInterface</c>
    /// for use by the <c>FileWriteDescriptor</c> in encoding the image data.
    /// </returns>
    /// 
    /// <remarks>
    /// This method is not for use by application developers. It is an internal ZTIL method.
    /// </remarks>
    ///
    virtual Ztil::WriteImageFileInterface* writeImage ( ) const;

    /// <summary>
    /// This method is used by <c>FileWriteDescriptor</c> to open a stream for image encoding.
    /// </summary>
    /// 
    /// <param name="pdsStream">An pointer to a <c>DataStreamInterface</c> derived class
    /// that provides a stream of data to be encoded.
    /// </param>
    ///
    /// <returns>
    /// This method returns an instance (pointer to) of the <c>WriteImageFileInterface</c>
    /// for use by the <c>FileWriteDescriptor</c> in encoding the image data.
    /// </returns>
    /// 
    /// <remarks>
    /// This method is not for use by application developers. It is an internal ZTIL method.
    /// </remarks>
    ///
    virtual Ztil::WriteImageFileInterface* writeImage (Ztil::DataStreamInterface* pdsStream) const;

    /// <summary>
    /// This method is used by <c>FileReadDescriptor</c> in it's copy constructor to 
    /// open a new connection to the data source.
    /// </summary>
    ///
    /// <param name="pOpenImage">An open image to be copied. 
    /// </param>
    ///
    /// <param name="ff">An instance of a <c>FindFileInterface</c> derived class. 
    /// This may be referenced during construction of the clone.
    /// </param>
    ///
    /// <returns>
    /// This method returns an instance (pointer to) of the <c>ReadImageFileInterface</c>
    /// for use by the <c>FileReadDescriptor</c> in decoding the image data.
    /// </returns>
    /// 
    /// <remarks>
    /// This method is not for use by application developers. It is an internal ZTIL method.
    /// </remarks>
    ///
    virtual Ztil::ReadImageFileInterface* cloneOpenImage (
        const Ztil::ReadImageFileInterface* pOpenImage, Ztil::FindFileInterface& ff ) const;

    /// <summary> This method passes an extension to act as a pretest for a format
    /// match. If this returns true, then an isDecodable call will follow.</summary>
    /// <param name="pExt">This is the file extension in the ASCII character
    /// format. The extension will be in ASCII to make testing quicker.</param>
    /// <returns> This should return true for an extension match. This is quick
    /// test and if true is returned a isDecodable check will follow.</returns>
    virtual bool isExtensionMatch(const char* pExt) const;
};
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif
#endif

