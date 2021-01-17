rem 拷贝.h文件
call :FileCopy CCurveToPline
call :FileCopy CFiltrateYxk
call :FileCopy CPhdPlot
call :FileCopy ZrxProductUtils

pause
exit /b 0

rem 文件拷贝函数
:FileCopy
copy /y ..\PhdObjectArx\%1.h ..\API_PhdObjectArx\Debug\include\%1.h
copy /y ..\PhdObjectArx\%1.h ..\API_PhdObjectArx\Release\include\%1.h
goto :eof

