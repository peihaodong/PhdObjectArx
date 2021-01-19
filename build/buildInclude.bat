rem 拷贝.h文件
call :FileCopy PhdObjectArxDynamicLink

call :FileCopy PhdArxInline
call :FileCopy PhdArxConver
call :FileCopy PhdArxDimStyle
call :FileCopy PhdArxEntity
call :FileCopy PhdArxGroup
call :FileCopy PhdArxLayer
call :FileCopy PhdArxLinetype
call :FileCopy PhdArxMethod
call :FileCopy PhdArxSelSet
call :FileCopy PhdArxSysDlg
call :FileCopy PhdArxSysVar
call :FileCopy PhdArxTextStyle
call :FileCopy PhdArxUiPr
call :FileCopy PhdArxUtility
call :FileCopy PhdArxView
call :FileCopy PhdArxViewport
call :FileCopy PhdArxXData
call :FileCopy PhdArxDatabase
call :FileCopy PhdArxBlock
call :FileCopy PhdArxCommand
call :FileCopy PhdArxXRecord

call :FileCopy CArxPreviewCtrl

pause
exit /b 0

rem 文件拷贝函数
:FileCopy
copy /y ..\PhdObjectArx\%1.h ..\API_PhdObjectArx\Debug\include\%1.h
copy /y ..\PhdObjectArx\%1.h ..\API_PhdObjectArx\Release\include\%1.h
goto :eof

