echo off

Set Msbuild=c:\Windows\Microsoft.NET\Framework\v4.0.30319\MsBuild.exe 

rem 编译 Debug x86
"%MsBuild%" /p:Configuration=Debug;Platform=x86 PhdObjectArx.msbuildproj
if errorlevel 1 goto error
rem 编译 Debug x64
"%MsBuild%" /p:Configuration=Debug;Platform=x64 PhdObjectArx.msbuildproj
if errorlevel 1 goto error
rem 编译 Release x86
"%MsBuild%" /p:Configuration=Release;Platform=x86 PhdObjectArx.msbuildproj
if errorlevel 1 goto error
rem 编译 Release x64
"%MsBuild%" /p:Configuration=Release;Platform=x64 PhdObjectArx.msbuildproj
if errorlevel 1 goto error


rem 拷贝头文件
call :FileCopy CCurveToPline
call :FileCopy CFiltrateYxk
call :FileCopy CPhdPlot
call :FileCopy ZrxProductUtils

:error
pause

rem 头文件拷贝函数
:FileCopy
copy /y ..\PhdObjectArx\%1.h ..\API_PhdObjectArx\Debug\include\%1.h
copy /y ..\PhdObjectArx\%1.h ..\API_PhdObjectArx\Release\include\%1.h
goto :eof
