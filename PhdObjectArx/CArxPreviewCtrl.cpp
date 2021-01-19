/********************************************************************
�� ���� ����Ԥ��DWGͼ�εĿؼ�
*********************************************************************/

#include "StdAfx.h"
#include "CArxPreviewCtrl.h"
#include "dbents.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void Phd::CArxPreviewCtrl::SetCustomPreview(double dScreenWidth, double dPixelWidth, double dPixelLength)
{
	m_bCustomPreView = true;
	//����ܶ�
	double dRealScreenWidth = dScreenWidth * 1000;
	m_dDensity = dRealScreenWidth / dPixelWidth;
	//
	m_dPixelWidth = dPixelWidth;
	m_dPixelLength = dPixelLength;
}

Phd::CArxPreviewCtrl::CArxPreviewCtrl()
	:m_bNewself(false)
	, m_bCustomPreView(false)
	,m_dDensity(0)
	, m_dPixelLength(0)
	,m_dPixelWidth(0)
	,m_nBackgroundColorIndex(-1)
{
	m_hPanCursor = NULL; // �ƶ�ʱ��ͼ��
	m_hCrossCursor = NULL; // ʮ��ͼ��
	m_hOrbitCursor = NULL; // ��תͼ��
	m_pView = NULL; // ͼ��ϵͳ�е���ͼ����������ͼ�ε�����
	m_pDevice = NULL; // ͼ��ϵͳ�е��豸��
	m_pModel = NULL;

	m_bPanning = false; // �Ƿ����ƶ�ͼ��״̬
	m_bOrbiting = false; // �Ƿ�����תͼ��״̬
	m_pDb = NULL; // ��Ԥ���ռ�󶨵����ݿ� 
}

Phd::CArxPreviewCtrl::~CArxPreviewCtrl()
{
	Clear();
}


BEGIN_MESSAGE_MAP(Phd::CArxPreviewCtrl, CStatic)
	//{{AFX_MSG_MAP(CPreviewCtrl)
	ON_WM_PAINT()
	ON_WM_SIZE()
// 	ON_WM_MOUSEWHEEL()
// 	ON_WM_LBUTTONDOWN()
 	ON_WM_MBUTTONDOWN()
 	ON_WM_MBUTTONUP()
 	ON_WM_MOUSEMOVE()
	ON_WM_NCHITTEST()
	ON_WM_SETFOCUS()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
//	ON_WM_LBUTTONDBLCLK()
	
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreviewCtrl message handlers

void Phd::CArxPreviewCtrl::OnPaint() 
{
	CPaintDC dc(this); 
	//ˢ��ͼ��ϵͳ��ͼ
	if (m_pView) 
	{
		m_pView->invalidate(); 
		m_pView->update();
	} 
}

void Phd::CArxPreviewCtrl::OnSize(UINT nType, int cx, int cy) 
{
	CRect rect;
	if (m_pDevice) 
	{
		GetClientRect(&rect);
		m_pDevice->onSize(rect.Width(), rect.Height());
	}
}

BOOL Phd::CArxPreviewCtrl::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	if (m_pView)
	{
		if (zDelta < 0)
			m_pView->zoom(0.5);
		else
			m_pView->zoom(1.5);

		Invalidate();
	}
	return TRUE;
}

void Phd::CArxPreviewCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	SetFocus();
	//���ù����ʽ
	m_bOrbiting = true;
	SetCapture();

	::SetClassLong(m_hWnd, GCL_HCURSOR, NULL);
	::SetCursor(m_hOrbitCursor);

	m_StartPt = point;
}

void Phd::CArxPreviewCtrl::OnMButtonDown(UINT nFlags, CPoint point) 
{
	//��ʼ�ƶ�
	m_bPanning = true;
	SetCapture();

	::SetClassLong(m_hWnd,GCL_HCURSOR,NULL);
	::SetCursor(m_hPanCursor);

	m_StartPt = point;

}
void Phd::CArxPreviewCtrl::OnMButtonUp(UINT nFlags, CPoint point) 
{
	ReleaseCapture();
	m_bPanning = false;
	::SetClassLong(m_hWnd,GCL_HCURSOR,(long)m_hCrossCursor);
}

