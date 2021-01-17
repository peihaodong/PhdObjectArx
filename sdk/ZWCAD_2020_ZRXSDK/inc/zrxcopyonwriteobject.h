
#ifndef _ZRXCOPYONWRITEOBJECT_H_H
#define _ZRXCOPYONWRITEOBJECT_H_H
#include "zacbasedefs.h"

#pragma pack(push, 8)

class ZcRxCopyOnWriteObject : public ZcRxObject
{
public:
	ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxCopyOnWriteObject, ZCBASE_PORT);

	ZCBASE_PORT ZcRxCopyOnWriteObject(ZcRxObject* pData);
	ZCBASE_PORT ZcRxCopyOnWriteObject(const ZcRxCopyOnWriteObject& other);
	ZCBASE_PORT ~ZcRxCopyOnWriteObject();
	ZCBASE_PORT const ZcRxCopyOnWriteObject& operator=(const ZcRxCopyOnWriteObject& other);

protected:
	ZCBASE_PORT ZcRxObject* write();
	ZCBASE_PORT const ZcRxObject* read() const;
	ZCBASE_PORT void unshare();

private:
	void* m_pData;
};

///////////////////////////////////////////////////////////////////////////////
// Defination of helper macros
///////////////////////////////////////////////////////////////////////////////

#define ZCRX_DECLARE_MEMBERS_READWRITE(CLASS_NAME, DATA_NAME)   \
	ZCRX_DECLARE_MEMBERS(CLASS_NAME);                           \
	DATA_NAME* write()                                          \
{                                                           \
	return (DATA_NAME*)ZcRxCopyOnWriteObject::write();      \
}                                                           \
	const DATA_NAME* read() const                           \
{                                                           \
	return (const DATA_NAME*)ZcRxCopyOnWriteObject::read(); \
}

#pragma pack(pop)

#endif //_ZRXCOPYONWRITEOBJECT_H_H
