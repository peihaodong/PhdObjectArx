#include "StdAfx.h"
#include "PhdUiPr.h"
//#include "PhdSysVar.h"



bool PhdUiPr::SelEnt(LPCTSTR szPrompt, AcRxClass* classType, AcDbObjectId& id, AcGePoint3d& pt)
{
	CString strPrompt;
	strPrompt.Format(_T("\n%s："),szPrompt);
	while (true)
	{
		ads_name ent;
		ads_point adsPt;
		int nRt = acedEntSel(strPrompt, ent, adsPt);
		if (RTCAN == nRt)
			return false;
		else if (RTNONE == nRt)
			return false;
		else if (RTNORM != nRt)
			continue;
	
		AcDbObjectId tmpId;
		acdbGetObjectId(tmpId, ent);
		AcDbEntity* pEnt = NULL;
		Acad::ErrorStatus es = acdbOpenAcDbEntity(pEnt, tmpId, AcDb::kForRead);
		if (Acad::eOk != es)
			return false;
		AcRxClass* rxClass = static_cast<AcRxClass*>(classType);

		bool bIsOk = false;
		if (pEnt->isKindOf(rxClass))	//如果“this”对象是由aClass表示的类的成员，或者是从aClass派生的类的成员，则返回true。
			bIsOk = true;
		//	if (pEnt->isA() == rxClass)		//此函数在所有派生类中都被重写。这个函数的实现就是简单地返回::desc()。例：AcDbLine的实现是:返回AcDbLine::desc();
		//		bIsOk = true;

		if (bIsOk)
		{
			pEnt->close();
			pt = asPnt3d(adsPt);
			id = tmpId;
			return true;
		}
		else
		{
			pEnt->close();
// 			CString strType = rxClass->name();
// 			acutPrintf(_T("\nSelected entity must be of type: %s"), strType);
// 			return false;
		}
	}
}

int PhdUiPr::SelEnt2(LPCTSTR szPrompt, AcRxClass* classType,
	AcDbObjectId& id, AcGePoint3d& pt)
{
	CString strPrompt;
	strPrompt.Format(_T("\n%s："), szPrompt);
	while (true)
	{
		ads_name ent;
		ads_point adsPt;
		int nRt = acedEntSel(strPrompt, ent, adsPt);
		if (RTCAN == nRt)
			return 0;
		else if (RTNONE == nRt)
			return 2;
		else if (RTERROR == nRt)
			return 2;
		else if (RTNORM != nRt)
			continue;

		AcDbObjectId tmpId;
		acdbGetObjectId(tmpId, ent);
		AcDbEntity* pEnt = NULL;
		Acad::ErrorStatus es = acdbOpenAcDbEntity(pEnt, tmpId, AcDb::kForRead);
		if (Acad::eOk != es)
			return false;
		AcRxClass* rxClass = static_cast<AcRxClass*>(classType);

		bool bIsOk = false;
		if (pEnt->isKindOf(rxClass))	//如果“this”对象是由aClass表示的类的成员，或者是从aClass派生的类的成员，则返回true。
			bIsOk = true;

		if (bIsOk)
		{
			pEnt->close();
			pt = asPnt3d(adsPt);
			id = tmpId;
			return 1;
		}
		else
		{
			pEnt->close();
		}
	}
}

bool PhdUiPr::SelEnt(LPCTSTR szPrompt, const AcArray<AcRxClass*>& arrclassType, AcDbObjectId& id, AcGePoint3d& pt)
{
	CString strPrompt;
	strPrompt.Format(_T("\n%s："), szPrompt);
	ads_name ent;
	ads_point adsPt;
	int nRt = acedEntSel(strPrompt, ent, adsPt);
	if (RTNORM != nRt)
		return false;
	AcDbObjectId tmpId;
	acdbGetObjectId(tmpId, ent);
	AcDbEntity* pEnt = NULL;
	Acad::ErrorStatus es = acdbOpenAcDbEntity(pEnt, tmpId, AcDb::kForRead);
	if (Acad::eOk != es)
		return false;

	bool bIsOk = false;
	for (int i = 0; i < arrclassType.length(); i++)
	{
		AcRxClass* rxClass = static_cast<AcRxClass*>(arrclassType[i]);
		if (pEnt->isKindOf(rxClass))	//如果“this”对象是由aClass表示的类的成员，或者是从aClass派生的类的成员，则返回true。
		{
			bIsOk = true;
			break;
		}
	}
	
	if (bIsOk)
	{
		pEnt->close();
		pt = asPnt3d(adsPt);
		id = tmpId;
		return true;
	}
	else
	{
		pEnt->close();
		CString str;
		for (int i = 0; i < arrclassType.length(); i++)
		{
			CString strType = arrclassType[i]->name();
			strType += _T(" ");
			str += strType;
		}
		acutPrintf(_T("\nSelected entity must be of type: %s"), str);
		return false;
	}
}

