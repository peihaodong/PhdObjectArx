#ifndef ZFORMATCODECPROPERTYINTERFACE_H
#include <zFormatCodecPropertyInterface.h>
#endif
#ifndef ZFORMATCODECINTPROPERTY_H
#include <zFormatCodecIntProperty.h>
#endif
#ifndef ZFORMATCODECDOUBLEPROPERTY_H
#include <zFormatCodecDoubleProperty.h>
#endif
#ifndef ZFORMATCODECSTRINGPROPERTY_H
#include <zFormatCodecStringProperty.h>
#endif
#ifndef ZFORMATCODECINCLUSIVEPROPERTYSETINTERFACE_H
#include <zFormatCodecInclusivePropertySetInterface.h>
#endif
#ifndef ZFORMATCODECEXCLUSIVEPROPERTYSETINTERFACE_H
#include <zFormatCodecExclusivePropertySetInterface.h>
#endif
#ifndef ZFORMATCODECPROPERTYSETITERATOR_H
#include <zFormatCodecPropertySetIterator.h>
#endif
#ifndef ZFORMATCODECTRANSPARENCY_H
#include <zFormatCodecTransparency.h>
#endif
#ifndef ZFORMATCODECDENSITY_H
#include <zFormatCodecDensity.h>
#endif
#ifndef ZFORMATCODECCOLORPROPERTY_H
#include <zFormatCodecColorProperty.h>
#endif
#ifndef ZFORMATCODECBOOLEANPROPERTY_H
#include <zFormatCodecBooleanProperty.h>
#endif

#ifndef ZPNGFORMATCODEC_H
#include <zPngFormatCodec.h>
#endif

#ifndef PNG_H
struct png_info_struct;
typedef struct png_info_struct png_info;
typedef png_info* png_infop;

struct png_struct_def;
typedef struct png_struct_def png_struct;
typedef png_struct* png_structp;
#endif

#ifndef ZPNGCUSTOMPROPERTIES_H
#define ZPNGCUSTOMPROPERTIES_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif
/// <summary>
/// This is a common base class for all PNG custom classes. It is intended to allow
/// easy identification of exported properties.
/// </summary>
///
class DllImpExp PngCustomProperty
{
public:
    /// <summary>
    /// The virtual destructor.
    /// </summary>
    ///
    virtual ~PngCustomProperty();

    /// <summary>
    /// This queries the <c>PngFormatCodec::PngIdentifier</c> for the derived property.
    /// </summary>
    ///
    /// <returns>
    /// This returns a member of the <c>PngFormatCodec::PngIdentifier</c> enum to identify
    /// the derived property.
    /// </returns>
    ///
    PngFormatCodec::PngIdentifier pngId ( ) const;

    /// <summary>
    /// (Private) This is an internally used method.
    /// </summary>
    ///
	/// <returns>
	/// (Private) This is an internally used method.
    /// </returns>
    ///
    virtual bool writeBefore ( ) const;

    /// <summary>
    /// (Private) This is an internally used method.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
	/// <returns>
	/// (Private) This is an internally used method.
	/// </returns>
	///
    virtual bool write ( png_structp pPng, png_infop pInfo ) const = 0;

protected:
    /// <summary>
    /// (Private) This is an internally used member.
    /// </summary>
    ///
    PngFormatCodec::PngIdentifier mPngId;

    /// <summary>
    /// (Private) This is an internally used member.
    /// </summary>
    ///
    bool mbWriteBeforePLTE;
};

/// <summary>
/// This property returns the PNG Gamma information for the image.
/// </summary>
///
/// <remarks>
/// This class is a thin wrapper around the <c>Ztil::FormatCodecDoubleProperty</c> property.
/// Access to the members is through the base class.
/// </remarks>
///
class DllImpExp PngGamma : public Ztil::FormatCodecDoubleProperty, public PngCustomProperty
{
public:
    /// <summary>
    /// The constructor.
    /// </summary>
    ///
    PngGamma ();

    /// <summary>
    /// (Private) The internal constructor.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
    PngGamma (png_structp pPng, png_infop pInfo);

    /// <summary>
    /// The destructor.
    /// </summary>
    ///
    ~PngGamma ();

