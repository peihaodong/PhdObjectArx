#pragma once

//���÷�Ӧ��
class CPhdPersistReactor :public AcDbObject
{
public:
	ACRX_DECLARE_MEMBERS(CPhdPersistReactor);

	CPhdPersistReactor();
	~CPhdPersistReactor();

	static bool AttachReactor(const AcDbObjectId& idObserve, const AcDbObjectId& idChanger);//�󶨷�Ӧ��
	static void AddReactor();//���ط�Ӧ��
	static void RemoveReactor();//ж�ط�Ӧ��

	Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);//����
	Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;//����
	Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler);
	Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const;

	//�۲��߱��ı�����
	virtual void modified(const AcDbObject* dbObj);
	//�۲��߱�ɾ�������
	virtual void erased(const AcDbObject* dbObj, Adesk::Boolean pErasing = true);

	//���øı���id
	void SetChangerId(const AcDbObjectId& id);


protected:
	AcDbObjectId m_idChanger;	//�ı���id
};

