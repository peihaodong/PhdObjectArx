//This class is written by Peihaodong.
//此类是反应器集合类，包含编辑器反应器、数据库反应器、文档反应器，为方便对反应器的操作编写此类
#pragma once


class CPhdReactor
{
public:
	CPhdReactor(void);
	~CPhdReactor(void);

	static void addReactor();//加载反应器
	static void removeReactor();//卸载反应器
};

//编辑器反应器
class CEditorReactor : public AcEditorReactor
{
public:
	CEditorReactor(void);
	~CEditorReactor(void);

	//功能：命令执行前触发
	//参数：cmdStr-被执行的命令名
	virtual void commandWillStart(const TCHAR* cmdStr);

	//功能：命令执行结束后触发
	//参数：cmdStr-被执行的命令名
	virtual void commandEnded(const TCHAR* cmdStr);

	//功能：执行命令被取消后触发
	//参数：cmdStr-被执行的命令名
	virtual void commandCancelled(const TCHAR* cmdStr);

	//功能：执行命令操作失败时触发
	//参数：cmdStr-被执行的命令名
	virtual void commandFailed(const TCHAR* cmdStr);

	//功能：鼠标左键双击时触发
	//参数：clickPoint-双击的点坐标(WCS)
	virtual void beginDoubleClick(const AcGePoint3d& clickPoint);

	//功能：单击鼠标右键时触发
	//参数：clickPoint-右击的点坐标(WCS)
	virtual void beginRightClick(const AcGePoint3d& clickPoint);

	//功能：某一dwg图纸被打开时触发
	//参数：filename-被打开图纸的路径名
	virtual void beginDwgOpen(TCHAR* filename);

	//功能：某一dwg图纸已经打开时触发
	//参数：filename-被打开图纸的路径名	pDb-被打开图纸所在的数据库
	virtual void endDwgOpen(const TCHAR* filename, AcDbDatabase* pDb);

	//功能：用户保存dwg图纸时触发
	//参数：pDwg-要保存的数据库的指针	pIntendedName-要保存到的文件路径(在此通知时，用户还没有机会更改文件名，因此pIntendedName可能不是实际用于保存绘图的文件名。)
	virtual void beginSave(AcDbDatabase* pDwg, const TCHAR* pIntendedName);

	//功能：这个回调函数表示绘图数据库pDwg保存到pActualName指定的文件中
	virtual void saveComplete(AcDbDatabase* pDwg, const TCHAR* pActualName);

	//功能：当用户关闭CAD时触发，可以使用veto()函数取消关闭
	virtual void beginQuit();

	//功能：这个通知发生在beginQuit()通知之后(如果没有被否决)和关闭处理开始之前
	virtual void quitWillStart();

	//功能：当一个数据库被构造时触发(当使用AcDbDatabase* pTempDb = new AcDbDatabase(false);时也能触发)
	//参数：pDb-被构造的数据库的指针
	virtual void databaseConstructed(AcDbDatabase* pDb);

	//功能：当一个数据库被销毁时触发(当使用delete pTempDb;时也能触发)
	//参数：pDb-被销毁的数据库的指针
	virtual void databaseToBeDestroyed(AcDbDatabase* pDb);

	//功能：这个回调函数表示文件名指定的绘图文件正在被读取并存储在绘图数据库pDwg中
	virtual void dwgFileOpened(AcDbDatabase* pDb, TCHAR* fileName);

	//功能：系统变量将要改变前触发
	//参数：varName-系统变量名
	virtual void sysVarWillChange(const TCHAR* varName);

	//功能：系统变量改变后触发
	//参数：varName-系统变量名	success-是否成功改变的布尔值
	virtual void sysVarChanged(const TCHAR* varName, Adesk::Boolean success);

	//功能：当改变视图时触发
	virtual void viewChanged();
};

//数据库反应器
class CDbReactor :public AcDbDatabaseReactor
{
public:
	CDbReactor(void);
	~CDbReactor(void);