bool PhdUiPr::SelEnts(LPCTSTR szPrompt, const AcArray<AcRxClass*>& arrclassType, AcDbObjectIdArray& idArr)
{
	idArr.removeAll();
	CString strPrompt;
	strPrompt.Format(_T("\n%s："), szPrompt);
	ads_name ent;
	ads_point adsPt;
	AcDbObjectId tmpId;
	bool bSucceed = false;

	while (1)
	{
		int nRt = acedEntSel(strPrompt, ent, adsPt);
		if (RTNORM == nRt)
		{
			acdbGetObjectId(tmpId, ent);
			AcDbEntity* pEnt = NULL;
			Acad::ErrorStatus es = acdbOpenAcDbEntity(pEnt, tmpId, AcDb::kForRead);
			if (Acad::eOk == es)
			{
				if (idArr.contains(tmpId))
				{
					acutPrintf(_T("\n已选取"));
					continue;
				}
				AcRxClass* rxClass = NULL;
				bool bIsOk = false;
				for (int i = 0; i < arrclassType.length(); i++)
				{
					rxClass = static_cast<AcRxClass*>(arrclassType[i]);
					if (pEnt->isKindOf(rxClass))	//如果“this”对象是由aClass表示的类的成员，或者是从aClass派生的类的成员，则返回true。
						bIsOk = true;
					//	if (pEnt->isA() == rxClass)		//此函数在所有派生类中都被重写。这个函数的实现就是简单地返回::desc()。例：AcDbLine的实现是:返回AcDbLine::desc();
					//		bIsOk = true;
				}
				if (bIsOk)
				{
					pEnt->close();
					idArr.append(tmpId);
					bSucceed = true;
				}
				else
				{
					pEnt->close();
					CString strTypes;
					for (int j = 0; j < arrclassType.length(); j++)
					{
						if (j > 0)
							strTypes += _T(", ");
						rxClass = static_cast<AcRxClass*>(arrclassType[j]);
						strTypes += rxClass->name();
					}
					acutPrintf(_T("\nSelected entity must be of type: %s"), strTypes);
				}
			}
			else
			{
				acutPrintf(_T("\n打开实体失败！"));
				return false;
			}
		}
		else
		{
			if (bSucceed)
				return true;
			else
				return false;
		}
	}
}

bool PhdUiPr::SelKey(LPCTSTR szPrompt, const std::vector<SKey>& vecKey, 
	CString& key)
{
	/*
	TCHAR szKword1[132];
	acedInitGet(0, _T("Shi Xu"));
	int nReturn = acedGetKword(_T("请选择要保留的线段 [实线(S)/虚线(X)] <S>："), szKword1);
	*/

	if (vecKey.size() == 0)
		return false;

	//遍历map容器
	CString strKeys;
	CString strLetterKey;
	CString strFirstKey = _T("");
	CString strFirstK;
	for (int i = 0; i < vecKey.size(); i++)
	{
		CString strText = vecKey[i].m_strName;
		CString strKey = vecKey[i].m_strValue;
		CString strK = strKey.GetAt(0);
		if (strFirstKey == _T(""))
		{
			strFirstKey = strKey;
			strFirstK = strKey.GetAt(0);
		}

		CString strTemp;
		strTemp.Format(_T("/%s(%s)"), strText, strK);
		strKeys += strTemp;
		strTemp.Format(_T("%s "), strKey);
		strLetterKey += strTemp;
	}

	strKeys.Delete(0);
	strKeys.Insert(0, _T('['));
	CString strEnd;
	strEnd.Format(_T("] <%s>"), strFirstK);
	strKeys.Insert(strKeys.GetLength(), strEnd);
	CString strPrompt;
	strPrompt.Format(_T("%s %s："), szPrompt, strKeys);
	strLetterKey.Delete(strLetterKey.GetLength()-1);

	TCHAR szKword1[132];
	acedInitGet(0, strLetterKey);
	int nReturn = acedGetKword(strPrompt, szKword1);
	if (nReturn == RTNORM)		//选取关键字
	{
		for (int i = 0; i < vecKey.size(); i++)
		{
			CString strKey = vecKey[i].m_strValue;
			if (_tcscmp(szKword1, strKey) == 0)
			{
				key = strKey;
				return true;
			}
		}
		return false;
	}
	else if (nReturn == RTCAN)	//取消
		return false;			
	else                        //默认
	{
		key = strFirstKey;
		return true;
	}
}

