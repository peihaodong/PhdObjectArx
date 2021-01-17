#include "StdAfx.h"
#include "CPhdReactor.h"

//反应器的全局指针
CEditorReactor* g_pEditorReactor = NULL;//编辑器反应器
CDocReactor* g_pDocReactor = NULL;//文档反应器
CDbReactor* g_pDbReactor = NULL;//数据库反应器

//extern BOOL g_bWTFlag;

CPhdReactor::CPhdReactor(void)
{
}


CPhdReactor::~CPhdReactor(void)
{
}

void CPhdReactor::addReactor()
{
	g_pEditorReactor = new CEditorReactor();
	acedEditor->addReactor(g_pEditorReactor);

	g_pDocReactor = new CDocReactor();
	acDocManager->addReactor(g_pDocReactor);

	g_pDbReactor = new CDbReactor();
	AcApDocumentIterator *it = acDocManager->newAcApDocumentIterator();
	for (; !it->done(); it->step())
	{
		it->document()->database()->addReactor(g_pDbReactor);
	}	
	delete it;
}

void CPhdReactor::removeReactor()
{
	if (g_pEditorReactor)
	{
		acedEditor->removeReactor(g_pEditorReactor);
		delete g_pEditorReactor;
		g_pEditorReactor = NULL;
	}	

	if (g_pDocReactor)
	{
		acDocManager->removeReactor(g_pDocReactor);
		delete g_pDocReactor;
		g_pDocReactor = NULL;
	}
	
	if (g_pDbReactor)
	{
		AcApDocumentIterator *it = acDocManager->newAcApDocumentIterator();
		for (; !it->done(); it->step())
		{
			it->document()->database()->removeReactor(g_pDbReactor);
		}	
		delete it;
		delete g_pDbReactor;
		g_pDbReactor = NULL;
	}
}

CEditorReactor::CEditorReactor( void )
{

}

CEditorReactor::~CEditorReactor( void )
{

}

void CEditorReactor::commandWillStart( const TCHAR* cmdStr )
{
// 	if (_tcsicmp(cmdStr,L"-boundary") == 0 )
// 	{
// 		g_bWTFlag = TRUE;
// 	}
}

void CEditorReactor::commandEnded( const TCHAR* cmdStr )
{
// 	if (_tcsicmp(cmdStr,L"-boundary") == 0 )
// 	{
// 		g_bWTFlag = FALSE;
// 	}
}

void CEditorReactor::commandCancelled( const TCHAR* cmdStr )
{

}

void CEditorReactor::beginDoubleClick( const AcGePoint3d& clickPoint )
{
// 	// 选择点
// 	ArxDbgSelSet ss;
// 	auto rs = ss.pointSelect(clickPoint);
// 	if (rs != ArxDbgSelSet::kSelected || ss.length() == 0)
// 		return;
// 	AcDbObjectIdArray ids;//用户双击的实体ids
// 	ss.asArray(ids);
// 	if (ids.isEmpty())
// 		return;
// 	auto selId = ids.first();
}

void CEditorReactor::commandFailed( const TCHAR* cmdStr )
{

}

void CEditorReactor::beginDwgOpen( TCHAR* filename )
{
	CString strFilePath = filename;

}

void CEditorReactor::beginQuit()
{

}

void CEditorReactor::beginRightClick( const AcGePoint3d& clickPoint )
{

}

void CEditorReactor::beginSave( AcDbDatabase* pDwg, const TCHAR* pIntendedName )
{
	CString strFilePath = pIntendedName;

}

void CEditorReactor::databaseConstructed( AcDbDatabase* pDb )
{

}

void CEditorReactor::databaseToBeDestroyed( AcDbDatabase* pDb )
{

}

void CEditorReactor::dwgFileOpened( AcDbDatabase* pDb, TCHAR* fileName )
{

}

void CEditorReactor::saveComplete( AcDbDatabase* pDwg, const TCHAR* pActualName )
{

}

void CEditorReactor::quitWillStart()
{

}

