#ifndef ZC_BRGBLABB_H
#define ZC_BRGBLABB_H 1

#include "zacadstrc.h"
#include "zcbrgbl.h"


typedef ZcBr::ErrorStatus		ZcBrErrorStatus;
typedef ZcBr::Relation			ZcBrRelation;
typedef ZcBr::Element2dShape	ZcBrElement2dShape;
typedef ZcBr::LoopType			ZcBrLoopType;
typedef ZcBr::ValidationLevel	ZcBrValidationLevel;
typedef ZcBr::ShellType			ZcBrShellType;


const ZcBrErrorStatus	eOk					= ZcBr::eOk;
const ZcBrErrorStatus	eNotImplementedYet	= ZcBr::eNotImplementedYet;
const ZcBrErrorStatus	eNotApplicable		= ZcBr::eNotApplicable;
const ZcBrErrorStatus	eInvalidInput		= ZcBr::eInvalidInput;
const ZcBrErrorStatus	eOutOfMemory		= ZcBr::eOutOfMemory;
const ZcBrErrorStatus	eNullObjectPointer	= ZcBr::eNullObjectPointer;
const ZcBrErrorStatus	eWrongObjectType	= ZcBr::eWrongObjectType;
const ZcBrErrorStatus	eWrongSubentityType	= ZcBr::eWrongSubentityType;
const ZcBrErrorStatus	eBrepChanged		= ZcBr::eBrepChanged;
const ZcBrErrorStatus	eNullObjectId		= ZcBr::eNullObjectId;
const ZcBrErrorStatus	eNullSubentityId	= ZcBr::eNullSubentityId;
const ZcBrErrorStatus	eObjectIdMismatch	= ZcBr::eObjectIdMismatch;
const ZcBrErrorStatus	eTopologyMismatch	= ZcBr::eTopologyMismatch;
const ZcBrErrorStatus	eUnsuitableTopology	= ZcBr::eUnsuitableTopology;
const ZcBrErrorStatus	eUnsuitableGeometry	= ZcBr::eUnsuitableGeometry;
const ZcBrErrorStatus	eMissingGeometry	= ZcBr::eMissingGeometry;
const ZcBrErrorStatus	eMissingSubentity	= ZcBr::eMissingSubentity;
const ZcBrErrorStatus	eInvalidObject		= ZcBr::eInvalidObject;
const ZcBrErrorStatus	eAmbiguousOutput	= ZcBr::eAmbiguousOutput;
const ZcBrErrorStatus	eDegenerateTopology	= ZcBr::eDegenerateTopology;
const ZcBrErrorStatus	eUninitialisedObject = ZcBr::eUninitialisedObject;


#endif
