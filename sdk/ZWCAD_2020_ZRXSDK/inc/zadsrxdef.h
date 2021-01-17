

#ifndef   _ZDSRXDEF_H_
#define   _ZDSRXDEF_H_ 1

#pragma pack (push, 8)
typedef struct fchnd {                
        struct fchnd *next;           
        int fcode;                    
        int (*fhdl)();                
} FunHandList;
 
class ZcRxGenHand;

class RxZDSAppTableEntryType {
  public:
    int    lflag;
    ZTCHAR* appname;
    ZSoft::LongPtr  apphandle;
    int    zds_fcode;
    int    zds_invkcnt;
    struct resbuf* zds_argl;
    FunHandList* zds_fhdl;
    ZcRxGenHand * modhandle;
    resbuf *zds_ret;
    int    zds_rettype;
};

#pragma pack (pop)
#endif
