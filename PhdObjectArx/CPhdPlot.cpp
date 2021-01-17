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
		m_strDeviceName = _T("DWG to PDF.pc5");//��ӡ������
		m_strOutPath = szPath;
	}
	else if (_tcsicmp(strSuffix, _T("tif")) == 0)
	{
		m_strDeviceName = _T("TIF.pc5");//��ӡ������
		m_strOutPath = szPath;
	}
	else if (_tcsicmp(strSuffix, _T("jpg")) == 0)
	{
		m_strDeviceName = _T("ZWCAD Virtual JPEG Plotter.pc5");//��ӡ������
		m_strOutPath = szPath;
	}
	else if (_tcsicmp(strSuffix, _T("dwf")) == 0)
	{
		m_strDeviceName = _T("DWF6 ePlot.pc5");//��ӡ������
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
	//�жϸ��ļ��Ƿ����
	if (!SetOutPath(szFilePath))
		return false;

	AcDbDatabase *pCurDb = acdbCurDwg();
	bool bNotCurDb = false;
	if (pCurDb != m_pDb)
	{
		bNotCurDb = true;
		acdbHostApplicationServices()->setWorkingDatabase(m_pDb);
	}

	//���ô�ӡ����
	AcDbObjectId idLayout;
	AcDbPlotSettings *pPlotSet = nullptr;
	SetPlotData(idLayout, pPlotSet,ptMin,ptMax);

	//��ʼ��ӡ
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
	//ȡ�ò��ֹ���������
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
	//��ò��ֵ�id
	idLayout = GetLayoutId();
	AcDbLayout *pLayout = NULL;
	acdbOpenObject(pLayout, idLayout, AcDb::kForRead);
	//������ӡ���ö���ָ��
	pPlotSet = new AcDbPlotSettings(pLayout->modelType());
	pPlotSet->copyFrom(pLayout);
	pLayout->close();

	//��ô�ӡ����֤������
	AcDbPlotSettingsValidator *pPSV = NULL;
	pPSV = acdbHostApplicationServices()->plotSettingsValidator();
	//���´�ӡ�豸�б�
	pPSV->refreshLists(pPlotSet);
	//���ô�ӡ�豸
	pPSV->setPlotCfgName(pPlotSet, m_strDeviceName);
	//����ͼֽ�ߴ�
	pPSV->setCanonicalMediaName(pPlotSet, m_strPixel);
	//���ô�ӡ��ΧΪ����
	pPSV->setPlotType(pPlotSet, AcDbPlotSettings::kWindow);

	//���ӿ����õ����ĵ㣨0,0,1��
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

	//���ô�ӡ��Χ,��������Χ�Ľ��򲻳���
	pPSV->setPlotWindowArea(pPlotSet, ptMin[X], ptMin[Y],
		ptMax[X], ptMax[Y]);
	//���ô�ӡ��ʽ
	pPSV->setCurrentStyleSheet(pPlotSet, m_strPrintStyle);
	//�Ƿ���д�ӡ
	pPSV->setPlotCentered(pPlotSet, true);
	//�����Ƿ���ñ�׼����
	pPSV->setUseStandardScale(pPlotSet, true);
	//����ͼֽ
	pPSV->setStdScaleType(pPlotSet, AcDbPlotSettings::kScaleToFit);
	//���ô�ӡ����
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
	AcPlPlotEngine* pEngine = NULL;//������ӡ����
	if (AcPlPlotFactory::createPublishEngine(pEngine) != Acad::eOk)
	{
		acedAlert(_T("��ӡʧ��!"));
		pPlotSet->close();
		return false;
	}

	// ��ӡ���ȶԻ���
	AcPlPlotProgressDialog *pPlotProgDlg = acplCreatePlotProgressDialog(acedGetAcadFrame()->m_hWnd, false, 1);
	pPlotProgDlg->setPlotMsgString(AcPlPlotProgressDialog::kDialogTitle, _T("��ӡ����"));
	pPlotProgDlg->setPlotMsgString(AcPlPlotProgressDialog::kCancelJobBtnMsg, _T("Cancel Job"));
	pPlotProgDlg->setPlotMsgString(AcPlPlotProgressDialog::kCancelSheetBtnMsg, _T("ȡ��"));
	pPlotProgDlg->setPlotMsgString(AcPlPlotProgressDialog::kSheetSetProgressCaption, _T("Job Progress"));
	pPlotProgDlg->setPlotMsgString(AcPlPlotProgressDialog::kSheetProgressCaption, _T("״̬: < ����������ͼֽ > "));
	pPlotProgDlg->setPlotProgressRange(0, 100);
	pPlotProgDlg->onBeginPlot();
	pPlotProgDlg->setIsVisible(false);

	Acad::ErrorStatus es;
	//begin plot
	es = pEngine->beginPlot(pPlotProgDlg);

	AcPlPlotPageInfo pageInfo;//��ӡҳ��Ϣ
	AcPlPlotInfo plotInfo; //��ӡ��Ϣ
	plotInfo.setLayout(idLayout);// ���ò���
	plotInfo.setOverrideSettings(pPlotSet);// ���ò���
	AcPlPlotInfoValidator validator;//������ӡ��Ϣ��֤��
	validator.setMediaMatchingPolicy(AcPlPlotInfoValidator::kMatchEnabled);
	es = validator.validate(plotInfo);
	// begin document
	const TCHAR *szDocName = acDocManager->curDocument()->fileName();
	es = pEngine->beginDocument(plotInfo, szDocName, NULL, 1, true, m_strOutPath);

	//����ӡ���ͽ��ȶԻ�������Ϣ
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
	//������Դ
	pEngine->destroy();
	pEngine = NULL;
	pPlotProgDlg->destroy();
	pPlotSet->close();

	return true;
}

