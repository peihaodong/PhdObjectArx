#include "StdAfx.h"
#include "PhdArxSelSet.h"

#pragma region 内部函数
resbuf* Callback(const TCHAR* szKword)
{
	if (_tcsicmp(szKword, _T("Scale")) == 0)
	{
		acutPrintf(_T("\n关键字Scale"));
		//字高
// 		double dCurHeight = g_TrdIni.GetJxtjHeight();	读取配置文件数据
// 		double dNewHeight = 40;
// 		if (PubFunc::GetDouble(_T("指定比例"), dCurHeight, dNewHeight))		用户交互设置数据
// 		{
// 			g_TrdIni.SetJxtjHeight(dNewHeight);	设置配置文件数据
// 		}
	}
	else if (_tcsicmp(szKword, _T("Number")) == 0)
	{
		acutPrintf(_T("\n关键字Number"));
		//起始编号
// 		int nCurNumber = g_TrdIni.GetJxtjNumber();	读取配置文件数据
// 		int nNewNumber = 1;
// 		if (PubFunc::GetInt(_T("指定起始编号"), nCurNumber, nNewNumber))	用户交互设置数据
// 		{
// 			g_TrdIni.SetJxtjNumber(nNewNumber);	设置配置文件数据
// 		}
	}
	else
		acutPrintf(_T("\n请输入关键字！"));

	return NULL;
}


#pragma endregion

AcDbObjectIdArray Phd::PhdArxSelSet::SelEntsByFilter(resbuf* pRb)
{
	assert(pRb);

	AcDbObjectIdArray arridSels;
	ads_name ssname;
	int nRet = acedSSGet(_T("X"), NULL, NULL, pRb, ssname);
	acutRelRb(pRb);	//释放结果缓冲区

	//遍历选择集
	long lLength = 0;
	acedSSLength(ssname, &lLength);
	if (lLength == 0)
		return arridSels;
	for (int i = 0; i < lLength; i++)
	{
		ads_name name;
		acedSSName(ssname, i, name);
		AcDbObjectId id;
		acdbGetObjectId(id, name);	//ads_name转AcDbObjectId
		arridSels.append(id);
	}
	acedSSFree(ssname);//释放选择集

	return arridSels;
}

bool Phd::PhdArxSelSet::SelEnts(LPCTSTR szPrompt, resbuf* pRb, AcDbObjectIdArray& arrid)
{
	assert(pRb);

	CString strPrompt;
	strPrompt.Format(_T("%s："), szPrompt);
	TCHAR* szRealPrompt = strPrompt.GetBuffer();	//将CString对象转为字符串指针
	ads_name ssname;
	TCHAR* promptPtrs[2] = { szRealPrompt, TEXT("选择删除对象：") };
	int nRet = acedSSGet(_T(":$"), promptPtrs, NULL, pRb, ssname);
	if (RTNORM != nRet)
	{
		acutRelRb(pRb);//释放结果缓冲区链表
		return false;
	}

	arrid.removeAll();

	//遍历选择集;
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

	acutRelRb(pRb);//释放结果缓冲区链表	
	acedSSFree(ssname);	// 释放选择集;

	return true;
}

bool Phd::PhdArxSelSet::SelEnts(LPCTSTR szPrompt, AcDbObjectIdArray& arrid)
{
	CString strPrompt;
	strPrompt.Format(_T("%s："), szPrompt);
	TCHAR* szRealPrompt = strPrompt.GetBuffer();	//将CString对象转为字符串指针
	ads_name ssname;
	TCHAR* promptPtrs[2] = { szRealPrompt, TEXT("选择删除对象：") };
	int nRet = acedSSGet(_T(":$"), promptPtrs, NULL, NULL, ssname);
	if (RTNORM != nRet)
		return false;

	arrid.removeAll();

	//遍历选择集;
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

	acedSSFree(ssname);	// 释放选择集;

	return true;
}

AcDbObjectIdArray Phd::PhdArxSelSet::GetAreaEnts(const AcGePoint3d& ptMin, const AcGePoint3d& ptMax)
{
	AcDbObjectIdArray arrid;
	ads_name ssname;
	int nRet = acedSSGet(_T("C"), asDblArray(ptMin), asDblArray(ptMax), NULL, ssname);
	if (RTNORM != nRet)
		return arrid;

	//遍历选择集;
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

	acedSSFree(ssname);	// 释放选择集;
	return arrid;
}

bool Phd::PhdArxSelSet::SelEnts(LPCTSTR szPrompt, resbuf* pRb, const std::vector<SKey>& vecKey, AcDbObjectIdArray& arrid)
{
	/*
	TCHAR kwordlist[] = { _T("Scale Prefix Dot Number Thickness _ Scale Prefix Dot Number Thickness") };
	TCHAR* promptPtrs[2] = { _T("选取要统计的矩形[比例(S)/前缀(P)/小数位(D)/起始编号(N)/板厚(T)]<退出>："),
		TEXT("选择删除对象：") };
	int nRet = acedSSGet(_T("_+.:?:$:K"), promptPtrs, kwordlist, rb, ssname);
	*/

	assert(pRb);
	if (vecKey.size() == 0)
		return false;

	//遍历map容器
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
	strPrompt.Format(_T("%s%s<退出>："), szPrompt, strKeys);
	TCHAR* szRealPrompt = strPrompt.GetBuffer();	//将CString对象转为字符串指针
	ads_name ssname;
	TCHAR* promptPtrs[2] = { szRealPrompt, TEXT("选择删除对象：") };
	
	TCHAR* szRealLetterKey = strLetterKey.GetBuffer();
//	TCHAR kwordlist[] = {  };

	resbuf* (*oldFunc) (const ACHAR*) = NULL;
	acedSSGetKwordCallbackPtr(&oldFunc);
	acedSSSetKwordCallbackPtr(Callback);
	int nRet = acedSSGet(_T("_+.:?:$:K"), promptPtrs, szRealLetterKey, pRb, ssname);
	if (RTNORM != nRet)
	{
		acutRelRb(pRb);//释放结果缓冲区链表
		acedSSSetKwordCallbackPtr(*oldFunc);
		return false;
	}

	arrid.removeAll();

	//遍历选择集;
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

	acutRelRb(pRb);//释放结果缓冲区链表	
	acedSSFree(ssname);	// 释放选择集;
	acedSSSetKwordCallbackPtr(*oldFunc);

	return true;
}
