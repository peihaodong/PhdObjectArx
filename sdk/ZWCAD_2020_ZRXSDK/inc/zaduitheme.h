

#ifndef _ZDUI_THEME_H_
#define _ZDUI_THEME_H_

#include "zadesk.h"
#ifdef _ZSOFT_WINDOWS_
#include <afxtempl.h>
#include "zAdAChar.h"
#include "zAcColorThemeEnum.h"

class CZcColorTheme;

#define PROPERTY_PALETTE_THEME  ZCRX_T("PropertyPalette")
#define TOOL_PALETTE_THEME      ZCRX_T("ToolPalette")
#define OWNDERDRAW_BUTTON_THEME ZCRX_T("OwnerDrawButton")
#define DIALOG_WORKSHEET_THEME  ZCRX_T("DialogWorksheet")
#define PALETTE_SET_THEME       ZCRX_T("PaletteSet")
#define DESIGN_CENTER_THEME     ZCRX_T("DesignCenter")
#define TOOL_PANEL_THEME        ZCRX_T("ToolPanel")
#define DOCKBAR_THEME           ZCRX_T("DockBar")   
#define DOCKCONTROLBAR_THEME    ZCRX_T("DockControlBar")   
#define ANCHORBAR_THEME         ZCRX_T("AnchorBar")   
#define ACTIVE_THEME            ZCRX_T("ACTIVETHEME")
#define DIALOG_THEME            ZCRX_T("DIALOGTHEME")

