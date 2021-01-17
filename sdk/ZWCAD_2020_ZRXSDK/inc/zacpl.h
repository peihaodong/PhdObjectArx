

#ifndef ZCPL_H
#define ZCPL_H

#if _MSC_VER >= 1000
#pragma once
#endif 

#ifdef  _ZCPL_BUILD
#  define   ZCPL_PORT  __declspec(dllexport)
#else
#  define ZCPL_PORT
#endif

#endif 