	//功能：实体添加到数据库后被触发
	//参数：dwg-添加的实体所在的数据库指针	dbObj-添加的实体的指针
	virtual void objectAppended (const AcDbDatabase* dwg, const AcDbObject* dbObj);

	//功能：实体被修改前触发
	//参数：dwg-被修改的实体所在的数据库指针	dbObj-被修改的实体的指针
	virtual void objectOpenedForModify(const AcDbDatabase * dwg, const AcDbObject * dbObj);

	//功能：实体被修改后触发
	//参数：dwg-被修改的实体所在的数据库指针	dbObj-被修改的实体的指针
	virtual void objectModified(const AcDbDatabase* dwg, const AcDbObject* dbObj);

	//功能：实体被删除后触发
	//参数：dwg-被删除实体所在的数据库指针	dbObj-被删除的实体的指针	pErased-实体是否被删除
	virtual void objectErased(const AcDbDatabase * dwg, const AcDbObject * dbObj, Adesk::Boolean pErased);

	//功能：修改系统变量前被触发
	//参数：dwg-修改系统变量所在的数据库指针	name-被修改的系统变量名
	virtual void headerSysVarWillChange(const AcDbDatabase * dwg, const ACHAR * name);

	//功能：修改系统变量后被触发
	//参数：dwg-修改系统变量所在的数据库指针	name-被修改的系统变量名	bSuccess-系统变量是否修改成功
	virtual void headerSysVarChanged(const AcDbDatabase * dwg, const ACHAR * name, Adesk::Boolean bSuccess);

	//功能：当dbObj所指向的对象通过撤销操作撤消其添加到AcDbDatabasedwg中的操作时，将发生此通知
	virtual void objectUnAppended(const AcDbDatabase * dwg, const AcDbObject * dbObj);
};

//文档反应器
class CDocReactor : public AcApDocManagerReactor
{
public:
	CDocReactor(void);
	~CDocReactor(void);

	//功能：文档被创建时触发
	//参数：pDocCreating-被创建的文档的指针
	virtual void documentCreated(AcApDocument* pDocCreating);

	//功能：文档被销毁时触发
	//参数：pDocCreating-被销毁的文档的指针
	virtual void documentToBeDestroyed(AcApDocument* pDocToDestroy);
	
	//功能：文档被激活或切换上下文时触发
	//参数：pActivatedDoc-被激活文档的指针
	virtual void documentActivated(AcApDocument * pActivatedDoc);

	//功能：某一文档被设置为当前文档时触发
	//参数：param2-刚刚成为当前文档的指针
	virtual void documentBecameCurrent(AcApDocument * param2);
};

//对象反应器
class CObjectReactor : public AcDbObjectReactor
{
public:
	CObjectReactor(void);
	~CObjectReactor(void);

	//
	virtual void cancelled(const AcDbObject* dbObj);

	//当拷贝对象关闭后调用
	virtual void copied(const AcDbObject* dbObj,const AcDbObject* newObj);

	//当实体被删除或被复原后调用
	virtual void erased(const AcDbObject* dbObj,Adesk::Boolean pErasing = true);

	//当实体被从内存中delete后调用
	virtual void goodbye(const AcDbObject* dbObj);

	//当实体被修改后调用
	virtual void modified(const AcDbObject* dbObj);

	//当实体的扩展数据被修改后调用
	virtual void modifiedXData(const AcDbObject* dbObj);

	//当实体被撤销后调用
	virtual void modifyUndone(const AcDbObject* dbObj);

	//当实体被关闭后调用
	virtual void objectClosed(const AcDbObjectId objId);

	//当对象被写打开后调用
	virtual void openedForModify(const AcDbObject* dbObj);

	//
	virtual void reappended(const AcDbObject* dbObj);

	//
	virtual void unappended(const AcDbObject* dbObj);

	//
	virtual void subObjModified(const AcDbObject* dbObj,const AcDbObject* subObj);

};