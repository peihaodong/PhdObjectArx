#pragma once



namespace PhdUtility {

	//功能：得到当前项目zrx文件路径
	CString GetCurZrxFilePath();

	//功能：得到当前项目zrx文件所在目录路径
	//返回的目录路径含带'\\'
	CString GetCurZrxFolderPath();

	//功能：加载cad菜单文件
	bool LoadCadMenu(const CString& strMenuFileName, const CString& strMenuGroupName);

	//功能：卸载cad菜单
	bool UnloadCadMenu(const CString& strMenuGroupName);

	//功能：加载zrx文件
	bool LoadZrxFile(LPCTSTR szFilePath);

	//功能：添加搜索路径
	bool AddSearchPath(LPCTSTR szSearchDir);

	//功能：将实体添加到模型空间
	AcDbObjectId PostToModelSpace(AcDbEntity* pEnt, AcDbDatabase *pDb = acdbCurDwg());
	// Summary:   添加实体到布局空间
	// Time:	  2020年6月5日 peihaodong
	// Explain:	  
	AcDbObjectId PostToPaperSpace(AcDbEntity* pEnt, AcDbDatabase *pDb = acdbCurDwg());


	//功能：按比例缩放实体
	bool ModifyEntByScale(AcDbEntity* pEnt,double dScale,const AcGePoint3d& ptBase);
	bool ModifyEntByScale(const AcDbObjectId& idEnt,double dScale,const AcGePoint3d& ptBase);
	bool ModifyEntByScale(const AcArray<AcDbEntity*>& arrpEnt,double dScale,
		const AcGePoint3d& ptBase);

	//功能：分解实体
	AcArray<AcDbEntity*> ExplodeEnt(AcDbEntity* pEnt);
	AcArray<AcDbEntity*> ExplodeEnt(const AcDbObjectId& idEnt);

	//功能：移动实体
	bool MoveEnt(AcDbEntity* pEnt, const AcGePoint3d &ptBase, const AcGePoint3d &ptDest);
	bool MoveEnt(const AcDbObjectIdArray& arrid, const AcGePoint3d &ptBase, const AcGePoint3d &ptDest);
	bool MoveEnt(const AcDbObjectId& idEnt, const AcGePoint3d &ptBase, const AcGePoint3d &ptDest);
	bool MoveEnt(const AcArray<AcDbEntity*>& arrEnt, const AcGePoint3d &ptBase, const AcGePoint3d &ptDest);

	//功能：旋转实体(弧度)
	bool RotateEnt(AcDbEntity *pEnt, const AcGePoint3d &ptBase, double rotation);
	bool RotateEnt(const AcArray<AcDbEntity*>& arrpEnt, const AcGePoint3d &ptBase, double rotation);

	//功能：偏移线段
	AcArray<AcDbCurve*> OffsetCurve(AcDbCurve* pCurve, double dOffsetDist);
	AcArray<AcDbCurve*> OffsetCurve(double dOffset, const AcGePoint3d& pt,
		AcDbCurve* pCurve,bool bOpposite = false);

	//得到向量方向在线段左右的正负值
	bool GetPosAngNegValue(AcDbCurve* pCurve, 
		const AcGePoint3d& ptBase, const AcGeVector3d& vecNormal);

	// Summary:   打断线段
	// Time:	  2020年4月9日 peihaodong
	// Explain:	  输入的点必须要用getClosestPointTo函数重新获得
	AcArray<AcDbCurve*> SplitCurve(AcDbCurve* pCurve, const AcGePoint3dArray& arrSplitPt);
	AcArray<AcDbCurve*> SplitCurve(AcDbCurve* pCurve, const AcGePoint3d& ptSplit);
	AcArray<AcDbCurve*> SplitCurve(const AcDbObjectId& idCurve,
		const AcGePoint3dArray& arrSplitPt);

