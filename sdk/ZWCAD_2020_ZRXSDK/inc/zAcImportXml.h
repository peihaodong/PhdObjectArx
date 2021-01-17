#pragma once

#include "zadesk.h"
#ifdef _ZSOFT_WINDOWS_
#import "msxml6.dll" named_guids rename_namespace("MSXML") rename("offset", "MSXMLoffset")
__declspec(selectany) extern const GUID CLSID_DOMDocumentZcad = MSXML::CLSID_DOMDocument60;
#endif
