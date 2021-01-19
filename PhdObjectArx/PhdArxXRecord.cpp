#include "stdafx.h"
#include "PhdArxXRecord.h"

bool Phd::PhdArxXRecord::SetXRecordOfNameDictionary(LPCTSTR szDictinaryName, LPCTSTR szRecordName,
	double dValue, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	//��ø����ݿ�����������ֵ�
	AcDbDictionary* pNameObjectDict = nullptr;
	auto es = pDb->getNamedObjectsDictionary(pNameObjectDict, AcDb::kForWrite);
	if (Acad::eOk != es)
		return false;
	AcDbDictionaryPointer apNameObjectDict;
	apNameObjectDict.acquire(pNameObjectDict);

	//�����Ҫ��ӵ��ֵ����Ƿ��Ѿ�����
	AcDbDictionary* pDict = nullptr;
	if (apNameObjectDict->getAt(szDictinaryName, (AcDbObject*&)pDict, AcDb::kForWrite)
		== Acad::eKeyNotFound)
	{
		//�½�һ���ֵ�
		pDict = new AcDbDictionary;
		AcDbObjectId idDictObj;
		apNameObjectDict->setAt(szDictinaryName, pDict, idDictObj);
	}
	AcDbDictionaryPointer apDict;
	apDict.acquire(pDict);

	//������չ��¼ʵ��
	AcDbXrecord* pXRec = new AcDbXrecord;
	AcDbObjectPointer<AcDbXrecord> apXRec;
	apXRec.acquire(pXRec);

	//���ֵ������һ����¼
	AcDbObjectId idXRec;
	es = apDict->setAt(szRecordName, apXRec, idXRec);
	if (es != Acad::eOk)
		return false;

	//������չ��¼������
	resbuf* pRb = acutBuildList(AcDb::kDxfReal, dValue, RTNONE);
	es = apXRec->setFromRbChain(*pRb);

	//�ͷ� �ṹ�建����
	acutRelRb(pRb);

	if (es != Acad::eOk)
		return false;

	return true;
}

bool Phd::PhdArxXRecord::GetXRecordOfNameDictionary(LPCTSTR szDictinaryName, LPCTSTR szRecordName,
	double& dValue, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	//��ø����ݿ�����������ֵ�
	AcDbDictionary* pNameObjectDict = nullptr;
	auto es = pDb->getNamedObjectsDictionary(pNameObjectDict, AcDb::kForRead);
	if (Acad::eOk != es)
		return false;
	AcDbDictionaryPointer apNameObjectDict;
	apNameObjectDict.acquire(pNameObjectDict);

	//��ö��������ֵ���ָ�����ֵ���
	AcDbDictionary* pDict = nullptr;
	es = apNameObjectDict->getAt(szDictinaryName, (AcDbObject*&)pDict, AcDb::kForRead);
	if (es != Acad::eOk)
		return false;
	AcDbDictionaryPointer apDict;
	apDict.acquire(pDict);

	//���ָ���Ķ����ֵ��еĶ���
	AcDbXrecord* pXRec = nullptr;
	if (apDict->getAt(szRecordName, (AcDbObject*&)pXRec, AcDb::kForRead) != Acad::eOk)
		return false;
	AcDbObjectPointer<AcDbXrecord> apXRec;
	apXRec.acquire(pXRec);

	//���������Ϣ
	resbuf* pRb = nullptr;
	apXRec->rbChain(&pRb);
	if (!pRb)
		return false;
	resbuf* pRbTemp = pRb;
	dValue = pRbTemp->resval.rreal;

	acutRelRb(pRb);
	return true;
}
