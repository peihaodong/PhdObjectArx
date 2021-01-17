

#ifndef   _ZCPROFILE_H__
#define   _ZCPROFILE_H__

#include "zacarray.h"
#include "zAdAChar.h"
#pragma pack (push, 8)

class ZcApProfileStorage;

class ZcApProfileManagerReactor 
{
public:
    virtual void currentProfileWillChange(const ZTCHAR *newProfile);
    virtual void currentProfileChanged(const ZTCHAR *newProfile);
    virtual void currentProfileWillBeReset(const ZTCHAR *currentProfile);
    virtual void currentProfileReset(const ZTCHAR *currentProfile);
    virtual void currentProfileWillBeSaved(const ZTCHAR *currentProfile);
    virtual void currentProfileSaved(const ZTCHAR *currentProfile);
    virtual void profileWillReset(const ZTCHAR *profileName);
    virtual void profileReset(const ZTCHAR *profileName);
    virtual void profileWillBeSaved(const ZTCHAR *profileName);
    virtual void profileSaved(const ZTCHAR *profileName);
    virtual ~ZcApProfileManagerReactor() {}
};

typedef ZcArray<ZTCHAR *> ZcApProfileNameArray;

class ZcApProfileManager 
{
    public:
		virtual ~ZcApProfileManager() { };

        virtual void ProfileRegistryKey(ZTCHAR *& strRegProfileKey,
                                        const ZTCHAR * strProfileName)=0;

        virtual Zcad::ErrorStatus ProfileStorage(ZcApProfileStorage*& pStore, 	
                                        const ZTCHAR * strProfileName,
                                        BOOL bCreateIfNotExists = TRUE)=0;
        virtual Zcad::ErrorStatus FixedProfileStorage(ZcApProfileStorage*& pStore, 	
                                        BOOL bCreateIfNotExists = TRUE)=0;

        virtual int ProfileListNames(ZcApProfileNameArray& nameList)=0;

        virtual Zcad::ErrorStatus ProfileExport(const ZTCHAR * strProfileName,
                                                const ZTCHAR * exportFileName)=0;

        virtual Zcad::ErrorStatus ProfileImport(const ZTCHAR * strProfileName,
                                                const ZTCHAR * importFileName,
                                                const ZTCHAR * profileDescription,
                                                ZSoft::Boolean bImportPathInfo)=0; 

        virtual Zcad::ErrorStatus ProfileDelete(const ZTCHAR * strProfileName)=0;

        virtual Zcad::ErrorStatus ProfileReset(const ZTCHAR * strProfileName)=0;

        virtual Zcad::ErrorStatus ProfileSetCurrent(const ZTCHAR * strProfileName)=0;

        virtual Zcad::ErrorStatus ProfileCopy(const ZTCHAR * newProfileName,
                                              const ZTCHAR * oldProfileName,
                                              const ZTCHAR * newProfileDesc)=0;

        virtual Zcad::ErrorStatus ProfileRename(const ZTCHAR * newProfileName,
                                                const ZTCHAR * oldProfileName,
                                                const ZTCHAR * newProfileDesc)=0;

        virtual void addReactor(ZcApProfileManagerReactor* ) = 0;
        virtual void removeReactor(ZcApProfileManagerReactor* ) = 0;

};

ZcApProfileManager* zcProfileManagerPtr();
#define zcProfileManager zcProfileManagerPtr()
class ZcString;
class ZcApProfileStorage
{
    public:
        virtual ~ZcApProfileStorage() {}
        virtual Zcad::ErrorStatus CreateNode(const ZTCHAR * pszNodePath,
            IUnknown*& pUnknown) = 0;
        virtual Zcad::ErrorStatus GetNode(const ZTCHAR * pszNodePath,
            IUnknown*& pUnknown) = 0;
        virtual Zcad::ErrorStatus ReplaceNode(const ZTCHAR * pszNodePath,
            IUnknown* pUnknown) = 0;
        virtual Zcad::ErrorStatus DeleteNode(const ZTCHAR * pszNodePath) = 0;
        virtual Zcad::ErrorStatus GetStorageFile(ZcString& pszFile) = 0;
        virtual Zcad::ErrorStatus Save(void) = 0;
};

#pragma pack (pop)
#endif 
