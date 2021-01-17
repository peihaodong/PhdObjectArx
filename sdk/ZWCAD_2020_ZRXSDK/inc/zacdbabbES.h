

#ifndef _ZACDBABBES_H_H
#define _ZACDBABBES_H_H


#include "zacdb.h"
typedef Zcad::ErrorStatus       ErrorStatus;

typedef ZcDb::OpenMode          OpenMode;
typedef ZcDb::OsnapMode         OsnapMode;
typedef ZcDb::CoordAxis         CoordAxis;
typedef ZcDb::CoordSystem       CoordSystem;
typedef ZcDb::Intersect         Intersect;
typedef ZcDb::Visibility        Visibility;
typedef ZcDb::SaveType          SaveType;
typedef ZcDb::DxfCode           DxfCode;
typedef ZcDb::DwgDataType       DwgDataType;
typedef ZcDb::TextHorzMode      TextHorzMode;
typedef ZcDb::TextVertMode      TextVertMode;
typedef ZcDb::LineSpacingStyle  LineSpacingStyle;
typedef ZcDb::Planarity         Planarity;
typedef ZcDb::PointIndex        PointIndex;
typedef ZcDb::EdgeIndex         EdgeIndex;
typedef ZcDb::Poly2dType        Poly2dType;
typedef ZcDb::Poly3dType        Poly3dType;
typedef ZcDb::PolyMeshType      PolyMeshType;
typedef ZcDb::Vertex2dType      Vertex2dType;
typedef ZcDb::Vertex3dType      Vertex3dType;
typedef ZcDb::SpaceValueType    SpaceValueType;
typedef ZcDb::BoolOperType      BoolOperType;
typedef ZcDb::SubentType        SubentType;
typedef ZcDb::GeomId            GeomId;
typedef ZcDb::GeomType          GeomType;
typedef ZcDb::OrthographicView  OrthographicView;

const Zcad::ErrorStatus eOk = Zcad::eOk;
const Zcad::ErrorStatus eNotImplementedYet = Zcad::eNotImplementedYet;
const Zcad::ErrorStatus eNotApplicable = Zcad::eNotApplicable;
const Zcad::ErrorStatus eInvalidInput = Zcad::eInvalidInput;
const Zcad::ErrorStatus eAmbiguousInput = Zcad::eAmbiguousInput;
const Zcad::ErrorStatus eAmbiguousOutput = Zcad::eAmbiguousOutput;
const Zcad::ErrorStatus eOutOfMemory = Zcad::eOutOfMemory;
const Zcad::ErrorStatus eBufferTooSmall = Zcad::eBufferTooSmall;
const Zcad::ErrorStatus eInvalidOpenState = Zcad::eInvalidOpenState;
const Zcad::ErrorStatus eEntityInInactiveLayout
	= Zcad::eEntityInInactiveLayout;
const Zcad::ErrorStatus eHandleExists = Zcad::eHandleExists;
const Zcad::ErrorStatus eNullHandle = Zcad::eNullHandle;
const Zcad::ErrorStatus eBrokenHandle = Zcad::eBrokenHandle;
const Zcad::ErrorStatus eUnknownHandle = Zcad::eUnknownHandle;
const Zcad::ErrorStatus eHandleInUse = Zcad::eHandleInUse;
const Zcad::ErrorStatus eNullObjectPointer = Zcad::eNullObjectPointer;
const Zcad::ErrorStatus eNullObjectId = Zcad::eNullObjectId;
const Zcad::ErrorStatus eNullBlockName = Zcad::eNullBlockName;
const Zcad::ErrorStatus eContainerNotEmpty = Zcad::eContainerNotEmpty;
const Zcad::ErrorStatus eNullEntityPointer = Zcad::eNullEntityPointer;
const Zcad::ErrorStatus eIllegalEntityType = Zcad::eIllegalEntityType;
const Zcad::ErrorStatus eKeyNotFound = Zcad::eKeyNotFound;
const Zcad::ErrorStatus eDuplicateKey = Zcad::eDuplicateKey;
const Zcad::ErrorStatus eInvalidIndex = Zcad::eInvalidIndex;
const Zcad::ErrorStatus eDuplicateIndex = Zcad::eDuplicateIndex;
const Zcad::ErrorStatus eAlreadyInDb = Zcad::eAlreadyInDb;
const Zcad::ErrorStatus eOutOfDisk = Zcad::eOutOfDisk;
const Zcad::ErrorStatus eDeletedEntry = Zcad::eDeletedEntry;
const Zcad::ErrorStatus eNegativeValueNotAllowed 
	= Zcad::eNegativeValueNotAllowed;
