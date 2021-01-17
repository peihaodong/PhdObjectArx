#pragma once


namespace PhdCommand {

	//���ܣ��ر��������
	void CommandEchoOff();

	//���ñ�ע���Ա���
	//˵������ע��ʾ����ֵ��dValue��������
	bool SetDimLineScale(double dValue);

	// Summary:   ���ñ�עȫ�ֱ���
	// Time:	  2019��11��12�� peihaodong
	// Explain:	  
	bool SetDimScale(double dValue);

	//���ܣ��������򸲸��Ƿ���ʾ�߿�
	bool SetWipeoutShow(bool bShow = false);

	//���ܣ����õ�Բ�ǰ뾶
	bool SetFilletRadius(double dRadius);

	//���ܣ�����cad���Բ��
	//����Բ��id
	AcDbObjectId FilletByCommand(const AcDbObjectId& idLine1, const AcDbObjectId& idLine2);

	//���ܣ���λʵ��
	bool OrientationEnt(const AcDbObjectId& idEnt);

	//���ܣ�zoom��ʾȫ��ʵ��
	bool ZoomAllEnt();

	// Summary:   ͨ������cad�����������ת�����
	// Time:	  2020��4��1�� peihaodong
	// Explain:	  �����µĶ����
	bool SplineToPline(const AcDbObjectIdArray& arridSpline,
		AcDbObjectIdArray& arridPline,int nPrecision = 10);
	bool SplineToPline(const AcDbObjectId& idSpline,
		AcDbObjectId& idPline, int nPrecision = 10);
	bool SplineToPline(AcDbSpline* pSpline,
		AcDbObjectId& idPline, int nPrecision = 10);
	bool SplineToPline2(AcDbSpline* pSpline,
		AcDbObjectId& idPline);
}

