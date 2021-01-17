#pragma once

//��ͼ
namespace PhdView {
	
	//************************************
	// Summary: 	�õ���ǰ��ͼ����
	// Parameters: 	
	//    view		- 	�����ǰ��ͼ��Ϣ
	// Returns:   	
	//************************************
	void GetCurrentView(AcDbViewTableRecord &view);

	//************************************
	// Summary: 	����ָ����Χ�л���ͼ
	// Parameters: 	
	//    ptMin		- 	������ͼ��С��
	//    ptMax		- 	������ͼ����
	//    scale		- 	���������һ�㲻��ֱ���л���ʵ���С��������scale����һ�£�
	// Returns:   	
	//************************************
	void SetViewExtent(const AcGePoint3d &ptMin, const AcGePoint3d &ptMax, double scale = 1.0);

	// Summary:   �õ���ǰ��ͼ�ĸ߶�
	// Time:	  2020��1��14�� peihaodong
	// Explain:	  
	double GetCurViewHeight();

	//�õ���ǰ��ͼ����
	void GetCurViewData(double& dHeight,double& dWidth,AcGePoint2d& ptCenter);

	//���õ�ǰ��ͼ����
	void SetCurViewData(double dHeight, double dWidth, const AcGePoint2d& ptCenter);
}