const Zcad::ErrorStatus eInvalidExtents = Zcad::eInvalidExtents;
const Zcad::ErrorStatus eInvalidAdsName = Zcad::eInvalidAdsName;
const Zcad::ErrorStatus eInvalidKey = Zcad::eInvalidKey;
const Zcad::ErrorStatus eEndOfObject = Zcad::eEndOfObject;
const Zcad::ErrorStatus eEndOfFile = Zcad::eEndOfFile;
const Zcad::ErrorStatus eObjectToBeDeleted = Zcad::eObjectToBeDeleted;
const Zcad::ErrorStatus eInvalidDwgVersion = Zcad::eInvalidDwgVersion;
const Zcad::ErrorStatus eAnonymousEntry = Zcad::eAnonymousEntry;
const Zcad::ErrorStatus eIllegalReplacement = Zcad::eIllegalReplacement;
const Zcad::ErrorStatus eIsReading = Zcad::eIsReading;
const Zcad::ErrorStatus eIsWriting = Zcad::eIsWriting;
const Zcad::ErrorStatus eNotOpenForRead = Zcad::eNotOpenForRead;
const Zcad::ErrorStatus eNotOpenForWrite = Zcad::eNotOpenForWrite;
const Zcad::ErrorStatus eNotThatKindOfClass = Zcad::eNotThatKindOfClass;
const Zcad::ErrorStatus eInvalidDxfCode = Zcad::eInvalidDxfCode;
const Zcad::ErrorStatus eInvalidResBuf = Zcad::eInvalidResBuf;
const Zcad::ErrorStatus eBadDxfSequence = Zcad::eBadDxfSequence;
const Zcad::ErrorStatus eInvalidBlockName = Zcad::eInvalidBlockName;
const Zcad::ErrorStatus eMissingDxfField  = Zcad::eMissingDxfField;
const Zcad::ErrorStatus eDuplicateDxfField = Zcad::eDuplicateDxfField;
const Zcad::ErrorStatus eFilerError = Zcad::eFilerError;
const Zcad::ErrorStatus eVertexAfterFace = Zcad::eVertexAfterFace;
const Zcad::ErrorStatus eInvalidFaceVertexIndex = Zcad::eInvalidFaceVertexIndex;
const Zcad::ErrorStatus eInvalidMeshVertexIndex = Zcad::eInvalidMeshVertexIndex;
const Zcad::ErrorStatus eOtherObjectsBusy = Zcad::eOtherObjectsBusy;
const Zcad::ErrorStatus eMustFirstAddBlockToDb = Zcad::eMustFirstAddBlockToDb;
const Zcad::ErrorStatus eCannotNestBlockDefs = Zcad::eCannotNestBlockDefs;
const Zcad::ErrorStatus eDwgRecoveredOK = Zcad::eDwgRecoveredOK;
const Zcad::ErrorStatus eDwgNotRecoverable = Zcad::eDwgNotRecoverable;
const Zcad::ErrorStatus eDwgNeedsRecovery = Zcad::eDwgNeedsRecovery;
const Zcad::ErrorStatus eDeleteEntity = Zcad::eDeleteEntity;
const Zcad::ErrorStatus eInvalidFix = Zcad::eInvalidFix;
const Zcad::ErrorStatus eFSMError = Zcad::eFSMError;
const Zcad::ErrorStatus eDxfPartiallyRead = Zcad::eDxfPartiallyRead;
const Zcad::ErrorStatus eMissingSymbolTable = Zcad::eMissingSymbolTable;
const Zcad::ErrorStatus eMissingSymbolTableRec = Zcad::eMissingSymbolTableRec;
const Zcad::ErrorStatus eDwgCRCDoesNotMatch = Zcad::eDwgCRCDoesNotMatch;
const Zcad::ErrorStatus eDwgSentinelDoesNotMatch 
	= Zcad::eDwgSentinelDoesNotMatch;
const Zcad::ErrorStatus eDwgObjectImproperlyRead 
	= Zcad::eDwgObjectImproperlyRead;
