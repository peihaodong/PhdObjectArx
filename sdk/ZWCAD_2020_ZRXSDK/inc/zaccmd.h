

#ifndef   _ZCCMD_H
#define   _ZCCMD_H

#include "zadesk.h"
#include "zAdAChar.h"


#define ZCRX_CMD_MODAL  	0x00000000
#define ZCRX_CMD_TRANSPARENT	0x00000001
#define ZCRX_CMD_USEPICKSET	0x00000002
#define ZCRX_CMD_REDRAW	        0x00000004
#define ZCRX_CMD_NOPERSPECTIVE     0x00000008 
#define ZCRX_CMD_NOMULTIPLE     0x00000010
#define ZCRX_CMD_NOTILEMODE     0x00000020  
#define ZCRX_CMD_NOPAPERSPACE   0x00000040  
#define ZCRX_CMD_PLOTONLY       0x00000080  
#define ZCRX_CMD_NOOEM          0x00000100
#define ZCRX_CMD_UNDEFINED      0x00000200
#define ZCRX_CMD_INPROGRESS     0x00000400
#define ZCRX_CMD_DEFUN          0x00000800
#define ZCRX_CMD_NONEWSTACK     0x00010000  
#define ZCRX_CMD_NOINTERNALLOCK 0x00020000
#define ZCRX_CMD_DOCREADLOCK       0x00080000  
#define ZCRX_CMD_DOCEXCLUSIVELOCK  0x00100000  
#define ZCRX_CMD_SESSION           0x00200000 
#define ZCRX_CMD_INTERRUPTIBLE	   0x00400000 
                                              
#define ZCRX_CMD_NOHISTORY	   0x00800000 
#define ZCRX_CMD_NO_UNDO_MARKER    0x01000000
#define ZCRX_CMD_NOBEDIT        0x02000000
#define ZCRX_MAX_CMDNAME_LEN  	64

#define ZCRX_COMMAND_DOCK  	ZCRX_T("ZCAD_REGISTERED_COMMANDS")

typedef void (*ZcRxFunctionPtr) ();

#ifdef _ZSOFT_WINDOWS_
#include <wtypes.h>   
#endif

#pragma pack (push, 8)
class ZcEdCommand;

struct ZcEdCommandStruc {
    ZcRxFunctionPtr fcnAddr;
    long            flags;
    void	        *app;
    HINSTANCE       hResHandle;

	ZcEdCommand		*cmd;
};
#pragma pack (pop)

#if defined(__cplusplus)

#include "zdbmain.h"
#include "zrxobject.h"

class ZcRxDictionary;
class ZcEdUIContext;

#pragma pack (push, 8)
class ZcEdCommand: public ZcRxObject 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcEdCommand);

    virtual void            commandUndef(bool undefIt) = 0;
    virtual ZSoft::Int32    commandFlags() const = 0;
    virtual ZcRxFunctionPtr functionAddr() const = 0;
    virtual void            functionAddr(ZcRxFunctionPtr fhdl) = 0;
    virtual void            *commandApp() const = 0;
    virtual ZcEdUIContext   *UIContext() const = 0;
    virtual int             functionCode() const = 0;
    virtual void            functionCode(int fcode) = 0;

    virtual const ZTCHAR *   globalName() const = 0;
    virtual const ZTCHAR *   localName() const = 0;

    virtual const HINSTANCE resourceHandle() const = 0;

};

class ZcEdCommandIterator: public ZcRxObject 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcEdCommandIterator);

    virtual bool               done() const = 0;
    virtual bool               next() = 0;
    virtual const ZcEdCommand* command() const = 0;
    virtual const ZTCHAR *      commandGroup() const = 0;
};

#define zcedRegCmds \
ZcEdCommandStack::cast(zcrxSysRegistry()->at(ZCRX_COMMAND_DOCK))

class ZcEdCommandStack: public ZcRxObject 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcEdCommandStack);

    virtual bool              atPut(const ZTCHAR * cmdGroupName,
                                    ZcRxDictionary*& cmdsGlobal,
                                    ZcRxDictionary*& cmdsLocal) = 0;

    virtual Zcad::ErrorStatus addCommand(const ZTCHAR * cmdGroupName,
                                         const ZTCHAR * cmdGlobalName,
                                         const ZTCHAR * cmdLocalName,
                                         ZSoft::Int32 commandFlags,
                                         ZcRxFunctionPtr FunctionAddr,
                                         ZcEdUIContext *UIContext=NULL,
                                         int fcode=-1,
                                         HINSTANCE hResourceHandle=NULL,
                                         ZcEdCommand** cmdPtrRet=NULL) = 0;

    virtual ZcEdCommandIterator* iterator() = 0;

    virtual ZcEdCommand* lookupGlobalCmd(const ZTCHAR * cmdName) = 0;
    virtual ZcEdCommand* lookupLocalCmd(const ZTCHAR * cmdName) = 0;
    virtual ZcEdCommand* lookupCmd(const ZTCHAR * cmdName,
                                   bool globalFlag) = 0;
    virtual ZcEdCommand* lookupCmd(const ZTCHAR * cmdName,
                                   bool globalFlag,
                                   bool allGroupsFlag) = 0;
    virtual ZcEdCommand* lookupCmd(const ZTCHAR * cmdName,
                                   bool globalFlag,
                                   bool allGroupsFlag,
                                   bool skipUndefed) = 0;
    virtual ZcEdCommand* lookupCmd2(const ZTCHAR * cmdName,
                                   bool globalFlag,
                                   bool allGroupsFlag,
                                   int skipFlags,
                                   bool match = false) = 0;

    virtual Zcad::ErrorStatus popGroupToTop(const ZTCHAR * cmdGroupName) = 0;

    virtual Zcad::ErrorStatus removeCmd(const ZTCHAR * cmdGroupName,
                                        const ZTCHAR * cmdGlobalName) = 0;

    virtual Zcad::ErrorStatus removeGroup(const ZTCHAR * groupName) = 0;

};

#pragma pack (pop)
#endif 
#endif
