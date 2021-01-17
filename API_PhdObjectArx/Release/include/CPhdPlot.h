#pragma once

//����cad�����ӡ����ӡ�ļ�

class CPhdPlot
{
public:
	CPhdPlot();
	~CPhdPlot();

	//����Ҫ��ӡ�����ݿ�ָ�루Ĭ��acdbCurDwg()��
	void SetDatabase(AcDbDatabase* pDb);

	//����ͼֽ�ߴ磨Ĭ��_T("A4")��
	void SetDrawSize(LPCTSTR szPixel);

	//���ô�ӡ��ʽ��Ĭ��_T("zwcad.ctb")��
	void SetPrintStyle(LPCTSTR szPriStyle);

	//������ת�Ƕȣ�Ĭ��0��
	void SetRotation(int nRotation);

	//��ʼ��ӡ
	bool BeginPlot(const AcGePoint3d& ptMin,const AcGePoint3d& ptMax,LPCTSTR szFilePath);


private:
	//���������ļ���·��������ݸ�·���Զ�ʶ��Ҫ��ӡ���ļ�����
	bool SetOutPath(LPCTSTR szPath);

	//��ò��ֵ�Id
	AcDbObjectId GetLayoutId() const;

	//���ô�ӡ����
	bool SetPlotData(AcDbObjectId& idLayout,AcDbPlotSettings*& pPlotSet,
		const AcGePoint3d& ptMin, const AcGePoint3d& ptMax) const;

	//��ӡ
	bool Plot(AcDbObjectId& idLayout, AcDbPlotSettings* pPlotSet) const;

private:
	AcDbDatabase* m_pDb;		//Ҫ��ӡ�����ݿ�ָ��
	CString m_strPixel;			//ͼֽ�ߴ�
	CString m_strPrintStyle;	//��ӡ��ʽ
	int m_nRotation;			//��ת�Ƕ�
	CString m_strDeviceName;	//��ӡ������(�ļ�����)

	CString m_strOutPath;		//�ļ����·��

};

