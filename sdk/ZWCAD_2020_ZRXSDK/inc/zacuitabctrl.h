

#ifndef _zcuiTabCtrl_h
#define _zcuiTabCtrl_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

class ZCUI_PORT CZcUiTab : public CZdUiTab {
    DECLARE_DYNAMIC(CZcUiTab);

public:
	            CZcUiTab ();
virtual         ~CZcUiTab ();

public:

protected:

    DECLARE_MESSAGE_MAP()
};

#pragma pack (pop)
#endif


