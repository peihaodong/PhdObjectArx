

#ifndef _zappinfo_h
#define _zappinfo_h 1

#include "zacdb.h"
#include "zrxdlinkr.h"
#include "zAdAChar.h"

#pragma pack (push, 8)

class ZcadAppInfoImp;

class ZcadAppInfo: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcadAppInfo);

    enum CmdStatus {
        kNoAction    = 0,
        kRetry       = 1,
        kShowMsg     = 2,
        kNoModule    = 3
    };
#pragma warning(push)
#pragma warning(disable:4480)
	enum MgdType {
		kUnManaged   = 0,
		kManaged     = 1,
		kJavaScript  = 2
	};
#pragma warning(pop)
    typedef ZcadAppInfo::CmdStatus (*LoaderFunPtr)(void *);

    ZcadAppInfo();
    virtual ~ZcadAppInfo();

    const ZTCHAR *appName() const;
    void setAppName(const ZTCHAR *);

    const ZTCHAR *moduleName() const;
    void setModuleName(const ZTCHAR *);

    const ZTCHAR *appDesc() const;
    void setAppDesc(const ZTCHAR *);

    bool appImplements(const ZTCHAR *) const;
    
    ZcadAppInfo::MgdType managed() const;
    void setManaged(ZcadAppInfo::MgdType mgdType);

    ZcadApp::ErrorStatus writeToRegistry(bool bObjDbx = false, bool skipHKLM = false);

    ZcadApp::ErrorStatus readFromRegistry();
    ZcadApp::ErrorStatus delFromRegistry(bool bObjDbx = false);

    ZcadAppInfo::CmdStatus runAppLoader();
    void setAppLoader(LoaderFunPtr);

    ZcadApp::LoadReasons loadReason();
    void setLoadReason(ZcadApp::LoadReasons);
    ZcadApp::ErrorStatus status() const;

    ZcadApp::ErrorStatus writeGroupNameToRegistry(const ZTCHAR* group);

    ZcadApp::ErrorStatus writeCommandNameToRegistry(const ZTCHAR* globalCmdName,
                                                    const ZTCHAR* localCmdName);
    
private:
    ZcadAppInfoImp * mpImp;
};

#pragma pack (pop)

#endif 