bool PhdUiPr::SelKey(LPCTSTR szPrompt, const std::vector<SKey>& vecKey, CString& key, int nInitFlag)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	if (vecKey.size() == 0)
		return false;

	//遍历map容器
	CString strKeys;
	CString strLetterKey;
	CString strFirstKey = _T("");
	CString strFirstK;
	for (int i = 0; i < vecKey.size(); i++)
	{
		CString strText = vecKey[i].m_strName;
		CString strKey = vecKey[i].m_strValue;
		CString strK = strKey.GetAt(0);
		if (strFirstKey == _T(""))
		{
			strFirstKey = strKey;
			strFirstK = strKey.GetAt(0);
		}

		CString strTemp;
		strTemp.Format(_T("/%s(%s)"), strText, strK);
		strKeys += strTemp;
		strTemp.Format(_T("%s "), strKey);
		strLetterKey += strTemp;
	}

	strKeys.Delete(0);
	strKeys.Insert(0, _T('['));
	CString strEnd;
	strEnd.Format(_T("] <%s>"), strFirstK);
	strKeys.Insert(strKeys.GetLength(), strEnd);
	CString strPrompt;
	strPrompt.Format(_T("%s %s："), szPrompt, strKeys);
	strLetterKey.Delete(strLetterKey.GetLength() - 1);

	TCHAR szKword1[132];
	acedInitGet(nInitFlag, strLetterKey);
	int nReturn = acedGetKword(strPrompt, szKword1);
	if (nReturn == RTNORM)		//选取关键字
	{
		for (int i = 0; i < vecKey.size(); i++)
		{
			CString strKey = vecKey[i].m_strValue;
			if (_tcscmp(szKword1, strKey) == 0)
			{
				key = strKey;
				return true;
			}
		}
		return false;
	}
	else if (nReturn == RTCAN)	//取消
		return false;
	else                        //默认
	{
		key = strFirstKey;
		return true;
	}
}

bool PhdUiPr::GetDouble(LPCTSTR szPrompt, double& dValue)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	CString prompt;
	prompt.Format(_T("\n%s: "), szPrompt);

	int initFlag = RSG_NONULL;	//非空
	acedInitGet(initFlag, NULL);
	int result = acedGetReal(prompt, &dValue);

	if (result == RTNORM) 
		return true;
	else
		return false;
}

bool PhdUiPr::GetDouble(LPCTSTR szPrompt, double& dValue, double dDefault, int nInitFlag)
{
	TCHAR defStr[512];
	acdbRToS(dDefault, -1, -1, defStr);
	CString prompt;
	prompt.Format(_T("\n%s<%s>: "), szPrompt, defStr);

	acedInitGet(nInitFlag, NULL);
	int result = acedGetReal(prompt, &dValue);

	if (result == RTNORM)		//函数操作成功
		return true;
	else if (result == RTNONE)	//空格、回车
	{
		dValue = dDefault;
		return true;
	}
	else
		return false;
}

bool PhdUiPr::GetInt(LPCTSTR szPrompt, int& nValue)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	CString prompt;
	prompt.Format(_T("\n%s: "), szPrompt);

	int initFlag = RSG_NONULL;	//非空
	acedInitGet(initFlag, NULL);
	int result = acedGetInt(prompt, &nValue);

	if (result == RTNORM)
		return true;
	else
		return false;
}

bool PhdUiPr::GetInt(LPCTSTR szPrompt, int& nValue, int nDefault)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	// set up prompt
	CString prompt;
	prompt.Format(_T("\n%s<%d>: "), szPrompt, nDefault);

	int initFlag = 0;	
	acedInitGet(initFlag, NULL);
	int result = acedGetInt(prompt, &nValue);

	if (result == RTNORM)		//函数操作成功
		return true;
	else if (result == RTNONE)	//空格、回车
	{
		nValue = nDefault;
		return true;
	}
	else
		return false;
}

