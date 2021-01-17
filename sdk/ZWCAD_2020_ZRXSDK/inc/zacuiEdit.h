

#ifndef _zcuiEdit_h
#define _zcuiEdit_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

#define ZC_ES_STRING                        0x01	
#define	ZC_ES_SYMBOL                        0x02
#define ZC_ES_NUMERIC                       0x04
#define ZC_ES_ANGLE                         0x08

#define ZC_ES_VAL_ONKILLFOCUS               0x10
#define ZC_ES_CONV_ONKILLFOCUS              0x20
#define ZC_ES_SHOW_ERRMSG                   0x40
#define ZC_ES_ERRMSG_ALLOWIGNORE            0x80

#define ZC_ES_NOZERO                        0x100
#define ZC_ES_NOBLANK                       0x200	
#define ZC_ES_NONEGATIVE                    0x400
#define	ZC_ES_INRANGE                       0x800

typedef enum {
    kZcUiError_None,                    
    kZcUiError_Blank,                   
    kZcUiError_Symbol,                  
    kZcUiError_Numeric,                 
    kZcUiError_Angle,                   
    kZcUiError_Zero,                    
    kZcUiError_Negative,                
    kZcUiError_Range                    
} ZCUI_ERROR_CODE;

class ZCUI_PORT CZcUiEdit : public CZdUiEdit {
    DECLARE_DYNAMIC(CZcUiEdit)

public:
                CZcUiEdit ();
virtual         ~CZcUiEdit ();

private:
        BOOL    m_bWantsFocus;
        BOOL    m_bWasValid;

protected:
virtual ZDUI_REPLY DoZdUiMessage (
                    ZDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
                );

public:
virtual void    SetStyleMask (DWORD mask);

private:
        void    DisplayError (UINT);    
public:
        BOOL    m_bChanged;             
        double  m_dMinValue;           
        double  m_dMaxValue;           
        CString m_csMsg;                
        BOOL    m_bTouch;               

        void    Convert ();             
        BOOL    ConvertData (CString& x);
        BOOL    HasChanged ();          
        void    SetDirty ();
        void    SetRange (double vMin, double vMax);
        BOOL    Validate ();			
        ZCUI_ERROR_CODE ValidateData (CString& x);

public:

protected:
	
	afx_msg BOOL OnChange();
    afx_msg void OnErrSpace();
    afx_msg void OnKillFocus(CWnd* pNewWnd);

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiAngleEdit : public CZcUiEdit {
    DECLARE_DYNAMIC(CZcUiAngleEdit)

public:
                CZcUiAngleEdit ();
virtual         ~CZcUiAngleEdit ();

public:
virtual void    SetStyleMask (DWORD mask);

public:

protected:

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiNumericEdit : public CZcUiEdit {
    DECLARE_DYNAMIC(CZcUiNumericEdit)

public:
                CZcUiNumericEdit ();
virtual         ~CZcUiNumericEdit ();

public:
virtual void    SetStyleMask (DWORD mask);

public:

protected:

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiStringEdit : public CZcUiEdit {
    DECLARE_DYNAMIC(CZcUiStringEdit)

public:
	            CZcUiStringEdit ();
virtual         ~CZcUiStringEdit ();

public:
virtual void    SetStyleMask (DWORD mask);

public:

protected:

	DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiSymbolEdit : public CZcUiEdit {
    DECLARE_DYNAMIC(CZcUiSymbolEdit)

public:
                CZcUiSymbolEdit ();
virtual         ~CZcUiSymbolEdit ();

public:
virtual void    SetStyleMask (DWORD mask);

public:

protected:

	DECLARE_MESSAGE_MAP()
};

#pragma pack (pop)
#endif