//��������:�����ַŴ���С��ͼ
// void Phd::CArxPreviewCtrl::OnMouseMove(UINT nFlags, CPoint point) 
// {
// 	if (m_pView)
// 	{
// 		if (m_bPanning)
// 		{
// 			//��ɴ��豸����ϵͳ����������ϵͳ��ת��
// 			AcGeVector3d pan_vec(-(point.x-m_StartPt.x),point.y-m_StartPt.y,0);
// 			pan_vec.transformBy(m_pView->viewingMatrix() * m_pView->worldToDeviceMatrix().inverse());
// 			m_pView->dolly(pan_vec);
// 			Invalidate();
// 			m_StartPt = point;
// 		}
// 		else if (m_bOrbiting)
// 		{
// 			const double Half_Pi = 1.570796326795;
// 
// 			AcGsDCRect view_rect;
// 			m_pView->getViewport (view_rect);
// 
// 			int nViewportX = (view_rect.m_max.x - view_rect.m_min.x) + 1;
// 			int nViewportY = (view_rect.m_max.y - view_rect.m_min.y) + 1;
// 
// 			int centerX = int(nViewportX / 2.0f) + view_rect.m_min.x;
// 			int centerY = int(nViewportY / 2.0f) + view_rect.m_min.y; 
// 
// 			const double radius = min (nViewportX, nViewportY) * 0.4f;
// 
// 			// �������µ����λ�ü��������ʸ��
// 			AcGeVector3d last_vector ((m_StartPt.x - centerX) / radius,
// 				-(m_StartPt.y - centerY) / radius,
// 				0.0);
// 
// 			if (last_vector.lengthSqrd () > 1.0) // �����뾶��Χ
// 				last_vector.normalize ();
// 			else
// 				last_vector.z = sqrt (1.0 - last_vector.x * last_vector.x - last_vector.y * last_vector.y);
// 
// 			AcGeVector3d new_vector((point.x - centerX) / radius,
// 				-(point.y - centerY) / radius,
// 				0.0);
// 
// 			if (new_vector.lengthSqrd () > 1.0) // �����뾶��Χ
// 				new_vector.normalize ();
// 			else
// 				new_vector.z = sqrt (1.0 - new_vector.x * new_vector.x - new_vector.y * new_vector.y);
// 
// 			// ȷ����������ĽǶ�
// 			AcGeVector3d rotation_vector (last_vector);
// 			rotation_vector = rotation_vector.crossProduct (new_vector); // rotation_vector = last_vector x new_vector
// 
// 			AcGeVector3d work_vector (rotation_vector);
// 			work_vector.z = 0.0f; // rotation_vector��xyƽ���ͶӰ
// 
// 			double roll_angle = atan2 (work_vector.x, work_vector.y); // �������������ʸ���ǳ��ϵ�
// 
// 			// �������ϵ�ʸ���͹���ʸ���ļн� 
// 			double length = rotation_vector.length ();
// 			double orbit_y_angle = (length != 0.0) ? acos (rotation_vector.z / length) + Half_Pi : Half_Pi; // represents inverse cosine of the dot product of the
// 			if (length > 1.0f) 
// 				length = 1.0f; 
// 
// 			double rotation_angle = asin (length); 
// 
// 			// view����
// 			m_pView->roll( roll_angle); 
// 			m_pView->orbit( 0.0f, orbit_y_angle); 
// 			m_pView->orbit( rotation_angle, 0.0f); 
// 			m_pView->orbit( 0.0f, -orbit_y_angle); 
// 			m_pView->roll(-roll_angle); 
// 			Invalidate();
// 			m_StartPt = point;
// 		}
// 		else
// 		{
// 			::SetClassLong(m_hWnd,GCL_HCURSOR,(long)m_hCrossCursor);
// 			SetFocus();
// 		}
// 	}
// 
// }

LRESULT Phd::CArxPreviewCtrl::OnNcHitTest(CPoint point)
{
	return HTCLIENT;
}


void Phd::CArxPreviewCtrl::OnSetFocus(CWnd* pOldWnd) 
{
	::SetClassLong(m_hWnd, GCL_HCURSOR, (long)m_hCrossCursor);

}

void Phd::CArxPreviewCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	m_bOrbiting = false;
	::SetClassLong(m_hWnd,GCL_HCURSOR,(long)m_hCrossCursor);
	ReleaseCapture();
}

