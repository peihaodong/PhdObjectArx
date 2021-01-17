
#ifndef __ADUIMESSAGE_H__
#define __ADUIMESSAGE_H__

#include "../inc/zaduiMessage.h"

#ifndef ADUI_COMMAND_STATE
#define ADUI_COMMAND_STATE		ZDUI_COMMAND_STATE
#endif //#ifndef ADUI_COMMAND_STATE

#ifndef ADUI_NOTIFY
#define ADUI_NOTIFY		ZDUI_NOTIFY
#endif //#ifndef ADUI_NOTIFY

#ifndef ADUI_PORT
#define ADUI_PORT		ZDUI_PORT
#endif //#ifndef ADUI_PORT

#ifndef ADUI_REPLY
#define ADUI_REPLY		ZDUI_REPLY
#endif //#ifndef ADUI_REPLY

#ifndef AdUiMessage
#define AdUiMessage		ZdUiMessage
#endif //#ifndef AdUiMessage

#ifndef AdUiNotification
#define AdUiNotification		ZdUiNotification
#endif //#ifndef AdUiNotification

#ifndef AdUiNotify
#define AdUiNotify		ZdUiNotify
#endif //#ifndef AdUiNotify

#ifndef AdUiNotifyId
#define AdUiNotifyId		ZdUiNotifyId
#endif //#ifndef AdUiNotifyId

#ifndef AdUiPostNotify
#define AdUiPostNotify		ZdUiPostNotify
#endif //#ifndef AdUiPostNotify

#ifndef CAdUiDrawTipText
#define CAdUiDrawTipText		CZdUiDrawTipText
#endif //#ifndef CAdUiDrawTipText

#ifndef kAdUiCommand_Begun
#define kAdUiCommand_Begun		kZdUiCommand_Begun
#endif //#ifndef kAdUiCommand_Begun

#ifndef kAdUiCommand_Cancelled
#define kAdUiCommand_Cancelled		kZdUiCommand_Cancelled
#endif //#ifndef kAdUiCommand_Cancelled

#ifndef kAdUiCommand_Completed
#define kAdUiCommand_Completed		kZdUiCommand_Completed
#endif //#ifndef kAdUiCommand_Completed

#ifndef kAdUiNotify_AppMainWindow
#define kAdUiNotify_AppMainWindow		kZdUiNotify_AppMainWindow
#endif //#ifndef kAdUiNotify_AppMainWindow

#ifndef kAdUiNotify_AppResourceInstance
#define kAdUiNotify_AppResourceInstance		kZdUiNotify_AppResourceInstance
#endif //#ifndef kAdUiNotify_AppResourceInstance

#ifndef kAdUiNotify_AutoLoad
#define kAdUiNotify_AutoLoad		kZdUiNotify_AutoLoad
#endif //#ifndef kAdUiNotify_AutoLoad

#ifndef kAdUiNotify_Change
#define kAdUiNotify_Change		kZdUiNotify_Change
#endif //#ifndef kAdUiNotify_Change

#ifndef kAdUiNotify_CommandState
#define kAdUiNotify_CommandState		kZdUiNotify_CommandState
#endif //#ifndef kAdUiNotify_CommandState

#ifndef kAdUiNotify_DrawTip
#define kAdUiNotify_DrawTip		kZdUiNotify_DrawTip
#endif //#ifndef kAdUiNotify_DrawTip

#ifndef kAdUiNotify_DrawTipText
#define kAdUiNotify_DrawTipText		kZdUiNotify_DrawTipText
#endif //#ifndef kAdUiNotify_DrawTipText

#ifndef kAdUiNotify_Generic
#define kAdUiNotify_Generic		kZdUiNotify_Generic
#endif //#ifndef kAdUiNotify_Generic

#ifndef kAdUiNotify_GetTipRect
#define kAdUiNotify_GetTipRect		kZdUiNotify_GetTipRect
#endif //#ifndef kAdUiNotify_GetTipRect

#ifndef kAdUiNotify_GetTipSupport
#define kAdUiNotify_GetTipSupport		kZdUiNotify_GetTipSupport
#endif //#ifndef kAdUiNotify_GetTipSupport

