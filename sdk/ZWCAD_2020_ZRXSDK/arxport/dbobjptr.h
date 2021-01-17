
#ifndef __DBOBJPTR_H__
#define __DBOBJPTR_H__

#include <assert.h>
#include "dbsymtb.h"

#include "../inc/zdbobjptr.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbBlockTable
#define AcDbBlockTable		ZcDbBlockTable
#endif //#ifndef AcDbBlockTable

#ifndef AcDbBlockTablePointer
#define AcDbBlockTablePointer		ZcDbBlockTablePointer
#endif //#ifndef AcDbBlockTablePointer

#ifndef AcDbBlockTableRecord
#define AcDbBlockTableRecord		ZcDbBlockTableRecord
#endif //#ifndef AcDbBlockTableRecord

#ifndef AcDbBlockTableRecordPointer
#define AcDbBlockTableRecordPointer		ZcDbBlockTableRecordPointer
#endif //#ifndef AcDbBlockTableRecordPointer

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbDictionary
#define AcDbDictionary		ZcDbDictionary
#endif //#ifndef AcDbDictionary

#ifndef AcDbDictionaryPointer
#define AcDbDictionaryPointer		ZcDbDictionaryPointer
#endif //#ifndef AcDbDictionaryPointer

#ifndef AcDbDimStyleTable
#define AcDbDimStyleTable		ZcDbDimStyleTable
#endif //#ifndef AcDbDimStyleTable

#ifndef AcDbDimStyleTablePointer
#define AcDbDimStyleTablePointer		ZcDbDimStyleTablePointer
#endif //#ifndef AcDbDimStyleTablePointer

#ifndef AcDbDimStyleTableRecord
#define AcDbDimStyleTableRecord		ZcDbDimStyleTableRecord
#endif //#ifndef AcDbDimStyleTableRecord

#ifndef AcDbDimStyleTableRecordPointer
#define AcDbDimStyleTableRecordPointer		ZcDbDimStyleTableRecordPointer
#endif //#ifndef AcDbDimStyleTableRecordPointer

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbEntityPointer
#define AcDbEntityPointer		ZcDbEntityPointer
#endif //#ifndef AcDbEntityPointer

#ifndef AcDbLayerTable
#define AcDbLayerTable		ZcDbLayerTable
#endif //#ifndef AcDbLayerTable

#ifndef AcDbLayerTablePointer
#define AcDbLayerTablePointer		ZcDbLayerTablePointer
#endif //#ifndef AcDbLayerTablePointer

#ifndef AcDbLayerTableRecord
#define AcDbLayerTableRecord		ZcDbLayerTableRecord
#endif //#ifndef AcDbLayerTableRecord

#ifndef AcDbLayerTableRecordPointer
#define AcDbLayerTableRecordPointer		ZcDbLayerTableRecordPointer
#endif //#ifndef AcDbLayerTableRecordPointer

#ifndef AcDbLinetypeTable
#define AcDbLinetypeTable		ZcDbLinetypeTable
#endif //#ifndef AcDbLinetypeTable

#ifndef AcDbLinetypeTablePointer
#define AcDbLinetypeTablePointer		ZcDbLinetypeTablePointer
#endif //#ifndef AcDbLinetypeTablePointer

#ifndef AcDbLinetypeTableRecord
#define AcDbLinetypeTableRecord		ZcDbLinetypeTableRecord
#endif //#ifndef AcDbLinetypeTableRecord

#ifndef AcDbLinetypeTableRecordPointer
#define AcDbLinetypeTableRecordPointer		ZcDbLinetypeTableRecordPointer
#endif //#ifndef AcDbLinetypeTableRecordPointer

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectPointer
#define AcDbObjectPointer		ZcDbObjectPointer
#endif //#ifndef AcDbObjectPointer

#ifndef AcDbObjectPointerBase
#define AcDbObjectPointerBase		ZcDbObjectPointerBase
#endif //#ifndef AcDbObjectPointerBase

#ifndef AcDbRegAppTable
#define AcDbRegAppTable		ZcDbRegAppTable
#endif //#ifndef AcDbRegAppTable

