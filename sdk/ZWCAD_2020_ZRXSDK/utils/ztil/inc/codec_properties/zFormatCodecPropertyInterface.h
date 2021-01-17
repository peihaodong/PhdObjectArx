#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif
#ifndef ZSTRINGBUFFER_H
#include "zStringBuffer.h"
#endif

#ifndef ZFORMATCODECPROPERTYINTERFACE_H
#define ZFORMATCODECPROPERTYINTERFACE_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{

/// <summary>
/// This is the base class for all of ZTIL's properties and all ZTIL codec 
/// properties. This class is organized as an interface class but does implement
/// the query functions for generic property information that is common to 
/// all ZTIL properties. 
/// </summary>
///
/// <remarks>
/// The class is most often used as the poly-morphic base class for handling
/// and passing ZTIL properties. Format Codec writers can and are likely to
/// derive from this class to expose properties containing meta-data or
/// or custom behavior from their Format Codec.
/// </remarks>
///
class DllImpExp FormatCodecPropertyInterface 
{
public:
    /// <summary>
    /// This declares constant identifiers that are used by the ZTIL defined
    /// codecs to identify themselves. 
    /// </summary>
    ///
    enum PropertyIdentifier { 
        /// <summary> 
        /// The constant Id for all properties defined by Format Codecs that
        /// are not derived from ZTIL internally implemented properties.
        /// </summary>
        ///
        kIdCustom = 0,
        /// <summary> 
        /// The constant Id for internal ZTIL properties based on simple
        /// c-style types. i.e. <c> integer, float, string, boolean </c>
        /// </summary>
        ///
        kSimpleType,
        /// <summary> 
        /// The constant Id for internal ZTIL property defining compression.
        /// </summary>
        ///
 	    kCompression,
        /// <summary> 
        /// The constant Id for internal ZTIL property defining density.
        /// </summary>
        ///
        kDensity, 
        /// <summary> 
        /// The constant Id for internal ZTIL property defining data organization.
        /// </summary>
        ///
        kDataOrganization,
        /// <summary> 
        /// The constant Id for internal ZTIL property defining association.
        /// </summary>
        ///
        kAssociation,
        /// <summary> 
        /// The constant Id for internal ZTIL property defining transparency.
        /// </summary>
        ///
        kTransparency,
        /// <summary> 
        /// The constant Id for internal ZTIL property defining correlation.
        /// </summary>
        ///
        kCorrelation,
        /// <summary> 
        /// The constant Id for internal ZTIL property defining color.
        /// </summary>
        ///
        kColor,
        /// <summary> 
        /// The constant Id for internal ZTIL property defining the reference name
        /// for multi-spectral images.
        /// </summary>
        ///
        kMultispectralReferenceName, 
        /// <summary> 
        /// (Deprecated)
        /// The constant Id for internal ZTIL property defining the band name
        /// of an band with a multi-spectral image.
        /// </summary>
        ///
        kMultispectralBandName,
        /// <summary> 
        /// (Deprecated)
        /// The constant Id for internal ZTIL property defining the bucket group
        /// of bands within a multi-spectral image.
        /// </summary>
        ///
        kMultispectralBucket,
        /// <summary> 
        /// (Deprecated)
        /// The constant Id for internal ZTIL property defining coordinate point.
        /// </summary>
        ///
        kLatLon,
        /// <summary> 
        /// The constant Id for internal ZTIL property defining a point.
        /// </summary>
        ///
        kPoint,
        /// <summary> 
        /// The constant Id for internal ZTIL property defining the format of
        /// samples (pixels) of a frame or band in an image.
        /// </summary>
        ///
        kSampleFormat,
        /// <summary>
        /// The constant Id for internal ZTIL property defining the format and
        /// value of void data within an image.
        /// </summary>
        ///
        kVoidData,
        /// <summary>
        /// The constant Id for internal ZTIL property that can be used to describe
        /// multiple correlations with implied rank.
        /// </summary>
        ///
        kCorrelationSet,
        /// <summary>
        /// The constant Id for internal ZTIL property that can be used to describe
        /// order of color channels in a pixel.
        /// </summary>
        ///
        kChannelOrder
    };
 
