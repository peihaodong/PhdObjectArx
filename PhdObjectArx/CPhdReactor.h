//This class is written by Peihaodong.
//�����Ƿ�Ӧ�������࣬�����༭����Ӧ�������ݿⷴӦ�����ĵ���Ӧ����Ϊ����Է�Ӧ���Ĳ�����д����
#pragma once


class CPhdReactor
{
public:
	CPhdReactor(void);
	~CPhdReactor(void);

	static void addReactor();//���ط�Ӧ��
	static void removeReactor();//ж�ط�Ӧ��
};

//�༭����Ӧ��
class CEditorReactor : public AcEditorReactor
{
public:
	CEditorReactor(void);
	~CEditorReactor(void);

	//���ܣ�����ִ��ǰ����
	//������cmdStr-��ִ�е�������
	virtual void commandWillStart(const TCHAR* cmdStr);

	//���ܣ�����ִ�н����󴥷�
	//������cmdStr-��ִ�е�������
	virtual void commandEnded(const TCHAR* cmdStr);

	//���ܣ�ִ�����ȡ���󴥷�
	//������cmdStr-��ִ�е�������
	virtual void commandCancelled(const TCHAR* cmdStr);

	//���ܣ�ִ���������ʧ��ʱ����
	//������cmdStr-��ִ�е�������
	virtual void commandFailed(const TCHAR* cmdStr);

	//���ܣ�������˫��ʱ����
	//������clickPoint-˫���ĵ�����(WCS)
	virtual void beginDoubleClick(const AcGePoint3d& clickPoint);

	//���ܣ���������Ҽ�ʱ����
	//������clickPoint-�һ��ĵ�����(WCS)
	virtual void beginRightClick(const AcGePoint3d& clickPoint);

	//���ܣ�ĳһdwgͼֽ����ʱ����
	//������filename-����ͼֽ��·����
	virtual void beginDwgOpen(TCHAR* filename);

	//���ܣ�ĳһdwgͼֽ�Ѿ���ʱ����
	//������filename-����ͼֽ��·����	pDb-����ͼֽ���ڵ����ݿ�
	virtual void endDwgOpen(const TCHAR* filename, AcDbDatabase* pDb);

	//���ܣ��û�����dwgͼֽʱ����
	//������pDwg-Ҫ��������ݿ��ָ��	pIntendedName-Ҫ���浽���ļ�·��(�ڴ�֪ͨʱ���û���û�л�������ļ��������pIntendedName���ܲ���ʵ�����ڱ����ͼ���ļ�����)
	virtual void beginSave(AcDbDatabase* pDwg, const TCHAR* pIntendedName);

	//���ܣ�����ص�������ʾ��ͼ���ݿ�pDwg���浽pActualNameָ�����ļ���
	virtual void saveComplete(AcDbDatabase* pDwg, const TCHAR* pActualName);

	//���ܣ����û��ر�CADʱ����������ʹ��veto()����ȡ���ر�
	virtual void beginQuit();

	//���ܣ����֪ͨ������beginQuit()֪֮ͨ��(���û�б����)�͹رմ���ʼ֮ǰ
	virtual void quitWillStart();

	//���ܣ���һ�����ݿⱻ����ʱ����(��ʹ��AcDbDatabase* pTempDb = new AcDbDatabase(false);ʱҲ�ܴ���)
	//������pDb-����������ݿ��ָ��
	virtual void databaseConstructed(AcDbDatabase* pDb);

	//���ܣ���һ�����ݿⱻ����ʱ����(��ʹ��delete pTempDb;ʱҲ�ܴ���)
	//������pDb-�����ٵ����ݿ��ָ��
	virtual void databaseToBeDestroyed(AcDbDatabase* pDb);

	//���ܣ�����ص�������ʾ�ļ���ָ���Ļ�ͼ�ļ����ڱ���ȡ���洢�ڻ�ͼ���ݿ�pDwg��
	virtual void dwgFileOpened(AcDbDatabase* pDb, TCHAR* fileName);

	//���ܣ�ϵͳ������Ҫ�ı�ǰ����
	//������varName-ϵͳ������
	virtual void sysVarWillChange(const TCHAR* varName);

	//���ܣ�ϵͳ�����ı�󴥷�
	//������varName-ϵͳ������	success-�Ƿ�ɹ��ı�Ĳ���ֵ
	virtual void sysVarChanged(const TCHAR* varName, Adesk::Boolean success);

	//���ܣ����ı���ͼʱ����
	virtual void viewChanged();
};

//���ݿⷴӦ��
class CDbReactor :public AcDbDatabaseReactor
{
public:
	CDbReactor(void);
	~CDbReactor(void);

