#pragma once

//�ӿ�
namespace PhdViewport {

	//���ܣ������ӿ�
	void CreateViewport();

	//���ܣ���ʾ���ӿ�
	void ShowViewportSi();
	//���ܣ���ʾ���ӿ�
	void ShowViewportFu();
	//���ܣ���ʾ���ӿ�
	void ShowViewportZhu();
	//���ܣ���ʾ���ӿ�
	void ShowViewportLi();
	//���ܣ���ʾ���ӿ�
	void ShowViewportZuo();
	//���ܣ���ʾ���ӿ�
	void ShowViewportDan();

	// Summary:   �����ӿڷ�Χ
	// Time:	  2019��10��31��
	// Explain:	  
	bool SetViewportRange(const AcGePoint3d& ptMin,const AcGePoint3d& ptMax,
		AcDbDatabase* pDb = acdbCurDwg());
	bool SetViewportRange(double dX, double dY,AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   �õ��ӿ�id
	// Time:	  2019��11��14�� peihaodong
	// Explain:	  
	AcDbObjectId GetViewportId(AcDbDatabase* pDb = acdbCurDwg());



}