#ifndef kAdUiNotify_GetTipText
#define kAdUiNotify_GetTipText		kZdUiNotify_GetTipText
#endif //#ifndef kAdUiNotify_GetTipText

#ifndef kAdUiNotify_HideWindow
#define kAdUiNotify_HideWindow		kZdUiNotify_HideWindow
#endif //#ifndef kAdUiNotify_HideWindow

#ifndef kAdUiNotify_HitTipRect
#define kAdUiNotify_HitTipRect		kZdUiNotify_HitTipRect
#endif //#ifndef kAdUiNotify_HitTipRect

#ifndef kAdUiNotify_NotValid
#define kAdUiNotify_NotValid		kZdUiNotify_NotValid
#endif //#ifndef kAdUiNotify_NotValid

#ifndef kAdUiNotify_Nothing
#define kAdUiNotify_Nothing		kZdUiNotify_Nothing
#endif //#ifndef kAdUiNotify_Nothing

#ifndef kAdUiNotify_Reload
#define kAdUiNotify_Reload		kZdUiNotify_Reload
#endif //#ifndef kAdUiNotify_Reload

#ifndef kAdUiNotify_RestoreFocus
#define kAdUiNotify_RestoreFocus		kZdUiNotify_RestoreFocus
#endif //#ifndef kAdUiNotify_RestoreFocus

#ifndef kAdUiNotify_ShowWindow
#define kAdUiNotify_ShowWindow		kZdUiNotify_ShowWindow
#endif //#ifndef kAdUiNotify_ShowWindow

#ifndef kAdUiNotify_UpdateTip
#define kAdUiNotify_UpdateTip		kZdUiNotify_UpdateTip
#endif //#ifndef kAdUiNotify_UpdateTip

#ifndef kAdUiNotify_Valid
#define kAdUiNotify_Valid		kZdUiNotify_Valid
#endif //#ifndef kAdUiNotify_Valid

#ifndef kAdUiNotify_Validate
#define kAdUiNotify_Validate		kZdUiNotify_Validate
#endif //#ifndef kAdUiNotify_Validate

#ifndef kAdUiReply_DrawTip
#define kAdUiReply_DrawTip		kZdUiReply_DrawTip
#endif //#ifndef kAdUiReply_DrawTip

#ifndef kAdUiReply_NotValid
#define kAdUiReply_NotValid		kZdUiReply_NotValid
#endif //#ifndef kAdUiReply_NotValid

#ifndef kAdUiReply_Nothing
#define kAdUiReply_Nothing		kZdUiReply_Nothing
#endif //#ifndef kAdUiReply_Nothing

#ifndef kAdUiReply_Ok
#define kAdUiReply_Ok		kZdUiReply_Ok
#endif //#ifndef kAdUiReply_Ok

#ifndef kAdUiReply_TextTip
#define kAdUiReply_TextTip		kZdUiReply_TextTip
#endif //#ifndef kAdUiReply_TextTip

#ifndef kAdUiReply_ToolTip
#define kAdUiReply_ToolTip		kZdUiReply_ToolTip
#endif //#ifndef kAdUiReply_ToolTip

#ifndef kAdUiReply_Valid
#define kAdUiReply_Valid		kZdUiReply_Valid
#endif //#ifndef kAdUiReply_Valid

#ifndef kAdUiNotify_ModalState
#define kAdUiNotify_ModalState	kZdUiNotify_ModalState
#endif //ifndef kAdUiNotify_ModalState

#ifndef kAdUiModal_Begun
#define kAdUiModal_Begun kZdUiModal_Begun
#endif //ifndef kAdUiModal_Begun

#ifndef kAdUiModal_Ended
#define kAdUiModal_Ended kZdUiModal_Ended
#endif //ifndef kAdUiModal_Ended

#ifndef ADUI_MODAL_STATE
#define ADUI_MODAL_STATE ZDUI_MODAL_STATE
#endif //ifndef ADUI_MODAL_STATE

#endif //#ifndef __ADUIMESSAGE_H__