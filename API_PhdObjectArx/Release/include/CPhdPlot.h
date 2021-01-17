#pragma once

//调用cad自身打印机打印文件

class CPhdPlot
{
public:
	CPhdPlot();
	~CPhdPlot();

	//设置要打印的数据库指针（默认acdbCurDwg()）
	void SetDatabase(AcDbDatabase* pDb);

	//设置图纸尺寸（默认_T("A4")）
	void SetDrawSize(LPCTSTR szPixel);

	//设置打印样式（默认_T("zwcad.ctb")）
	void SetPrintStyle(LPCTSTR szPriStyle);

	//设置旋转角度（默认0）
	void SetRotation(int nRotation);

	//开始打印
	bool BeginPlot(const AcGePoint3d& ptMin,const AcGePoint3d& ptMax,LPCTSTR szFilePath);


private:
	//设置生成文件的路径，会根据该路径自动识别要打印的文件类型
	bool SetOutPath(LPCTSTR szPath);

	//获得布局的Id
	AcDbObjectId GetLayoutId() const;

	//设置打印数据
	bool SetPlotData(AcDbObjectId& idLayout,AcDbPlotSettings*& pPlotSet,
		const AcGePoint3d& ptMin, const AcGePoint3d& ptMax) const;

	//打印
	bool Plot(AcDbObjectId& idLayout, AcDbPlotSettings* pPlotSet) const;

private:
	AcDbDatabase* m_pDb;		//要打印的数据库指针
	CString m_strPixel;			//图纸尺寸
	CString m_strPrintStyle;	//打印样式
	int m_nRotation;			//旋转角度
	CString m_strDeviceName;	//打印机名字(文件类型)

	CString m_strOutPath;		//文件输出路径

};