#ifndef AcDbRegAppTablePointer
#define AcDbRegAppTablePointer		ZcDbRegAppTablePointer
#endif //#ifndef AcDbRegAppTablePointer

#ifndef AcDbRegAppTableRecord
#define AcDbRegAppTableRecord		ZcDbRegAppTableRecord
#endif //#ifndef AcDbRegAppTableRecord

#ifndef AcDbRegAppTableRecordPointer
#define AcDbRegAppTableRecordPointer		ZcDbRegAppTableRecordPointer
#endif //#ifndef AcDbRegAppTableRecordPointer

#ifndef AcDbSymbolTablePointer
#define AcDbSymbolTablePointer		ZcDbSymbolTablePointer
#endif //#ifndef AcDbSymbolTablePointer

#ifndef AcDbSymbolTableRecordPointer
#define AcDbSymbolTableRecordPointer		ZcDbSymbolTableRecordPointer
#endif //#ifndef AcDbSymbolTableRecordPointer

#ifndef AcDbTextStyleTable
#define AcDbTextStyleTable		ZcDbTextStyleTable
#endif //#ifndef AcDbTextStyleTable

#ifndef AcDbTextStyleTablePointer
#define AcDbTextStyleTablePointer		ZcDbTextStyleTablePointer
#endif //#ifndef AcDbTextStyleTablePointer

#ifndef AcDbTextStyleTableRecord
#define AcDbTextStyleTableRecord		ZcDbTextStyleTableRecord
#endif //#ifndef AcDbTextStyleTableRecord

#ifndef AcDbTextStyleTableRecordPointer
#define AcDbTextStyleTableRecordPointer		ZcDbTextStyleTableRecordPointer
#endif //#ifndef AcDbTextStyleTableRecordPointer

#ifndef AcDbUCSTable
#define AcDbUCSTable		ZcDbUCSTable
#endif //#ifndef AcDbUCSTable

#ifndef AcDbUCSTablePointer
#define AcDbUCSTablePointer		ZcDbUCSTablePointer
#endif //#ifndef AcDbUCSTablePointer

#ifndef AcDbUCSTableRecord
#define AcDbUCSTableRecord		ZcDbUCSTableRecord
#endif //#ifndef AcDbUCSTableRecord

#ifndef AcDbUCSTableRecordPointer
#define AcDbUCSTableRecordPointer		ZcDbUCSTableRecordPointer
#endif //#ifndef AcDbUCSTableRecordPointer

#ifndef AcDbViewTable
#define AcDbViewTable		ZcDbViewTable
#endif //#ifndef AcDbViewTable

#ifndef AcDbViewTablePointer
#define AcDbViewTablePointer		ZcDbViewTablePointer
#endif //#ifndef AcDbViewTablePointer

#ifndef AcDbViewTableRecord
#define AcDbViewTableRecord		ZcDbViewTableRecord
#endif //#ifndef AcDbViewTableRecord

#ifndef AcDbViewTableRecordPointer
#define AcDbViewTableRecordPointer		ZcDbViewTableRecordPointer
#endif //#ifndef AcDbViewTableRecordPointer

#ifndef AcDbViewportTable
#define AcDbViewportTable		ZcDbViewportTable
#endif //#ifndef AcDbViewportTable

#ifndef AcDbViewportTablePointer
#define AcDbViewportTablePointer		ZcDbViewportTablePointer
#endif //#ifndef AcDbViewportTablePointer

#ifndef AcDbViewportTableRecord
#define AcDbViewportTableRecord		ZcDbViewportTableRecord
#endif //#ifndef AcDbViewportTableRecord

#ifndef AcDbViewportTableRecordPointer
#define AcDbViewportTableRecordPointer		ZcDbViewportTableRecordPointer
#endif //#ifndef AcDbViewportTableRecordPointer

#ifndef AcDbAnnotationScaleView
#define AcDbAnnotationScaleView	ZcDbAnnotationScaleView
#endif //AcDbAnnotationScaleView

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef acdbOpenObject
#define acdbOpenObject		zcdbOpenObject
#endif //#ifndef acdbOpenObject

#endif //#ifndef __DBOBJPTR_H__
