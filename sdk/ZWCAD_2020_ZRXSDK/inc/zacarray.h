

#ifndef _ZCARRAY_H
#define _ZCARRAY_H


#include <memory.h>     
#include <stdlib.h>
#include <algorithm>
#include <type_traits>
#include "zadesk.h"
#include "assert.h"

#ifdef ASSERT
#define ZC_ARRAY_ASSERT ASSERT
#elif defined assert
#define ZC_ARRAY_ASSERT assert
#elif defined _ASSERTE
#define ZC_ARRAY_ASSERT _ASSERTE
#else
#define ZC_ARRAY_ASSERT(T)
#endif

#pragma pack (push, 8)

#define ZCARRAY_GROWTH_THRESHOLD 0x10000
#define AllocatorSelector ZcArrayItemCopierSelector
template <class T> class ZcArrayMemCopyReallocator
{
public:
    static void copyItems(T* pDest, size_t nBufLen, const T * pSource, size_t nCount, bool bMove, bool bSameBuffer)
    {
        ZC_ARRAY_ASSERT((nCount <= nBufLen) && (nCount >= 0 && nCount < 0x40000000));
		ZC_ARRAY_ASSERT(pSource > pDest || (pDest >= pSource + nCount));
		ZC_ARRAY_ASSERT(bMove || !bSameBuffer);
        if (nCount > 0) 
        {
			if (bSameBuffer)
				memmove_s(pDest, nBufLen * sizeof(T), pSource, nCount * sizeof(T));
			else
				memcpy_s(pDest, nBufLen * sizeof(T), pSource, nCount * sizeof(T));
        }
    }
};

template <class T> class ZcArrayObjectCopyReallocator
{
public:
    static void copyItems(T* pDest, size_t nCopyLen, const T * pSource, size_t nCount, bool bMove, bool bSameBuffer)
    {
        ZC_ARRAY_ASSERT((nCount <= nCopyLen) && (nCount >= 0 && nCount < 0x40000000));
		ZC_ARRAY_ASSERT(pSource > pDest || (pDest >= pSource + nCount));
		ZC_ARRAY_ASSERT(bMove || !bSameBuffer);
        while(nCount--)
        {
            *pDest = *pSource;
			pDest++;
            pSource++;
        }
    }
};

template<typename T, bool>
struct ZcArrayItemCopierSelector;

template<typename T>
struct ZcArrayItemCopierSelector<T, false>
{
    typedef ZcArrayObjectCopyReallocator<T> allocator;
};

template<typename T>
struct ZcArrayItemCopierSelector<T, true>
{
    typedef ZcArrayMemCopyReallocator<T> allocator;
};


