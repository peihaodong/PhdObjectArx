
#ifndef ZRXVERSION_HEADERFILE
#define ZRXVERSION_HEADERFILE

/*
                                        !!IMPORTANT!!                                               
根据二进制兼容讨论结果，ZRXVERNUM在加载zrx模块时，由zrxKeyCheck使用ZRX_MAIN_VERSION来进行兼容性判断。
ZRX_PATCH_VERSION不作为判断条件。
关于这两个值的维护：
ZRX_MAIN_VERSION只有在ZRX产生不兼容修改时才修改。
ZRX_PATCH_VERSION仍可按原规则维护，但是不作为兼容性判断的条件。

具体判断方案详见zrxKeyCheck函数的实现。
*/
const  unsigned int  ZRX_MAIN_VERSION = 2018; //ZRX不兼容时才修改
const  unsigned int  ZRX_PATCH_VERSION = 40;
//规则：sp1:10, sp1-1:11, sp1-2:12,......sp2:20, sp2-1:21,....以此类推



#endif	//ZRXVERSION_HEADERFILE