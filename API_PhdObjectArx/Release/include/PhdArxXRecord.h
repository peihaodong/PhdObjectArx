#pragma once


namespace Phd {

class PHD_OBJECTARX_API PhdArxXRecord
{
public:
	//************************************
	// Summary:  ������չ��¼�����������ֵ���
	// Parameter:
	//      szDictinaryName -    ���������ֵ��е��ֵ���
	//		szRecordName - �ֵ��еļ�¼��
	//		dValue - �����double������
	//      pDb -    ���ݿ�
	// Return:   
	// Notice:   
	// Update Time: 2020-10-21 16:13:30
	//************************************
	bool SetXRecordOfNameDictionary(LPCTSTR szDictinaryName,
		LPCTSTR szRecordName, double dValue, AcDbDatabase* pDb = acdbCurDwg());

	//************************************
	// Summary:  �õ���չ��¼�����������ֵ���
	// Parameter:
	//      szDictinaryName -    ���������ֵ��е��ֵ���
	//      szRecordName -    �ֵ��еļ�¼��
	//      dValue -    �����double������
	//      pDb -    ���ݿ�
	// Return:   
	// Notice:   
	// Update Time: 2020-10-21 16:42:20
	//************************************
	bool GetXRecordOfNameDictionary(LPCTSTR szDictinaryName,
		LPCTSTR szRecordName, double& dValue, AcDbDatabase* pDb = acdbCurDwg());
};

}