template <typename T, typename R = typename ZcArrayItemCopierSelector<T, std::tr1::is_pod<T>::value>::allocator  > class ZcArray
{
public:
    ZcArray(int initPhysicalLength = 0, int initGrowLength = 8);
    ZcArray(const ZcArray<T,R>&);
	ZcArray(ZcArray<T,R>&&);
    ~ZcArray();

	typedef R Allocator;
	enum 
	{
		eUsesMemCopy = std::is_same<R, ZcArrayMemCopyReallocator<T>>::value
	};

    ZcArray<T,R>&         operator =  (const ZcArray<T,R>&);
	ZcArray<T,R>&         operator =  (ZcArray<T,R>&&);
    bool                operator == (const ZcArray<T,R>&) const;

    T&                  operator [] (int);
    const T &           operator [] (int) const;
    const T &             at          (int index) const;
          T &             at          (int index);
    ZcArray<T,R>&         setAt       (int index, const T& value);
    ZcArray<T,R>&         setAll      (const T& value);
    T&                  first       ();
    const T &           first       () const;
    T&                  last        ();
    const T &           last        () const;

    int                 append      (const T& value);
    ZcArray<T,R>&         append      (const ZcArray<T,R>& array);
    ZcArray<T,R>&         insertAt    (int index, const T& value);

    ZcArray<T,R>&         removeAt    (int index);
    bool                  remove      (const T& value, int start = 0);
    ZcArray<T,R>&         removeFirst ();
    ZcArray<T,R>&         removeLast  ();
    ZcArray<T,R>&         removeAll   ();
    ZcArray<T,R>&         removeSubArray (int startIndex, int endIndex);

    bool                contains    (const T& value, int start = 0) const;
    bool                find        (const T& value, int& foundAt,
                                     int start = 0) const;
	int                 find        (const T& value) const;
	int                 findFrom    (const T& value, int start) const;

    int                 length      () const; 
    bool                isEmpty     () const;
    int                 logicalLength() const;
    ZcArray<T,R>&         setLogicalLength(int);
    int                 physicalLength() const;
    ZcArray<T,R>&         setPhysicalLength(int);

    int                 growLength  () const;
    ZcArray<T,R>&         setGrowLength(int);

    ZcArray<T,R>&         reverse     ();
    ZcArray<T,R>&         swap        (int i1, int i2);

    const T*            asArrayPtr  () const;
    T*                  asArrayPtr  ();

	T* begin()				{ return mpArray; }
	T* end()				{ return mpArray + mLogicalLen; }

	const T* begin() const	{ return mpArray; }
	const T* end() const	{ return mpArray + mLogicalLen; }
protected:
    T*                  mpArray;
    int                 mPhysicalLen;
    int                 mLogicalLen;
    int                 mGrowLen;   

	bool                allocPhysBuf();
	bool                deletePhysBuf(T *pBuf, size_t nCount);
    bool                isValid     (int) const;
};

#pragma pack (pop)

#ifdef GE_LOCATED_NEW
#include "zgegblnew.h"
#endif

#pragma pack (push, 8)

template <class T, class R> inline bool
ZcArray<T,R>::contains(const T& value, int start) const
{ return this->findFrom(value, start) != -1; }

template <class T, class R> inline int
ZcArray<T,R>::length() const
{ return mLogicalLen; }

template <class T, class R> inline bool
ZcArray<T,R>::isEmpty() const
{ return mLogicalLen == 0; }

template <class T, class R> inline int
ZcArray<T,R>::logicalLength() const
{ return mLogicalLen; }

template <class T, class R> inline int
ZcArray<T,R>::physicalLength() const
{ return mPhysicalLen; }

template <class T, class R> inline int
ZcArray<T,R>::growLength() const
{ return mGrowLen; }

template <class T, class R> inline const T*
ZcArray<T,R>::asArrayPtr() const
{ return mpArray; }

template <class T, class R> inline T*
ZcArray<T,R>::asArrayPtr()
{ return mpArray; }

template <class T, class R> inline bool
ZcArray<T,R>::isValid(int i) const
{ return i >= 0 && i < mLogicalLen; }

template <class T, class R> inline T&
ZcArray<T,R>::operator [] (int i)
{ ZC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i]; }

template <class T, class R> inline const T&
ZcArray<T,R>::operator [] (int i) const
{ ZC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i]; }

template <class T, class R> inline T&
ZcArray<T,R>::at(int i)
{ ZC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i]; }

template <class T, class R> inline const T&
ZcArray<T,R>::at(int i) const
{ ZC_ARRAY_ASSERT(this->isValid(i)); return mpArray[i]; }

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::setAt(int i, const T& value)
{ ZC_ARRAY_ASSERT(this->isValid(i)); mpArray[i] = value; return *this; }

template <class T, class R> inline T&
ZcArray<T,R>::first()
{ ZC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[0]; }

template <class T, class R> inline const T&
ZcArray<T,R>::first() const
{ ZC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[0]; }

template <class T, class R> inline T&
ZcArray<T,R>::last()
{ ZC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[mLogicalLen-1]; }

template <class T, class R> inline const T&
ZcArray<T,R>::last() const
{ ZC_ARRAY_ASSERT(!this->isEmpty()); return mpArray[mLogicalLen-1]; }