const Zcad::ErrorStatus eNoInputFiler = Zcad::eNoInputFiler;
const Zcad::ErrorStatus eDwgNeedsAFullSave = Zcad::eDwgNeedsAFullSave;
const Zcad::ErrorStatus eDxfReadAborted = Zcad::eDxfReadAborted;
const Zcad::ErrorStatus eDxbPartiallyRead = Zcad::eDxbPartiallyRead;
const Zcad::ErrorStatus eDxbReadAborted = Zcad::eDxbReadAborted;
const Zcad::ErrorStatus eFileLockedByZCAD = Zcad::eFileLockedByZCAD;
const Zcad::ErrorStatus eFileAccessErr = Zcad::eFileAccessErr;
const Zcad::ErrorStatus eFileSystemErr = Zcad::eFileSystemErr;
const Zcad::ErrorStatus eFileInternalErr = Zcad::eFileInternalErr;
const Zcad::ErrorStatus eFileNotFound = Zcad::eFileNotFound;
const Zcad::ErrorStatus eDwgShareDemandLoad = Zcad::eDwgShareDemandLoad;
const Zcad::ErrorStatus eDwgShareReadAccess = Zcad::eDwgShareReadAccess;
const Zcad::ErrorStatus eDwgShareWriteAccess = Zcad::eDwgShareWriteAccess;
const Zcad::ErrorStatus eDwkLockFileFound = Zcad::eDwkLockFileFound;
const Zcad::ErrorStatus eWasErased = Zcad::eWasErased;
const Zcad::ErrorStatus eWasNotErased = Zcad::eWasNotErased;
const Zcad::ErrorStatus ePermanentlyErased = Zcad::ePermanentlyErased;
const Zcad::ErrorStatus eWasOpenForRead = Zcad::eWasOpenForRead;
const Zcad::ErrorStatus eWasOpenForWrite = Zcad::eWasOpenForWrite;
const Zcad::ErrorStatus eWasOpenForUndo = Zcad::eWasOpenForUndo;
const Zcad::ErrorStatus eWasNotifying = Zcad::eWasNotifying;
const Zcad::ErrorStatus eWasOpenForNotify = Zcad::eWasOpenForNotify;
const Zcad::ErrorStatus eOnLockedLayer = Zcad::eOnLockedLayer;
const Zcad::ErrorStatus eMustOpenThruOwner = Zcad::eMustOpenThruOwner;
const Zcad::ErrorStatus eSubentitiesStillOpen = Zcad::eSubentitiesStillOpen;
const Zcad::ErrorStatus eAtMaxReaders = Zcad::eAtMaxReaders;
const Zcad::ErrorStatus eIsWriteProtected = Zcad::eIsWriteProtected;
const Zcad::ErrorStatus eIsXRefObject = Zcad::eIsXRefObject;
const Zcad::ErrorStatus eNotAnEntity = Zcad::eNotAnEntity;
const Zcad::ErrorStatus eHadMultipleReaders = Zcad::eHadMultipleReaders;
const Zcad::ErrorStatus eWasNotOpenForWrite = Zcad::eWasNotOpenForWrite;
const Zcad::ErrorStatus eCloseWasNotifying = Zcad::eCloseWasNotifying;
const Zcad::ErrorStatus eCloseModifyAborted = Zcad::eCloseModifyAborted;
const Zcad::ErrorStatus eClosePartialFailure = Zcad::eClosePartialFailure;
const Zcad::ErrorStatus eCannotBeErasedByCaller = Zcad::eCannotBeErasedByCaller;
const Zcad::ErrorStatus eFixedAllErrors = Zcad::eFixedAllErrors;
const Zcad::ErrorStatus eLeftErrorsUnfixed = Zcad::eLeftErrorsUnfixed;
const Zcad::ErrorStatus eUnrecoverableErrors = Zcad::eUnrecoverableErrors;
const Zcad::ErrorStatus eNoDatabase = Zcad::eNoDatabase;
const Zcad::ErrorStatus eXdataSizeExceeded = Zcad::eXdataSizeExceeded;
const Zcad::ErrorStatus eRegappIdNotFound = Zcad::eRegappIdNotFound;
const Zcad::ErrorStatus eRepeatEntity = Zcad::eRepeatEntity;
const Zcad::ErrorStatus eRecordNotInTable = Zcad::eRecordNotInTable;
const Zcad::ErrorStatus eIteratorDone = Zcad::eIteratorDone;
const Zcad::ErrorStatus eNotInBlock = Zcad::eNotInBlock;
const Zcad::ErrorStatus eGeneralModelingFailure = Zcad::eGeneralModelingFailure;
const Zcad::ErrorStatus eOutOfRange = Zcad::eOutOfRange;
const Zcad::ErrorStatus eNonCoplanarGeometry = Zcad::eNonCoplanarGeometry;
const Zcad::ErrorStatus eDegenerateGeometry  = Zcad::eDegenerateGeometry;
const Zcad::ErrorStatus eOwnerNotInDatabase = Zcad::eOwnerNotInDatabase;
const Zcad::ErrorStatus eOwnerNotOpenForRead = Zcad::eOwnerNotOpenForRead;
const Zcad::ErrorStatus eOwnerNotOpenForWrite = Zcad::eOwnerNotOpenForWrite;
const Zcad::ErrorStatus eExplodeBeforeTransform = Zcad::eExplodeBeforeTransform;
const Zcad::ErrorStatus eCannotScaleNonUniformly 
	= Zcad::eCannotScaleNonUniformly;
