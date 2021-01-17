#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif

#ifndef ZDATABUFFER_H
#define ZDATABUFFER_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{
/// <summary>
/// DataBuffer binds the size of the contained buffer to the buffer itself. The
/// class is used to pass memory between classes in ZTIL.
/// </summary>
///
/// <remarks>
/// The class wraps an array of bytes and a count of bytes into a class
/// that can describe the buffer it contains. It is used to pass tiles and 
/// rows of data between classes and methods in ZTIL.
/// </remarks>
///
class DllImpExp DataBuffer 
{
public:
    /// <summary>
    /// Defines a shortcut (typedef) for the definition of the buffer.
    /// </summary>
    typedef Byte* DataPtr;

public:
    /// <summary>
    /// The trivial constructor, the class can be completely set after instantiation.
    /// </summary>
    ///
    DataBuffer ();

    /// <summary>
    /// Construct a DataBuffer of a given size. The nBytes argument specifies 
    /// the number of bytes the buffer will hold.
    /// </summary>
    /// 
    /// <param name='nBytes'>
    /// The number of bytes the buffer will hold.
    /// </param>
    ///
    /// <remarks> This constructor can throw an <c>ZTILException</c> instance if the allocation
    /// fails. A message of "Allocation Failure!" is in the class and the thrown object should be
    /// deleted in the catch statement or it will be leaked. If you are allocating something large
    /// like an entire image of static memory, be sure to catch this.</remarks>
    DataBuffer ( int nBytes );

    /// <summary>
    /// The Cloning constructor will allocate and copy the cloned DataBuffer completely.
    /// </summary>
    ///
	/// <param name='other'>
	/// A constant reference to an instance of DataBuffer that is to be copied.
	/// </param>
	/// 
    DataBuffer ( const DataBuffer& other );
    
    /// <summary>
    /// The destructor will deallocate the enclosed buffer.
    /// </summary>
    ///
    virtual ~DataBuffer ();

    /// <summary>
    /// Queries the number of bytes in the buffer.
    /// </summary>
    ///
    /// <returns>
    /// Returns the integer count of bytes allocated in the internal buffer.
    /// </returns>
    ///
    virtual int numBytes () const;

    /// <summary>
    /// Queries for modifiable access to the enclosed buffer.
    /// </summary>
    ///
    /// <returns>
    /// Returns a pointer that may be used to write into the enclosed buffer.
    /// </returns>
    ///
    virtual /*DataPtr*/ unsigned char* dataPtr ();

    /// <summary>
    /// Queries for read-only access to the enclosed buffer.
    /// </summary>
    ///
    /// <returns>
    /// Returns a pointer that may be used to read from the enclosed buffer.
    /// </returns>
    ///
    virtual /*const DataPtr*/ const unsigned char* dataPtr() const;

    /// <summary>
    /// Sets the size of the enclosed buffer.
    /// </summary>
    ///
    /// <param name='nBytes'>
    /// The number of bytes the buffer will hold.
    /// </param>
    ///
    /// <remarks>
    /// This will release any buffer that is currently allocated and allocate
    /// a new buffer of the set size. The data in the buffer is not maintained.
    /// This method can throw an <c>ZTILException</c> instance if the allocation
    /// fails. A message of "Allocation Failure!" is in the class and the thrown object should be
    /// deleted in the catch statement or it will be leaked. If you are allocating something large
    /// like an entire image of static memory, be sure to catch this.</remarks>
     virtual void setSize (int nBytes);

    /// <summary>
    /// The assignment operator will deallocate the current buffer then allocate
    /// and copy the assigned DataBuffer completely.
    /// </summary>
    ///
    /// <param name='rhs'>
    /// The instance of a DataBuffer to be copied.
    /// </param>
    ///
    /// <returns>
    /// Returns an instance of the assigned object.
    /// </returns>
    ///
    virtual DataBuffer& operator= (const DataBuffer& rhs);

protected:
    /// <summary>
    /// (Protected) The size of the internal buffer in bytes.
    /// </summary>
    ///
    int mnBufferBytes;
    /// <summary>
    /// (Protected) The pointer to the internal buffer.
    /// </summary>
    ///
    DataPtr mpBuffer;
};

} // end of namespace Ztil
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif

#ifndef ZDATABUFFER_INL
#include <zDataBuffer.inl>
#endif