typedef enum {
    
	kUnknownElements = -1,

	kPaletteFontCaption,
	kPaletteFontTab,
	kPaletteFontToolTip,
	kPaletteFont,
	kWorksheetFont,
	kWorksheetFontCaption,
	kInspectorItemFont,
	kInspectorRootFont,

	kPaletteBackground,
	kPaletteCaptionBackground,
	kPaletteCaptionInactive,
	kPaletteCaptionText,
	kPaletteCaptionInactiveText,
	kPaletteTabText,
	kPaletteTabBackground,
	kPaletteBorder,
	kPaletteTabShadow,
	kPaletteTabHighlight,
	kPaletteTabTextHilite,
	kPaletteTabSelectHilite,
	kPaletteToolTip,
	kPaletteToolTipText,
	kPaletteButtonText,
	kPaletteButtonTextDisabled,
	kPaletteButtonBorder,
	kPaletteItemText,
	kPaletteScrollBackground,
	kPaletteScrollThumb,
	kPaletteScrollArrow,

	kWorksheetBackground,
	kWorksheetCaptionBackground,
	kWorksheetCaptionText,
	kWorksheet3DBtnShadow,
	kWorksheetButtonText,
	kWorksheetButtonTextDisabled,
	kWorksheetScrollBackground,
	kWorksheetScrollThumb,
	kWorksheetBorder,
	kWorksheetGripHighlight,

	kInspector,
	kInspectorTop,
	kInspectorCat,
	kInspectorItem,
	kInspectorBorder,
	kInspectorBorderItem,
	kInspectorTextTop,
	kInspectorTextCat,
	kInspectorTextItem,
	kInspectorTextLabel,
	kInspectorFGHighlight,
	kInspectorBGHighlight,
	kInspector3dShadow,
	kInspectorControl,
	kInspectorCatChevron1,
	kInspectorCatChevron2,
	kInspectorSubChevron,
	kInspectorCellHighlight,

	kPanelBackground,
	kPanelSashBackground,
	kPanelBorder,

	kControlBorder,
	kControlBackground,  
	kDisabledControlBorder,
	kControlSupport,
	kControlHighlight,
	kControlActiveOuterBorder,
	kControlErrorOuterBorder,
	kControlActiveText,
	kControlText,
	kControlInactiveText,

	kPaletteFrameInnerBorder,
	kPaletteFrameOuterBorder,
	kPaletteFrameBackground,
	kPaletteFrameShadow,
	kInspectorTopGradient1,
	kInspectorTopGradient2,
	kPaletteScrollBackgroundBorder,
	kPaletteScrollBackgroundGradient1,
	kPaletteScrollBackgroundGradient2,
	kPaletteScrollSliderInactive,
	kPaletteScrollSliderActiveOuterBorder,
	kPaletteScrollSliderActiveOuterGradient1,
	kPaletteScrollSliderActiveOuterGradient2,
	kPaletteScrollSliderActiveOuterGradient3,
	kPaletteScrollSliderActiveOuterGradient4,
	kPaletteScrollSliderActiveInnerGradient1,
	kPaletteScrollSliderActiveInnerGradient2,
	kInspectorClosedOuterBorder,
	kInspectorOpenOuterBorder,
	kInspectorInnerBorder,
	kPaletteColumnHeaderBackground,
	kPaletteHyperlinkText,
	kPaletteTreeOrListBackground,

	kAnchorBarOuterBorder,
	kAnchorBarEmbossRightBottom,
	kAnchorBarEmbossLeftTop,
	kAnchorBarInnerHighlight,
	kAnchorBarGradient1,
	kAnchorBarGradient2,
	kAnchorBarActiveTitleBackground,
	kAnchorBarCaptionText,

	kGrabBarDotDark,
	kGrabBarDotLight,
	kControlBarTitleBackground,
	
	kAppFrameBorder,
	kAppFrameOuterBorder,
	kAppFrameAFGradientTop,
	kAppFrameAFGradientBottom,
	
	kAppFrameCaptionActiveGradientTop,
	kAppFrameCaptionActiveGradientBottom,
	kAppFrameCaptionInActiveGradientTop,
	kAppFrameCaptionInActiveGradientBottom,
	kAppFrameCaptionOuterBorder,
	kAppFrameCaptionInnerBorder,
	
	kAppFrameQATGradientTop,
	kAppFrameQATGradientBottom,
	kAppFrameQATOuterBorder,
	kAppFrameQATInnerBorder,

	kAppFrameQATButtonsBorder,
	kAppFrameQATButtonsRolloverBorder,
	kAppFrameQATButtonsClickBorder,
	kAppFrameQATFlyoutButtonText,

	kAppFrameBigMBBGradientFillTop,          
	kAppFrameBigMBBGradientFillMiddleUpper,  
	kAppFrameBigMBBGradientFillMiddleLower,  
	kAppFrameBigMBBGradientFillBottom,       

	kAppFrameSmallMBBGradientFillTop,        
	kAppFrameSmallMBBGradientFillMiddleUpper,
	kAppFrameSmallMBBGradientFillMiddleLower,
	kAppFrameSmallMBBGradientFillBottom,     

	kAppFrameDocNameProductNameText,
	kAppFrameDocNameFileNameText,
	kAppFrameDocNameInactiveProductNameText,
	kAppFrameDocNameInactiveFileNameText,

	kAppFrameMenuBarMenuText,
	kAppFrameMenuBarMenuHighlightText,
	kAppFrameMenuBarMenuDeHighlightText,
	kAppFrameMenuBarRolloverBorder,
	kAppFrameMenuBarRolloverFill,
	kAppFrameMenuBarClickBorder,
	kAppFrameMenuBarClickFill,

	kAppFrameAppWindowControlButtonsRolloverGradientBorderTop,
	kAppFrameAppWindowControlButtonsRolloverGradientBorderMiddle,
	kAppFrameAppWindowControlButtonsRolloverGradientBorderBottom,
	kAppFrameAppWindowControlButtonsRolloverGradientFillTop,
	kAppFrameAppWindowControlButtonsRolloverGradientFillMiddleUpper,
	kAppFrameAppWindowControlButtonsRolloverGradientFillMiddleLower,
	kAppFrameAppWindowControlButtonsRolloverGradientFillBottom,
	kAppFrameAppWindowControlButtonsClickGradientBorderTop,
	kAppFrameAppWindowControlButtonsClickGradientBorderMiddle,
	kAppFrameAppWindowControlButtonsClickGradientBorderBottom,
	kAppFrameAppWindowControlButtonsClickGradientFillTop,
	kAppFrameAppWindowControlButtonsClickGradientFillMiddleUpper,
	kAppFrameAppWindowControlButtonsClickGradientFillMiddleLower,
	kAppFrameAppWindowControlButtonsClickGradientFillBottom,
	kAppFrameInfoCenterToggleButtonText,
	kAppFrameZeroDocBackgroundGradientTop,
	kAppFrameZeroDocBackgroundGradientBottom,

	kStatusBarPaneUnSelectedTopGradient,
	kStatusBarPaneUnSelectedBottomGradient,
	kStatusBarPaneRolloverGradient1,
	kStatusBarPaneRolloverGradient2,
	kStatusBarPaneRolloverGradient3,
	kStatusBarPaneRolloverGradient4,
	kStatusBarPaneSelectionGradient1,
	kStatusBarPaneSelectionGradient2,
	kStatusBarPaneSelectionGradient3,
	kStatusBarPaneSelectionGradient4,
	kStatusBarPaneBorder1,
	kStatusBarPaneBorder2,
	kStatusBarBkGrdBorder,
	kStatusBarBkGrdInnerLine,
	kStatusBarBkGrdTopGradient,
	kStatusBarBkGrdBottomGradient,

	kToolbarGripDarkDot,
	kToolbarGripLightDot,
	kToolbarGripBackground,
	kToolbarBorder,
	kToolbarBackground,
	kToolbarRolloverBorder,
	kToolbarCloseButton,

	kSquareButtonHoverBorder,
	kSquareButtonHoverHighlight,
	kSquareButtonHoverBackgroundTop,
	kSquareButtonHoverBackgroundBottom,
	kSquareButtonClickBorder,
	kSquareButtonClickHighlight,
	kSquareButtonClickBackgroundTop,
	kSquareButtonClickBackgroundBottom,

	kComboBoxBackgroundTop,
	kComboBoxBackgroundBottom,
	kComboBoxActiveBackgroundTop,
	kComboBoxActiveBackgroundBottom,
	kComboBoxArrow,
	kComboBoxArrowShadow,
	kComboBoxHoverText,
	kComboBoxSelectText,
	kComboBoxHoverBackgroundTop,
	kComboBoxHoverBackgroundBottom,
	kComboBoxSelectBackgroundTop,
	kComboBoxSelectBackgroundBottom,
	kComboBoxHoverSelectHighlight,

	kSpinControlHighlight,
	kSpinControlBorder,
	kSpinControlClickBackgroundTop,
	kSpinControlClickBackgroundBottom,
	kSpinControlBackgroundTop,
	kSpinControlBackgroundBottom,

	kTextInputInnerShadow,
	kTextInputActiveBackgroundTop,
	kTextInputActiveBackgroundBottom,
	kTextInputActiveHighlight,
	kTextInputActiveText,
	kTextInputActiveBorder,

	kCategoryExpander,
	kCategoryExpanderShadow,
	kGroupGrip,
	kGroupGripShadow,
	kCategoryBackground,
	kCategoryBorder,
	kCategoryActiveText,

	kListBoxHoverBackgroundTop,
	kListBoxHoverBackgroundBottom,
	kListBoxHoverBorder,
	kListBoxClickBackgroundTop,
	kListBoxClickBackgroundBottom,
	kListBoxClickBorder,
	kListBoxSelectBackgroundTop,
	kListBoxSelectBackgroundBottom,
	kListBoxSelectBorder,
	kListBoxSelectHoverBackgroundTop,
	kListBoxSelectHoverBackgroundBottom,
	kListBoxSelectHoverBorder,
	kListBoxInnerShadow,
	kListBoxSelectText,

	kTreeControlLine

} ZdUiThemeElement;