const Zcad::ErrorStatus eNotInDatabase = Zcad::eNotInDatabase;
const Zcad::ErrorStatus eNotCurrentDatabase = Zcad::eNotCurrentDatabase;
const Zcad::ErrorStatus eIsAnEntity = Zcad::eIsAnEntity;
const Zcad::ErrorStatus eCannotChangeActiveViewport 
	= Zcad::eCannotChangeActiveViewport;
const Zcad::ErrorStatus eNotInPaperspace = Zcad::eNotInPaperspace;
const Zcad::ErrorStatus eCommandWasInProgress = Zcad::eCommandWasInProgress;
const Zcad::ErrorStatus eInvalidAxis  = Zcad::eInvalidAxis;
const Zcad::ErrorStatus ePointNotOnEntity  = Zcad::ePointNotOnEntity;
const Zcad::ErrorStatus eSingularPoint  = Zcad::eSingularPoint;
const Zcad::ErrorStatus eInvalidOffset = Zcad::eInvalidOffset;
const Zcad::ErrorStatus eStringTooLong  = Zcad::eStringTooLong;
const Zcad::ErrorStatus eNullIterator = Zcad::eNullIterator;
const Zcad::ErrorStatus eInvalidSymbolTableName = Zcad::eInvalidSymbolTableName;
const Zcad::ErrorStatus eDuplicateRecordName = Zcad::eDuplicateRecordName;
const Zcad::ErrorStatus eXRefDependent = Zcad::eXRefDependent;
const Zcad::ErrorStatus eSelfReference = Zcad::eSelfReference;
const Zcad::ErrorStatus eWrongDatabase = Zcad::eWrongDatabase;
const Zcad::ErrorStatus eWrongObjectType = Zcad::eWrongObjectType;
const Zcad::ErrorStatus eInvalidSymTableFlag = Zcad::eInvalidSymTableFlag;
const Zcad::ErrorStatus eUndefinedLineType = Zcad::eUndefinedLineType;
const Zcad::ErrorStatus eInvalidTextStyle = Zcad::eInvalidTextStyle;
const Zcad::ErrorStatus eTooFewLineTypeElements = Zcad::eTooFewLineTypeElements;
const Zcad::ErrorStatus eTooManyLineTypeElements 
	= Zcad::eTooManyLineTypeElements;
