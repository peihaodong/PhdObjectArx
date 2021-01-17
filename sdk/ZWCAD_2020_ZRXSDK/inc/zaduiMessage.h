

#ifndef _zduiMessage_h
#define _zduiMessage_h
#pragma pack (push, 8)

#pragma once

typedef enum {

    kZdUiNotify_Nothing,
    kZdUiNotify_Generic,
    kZdUiNotify_AppMainWindow,
    kZdUiNotify_AppResourceInstance,
    kZdUiNotify_AutoLoad,
    kZdUiNotify_Reload,
    kZdUiNotify_GetTipSupport,
    kZdUiNotify_GetTipText,
    kZdUiNotify_GetTipRect,
    kZdUiNotify_HitTipRect,
    kZdUiNotify_DrawTip,
    kZdUiNotify_DrawTipText,
    kZdUiNotify_UpdateTip,
    kZdUiNotify_HideWindow,
    kZdUiNotify_ShowWindow,
    kZdUiNotify_RestoreFocus,
    kZdUiNotify_Change,
    kZdUiNotify_NotValid,
    kZdUiNotify_Valid,
    kZdUiNotify_Validate,
    kZdUiNotify_CommandState,
	kZdUiNotify_ModalState,
} ZDUI_NOTIFY;

typedef enum {

    kZdUiReply_Nothing,
    kZdUiReply_Ok,
    kZdUiReply_NotValid,
    kZdUiReply_Valid,
    kZdUiReply_TextTip,
    kZdUiReply_ToolTip,
    kZdUiReply_DrawTip,

} ZDUI_REPLY;

typedef enum {

    kZdUiCommand_Cancelled = -1,
    kZdUiCommand_Completed,
    kZdUiCommand_Begun,

} ZDUI_COMMAND_STATE;

typedef enum 
{
	kZdUiModal_Begun = 1,
	kZdUiModal_Ended,
} ZDUI_MODAL_STATE;

class ZDUI_PORT CZdUiDrawTipText {
public:
                CZdUiDrawTipText (CDC& dc, CRect& rect, CString& text);

public:
        CDC&    m_dc;
        CRect&  m_rect;
        CString& m_text;
};

const UINT ZDUI_PORT ZdUiMessage ();

ZDUI_NOTIFY ZDUI_PORT ZdUiNotification (WPARAM wp);

#if !defined(_WIN64) && !defined (_ZC64)
ZDUI_REPLY ZDUI_PORT ZdUiNotify (CWnd& w, UINT id, ZDUI_NOTIFY n, DWORD_PTR lParam);
ZDUI_REPLY ZDUI_PORT ZdUiNotify (CWnd* w, UINT id, ZDUI_NOTIFY n, DWORD_PTR lParam);
#else
ZDUI_REPLY ZDUI_PORT ZdUiNotify (CWnd& w, UINT id, ZDUI_NOTIFY n, LPARAM lParam);
ZDUI_REPLY ZDUI_PORT ZdUiNotify (CWnd* w, UINT id, ZDUI_NOTIFY n, LPARAM lParam);
#endif

UINT ZDUI_PORT ZdUiNotifyId (WPARAM wp);

#if !defined(_WIN64) && !defined (_ZC64)
BOOL ZDUI_PORT ZdUiPostNotify (CWnd& w, UINT id, ZDUI_NOTIFY n, DWORD_PTR lParam);
BOOL ZDUI_PORT ZdUiPostNotify (CWnd* w, UINT id, ZDUI_NOTIFY n, DWORD_PTR lParam);
#else
BOOL ZDUI_PORT ZdUiPostNotify (CWnd& w, UINT id, ZDUI_NOTIFY n, LPARAM lParam);
BOOL ZDUI_PORT ZdUiPostNotify (CWnd* w, UINT id, ZDUI_NOTIFY n, LPARAM lParam);
#endif
#pragma pack (pop)
#endif