	// Summary: 通过距离延伸线段  
	// Time:	  2020年2月12日 peihaodong
	// Explain:	  
	bool ExtendCurveByDist(AcDbPolyline* pPline, bool isStartPt, double dDist);
	// Summary:   延伸线段
	// Time:	  2020年2月26日 peihaodong
	// Explain:	  
	bool ExtendCurve(AcDbCurve* pBorder, AcDbCurve* pExtend, const AcGePoint3d& ptExtend);

	// Summary:   修剪线段
	// Time:	  2020年2月26日 peihaodong
	// Explain:	  
	bool TrimCurve(AcDbCurve* pBorder, AcDbCurve* pTrim,
		const AcGePoint3d& ptTrim, AcDbCurve*& pNewTrim);

	// Summary:   删除实体
	// Time:	  2019年11月5日 peihaodong
	// Explain:	  
	bool DeleteEnt(const AcDbObjectId& idEnt);
	void DeleteEnt(AcArray<AcDbEntity*>& arrpEnt);

	// Summary:   拷贝实体
	// Time:	  2019年11月22日 peihaodong
	// Explain:	  
	AcArray<AcDbEntity*> CopyEnt(const AcDbObjectIdArray& arrid);
	AcArray<AcDbEntity*> CopyEnt(const AcArray<AcDbEntity*>& arrp);
	AcDbEntity* CopyEnt(const AcDbObjectId& idEnt);

	// Summary:   镜像实体
	// Time:	  2020年3月5日 peihaodong
	// Explain:	  
	AcDbEntity* MirrorEnt(AcDbEntity* pEnt, const AcGePoint3d& pt1,
		const AcGePoint3d& pt2);
	AcArray<AcDbEntity*> MirrorEnt(const AcDbObjectIdArray& arrid, const AcGePoint3d& pt1,
		const AcGePoint3d& pt2);
	AcArray<AcDbEntity*> MirrorEnt(const AcArray<AcDbEntity*>& arrp, const AcGePoint3d& pt1,
		const AcGePoint3d& pt2);

	// Summary:   环形矩阵
	// Time:	  2020年3月5日 peihaodong
	// Explain:	  nCurNum：当前需要的数量；nSum：总共的数量
	AcArray<AcDbEntity*> AnnularMatrix(const AcDbObjectIdArray& arrid,
		const AcGePoint3d& ptBase, int nCurNum, int nSum);
	AcArray<AcDbEntity*> AnnularMatrix(const AcArray<AcDbEntity*>& arrp,
		const AcGePoint3d& ptBase, int nYxcs, int nSum);

	//功能：得到圆弧凸度
	double GetArcBulge(AcDbArc* pArc);
	double GetArcBulge(double dAngleStart, double dAngleEnd);
	double GetArcBulge(const AcDbObjectId& idArc);
	double GetArcBulge(AcDbCurve* pCurve);
	double GetArcBulge(const AcGeCircArc2d& geArc);

	//功能：得到几何类对象
	AcGeLine2d GetGeLine2d(AcDbLine* pLine);
	AcGeLineSeg2d GetGeLineSeg2d(AcDbLine* pLine);
	AcGeLineSeg2d GetGeLineSeg2d(const AcDbObjectId& idLine);
	AcGeCircArc2d GetGeCircArc(AcDbArc* pArc);
	AcGeCircArc2d GetGeCircArc(AcDbCircle* pCircle);
	AcGeLineSeg2d GetGeLineSeg2d(AcDbPolyline* pPolyline, unsigned int unIndex);
	AcGeCircArc2d GetGeCircArc2d(AcDbPolyline* pPolyline, unsigned int unIndex);