const Zcad::ErrorStatus eExcessiveItemCount = Zcad::eExcessiveItemCount;
const Zcad::ErrorStatus eIgnoredLinetypeRedef = Zcad::eIgnoredLinetypeRedef;
const Zcad::ErrorStatus eBadUCS = Zcad::eBadUCS;
const Zcad::ErrorStatus eBadPaperspaceView = Zcad::eBadPaperspaceView;
const Zcad::ErrorStatus eSomeInputDataLeftUnread=Zcad::eSomeInputDataLeftUnread;
const Zcad::ErrorStatus eNoInternalSpace=Zcad::eNoInternalSpace;
const Zcad::ErrorStatus eInvalidDimStyle = Zcad::eInvalidDimStyle;
const Zcad::ErrorStatus eInvalidLayer = Zcad::eInvalidLayer;
const Zcad::ErrorStatus eUserBreak = Zcad::eUserBreak;
const Zcad::ErrorStatus eBadLayerName = Zcad::eBadLayerName;
const Zcad::ErrorStatus eLayerGroupCodeMissing = Zcad::eLayerGroupCodeMissing;
const Zcad::ErrorStatus eBadColorIndex = Zcad::eBadColorIndex;
const Zcad::ErrorStatus eBadColor = Zcad::eBadColor;
const Zcad::ErrorStatus eBadLinetypeName = Zcad::eBadLinetypeName;
const Zcad::ErrorStatus eBadLinetypeScale = Zcad::eBadLinetypeScale;
const Zcad::ErrorStatus eBadVisibilityValue = Zcad::eBadVisibilityValue;
const Zcad::ErrorStatus eProperClassSeparatorExpected 
	= Zcad::eProperClassSeparatorExpected;
const Zcad::ErrorStatus eBadMaterialName = Zcad::eBadMaterialName;
const Zcad::ErrorStatus ePagerError = Zcad::ePagerError;
const Zcad::ErrorStatus eOutOfPagerMemory = Zcad::eOutOfPagerMemory;
const Zcad::ErrorStatus ePagerWriteError = Zcad::ePagerWriteError;
const Zcad::ErrorStatus eWasNotForwarding = Zcad::eWasNotForwarding;
const Zcad::ErrorStatus eInvalidIdMap = Zcad::eInvalidIdMap;
const Zcad::ErrorStatus eInvalidOwnerObject = Zcad::eInvalidOwnerObject;
const Zcad::ErrorStatus eOwnerNotSet = Zcad::eOwnerNotSet;
const Zcad::ErrorStatus eNoActiveTransactions = Zcad::eNoActiveTransactions; 
const Zcad::ErrorStatus eNotTopTransaction = Zcad::eNotTopTransaction; 
const Zcad::ErrorStatus eTransactionOpenWhileCommandEnded 
	= Zcad::eTransactionOpenWhileCommandEnded;
const Zcad::ErrorStatus eInProcessOfCommitting 
	= Zcad::eInProcessOfCommitting;
const Zcad::ErrorStatus eNotNewlyCreated = Zcad::eNotNewlyCreated;
const Zcad::ErrorStatus eLongTransReferenceError 
	= Zcad::eLongTransReferenceError;
const Zcad::ErrorStatus eNoWorkSet = Zcad::eNoWorkSet;
const Zcad::ErrorStatus eAlreadyInGroup = Zcad::eAlreadyInGroup;
const Zcad::ErrorStatus eNotInGroup = Zcad::eNotInGroup;
const Zcad::ErrorStatus eWrongSubentityType = Zcad::eWrongSubentityType;
const Zcad::ErrorStatus eInvalidStyle = Zcad::eInvalidStyle;
const Zcad::ErrorStatus eCannotRestoreFromAcisFile 
	= Zcad::eCannotRestoreFromAcisFile;
const Zcad::ErrorStatus eNonPlanarEntity = Zcad::eNonPlanarEntity;
const Zcad::ErrorStatus eCannotExplodeEntity = Zcad::eCannotExplodeEntity;
const Zcad::ErrorStatus ePolyWidthLost = Zcad::ePolyWidthLost;
const Zcad::ErrorStatus eNullExtents = Zcad::eNullExtents;

const Zcad::ErrorStatus eLockViolation = Zcad::eLockViolation;
const Zcad::ErrorStatus eLockConflict = Zcad::eLockConflict;
const Zcad::ErrorStatus eDatabaseObjectsOpen = Zcad::eDatabaseObjectsOpen;
const Zcad::ErrorStatus eLockChangeInProgress = Zcad::eLockChangeInProgress;

const Zcad::ErrorStatus eVetoed = Zcad::eVetoed;
const Zcad::ErrorStatus eXrefReloaded = Zcad::eXrefReloaded;
const Zcad::ErrorStatus eXrefReloadImpossibleAtThisTime = Zcad::eXrefReloadImpossibleAtThisTime;