    /// <summary>
    /// This method is an artificial copy constructor. All properties
    /// that are not trivial (no additional methods or data) derivations or 
    /// instances of ZTIL defined property classes should implement this method.
    /// </summary>
    ///
    /// <returns>
    /// This method returns the new <c>FormatCodecPropertyInterface</c> instance.
    /// </returns>
    ///
    virtual Ztil::FormatCodecPropertyInterface* clone () const;

    /// <summary>
    /// (Private) This is an internally used method.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
	/// <returns>
	/// (Private) This is an internally used method.
	/// </returns>
	///
    bool write ( png_structp pPng, png_infop pInfo ) const;
};

/// <summary>
/// This property encodes the PNG optional scale factor for image display.
/// </summary>
///
class DllImpExp PngScale : public Ztil::FormatCodecInclusivePropertySetInterface, public PngCustomProperty
{
public:
    /// <summary>
    /// The constructor.
    /// </summary>
    ///
    PngScale ();

    /// <summary>
    /// (Private) The internal constructor.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
    PngScale (png_structp pPng, png_infop pInfo);

    /// <summary>
    /// The destructor.
    /// </summary>
    ///
    ~PngScale ();

    /// <summary>
    /// This method is an artificial copy constructor. All properties
    /// that are not trivial (no additional methods or data) derivations or 
    /// instances of ZTIL defined property classes should implement this method.
    /// </summary>
    ///
    /// <returns>
    /// This method returns the new <c>FormatCodecPropertyInterface</c> instance.
    /// </returns>
    ///
    virtual Ztil::FormatCodecPropertyInterface* clone () const;

    /// <summary>
    /// (Private) This is an internally used method.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
	/// <returns>
	/// (Private) This is an internally used method.
	/// </returns>
	///
    bool write ( png_structp pPng, png_infop pInfo ) const;
};

/// <summary>
/// This property represents the optional PNG page offsetting information.
/// </summary>
///
class DllImpExp PngPageOffset : public Ztil::FormatCodecInclusivePropertySetInterface, public PngCustomProperty
{
public:
    /// <summary>
    /// The constructor.
    /// </summary>
    ///
    PngPageOffset ();

    /// <summary>
    /// (Private) The internal constructor.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
    PngPageOffset (png_structp pPng, png_infop pInfo);

    /// <summary>
    /// The destructor.
    /// </summary>
    ///
    ~PngPageOffset ();

    /// <summary>
    /// This method is an artificial copy constructor. All properties
    /// that are not trivial (no additional methods or data) derivations or 
    /// instances of ZTIL defined property classes should implement this method.
    /// </summary>
    ///
    /// <returns>
    /// This method returns the new <c>FormatCodecPropertyInterface</c> instance.
    /// </returns>
    ///
    virtual Ztil::FormatCodecPropertyInterface* clone () const;

    /// <summary>
    /// (Private) This is an internally used method.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
	/// <returns>
	/// (Private) This is an internally used method.
	/// </returns>
	///
    bool write ( png_structp pPng, png_infop pInfo ) const;
};

/// <summary>
/// This property holds the any of the many different strings that can be stored in a PNG file.
/// </summary>
///
class DllImpExp PngText : public Ztil::FormatCodecStringProperty, public PngCustomProperty
{
public:
    /// <summary>
    /// An enum with descriptions for the different strings in PNG.
    /// </summary>
    ///
    enum Keyword { 
        /// <summary>
        /// This entry is a comment embedded in the image.
        /// </summary>        
        kComment = 0, 
        /// <summary>
        /// This entry is the title for the image.
        /// </summary>        
        kTitle, 
        /// <summary>
        /// This entry is the author of the image.
        /// </summary>        
        kAuthor, 
        /// <summary>
        /// This entry is the description of the image.
        /// </summary>        
        kDescription, 
        /// <summary>
        /// This entry is the copyright information for the image.
        /// </summary>        
        kCopyright, 
        /// <summary>
        /// This entry is the time of creation of the image.
        /// </summary>        
        kCreationTime,
        /// <summary>
        /// This entry is the software name for the application that created the image.
        /// </summary>        
        kSoftware, 
        /// <summary>
        /// This entry is a disclaimer for the image.
        /// </summary>        
        kDisclaimer, 
        /// <summary>
        /// This entry is a warning for the image.
        /// </summary>        
        kWarning, 
        /// <summary>
        /// This entry is the source of the image.
        /// </summary>        
        kSource 
    };

