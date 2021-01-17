

#ifndef _ZADUI_PORT_H_H
#define _ZADUI_PORT_H_H

//NPD_ZDUI
#ifdef  _ZDUI_BUILD
#  define   ZDUI_PORT  __declspec(dllexport)
#else
#  define   ZDUI_PORT  
#endif

#endif //_ZADUI_PORT_H_H