

#ifndef _ZCFILEDEPMGR_H
#define _ZCFILEDEPMGR_H

#pragma pack(push, 8)

class ZcFileDependencyInfo {
    public:
        const ZTCHAR *mpFullFileName;
        const ZTCHAR *mpFileName;
        const ZTCHAR *mpFoundPath;
        const ZTCHAR *mpFingerprintGuid;
        const ZTCHAR *mpVersionGuid;
        const ZTCHAR *mpFeature;
        bool        mIsModified;
        bool        mAffectsGraphics;
        ZSoft::Int32         mIndex;
        ZSoft::Int32         mTimeStamp;
        ZSoft::Int32         mFileSize;
        ZSoft::Int32         mReferenceCount;
};

class ZSOFT_NO_VTABLE ZcFileDependencyManager {
    public:
        virtual ~ZcFileDependencyManager() {};

        virtual ZSoft::Int32  createEntry(const ZTCHAR *feature,
                                 const ZTCHAR *fullFileName,
                                 const bool affectsGraphics = false,
                                 const bool noIncrement = false) = 0;

        virtual Zcad::ErrorStatus getEntry(const ZTCHAR *feature,
                                           const ZTCHAR *fullFileName,
                                           ZcFileDependencyInfo *&fileInfo, 
                                           const bool useCachedInfo = false) = 0;

        virtual Zcad::ErrorStatus getEntry(const ZSoft::Int32  index,
                                           ZcFileDependencyInfo *&fileInfo, 
                                           const bool useCachedInfo = false) = 0;

        virtual Zcad::ErrorStatus updateEntry(const ZTCHAR *feature,
                                              const ZTCHAR *fullFileName) = 0;
                                      
        virtual Zcad::ErrorStatus updateEntry(const ZSoft::Int32  index) = 0;

        virtual Zcad::ErrorStatus eraseEntry(const ZTCHAR *feature,
                                             const ZTCHAR *fullFileName,
                                             const bool forceRemove=false) = 0;
                                      
        virtual Zcad::ErrorStatus eraseEntry(const ZSoft::Int32  index,
                                             const bool forceRemove=false) = 0;

        virtual ZSoft::Int32  countEntries() = 0;

        virtual void iteratorInitialize(const ZTCHAR *feature = NULL,
                                        const bool modifiedOnly = false,
                                        const bool affectsGraphicsOnly = false,
                                        const bool walkXRefTree = false) = 0;

        virtual ZSoft::Int32  iteratorNext() = 0;
};

#pragma pack(pop)

#endif
