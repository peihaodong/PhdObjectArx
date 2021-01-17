

#define     ASITRYSET   IncreaseGlobalAccount(0); try
#define     ASICATCHALL catch (int ASITRYCODE)
#define     ASITRYDEL   DecreaseGlobalAccount(0);
#define     ASITHROW(x) if( CheckGlobalAccount(0) ) throw((int)(x))
#pragma pack (push, 8)

DLLScope int IncreaseGlobalAccount(int ind);
DLLScope int DecreaseGlobalAccount(int ind);
DLLScope int CheckGlobalAccount(int ind);
#pragma pack (pop)
