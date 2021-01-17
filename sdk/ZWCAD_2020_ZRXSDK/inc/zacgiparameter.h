

#ifndef _ZACGIPARAMETER_H_H
#define _ZACGIPARAMETER_H_H


#include "zrxcopyonwriteobject.h"

#pragma pack(push, 8)

class ZcGiParameterImp;

class ZCDB_PORT ZcGiParameter : public ZcRxCopyOnWriteObject
{
	friend class ZcGiParameterImp;

public:
	ZCRX_DECLARE_MEMBERS_READWRITE(ZcGiParameter, ZcGiParameterImp);

	ZcGiParameter(ZcGiParameterImp* pImp);
	ZcGiParameter(const ZcGiParameter& other);
	const ZcGiParameter& operator=(const ZcGiParameter& other);
};

#pragma pack(pop)

#endif //_ZACGIPARAMETER_H_H