    /// <summary>
    /// Simple types of properties are used by Codecs as the basis for 
    /// Codec specific properties. There are defined base classes in 
    /// ZTIL for each of the properties except <c> kCustom </c>
    /// </summary>    
    ///
    /// <remarks>
    /// The simple types can also be used as elements of a complex property
    /// by grouping multiple simple property instance in a property set.
    /// </remarks>
    ///
    enum PropertyDataType {
        /// <summary> 
        /// The constant Id for all properties defined by Format Codecs that
        /// are not derived from ZTIL internally defined simple types.
        /// </summary>
        ///
        kCustom = 0, 
        /// <summary>
        /// This is used by a type that encodes no data, only exposing the
        /// string description and name properties defined by 
        /// <c>FormatCodecPropertyInterface</c>.
        /// </summary>
        ///
		kVoid,
        /// <summary>
        /// Indicates the property encodes a boolean value.
        /// </summary>
        ///
        kBoolean,
        /// <summary>
        /// Indicates the property encodes a integer value.
        /// </summary>
        ///
        kInteger,
        /// <summary>
        /// Indicates the property encodes a double floating point value.
        /// </summary>
        ///
        kDouble,
        /// <summary>
        /// Indicates the property encodes a string value.
        /// </summary>
        ///
        kString,
        /// <summary>
        /// Indicates the property is a set of properties where each property
        /// in the set is valid.
        /// </summary>
        ///
        kInclusiveSet,
        /// <summary>
        /// Indicates the property is a set of properties where only one property
        /// in the set is considered "active" at a time. 
        /// </summary>
        ///
        /// <remarks>
        /// The exclusive set is most often used to return a list of choices 
        /// such as compression level or type.
        /// </remarks>
        ///
        kExclusiveSet,
        /// <summary>
        /// Indicates the property encodes a date value.
        /// </summary>
        ///
        kDate,
        /// <summary>
        /// Indicates the property is represented by one of the defined and implemented
        /// ZTIL properties.
        /// </summary>
        ///
        kClass
    };

    /// <summary>
    /// This enum is used to define and describe when a property is used.
    /// </summary>
    ///
	enum PropertyUsage 
    { 
        /// <summary>
        /// The usage is unknown. So assume what you will. 
        /// </summary>
        ///
        kUsageUnknown,
        /// <summary>
        /// The property is a read-only property and can not be modified nor written.
        /// </summary>
        ///
        kReadOnly, 
        /// <summary>
        /// The property is a read and write capable.
        /// </summary>
        ///
        kReadWrite, 
        /// <summary>
        /// The property is only available when a new image is being written.
        /// </summary>
        ///
        kWriteOnly 
    };

    /// <summary>
    /// This enum is used to define and describe how a properties information
    /// applies to an image within a file.
    /// </summary>
    ///
	enum PropertyLevel 
    { 
        /// <summary>
        /// The level is unknown. So assume what you will. 
        /// </summary>
        ///
        kLevelUnknown,
        /// <summary>
        /// The property encodes information regarding the frame or band of an image. 
        /// </summary>
        ///
        kLevelFrame, 
        /// <summary>
        /// The property encodes information regarding the association between two or more
        /// frames or bands within the image. 
        /// </summary>
        ///
        kLevelAssociation, 
        /// <summary>
        /// The property encodes information regarding the image file and is not specific
        /// to any band or frame in the image file. 
        /// </summary>
        ///
        kLevelFile
    };

    /// <summary>
    /// The virtual destructor.
    /// </summary>
    ///
    virtual ~FormatCodecPropertyInterface ();

    /// <summary>
    /// This abstract method is an artificial copy constructor. All properties
    /// that are not trivial (no additional methods or data) derivations or 
    /// instances of ZTIL defined property classes should implement this method.
    /// </summary>
    ///
    /// <returns>
    /// This method returns the new <c>FormatCodecPropertyInterface</c> instance.
    /// </returns>
    ///
    virtual FormatCodecPropertyInterface* clone () const = 0;

    /// <summary>
    /// Query for the <c>PropertyIdentifier</c> of the property.
    /// </summary>
    ///
    /// <returns>
    /// A member of the PropertyIdentifier enum identifying the class.
    /// </returns>
    ///
    virtual PropertyIdentifier getIdentifier () const;

    /// <summary>
    /// Query for the <c>PropertyDataType</c> of the property.
    /// </summary>
    ///
    /// <returns>
    /// A member of the PropertyDataTyoe enum indicating the data type of the class.
    /// </returns>
    ///
    virtual PropertyDataType getDataType () const;

    /// <summary>
    /// Query whether the property is required to be set for writing an image
    /// file to succeed.
    /// </summary>
    ///
    
