#include "StdAfx.h"
#include "CPhdPlot.h"


CPhdPlot::CPhdPlot()
	: m_strPixel(_T("A4"))
	, m_strPrintStyle(_T("zwcad.ctb"))
	, m_nRotation(0)
	, m_pDb(acdbCurDwg())
{

}

CPhdPlot::~CPhdPlot()
{

}

bool CPhdPlot::SetOutPath(LPCTSTR szPath)
{
	CString str = szPath;
	int nFindIndex = str.ReverseFind(_T('.'));
	if (nFindIndex == -1)
		return false;
	CString strSuffix = str.Right(str.GetLength() - nFindIndex - 1);
	if (_tcsicmp(strSuffix, _T("pdf")) == 0)
	{
		m_strDeviceName = _T("DWG to PDF.pc5");//打印机名字
		m_strOutPath = szPath;
	}
	else if (_tcsicmp(strSuffix, _T("tif")) == 0)
	{
		m_strDeviceName = _T("TIF.pc5");//打印机名字
		m_strOutPath = szPath;
	}
	else if (_tcsicmp(strSuffix, _T("jpg")) == 0)
	{
		m_strDeviceName = _T("ZWCAD Virtual JPEG Plotter.pc5");//打印机名字
		m_strOutPath = szPath;
	}
	else if (_tcsicmp(strSuffix, _T("dwf")) == 0)
	{
		m_strDeviceName = _T("DWF6 ePlot.pc5");//打印机名字
		m_strOutPath = szPath;
	}
	else
		return false;
	return true;
}

void CPhdPlot::SetDrawSize(LPCTSTR szPixel)
{
	m_strPixel = szPixel;
}

void CPhdPlot::SetPrintStyle(LPCTSTR szPriStyle)
{
	m_strPrintStyle = szPriStyle;
}

void CPhdPlot::SetRotation(int nRotation)
{
	m_nRotation = nRotation;
}

void CPhdPlot::SetDatabase(AcDbDatabase* pDb)
{
	m_pDb = pDb;
}

bool CPhdPlot::BeginPlot(const AcGePoint3d& ptMin, const AcGePoint3d& ptMax, LPCTSTR szFilePath)
{
	//判断该文件是否符合
	if (!SetOutPath(szFilePath))
		return false;

	AcDbDatabase *pCurDb = acdbCurDwg();
	bool bNotCurDb = false;
	if (pCurDb != m_pDb)
	{
		bNotCurDb = true;
		acdbHostApplicationServices()->setWorkingDatabase(m_pDb);
	}

	//设置打印数据
	AcDbObjectId idLayout;
	AcDbPlotSettings *pPlotSet = nullptr;
	SetPlotData(idLayout, pPlotSet,ptMin,ptMax);

	//开始打印
	if (!Plot(idLayout, pPlotSet))
	{
		if (bNotCurDb)
			acdbHostApplicationServices()->setWorkingDatabase(pCurDb);
		return false;
	}

	if (bNotCurDb)
		acdbHostApplicationServices()->setWorkingDatabase(pCurDb);
	return true;
}

AcDbObjectId CPhdPlot::GetLayoutId() const
{
	//取得布局管理器对象
	AcDbLayoutManager *pLayoutManager = nullptr;
	pLayoutManager = acdbHostApplicationServices()->layoutManager();
	AcDbObjectId btrId = pLayoutManager->getActiveLayoutBTRId();
	AcDbBlockTableRecord *pBTR = nullptr;
	Acad::ErrorStatus es = acdbOpenObject(pBTR, btrId, AcDb::kForRead);
	AcDbObjectId  layoutId = pBTR->getLayoutId();
	pBTR->close();
	return layoutId;
}

