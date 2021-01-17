

#ifndef _ZANavListCtrl_h
#define _ZANavListCtrl_h

#pragma once

class  CNavListCtrl;

class CNavDropSource : public COleDropSource
{
public:
    CNavDropSource();       

    CNavListCtrl* m_pListCtrl;

    SCODE GiveFeedback(DROPEFFECT dropEffect);
};

class ANAV_PORT CNavListCtrl : public CZdUiListCtrl {
public:
    CNavListCtrl ();

public:

protected:
    
    afx_msg void OnBeginDrag(NMHDR* pNMHDR, LRESULT* pResult);
    
    afx_msg LRESULT OnHandleDrag(UINT_PTR pDataSource, LPARAM nSelectedItem);
    DECLARE_MESSAGE_MAP()

    CImageList* m_pDragImage;
    CNavDropSource m_dropSource;

};

#endif 
