// LayerSample.h : LayerSample DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLayerSampleApp
// �йش���ʵ�ֵ���Ϣ������� LayerSample.cpp
//

class CLayerSampleApp : public CWinApp
{
public:
	CLayerSampleApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