    /// <summary>
    /// This static method will return the ASCII property name from the keyword string type.
    /// </summary>
    /// 
    /// <param name="key"> The enum <c>Keyword</c> entry to translate to a string property name.
    /// </param>
    ///
    /// <returns>
    /// A const pointer to an ASCII character array.
    /// </returns>
    ///
    static const char* getString ( Keyword key );

public:
    /// <summary>
    /// The constructor.
    /// </summary>
    ///
    /// <param name='sbDefault'> The default string of text. </param>
    ///
    /// <param name='nMaximumBytes'> The maximum number of bytes that the string of text can occupy. </param>
    ///
    /// <param name='key'> An enum entry describing the type or usage of the string. </param>
    ///
    PngText ( const Ztil::StringBuffer& sbDefault, int nMaximumBytes, Keyword key = kComment );

    /// <summary>
    /// The destructor.
    /// </summary>
    ///
    ~PngText ();

    /// <summary>
    /// This method is an artificial copy constructor. All properties
    /// that are not trivial (no additional methods or data) derivations or 
    /// instances of ZTIL defined property classes should implement this method.
    /// </summary>
    ///
    /// <returns>
    /// This method returns the new <c>FormatCodecPropertyInterface</c> instance.
    /// </returns>
    ///
    virtual Ztil::FormatCodecPropertyInterface* clone () const;

    /// <summary>
    /// This method will get the keyword text from a constructed instance.
    /// </summary>
    ///
    /// <param name="pKeyword"> A const array reference that will be set with the keyword string.
    /// </param>
    ///
    void getKeyword ( const char*& pKeyword ) const;

    /// <summary>
    /// (Private) This is an internally used method.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
	/// <returns>
	/// (Private) This is an internally used method.
	/// </returns>
	///
    bool write ( png_structp pPng, png_infop pInfo ) const;

protected:
    /// <summary>
    /// (Protected) The <c>Keyword</c> entry describing the text context.
    /// </summary>
    ///
    Keyword mKeyword;

    /// <summary>
    /// (Protected) The static array of ASCII keyword entry names.
    /// </summary>
    ///
    static const char* mcpKeywords[10];
};

/// <summary>
/// This property encloses the PNG representation of the sRGB color property.
/// </summary>
///
class DllImpExp PngSRGB : public Ztil::FormatCodecExclusivePropertySetInterface, public PngCustomProperty
{

    enum Intent { 
        kPerceptual = 0, 
        kRelative, 
        kSaturation, 
        kAbsolute
    };

public:
    /// <summary>
    /// The constructor.
    /// </summary>
    ///
    PngSRGB ( );

    /// <summary>
    /// (Private) The internal constructor.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
    PngSRGB ( png_structp pPng, png_infop pInfo );

    /// <summary>
    /// The virtual destructor.
    /// </summary>
    ///
    ~PngSRGB ();

    /// <summary>
    /// This method is an artificial copy constructor. All properties
    /// that are not trivial (no additional methods or data) derivations or 
    /// instances of ZTIL defined property classes should implement this method.
    /// </summary>
    ///
    /// <returns>
    /// This method returns the new <c>FormatCodecPropertyInterface</c> instance.
    /// </returns>
    ///
    virtual Ztil::FormatCodecPropertyInterface* clone () const;

    /// <summary>
    /// This method selects the model of sRGB for the image.
    /// </summary>
    ///
    /// <param name="nSelectionIndex"> The index to be set as selected.
    /// </param>
    ///    
    virtual void setSelectedIndex (int nSelectionIndex);

    /// <summary>
    /// (Private) This is an internally used method.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
	/// <returns>
	/// (Private) This is an internally used method.
	/// </returns>
	///
    bool write ( png_structp pPng, png_infop pInfo ) const;
private:
    Intent mSRgbIntent;
};

