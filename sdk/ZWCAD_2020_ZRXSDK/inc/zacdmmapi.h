

#ifndef _ZCDMMAPI_H
#define _ZCDMMAPI_H

#include "zAdAChar.h"
#include "zacdmmeplotproperty.h"
#include "zacdmmeplotproperties.h"
#include "zacdmmutils.h"
#include "zacplplotlogger.h"
#include "zAc3dDwfNavTree.h"

class ZcDMMSheetReactorInfo
{
public:
    enum PlotArea {
        kDisplay = 0,
        kExtents = 1,
        kLimits = 2,
        kView,
        kWindow,
        kLayout
    };
    enum PlotRotation {
        k0degrees,
        k90degrees,
        k180degrees,
        k270degrees
    };
    enum PlotMediaUnits {
        kInches,
        kMillimeters,
        kPixels
    };
    virtual ZcPlPlotLogger * GetPlotLogger() = 0;
    virtual ZcDbDatabase* database()      const = 0;
    virtual bool    isPlotJobCancelled()    const = 0;
    virtual void AddPageProperties(ZcDMMEPlotPropertyVec props) = 0;
    virtual void AddPageResources(ZcDMMResourceVec resources) = 0;
    virtual const ZTCHAR * UniqueLayoutId() = 0;
    virtual ZcDbObjectId   plotLayoutId()           const = 0;
    virtual bool           isModelLayout()          const = 0;
    virtual PlotArea plotArea() const = 0;
    virtual PlotRotation plotRotation() const = 0;
    virtual PlotMediaUnits plotMediaUnits() const = 0;
    virtual double paperScale()                     const = 0;
    virtual double drawingScale()                   const = 0;
    virtual double originX()                        const = 0;
    virtual double originY()                        const = 0;
    virtual double plotWindowMinX()                 const = 0;
    virtual double plotWindowMinY()                 const = 0;
    virtual double plotWindowMaxX()                 const = 0;
    virtual double plotWindowMaxY()                 const = 0;
    virtual const TCHAR*  viewPlotted()             const = 0;
    virtual bool isScaleSpecified()                 const = 0;
    virtual bool areLinesHidden()                   const = 0;
    virtual bool arePlottingLineWeights()           const = 0;
    virtual bool areScalingLineWeights()            const = 0;
    virtual double displayMinX()                    const = 0;
    virtual double displayMinY()                    const = 0;
    virtual double displayMaxX()                    const = 0;
    virtual double displayMaxY()                    const = 0;
    virtual double layoutMarginMinX()               const = 0;
    virtual double layoutMarginMinY()               const = 0;
    virtual double layoutMarginMaxX()               const = 0;
    virtual double layoutMarginMaxY()               const = 0;
    virtual double printableBoundsX()               const = 0;
    virtual double printableBoundsY()               const = 0;
    virtual double maxBoundsX()                     const = 0;
    virtual double maxBoundsY()                     const = 0;
    virtual double stepsPerInch()                  const = 0;
    virtual const TCHAR* configuration()            const = 0;
    virtual const TCHAR* plotToFilePath()           const = 0;
    virtual const TCHAR* plotToFileName()           const = 0;
    virtual const TCHAR* canonicalMediaName()       const = 0;
    virtual double plotBoundsMinX()                 const = 0;
    virtual double plotBoundsMinY()                 const = 0;
    virtual double plotBoundsMaxX()                 const = 0;
    virtual double plotBoundsMaxY()                 const = 0;
    virtual double layoutBoundsMinX()               const = 0;
    virtual double layoutBoundsMinY()               const = 0;
    virtual double layoutBoundsMaxX()               const = 0;
    virtual double layoutBoundsMaxY()               const = 0;
    virtual double effectivePlotOffsetX()           const = 0;
    virtual double effectivePlotOffsetY()           const = 0;
    virtual int    effectivePlotOffsetXdevice()     const = 0;
    virtual int    effectivePlotOffsetYdevice()     const = 0;
    virtual bool    publishingTo3DDwf()     const = 0;
    virtual bool set3dDwfNavigationTreeNode(const Zc3dDwfNavTreeNode* root) = 0;
    virtual Zc3dDwfNavTreeNode* get3dDwfNavigationTreeNode() = 0;

public:
    virtual ~ZcDMMSheetReactorInfo() {};

protected:
    ZcDMMSheetReactorInfo() {};
};

