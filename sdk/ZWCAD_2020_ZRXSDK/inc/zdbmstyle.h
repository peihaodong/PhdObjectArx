

#ifndef ZD_DBMLINESTYLE_H
#define ZD_DBMLINESTYLE_H

#include "zdbmain.h"
#include "zAdAChar.h"

#pragma pack (push, 8)

#define MSTYLE_NAME_LENGTH 32
#define MSTYLE_DESCRIPTION_LENGTH 256
#define LTYPE_LENGTH 32
#define MLINE_MAX_ELEMENTS 16

#define MIN_ANGLE (10.0 * PI / 180.0)

#define MAX_ANGLE (170.0 * PI / 180.0)

#define MSTYLE_DXF_FILL_ON           (0x1)
#define MSTYLE_DXF_SHOW_MITERS       (0x2)
#define MSTYLE_DXF_START_SQUARE_CAP  (0x10)
#define MSTYLE_DXF_START_INNER_ARCS  (0x20)
#define MSTYLE_DXF_START_ROUND_CAP   (0x40)
#define MSTYLE_DXF_END_SQUARE_CAP    (0x100)
#define MSTYLE_DXF_END_INNER_ARCS    (0x200)
#define MSTYLE_DXF_END_ROUND_CAP     (0x400)
#define MSTYLE_DXF_JUST_TOP          (0x1000)
#define MSTYLE_DXF_JUST_ZERO         (0x2000)
#define MSTYLE_DXF_JUST_BOT          (0x4000)

class ZcDbMlineStyle: public  ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbMlineStyle);
    ZcDbMlineStyle();
    virtual ~ZcDbMlineStyle();

    void              initMlineStyle();
    void              set(const ZcDbMlineStyle & src, 
                          bool checkIfReferenced = true);

    Zcad::ErrorStatus setDescription(const ZTCHAR * description);
    const ZTCHAR*       description() const;

    Zcad::ErrorStatus setName(const ZTCHAR * name);
    const ZTCHAR*       name() const;

    void              setShowMiters(bool showThem);
    bool              showMiters() const;

    void              setStartSquareCap(bool showIt);
    bool              startSquareCap() const;

    void              setStartRoundCap(bool showIt);
    bool              startRoundCap() const;

    void              setStartInnerArcs(bool showThem);
    bool              startInnerArcs() const;

    void              setEndSquareCap(bool showIt);
    bool              endSquareCap() const;

    void              setEndRoundCap(bool showIt);
    bool              endRoundCap() const;

    void              setEndInnerArcs(bool showThem);
    bool              endInnerArcs() const;

    Zcad::ErrorStatus setFillColor(const ZcCmColor& color);
    const ZcCmColor&  fillColor() const;

    void              setFilled(bool onOff);
    bool              filled() const;

    Zcad::ErrorStatus setStartAngle(double ang);
    double            startAngle() const;

    Zcad::ErrorStatus setEndAngle(double ang);
    double            endAngle() const;

    Zcad::ErrorStatus addElement(int& index, double offset,
                                 const ZcCmColor &color,
                                 ZcDbObjectId linetypeId,
                                 bool checkIfReferenced = true);
    Zcad::ErrorStatus removeElementAt(int elem);

    int numElements() const;

    Zcad::ErrorStatus setElement(int & elem, double offset,
                                 const ZcCmColor &color,
                                 ZcDbObjectId linetypeId);

    Zcad::ErrorStatus getElementAt(int elem, double& offset,
                                   ZcCmColor & color,
                                   ZcDbObjectId & linetypeId) const;

    virtual Zcad::ErrorStatus subErase     (ZSoft::Boolean pErasing = true);
    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* filer) const;

    virtual Zcad::ErrorStatus copyFrom     (const ZcRxObject* other);

};

#pragma pack (pop)

#endif
