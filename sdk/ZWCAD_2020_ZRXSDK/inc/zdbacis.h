

#ifndef ZDB_API_DBACIS_H
#define ZDB_API_DBACIS_H

#include "zacdb.h"
#pragma pack (push, 8)

class ZcDbDwgFiler;
class ZcDbDxfFiler;
class AcDbObject;
class ENTITY;

extern "C"
{
	void zcdbModelerStart();
	void zcdbModelerEnd();
	ZSoft::Boolean zcdbIsModelerStarted();

	Zcad::ErrorStatus zcdbAcisSaveEntityToDwgFiler     (ZcDbDwgFiler* filer, 
		ENTITY*       ent);
	Zcad::ErrorStatus zcdbAcisRestoreEntityFromDwgFiler(ZcDbDwgFiler* filer, 
		ENTITY*&      ent);
	Zcad::ErrorStatus zcdbAcisSaveEntityToDxfFiler     (ZcDbDxfFiler* filer, 
		ENTITY*       ent); 
	Zcad::ErrorStatus zcdbAcisRestoreEntityFromDxfFiler(ZcDbDxfFiler* filer, 
		ENTITY*&      ent);

	void           zcdbAcisSetDeleteBulletins(ZSoft::Boolean onOff);
	ZSoft::Boolean zcdbAcisGetDeleteBulletins();

	ZSoft::Boolean zcdbSetAcisDwgVer(int version);

	void           zcdbAcisDeleteModelerBulletins(void);
}

enum ModelerRestoreOptions
{
	kReadForeignEntities			= 0x01,
	kReadUnknownEntities			= 0x02,
	kLoseUnknownCustomAttributes	= 0x04,
	kReadStrangerEntityDefault		= (kReadForeignEntities | kReadUnknownEntities | kLoseUnknownCustomAttributes), 
	kModelerRestoreOptionsFuture1	= 0x08,
	kModelerRestoreOptionsFuture2	= 0x10,
	kModelerRestoreOptionsFuture3	= 0x20,
	kModelerRestoreOptionsFuture4	= 0x40,
};


Zcad::ErrorStatus zcdbModelerSaveEntityToDwgFiler     (ZcDbDwgFiler* filer, 
	ENTITY*       ent,
	ZcDbDatabase* pDb,
	int modelerVersion = -1);
Zcad::ErrorStatus zcdbModelerRestoreEntityFromDwgFiler(ZcDbDwgFiler* filer, 
	ENTITY*&      ent,
	int* pModelerVersion = nullptr,
	unsigned restoreOptions = kReadStrangerEntityDefault);
Zcad::ErrorStatus zcdbModelerSaveEntityToDxfFiler     (ZcDbDxfFiler* filer, 
	ENTITY*       ent, 
	ZcDbDatabase* pDb,
	int modelerVersion = -1); 
Zcad::ErrorStatus zcdbModelerRestoreEntityFromDxfFiler(ZcDbDxfFiler* filer, 
	ENTITY*&      ent,
	int* pModelerVersion = nullptr,
	unsigned restoreOptions = kReadStrangerEntityDefault);



#pragma pack (pop)
#endif
