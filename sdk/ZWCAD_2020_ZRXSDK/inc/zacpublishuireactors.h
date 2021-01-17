
#ifndef _ZCPUBLISHUIREACTORS_H
#define _ZCPUBLISHUIREACTORS_H

#include "zAdAChar.h"
#include "zAcPublishReactors.h"
#include "zrxobject.h"
#include "zacarray.h"
#include "zacpldsddata.h"
#include "zAcPublishReactors.h"

class ZcPublishUIReactorInfo
{
public:
    ZcPublishUIReactorInfo() {};
    virtual ~ZcPublishUIReactorInfo() {};
    virtual const ZcPlDSDData * GetDSDData() = 0;
    virtual const ZcNameValuePairVec
        GetPrivateData(const ZTCHAR * sectionName) = 0;
    virtual bool WritePrivateSection(const ZTCHAR * sectionName,
        const ZcNameValuePairVec nameValuePairVec) = 0;
    virtual bool JobWillPublishInBackground() = 0;
};

class ZcPublishUIReactor : public ZcRxObject
{
public:
    virtual void OnInitPublishOptionsDialog(IUnknown **pUnk,
                                            ZcPublishUIReactorInfo *pInfo);
	virtual void OnInitExportOptionsDialog(IUnknown **pUnk, ZcPublishUIReactorInfo *pInfo);

	virtual void PersistenceRegistryForExportOptionsDialog(const ZTCHAR* lpszRegRoot, bool bIsReadRegistry = true);

	virtual void OnInitAutoPublishSettingsDialog(IUnknown **pUnk, ZcPublishUIReactorInfo *pInfo);

	virtual void PersistenceRegistryForAutoPublishDialog(const ZTCHAR* lpszRegRoot,	bool bIsReadRegistry = true);

    virtual ~ZcPublishUIReactor() {};

protected:
    ZcPublishUIReactor() {};
};

inline void
ZcPublishUIReactor::OnInitPublishOptionsDialog(IUnknown **pUnk,
                                               ZcPublishUIReactorInfo *pInfo)
{
};


inline 
void ZcPublishUIReactor::OnInitExportOptionsDialog(IUnknown **pUnk, ZcPublishUIReactorInfo *pInfo)
{
}

inline 
void ZcPublishUIReactor::PersistenceRegistryForExportOptionsDialog(const ZTCHAR* lpszRegRoot, bool bIsReadRegistry)
{
}

inline 
void ZcPublishUIReactor::OnInitAutoPublishSettingsDialog(IUnknown **pUnk, ZcPublishUIReactorInfo *pInfo)
{
}

inline 
void ZcPublishUIReactor::PersistenceRegistryForAutoPublishDialog(const ZTCHAR* lpszRegRoot, bool bIsReadRegistry)
{
}

void ZcGlobAddPublishUIReactor(ZcPublishUIReactor *pReactor);

void ZcGlobRemovePublishUIReactor(ZcPublishUIReactor *pReactor);

typedef void (__cdecl * ZCGLOBADDPUBLISHUIREACTOR)(ZcPublishUIReactor * pReactor);
typedef void (__cdecl * ZCGLOBREMOVEPUBLISHUIREACTOR)(ZcPublishUIReactor * pReactor);
#endif

