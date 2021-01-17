

#ifndef _ZDSCODES_H
#define _ZDSCODES_H 1

#define RQSAVE  14 
#define RQEND   15 
#define RQQUIT  16 
#define RQCFG   22 

#define RQXLOAD 100 
#define RQXUNLD 101 
#define RQSUBR  102 
#define RQHUP   105 
#define RQXHELP 118 

#define RSRSLT   1 
#define RSERR    3 

#define RTNONE    5000 
#define RTREAL    5001 
#define RTPOINT   5002 
#define RTSHORT   5003 
#define RTANG     5004 
#define RTSTR     5005 
#define RTENAME   5006 
#define RTPICKS   5007 
#define RTORINT   5008 
#define RT3DPOINT 5009 
#define RTLONG    5010 
#define RTVOID    5014 
#define RTLB      5016 
#define RTLE      5017 
#define RTDOTE    5018 
#define RTNIL     5019 
#define RTDXF0    5020 
#define RTT       5021 
#define RTRESBUF  5023 
#define RTMODELESS 5027 

#define RTLONG_PTR 5030
#define RTINT64    5031
#define RTNORM    5100

#define RTERROR          (-5001) 
#define RTCAN            (-5002) 
#define RTREJ            (-5003) 
#define RTFAIL           (-5004) 
#define RTKWORD          (-5005) 
#define RTINPUTTRUNCATED (-5008)

#ifndef WM_ZCAD_KEEPFOCUS
#ifndef WM_USER
#define WM_ZCAD_KEEPFOCUS (0x0400+0x6D01)
#else
#define WM_ZCAD_KEEPFOCUS (WM_USER+0x6D01)
#endif   
#endif

#endif
