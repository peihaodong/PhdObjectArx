#ifndef ZFORMATCODECCORRELATION_H
#include "zFormatCodecCorrelation.h"
#endif
#ifndef ZFILESPECIFIER_H
#include "zFileSpecifier.h"
#endif

#ifndef ZFORMATCODECEXTERNALCORRELATION_H
#define ZFORMATCODECEXTERNALCORRELATION_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif


namespace Ztil {

///<summary>This class represents correlation information that 
///is stored in a separate file from the image data. As an interface it
///can be used with other correlation classes.</summary>
///<remarks>An example of an external correlations source is a "World File" such as for tif *.tfw.</remarsK>
class DllImpExp FormatCodecExternalCorrelationInterface
{
public:
    ///<summary>The destructor.</summary>
    virtual ~FormatCodecExternalCorrelationInterface () {}

    ///<summary>This method is an artificial copy constructor. It will
    /// make a complete and accurate copy of the class.</summary>
    ///<returns>This method returns the new <c>FormatCodecExternalCorrelation</c> instance
    /// as a <c>FormatCodecPropertyInterface</c> pointer.</returns>
    virtual FormatCodecPropertyInterface* clone () const = 0;
    
    ///<summary>This queries the full filename and path to the file.</summary>
    ///<param name='fsCorrelation'>This reference receives the full path name to the file.</param>
    virtual void getFileSpecifier (FileSpecifier& fsCorrelation) const = 0;

    ///<summary>This queries the path to the file.</summary>
    ///<param name='fsCorrelationPath'>This reference receives only the path without the name of the file.</param>
    virtual void getFilePath (FileSpecifier& fsCorrelationPath) const = 0;

    ///<summary>This queries the name of the file.</summary>
    ///<param name='sbFileName'>This reference receives only the file name without the path.</param>
    virtual void getFileName (StringBuffer& sbFileName) const = 0;

    ///<summary>This queries the extension of the file name.</summary>
    ///<param name='sbFileExtension'>This reference receives only the file name without the path.</param>
    virtual void getFileExtension (StringBuffer& sbFileExtension) const = 0;

    ///<summary>This sets the name of the file to be written.</summary>
    ///<param name='sbFileName'>This const reference contains the file name to write to.</param>
    virtual void setWriteFileName (const StringBuffer& sbFileName) = 0;

    ///<summary>This sets the path to the directory where the file will be written.</summary>
    ///<param name='fsPath'>This const reference contains the path to the file write to.</param>
    virtual void setWritePath (const FileSpecifier& fsPath) = 0;


    ///<summary>This method causes the file at the set path to be read.</summary>
    ///<remarks>This is much like a "go" method that signals that the information 
    ///to process is present and to start processing.</remarks>
    virtual void readCorrelation () = 0;

    ///<summary>This method causes the file at the set path to be written to.</summary>
    ///<remarks>This is much like a "go" method that signals that the information 
    ///to process is present and to start processing.</remarks>
    virtual void writeCorrelation () = 0;

    ///<summary>This sets orientation information from the image file.</summary>
    ///<param name='ornt'>This is an instance of the <c>Orientation</c> enum which describe the direction of the image axis.</param>
    ///<remarks>Some information in the image files can effect the returns of correlation from the external file.</remarks>
    virtual void setOrientation (Ztil::Orientation ornt) = 0;

    ///<summary>This sets the image size from the image file.</summary>
    ///<param name='rows'>This the positive integer number of rows of data in the image.</param>
    ///<param name='columns'>This the positive integer number of columns of data in the image.</param>
    ///<remarks>Some information in the image files can effect the returns of correlation from the external file.</remarks>
    virtual void setImageDimensions (int rows, int columns) = 0;

    ///<summary>This sets the sample size of data in the image file.</summary>
    ///<param name='nBits'>This the positive integer number of bits that are in a pixel of the image.</param>
    ///<remarks>Some information in the image files can effect the returns of correlation from the external file.</remarks>
    virtual void setImageBitsPerPixel(int nBits) = 0;
};

///<summary>This class represents correlation information that 
///is stored in a separate file from the image data.</summary>
///<remarks>An example of an external correlations source is a "World File" 
///such as for tif *.tfw. This derivation is for convenience and capability.</remarks>
class DllImpExp FormatCodecExternalCorrelation 
    : public FormatCodecCorrelation, public FormatCodecExternalCorrelationInterface
{
public:
    ///<summary>The destructor.</summary>
    virtual ~FormatCodecExternalCorrelation() {}

private:
    void operator= (const FormatCodecExternalCorrelation&);
};
} // end of namespace Ztil
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
