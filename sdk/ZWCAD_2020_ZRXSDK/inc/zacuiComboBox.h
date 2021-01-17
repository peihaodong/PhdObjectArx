

#ifndef _zcuiComboBox_h
#define _zcuiComboBox_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

#pragma push_macro("_USE_ANSI_CPP")
#define _USE_ANSI_CPP
#include <map>
#pragma pop_macro("_USE_ANSI_CPP")
typedef std::map<int, ZcCmColor*>   ZcCmColorTable;

class CZdUiImage;
class ZCUI_PORT CZcUiComboBox : public CZdUiComboBox {
    DECLARE_DYNAMIC(CZcUiComboBox);

public:
                CZcUiComboBox ();
virtual         ~CZcUiComboBox ();

public:
        CZcUiEdit *ZcUiEditBox ();
        BOOL    Validate ();
        ZCUI_ERROR_CODE ValidateData (CString& x);
        void    Convert ();
        BOOL    ConvertData (CString& x);
        void    SetRange (double vMin, double vMax);

public:

protected:

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiAngleComboBox : public CZcUiComboBox {
    DECLARE_DYNAMIC(CZcUiAngleComboBox);

public:
                CZcUiAngleComboBox ();
virtual         ~CZcUiAngleComboBox ();

public:

protected:

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiNumericComboBox : public CZcUiComboBox {
    DECLARE_DYNAMIC(CZcUiNumericComboBox);

public:
                CZcUiNumericComboBox ();
virtual         ~CZcUiNumericComboBox ();

public:

protected:

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiStringComboBox : public CZcUiComboBox {
    DECLARE_DYNAMIC(CZcUiStringComboBox);

public:
                CZcUiStringComboBox ();
virtual         ~CZcUiStringComboBox ();

public:

protected:

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiSymbolComboBox : public CZcUiComboBox {
    DECLARE_DYNAMIC(CZcUiSymbolComboBox);

public:
                CZcUiSymbolComboBox ();
virtual         ~CZcUiSymbolComboBox ();

public:

protected:

    DECLARE_MESSAGE_MAP()
};

#define ZCUI_MAX_COMBOBOX_MRU   6
#define ZCUI_MAX_TRUECOLOR_COMBOBOX_MRU   16

class ZCUI_PORT CZcUiMRUComboBox;
class ZCUI_PORT CZcUiMRUListBox;

typedef enum {
    kZcUiMRUCargo_Last = -106,
    kZcUiMRUCargo_Option2 = -105,
    kZcUiMRUCargo_Option1 = -104,
    kZcUiMRUCargo_Other2 = -103,
    kZcUiMRUCargo_Other1 = -102,
    kZcUiMRUCargo_None = -101
} ZCUI_MRU_CARGO;

class ZCUI_PORT CZcUiMRUListBox : public CZcUiListBox {
public:
                CZcUiMRUListBox ();
virtual         ~CZcUiMRUListBox ();

public:
virtual void    GetContentExtent (
                    int item, LPCTSTR text, int& width, int& height
                );

protected:
virtual BOOL    OnGetTipRect (CRect& r);

protected:
        int     ExtraWidth ();
        CZcUiMRUComboBox *MRUComboBox ();

public:

protected:

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiMRUComboBox : public CZcUiComboBox {
public:
                CZcUiMRUComboBox ();
virtual         ~CZcUiMRUComboBox ();

virtual void    GetContentExtent (LPCTSTR text, int& width, int& height);
virtual BOOL    GetItemColors(DRAWITEMSTRUCT& dis, COLORREF& fgColor, 
                              COLORREF& bgColor, COLORREF& fillColor);

protected:
virtual BOOL    OnGetTipRect (CRect& r);

protected:
        BOOL    m_bIsDynamicCreation : 1;   
        BOOL    m_bUseOption1       : 1;
        BOOL    m_bUseOption2       : 1;
        BOOL    m_bUseOther1        : 1;
        BOOL    m_bUseOther2        : 1;
        BOOL    m_bOther1Selected   : 1;
        BOOL    m_bOther2Selected   : 1;
        int     m_cargoOption1;
        int     m_cargoOption2;
        LOGPALETTE* m_logPalette;
        HPALETTE m_hPalette;
        CPalette* m_pOldPalette;
        int     m_itemHeight;
        int     m_lastSelection;
        int     m_mruCargo[ZCUI_MAX_COMBOBOX_MRU];
        int     m_mruLen;
        CString m_mruName[ZCUI_MAX_COMBOBOX_MRU];

virtual int     CalcItemHeight ();
virtual void    DrawItemImage (CDC& dc, CRect& r, INT_PTR cargo);
        void    DrawItemImageFromCargo(CDC* dc, CRect& r, int i);
        void    DrawTextAndFocusRect(LPDRAWITEMSTRUCT lpDrawItemStruct,
                                     CDC* dc,
                                     CRect& rItem,
                                     int i,
                                     COLORREF& fgColor,
                                     COLORREF& bgColor);
        void    CreateAndSelectPalette (LPDRAWITEMSTRUCT lpDrawItemStruct,
                                        CDC* dc);
        void    SetupForImageDraw(LPDRAWITEMSTRUCT lpDrawItemStruct,
                                  CDC* dc,
                                  CRect& rItem,
                                  CRect& rImage,
                                  COLORREF& fgColor,
                                  COLORREF& bgColor);
        void    ResetAndRestorePalette(CDC* dc, int savedState);

        BOOL    FindCargoInMRU (int cargo);
        int     GenerateCargoFromMRU (int seed);
virtual BOOL    GetOptionName (BOOL isOption2, CString& name);
virtual BOOL    GetOtherName (BOOL isOther2, CString& name);
virtual void    OnAddItems ();
virtual void    OnComboBoxInit ();
virtual BOOL    OnSelectOther (BOOL isOther2, int curSel, int& newSel);
        void    SelectOther (BOOL isOther2);

public:
        int     AddItemToList (LPCTSTR name, INT_PTR cargo);
        int     AddItemToMRU (LPCTSTR name, int cargo); 
        void    AddItems ();
virtual BOOL    Create (DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
virtual int     ExtraWidth ();
        int     FindItemByCargo (INT_PTR cargo);
        int     GetCargoOption1 ();
        int     GetCargoOption2 ();
        INT_PTR     GetCurrentItemCargo ();
        INT_PTR     GetItemCargo (int item);
        LOGPALETTE *GetLogPalette ();
        HPALETTE GetPalette ();
        BOOL    GetUseOption1 ();
        BOOL    GetUseOption2 ();
        BOOL    GetUseOther1 ();
        BOOL    GetUseOther2 ();
virtual int     ImageWidth ();
        int     InsertItemInList (int index, LPCTSTR name, INT_PTR cargo);
        int     ItemHeight ();
        void    RecalcHeight ();
        void    RemoveItemFromMRU (int cargo);
        void    SetCargoOption1 (int cargo);
        void    SetCargoOption2 (int cargo);
        void    SetLastSelection (int sel);
        void    SetLogPalette (LOGPALETTE *logPalette);
        void    SetPalette (HPALETTE hPalette);
        void    SetUseOption1 (BOOL use);
        void    SetUseOption2 (BOOL use);
        void    SetUseOther1 (BOOL use);
        void    SetUseOther2 (BOOL use);

public:        
        BOOL    GetUseByBlock ();
        BOOL    GetUseByLayer ();
        BOOL    GetUseOther ();
        BOOL    GetUseWindows ();
        void    SetUseByBlock (BOOL use);
        void    SetUseByLayer (BOOL use);
        void    SetUseOther (BOOL use);
        void    SetUseWindows (BOOL use);

public:
    
    public:
    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
    virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
    protected:
    virtual void PreSubclassWindow();
    virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

protected:
    
    afx_msg BOOL OnCloseUp();
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg BOOL OnDropDown();
    afx_msg BOOL OnSelEndOk();

    DECLARE_MESSAGE_MAP()
};

class CZcUiLTypeRecord : public CObject {
public:
	CString & ltypeName();
	void setLTypeName(CString sName);
	ZcDbObjectId objectId();
	void setObjectId(ZcDbObjectId id);
	BOOL isDependent();
	void setIsDependent(BOOL bValue);

private:
	CString m_strLTypeName;
	ZcDbObjectId m_idObjectId;
	BOOL m_bIsDependent;
};

inline CString& CZcUiLTypeRecord::ltypeName() 
{
	return m_strLTypeName;
}

inline void CZcUiLTypeRecord::setLTypeName(CString sName) 
{
	m_strLTypeName = sName;
}

inline ZcDbObjectId CZcUiLTypeRecord::objectId() 
{
	return m_idObjectId;
}

inline void CZcUiLTypeRecord::setObjectId(ZcDbObjectId id) 
{
	m_idObjectId = id;
}

inline BOOL CZcUiLTypeRecord::isDependent()
{
	return m_bIsDependent;
}

inline void CZcUiLTypeRecord::setIsDependent(BOOL bValue)
{
	m_bIsDependent = bValue;
}

class ZCUI_PORT CZcUiLineTypeComboBox : public CZcUiMRUComboBox 
{
public:
	CZcUiLineTypeComboBox ();
	virtual ~CZcUiLineTypeComboBox ();

	virtual void    OnComboBoxInit ();

	void    AddItems ();

	ZcDbObjectId getOIDSel(int sel);
	ZcDbObjectId getOIDCurSel();
	void setCurSelByOID(const ZcDbObjectId& oidCurSel);       
	bool isOtherSelected();
	void forceSelectOther (BOOL isOther2);
	int  getLastSelection();
	bool getDbReload();
	void setDbReload(bool bReload);
	void emptyLTypeLocalList();
protected:
	virtual void DrawItemImage (CDC& dc, CRect& r, INT_PTR cargo);
	virtual void OnAddItems ();
	virtual BOOL OnSelectOther (BOOL isOther2, int curSel, int& newSel);
    INT_PTR  GetItemCargo (int item);
    int  FindItemByCargo (ZcDbObjectId cargo);
    void LoadContentsFromDatabase();
    void ShowLTypes(bool bForceReloadDB = false);
    int AddLTypeToControl(CZcUiLTypeRecord * pLTypeRecord);
    CZcUiLTypeRecord* CreateLTRecord(CString& cstrLTName, ZcDbObjectId& oidLT);

	virtual int ImageWidth();

    ZcDbDatabase* getLTLocalMapDB();
    void setLTLocalMapDB(ZcDbDatabase* pDb);

    CObList m_LTypeLocalList;
    ZcDbDatabase* m_pLTLocalMapDB;
    bool m_bDbReload;

public:

public:

    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
protected:
    DECLARE_MESSAGE_MAP()
};

inline
bool
CZcUiLineTypeComboBox::getDbReload()
{
    return m_bDbReload;
}
inline
void
CZcUiLineTypeComboBox::setDbReload(bool bReload)
{
    m_bDbReload = bReload;
}

inline
void
CZcUiLineTypeComboBox::forceSelectOther (BOOL isOther2)
{
    SelectOther(isOther2);
}

inline
int
CZcUiLineTypeComboBox::getLastSelection()
{
    return m_lastSelection;
}

inline
bool
CZcUiLineTypeComboBox::isOtherSelected()
{
    CString otherName;
    CString curSelName;
    GetOtherName (false, otherName);
    GetLBText(GetCurSel(), curSelName);
    return curSelName == otherName;
}

inline
ZcDbObjectId
CZcUiLineTypeComboBox::getOIDSel(int sel)
{
    ZcDbObjectId oidLT;
    CZcUiLTypeRecord* pLTRec =
                (CZcUiLTypeRecord*)(GetItemDataPtr(sel));
    if (NULL != pLTRec)
        oidLT = pLTRec->objectId();
    return oidLT;
}

inline
ZcDbObjectId
CZcUiLineTypeComboBox::getOIDCurSel()
{
    return getOIDSel(GetCurSel());
}

inline
void
CZcUiLineTypeComboBox::setCurSelByOID(const ZcDbObjectId& oidCurSel)
{
    int i = FindItemByCargo(oidCurSel);
    SetCurSel(i >= 0 ? i : m_lastSelection);
    if (i >= 0)
        m_lastSelection = i;
}
class ZCUI_PORT CZcUiColorComboBox : public CZcUiMRUComboBox {
public:
                CZcUiColorComboBox ();
virtual         ~CZcUiColorComboBox ();

protected:
virtual void    DrawItemImage (CDC& dc, CRect& r, INT_PTR cargo);
virtual void    OnAddItems ();
virtual BOOL    OnSelectOther (BOOL isOther2, int curSel, int& newSel);

protected:
        int     m_blockColorIndex;

virtual BOOL    GetOtherColorIndex (
                    int defaultColorIndex, int layerColorIndex, BOOL enableMetaColors,
                    int& colorIndex
                );
virtual BOOL    GetWindowsColor (COLORREF& color);
virtual BOOL    GetOtherName (BOOL isOther2, CString& name);

        void    RGBFill (CDC& dc, CRect& rFill);
public:
        int     AddColorToMRU (int colorIndex);
        int     FindItemByColorIndex (int colorIndex);
        int     GetBlockColorIndex ();
virtual COLORREF GetColorFromIndex (int colorIndex);
virtual int     GetColorIndex (COLORREF color);
        int     GetCurrentItemColorIndex ();
virtual int     GetCurrentLayerColorIndex ();
        int     GetItemColorIndex (int item);
virtual COLORREF LookupColor (
                    int colorIndex,
                    LOGPALETTE *logPalette
                );
        void    SetBlockColorIndex (int colorIndex);

public:

protected:
    DECLARE_MESSAGE_MAP()
};

#define ZCUI_TRUECOLOR_COMBOBOX_TABLE_SIZE  ZCUI_MAX_TRUECOLOR_COMBOBOX_MRU + 9

class ZCUI_PORT CZcUiTrueColorComboBox : public CZcUiMRUComboBox {
public:

    enum ColorTableIndex {
        kCargoOption1           =  0,
        kCargoOption2           =  1,
        kCargoStockItem1        =  2,
        kCargoStockItem2        =  3,
        kCargoStockItem3        =  4,
        kCargoStockItem4        =  5,
        kCargoStockItem5        =  6,
        kCargoStockItem6        =  7,
        kCargoStockItem7        =  8,
        kIndexOfFirstMRUItem    =  9,
        kCargoOther1            = -1,
        kCargoOther2            = -2,
        kLastIndex              = ZCUI_TRUECOLOR_COMBOBOX_TABLE_SIZE-1
    };

                        CZcUiTrueColorComboBox      ();
virtual                 ~CZcUiTrueColorComboBox     ();

void                    AddItems                    ();
int                     AddItemToList               (LPCTSTR name, int index, INT_PTR cargo);
int                     AddItemToMRU                (LPCTSTR name, int cargo);
int                     AddColorToMRU               (const ZcCmColor& color);

int                     FindItemByColor             (const ZcCmColor& color);
void                    GetCurrentItemColor         (ZcCmColor& color);
DWORD                   getColorByCargo             (int cargo);

const ZcCmColor&        GetBlockColor               ();
void                    SetBlockColor               (const ZcCmColor& color);

virtual COLORREF        GetColorFromIndex           (int colorIndex);
DWORD                   getColorData                (ZcCmColor color);
int                     GetColorIndex               (COLORREF color);

protected:

int                     m_cargoOther1;
int                     m_cargoOther2;
ZcCmColor               m_blockColor;

virtual void            DrawItemImage               (CDC& dc, CRect& r, INT_PTR cargo);
virtual void            OnAddItems                  ();

virtual BOOL            OnSelectOther               (BOOL isOther2,int curSel,int& newSel);
BOOL                    GetOtherColor               (ZcCmColor& defaultColor,
                                                     const ZcCmColor& layerColor,
                                                     BOOL enableMetaColors);
BOOL                    GetWindowsColor             (ZcCmColor& color);
virtual BOOL            GetOtherName                (BOOL isOther2, CString& name);

ZcCmColor *             m_ZcCmColorTable[ZCUI_TRUECOLOR_COMBOBOX_TABLE_SIZE];
int                     m_nextZcCmColorTableIndex;

void                    initZcCmColorTable          (void);

void                    RGBFill                     (CDC& dc, CRect& rFill);

bool                    GetCurrentLayerColor        (ZcCmColor& color);

virtual COLORREF        LookupColor                 (int colorIndex, LOGPALETTE *logPalette);

afx_msg void            OnDrawItem                  (int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);

public:

protected:

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiLineWeightComboBox : public CZcUiMRUComboBox {
public:
                CZcUiLineWeightComboBox ();
virtual         ~CZcUiLineWeightComboBox ();

protected:
virtual void    DrawItemImage (CDC& dc, CRect& r, INT_PTR cargo);
virtual void    OnAddItems ();

protected:
        double  m_lineWeightScale;

public:
        int     FindItemByLineWeight (int lw);
        int     GetCurrentItemLineWeight ();
        int     GetCurrentLayerLineWeight ();
        int     GetItemLineWeight (int item);
        double  GetLineWeightScale ();
        void    SetLineWeightScale (double scale);
        void    SetUseDefault(BOOL b);
        virtual int     ImageWidth ();
private:
        BOOL    m_bUseDefault;

public:

protected:

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiArrowHeadComboBox : public CZcUiMRUComboBox {
public:
                CZcUiArrowHeadComboBox ();
virtual         ~CZcUiArrowHeadComboBox ();

protected:
virtual void    DrawItemImage (CDC& dc, CRect& r, INT_PTR cargo);
virtual int     CalcItemHeight ();
virtual BOOL    GetOtherName (BOOL isOther2, CString& name);
virtual void    OnAddItems ();
virtual void    OnComboBoxInit ();

public:
        BOOL    GetUseOrigin2 ();
        void    SetUseOrigin2 (BOOL use);
		virtual bool LoadImage();
private:
        CBitmap* m_pArrowImage;
        int     m_arrowCount;
        int     m_arrowSize;
        BOOL    m_bUseOrigin2;
		BOOL    m_bThemedArrowImagesLoaded;

public:
        int     AddArrowHeadToMRU (LPCTSTR name);

public:

protected:

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiPlotStyleTablesComboBox : public CZcUiMRUComboBox {
    public:
        CZcUiPlotStyleTablesComboBox ();
        CZcUiPlotStyleTablesComboBox (BOOL bInitialize);
        virtual         ~CZcUiPlotStyleTablesComboBox ();
        
        void    SetFileType(bool currentDrawing, bool named);
        int     AddMissingStyleTable(LPCTSTR fullFileName, bool bMissing = true);
        bool    IsMissing(int index);

        virtual int     ImageWidth ();

        void GetLBText(int nIndex, CString& rString) const;

        int     AddItemToList (LPCTSTR name,    INT_PTR cargo);

    protected:
        virtual void    DrawItemImage (CDC& dc, CRect& r, INT_PTR cargo);
        virtual int     CalcItemHeight ();
        virtual void    OnAddItems ();
        virtual void    OnComboBoxInit ();

    private:
        CBitmap m_plotStyleTablesBitmap;
        int     m_plotStyleTableBitmapSize;
        BOOL    m_bImageDisplayed;
        bool    m_bCurrentDrawing;
        bool    m_bNamed;
        BOOL    m_bInitialize;          

    public:
		virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
    protected:

    afx_msg BOOL OnDropDown();

        DECLARE_MESSAGE_MAP()
};
class ZCUI_PORT CZcUiPlotStyleNamesComboBox : public CZcUiMRUComboBox {
    public:
        CZcUiPlotStyleNamesComboBox ();
        virtual         ~CZcUiPlotStyleNamesComboBox ();
        virtual int     ImageWidth ();
        void            OtherRunsSelectPlotStyle() {m_whatOtherDoes = 0; }
        void            OtherRunsCurrentPlotStyle() {m_whatOtherDoes = 1; }
        void            OtherRunsDefault() {m_whatOtherDoes = -1;}
        void            SetAllowByLayerByBlock(BOOL bAllow) {m_bAllowByLayerByBlock = bAllow;}
        void            SetColorDependentMode();
        void            SetNamedMode();

    protected:
        virtual void    OnAddItems ();
        virtual BOOL    OnSelectOther (BOOL isOther2, int curSel, int& newSel);
        virtual void    OnComboBoxInit ();

    private:

        int m_whatOtherDoes;
        BOOL m_bColorDependentMode;
        BOOL m_bAllowByLayerByBlock;
        BOOL m_bLastByBlock;
        BOOL m_bLastByLayer;
        BOOL m_bLastUseOther;

    public:
    protected:
        DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiPredefBlockComboBox : public CZcUiMRUComboBox {
public:
                CZcUiPredefBlockComboBox ();
virtual         ~CZcUiPredefBlockComboBox ();

protected:
virtual void    DrawItemImage (CDC& dc, CRect& r, INT_PTR cargo);
virtual int     CalcItemHeight ();
virtual BOOL    GetOtherName (BOOL isOther2, CString& name);
virtual void    OnAddItems ();
virtual void    OnComboBoxInit ();
	virtual bool    LoadImages ();
private:
        CBitmap* m_blockBitmap;
        int     m_blockCount;
        int     m_blockSize;
		BOOL	m_bThemedBlockImagesLoaded;
public:
        int     AddPredefBlockToMRU (LPCTSTR name);

public:
protected:
    DECLARE_MESSAGE_MAP()
};
#pragma pack (pop)
#endif


