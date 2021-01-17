

#ifndef _ZANavDataArray_h
#define _ZANavDataArray_h

#if _MSC_VER >= 1000
#pragma once
#endif 

#pragma warning(push)
#pragma warning(disable : 4275)
class ANAV_PORT CNavDataArray : public CNavArray<CNavData> {
public:
                CNavDataArray ();
virtual         ~CNavDataArray ();
};
#pragma warning(pop)

#endif
