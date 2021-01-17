#pragma once
#include "PhdInline.h"

//�û�����
namespace PhdUiPr {

	//���ܣ�ѡȡ����ʵ��
	//���ӣ�PhdUiPr::SelEnt(_T("ѡ��һ��ֱ��"), AcDbLine::desc(), id, pt);
	bool SelEnt(LPCTSTR szPrompt, AcRxClass* classType, AcDbObjectId& id, AcGePoint3d& pt);
	bool SelEnt(LPCTSTR szPrompt, const AcArray<AcRxClass*>& arrclassType, AcDbObjectId& id,
		AcGePoint3d& pt);
	// Summary:   ѡȡ����ʵ��
	// Time:	  2020��6��10�� peihaodong
	// Explain:	  ����0��ȡ�� ����1���ɹ� ����2���ո�\�س�
	int SelEnt2(LPCTSTR szPrompt, AcRxClass* classType, AcDbObjectId& id, AcGePoint3d& pt);

	//���ܣ�ѡȡ���ʵ��
	bool SelEnts(LPCTSTR szPrompt, const AcArray<AcRxClass*>& arrclassType, AcDbObjectIdArray& idArr);

	//���ܣ�ѡ��ؼ���
	//���ӣ�
	//std::vector<SKey> vecKey;
	//vecKey.push_back(SKey(_T("����"), _T("Scale")));
	//vecKey.push_back(SKey(_T("���"), _T("Number")));
	bool SelKey(LPCTSTR szPrompt, const std::vector<SKey>& vecKey,CString& key);
	bool SelKey(LPCTSTR szPrompt, const std::vector<SKey>& vecKey, CString& key, int nInitFlag);

	//���ܣ���ȡʵ��
	bool GetDouble(LPCTSTR szPrompt, double& dValue);
	bool GetDouble(LPCTSTR szPrompt,double& dValue,double dDefault);
	bool GetDouble(LPCTSTR szPrompt, double& dValue, double dDefault,int nInitFlag);

	//���ܣ���ȡ����
	bool GetInt(LPCTSTR szPrompt, int& nValue);
	bool GetInt(LPCTSTR szPrompt, int& nValue,int nDefault);

	//���ܣ���ȡ�ַ���
	bool GetString(LPCTSTR szPrompt,CString& strValue);
	bool GetString(LPCTSTR szPrompt, CString& strValue,LPCTSTR szDefault);
	bool GetString(LPCTSTR szPrompt, CString& strValue, int nInitFlag);

	//���ܣ���ȡ��
	bool GetPoint(LPCTSTR szPrompt, AcGePoint3d& pt);
	bool GetPoint(LPCTSTR szPrompt, AcGePoint3d& pt, const AcGePoint3d& ptBase);

	//���ܣ���ȡ�ǵ�
	bool GetCorner(LPCTSTR szPrompt, const AcGePoint3d& ptBase, AcGePoint3d& pt);

	//���ܣ���ȡ�Ƕ�
	//ע�⣺�û�������������ػ���ֵ
	bool GetAngle(LPCTSTR szPrompt, double& dAngle);
	bool GetAngle(LPCTSTR szPrompt, double& dAngle, double dDefault);
	bool GetAngle(LPCTSTR szPrompt, double& dAngle,const AcGePoint3d& ptBase);
	bool GetAngle(LPCTSTR szPrompt, double& dAngle,const AcGePoint3d& ptBase, double dDefault);

	//���ܣ���ȡ����
	bool GetDist(LPCTSTR szPrompt, double& dDist);
	bool GetDist(LPCTSTR szPrompt, double& dDist, double dDefault);
	bool GetDist(LPCTSTR szPrompt, double& dDist, const AcGePoint3d& ptBase);
	bool GetDist(LPCTSTR szPrompt, double& dDist, const AcGePoint3d& ptBase, double dDefault);





}

