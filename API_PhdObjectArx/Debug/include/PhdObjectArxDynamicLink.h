#pragma once

#ifdef PHD_OBJECTARX
#define PHD_OBJECTARX_API __declspec(dllexport)
#else
#define PHD_OBJECTARX_API __declspec(dllimport)
#endif

//	添加头文件
#include "PhdArxInline.h"
#include "PhdArxConver.h"
#include "PhdArxDimStyle.h"
#include "PhdArxEntity.h"
#include "PhdArxGroup.h"
#include "PhdArxLayer.h"
#include "PhdArxLinetype.h"
#include "PhdArxMethod.h"
#include "PhdArxSelSet.h"
#include "PhdArxSysDlg.h"
#include "PhdArxSysVar.h"
#include "PhdArxTextStyle.h"
#include "PhdArxUiPr.h"
#include "PhdArxUtility.h"
#include "PhdArxEntity.h"
#include "PhdArxView.h"
#include "PhdArxViewport.h"
#include "PhdArxXData.h"
#include "PhdArxDatabase.h"
#include "PhdArxBlock.h"
#include "PhdArxCommand.h"

#include "CArxPreviewCtrl.h"


#ifndef PHD_OBJECTARX
//相当于在vs配置中添加 附加依赖项

#pragma comment(lib,"PhdObjectArx.lib")

#endif