

#ifndef _ZACEDINET_H_
#define _ZACEDINET_H_
#pragma pack (push, 8)

extern ZSoft::Boolean
zcedCreateShortcut(void* pvHwndParent, const ZTCHAR* szLinkPath,
				   const ZTCHAR* szObjectPath, const ZTCHAR* szDesc);

extern ZSoft::Boolean
zcedResolveShortcut(void* pvHwndParent, const ZTCHAR* szLinkPath,
					ZTCHAR* szObjectPath);

extern ZSoft::Boolean
zcedGetUserFavoritesDir(ZTCHAR* szFavoritesDir);

extern ZSoft::Boolean
zcedCreateInternetShortcut(const ZTCHAR* szURL, const ZTCHAR* szShortcutPath);

extern ZSoft::Boolean
zcedResolveInternetShortcut(const ZTCHAR* szLinkFile, ZTCHAR* szUrl);

#pragma pack (pop)
#endif	
