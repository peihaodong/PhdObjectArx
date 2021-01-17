#ifndef AECMODELER_INC_DARRAY_H
#define AECMODELER_INC_DARRAY_H

#include <stddef.h>
#include "zglobal.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwDarray
{
public:

    ZwDarray             ();
    ZwDarray             (const ZwDarray& da);
    ZwDarray             (int len);
    ZwDarray             (void* ptr);
    ~ZwDarray            ();
    
    ZwDarray& operator  =(const ZwDarray& da);
    
    void*&  operator [](int index);
    void*   operator [](int index) const;
    
    int     add        (void* ptr);
    void    add        (int index, void* ptr);
    void    add        (const ZwDarray& da);
    void    del        (int index);
    int     del        (void* ptr);
    int     merge      (void* ptr);
    int     merge      (const ZwDarray& da);
    int     find       (const void* ptr, int startIndex = 0) const;
    int     contains   (const void* ptr) const;
    void    swap       (int index1, int index2);
    void    intersectWith(const ZwDarray&);
    
    int     length     ();
    int     length     () const;
    
    void    resize     (int len);
    void    init       ();
    void    init       (int len);

    void    fixAfterMemcopy(void* newAddress);
    
private:

    enum { kMinLength = 4 };       // Minimum allocated array length

    void  **mArray;                // Pointer to the array of void pointers 
    int   mAllocLength;            // Length of the allocated array 
    int   mUsedLength;             // Length of the array actually used
    void* mFixedArray[kMinLength]; // A short array of void pointers
    
    void  extendArray(int len);
    int   findLength () const;

}; // class Darray



// Inline methods

#pragma warning(push)
#pragma warning(disable: 4068)
#pragma C-Cover off


inline ZwDarray::ZwDarray() : mAllocLength(0), mUsedLength(0) {}


inline ZwDarray::ZwDarray(int len) : mAllocLength(0), mUsedLength(0)
{ 
    resize(len); 
}


inline ZwDarray::ZwDarray(void* ptr) : mAllocLength(0), mUsedLength(0)
{ 
    resize(1); 
    mArray[0] = ptr; 
    mUsedLength = 1; 
}


inline int ZwDarray::contains(const void* ptr) const 
{ 
    return (find(ptr) != -1); 
}


inline int ZwDarray::length() const 
{
    if ((mUsedLength == 0) || (mArray[mUsedLength - 1] != NULL)) {
    return mUsedLength;    // Fast and easy way used in most cases
    } else {
    return findLength();  // Finding the actual length
    }
}


inline int ZwDarray::length()
{
    if ((mUsedLength != 0) && (mArray[mUsedLength - 1] == NULL)) {
    mUsedLength = findLength();
    }
    return mUsedLength;   
}


inline void ZwDarray::init() { resize(0); }

inline ZwDarray::~ZwDarray()   { init();    }


inline void*& ZwDarray::operator [](int index) 
{
    MASSERT(index >= 0);
    
    if (index >= mUsedLength) {
    mUsedLength = index + 1;
    
    if (index >= mAllocLength)
        extendArray(index + 1);
    }
    
    return mArray[index];
} // []


inline void* ZwDarray::operator [](int index) const
{
    MASSERT(index >= 0);
    
    if (index >= mUsedLength) {
    return NULL;
    } else {
    return mArray[index];
    }
} // []


#pragma C-Cover on
#pragma warning(pop)

AECMODELER_NAMESPACE_END
#endif 