const Zcad::ErrorStatus eNoDocument = Zcad::eNoDocument;
const Zcad::ErrorStatus eNotFromThisDocument = Zcad::eNotFromThisDocument;
const Zcad::ErrorStatus eLISPActive = Zcad::eLISPActive;
const Zcad::ErrorStatus eTargetDocNotQuiescent = Zcad::eTargetDocNotQuiescent;
const Zcad::ErrorStatus eDocumentSwitchDisabled = Zcad::eDocumentSwitchDisabled;
const Zcad::ErrorStatus eInvalidContext = Zcad::eInvalidContext;

const Zcad::ErrorStatus eProfileDoesNotExist = Zcad::eProfileDoesNotExist;
const Zcad::ErrorStatus eInvalidFileExtension= Zcad::eInvalidFileExtension;
const Zcad::ErrorStatus eInvalidProfileName  = Zcad::eInvalidProfileName;
const Zcad::ErrorStatus eFileExists          = Zcad::eFileExists;     
const Zcad::ErrorStatus eProfileIsInUse      = Zcad::eProfileIsInUse;
const Zcad::ErrorStatus eCantOpenFile        = Zcad::eCantOpenFile;
const Zcad::ErrorStatus eNoFileName          = Zcad::eNoFileName;
const Zcad::ErrorStatus eRegistryAccessError = Zcad::eRegistryAccessError;
const Zcad::ErrorStatus eRegistryCreateError = Zcad::eRegistryCreateError;

const Zcad::ErrorStatus eBadDxfFile = Zcad::eBadDxfFile;
const Zcad::ErrorStatus eUnknownDxfFileFormat = Zcad::eUnknownDxfFileFormat;
const Zcad::ErrorStatus eMissingDxfSection = Zcad::eMissingDxfSection;
const Zcad::ErrorStatus eInvalidDxfSectionName = Zcad::eInvalidDxfSectionName;
const Zcad::ErrorStatus eNotDxfHeaderGroupCode = Zcad::eNotDxfHeaderGroupCode;
const Zcad::ErrorStatus eUndefinedDxfGroupCode = Zcad::eUndefinedDxfGroupCode;
const Zcad::ErrorStatus eNotInitializedYet = Zcad::eNotInitializedYet;
const Zcad::ErrorStatus eInvalidDxf2dPoint = Zcad::eInvalidDxf2dPoint;
const Zcad::ErrorStatus eInvalidDxf3dPoint = Zcad::eInvalidDxf3dPoint;
const Zcad::ErrorStatus eBadlyNestedAppData  = Zcad::eBadlyNestedAppData;
const Zcad::ErrorStatus eIncompleteBlockDefinition = Zcad::eIncompleteBlockDefinition;
const Zcad::ErrorStatus eIncompleteComplexObject = Zcad::eIncompleteComplexObject;
const Zcad::ErrorStatus eBlockDefInEntitySection = Zcad::eBlockDefInEntitySection;
const Zcad::ErrorStatus eNoBlockBegin = Zcad::eNoBlockBegin;
const Zcad::ErrorStatus eDuplicateLayerName = Zcad::eDuplicateLayerName;
const Zcad::ErrorStatus eDuplicateBlockName = Zcad::eDuplicateBlockName;
const Zcad::ErrorStatus eBadPlotStyleName = Zcad::eBadPlotStyleName;
const Zcad::ErrorStatus eBadPlotStyleType = Zcad::eBadPlotStyleType;
const Zcad::ErrorStatus eBadPlotStyleNameHandle = Zcad::eBadPlotStyleNameHandle;
const Zcad::ErrorStatus eUndefineShapeName = Zcad::eUndefineShapeName;
const Zcad::ErrorStatus eDuplicateBlockDefinition = Zcad::eDuplicateBlockDefinition;
const Zcad::ErrorStatus eMissingBlockName = Zcad::eMissingBlockName;
const Zcad::ErrorStatus eBinaryDataSizeExceeded = Zcad::eBinaryDataSizeExceeded;
const Zcad::ErrorStatus eHatchTooDense = Zcad::eHatchTooDense;

const Zcad::ErrorStatus eUndoOperationNotAvailable = Zcad::eUndoOperationNotAvailable;
const Zcad::ErrorStatus eUndoNoGroupBegin = Zcad::eUndoNoGroupBegin;

const Zcad::ErrorStatus eObjectIsReferenced = Zcad::eObjectIsReferenced;
const Zcad::ErrorStatus eNoThumbnailBitmap = Zcad::eNoThumbnailBitmap;
const Zcad::ErrorStatus eGuidNoAddress = Zcad::eGuidNoAddress;
const Zcad::ErrorStatus eNoPlotStyleTranslationTable = Zcad::eNoPlotStyleTranslationTable;

