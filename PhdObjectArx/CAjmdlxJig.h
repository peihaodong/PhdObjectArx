#pragma once

//阿基米德螺线拖动，一拖多

class CAjmdlxCsm :public AcDbEntity
{
public:
	CAjmdlxCsm(const AcGePoint3d& pt,double dT1,double dT2,double dR,
		double dAdd = 0.01);
	~CAjmdlxCsm();

	// Summary:   设置参数
	// Time:	  2020年1月8日 peihaodong
	// Explain:	  
	void SetBasePoint(const AcGePoint3d& pt);
	void SetT1(double dT1);
	void SetT2(double dT2);
	void SetR(double dR);
	void SetAdd(double dAdd); 

	//添加到模型空间
	AcDbObjectId Append();

private:
	virtual Adesk::Boolean worldDraw(AcGiWorldDraw* mode);

private:
	AcGePoint3d m_ptBase;
	double m_dT1;
	double m_dT2;
	double m_dR;
	double m_dAdd;

	AcDbPolyline* m_pPolyline;

	bool m_bAppend;			//是否添加到模型空间
};

class CAjmdlxJig :public AcEdJig
{
public:
	CAjmdlxJig( double dT1, double dT2, double dR,
		double dAdd = 0.01);
	~CAjmdlxJig();

	bool BeginDrag(CAjmdlxCsm*& pDragEnt);

private:
	virtual AcDbEntity* entity() const;
	virtual DragStatus sampler();
	virtual Adesk::Boolean update();

private:
	AcGePoint3d m_ptBase;
	double m_dT1;
	double m_dT2;
	double m_dR;
	double m_dAdd;

	CAjmdlxCsm* m_pAjmdlxCsm;

};

