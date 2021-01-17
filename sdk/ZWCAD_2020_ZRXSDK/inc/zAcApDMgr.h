
#pragma once

#include "zacdocman.h"
#include <map>

template <class T> 
class ZcApDataManager : public ZcApDocManagerReactor {

public:
	ZcApDataManager () {
		zcDocManager->addReactor (this) ;
	}
	~ZcApDataManager () {
		if ( zcDocManager != NULL )
			zcDocManager->removeReactor (this) ;
	}
	virtual void documentToBeDestroyed (ZcApDocument *pDoc) {
		m_dataMap.erase (pDoc) ;
	}

	T &docData (ZcApDocument *pDoc) {
		if (m_dataMap.find(pDoc) == m_dataMap.end ())
			return (m_dataMap[pDoc]) ;
		return ((*(m_dataMap.find(pDoc))).second);
	}
	T &docData () {
		return (docData (zcDocManager->curDocument ())) ;
	}

private:
	std::map<ZcApDocument *, T> m_dataMap ;
} ;