void CEditorReactor::endDwgOpen( const TCHAR* filename, AcDbDatabase* pDb )
{

}

void CEditorReactor::sysVarWillChange( const TCHAR* varName )
{

}

void CEditorReactor::sysVarChanged( const TCHAR* varName, Adesk::Boolean success )
{

}

void CEditorReactor::viewChanged()
{

}

CDbReactor::CDbReactor( void )
{

}

CDbReactor::~CDbReactor( void )
{

}

void CDbReactor::objectAppended( const AcDbDatabase* dwg, const AcDbObject* dbObj )
{
	AcDbDatabaseReactor::objectAppended (dwg, dbObj);

	if (dbObj->isKindOf(AcDbEntity::desc()) && const_cast<AcDbObject*>(dbObj)->upgradeOpen() == Acad::eOk)
	{

	}
}

void CDbReactor::objectModified( const AcDbDatabase* dwg, const AcDbObject* dbObj )
{
	AcDbDatabaseReactor::objectModified(dwg,dbObj);


}

void CDbReactor::objectErased( const AcDbDatabase * dwg, const AcDbObject * dbObj, Adesk::Boolean pErased )
{
	AcDbDatabaseReactor::objectErased (dwg, dbObj, pErased) ;

	if (pErased)//对象被擦除
	{
		if (dbObj->isKindOf(AcDbBlockReference::desc()))//区分对象是什么类型
		{

		}
	}
}

void CDbReactor::headerSysVarChanged( const AcDbDatabase * dwg, const ACHAR * name, Adesk::Boolean bSuccess )
{
	AcDbDatabaseReactor::headerSysVarChanged (dwg, name, bSuccess) ;

}

void CDbReactor::headerSysVarWillChange( const AcDbDatabase * dwg, const ACHAR * name )
{
	AcDbDatabaseReactor::headerSysVarWillChange(dwg,name);


}

void CDbReactor::objectUnAppended( const AcDbDatabase * dwg, const AcDbObject * dbObj )
{
	AcDbDatabaseReactor::objectUnAppended(dwg,dbObj);


}

void CDbReactor::objectOpenedForModify( const AcDbDatabase * dwg, const AcDbObject * dbObj )
{
	AcDbDatabaseReactor::objectOpenedForModify(dwg,dbObj);


}

void CDocReactor::documentCreated( AcApDocument* pDocCreating )
{
	pDocCreating->database()->addReactor(g_pDbReactor);
}

void CDocReactor::documentToBeDestroyed( AcApDocument* pDocToDestroy )
{
	pDocToDestroy->database()->removeReactor(g_pDbReactor);
}

CDocReactor::CDocReactor( void )
{

}

CDocReactor::~CDocReactor( void )
{

}

void CDocReactor::documentActivated( AcApDocument * pActivatedDoc )
{

}

void CDocReactor::documentBecameCurrent( AcApDocument * param2 )
{

}

CObjectReactor::CObjectReactor(void)
{

}

CObjectReactor::~CObjectReactor(void)
{

}

void CObjectReactor::cancelled(const AcDbObject* dbObj)
{

}

void CObjectReactor::copied(const AcDbObject* dbObj, const AcDbObject* newObj)
{

}

void CObjectReactor::erased(const AcDbObject* dbObj, Adesk::Boolean pErasing /*= true*/)
{

}

void CObjectReactor::goodbye(const AcDbObject* dbObj)
{

}

void CObjectReactor::modified(const AcDbObject* dbObj)
{

}

void CObjectReactor::modifiedXData(const AcDbObject* dbObj)
{

}

void CObjectReactor::modifyUndone(const AcDbObject* dbObj)
{

}

void CObjectReactor::objectClosed(const AcDbObjectId objId)
{

}

void CObjectReactor::openedForModify(const AcDbObject* dbObj)
{

}

void CObjectReactor::reappended(const AcDbObject* dbObj)
{

}

void CObjectReactor::unappended(const AcDbObject* dbObj)
{

}

void CObjectReactor::subObjModified(const AcDbObject* dbObj, const AcDbObject* subObj)
{

}
