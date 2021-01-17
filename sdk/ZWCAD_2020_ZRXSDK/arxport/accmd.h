
#ifndef __ACCMD_H__
#define __ACCMD_H__

#include "AdAChar.h"
#ifdef _ZSOFT_WINDOWS_
#include <wtypes.h>
#endif
#include "dbmain.h"
#include "rxobject.h"

#include "../inc/zaccmd.h"

#ifndef ACAD_REGISTERED_COMMANDS
#define ACAD_REGISTERED_COMMANDS		ZCAD_REGISTERED_COMMANDS
#endif //#ifndef ACAD_REGISTERED_COMMANDS

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_CMD_DEFUN
#define ACRX_CMD_DEFUN		ZCRX_CMD_DEFUN
#endif //#ifndef ACRX_CMD_DEFUN

#ifndef ACRX_CMD_DOCEXCLUSIVELOCK
#define ACRX_CMD_DOCEXCLUSIVELOCK		ZCRX_CMD_DOCEXCLUSIVELOCK
#endif //#ifndef ACRX_CMD_DOCEXCLUSIVELOCK

#ifndef ACRX_CMD_DOCREADLOCK
#define ACRX_CMD_DOCREADLOCK		ZCRX_CMD_DOCREADLOCK
#endif //#ifndef ACRX_CMD_DOCREADLOCK

#ifndef ACRX_CMD_INPROGRESS
#define ACRX_CMD_INPROGRESS		ZCRX_CMD_INPROGRESS
#endif //#ifndef ACRX_CMD_INPROGRESS

#ifndef ACRX_CMD_INTERRUPTIBLE
#define ACRX_CMD_INTERRUPTIBLE		ZCRX_CMD_INTERRUPTIBLE
#endif //#ifndef ACRX_CMD_INTERRUPTIBLE

#ifndef ACRX_CMD_MODAL
#define ACRX_CMD_MODAL		ZCRX_CMD_MODAL
#endif //#ifndef ACRX_CMD_MODAL

#ifndef ACRX_CMD_NOBEDIT
#define ACRX_CMD_NOBEDIT		ZCRX_CMD_NOBEDIT
#endif //#ifndef ACRX_CMD_NOBEDIT

#ifndef ACRX_CMD_NOHISTORY
#define ACRX_CMD_NOHISTORY		ZCRX_CMD_NOHISTORY
#endif //#ifndef ACRX_CMD_NOHISTORY

#ifndef ACRX_CMD_NOINTERNALLOCK
#define ACRX_CMD_NOINTERNALLOCK		ZCRX_CMD_NOINTERNALLOCK
#endif //#ifndef ACRX_CMD_NOINTERNALLOCK

#ifndef ACRX_CMD_NOMULTIPLE
#define ACRX_CMD_NOMULTIPLE		ZCRX_CMD_NOMULTIPLE
#endif //#ifndef ACRX_CMD_NOMULTIPLE

#ifndef ACRX_CMD_NONEWSTACK
#define ACRX_CMD_NONEWSTACK		ZCRX_CMD_NONEWSTACK
#endif //#ifndef ACRX_CMD_NONEWSTACK

#ifndef ACRX_CMD_NOOEM
#define ACRX_CMD_NOOEM		ZCRX_CMD_NOOEM
#endif //#ifndef ACRX_CMD_NOOEM

#ifndef ACRX_CMD_NOPAPERSPACE
#define ACRX_CMD_NOPAPERSPACE		ZCRX_CMD_NOPAPERSPACE
#endif //#ifndef ACRX_CMD_NOPAPERSPACE

#ifndef ACRX_CMD_NOPERSPECTIVE
#define ACRX_CMD_NOPERSPECTIVE		ZCRX_CMD_NOPERSPECTIVE
#endif //#ifndef ACRX_CMD_NOPERSPECTIVE

#ifndef ACRX_CMD_NOTILEMODE
#define ACRX_CMD_NOTILEMODE		ZCRX_CMD_NOTILEMODE
#endif //#ifndef ACRX_CMD_NOTILEMODE

#ifndef ACRX_CMD_NO_UNDO_MARKER
#define ACRX_CMD_NO_UNDO_MARKER		ZCRX_CMD_NO_UNDO_MARKER
#endif //#ifndef ACRX_CMD_NO_UNDO_MARKER

#ifndef ACRX_CMD_PLOTONLY
#define ACRX_CMD_PLOTONLY		ZCRX_CMD_PLOTONLY
#endif //#ifndef ACRX_CMD_PLOTONLY

#ifndef ACRX_CMD_REDRAW
#define ACRX_CMD_REDRAW		ZCRX_CMD_REDRAW
#endif //#ifndef ACRX_CMD_REDRAW

#ifndef ACRX_CMD_SESSION
#define ACRX_CMD_SESSION		ZCRX_CMD_SESSION
#endif //#ifndef ACRX_CMD_SESSION

#ifndef ACRX_CMD_TRANSPARENT
#define ACRX_CMD_TRANSPARENT		ZCRX_CMD_TRANSPARENT
#endif //#ifndef ACRX_CMD_TRANSPARENT

#ifndef ACRX_CMD_UNDEFINED
#define ACRX_CMD_UNDEFINED		ZCRX_CMD_UNDEFINED
#endif //#ifndef ACRX_CMD_UNDEFINED

#ifndef ACRX_CMD_USEPICKSET
#define ACRX_CMD_USEPICKSET		ZCRX_CMD_USEPICKSET
#endif //#ifndef ACRX_CMD_USEPICKSET

#ifndef ACRX_COMMAND_DOCK
#define ACRX_COMMAND_DOCK		ZCRX_COMMAND_DOCK
#endif //#ifndef ACRX_COMMAND_DOCK

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef ACRX_MAX_CMDNAME_LEN
#define ACRX_MAX_CMDNAME_LEN		ZCRX_MAX_CMDNAME_LEN
#endif //#ifndef ACRX_MAX_CMDNAME_LEN

#ifndef ACRX_T
#define ACRX_T		ZCRX_T
#endif //#ifndef ACRX_T

#ifndef AD_REGISTERED_COMMANDS
#define AD_REGISTERED_COMMANDS		ZD_REGISTERED_COMMANDS
#endif //#ifndef AD_REGISTERED_COMMANDS

#ifndef AcEdCommand
#define AcEdCommand		ZcEdCommand
#endif //#ifndef AcEdCommand

#ifndef AcEdCommandIterator
#define AcEdCommandIterator		ZcEdCommandIterator
#endif //#ifndef AcEdCommandIterator

#ifndef AcEdCommandStack
#define AcEdCommandStack		ZcEdCommandStack
#endif //#ifndef AcEdCommandStack

#ifndef AcEdCommandStruc
#define AcEdCommandStruc		ZcEdCommandStruc
#endif //#ifndef AcEdCommandStruc

#ifndef AcEdUIContext
#define AcEdUIContext		ZcEdUIContext
#endif //#ifndef AcEdUIContext

#ifndef AcRxDictionary
#define AcRxDictionary		ZcRxDictionary
#endif //#ifndef AcRxDictionary

#ifndef AcRxFunctionPtr
#define AcRxFunctionPtr		ZcRxFunctionPtr
#endif //#ifndef AcRxFunctionPtr

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef acedRegCmds
#define acedRegCmds		zcedRegCmds
#endif //#ifndef acedRegCmds

#ifndef acrxSysRegistry
#define acrxSysRegistry		zcrxSysRegistry
#endif //#ifndef acrxSysRegistry

#endif //#ifndef __ACCMD_H__