void Phd::CArxPreviewCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	double x = point.x;
	double y = point.y;
	CString sx, sy;
	sx.Format(_T("%.2f"),x);
	sy.Format(_T("%.2f"), y);
	AfxMessageBox( _T("x=")+sx+_T("y=") + sy);
}


void Phd::CArxPreviewCtrl::Clear()
{
	m_strCurDwgPath = _T("");

	AcGsManager *pGsManager = acgsGetGsManager();
	//ֱ�ӹر�cad ��ģ̬�Ի�������ȡ����gsmanager
	if (pGsManager==NULL)
	{
		return;
	}

	//RXASSERT(pGsManager);
	if (m_pView) 
	{
		m_pView->eraseAll();
		if (m_pDevice) 
		{
			bool b = m_pDevice->erase(m_pView);
			//RXASSERT(b);
		}

		

#if ZRX < 21
		AcGsClassFactory *pFactory = pGsManager->getGSClassFactory();
		pFactory->deleteView(m_pView);
#else
		AcGsGraphicsKernel *pFactory = pGsManager->getGSClassFactory();
		pFactory->deleteView(m_pView);
#endif

		m_pView = NULL;
	}

	if (m_pModel) 
	{
		pGsManager->destroyAutoCADModel(m_pModel);
		m_pModel = NULL;
	}

	if (m_pDevice) 
	{
		pGsManager->destroyAutoCADDevice(m_pDevice);
		m_pDevice = NULL;
	}

// 	//���������ݿⲻ�ǵ�ǰ���ݿ⣬�´ξͰ���delete
// 	if (m_pDb) 
// 	{
// 		if (m_pDb!=acdbCurDwg())
// 		{
// 			delete m_pDb;
// 		}
// 		m_pDb = NULL;
// 	}
	//���������ݿ��Ǹ��ഴ���ģ��´ξͰ���delete
	if (m_pDb && m_bNewself)
	{
		delete m_pDb;
		m_pDb = NULL;
		m_bNewself = false;
	}

}

void Phd::CArxPreviewCtrl::EraseAll()
{
	Clear();
	InitGS(NULL);
	m_pView->eraseAll();
	OnPaint();
}

//��������:����dwg�ļ�����Ԥ��
BOOL Phd::CArxPreviewCtrl::Init(LPCTSTR szDwgFile, CString strBlkTblRcd)
{ 
	Clear();

	m_pDb = new AcDbDatabase(false,true);
	m_bNewself = true;

  	Acad::ErrorStatus es = m_pDb->readDwgFile(szDwgFile);

	if (es != Acad::eOk)
	{
		delete m_pDb;
		m_pDb = NULL;
	}

	BOOL rt = InitInner(m_pDb,strBlkTblRcd);
	if (rt == TRUE)
		m_strCurDwgPath = szDwgFile;

	return rt;
}


//��������:�������ݿ�ָ�뼴��Ԥ�����ݿ��е�ʵ��
BOOL Phd::CArxPreviewCtrl::Init(AcDbDatabase *pDb, CString strBlkTblRcd)
{ 
	Clear();

	BOOL bRs = InitInner(pDb, strBlkTblRcd);
	if (bRs)
	{
		ZoomE();
	}

	return bRs;
}


//��������:��õ�ǰ�ӿڵ���Ϣ��
//�������:height �ӿڸ߶ȣ�width �ӿڿ�ȣ�target �ӿ����ĵ㣬viewDir �ӿڵĹ۲�������twist Ť�����ӿ�
bool Phd::CArxPreviewCtrl::GetActiveViewPortInfo (ads_real &height, ads_real &width, 
											 AcGePoint3d &target, AcGeVector3d &viewDir, 
											 ads_real &viewTwist, bool getViewCenter)
{ 
	AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase(); 

	if (pDb == NULL)
		return false;

	AcDbViewportTable *pVTable = NULL;
	Acad::ErrorStatus es = pDb->getViewportTable (pVTable, AcDb::kForRead);

	if (es == Acad::eOk)
	{
		AcDbViewportTableRecord *pViewPortRec = NULL;
		es = pVTable->getAt (_T("*Active"), pViewPortRec, AcDb::kForRead);
		if (es == Acad::eOk)
		{
			height = pViewPortRec->height ();
			width = pViewPortRec->width ();

			if (getViewCenter == true)
			{
				struct resbuf rb;
				memset (&rb, 0, sizeof (struct resbuf));
				acedGetVar (_T("VIEWCTR"), &rb);

				target = AcGePoint3d (rb.resval.rpoint[X], rb.resval.rpoint[Y], rb.resval.rpoint[Z]);
			}
			else
			{

				target = pViewPortRec->target ();
			} 

			viewDir = pViewPortRec->viewDirection ();

			viewTwist = pViewPortRec->viewTwist ();
		}
		pVTable->close ();
		pViewPortRec->close(); 
	} 

	return (true);
}

