#include "StdAfx.h"
#include "PhdSelSet.h"

#pragma region �ڲ�����
resbuf* Callback(const TCHAR* szKword)
{
	if (_tcsicmp(szKword, _T("Scale")) == 0)
	{
		acutPrintf(_T("\n�ؼ���Scale"));
		//�ָ�
// 		double dCurHeight = g_TrdIni.GetJxtjHeight();	��ȡ�����ļ�����
// 		double dNewHeight = 40;
// 		if (PubFunc::GetDouble(_T("ָ������"), dCurHeight, dNewHeight))		�û�������������
// 		{
// 			g_TrdIni.SetJxtjHeight(dNewHeight);	���������ļ�����
// 		}
	}
	else if (_tcsicmp(szKword, _T("Number")) == 0)
	{
		acutPrintf(_T("\n�ؼ���Number"));
		//��ʼ���
// 		int nCurNumber = g_TrdIni.GetJxtjNumber();	��ȡ�����ļ�����
// 		int nNewNumber = 1;
// 		if (PubFunc::GetInt(_T("ָ����ʼ���"), nCurNumber, nNewNumber))	�û�������������
// 		{
// 			g_TrdIni.SetJxtjNumber(nNewNumber);	���������ļ�����
// 		}
	}
	else
		acutPrintf(_T("\n������ؼ��֣�"));

	return NULL;
}


#pragma endregion

AcDbObjectIdArray PhdSelSet::SelEntsByFilter(resbuf* pRb)
{
	assert(pRb);

	AcDbObjectIdArray arridSels;
	ads_name ssname;
	int nRet = acedSSGet(_T("X"), NULL, NULL, pRb, ssname);
	acutRelRb(pRb);	//�ͷŽ��������

	//����ѡ��
	long lLength = 0;
	acedSSLength(ssname, &lLength);
	if (lLength == 0)
		return arridSels;
	for (int i = 0; i < lLength; i++)
	{
		ads_name name;
		acedSSName(ssname, i, name);
		AcDbObjectId id;
		acdbGetObjectId(id, name);	//ads_nameתAcDbObjectId
		arridSels.append(id);
	}
	acedSSFree(ssname);//�ͷ�ѡ��

	return arridSels;
}

bool PhdSelSet::SelEnts(LPCTSTR szPrompt, resbuf* pRb, AcDbObjectIdArray& arrid)
{
	assert(pRb);

	CString strPrompt;
	strPrompt.Format(_T("%s��"), szPrompt);
	TCHAR* szRealPrompt = strPrompt.GetBuffer();	//��CString����תΪ�ַ���ָ��
	ads_name ssname;
	TCHAR* promptPtrs[2] = { szRealPrompt, TEXT("ѡ��ɾ������") };
	int nRet = acedSSGet(_T(":$"), promptPtrs, NULL, pRb, ssname);
	if (RTNORM != nRet)
	{
		acutRelRb(pRb);//�ͷŽ������������
		return false;
	}

	arrid.removeAll();

	//����ѡ��;
	long lLen = 0;
	acedSSLength(ssname, &lLen);
	for (long index = 0; index < lLen; index++)
	{
		ads_name ent;
		acedSSName(ssname, index, ent);
		AcDbObjectId objId;
		acdbGetObjectId(objId, ent);
		arrid.append(objId);
	}

	acutRelRb(pRb);//�ͷŽ������������	
	acedSSFree(ssname);	// �ͷ�ѡ��;

	return true;
}

bool PhdSelSet::SelEnts(LPCTSTR szPrompt, AcDbObjectIdArray& arrid)
{
	CString strPrompt;
	strPrompt.Format(_T("%s��"), szPrompt);
	TCHAR* szRealPrompt = strPrompt.GetBuffer();	//��CString����תΪ�ַ���ָ��
	ads_name ssname;
	TCHAR* promptPtrs[2] = { szRealPrompt, TEXT("ѡ��ɾ������") };
	int nRet = acedSSGet(_T(":$"), promptPtrs, NULL, NULL, ssname);
	if (RTNORM != nRet)
		return false;

	arrid.removeAll();

	//����ѡ��;
	long lLen = 0;
	acedSSLength(ssname, &lLen);
	for (long index = 0; index < lLen; index++)
	{
		ads_name ent;
		acedSSName(ssname, index, ent);
		AcDbObjectId objId;
		acdbGetObjectId(objId, ent);
		arrid.append(objId);
	}

	acedSSFree(ssname);	// �ͷ�ѡ��;

	return true;
}