/// <summary>
/// This property encloses the PNG representation of the Histogram information.
/// </summary>
///
class DllImpExp PngHistogram : public Ztil::FormatCodecPropertyInterface, public PngCustomProperty
{
public:
    /// <summary>
    /// The constructor.
    /// </summary>
    ///
    PngHistogram ();

    /// <summary>
    /// (Private) The internal constructor.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
    PngHistogram (png_structp pPng, png_infop pInfo);

    /// <summary>
    /// The virtual destructor.
    /// </summary>
    ///
    ~PngHistogram ();

    /// <summary>
    /// This method is an artificial copy constructor. All properties
    /// that are not trivial (no additional methods or data) derivations or 
    /// instances of ZTIL defined property classes should implement this method.
    /// </summary>
    ///
    /// <returns>
    /// This method returns the new <c>FormatCodecPropertyInterface</c> instance.
    /// </returns>
    ///
    virtual Ztil::FormatCodecPropertyInterface* clone () const;

    /// <summary>
    /// This method queries the number of entries of histogram data.
    /// </summary>
    ///
    /// <returns>
    /// This method returns integer number of entries.
    /// </returns>
    ///
    int numEntries () const;

    /// <summary>
    /// This method will retrieve the counts of frequency in the histogram.
    /// </summary>
    /// 
    /// <param name="nEntries"> The number of entries of histogram data to retrieve.
    /// </param>
    ///
    /// <param name="pEntries"> An array of unsigned shorts to receive the histogram counts.
    /// </param>
    ///
    void getHistogram ( int nEntries, unsigned short* pEntries ) const;
    
    /// <summary>
    /// This method will set the counts of frequency into the histogram chunk of the image.
    /// </summary>
    /// 
    /// <param name="nEntries"> The number of entries of histogram data to set.
    /// </param>
    ///
    /// <param name="pEntries"> An array of unsigned shorts that contain the histogram counts.
    /// </param>
    ///
    void setHistogram ( int nEntries, unsigned short* pEntries );

    /// <summary>
    /// (Private) This is an internally used method.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
	/// <returns>
	/// (Private) This is an internally used method.
	/// </returns>
	///
    bool write ( png_structp pPng, png_infop pInfo ) const;

private:
    unsigned short * masHistogram;
    int mnEntries;
};

/// <summary>
/// This property will return the number of bits that are actually used in a data unit of the image.
/// An example might be where an images uses 4 bits for 16 shades of gray but returns 8 bits per pixel.
/// </summary>
///
class DllImpExp PngGraySignificantBits : public Ztil::FormatCodecIntProperty, public PngCustomProperty
{
public:
    /// <summary>
    /// The constructor.
    /// </summary>
    ///
    PngGraySignificantBits ();

    /// <summary>
    /// (Private) The internal constructor.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
    PngGraySignificantBits (png_structp pPng, png_infop pInfo);

    /// <summary>
    /// The destructor.
    /// </summary>
    ///
    ~PngGraySignificantBits ();

    /// <summary>
    /// (Private) This is an internally used method.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
	/// <returns>
	/// (Private) This is an internally used method.
	/// </returns>
	///
    bool write ( png_structp pPng, png_infop pInfo ) const;
};

/// <summary>
/// This class represents a level of the lossless zlib compression for compressing in PNG.
/// </summary>
///
class DllImpExp PngCompressionType : public Ztil::FormatCodecPropertyInterface
{
public:
    /// <summary>
    /// This enum lists various levels of compression where higher levels take longer to complete.
    /// </summary>
    ///
	enum Compression { 
        /// <summary>
        /// This indicates no compression.
        /// </summary>
        kNone = 0, 
        /// <summary>
        /// This indicates low compression for fast completion.
        /// </summary>
        kLow = 1, 
        /// <summary>
        /// This indicates medium compression.
        /// </summary>
        kMedium = 3, 
        /// <summary>
        /// This indicates normal compression with acceptable performance.
        /// </summary>
        kNormal = 6, 
        /// <summary>
        /// This indicates using the most possible compression without regard to performance.
        /// </summary>
        kHigh = 9 
    };

public:
    /// <summary>
    /// The constructor.
    /// </summary>
    ///
	/// <param name="type">
	/// A entry from the <c>Compression</c> enum stating the compression method.
	/// </param>
	///
	PngCompressionType(Compression type);