	//功能：得到交点
	bool GetIntersectPoint(const AcGeLine2d& geLine1, const AcGeLine2d& geLine2, 
		AcGePoint3d& ptIntersect);
	bool GetIntersectPoint(const AcGeLineSeg2d& geLine1, const AcGeLineSeg2d& geLine2,
		AcGePoint3d& ptIntersect);
	bool GetIntersectPoint(const AcGeCircArc2d& geCircArc1, const AcGeCircArc2d& geCircArc2, int& nNum,
		AcGePoint3dArray& arrptIntersect);
	bool GetIntersectPoint(const AcGeLine2d& geLine, const AcGeCircArc2d& geCircArc, int& nNum,
		AcGePoint3dArray& arrptIntersect);
	bool GetIntersectPoint(const AcGeLineSeg2d& geLine1, const AcGeLine2d& geLine2,
		AcGePoint3d& ptIntersect);
	bool GetIntersectPoint(const AcGeLineSeg2d& geLine, const AcGeCircArc2d& geCircArc, int& nNum,
		AcGePoint3dArray& arrptIntersect);
	
	//功能：得到向量在另一向量上的投影向量
	// Parameters: 	
	//    ptBase		- 	输入基点
	//    vctOffset		- 	输入被投影的向量
	//    vctDirection		- 	输入方向向量
	AcGeVector3d GetProjectVector(const AcGePoint3d& ptBase, const AcGeVector3d& vctOffset,
		const AcGeVector3d& vctDirection);

	// Summary:   得到线段某点的切线向量
	// Time:	  2020年1月13日 peihaodong
	// Explain:	  
	AcGeVector3d GetTangentLineVec(const AcGePoint3d& ptOnCurve,
		const AcDbObjectId& idCurve);
	AcGeVector3dArray GetTangLineVecs(const AcGePoint3d& pt,
		const AcDbObjectId& idCurve);
	AcGeVector3dArray GetTangLineVecs(const AcGePoint3d& pt,
		AcDbCurve* pCurve);

	bool GetTangentLineVecs(AcDbPolyline* pPline,const AcGePoint3d& pt,
		AcGeVector3dArray& arrvec);

	//功能：得到两直线的角平分线向量
	// Parameters: 	
	//    idLine1		- 	输入直线1的id
	//    idLine2		- 	输入直线2的id
	//    midVector		- 	输出角平分线向量
	AcGeVector2d GetMidVectorOfLines(AcDbLine* pLine1, AcDbLine* pLine2);

	// Summary:   通过向量和点得到和X轴的角度(0~2π)
	// Time:	  2020年1月14日 peihaodong
	// Explain:	  
	double GetAngle(const AcGePoint3d& pt, const AcGeVector3d& vec);

	//功能：得到线段长度
	double GetCurveLength(AcDbCurve* pCurve);

	//功能：判断点是否在线段上
	bool IsPtOnCurve(const AcGePoint3d& pt, AcDbCurve* pCurve,double dTol = 0);

	//功能：得到两直线的夹角
	double GetAngleOfLines(AcDbLine* pLine1, AcDbLine* pLine2);

	// Summary:   得到线段上距离该点最近的点
	// Time:	  2020年4月17日 peihaodong
	// Explain:	  
	AcGePoint3d GetClosedPtInCurve(AcDbCurve* pCurve, const AcGePoint3d& pt);
	bool GetClosedPtInCurve(const AcDbObjectId& idCurve,const AcGePoint3d& pt,
		AcGePoint3d& ptClosed);

	// Summary: 	对点的数组进行排序
	// Parameters: 	
	//    PointArr		- 	输入点的数组
	//    bVertical		- 	输入排序标识	false:按水平排序	true:按垂直排序
	AcGePoint3dArray SortPtArr(const AcGePoint3dArray& PointArr, bool bVertical = false);

	//功能：显示/关闭进度条
	void ShowProgressBar(const CString& strName, bool bStart);
	//功能：设置进度条
	//参数：
	//	nCurIndex	-	当前下标
	//	nSum		-	总的下标数量
	void SetProgressBar(int nCurIndex, int nSum);

	//功能：设置实体被选中
	void SetEntSelected(const AcDbObjectIdArray& arridEnt, bool bSeled = true, bool bHighlight = false);

