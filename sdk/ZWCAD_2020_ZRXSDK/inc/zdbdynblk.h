
#pragma once

#include "zdbeval.h"
#include "zAcString.h"

#pragma pack (push, 8)

class ZcDbDynBlockReference;
class ZcDbDynBlockReferenceProperty;
class ZcDbImpDynBlockReference;
class ZcDbImpDynBlockReferenceProperty;
class ZcDbImpDynBlockTableRecord;

class ZcDbDynBlockReferenceProperty : public ZcHeapOperators
{
public:
    enum UnitsType {
        kNoUnits = 0,
        kAngular,
        kDistance,
        kArea
    };
    ZcDbDynBlockReferenceProperty ();
    virtual ~ZcDbDynBlockReferenceProperty ();
    ZcDbDynBlockReferenceProperty (const ZcDbDynBlockReferenceProperty& other);
    ZcDbDynBlockReferenceProperty& operator=(
            const ZcDbDynBlockReferenceProperty& other);
    ZcDbObjectId          blockId() const;
    ZcString              propertyName ()   const;
    ZcDb::DwgDataType	  propertyType ()  const;
    bool                  readOnly ()       const;
    bool                  show ()           const;
    ZcString              description ()    const;
    UnitsType             unitsType () const;
    Zcad::ErrorStatus     getAllowedValues(ZcDbEvalVariantArray& values);
    ZcDbEvalVariant       value () const;
    Zcad::ErrorStatus     setValue (const ZcDbEvalVariant& value);

	bool operator==(const ZcDbDynBlockReferenceProperty& other);
private:

    ZcDbImpDynBlockReferenceProperty* mpImp;
    friend class ZcDbImpDynBlockReferenceProperty;
    friend class ZcDbImpDynBlockReference;
};

typedef ZcArray<ZcDbDynBlockReferenceProperty,
        ZcArrayObjectCopyReallocator<ZcDbDynBlockReferenceProperty> >
             ZcDbDynBlockReferencePropertyArray;

class ZcDbDynBlockReference : public ZcHeapOperators
{
public:
    ZcDbDynBlockReference(ZcDbObjectId blockRefId);
    ZcDbDynBlockReference(ZcDbBlockReference* pRef);
    virtual ~ZcDbDynBlockReference ();
    static bool       isDynamicBlock (ZcDbObjectId blockTableRecordId);
    bool              isDynamicBlock () const;
    ZcDbObjectId blockId() const;
    void              getBlockProperties (
                        ZcDbDynBlockReferencePropertyArray& properties) const;
    Zcad::ErrorStatus resetBlock ();
    Zcad::ErrorStatus convertToStaticBlock ();
    Zcad::ErrorStatus convertToStaticBlock (const ZcString& newBlockName);
    ZcDbObjectId      dynamicBlockTableRecord () const;
    ZcDbObjectId      anonymousBlockTableRecord () const;

private:
    ZcDbDynBlockReference();

    ZcDbImpDynBlockReference* mpImp;
};

#pragma pack (pop)

