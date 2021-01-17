

#ifndef   _ZDBJIG_H_
#define   _ZDBJIG_H_ 1

#if defined(__cplusplus)
#ifndef _ZCDB_H
#include "zacdb.h"
#endif

#include "zdbdimdata.h"  

#pragma pack (push, 8)

class	ZcEdImpJig;
class	ZcDbEntity;

class ZcEdJig: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcEdJig);

    enum UserInputControls {
	kGovernedByOrthoMode	    = 0x0001,
	kNullResponseAccepted		= 0x0002,
	kDontEchoCancelForCtrlC		= 0x0004,
	kDontUpdateLastPoint		= 0x0008,
	kNoDwgLimitsChecking		= 0x0010,
	kNoZeroResponseAccepted		= 0x0020,
	kNoNegativeResponseAccepted	= 0x0040,
	kAccept3dCoordinates		= 0x0080,
	kAcceptMouseUpAsPoint		= 0x0100,
	kAnyBlankTerminatesInput	= 0x0200,
	kInitialBlankTerminatesInput	= 0x0400,
	kAcceptOtherInputString		= 0x0800,
    kGovernedByUCSDetect        = 0x1000,
    kNoZDirectionOrtho          = 0x2000,
	kImpliedFaceForUCSChange    = 0x4000,
	kUseBasePointElevation      = 0x8000
	};

    enum DragStatus {
        kModeless       = -17,
        kNoChange       = -6,
        kCancel         = -4,
        kOther          = -3,
        kNull           = -1,
        kNormal         = 0,
	kKW1,
	kKW2,
	kKW3,
	kKW4,
	kKW5,
	kKW6,
	kKW7,
	kKW8,
	kKW9
    };

    enum CursorType {
	kNoSpecialCursor = -1,           
	kCrosshair = 0,                  
	kRectCursor,                     
	kRubberBand,                     
	kNotRotated,                     
	kTargetBox,                      
	kRotatedCrosshair,               
	kCrosshairNoRotate,              
	kInvisible,                      
	kEntitySelect,                   
	kParallelogram,                  
	kEntitySelectNoPersp,            
	kPkfirstOrGrips,
    kCrosshairDashed
    };

    ZcEdJig();
    virtual ~ZcEdJig();

    DragStatus	drag();
    virtual DragStatus	sampler(); 
    virtual ZSoft::Boolean  update();
    ZcDbObjectId append();

    const ZTCHAR* keywordList();
    void        setKeywordList(const ZTCHAR*);

    const ZTCHAR* dispPrompt();
    void        setDispPrompt(const ZTCHAR*, ...);

    DragStatus acquireString(ZTCHAR* str);
    DragStatus acquireAngle(double &ang);
    DragStatus acquireAngle(double &ang, const ZcGePoint3d& basePnt);
    DragStatus acquireDist(double &dist);
    DragStatus acquireDist(double &dist, const ZcGePoint3d& basePnt);
    DragStatus acquirePoint(ZcGePoint3d&);
    DragStatus acquirePoint(ZcGePoint3d&, const ZcGePoint3d&basePnt);

    ZcEdJig::CursorType specialCursorType();
    void                setSpecialCursorType(CursorType);

    ZcEdJig::UserInputControls userInputControls();
    void                       setUserInputControls(ZcEdJig::UserInputControls);

    virtual ZcDbEntity* entity() const;
    virtual ZcDbDimDataPtrArray * dimData(const double dimScale);
    virtual Zcad::ErrorStatus setDimValue(const ZcDbDimData* dimData,
                                          const double dimValue); 

protected:
    ZcEdImpJig*  mpImpJig;
};

#pragma pack (pop)
#endif 
#endif
