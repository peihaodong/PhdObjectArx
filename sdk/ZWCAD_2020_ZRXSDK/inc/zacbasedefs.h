

#ifndef _ZACBASEDEFS_H_H
#define _ZACBASEDEFS_H_H


#ifdef _ZSOFT_WINDOWS_
	#ifndef ZCBASE_PORT
		#ifdef ZCBASE_API
			#define ZCBASE_PORT _declspec(dllexport)
		#else
			#define ZCBASE_PORT _declspec(dllimport)
		#endif
	#endif
#else
	#define ZCBASE_PORT
#endif 

#endif //_ZACBASEDEFS_H_H