class CZdUiThemeModifiedReactor
{
public:
    virtual void ThemeModified(const CZdUiTheme * pTheme, ZdUiThemeElement element) = 0;
};

class ZDUI_PORT CZdUiTheme
{
    friend class CZdUiThemeManager;
	friend class ZcadUiStyleManager;

public:
    
    COLORREF GetColor (ZdUiThemeElement nDisplayElement) const;
    DWORD GetARGBColor(ZdUiThemeElement nDisplayElement) const;
    BOOL SetColor(ZdUiThemeElement nDisplayElement, COLORREF crColor);
	BOOL SetARGBColor(ZdUiThemeElement nDisplayElement, DWORD dColor);

    BOOL SetFont(ZdUiThemeElement nDisplayElement,LOGFONT *plf=NULL);
    BOOL GetFont(ZdUiThemeElement nDisplayElement,LOGFONT *plf) const;
    BOOL GetFont(ZdUiThemeElement nDisplayElement,CFont *& pFont) const;

    BOOL GetData(int nElement, DWORD& dwData) const;
    void SetData(int nElement, const DWORD& dwData);
    BOOL GetData(int nElement, CString& sData) const;
    void SetData(int nElement, const CString& sData);
    void* GetDataPtr(int nElement) const;
    void SetDataPtr(int nElement, void* pData);
    BOOL RegisterReactor(CZdUiThemeModifiedReactor * pReactor);
    BOOL UnregisterReactor(CZdUiThemeModifiedReactor * pReactor);