//��������:��ʼ��ͼ��ϵͳ
void Phd::CArxPreviewCtrl::InitGS(HINSTANCE hRes)
{
	// ���ع��
// 	if (m_hPanCursor == NULL)
// 		m_hPanCursor = LoadCursor(hRes,MAKEINTRESOURCE(IDC_PAN));
// 	if (m_hCrossCursor == NULL)
// 		m_hCrossCursor = LoadCursor(hRes,MAKEINTRESOURCE(IDC_CROSS));
// 	if (m_hOrbitCursor == NULL)
// 		m_hOrbitCursor = LoadCursor(hRes,MAKEINTRESOURCE(IDC_ORBIT));
// 	::SetClassLong(m_hWnd,GCL_HCURSOR,NULL);

	// ��ʼ����ͼ

	// ���ͼ��ϵͳ������
	AcGsManager *pGsManager = acgsGetGsManager();
	//RXASSERT(pGsManager);
	// ���ͼ��ϵͳ�๤��
#if ZRX < 21
	AcGsClassFactory *pFactory = pGsManager->getGSClassFactory();
#else
	AcGsGraphicsKernel *pFactory = pGsManager->getGSClassFactory();
#endif
	//RXASSERT(pFactory);

	// ����ͼ��ϵͳ�豸
#if ZRX < 21
	m_pDevice = pGsManager->createAutoCADDevice(m_hWnd);
#else
	m_pDevice = pGsManager->createAutoCADDevice(*pFactory, m_hWnd);
#endif
	if (m_nBackgroundColorIndex != -1)
	{
		AcDbLine* pLine = new AcDbLine(AcGePoint3d::kOrigin,AcGePoint3d(10,10,0));
		pLine->setColorIndex(m_nBackgroundColorIndex);
		AcGsColor colorBackground;
		AcCmColor color = pLine->color();
		delete pLine;
		colorBackground.m_red = color.red();
		colorBackground.m_green = color.green();
		colorBackground.m_blue = color.blue();
		m_pDevice->setBackgroundColor(colorBackground);
	}
	
	CRect rect;
	GetClientRect(&rect);

	m_pDevice->onSize(rect.Width(), rect.Height());
	// ����ͼ��ϵͳ��ͼ
	m_pView = pFactory->createView();
	//RXASSERT(m_pView);
#if ZRX < 21
	m_pModel = pGsManager->createAutoCADModel();
#else
	m_pModel = pGsManager->createAutoCADModel(*pFactory);
#endif
	
	//RXASSERT(m_pModel);

	m_pDevice->add(m_pView);

	double height = 0.0, width = 0.0, viewTwist = 0.0;
	AcGePoint3d ptTargetView;
	AcGeVector3d vecViewDir;
	GetActiveViewPortInfo (height, width, ptTargetView, vecViewDir, viewTwist, true);

	m_pView->setView(ptTargetView + vecViewDir, ptTargetView,
		AcGeVector3d(0.0, 1.0, 0.0), 1.0, 1.0); 

}

