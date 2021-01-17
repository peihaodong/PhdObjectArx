

#ifndef _zcuiButton_h
#define _zcuiButton_h

#if _MSC_VER >= 1000
#pragma once
#endif 

class ZCUI_PORT CZcUiOwnerDrawButton : public CZdUiOwnerDrawButton {
	DECLARE_DYNAMIC(CZcUiOwnerDrawButton)

public:
	            CZcUiOwnerDrawButton ();
virtual         ~CZcUiOwnerDrawButton ();

public:

protected:

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiBitmapButton : public CZdUiBitmapButton {
	DECLARE_DYNAMIC(CZcUiBitmapButton)

public:
	            CZcUiBitmapButton ();
virtual         ~CZcUiBitmapButton ();

public:

protected:

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiBitmapStatic : public CZdUiBitmapStatic {
	DECLARE_DYNAMIC(CZcUiBitmapStatic)

public:
	            CZcUiBitmapStatic ();
virtual         ~CZcUiBitmapStatic ();

public:

protected:

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiDropSite : public CZdUiDropSite {
	DECLARE_DYNAMIC(CZcUiDropSite)

public:
	            CZcUiDropSite ();
virtual         ~CZcUiDropSite ();

public:

protected:

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiPickButton : public CZdUiBitmapButton {
	DECLARE_DYNAMIC(CZcUiPickButton)

public:
	            CZcUiPickButton ();
virtual         ~CZcUiPickButton ();

protected:
virtual BOOL    OnLoadBitmap (LPCTSTR strResId);

public:

protected:

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiSelectButton : public CZcUiPickButton {
	DECLARE_DYNAMIC(CZcUiSelectButton)

public:
	            CZcUiSelectButton ();
virtual         ~CZcUiSelectButton ();

public:

protected:

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiToolButton : public CZdUiToolButton {
	DECLARE_DYNAMIC(CZcUiToolButton)

public:
	            CZcUiToolButton ();
virtual         ~CZcUiToolButton ();

public:

protected:

	DECLARE_MESSAGE_MAP()
};

#endif


