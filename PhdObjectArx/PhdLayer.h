#pragma once

//ͼ��
namespace PhdLayer {

	//���ܣ��õ�ͼ��id
	//bCreate-���벼��ֵ��ͼ�㲻�����Ƿ񴴽�
	AcDbObjectId GetLayerId(const CString& strLayerName, bool bCreate = true,
		AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   pDb�Ƿ���ڴ����ֵ�ͼ��
	// Time:	  2019��12��23�� peihaodong
	// Explain:	  
	bool IsExist(LPCTSTR szLayerName, AcDbDatabase* pDb = acdbCurDwg());

	//���ܣ�����ʵ��ͼ��
	bool SetEntLayer(const AcDbObjectId& idEnt, const AcDbObjectId& idLayer);
	bool SetEntLayer(const AcDbObjectIdArray& arridEnt, const AcDbObjectId& idLayer);

	// Summary:   ����ͼ��ر�
	// Time:	  2019��11��18�� peihaodong
	// Explain:	  
	bool SetLayerOff(const AcDbObjectId& idLayer,bool bOff = true);

	// Summary:   �õ�ͼ����
	// Time:	  2019��11��18�� peihaodong
	// Explain:	  
	CString GetLayerName(const AcDbObjectId& idLayer);

	// Summary:   �õ�pDb���ݿ���szLayerNameͼ���µ�����ʵ��ID
	// Time:	  2019��12��18�� peihaodong
	// Explain:	  
	AcDbObjectIdArray GetEntIdsOfLayer(LPCTSTR szLayerName,
		AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   ����ͼ����ɫ
	// Time:	  2019��12��23�� peihaodong
	// Explain:	  
	bool SetColorIndex(const AcDbObjectId& idLayer, int nColorIndex);

	// Summary:   �õ�ͼ����ɫ����
	// Time:	  2019��12��23�� peihaodong
	// Explain:	  
	int GetLayerColorIndex(const AcDbObjectId& idLayer);

	// Summary:   �õ����ݿ����е�ͼ��id
	// Time:	  2020��3��23�� peihaodong
	// Explain:	  
	AcDbObjectIdArray GetLayerIdsOnDb(AcDbDatabase* pDb);

}

