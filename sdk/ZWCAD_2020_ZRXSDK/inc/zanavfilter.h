

#ifndef _ZANavFilter_h
#define _ZANavFilter_h

#pragma once

#pragma warning(push)
#pragma warning(disable : 4275)
class ANAV_PORT CNavFilter : public CStringArray {
public:

                CNavFilter ();
virtual         ~CNavFilter ();

private:

        BOOL    m_bFullDescription;  

protected:

        CString m_description;

        INT_PTR m_tagIndex;

public:

        LPCTSTR GetDescription ();                  
        void    SetDescription (LPCTSTR desc);      
        void    GetFullDescription (CString& desc); 
        void    SetFullDescription (LPCTSTR desc);  
        INT_PTR GetTagIndex ();
        void    SetTagIndex (INT_PTR tagIndex);

        int     Find (LPCTSTR str);

        int     GetCount ();

        BOOL    IsAllowed (LPCTSTR fileName);

        LPTSTR SetFrom (LPTSTR str, BOOL bUseFullDescrition = FALSE);        
};
#pragma warning(pop)

#endif