class ZcDMMEntityReactorInfo
{
public:
    virtual bool isCancelled()    const = 0;
    virtual const wchar_t * UniqueEntityId() = 0;
    virtual ZcDbEntity* entity()             const = 0;
    virtual ZcDbObjectId effectiveBlockLayerId()  const = 0;
    virtual bool GetCurrentEntityNode(ZcDMMNode & node, ZcDbObjectIdArray objIds) const = 0;
    virtual int GetNextAvailableNodeId() const = 0;
    virtual bool GetEntityNode(ZcDbObjectId id, ZcDbObjectIdArray objIds,
        int & nodeId) const = 0;
    virtual const ZcDMMNode * GetNode(int nodeId) const = 0;
    virtual ZcPlPlotLogger * GetPlotLogger() = 0;
    virtual bool SetCurrentNode(int nodeId, ZcDbObjectIdArray objIds) = 0;
    virtual bool SetNodeName(int nodeNumber, const wchar_t *name) = 0;
    virtual bool AddProperties(const ZcDMMEPlotProperties * props) = 0;
    virtual bool AddPropertiesIds(ZcDMMStringVec * IdVec, ZcDMMNode & node) = 0;
    virtual void flush()      = 0;
    virtual void cancelTheJob()        = 0;
    virtual bool AddNodeToMap(ZcDbObjectId Id, ZcDbObjectIdArray objIds, int nodeId) = 0;
    virtual bool add3DDwfProperty(const wchar_t* category, const wchar_t* name, const wchar_t* value) = 0;
	virtual bool add3DDwfAttribute(const wchar_t* category, const wchar_t* name, const wchar_t* ns, 
		const wchar_t* nsUrl, const wchar_t* attName, const wchar_t* attVal) = 0;

    virtual const ZcArray<long>& getGraphicIDs() = 0;
    virtual const ZcDbObjectIdArray& getEntityBlockRefPath() = 0;

public:
    virtual ~ZcDMMEntityReactorInfo() {};

protected:
    ZcDMMEntityReactorInfo() {};
};

class ZcDMMReactor : public ZcRxObject
{
public:
    virtual void OnBeginSheet(ZcDMMSheetReactorInfo * pInfo);
    virtual void OnBeginEntity(ZcDMMEntityReactorInfo * pInfo);
    virtual void OnEndEntity(ZcDMMEntityReactorInfo * pInfo);
    virtual void OnEndSheet(ZcDMMSheetReactorInfo * pInfo);
    virtual ~ZcDMMReactor() {};

protected:
    ZcDMMReactor() {};
};

inline void ZcDMMReactor::OnBeginSheet(ZcDMMSheetReactorInfo * pInfo) {};
inline void ZcDMMReactor::OnBeginEntity(ZcDMMEntityReactorInfo * pInfo) {};
inline void ZcDMMReactor::OnEndEntity(ZcDMMEntityReactorInfo * pInfo) {};
inline void ZcDMMReactor::OnEndSheet(ZcDMMSheetReactorInfo * pInfo) {};

void ZcGlobAddDMMReactor(ZcDMMReactor * pReactor);

void ZcGlobRemoveDMMReactor(ZcDMMReactor * pReactor);

typedef void (__cdecl *ZCGLOBADDDMMREACTOR)(ZcDMMReactor * pReactor);
typedef void (__cdecl *ZCGLOBREMOVEDMMREACTOR)(ZcDMMReactor * pReactor);

#endif 
