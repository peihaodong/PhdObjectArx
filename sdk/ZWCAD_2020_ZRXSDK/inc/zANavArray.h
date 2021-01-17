

#ifndef _ZNavArray_h
#define _ZNavArray_h

#pragma once

#include "zadesk.h"
#include "afxtempl.h"       

template <class T>
class CNavArray : public CTypedPtrArray<CObArray, T*> {
public:
                CNavArray ();
virtual         ~CNavArray ();

protected:
virtual T       *NewData ();
public:
        T       *AddData ();
        int     GetCount ();
        T       *GetData (INT_PTR index);
        BOOL    IsIndexValid (INT_PTR index);
        void    RemoveData (INT_PTR index);
        void    RemoveAllData ();
};

template <class T>
CNavArray<T>::CNavArray () :
    CTypedPtrArray<CObArray, T*>()
{
}

template <class T>
CNavArray<T>::~CNavArray ()
{
    RemoveAllData();
}

template <class T>
T    *CNavArray<T>::AddData ()
{
    T    *d = NewData();

    ASSERT(d != NULL);
    if (d != NULL)
        this->Add(d);
    return d;
}

template <class T>
int  CNavArray<T>::GetCount ()
{
    const size_t nCount = GetUpperBound() + 1;
    ASSERT(nCount < 0x1000000);
    return (int)nCount;
}

template <class T>
T    *CNavArray<T>::GetData (INT_PTR index)
{
    T    *d = NULL;

    if (IsIndexValid(index))
        d = GetAt(index);
    return d;
}

template <class T>
BOOL CNavArray<T>::IsIndexValid (INT_PTR index)
{
    return ((index >= 0) && (index <= GetUpperBound()));
}

template <class T>
T    *CNavArray<T>::NewData ()
{
    return new T;
}

template <class T>
void CNavArray<T>::RemoveData (INT_PTR index)
{
    T    *d;

    if (IsIndexValid(index)) {
        d = GetAt(index);
        RemoveAt(index);
        delete d;
    }
}

template <class T>
void CNavArray<T>::RemoveAllData ()
{
    const int  n = this->GetCount();

    for (int i = 0; i < n; i++) {
        T *d = GetAt(i);
        delete d;
    }
    RemoveAll();
#ifdef _ZSOFT_WINDOWS_
	FreeExtra();
#endif
}

#endif
