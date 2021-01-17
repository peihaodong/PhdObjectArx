#pragma once

//永久反应器
class CPhdPersistReactor :public AcDbObject
{
public:
	ACRX_DECLARE_MEMBERS(CPhdPersistReactor);

	CPhdPersistReactor();
	~CPhdPersistReactor();

	static bool AttachReactor(const AcDbObjectId& idObserve, const AcDbObjectId& idChanger);//绑定反应器
	static void AddReactor();//加载反应器
	static void RemoveReactor();//卸载反应器

	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);//保存
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;//加载
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler);
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const;

	//观察者被改变后调用
	virtual void modified(const AcDbObject* dbObj);
	//观察者被删除后调用
	virtual void erased(const AcDbObject* dbObj, Adesk::Boolean pErasing = true);

	//设置改变者id
	void SetChangerId(const AcDbObjectId& id);


protected:
	AcDbObjectId m_idChanger;	//改变者id
};