const Zcad::ErrorStatus ePlotStyleInColorDependentMode = Zcad::ePlotStyleInColorDependentMode;
const Zcad::ErrorStatus eNoClassId = Zcad::eNoClassId;
const Zcad::ErrorStatus eMaxLayouts = Zcad::eMaxLayouts;

const Zcad::ErrorStatus eWrongCellType = Zcad::eWrongCellType;
const Zcad::ErrorStatus eCannotChangeColumnType = Zcad::eCannotChangeColumnType;
const Zcad::ErrorStatus eRowsMustMatchColumns = Zcad::eRowsMustMatchColumns;

const Zcad::ErrorStatus eNullNodeId = Zcad::eNullNodeId;
const Zcad::ErrorStatus eNoNodeActive = Zcad::eNoNodeActive;
const Zcad::ErrorStatus eGraphContainsProxies = Zcad::eGraphContainsProxies;

const Zcad::ErrorStatus eLoadFailed = Zcad::eLoadFailed;
const Zcad::ErrorStatus eDeviceNotFound = Zcad::eDeviceNotFound;
const Zcad::ErrorStatus eNoCurrentConfig = Zcad::eNoCurrentConfig;
const Zcad::ErrorStatus eNullPtr = Zcad::eNullPtr;
const Zcad::ErrorStatus eNoLayout = Zcad::eNoLayout;
const Zcad::ErrorStatus eIncompatiblePlotSettings = Zcad::eIncompatiblePlotSettings;
const Zcad::ErrorStatus eNonePlotDevice = Zcad::eNonePlotDevice;
const Zcad::ErrorStatus eNoMatchingMedia = Zcad::eNoMatchingMedia;
const Zcad::ErrorStatus eInvalidView = Zcad::eInvalidView;
const Zcad::ErrorStatus eInvalidWindowArea = Zcad::eInvalidWindowArea;
const Zcad::ErrorStatus eInvalidPlotArea = Zcad::eInvalidPlotArea;
const Zcad::ErrorStatus eCustomSizeNotPossible = Zcad::eCustomSizeNotPossible;

const Zcad::ErrorStatus ePageCancelled = Zcad::ePageCancelled;
const Zcad::ErrorStatus ePlotCancelled = Zcad::ePlotCancelled;
const Zcad::ErrorStatus eInvalidEngineState = Zcad::eInvalidEngineState;
const Zcad::ErrorStatus ePlotAlreadyStarted = Zcad::ePlotAlreadyStarted;
const Zcad::ErrorStatus eNoErrorHandler = Zcad::eNoErrorHandler;
const Zcad::ErrorStatus eInvalidPlotInfo = Zcad::eInvalidPlotInfo;
const Zcad::ErrorStatus eNumberOfCopiesNotSupported = Zcad::eNumberOfCopiesNotSupported;
const Zcad::ErrorStatus eLayoutNotCurrent = Zcad::eLayoutNotCurrent;
const Zcad::ErrorStatus eGraphicsNotGenerated = Zcad::eGraphicsNotGenerated;
const Zcad::ErrorStatus eCannotPlotToFile = Zcad::eCannotPlotToFile;
const Zcad::ErrorStatus eMustPlotToFile = Zcad::eMustPlotToFile;
const Zcad::ErrorStatus eBackgroundPlotInProgress = Zcad::eBackgroundPlotInProgress;

const Zcad::ErrorStatus eInvalidObjectId = Zcad::eInvalidObjectId;
const Zcad::ErrorStatus eInvalidXrefObjectId = Zcad::eInvalidXrefObjectId;
const Zcad::ErrorStatus eNoViewAssociation = Zcad::eNoViewAssociation;
const Zcad::ErrorStatus eNoLabelBlock = Zcad::eNoLabelBlock;
const Zcad::ErrorStatus eUnableToSetViewAssociation = Zcad::eUnableToSetViewAssociation;
const Zcad::ErrorStatus eUnableToGetViewAssociation = Zcad::eUnableToGetViewAssociation;
const Zcad::ErrorStatus eUnableToSetLabelBlock = Zcad::eUnableToSetLabelBlock;
const Zcad::ErrorStatus eUnableToGetLabelBlock = Zcad::eUnableToGetLabelBlock;
const Zcad::ErrorStatus eUnableToRemoveAssociation = Zcad::eUnableToRemoveAssociation;
const Zcad::ErrorStatus eUnableToSyncModelView = Zcad::eUnableToSyncModelView;