bool PhdUiPr::GetString(LPCTSTR szPrompt, CString& strValue)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	CString prompt;
	prompt.Format(_T("\n%s: "), szPrompt);

	int initFlag = RSG_NONULL;	//非空
	acedInitGet(initFlag, NULL);
	TCHAR val[512];
	int result = acedGetString(1, prompt, val);
	//参数一：如果非零，字符串可以包含空格，用户必须输入[Enter]来终止它;
	//如果为0，则输入空白或[Enter]结束字符串

	if (result == RTNORM)
	{
		strValue = val;
		return true;
	}
	else
		return false;
}

bool PhdUiPr::GetString(LPCTSTR szPrompt, CString& strValue, int nInitFlag)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	CString prompt;
	prompt.Format(_T("\n%s: "), szPrompt);

//	int initFlag = RSG_NONULL;	//非空
	acedInitGet(nInitFlag, NULL);
	TCHAR val[512];
	int result = acedGetString(0, prompt, val);
	//参数一：如果非零，字符串可以包含空格，用户必须输入[Enter]来终止它;
	//如果为0，则输入空白或[Enter]结束字符串

	if (result == RTNORM)
	{
		strValue = val;
		return true;
	}
	else
		return false;
}

bool PhdUiPr::GetString(LPCTSTR szPrompt, CString& strValue, LPCTSTR szDefault)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	// set up prompt
	CString prompt;
	prompt.Format(_T("\n%s<%s>: "), szPrompt, szDefault);

	int initFlag = RSG_NONULL;	//非空
	acedInitGet(initFlag, NULL);
	TCHAR val[512];
	int result = acedGetString(0, prompt, val);
	//参数一：如果非零，字符串可以包含空格，用户必须输入[Enter]来终止它;
	//如果为0，则输入空白或[Enter]结束字符串

	if (result == RTNORM)
	{
		strValue = val;
		return true;
	}
	else
		return false;
}

bool PhdUiPr::GetPoint(LPCTSTR szPrompt, AcGePoint3d& pt)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	CString prompt;
	prompt.Format(_T("\n%s: "), szPrompt);

	int initFlag = RSG_NONULL;	//非空
	acedInitGet(initFlag, NULL);
	ads_point adsPt;
	int result = acedGetPoint(NULL,prompt, adsPt);

	if (result == RTNORM)
	{
		pt = asPnt3d(adsPt);
		//PhdSysVar::SetSysVar(_T("LASTPOINT"),pt);
		return true;
	}
	else
		return false;
}

bool PhdUiPr::GetAngle(LPCTSTR szPrompt, double& dAngle)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	CString prompt;
	prompt.Format(_T("\n%s: "), szPrompt);

	int initFlag = RSG_NONULL;	//非空
	acedInitGet(initFlag, NULL);
	int result = acedGetOrient(NULL, prompt, &dAngle);

	if (result == RTNORM)
		return true;
	else
		return false;
}

bool PhdUiPr::GetDist(LPCTSTR szPrompt, double& dDist)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	CString prompt;
	prompt.Format(_T("\n%s: "), szPrompt);

	int initFlag = RSG_NONULL + RSG_NOZERO + RSG_NONEG;	//非空、非零、非负
	acedInitGet(initFlag, NULL);
	int result = acedGetDist(NULL, prompt, &dDist);

	if (result == RTNORM)
		return true;
	else
		return false;
}

bool PhdUiPr::GetDist(LPCTSTR szPrompt, double& dDist, const AcGePoint3d& ptBase, double dDefault)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	TCHAR defStr[512];
	acdbRToS(dDefault, -1, -1, defStr);
	CString prompt;
	prompt.Format(_T("\n%s<%s>: "), szPrompt, defStr);

	int initFlag = RSG_NONULL + RSG_NOZERO + RSG_NONEG;	//非空、非零、非负
	acedInitGet(initFlag, NULL);
	int result = acedGetDist(asDblArray(ptBase), prompt, &dDist);

	if (result == RTNORM)
		return true;
	else
		return false;
}

bool PhdUiPr::GetDist(LPCTSTR szPrompt, double& dDist, const AcGePoint3d& ptBase)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	CString prompt;
	prompt.Format(_T("\n%s: "), szPrompt);

	int initFlag = RSG_NONULL + RSG_NOZERO + RSG_NONEG;	//非空、非零、非负
	acedInitGet(initFlag, NULL);
	int result = acedGetDist(asDblArray(ptBase), prompt, &dDist);

	if (result == RTNORM)
		return true;
	else
		return false;
}