	//功能：调整绘图次序
	bool SetEntToBottom(const AcDbObjectId& id, AcDbDatabase* pDb = acdbCurDwg());

	// Summary: 	拉伸实体
	// Parameters: 	
	//    arrid		- 	输入需要被拉伸的实体id数组
	//    ptCorner1		- 	输入被拉伸的角点1
	//    ptCorner2		- 	输入被拉伸的角点2
	//    ptBase		- 	输入基点
	//    ptTarget		- 	输入目标点
	bool StretchEnt(const AcDbObjectIdArray& arrid, const AcGePoint3d& ptCorner1, const AcGePoint3d& ptCorner2,
		const AcGePoint3d& ptBase, const AcGePoint3d& ptTarget);

	//功能：得到经过点坐标上的实体id
	AcDbObjectIdArray GetEntIdByPt(const AcGePoint3d& pt,bool bAll = false);

	//功能：得到目录下所有的dwg图纸路径
	AcArray<CString> GetAllDwgPath(LPCTSTR szFolderPath);

	// Summary:   得到目录下所有的dwg图纸名
	// Time:	  2019年10月22日
	// Explain:	  
	AcArray<CString> GetAllDwgName(LPCTSTR szFolderPath);

	// Summary:   得到实体外包矩形
	// Time:	  2019年10月23日
	// Explain:	  
	AcDbExtents GetEntExtents(const AcDbObjectId& idEnt);
	AcDbExtents GetEntExtents(const AcDbObjectIdArray& arrid);
	AcDbExtents GetEntExtents(const AcArray<AcDbEntity*>& arrEnt);

	// Summary:   
	// Time:	  2019年11月15日 peihaodong
	// Explain:	  水平返回1，垂直返回2，并得到水平或垂直值，不是水平或垂直返回0
	int GetLineType(const AcDbObjectId& idLine,double& dPosition);
	int GetLineType(AcDbLine* pLine,double& dPosition);

	// Summary:   得到实体外包矩形的最大点和最小点
	// Time:	  2019年11月19日 peihaodong
	// Explain:	  
	bool GetExtentsPt(const AcDbObjectId& idEnt,AcGePoint3d& ptMax,AcGePoint3d& ptMin);
	bool GetExtentsPt(AcDbEntity* pEnt,AcGePoint3d& ptMax, AcGePoint3d& ptMin);
	bool GetExtentsPt(const AcDbObjectIdArray& arrid, AcGePoint3d& ptMax,
		AcGePoint3d& ptMin);

	// Summary:   判断两点是否相等
	// Time:	  2019年11月27日 peihaodong
	// Explain:	  nDotNum代表小数位数
	bool PtIsEqual(const AcGePoint3d& pt1,const AcGePoint3d& pt2,int nDotNum);

	// Summary:   判断两个直线是否重合
	// Time:	  2019年11月28日 peihaodong
	// Explain:	  
	bool LineIsCoincide(AcDbLine* pLine1,AcDbLine* pLine2);

	// Summary:   判断两个直线是否完全包含
	// Time:	  2019年11月28日 peihaodong
	// Explain:	  
	bool LineIsCompleteContain(AcDbLine* pLongLine, AcDbLine* pShortLine);

	// Summary:   删除相同的点
	// Time:	  2019年11月29日 peihaodong
	// Explain:	  
	AcGePoint3dArray RemoveSamePt(const AcGePoint3dArray& arrpt);

	// Summary:   得到实体图层名
	// Time:	  2019年12月25日 peihaodong
	// Explain:	  
	CString GetEntLayerName(AcDbEntity* pEnt);

	// Summary:   是否是符合类型的id
	// Time:	  2020年1月13日 peihaodong
	// Explain:	  
	bool IsAccordId(const AcDbObjectId& idEnt,
		const AcArray<AcRxClass*>& arrType);

	// Summary:   数组中是否包含该点
	// Time:	  2020年2月4日 peihaodong
	// Explain:	  
	bool IsContainsPt(const AcGePoint3dArray& arrPt,
		const AcGePoint3d& pt, double dTol = 0.01);

	// Summary:   将多段线点的顺序设置反（闭合的线段第一点不变）
	// Time:	  2020年2月4日 peihaodong
	// Explain:	  直接修改该多段线
	bool ReversePolylinePt(AcDbPolyline* pPline);
	// Summary:   将多段线点的顺序设置反（闭合的线段第一点不变）
	// Time:	  2020年4月2日 peihaodong
	// Explain:	  新创建一个多段线，原多段线不变
	AcDbPolyline* ReversePlinePt(AcDbPolyline* pPline);

	// Summary:   将2维多段线转换成多段线
	// Time:	  2020年2月4日 peihaodong
	// Explain:	  相当于生成该二维多段线的多段线指针
	AcDbPolyline* Pline2dToPline(AcDb2dPolyline* p2dPline);

	//************************************
	// Summary: 	是否是镜像圆弧
	// Parameters: 	
	//    pArc		- 	
	// Returns:   	
	//************************************
	bool IsMirrorArc(AcDbArc* pArc);

	// Summary:   倒圆角
	// Time:	  2020年3月6日 peihaodong
	// Explain:	  
	bool FilletCurve(double dRadius, AcDbLine* pLine1, const AcGePoint3d& pt1,
		AcDbArc* pArc2, const AcGePoint3d& pt2, AcDbArc*& pArcFillet);
	bool FilletCurve(double dRadius, AcDbArc* pArc1, const AcGePoint3d& pt1,
		AcDbArc* pArc2, const AcGePoint3d& pt2, AcDbArc*& pArcFillet);
	void ModifyLinePtToInterPt(AcDbLine* pLine, const AcGePoint3d& ptOnLine,
		const AcGePoint3d& ptInter);
	void ModifyArcPtToInterPt(AcDbArc* pArc, const AcGePoint3d& ptOnArc,
		const AcGePoint3d& ptInter);
	void ModifyLinePt(AcDbLine* pLine, const AcGePoint3d& ptFrom, const AcGePoint3d& ptTo);

	// Summary:   得到资源中的字符串
	// Time:	  2020年3月13日 peihaodong
	// Explain:	  
	CString GetRcStr(int nID);

	// Summary:   得到某一方向向量的两个正交向量
	// Time:	  2020年4月7日 peihaodong
	// Explain:	  
	AcGeVector3dArray GetPerpVec(const AcGeVector3d& vecDirec);

	//判断线段是否是逆时针
	bool IsAntiClockWise(const AcGePoint3dArray& arrpt);
	double GetPtArrayArea(const AcGePoint3dArray& arrpt);

	// Summary:   得到多段线该点处的线段下标和线段类型
	// Time:	  2020年4月17日 peihaodong
	// Explain:	  当pt不在多段线上时返回-1
	int GetPlineSegIndexByPt(AcDbPolyline* pPline,const AcGePoint3d& pt,
		bool& bIsArc);

	//判断向量二在向量一的左边还是右边
	//1：左边   2：右边
	int JudgeVectorLeftOrRight(const AcGeVector3d& vec1,
		const AcGeVector3d& vec2);

	// Summary:   点是否在闭合多段线内
	// Time:	  2020年6月22日 peihaodong
	// Explain:	  
	bool PtIsInClosePline(const AcGePoint3d& pt,AcDbPolyline* pPline);

	// Summary:   是否共线
	// Time:	  2020年6月24日 peihaodong
	// Explain:	  
	bool IsColinear(const AcGePoint3d& pt1,const AcGePoint3d& pt2,
		const AcGePoint3d& pt3);

	// Summary:   给一条多段线增加点
	// Time:	  2020年7月16日 peihaodong
	// Explain:	  
	bool PlineAddPts(AcDbPolyline* pPline,const AcGePoint3dArray& arrpt);

}