	//���ܣ�ʵ����ӵ����ݿ�󱻴���
	//������dwg-��ӵ�ʵ�����ڵ����ݿ�ָ��	dbObj-��ӵ�ʵ���ָ��
	virtual void objectAppended (const AcDbDatabase* dwg, const AcDbObject* dbObj);

	//���ܣ�ʵ�屻�޸�ǰ����
	//������dwg-���޸ĵ�ʵ�����ڵ����ݿ�ָ��	dbObj-���޸ĵ�ʵ���ָ��
	virtual void objectOpenedForModify(const AcDbDatabase * dwg, const AcDbObject * dbObj);

	//���ܣ�ʵ�屻�޸ĺ󴥷�
	//������dwg-���޸ĵ�ʵ�����ڵ����ݿ�ָ��	dbObj-���޸ĵ�ʵ���ָ��
	virtual void objectModified(const AcDbDatabase* dwg, const AcDbObject* dbObj);

	//���ܣ�ʵ�屻ɾ���󴥷�
	//������dwg-��ɾ��ʵ�����ڵ����ݿ�ָ��	dbObj-��ɾ����ʵ���ָ��	pErased-ʵ���Ƿ�ɾ��
	virtual void objectErased(const AcDbDatabase * dwg, const AcDbObject * dbObj, Adesk::Boolean pErased);

	//���ܣ��޸�ϵͳ����ǰ������
	//������dwg-�޸�ϵͳ�������ڵ����ݿ�ָ��	name-���޸ĵ�ϵͳ������
	virtual void headerSysVarWillChange(const AcDbDatabase * dwg, const ACHAR * name);

	//���ܣ��޸�ϵͳ�����󱻴���
	//������dwg-�޸�ϵͳ�������ڵ����ݿ�ָ��	name-���޸ĵ�ϵͳ������	bSuccess-ϵͳ�����Ƿ��޸ĳɹ�
	virtual void headerSysVarChanged(const AcDbDatabase * dwg, const ACHAR * name, Adesk::Boolean bSuccess);

	//���ܣ���dbObj��ָ��Ķ���ͨ������������������ӵ�AcDbDatabasedwg�еĲ���ʱ����������֪ͨ
	virtual void objectUnAppended(const AcDbDatabase * dwg, const AcDbObject * dbObj);
};

//�ĵ���Ӧ��
class CDocReactor : public AcApDocManagerReactor
{
public:
	CDocReactor(void);
	~CDocReactor(void);

	//���ܣ��ĵ�������ʱ����
	//������pDocCreating-���������ĵ���ָ��
	virtual void documentCreated(AcApDocument* pDocCreating);

	//���ܣ��ĵ�������ʱ����
	//������pDocCreating-�����ٵ��ĵ���ָ��
	virtual void documentToBeDestroyed(AcApDocument* pDocToDestroy);
	
	//���ܣ��ĵ���������л�������ʱ����
	//������pActivatedDoc-�������ĵ���ָ��
	virtual void documentActivated(AcApDocument * pActivatedDoc);

	//���ܣ�ĳһ�ĵ�������Ϊ��ǰ�ĵ�ʱ����
	//������param2-�ոճ�Ϊ��ǰ�ĵ���ָ��
	virtual void documentBecameCurrent(AcApDocument * param2);
};

//����Ӧ��
class CObjectReactor : public AcDbObjectReactor
{
public:
	CObjectReactor(void);
	~CObjectReactor(void);

	//
	virtual void cancelled(const AcDbObject* dbObj);

	//����������رպ����
	virtual void copied(const AcDbObject* dbObj,const AcDbObject* newObj);

	//��ʵ�屻ɾ���򱻸�ԭ�����
	virtual void erased(const AcDbObject* dbObj,Adesk::Boolean pErasing = true);

	//��ʵ�屻���ڴ���delete�����
	virtual void goodbye(const AcDbObject* dbObj);

	//��ʵ�屻�޸ĺ����
	virtual void modified(const AcDbObject* dbObj);

	//��ʵ�����չ���ݱ��޸ĺ����
	virtual void modifiedXData(const AcDbObject* dbObj);

	//��ʵ�屻���������
	virtual void modifyUndone(const AcDbObject* dbObj);

	//��ʵ�屻�رպ����
	virtual void objectClosed(const AcDbObjectId objId);

	//������д�򿪺����
	virtual void openedForModify(const AcDbObject* dbObj);

	//
	virtual void reappended(const AcDbObject* dbObj);

	//
	virtual void unappended(const AcDbObject* dbObj);

	//
	virtual void subObjModified(const AcDbObject* dbObj,const AcDbObject* subObj);

};