bool PhdUiPr::GetDist(LPCTSTR szPrompt, double& dDist, double dDefault)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	TCHAR defStr[512];
	acdbRToS(dDefault, -1, -1, defStr);
	CString prompt;
	prompt.Format(_T("\n%s<%s>: "), szPrompt, defStr);

	int initFlag = RSG_NONULL + RSG_NOZERO + RSG_NONEG;	//非空、非零、非负
	acedInitGet(initFlag, NULL);
	int result = acedGetDist(NULL, prompt, &dDist);

	if (result == RTNORM)
		return true;
	else
		return false;
}

bool PhdUiPr::GetAngle(LPCTSTR szPrompt, double& dAngle, const AcGePoint3d& ptBase, double dDefault)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	TCHAR defStr[512];
	acdbRToS(dDefault, -1, -1, defStr);
	CString prompt;
	prompt.Format(_T("\n%s<%s>: "), szPrompt, defStr);

	int initFlag = RSG_NONULL;	//非空
	acedInitGet(initFlag, NULL);
	int result = acedGetOrient(asDblArray(ptBase), prompt, &dAngle);

	if (result == RTNORM)
		return true;
	else
		return false;
}

bool PhdUiPr::GetAngle(LPCTSTR szPrompt, double& dAngle, const AcGePoint3d& ptBase)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	CString prompt;
	prompt.Format(_T("\n%s: "), szPrompt);

	int initFlag = RSG_NONULL;	//非空
	acedInitGet(initFlag, NULL);
	int result = acedGetOrient(asDblArray(ptBase), prompt, &dAngle);

	if (result == RTNORM)
		return true;
	else
		return false;
}

bool PhdUiPr::GetCorner(LPCTSTR szPrompt, const AcGePoint3d& ptBase, AcGePoint3d& pt)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	CString prompt;
	prompt.Format(_T("\n%s: "), szPrompt);

	int initFlag = RSG_NONULL;	//非空
	acedInitGet(initFlag, NULL);
	ads_point adsPt;
	int result = acedGetCorner(asDblArray(ptBase), prompt, adsPt);

	if (result == RTNORM)
	{
		pt = asPnt3d(adsPt);
		return true;
	}
	else
		return false;
}

bool PhdUiPr::GetAngle(LPCTSTR szPrompt, double& dAngle, double dDefault)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	TCHAR defStr[512];
	acdbRToS(dDefault, -1, -1, defStr);
	CString prompt;
	prompt.Format(_T("\n%s<%s>: "), szPrompt, defStr);

	int initFlag = RSG_NONULL;	//非空
	acedInitGet(initFlag, NULL);
	int result = acedGetOrient(NULL, prompt, &dAngle);

	if (result == RTNORM)
		return true;
	else
		return false;
}

bool PhdUiPr::GetPoint(LPCTSTR szPrompt, AcGePoint3d& pt,
	const AcGePoint3d& ptBase)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	CString prompt;
	prompt.Format(_T("\n%s: "), szPrompt);

	int initFlag = RSG_NONULL;	//非空
	acedInitGet(initFlag, NULL);
	ads_point adsPt;
	int result = acedGetPoint(asDblArray(ptBase), prompt, adsPt);

	if (result == RTNORM)
	{
		pt = asPnt3d(adsPt);
		//PhdSysVar::SetSysVar(_T("LASTPOINT"), pt);
		return true;
	}
	else
		return false;
}

bool PhdUiPr::GetDouble(LPCTSTR szPrompt, double& dValue, double dDefault)
{
	/*
	RSG_NONULL：不允许空输入
	RSG_NOZERO：不允许零值
	RSG_NONEG：不允许负值
	RSG_NOLIM：允许用户输入图形界限外的点
	RSG_DASH：在绘制橡皮筋线或框时使用虚线
	*/

	// set up prompt
	TCHAR defStr[512];
	acdbRToS(dDefault, -1, -1, defStr);
	CString prompt;
	prompt.Format(_T("\n%s<%s>: "), szPrompt, defStr);

	int initFlag = 0;	
	acedInitGet(initFlag, NULL);
	int result = acedGetReal(prompt, &dValue);

	if (result == RTNORM)		//函数操作成功
		return true;
	else if (result == RTNONE)	//空格、回车
	{
		dValue = dDefault;
		return true;
	}
	else
		return false;
}
