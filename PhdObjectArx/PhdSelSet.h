#pragma once
#include "PhdInline.h"

//ѡ��ѡȡʵ��
namespace PhdSelSet {

	//���ܣ�ͨ����������ѡȡʵ��
	//���ӣ�resbuf* pRb = acutBuildList(-4, _T("<and"), RTDXF0, _T("INSERT"), 1001, _T("��չ����Ӧ�ó�����"), -4, _T("and>"), RTNONE);
	AcDbObjectIdArray SelEntsByFilter(resbuf* pRb);

	//���ܣ�ѡȡ���ʵ��
	//���ӣ�resbuf* pRb = acutBuildList(-4, _T("<OR"),RTDXF0, _T("LINE"),RTDXF0, _T("ARC"),RTDXF0, _T("LWPOLYLINE"),-4, _T("OR>"),RTNONE);
	//�����ڲ��ͷ�pRbָ��
	bool SelEnts(LPCTSTR szPrompt, resbuf* pRb,AcDbObjectIdArray& arrid );
	bool SelEnts(LPCTSTR szPrompt, AcDbObjectIdArray& arrid);

	//���ܣ�ѡȡ���ʵ�壬���ڹؼ���
	//ע�⣺��Ҫ��дCallback����
	//���ӣ�
	//std::vector<SKey> vecKey;
	//vecKey.push_back(SKey(_T("����"), _T("Scale")));
	//vecKey.push_back(SKey(_T("���"), _T("Number")));
	bool SelEnts(LPCTSTR szPrompt, resbuf* pRb, const std::vector<SKey>& vecKey, AcDbObjectIdArray& arrid);

	// Summary:   �õ�������ʵ��id
	// Time:	  2019��10��22��
	// Explain:	  ʹ�ô˺���ʱ��Ҫ��ʾȫ��ʵ��
	AcDbObjectIdArray GetAreaEnts(const AcGePoint3d& ptMin,const AcGePoint3d& ptMax);


}