template <class T, class R> inline int
ZcArray<T,R>::append(const T& value)
{ insertAt(mLogicalLen, value); return mLogicalLen-1; }

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::removeFirst()
{ ZC_ARRAY_ASSERT(!isEmpty()); return removeAt(0); }

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::removeLast()
{
    ZC_ARRAY_ASSERT(!isEmpty());
    if (!isEmpty())
        mLogicalLen--;
    return *this;
}

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::removeAll()
{ this->setLogicalLength(0); return *this; }

template <class T, class R> inline ZcArray<T,R>&
ZcArray<T,R>::setGrowLength(int glen)
{ ZC_ARRAY_ASSERT(glen > 0); mGrowLen = glen; return *this; }
#define lowMemBail() ZC_ARRAY_ASSERT(false)

template < class T, class R >
ZcArray< T, R > ::ZcArray(int physicalLength, int growLength)
: mpArray(nullptr),
  mPhysicalLen(physicalLength),
  mLogicalLen(0),
  mGrowLen(growLength)
{
    ZC_ARRAY_ASSERT(mGrowLen > 0);
    ZC_ARRAY_ASSERT(mPhysicalLen >= 0);
    if (mPhysicalLen > 0) 
	{
		this->allocPhysBuf();
    }
}

template <class T, class R>
ZcArray<T,R>::ZcArray(const ZcArray<T,R>& src)
: mpArray(nullptr),
  mPhysicalLen(src.mPhysicalLen),
  mLogicalLen(src.mLogicalLen),
  mGrowLen(src.mGrowLen)
{
	ZC_ARRAY_ASSERT(mPhysicalLen >= mLogicalLen);
	if (mLogicalLen <= 0) 
	{
		ZC_ARRAY_ASSERT(0 == mLogicalLen);
		mPhysicalLen = 0;
	}
	if (mPhysicalLen <= 0) 
	{
		ZC_ARRAY_ASSERT((0 == mPhysicalLen) && (0 == mLogicalLen));
	}
	else 
	{
		ZC_ARRAY_ASSERT(mLogicalLen > 0);
		if (this->allocPhysBuf())
			R::copyItems(mpArray, mPhysicalLen, src.mpArray, mLogicalLen, false, false);
	}
}

template <class T, class R>
ZcArray<T,R>::ZcArray(ZcArray<T,R>&& src)
 : mpArray(src.mpArray),
 mPhysicalLen(src.mPhysicalLen),
 mLogicalLen(src.mLogicalLen),
 mGrowLen(src.mGrowLen)
{
	src.mpArray = nullptr;
	src.mPhysicalLen = 0;
	src.mLogicalLen = 0;
	src.mGrowLen = 8;
}