const Zcad::ErrorStatus eSubSelectionSetEmpty = Zcad::eSubSelectionSetEmpty;
const Zcad::ErrorStatus eGraphEdgeNotFound = Zcad::eGraphEdgeNotFound;
const Zcad::ErrorStatus eGraphNodeNotFound = Zcad::eGraphNodeNotFound;
const Zcad::ErrorStatus eGraphNodeAlreadyExists = Zcad::eGraphNodeAlreadyExists;
const Zcad::ErrorStatus eGraphEdgeAlreadyExists = Zcad::eGraphEdgeAlreadyExists;
const Zcad::ErrorStatus eGraphCyclesFound = Zcad::eGraphCyclesFound;

const Zcad::ErrorStatus eAlreadyHasRepresentation =
	Zcad::eAlreadyHasRepresentation;
const Zcad::ErrorStatus eNoRepresentation = Zcad::eNoRepresentation;
const Zcad::ErrorStatus eNoIntersections = Zcad::eNoIntersections;
const Zcad::ErrorStatus eEmbeddedIntersections = Zcad::eEmbeddedIntersections;

const Zcad::ErrorStatus eFailedToSetEdgeChamfers = Zcad::eFailedToSetEdgeChamfers;
const Zcad::ErrorStatus eNoCoectedBlendSet = Zcad::eNoConnectedBlendSet;
const Zcad::ErrorStatus eFailedToBlend = Zcad::eFailedToBlend;
const Zcad::ErrorStatus eFailedToSetEdgeRounds = Zcad::eFailedToSetEdgeRounds;

const Zcad::ErrorStatus eFailedToSetVertexRounds = Zcad::eFailedToSetVertexRounds;
const Zcad::ErrorStatus eFailedToEvaluate = Zcad::eFailedToEvaluate;
const Zcad::ErrorStatus eFailedToEvaluateDependents = Zcad::eFailedToEvaluateDependents;
const Zcad::ErrorStatus eInvalidExpression = Zcad::eInvalidExpression;
const Zcad::ErrorStatus eCyclicDependency = Zcad::eCyclicDependency;
const Zcad::ErrorStatus eInconsistentConstraint = Zcad::eInconsistentConstraint;
const Zcad::ErrorStatus eOverDefinedConstraint = Zcad::eOverDefinedConstraint;
const Zcad::ErrorStatus eInvalidParameterName = Zcad::eInvalidParameterName;
const Zcad::ErrorStatus eReferencedInEquation = Zcad::eReferencedInEquation;

const Zcad::ErrorStatus eStringNotAllowedInExpression = Zcad::eStringNotAllowedInExpression;
const Zcad::ErrorStatus eTooManyActiveCommands = Zcad::eTooManyActiveCommands;

const Zcad::ErrorStatus eUnableToTrimLastPiece = Zcad::eUnableToTrimLastPiece;
const Zcad::ErrorStatus eUnableToTrimSurface = Zcad::eUnableToTrimSurface;

const Zcad::ErrorStatus eModifyingAssociativeEntity = Zcad::eModifyingAssociativeEntity;
const Zcad::ErrorStatus eModifyingDimensionWithExpression = Zcad::eModifyingDimensionWithExpression;

const Zcad::ErrorStatus eDependentOnObjectErased = Zcad::eDependentOnObjectErased;
const Zcad::ErrorStatus eSelfIntersecting = Zcad::eSelfIntersecting;
const Zcad::ErrorStatus eNotOnBoundary = Zcad::eNotOnBoundary;
const Zcad::ErrorStatus eNotConnected = Zcad::eNotConnected;
const Zcad::ErrorStatus eNoInputPath = Zcad::eNoInputPath;
const Zcad::ErrorStatus eNotAssociative = Zcad::eNotAssociative;
const Zcad::ErrorStatus eNotG1Continuous = Zcad::eNotG1Continuous;

const Zcad::ErrorStatus eChangedAgainstAssociativity = Zcad::eChangedAgainstAssociativity;

#endif 