    void SuspendModifiedNotifications() { m_nModNotificationsSuspended++; }
    void ResumeModifiedNotifications();
    void SendModifiedNotification() const;
	bool UsesActiveThemeColors(){return m_pColorTheme == NULL;}
	bool IsDark() const;
    void IncrementRefCount() { m_nRefCount++; }

    CZdUiTheme& operator=(const CZdUiTheme& Theme);
    static COLORREF GetRGBForeColor(DWORD fgColor, COLORREF bgColor);
private:
    CZdUiTheme();
	CZdUiTheme(const CZcColorTheme & colorTheme, ZcColorThemeEnum themeType);
	virtual ~CZdUiTheme();
	void commonInitialize();
	void SetColorTheme(const CZcColorTheme& colorTheme, ZcColorThemeEnum themeType);
	void InitializeFont(LOGFONT & sourceLF, LOGFONT & destLF, int fontType = 0);
	void InitializeFontsForDialog();
	void InitWithActiveThemeColors();
    void SendThemeModifiedNotifications(ZdUiThemeElement nElement) const;

    void CheckXP();

	COLORREF GetActiveThemeColor(ZdUiThemeElement nElement) const;

    BOOL UsesXP() { return m_bUsesXPThemes; };

    void DecrementRefCount() { m_nRefCount--; }
    int RefCount() { return m_nRefCount; }

    int    m_nRefCount;
	CTypedPtrArray<CPtrArray, CZdUiThemeModifiedReactor*> m_arrayModReactors;
    int m_nModNotificationsSuspended;
    CMap<int, int, DWORD, DWORD> m_mapDwordValues;
    CMap<int, int, CString, CString> m_mapStringValues;
    CMap<int, int, void*, void*> m_mapPointerValues;

    LOGFONT             m_lfWorksheet;
    LOGFONT             m_lfWorksheetCaption;
    LOGFONT             m_lfPaletteCaption;
    LOGFONT             m_lfInspectorItem;
    LOGFONT             m_lfInspectorRoot;
    LOGFONT             m_lfPaletteTab;
    LOGFONT             m_lfPalette;
    LOGFONT             m_lfPaletteToolTip;
	CZcColorTheme*      m_pColorTheme;
	ZcColorThemeEnum    m_themeType;

    BOOL                m_bUsesXPThemes;    
    
};
#endif

#endif 

