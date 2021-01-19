#include "stdafx.h"
#include "PhdArxXRecord.h"

bool Phd::PhdArxXRecord::SetXRecordOfNameDictionary(LPCTSTR szDictinaryName, LPCTSTR szRecordName,
	double dValue, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	//获得该数据库的有名对象字典
	AcDbDictionary* pNameObjectDict = nullptr;
	auto es = pDb->getNamedObjectsDictionary(pNameObjectDict, AcDb::kForWrite);
	if (Acad::eOk != es)
		return false;
	AcDbDictionaryPointer apNameObjectDict;
	apNameObjectDict.acquire(pNameObjectDict);

	//检查所要添加的字典项是否已经存在
	AcDbDictionary* pDict = nullptr;
	if (apNameObjectDict->getAt(szDictinaryName, (AcDbObject*&)pDict, AcDb::kForWrite)
		== Acad::eKeyNotFound)
	{
		//新建一个字典
		pDict = new AcDbDictionary;
		AcDbObjectId idDictObj;
		apNameObjectDict->setAt(szDictinaryName, pDict, idDictObj);
	}
	AcDbDictionaryPointer apDict;
	apDict.acquire(pDict);

	//创建扩展记录实体
	AcDbXrecord* pXRec = new AcDbXrecord;
	AcDbObjectPointer<AcDbXrecord> apXRec;
	apXRec.acquire(pXRec);

	//向字典中添加一条记录
	AcDbObjectId idXRec;
	es = apDict->setAt(szRecordName, apXRec, idXRec);
	if (es != Acad::eOk)
		return false;

	//设置扩展记录的内容
	resbuf* pRb = acutBuildList(AcDb::kDxfReal, dValue, RTNONE);
	es = apXRec->setFromRbChain(*pRb);

	//释放 结构体缓冲区
	acutRelRb(pRb);

	if (es != Acad::eOk)
		return false;

	return true;
}

bool Phd::PhdArxXRecord::GetXRecordOfNameDictionary(LPCTSTR szDictinaryName, LPCTSTR szRecordName,
	double& dValue, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	//获得该数据库的有名对象字典
	AcDbDictionary* pNameObjectDict = nullptr;
	auto es = pDb->getNamedObjectsDictionary(pNameObjectDict, AcDb::kForRead);
	if (Acad::eOk != es)
		return false;
	AcDbDictionaryPointer apNameObjectDict;
	apNameObjectDict.acquire(pNameObjectDict);

	//获得对象有名字典中指定的字典项
	AcDbDictionary* pDict = nullptr;
	es = apNameObjectDict->getAt(szDictinaryName, (AcDbObject*&)pDict, AcDb::kForRead);
	if (es != Acad::eOk)
		return false;
	AcDbDictionaryPointer apDict;
	apDict.acquire(pDict);

	//获得指定的对象字典中的对象
	AcDbXrecord* pXRec = nullptr;
	if (apDict->getAt(szRecordName, (AcDbObject*&)pXRec, AcDb::kForRead) != Acad::eOk)
		return false;
	AcDbObjectPointer<AcDbXrecord> apXRec;
	apXRec.acquire(pXRec);

	//获得数据信息
	resbuf* pRb = nullptr;
	apXRec->rbChain(&pRb);
	if (!pRb)
		return false;
	resbuf* pRbTemp = pRb;
	dValue = pRbTemp->resval.rreal;

	acutRelRb(pRb);
	return true;
}
