ZrxWizardSetup.exe Instructions:

This tool will copy files under the directory "..\ZRXSDK\Tools\ZrxWizard\WizFiles" to the response directory, so that ZRX projects can be easily and quickly generated with templates in VC10.

The following destination paths may vary on different computers depending on the operating system version or the path where VisualStudio10 was installed.
Source File	--> Destination Path File
ZrxWizard.vsdir	  --> C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcprojects\ZrxWizard\ZrxWizard.vsdir
ZrxWizard_2.vsdir --> C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcprojects\ZrxWizard.vsdir
ZrxWizard.vsz     --> C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcprojects\ZrxWizard.vsz
ZrxWizard.ico     --> C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcprojects\ZrxWizard.ico
zrxDebug.props    --> C:\Users\localuser\AppData\Local\Microsoft\MSBuild\v4.0\zrxDebug.props
zrxRelease.props  --> C:\Users\localuser\AppData\Local\Microsoft\MSBuild\v4.0\zrxRelease.props

Restrictions:
1.VC10 must have been installed;
2.The relative positions of files and folders under the directory "..\ZRXSDK\Tools" cannot be changed, otherwise the installation of ZRX Wizard may fail or the execution of post-build events (zrxcheck) via newly-created zrx projects may fail.

