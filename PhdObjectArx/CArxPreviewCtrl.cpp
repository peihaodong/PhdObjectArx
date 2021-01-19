/********************************************************************
描 述： 用来预览DWG图形的控件
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
	//求出密度
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
	m_hPanCursor = NULL; // 移动时的图标
	m_hCrossCursor = NULL; // 十字图标
	m_hOrbitCursor = NULL; // 旋转图标
	m_pView = NULL; // 图形系统中的视图，用来绘制图形的区域
	m_pDevice = NULL; // 图形系统中的设备，
	m_pModel = NULL;

	m_bPanning = false; // 是否处于移动图形状态
	m_bOrbiting = false; // 是否处于旋转图形状态
	m_pDb = NULL; // 该预览空间绑定的数据库 
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
	//刷新图形系统视图
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
	//设置光标样式
	m_bOrbiting = true;
	SetCapture();

	::SetClassLong(m_hWnd, GCL_HCURSOR, NULL);
	::SetCursor(m_hOrbitCursor);

	m_StartPt = point;
}

void Phd::CArxPreviewCtrl::OnMButtonDown(UINT nFlags, CPoint point) 
{
	//开始移动
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

//函数功能:鼠标滚轮放大缩小视图
// void Phd::CArxPreviewCtrl::OnMouseMove(UINT nFlags, CPoint point) 
// {
// 	if (m_pView)
// 	{
// 		if (m_bPanning)
// 		{
// 			//完成从设备坐标系统到世界坐标系统的转换
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
// 			// 从最后和新的鼠标位置计算出两个矢量
// 			AcGeVector3d last_vector ((m_StartPt.x - centerX) / radius,
// 				-(m_StartPt.y - centerY) / radius,
// 				0.0);
// 
// 			if (last_vector.lengthSqrd () > 1.0) // 超出半径范围
// 				last_vector.normalize ();
// 			else
// 				last_vector.z = sqrt (1.0 - last_vector.x * last_vector.x - last_vector.y * last_vector.y);
// 
// 			AcGeVector3d new_vector((point.x - centerX) / radius,
// 				-(point.y - centerY) / radius,
// 				0.0);
// 
// 			if (new_vector.lengthSqrd () > 1.0) // 超出半径范围
// 				new_vector.normalize ();
// 			else
// 				new_vector.z = sqrt (1.0 - new_vector.x * new_vector.x - new_vector.y * new_vector.y);
// 
// 			// 确定相机操作的角度
// 			AcGeVector3d rotation_vector (last_vector);
// 			rotation_vector = rotation_vector.crossProduct (new_vector); // rotation_vector = last_vector x new_vector
// 
// 			AcGeVector3d work_vector (rotation_vector);
// 			work_vector.z = 0.0f; // rotation_vector到xy平面的投影
// 
// 			double roll_angle = atan2 (work_vector.x, work_vector.y); // 假设相机的向上矢量是朝上的
// 
// 			// 计算向上的矢量和工作矢量的夹角 
// 			double length = rotation_vector.length ();
// 			double orbit_y_angle = (length != 0.0) ? acos (rotation_vector.z / length) + Half_Pi : Half_Pi; // represents inverse cosine of the dot product of the
// 			if (length > 1.0f) 
// 				length = 1.0f; 
// 
// 			double rotation_angle = asin (length); 
// 
// 			// view操作
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
	//直接关闭cad 非模态对话框中提取不到gsmanager
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

// 	//如果这个数据库不是当前数据库，下次就把它delete
// 	if (m_pDb) 
// 	{
// 		if (m_pDb!=acdbCurDwg())
// 		{
// 			delete m_pDb;
// 		}
// 		m_pDb = NULL;
// 	}
	//如果这个数据库是该类创建的，下次就把它delete
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

//函数功能:传入dwg文件即可预览
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


//函数功能:传入数据库指针即可预览数据库中的实体
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


//函数功能:获得当前视口的信息。
//输出参数:height 视口高度，width 视口宽度，target 视口中心点，viewDir 视口的观察向量，twist 扭曲的视口
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

//函数功能:初始化图形系统
void Phd::CArxPreviewCtrl::InitGS(HINSTANCE hRes)
{
	// 加载光标
// 	if (m_hPanCursor == NULL)
// 		m_hPanCursor = LoadCursor(hRes,MAKEINTRESOURCE(IDC_PAN));
// 	if (m_hCrossCursor == NULL)
// 		m_hCrossCursor = LoadCursor(hRes,MAKEINTRESOURCE(IDC_CROSS));
// 	if (m_hOrbitCursor == NULL)
// 		m_hOrbitCursor = LoadCursor(hRes,MAKEINTRESOURCE(IDC_ORBIT));
// 	::SetClassLong(m_hWnd,GCL_HCURSOR,NULL);

	// 初始化视图

	// 获得图形系统管理器
	AcGsManager *pGsManager = acgsGetGsManager();
	//RXASSERT(pGsManager);
	// 获得图形系统类工厂
#if ZRX < 21
	AcGsClassFactory *pFactory = pGsManager->getGSClassFactory();
#else
	AcGsGraphicsKernel *pFactory = pGsManager->getGSClassFactory();
#endif
	//RXASSERT(pFactory);

	// 创建图形系统设备
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
	// 创建图形系统视图
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


// 缩放到整个图纸可见
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

//函数功能:获得块中的所有实体
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

//函数功能:获得实体的范围
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
