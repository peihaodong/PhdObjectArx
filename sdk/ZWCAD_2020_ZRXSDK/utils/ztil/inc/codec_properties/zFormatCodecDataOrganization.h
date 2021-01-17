#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif
#ifndef ZFORMATCODECEXCLUSIVEPROPERTYSETINTERFACE_H
#include "zFormatCodecExclusivePropertySetInterface.h"
#endif

#ifndef ZFORMATCODECDATAORGANIZATION_H
#define ZFORMATCODECDATAORGANIZATION_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{
///<summary>This property describes how the image data is stored in the file. </summary>
///<remarks>Most image file formats store data only one way and so do not 
///need this property. Some formats such as TIFF offer multiple options for 
///encoding the data and this property can be used to let applications set the one 
///they want to use. </remarks>
class DllImpExp FormatCodecDataOrganization : public FormatCodecPropertyInterface
{
public:
    ///<summary>Enum declaring the possible data organizations</summary>
    enum Organization { 
        ///<summary>Data is stored as one large rectangle of pixels. Most common.</summar>
        kMonolithic, 
        ///<summary>Data is stored as an array of square tiles of pixels.</summary>
        kTiled, 
        ///<summary>Data is stored in a series of image wide bands of data.</summary>
        kStripped 
    };
    ///<summary>Enum declaring the shape of tiles for tiled images.</summary>
    enum TileGeometry { 
        ///<summary>The tiles are stored as squares. This is most common.</summary>
        kSquare, 
        ///<summary>The tiles are stored with differing row and column sizes.</summary>
        kRectangle 
    };

public:
    ///<summary>The Destructor.</summary>
    virtual ~FormatCodecDataOrganization ();

    ///<summary> The clone method makes a complete copy of any subclassed object.</summary>
    ///<returns> This returns the cloned <c>FormatCodecDataOrganization</c> subclass.</returns>
    virtual FormatCodecPropertyInterface* clone () const;

    ///<summary> Queries the organization of the data. </summary>
    ///<returns> Returns the enum entry that describes the organization of the data.</returns>
    virtual Organization getOrganization () const;

    ///<summary> Set the desired organization when writing out image data to a file.</summary>
    ///<param name='organization'> An enum instance describing the desired organization of the image data. </param>
    ///<returns> This will return true if the organization is available and successfully selected.</returns>
    virtual bool setOrganization ( Organization organization );

    ///<summary> Queries the dimensions of tiles in the image file.</summary>
    ///<param name='nWidth'> A reference to an integer to receive the width of a tile in pixels.</param>
    ///<param name='nHeight'> A reference to an integer to receive the height of a tile in pixels.</param>
    ///<returns>This will return true if the organization of data in the file is tiles.</returns>
    virtual bool  getTileDimensions ( int& nWidth, int& nHeight );

    ///<summary> This sets the dimensions of tiles in the image file when writing.</summary>
    ///<param name='nWidth'> An integer to set as the width of a tile in pixels.</param>
    ///<param name='nHeight'> An integer to set as the height of a tile in pixels.</param>
    ///<returns>This will return true if successful.</returns>
    virtual bool setTileDimensions ( int nWidth, int nHeight );

    ///<summary> Queries the number of rows in a strip of data in the image file.</summary>
    ///<param name='nRowsPerStrip'> A reference to an integer to receive the height of strip in rows.</param>
    ///<returns> This will return true if the image data is organized as strips.</returns>
    virtual bool getRowsPerStrip ( int& nRowsPerStrip );

    ///<summary> Sets the number of rows to be in a strip of data in the image file.</summary>
    ///<param name='nRowsPerStrip'> An integer to number of rows for the strip.</param>
    ///<returns> This will return true if successful.</returns>
    virtual bool setRowsPerStrip ( int nRowsPerStrip );

protected:

    ///<summary>Constructor with preset organization.</summary>
    FormatCodecDataOrganization ( Organization org );

    ///<summary> This sets the default dimensions of tiles in the image file when writing.</summary>
    ///<param name='nWidth'> An integer to set as the default width of a tile in pixels.</param>
    ///<param name='nHeight'> An integer to set as the default height of a tile in pixels.</param>
    void setDefaultTileDimensions ( int nWidth, int nHeight );
    
    ///<summary> Sets the default number of rows to be in a strip of data in the image file.</summary>
    ///<param name='nRowsPerStrip'> An integer to number of rows for the strip.</param>
    void setDefaultRowsPerStrip ( int nRowsPerStrip );

    ///<summary> The set width of a tile.</summary>
    int mnTileWidth;
    ///<summary> The default width of a tile.</summary>
    int mnDefaultTileWidth;
    ///<summary> The set height of a tile.</summary>
    int mnTileHeight;
    ///<summary> The default height of a tile.</summary>
    int mnDefaultTileHeight;
    ///<summary> The set number of rows in a strip.</summary>
    int mnRowsPerStrip;
    ///<summary> The default number of rows in a strip.</summary>
    int mnDefaultRowsPerStrip;

    ///<summary> The default organization of the image file.</summary>
    Organization mOrgDefault;
    ///<summary> The set organization of the data in the image file.</summary>
    Organization mOrganization;
};

} // end of namespace Ztil
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif

