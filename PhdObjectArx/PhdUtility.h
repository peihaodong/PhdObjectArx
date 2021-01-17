#pragma once



namespace PhdUtility {

	//���ܣ��õ���ǰ��Ŀzrx�ļ�·��
	CString GetCurZrxFilePath();

	//���ܣ��õ���ǰ��Ŀzrx�ļ�����Ŀ¼·��
	//���ص�Ŀ¼·������'\\'
	CString GetCurZrxFolderPath();

	//���ܣ�����cad�˵��ļ�
	bool LoadCadMenu(const CString& strMenuFileName, const CString& strMenuGroupName);

	//���ܣ�ж��cad�˵�
	bool UnloadCadMenu(const CString& strMenuGroupName);

	//���ܣ�����zrx�ļ�
	bool LoadZrxFile(LPCTSTR szFilePath);

	//���ܣ��������·��
	bool AddSearchPath(LPCTSTR szSearchDir);

	//���ܣ���ʵ����ӵ�ģ�Ϳռ�
	AcDbObjectId PostToModelSpace(AcDbEntity* pEnt, AcDbDatabase *pDb = acdbCurDwg());
	// Summary:   ���ʵ�嵽���ֿռ�
	// Time:	  2020��6��5�� peihaodong
	// Explain:	  
	AcDbObjectId PostToPaperSpace(AcDbEntity* pEnt, AcDbDatabase *pDb = acdbCurDwg());


	//���ܣ�����������ʵ��
	bool ModifyEntByScale(AcDbEntity* pEnt,double dScale,const AcGePoint3d& ptBase);
	bool ModifyEntByScale(const AcDbObjectId& idEnt,double dScale,const AcGePoint3d& ptBase);
	bool ModifyEntByScale(const AcArray<AcDbEntity*>& arrpEnt,double dScale,
		const AcGePoint3d& ptBase);

	//���ܣ��ֽ�ʵ��
	AcArray<AcDbEntity*> ExplodeEnt(AcDbEntity* pEnt);
	AcArray<AcDbEntity*> ExplodeEnt(const AcDbObjectId& idEnt);

	//���ܣ��ƶ�ʵ��
	bool MoveEnt(AcDbEntity* pEnt, const AcGePoint3d &ptBase, const AcGePoint3d &ptDest);
	bool MoveEnt(const AcDbObjectIdArray& arrid, const AcGePoint3d &ptBase, const AcGePoint3d &ptDest);
	bool MoveEnt(const AcDbObjectId& idEnt, const AcGePoint3d &ptBase, const AcGePoint3d &ptDest);
	bool MoveEnt(const AcArray<AcDbEntity*>& arrEnt, const AcGePoint3d &ptBase, const AcGePoint3d &ptDest);

	//���ܣ���תʵ��(����)
	bool RotateEnt(AcDbEntity *pEnt, const AcGePoint3d &ptBase, double rotation);
	bool RotateEnt(const AcArray<AcDbEntity*>& arrpEnt, const AcGePoint3d &ptBase, double rotation);

	//���ܣ�ƫ���߶�
	AcArray<AcDbCurve*> OffsetCurve(AcDbCurve* pCurve, double dOffsetDist);
	AcArray<AcDbCurve*> OffsetCurve(double dOffset, const AcGePoint3d& pt,
		AcDbCurve* pCurve,bool bOpposite = false);

	//�õ������������߶����ҵ�����ֵ
	bool GetPosAngNegValue(AcDbCurve* pCurve, 
		const AcGePoint3d& ptBase, const AcGeVector3d& vecNormal);

	// Summary:   ����߶�
	// Time:	  2020��4��9�� peihaodong
	// Explain:	  ����ĵ����Ҫ��getClosestPointTo�������»��
	AcArray<AcDbCurve*> SplitCurve(AcDbCurve* pCurve, const AcGePoint3dArray& arrSplitPt);
	AcArray<AcDbCurve*> SplitCurve(AcDbCurve* pCurve, const AcGePoint3d& ptSplit);
	AcArray<AcDbCurve*> SplitCurve(const AcDbObjectId& idCurve,
		const AcGePoint3dArray& arrSplitPt);

	// Summary: ͨ�����������߶�  
	// Time:	  2020��2��12�� peihaodong
	// Explain:	  
	bool ExtendCurveByDist(AcDbPolyline* pPline, bool isStartPt, double dDist);
	// Summary:   �����߶�
	// Time:	  2020��2��26�� peihaodong
	// Explain:	  
	bool ExtendCurve(AcDbCurve* pBorder, AcDbCurve* pExtend, const AcGePoint3d& ptExtend);

	// Summary:   �޼��߶�
	// Time:	  2020��2��26�� peihaodong
	// Explain:	  
	bool TrimCurve(AcDbCurve* pBorder, AcDbCurve* pTrim,
		const AcGePoint3d& ptTrim, AcDbCurve*& pNewTrim);

	// Summary:   ɾ��ʵ��
	// Time:	  2019��11��5�� peihaodong
	// Explain:	  
	bool DeleteEnt(const AcDbObjectId& idEnt);
	void DeleteEnt(AcArray<AcDbEntity*>& arrpEnt);

	// Summary:   ����ʵ��
	// Time:	  2019��11��22�� peihaodong
	// Explain:	  
	AcArray<AcDbEntity*> CopyEnt(const AcDbObjectIdArray& arrid);
	AcArray<AcDbEntity*> CopyEnt(const AcArray<AcDbEntity*>& arrp);
	AcDbEntity* CopyEnt(const AcDbObjectId& idEnt);

	// Summary:   ����ʵ��
	// Time:	  2020��3��5�� peihaodong
	// Explain:	  
	AcDbEntity* MirrorEnt(AcDbEntity* pEnt, const AcGePoint3d& pt1,
		const AcGePoint3d& pt2);
	AcArray<AcDbEntity*> MirrorEnt(const AcDbObjectIdArray& arrid, const AcGePoint3d& pt1,
		const AcGePoint3d& pt2);
	AcArray<AcDbEntity*> MirrorEnt(const AcArray<AcDbEntity*>& arrp, const AcGePoint3d& pt1,
		const AcGePoint3d& pt2);

	// Summary:   ���ξ���
	// Time:	  2020��3��5�� peihaodong
	// Explain:	  nCurNum����ǰ��Ҫ��������nSum���ܹ�������
	AcArray<AcDbEntity*> AnnularMatrix(const AcDbObjectIdArray& arrid,
		const AcGePoint3d& ptBase, int nCurNum, int nSum);
	AcArray<AcDbEntity*> AnnularMatrix(const AcArray<AcDbEntity*>& arrp,
		const AcGePoint3d& ptBase, int nYxcs, int nSum);

	//���ܣ��õ�Բ��͹��
	double GetArcBulge(AcDbArc* pArc);
	double GetArcBulge(double dAngleStart, double dAngleEnd);
	double GetArcBulge(const AcDbObjectId& idArc);
	double GetArcBulge(AcDbCurve* pCurve);
	double GetArcBulge(const AcGeCircArc2d& geArc);

	//���ܣ��õ����������
	AcGeLine2d GetGeLine2d(AcDbLine* pLine);
	AcGeLineSeg2d GetGeLineSeg2d(AcDbLine* pLine);
	AcGeLineSeg2d GetGeLineSeg2d(const AcDbObjectId& idLine);
	AcGeCircArc2d GetGeCircArc(AcDbArc* pArc);
	AcGeCircArc2d GetGeCircArc(AcDbCircle* pCircle);
	AcGeLineSeg2d GetGeLineSeg2d(AcDbPolyline* pPolyline, unsigned int unIndex);
	AcGeCircArc2d GetGeCircArc2d(AcDbPolyline* pPolyline, unsigned int unIndex);

	//���ܣ��õ�����
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
	
	//���ܣ��õ���������һ�����ϵ�ͶӰ����
	// Parameters: 	
	//    ptBase		- 	�������
	//    vctOffset		- 	���뱻ͶӰ������
	//    vctDirection		- 	���뷽������
	AcGeVector3d GetProjectVector(const AcGePoint3d& ptBase, const AcGeVector3d& vctOffset,
		const AcGeVector3d& vctDirection);

	// Summary:   �õ��߶�ĳ�����������
	// Time:	  2020��1��13�� peihaodong
	// Explain:	  
	AcGeVector3d GetTangentLineVec(const AcGePoint3d& ptOnCurve,
		const AcDbObjectId& idCurve);
	AcGeVector3dArray GetTangLineVecs(const AcGePoint3d& pt,
		const AcDbObjectId& idCurve);
	AcGeVector3dArray GetTangLineVecs(const AcGePoint3d& pt,
		AcDbCurve* pCurve);

	bool GetTangentLineVecs(AcDbPolyline* pPline,const AcGePoint3d& pt,
		AcGeVector3dArray& arrvec);

	//���ܣ��õ���ֱ�ߵĽ�ƽ��������
	// Parameters: 	
	//    idLine1		- 	����ֱ��1��id
	//    idLine2		- 	����ֱ��2��id
	//    midVector		- 	�����ƽ��������
	AcGeVector2d GetMidVectorOfLines(AcDbLine* pLine1, AcDbLine* pLine2);

	// Summary:   ͨ�������͵�õ���X��ĽǶ�(0~2��)
	// Time:	  2020��1��14�� peihaodong
	// Explain:	  
	double GetAngle(const AcGePoint3d& pt, const AcGeVector3d& vec);

	//���ܣ��õ��߶γ���
	double GetCurveLength(AcDbCurve* pCurve);

	//���ܣ��жϵ��Ƿ����߶���
	bool IsPtOnCurve(const AcGePoint3d& pt, AcDbCurve* pCurve,double dTol = 0);

	//���ܣ��õ���ֱ�ߵļн�
	double GetAngleOfLines(AcDbLine* pLine1, AcDbLine* pLine2);

	// Summary:   �õ��߶��Ͼ���õ�����ĵ�
	// Time:	  2020��4��17�� peihaodong
	// Explain:	  
	AcGePoint3d GetClosedPtInCurve(AcDbCurve* pCurve, const AcGePoint3d& pt);
	bool GetClosedPtInCurve(const AcDbObjectId& idCurve,const AcGePoint3d& pt,
		AcGePoint3d& ptClosed);

	// Summary: 	�Ե�������������
	// Parameters: 	
	//    PointArr		- 	����������
	//    bVertical		- 	���������ʶ	false:��ˮƽ����	true:����ֱ����
	AcGePoint3dArray SortPtArr(const AcGePoint3dArray& PointArr, bool bVertical = false);

	//���ܣ���ʾ/�رս�����
	void ShowProgressBar(const CString& strName, bool bStart);
	//���ܣ����ý�����
	//������
	//	nCurIndex	-	��ǰ�±�
	//	nSum		-	�ܵ��±�����
	void SetProgressBar(int nCurIndex, int nSum);

	//���ܣ�����ʵ�屻ѡ��
	void SetEntSelected(const AcDbObjectIdArray& arridEnt, bool bSeled = true, bool bHighlight = false);

	//���ܣ�������ͼ����
	bool SetEntToBottom(const AcDbObjectId& id, AcDbDatabase* pDb = acdbCurDwg());

	// Summary: 	����ʵ��
	// Parameters: 	
	//    arrid		- 	������Ҫ�������ʵ��id����
	//    ptCorner1		- 	���뱻����Ľǵ�1
	//    ptCorner2		- 	���뱻����Ľǵ�2
	//    ptBase		- 	�������
	//    ptTarget		- 	����Ŀ���
	bool StretchEnt(const AcDbObjectIdArray& arrid, const AcGePoint3d& ptCorner1, const AcGePoint3d& ptCorner2,
		const AcGePoint3d& ptBase, const AcGePoint3d& ptTarget);

	//���ܣ��õ������������ϵ�ʵ��id
	AcDbObjectIdArray GetEntIdByPt(const AcGePoint3d& pt,bool bAll = false);

	//���ܣ��õ�Ŀ¼�����е�dwgͼֽ·��
	AcArray<CString> GetAllDwgPath(LPCTSTR szFolderPath);

	// Summary:   �õ�Ŀ¼�����е�dwgͼֽ��
	// Time:	  2019��10��22��
	// Explain:	  
	AcArray<CString> GetAllDwgName(LPCTSTR szFolderPath);

	// Summary:   �õ�ʵ���������
	// Time:	  2019��10��23��
	// Explain:	  
	AcDbExtents GetEntExtents(const AcDbObjectId& idEnt);
	AcDbExtents GetEntExtents(const AcDbObjectIdArray& arrid);
	AcDbExtents GetEntExtents(const AcArray<AcDbEntity*>& arrEnt);

	// Summary:   
	// Time:	  2019��11��15�� peihaodong
	// Explain:	  ˮƽ����1����ֱ����2�����õ�ˮƽ��ֱֵ������ˮƽ��ֱ����0
	int GetLineType(const AcDbObjectId& idLine,double& dPosition);
	int GetLineType(AcDbLine* pLine,double& dPosition);

	// Summary:   �õ�ʵ��������ε��������С��
	// Time:	  2019��11��19�� peihaodong
	// Explain:	  
	bool GetExtentsPt(const AcDbObjectId& idEnt,AcGePoint3d& ptMax,AcGePoint3d& ptMin);
	bool GetExtentsPt(AcDbEntity* pEnt,AcGePoint3d& ptMax, AcGePoint3d& ptMin);
	bool GetExtentsPt(const AcDbObjectIdArray& arrid, AcGePoint3d& ptMax,
		AcGePoint3d& ptMin);

	// Summary:   �ж������Ƿ����
	// Time:	  2019��11��27�� peihaodong
	// Explain:	  nDotNum����С��λ��
	bool PtIsEqual(const AcGePoint3d& pt1,const AcGePoint3d& pt2,int nDotNum);

	// Summary:   �ж�����ֱ���Ƿ��غ�
	// Time:	  2019��11��28�� peihaodong
	// Explain:	  
	bool LineIsCoincide(AcDbLine* pLine1,AcDbLine* pLine2);

	// Summary:   �ж�����ֱ���Ƿ���ȫ����
	// Time:	  2019��11��28�� peihaodong
	// Explain:	  
	bool LineIsCompleteContain(AcDbLine* pLongLine, AcDbLine* pShortLine);

	// Summary:   ɾ����ͬ�ĵ�
	// Time:	  2019��11��29�� peihaodong
	// Explain:	  
	AcGePoint3dArray RemoveSamePt(const AcGePoint3dArray& arrpt);

	// Summary:   �õ�ʵ��ͼ����
	// Time:	  2019��12��25�� peihaodong
	// Explain:	  
	CString GetEntLayerName(AcDbEntity* pEnt);

	// Summary:   �Ƿ��Ƿ������͵�id
	// Time:	  2020��1��13�� peihaodong
	// Explain:	  
	bool IsAccordId(const AcDbObjectId& idEnt,
		const AcArray<AcRxClass*>& arrType);

	// Summary:   �������Ƿ�����õ�
	// Time:	  2020��2��4�� peihaodong
	// Explain:	  
	bool IsContainsPt(const AcGePoint3dArray& arrPt,
		const AcGePoint3d& pt, double dTol = 0.01);

	// Summary:   ������ߵ��˳�����÷����պϵ��߶ε�һ�㲻�䣩
	// Time:	  2020��2��4�� peihaodong
	// Explain:	  ֱ���޸ĸö����
	bool ReversePolylinePt(AcDbPolyline* pPline);
	// Summary:   ������ߵ��˳�����÷����պϵ��߶ε�һ�㲻�䣩
	// Time:	  2020��4��2�� peihaodong
	// Explain:	  �´���һ������ߣ�ԭ����߲���
	AcDbPolyline* ReversePlinePt(AcDbPolyline* pPline);

	// Summary:   ��2ά�����ת���ɶ����
	// Time:	  2020��2��4�� peihaodong
	// Explain:	  �൱�����ɸö�ά����ߵĶ����ָ��
	AcDbPolyline* Pline2dToPline(AcDb2dPolyline* p2dPline);

	//************************************
	// Summary: 	�Ƿ��Ǿ���Բ��
	// Parameters: 	
	//    pArc		- 	
	// Returns:   	
	//************************************
	bool IsMirrorArc(AcDbArc* pArc);

	// Summary:   ��Բ��
	// Time:	  2020��3��6�� peihaodong
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

	// Summary:   �õ���Դ�е��ַ���
	// Time:	  2020��3��13�� peihaodong
	// Explain:	  
	CString GetRcStr(int nID);

	// Summary:   �õ�ĳһ����������������������
	// Time:	  2020��4��7�� peihaodong
	// Explain:	  
	AcGeVector3dArray GetPerpVec(const AcGeVector3d& vecDirec);

	//�ж��߶��Ƿ�����ʱ��
	bool IsAntiClockWise(const AcGePoint3dArray& arrpt);
	double GetPtArrayArea(const AcGePoint3dArray& arrpt);

	// Summary:   �õ�����߸õ㴦���߶��±���߶�����
	// Time:	  2020��4��17�� peihaodong
	// Explain:	  ��pt���ڶ������ʱ����-1
	int GetPlineSegIndexByPt(AcDbPolyline* pPline,const AcGePoint3d& pt,
		bool& bIsArc);

	//�ж�������������һ����߻����ұ�
	//1�����   2���ұ�
	int JudgeVectorLeftOrRight(const AcGeVector3d& vec1,
		const AcGeVector3d& vec2);

	// Summary:   ���Ƿ��ڱպ϶������
	// Time:	  2020��6��22�� peihaodong
	// Explain:	  
	bool PtIsInClosePline(const AcGePoint3d& pt,AcDbPolyline* pPline);

	// Summary:   �Ƿ���
	// Time:	  2020��6��24�� peihaodong
	// Explain:	  
	bool IsColinear(const AcGePoint3d& pt1,const AcGePoint3d& pt2,
		const AcGePoint3d& pt3);

	// Summary:   ��һ����������ӵ�
	// Time:	  2020��7��16�� peihaodong
	// Explain:	  
	bool PlineAddPts(AcDbPolyline* pPline,const AcGePoint3dArray& arrpt);

}