template <class T, class R>
ZcArray<T,R>::~ZcArray()
{
	this->deletePhysBuf(mpArray, mPhysicalLen);
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::operator = (const ZcArray<T,R>& src)
{
    if (this != &src) {
        if(src.mLogicalLen <= 0)
		{
			ZC_ARRAY_ASSERT(src.mLogicalLen == 0);
			mLogicalLen = 0;
		}
		else
		{
			if (mPhysicalLen < src.mLogicalLen) 
			{
				if (mpArray != nullptr)
				{
					deletePhysBuf(mpArray, mPhysicalLen);
					mpArray = nullptr;
				}
				mPhysicalLen = src.mLogicalLen;
				if (!this->allocPhysBuf())
					return *this;
			}
			mLogicalLen = src.mLogicalLen;
			ZC_ARRAY_ASSERT((mLogicalLen > 0) && (mPhysicalLen >= mLogicalLen));
			R::copyItems(mpArray, mPhysicalLen, src.mpArray, mLogicalLen, false, false);
		}
    }
    return *this;
}

template <class T, class R> 
ZcArray<T,R>& ZcArray<T,R>::operator = (ZcArray<T,R>&& src)
{
	if (this != &src) 
	{
		mPhysicalLen = src.mPhysicalLen;
		mpArray = src.mpArray;
		mLogicalLen = src.mLogicalLen;
		mGrowLen = src.mGrowLen;
		src.mpArray = nullptr;
		src.mPhysicalLen = 0;
		src.mLogicalLen = 0;
		src.mGrowLen = 8;
	}
	return *this;
}

template <class T, class R> bool
ZcArray<T,R>::operator == (const ZcArray<T,R>& cpr) const
{
    if (mLogicalLen == cpr.mLogicalLen) {
        for (int i = 0; i < mLogicalLen; i++)
            if (mpArray[i] != cpr.mpArray[i])
                return false;
        return true;
    }
    return false;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::setAll(const T& value)
{
    for (int i = 0; i < mLogicalLen; i++) {
        mpArray[i] = value;
    }
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::append(const ZcArray<T,R>& otherArray)
{
    const int otherLen = otherArray.length();
    if (otherLen == 0) {
        return *this;
    }
    int newLen = mLogicalLen + otherLen;
    if (newLen > mPhysicalLen) {
        setPhysicalLength(mLogicalLen + std::max<int>(otherLen, mGrowLen));
    }

    R::copyItems(mpArray + mLogicalLen, (mPhysicalLen - mLogicalLen), otherArray.mpArray, otherLen, false, false);
    
    mLogicalLen = newLen;
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::insertAt(int index, const T& value)
{
    ZC_ARRAY_ASSERT(index >= 0 && index <= mLogicalLen);
	if (index < 0 || index > mLogicalLen)
		return *this;
    const T  tmp(value);
    if (mLogicalLen >= mPhysicalLen) {
		ZC_ARRAY_ASSERT(mLogicalLen == mPhysicalLen);
        int growth = (mLogicalLen * sizeof(T)) < ZCARRAY_GROWTH_THRESHOLD ?
            mLogicalLen : ZCARRAY_GROWTH_THRESHOLD / sizeof(T);
        setPhysicalLength(mLogicalLen + std::max<int>(growth, mGrowLen));
    }

    if (index != mLogicalLen) {
        ZC_ARRAY_ASSERT(mLogicalLen >= 0);
        T* p = mpArray + mLogicalLen;
        T* pStop = mpArray + index;
        do {
            *p = *(p-1);
        } while (--p != pStop);
    }
    mpArray[index] = tmp;
    mLogicalLen++;
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::removeAt(int index)
{
    ZC_ARRAY_ASSERT(isValid(index));
	ZC_ARRAY_ASSERT(mLogicalLen <= mPhysicalLen);
	ZC_ARRAY_ASSERT(!isEmpty());
	if (isEmpty() || !isValid(index))
		return *this;
    if (index < mLogicalLen - 1) {
		R::copyItems(mpArray + index, mPhysicalLen - index,	mpArray + index + 1, mLogicalLen - 1 - index, true, true);
    }
    mLogicalLen--;
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::removeSubArray(int startIndex, int endIndex)
{
    ZC_ARRAY_ASSERT(isValid(startIndex));
    ZC_ARRAY_ASSERT(startIndex <= endIndex);

    if ( endIndex >= mLogicalLen - 1) {
        mLogicalLen = startIndex;
        return *this;
    }

	const int kNumToRemove = endIndex + 1 - startIndex;
	const int kNumToShift = mLogicalLen - 1 - endIndex;
	ZC_ARRAY_ASSERT(kNumToShift >= 1);
	R::copyItems(mpArray + startIndex, mPhysicalLen - startIndex, mpArray + endIndex + 1, kNumToShift, true, true);
	mLogicalLen -= kNumToRemove;
    return *this;
}

template <class T, class R> bool
ZcArray<T,R>::find(const T& value, int& index, int start) const
{
    const int nFoundAt = this->findFrom(value, start);
    if (nFoundAt == -1)
        return false;
    index = nFoundAt;
    return true;
}

template <class T, class R> int
ZcArray<T,R>::find(const T& value) const
{
	return this->findFrom(value, 0);   
}

template <class T, class R> int
ZcArray<T,R>::findFrom(const T& value, int start) const
{
	ZC_ARRAY_ASSERT(start >= 0);
	if (start < 0)
		return -1;
	for (int i = start; i < this->mLogicalLen; i++) {
		if (mpArray[i] == value)
			return i;
	}
	return -1;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::setLogicalLength(int n)
{
    ZC_ARRAY_ASSERT(n >= 0);
	if (n < 0)
		n = 0;
	ZC_ARRAY_ASSERT(n < 0x40000000); 
    if (n > mPhysicalLen) {

        const int growth = (mPhysicalLen * sizeof(T)) < ZCARRAY_GROWTH_THRESHOLD ?
            mPhysicalLen : ZCARRAY_GROWTH_THRESHOLD / sizeof(T);

        int minSize = mPhysicalLen + std::max<int>(growth, mGrowLen);
        if ( n > minSize)
            minSize = n;
        setPhysicalLength(minSize);
    }
    mLogicalLen = n;
	ZC_ARRAY_ASSERT(mLogicalLen <= mPhysicalLen);
    return *this;
}

template <class T, class R> 
bool ZcArray<T,R>::allocPhysBuf()
{
	ZC_ARRAY_ASSERT(mPhysicalLen > 0);
	ZC_ARRAY_ASSERT(mpArray == nullptr);
#ifdef GE_LOCATED_NEW
	mpArray = GENEWLOCVEC(T, mPhysicalLen, this) ();
#else
	mpArray = new T[mPhysicalLen];
#endif
	ZC_ARRAY_ASSERT(mpArray != nullptr);
	if (mpArray == nullptr) 
	{
		mPhysicalLen = 0;
		mLogicalLen = 0;
		return false;
	}
	return true;
}

template <class T, class R> bool
ZcArray<T,R>::deletePhysBuf(T* pBuf, size_t nCount)
{
	if (pBuf == nullptr) 
	{
		ZC_ARRAY_ASSERT(nCount == 0);
	}
	else 
	{
		ZC_ARRAY_ASSERT(nCount > 0);
		delete[] pBuf;
	}
	return true;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::setPhysicalLength(int n)
{
	ZC_ARRAY_ASSERT(n >= 0 && n < 0x40000000);
	if (n == mPhysicalLen || n < 0)
		return *this;

	ZC_ARRAY_ASSERT((mPhysicalLen >= mLogicalLen) && (mPhysicalLen == 0) == (mpArray == nullptr));
	T* pOldArray = mpArray;
	const size_t nOldLen = mPhysicalLen;

	mPhysicalLen = n;
	mpArray = nullptr;
	if (mPhysicalLen < mLogicalLen)
		mLogicalLen = mPhysicalLen;
	if ((mPhysicalLen != 0) && this->allocPhysBuf())
		R::copyItems(mpArray, mPhysicalLen, pOldArray, mLogicalLen,	true, false);
	deletePhysBuf(pOldArray, nOldLen);
	return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::reverse()
{
    for (int i = 0; i < mLogicalLen/2; i++) {
        const T tmp = mpArray[i];
        mpArray[i] = mpArray[mLogicalLen - 1 - i];
        mpArray[mLogicalLen - 1 - i] = tmp;
    }
    return *this;
}

template <class T, class R> ZcArray<T,R>&
ZcArray<T,R>::swap(int i1, int i2)
{
    ZC_ARRAY_ASSERT(isValid(i1));
    ZC_ARRAY_ASSERT(isValid(i2));

    if (i1 == i2) return *this;

    const T tmp = mpArray[i1];
    mpArray[i1] = mpArray[i2];
    mpArray[i2] = tmp;
    return *this;
}

template <class T, class R> bool
ZcArray<T,R>::remove(const T& value, int start)
{
    const int i = this->findFrom(value, start);
    if (i == -1)
        return false;
    this->removeAt(i);
    return true;
}

#include "zacarrayhelper.h"

#pragma pack (pop)
#endif