bool CPhdPlot::SetPlotData(AcDbObjectId& idLayout, AcDbPlotSettings*& pPlotSet,
	const AcGePoint3d& ptMin, const AcGePoint3d& ptMax) const
{
	//获得布局的id
	idLayout = GetLayoutId();
	AcDbLayout *pLayout = NULL;
	acdbOpenObject(pLayout, idLayout, AcDb::kForRead);
	//创建打印设置对象指针
	pPlotSet = new AcDbPlotSettings(pLayout->modelType());
	pPlotSet->copyFrom(pLayout);
	pLayout->close();

	//获得打印机验证器对象
	AcDbPlotSettingsValidator *pPSV = NULL;
	pPSV = acdbHostApplicationServices()->plotSettingsValidator();
	//更新打印设备列表
	pPSV->refreshLists(pPlotSet);
	//设置打印设备
	pPSV->setPlotCfgName(pPlotSet, m_strDeviceName);
	//设置图纸尺寸
	pPSV->setCanonicalMediaName(pPlotSet, m_strPixel);
	//设置打印范围为窗口
	pPSV->setPlotType(pPlotSet, AcDbPlotSettings::kWindow);

	//将视口设置到中心点（0,0,1）
	AcDbViewportTable *pViewTbl = nullptr;
	acdbCurDwg()->getViewportTable(pViewTbl, AcDb::kForRead);
	AcDbViewportTableRecord *pViewRcd = nullptr;
	pViewTbl->getAt(_T("*ACTIVE"), pViewRcd, AcDb::kForWrite);
	AcGePoint3d targetPt = pViewRcd->target();
	if (targetPt[X] != 0 || targetPt[Y] != 0)
	{
		AcGePoint3d rightPt(0, 0, 1);
		pViewRcd->setTarget(rightPt);
	}
	pViewRcd->close();
	pViewTbl->close();

	//设置打印范围,超出给范围的将打不出来
	pPSV->setPlotWindowArea(pPlotSet, ptMin[X], ptMin[Y],
		ptMax[X], ptMax[Y]);
	//设置打印样式
	pPSV->setCurrentStyleSheet(pPlotSet, m_strPrintStyle);
	//是否居中打印
	pPSV->setPlotCentered(pPlotSet, true);
	//设置是否采用标准比例
	pPSV->setUseStandardScale(pPlotSet, true);
	//布满图纸
	pPSV->setStdScaleType(pPlotSet, AcDbPlotSettings::kScaleToFit);
	//设置打印方向
	switch (static_cast<int>(m_nRotation))
	{
	case 0:
		pPSV->setPlotRotation(pPlotSet, AcDbPlotSettings::k0degrees);
		break;
	case 90:
		pPSV->setPlotRotation(pPlotSet, AcDbPlotSettings::k90degrees);
		break;
	case 180:
		pPSV->setPlotRotation(pPlotSet, AcDbPlotSettings::k180degrees);
		break;
	case 270:
		pPSV->setPlotRotation(pPlotSet, AcDbPlotSettings::k270degrees);
		break;
	default:
		pPSV->setPlotRotation(pPlotSet, AcDbPlotSettings::k0degrees);
		break;
	}

	return true;
}

bool CPhdPlot::Plot(AcDbObjectId& idLayout, AcDbPlotSettings* pPlotSet) const
{
	AcPlPlotEngine* pEngine = NULL;//创建打印引擎
	if (AcPlPlotFactory::createPublishEngine(pEngine) != Acad::eOk)
	{
		acedAlert(_T("打印失败!"));
		pPlotSet->close();
		return false;
	}

	// 打印进度对话框
	AcPlPlotProgressDialog *pPlotProgDlg = acplCreatePlotProgressDialog(acedGetAcadFrame()->m_hWnd, false, 1);
	pPlotProgDlg->setPlotMsgString(AcPlPlotProgressDialog::kDialogTitle, _T("打印进度"));
	pPlotProgDlg->setPlotMsgString(AcPlPlotProgressDialog::kCancelJobBtnMsg, _T("Cancel Job"));
	pPlotProgDlg->setPlotMsgString(AcPlPlotProgressDialog::kCancelSheetBtnMsg, _T("取消"));
	pPlotProgDlg->setPlotMsgString(AcPlPlotProgressDialog::kSheetSetProgressCaption, _T("Job Progress"));
	pPlotProgDlg->setPlotMsgString(AcPlPlotProgressDialog::kSheetProgressCaption, _T("状态: < 正在重生成图纸 > "));
	pPlotProgDlg->setPlotProgressRange(0, 100);
	pPlotProgDlg->onBeginPlot();
	pPlotProgDlg->setIsVisible(false);

	Acad::ErrorStatus es;
	//begin plot
	es = pEngine->beginPlot(pPlotProgDlg);

	AcPlPlotPageInfo pageInfo;//打印页信息
	AcPlPlotInfo plotInfo; //打印信息
	plotInfo.setLayout(idLayout);// 设置布局
	plotInfo.setOverrideSettings(pPlotSet);// 重置参数
	AcPlPlotInfoValidator validator;//创建打印信息验证器
	validator.setMediaMatchingPolicy(AcPlPlotInfoValidator::kMatchEnabled);
	es = validator.validate(plotInfo);
	// begin document
	const TCHAR *szDocName = acDocManager->curDocument()->fileName();
	es = pEngine->beginDocument(plotInfo, szDocName, NULL, 1, true, m_strOutPath);

	//给打印机和进度对话框发送消息
	pPlotProgDlg->onBeginSheet();
	pPlotProgDlg->setSheetProgressRange(0, 100);
	pPlotProgDlg->setSheetProgressPos(0);
	//begin page
	es = pEngine->beginPage(pageInfo, plotInfo, true);
	es = pEngine->beginGenerateGraphics();
	es = pEngine->endGenerateGraphics();
	//end page
	es = pEngine->endPage();
	pPlotProgDlg->setSheetProgressPos(100);
	pPlotProgDlg->onEndSheet();
	pPlotProgDlg->setPlotProgressPos(100);
	//end document
	es = pEngine->endDocument();
	//end plot
	es = pEngine->endPlot();
	//返回资源
	pEngine->destroy();
	pEngine = NULL;
	pPlotProgDlg->destroy();
	pPlotSet->close();

	return true;
}