BOOL Phd::CArxPreviewCtrl::InitInner(AcDbDatabase *pDb, CString strBlkTblRcd)
{
	if (pDb == NULL)
	{
		m_pDb = new AcDbDatabase(true, true); 
		m_bNewself = true;
	}
	else
	{
		m_pDb = pDb;
	}

	if (m_pDb == NULL)
		return FALSE;

	Acad::ErrorStatus es = Acad::eOk;
	AcDbBlockTableRecord *pRec = NULL;
	AcDbBlockTable *pTab = NULL;
	AcDbObjectId idRec = NULL;
	if ((es = m_pDb->getBlockTable(pTab, AcDb::kForRead))!=Acad::eOk)
		return FALSE;

	if ((es = pTab->getAt(strBlkTblRcd,pRec,AcDb::kForRead))!=Acad::eOk)
	{
		pTab->close();
		return FALSE;
	}
	if ((es=pTab->getAt(strBlkTblRcd,idRec))!=Acad::eOk)
	{
		pTab->close();
		pRec->close();
		return FALSE;
	}
	pTab->close();

//	AcDbObjectId idRec = pRec->id();
	AcDbObjectIdArray aridEnt;
	GetAllEnt(idRec, aridEnt);
	m_extents = AcDbExtents();
	GetEntExtents(aridEnt, m_extents);

	/*HINSTANCE hInstance;*/
	InitGS(NULL);

	m_pView->add(pRec, m_pModel); 

	pRec->close();
	ZoomE();

	return TRUE;
}


// ���ŵ�����ͼֽ�ɼ�
void Phd::CArxPreviewCtrl::ZoomE()
{
	AcGePoint3d ptTargetView;
	Mid(m_extents.maxPoint(), m_extents.minPoint(), ptTargetView);

	if (!m_bCustomPreView)
	{
		double dLenght = m_extents.maxPoint().x - m_extents.minPoint().x;
		double dWidth = m_extents.maxPoint().y - m_extents.minPoint().y;
		m_pView->setView(ptTargetView + AcGeVector3d::kZAxis, ptTargetView, AcGeVector3d::kYAxis, dLenght*1.05, dWidth*1.05);
	}
	else
	{
		double dLength = m_dDensity * m_dPixelLength;
		double dWidth = m_dDensity * m_dPixelWidth;
		m_pView->setView(ptTargetView + AcGeVector3d::kZAxis, ptTargetView, AcGeVector3d::kYAxis, dLength, dWidth);
	}

	OnPaint();
}

void Phd::CArxPreviewCtrl::Mid(const AcGePoint3d& pt1, const AcGePoint3d& pt2, AcGePoint3d& ptMid)
{ 
	ptMid.x = 0.5 *(pt1.x + pt2.x);
	ptMid.y = 0.5 *(pt1.y + pt2.y);
	ptMid.z = 0.5 *(pt1.z + pt2.z);
}

//��������:��ÿ��е�����ʵ��
void Phd::CArxPreviewCtrl::GetAllEnt(const AcDbObjectId& idBlockRec, AcDbObjectIdArray& IDArray)
{
	IDArray.setPhysicalLength(0);

	Acad::ErrorStatus es;

	AcDbBlockTableRecord *pBlkRec = NULL;
	if (Acad::eOk != (es = acdbOpenObject(pBlkRec,idBlockRec,AcDb::kForRead))) 
	{ 
		return;
	}

	AcDbBlockTableRecordIterator *pIt = NULL;
	pBlkRec->newIterator(pIt);
	pBlkRec->close();

	for (pIt->start(); !pIt->done(); pIt->step())
	{
		AcDbObjectId idEnt;
		if (Acad::eOk == pIt->getEntityId(idEnt)) 
		{ 
			IDArray.append(idEnt);
		}
	}
	delete pIt;
	pIt = NULL;
}

//��������:���ʵ��ķ�Χ
Acad::ErrorStatus Phd::CArxPreviewCtrl::GetEntExtents(const AcDbObjectId& idEnt, AcDbExtents& extents)
{
	Acad::ErrorStatus es;
	AcDbEntity *pEnt = NULL;
	if (Acad::eOk == acdbOpenObject(pEnt, idEnt, AcDb::kForRead)) 
	{ 
		AcDbBlockReference *pBlkRef = AcDbBlockReference::cast(pEnt);
		if (pBlkRef) 
		{ 
			es = pBlkRef->geomExtentsBestFit(extents);
		}
		else
		{
			es = pEnt->getGeomExtents(extents);
		}
		pEnt->close();
	}

	return (es);
}


void Phd::CArxPreviewCtrl::GetEntExtents(const AcDbObjectIdArray& aridEnt, AcDbExtents& extents)
{
	for (int i = 0; i<aridEnt.length();i++)
	{
		AcDbExtents tem;
		if (GetEntExtents(aridEnt[i], tem) == Acad::eOk) 
		{ 
			extents.addExt(tem);
		}
	}
}