AcDbObjectIdArray PhdSelSet::GetAreaEnts(const AcGePoint3d& ptMin, const AcGePoint3d& ptMax)
{
	AcDbObjectIdArray arrid;
	ads_name ssname;
	int nRet = acedSSGet(_T("C"), asDblArray(ptMin), asDblArray(ptMax), NULL, ssname);
	if (RTNORM != nRet)
		return arrid;

	//����ѡ��;
	long lLen = 0;
	acedSSLength(ssname, &lLen);
	for (long index = 0; index < lLen; index++)
	{
		ads_name ent;
		acedSSName(ssname, index, ent);
		AcDbObjectId objId;
		acdbGetObjectId(objId, ent);
		arrid.append(objId);
	}

	acedSSFree(ssname);	// �ͷ�ѡ��;
	return arrid;
}

bool PhdSelSet::SelEnts(LPCTSTR szPrompt, resbuf* pRb, const std::vector<SKey>& vecKey, AcDbObjectIdArray& arrid)
{
	/*
	TCHAR kwordlist[] = { _T("Scale Prefix Dot Number Thickness _ Scale Prefix Dot Number Thickness") };
	TCHAR* promptPtrs[2] = { _T("ѡȡҪͳ�Ƶľ���[����(S)/ǰ׺(P)/С��λ(D)/��ʼ���(N)/���(T)]<�˳�>��"),
		TEXT("ѡ��ɾ������") };
	int nRet = acedSSGet(_T("_+.:?:$:K"), promptPtrs, kwordlist, rb, ssname);
	*/

	assert(pRb);
	if (vecKey.size() == 0)
		return false;

	//����map����
	CString strKeys;
	CString strLetterKey;
	for (int i = 0; i < vecKey.size(); i++)
	{
		CString strText = vecKey[i].m_strName;
		CString strKey = vecKey[i].m_strValue;
		CString strK = strKey.GetAt(0);
		CString strTemp;
		strTemp.Format(_T("/%s(%s)"), strText, strK);
		strKeys += strTemp;
		strTemp.Format(_T("%s "), strKey);
		strLetterKey += strTemp;
	}
// 	std::map<CString, CString>::const_iterator iter;
// 	for (iter = mapKeys.begin(); iter != mapKeys.end(); iter++)
// 	{
// 		CString strText = iter->first;
// 		CString strKey = iter->second;
// 		CString strK = strKey.GetAt(0);
// 		CString strTemp;
// 		strTemp.Format(_T("/%s(%s)"),strText, strK);
// 		strKeys += strTemp;
// 		strTemp.Format(_T("%s "),strKey);
// 		strLetterKey += strTemp;
// 	}
	strLetterKey += _T('-');
	for (int i = 0; i < vecKey.size(); i++)
	{
		CString strKey = vecKey[i].m_strValue;
		CString strTemp;
		strTemp.Format(_T(" %s"), strKey);
		strLetterKey += strTemp;
	}
// 	for (iter = mapKeys.begin(); iter != mapKeys.end(); iter++)
// 	{
// 		CString strKey = iter->second;
// 		CString strTemp;
// 		strTemp.Format(_T(" %s"), strKey);
// 		strLetterKey += strTemp;
// 	}
	strKeys.Delete(0);
	strKeys.Insert(0,_T('['));
	strKeys.Insert(strKeys.GetLength(), _T(']'));
	CString strPrompt;
	strPrompt.Format(_T("%s%s<�˳�>��"), szPrompt, strKeys);
	TCHAR* szRealPrompt = strPrompt.GetBuffer();	//��CString����תΪ�ַ���ָ��
	ads_name ssname;
	TCHAR* promptPtrs[2] = { szRealPrompt, TEXT("ѡ��ɾ������") };
	
	TCHAR* szRealLetterKey = strLetterKey.GetBuffer();
//	TCHAR kwordlist[] = {  };

	resbuf* (*oldFunc) (const ACHAR*) = NULL;
	acedSSGetKwordCallbackPtr(&oldFunc);
	acedSSSetKwordCallbackPtr(Callback);
	int nRet = acedSSGet(_T("_+.:?:$:K"), promptPtrs, szRealLetterKey, pRb, ssname);
	if (RTNORM != nRet)
	{
		acutRelRb(pRb);//�ͷŽ������������
		acedSSSetKwordCallbackPtr(*oldFunc);
		return false;
	}

	arrid.removeAll();

	//����ѡ��;
	long lLen = 0;
	acedSSLength(ssname, &lLen);
	for (long index = 0; index < lLen; index++)
	{
		ads_name ent;
		acedSSName(ssname, index, ent);
		AcDbObjectId objId;
		acdbGetObjectId(objId, ent);
		arrid.append(objId);
	}

	acutRelRb(pRb);//�ͷŽ������������	
	acedSSFree(ssname);	// �ͷ�ѡ��;
	acedSSSetKwordCallbackPtr(*oldFunc);

	return true;
}