	/// <returns>
	/// This method returns true on success.
	/// </returns>
	///
	/// <remarks>
    /// Some format codecs require some properties to be set in order to correctly
    /// write out an image. All properties are required/strongly suggested to 
    /// have acceptable defaults such that if a property is queried from the codec
    /// and directly set without modification it will be valid.
    /// </remarks>
    ///
    virtual bool isRequired () const;

    /// <summary>
    /// Query whether the property's value may change depending on the values set
    /// in other properties exposed by the format codec for the current image frame
    /// being written.
    /// </summary>
    ///
	/// <returns>
	/// This method returns true if the property's value depends on the the settings in other properties.
	/// </returns>
	///
    /// <remarks>
    /// Some format codecs may expose properties that have interdependencies. It
    /// would be recommended that such properties be enclosed with a property set.
    /// </remarks>
    ///
	
    virtual bool isContextSensitive () const;

    /// <summary>
    /// This returns the textual description of the property for display
    /// by an application's UI.
    /// </summary>
    ///
    /// <returns>
    /// The method returns a const instance of a StringBuffer class enclosing
    /// the description string.
    /// </returns>
    ///
    virtual const StringBuffer& getDescription () const;

    /// <summary>
    /// This returns the textual name of the property for display
    /// by an application's UI.
    /// </summary>
    ///
    /// <returns>
    /// The method returns a const instance of a StringBuffer class enclosing
    /// the name string.
    /// </returns>
    ///
    virtual const StringBuffer& getName () const;

    /// <summary>
    /// Queries the property for its usage.
    /// </summary>
    ///
    /// <returns>
    /// The value of the PropertyUsage enum describing the property.
    /// </returns>	
    ///
    virtual PropertyUsage getUsage() const;

    /// <summary>
    /// Queries the property for its usage.
    /// </summary>
    ///
    /// <returns>
    /// The value of the PropertyUsage enum describing the property.
    /// </returns>	
    ///
	virtual PropertyLevel getLevel() const;
	
protected:
    /// <summary> 
    /// (Protected) Default constructor.
    /// </summary>
    ///
    FormatCodecPropertyInterface ();

    /// <summary> 
    /// (Protected) Copy constructor.
    /// </summary>
    ///
    /// <param name="from">
    /// A const instance reference to be used to initialize the members of the
    /// new instance.
    /// </param>
    ///
    FormatCodecPropertyInterface (const FormatCodecPropertyInterface& from);

    /// <summary>
    /// (Protected) The <c>PropertyIdentifier</c> identifier to identify the 
    /// object.
    /// </summary>
    ///
    PropertyIdentifier mId;

    /// <summary>
    /// (Protected) The <c>PropertyDataType</c> describing the form of the object instance.
    /// </summary>
    ///
    PropertyDataType mType;

    /// <summary>
    /// (Protected) A boolean value indicating that the object instance is of a
    /// type that is required to be set by the owning codec.
    /// </summary>
    ///
    bool mbRequired;

    /// <summary>
    /// (Protected) A boolean value that indicates that the default value of the
    /// object instance may change based on other data or properties that are set
    /// set into the codec.
    /// </summary>
    ///
    /// <remarks>
    /// An instance of this dependency is often found with the compression property
    /// where the available compression modes vary depending on the data type of the image.
    /// </remarks>
    ///
    bool mbContextSensitive;

    /// <summary>
    /// (Protected) The name of the property.
    /// </summary>
    ///
    StringBuffer msbName;

    /// <summary>
    /// (Protected) The description of the property.
    /// </summary>
    ///
    StringBuffer msbDescription;

    /// <summary>
    /// (Protected) The usage of the property, whether it may be read and or written.
    /// </summary>
    ///
    PropertyUsage mUsage;

    /// <summary>
    /// (Protected) This describes the relationship of the property to the image file
    /// which is open in the codec.
    /// </summary>
    ///
	PropertyLevel mLevel;

    /// <summary>
    /// (Protected) The assignment operator.
    /// </summary>
    ///
    /// <param name="from">
    /// A const reference to an instance.
    /// </param>
    ///
	/// <returns>
	///	A reference to *this.
	/// </returns>	
	///
    /// <remarks>
    /// This method is not implemented. Use the <c>clone</c> method instead.
    /// </remarks>
    ///
    FormatCodecPropertyInterface& operator= (const FormatCodecPropertyInterface& from);  //not implemented
private:
};

} // end of namespace Ztil
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif
#endif
