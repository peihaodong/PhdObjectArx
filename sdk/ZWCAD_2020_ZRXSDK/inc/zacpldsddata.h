

#ifndef ZCPLDSDDATA_H
#define ZCPLDSDDATA_H

#pragma once

#include "zacpl.h"
#include "zacplobject.h"
#include "zacpldsdentry.h"
#include "zacarray.h"

typedef ZcArray<ZcPlDSDEntry, ZcArrayObjectCopyReallocator <ZcPlDSDEntry> > ZcPlDSDEntries;

struct ZcPl3dDwfOptions {
    bool  bGroupByXrefHierarchy;
    bool  bPublishWithMaterials;
};

class ZcPlDSDData  : public ZcPlObject
{
    ZCPL_DECLARE_MEMBERS(ZcPlDSDData)

public:

    ZCPL_PORT ZcPlDSDData();

    ZCPL_PORT virtual ~ZcPlDSDData();

    ZCPL_PORT ZcPlDSDData(const ZcPlDSDData & src);

    ZCPL_PORT ZcPlDSDData& operator= (const ZcPlDSDData &src);

    ZCPL_PORT const ZTCHAR *      projectPath() const;
    ZCPL_PORT void              setProjectPath(const ZTCHAR * pVal);

    ZCPL_PORT const ZTCHAR *      destinationName() const;
    ZCPL_PORT void              setDestinationName(const ZTCHAR * pVal);

    ZCPL_PORT void              getDSDEntries(ZcPlDSDEntries &val) const;
    ZCPL_PORT void              setDSDEntries(const ZcPlDSDEntries &val);

    ZCPL_PORT int               numberOfDSDEntries() const;
    ZCPL_PORT ZcPlDSDEntry&     DSDEntryAt(int idx);

    ZCPL_PORT ZcPlDSDEntry::SheetType sheetType() const;
    ZCPL_PORT void                    setSheetType(ZcPlDSDEntry::SheetType val);

    ZCPL_PORT const ZTCHAR *      password() const;
    ZCPL_PORT void              setPassword(const ZTCHAR * pVal);

    ZCPL_PORT void              getUnrecognizedData(
                                    ZcArray<ZTCHAR*> &sectionArray,
                                    ZcArray<ZTCHAR*> &dataArray) const;
    ZCPL_PORT void              setUnrecognizedData(
                                    const ZcArray<ZTCHAR*> &sectionArray,
                                    const ZcArray<ZTCHAR*> &dataArray);
    ZCPL_PORT void              setUnrecognizedData(
                                    const ZTCHAR * pSectionName,
                                    const ZTCHAR * pSectionData);
    
    ZCPL_PORT unsigned int      majorVersion() const;
    ZCPL_PORT void              setMajorVersion(unsigned int majorVersion);

    ZCPL_PORT unsigned int      minorVersion() const;
    ZCPL_PORT void              setMinorVersion(unsigned int minorVersion);

    ZCPL_PORT const ZTCHAR *      sheetSetName() const;
    ZCPL_PORT void              setSheetSetName(const ZTCHAR * pSheetSetName);

    ZCPL_PORT unsigned int      noOfCopies() const;
    ZCPL_PORT void              setNoOfCopies(unsigned int copies);

    ZCPL_PORT void              setIsSheetSet(bool bSheetSet);
    ZCPL_PORT bool              isSheetSet() const;

    ZCPL_PORT bool              isHomogeneous() const;
    ZCPL_PORT void              setIsHomogeneous(bool bHomogeneous);
    
    ZCPL_PORT bool              plotStampOn() const;
    ZCPL_PORT void              setPlotStampOn(bool bOn);

    ZCPL_PORT const ZTCHAR *      selectionSetName() const;
    ZCPL_PORT void              setSelectionSetName(const ZTCHAR * pSelSetName);

    ZCPL_PORT const ZTCHAR *      categoryName() const;
    ZCPL_PORT void              setCategoryName(const ZTCHAR * pCategoryName);

    ZCPL_PORT const ZTCHAR *      logFilePath() const;
    ZCPL_PORT void              setLogFilePath(const ZTCHAR * pLogFilePath);

    ZCPL_PORT const ZcPl3dDwfOptions&   get3dDwfOptions() const;
    ZCPL_PORT void              set3dDwfOptions(const ZcPl3dDwfOptions &val);

    ZCPL_PORT bool              readDSD(const ZTCHAR *pName);
    ZCPL_PORT bool              writeDSD(const ZTCHAR *pName);

    ZCPL_PORT bool              includeLayerInfo() const;
    ZCPL_PORT void              setIncludeLayerInfo(bool bOn);
    
    ZCPL_PORT bool              promptForDwfName() const;
    ZCPL_PORT void              setPromptForDwfName(bool bPromptForDwfName);

    ZCPL_PORT bool              pwdProtectPublishedDWF() const;
    ZCPL_PORT void              setPwdProtectPublishedDWF(
                                bool bPwdProtectPublishedDWF);

    ZCPL_PORT bool              promptForPassword() const;
    ZCPL_PORT void              setPromptForPassword(bool bPromptForPassword);
};

#endif 