    /// <summary>
    /// The destructor.
    /// </summary>
    ///
	~PngCompressionType();


    /// <summary>
    /// This method is an artificial copy constructor. All properties
    /// that are not trivial (no additional methods or data) derivations or 
    /// instances of ZTIL defined property classes should implement this method.
    /// </summary>
    ///
    /// <returns>
    /// This method returns the new <c>FormatCodecPropertyInterface</c> instance.
    /// </returns>
    ///
	virtual Ztil::FormatCodecPropertyInterface* clone() const;

    /// <summary>
    /// This method returns the instances compression type.
    /// </summary>
    ///
    /// <returns>
    /// This returns an entry from the <c>Compression</c> enum.
    /// </returns>
    ///
	Compression type();

private:
	Compression mCompressionType;
};

/// <summary>
/// This property is a set of possible compression levels that are available for use in PNG.
/// </summary>
///
class DllImpExp PngCompression : public Ztil::FormatCodecExclusivePropertySetInterface
{
public:
    /// <summary>
    /// The constructor.
    /// </summary>
    ///
	/// <param name="type">
	/// A entry from the <c>Compression</c> enum stating the compression method.
	/// </param>
	///
	PngCompression(PngCompressionType::Compression type = PngCompressionType::kNormal);

    /// <summary>
    /// The destructor.
    /// </summary>
    ///
	~PngCompression();

public:

    /// <summary>
    /// This method is an artificial copy constructor. All properties
    /// that are not trivial (no additional methods or data) derivations or 
    /// instances of ZTIL defined property classes should implement this method.
    /// </summary>
    ///
    /// <returns>
    /// This method returns the new <c>FormatCodecPropertyInterface</c> instance.
    /// </returns>
    ///
	virtual Ztil::FormatCodecPropertyInterface* clone() const;

    /// <summary>
    /// This method queries the selected compression level at a given index.
    /// </summary>
    ///
    /// <param name="nIndex"> The index to be queried.
    /// </param>
    ///
    /// <returns>
    /// This method returns the <c>PngCompressionType::Compression</c> entry for the given index.
    /// </returns>
    ///
    PngCompressionType::Compression getCompressionType(int nIndex)const;

    /// <summary>
    /// This method selects a compression to use through it's type.
    /// </summary>
    ///
    /// <param name="use"> The <c>PngCompressionType::Compression</c> of the index to be selected.
    /// </param>
    ///
    /// <returns>
    /// This method returns true on success.
    /// </returns>
    ///
    bool selectCompression(PngCompressionType::Compression use);

    /// <summary>
    /// (Private) This is an internally used method.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
	/// <returns>
	/// Internally used.
	/// </returns>
	///
	bool write(png_structp pPng, png_infop pInfo) const;
};

/// <summary>
/// This method represents the PNG option of interlacing data for web display.
/// </summary>
///
class DllImpExp PngInterlacing : public Ztil::FormatCodecBooleanProperty, public PngCustomProperty
{
public:
    /// <summary>
    /// The constructor.
    /// </summary>
    ///
    PngInterlacing ();

    /// <summary>
    /// (Private) The internal constructor.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
    PngInterlacing (png_structp pPng, png_infop pInfo);

    /// <summary>
    /// The destructor.
    /// </summary>
    ///
    ~PngInterlacing ();

    /// <summary>
    /// This method is an artificial copy constructor. All properties
    /// that are not trivial (no additional methods or data) derivations or 
    /// instances of ZTIL defined property classes should implement this method.
    /// </summary>
    ///
    /// <returns>
    /// This method returns the new <c>FormatCodecPropertyInterface</c> instance.
    /// </returns>
    ///
    virtual Ztil::FormatCodecPropertyInterface* clone () const;

    /// <summary>
    /// (Private) This is an internally used method.
    /// </summary>
    ///
    /// <param name="pPng"> Internally used.
    /// </param>
    ///
    /// <param name="pInfo"> Internally used.
    /// </param>
    ///
	/// <returns>
	/// Internally used.
	/// </returns>
	///
    bool write(png_structp pPng, png_infop pInfo) const;
};
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif
#endif
