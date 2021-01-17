
#include "zacarray.h"

#ifndef ZcDMMUtils_h
#define ZcDMMUtils_h

typedef const wchar_t * PCWIDESTR;
typedef wchar_t * PWIDESTR;

class ZcDMMWideString
{
public:
    ZcDMMWideString();
    ZcDMMWideString(const ZcDMMWideString& ws);
    ZcDMMWideString(PCWIDESTR pwsz);
    virtual ~ZcDMMWideString();
    const ZcDMMWideString& operator= (const ZcDMMWideString& ws);
    const ZcDMMWideString& operator= (PCWIDESTR pwsz);
    operator PCWIDESTR() const;
    void   Empty();
    bool   IsEmpty() const;
    unsigned GetLength() const;
    const ZcDMMWideString& operator+= (ZcDMMWideString ws);

    friend ZcDMMWideString operator+
        (const ZcDMMWideString& wsLeft, wchar_t wch);
    friend ZcDMMWideString operator+
        (wchar_t wch, const ZcDMMWideString& wsRight);
    friend ZcDMMWideString operator+
        (const ZcDMMWideString& wsLeft, const ZcDMMWideString& wsRight);

private:
    void Alloc(size_t iLen);
    void Alloc(PCWIDESTR pwsz,size_t iLen);
    void Alloc(PCWIDESTR pwsz);
    static void Release(PWIDESTR pwsz);
    void Release();

    void MoveChars(int iStartOffset,PCWIDESTR pwsz,size_t iChars);

    PWIDESTR  m_pData;
    unsigned  m_iLength;
};

inline void ZcDMMWideString::MoveChars(int iStartOffset,
                                       PCWIDESTR pwsz, size_t iChars)
{
    const unsigned n32Chars = (unsigned)iChars;
    assert(n32Chars == iChars);
    assert(iStartOffset >=0);
    assert((unsigned)iStartOffset <= m_iLength);
    assert(iStartOffset + iChars <= m_iLength+1);

    memmove(m_pData+iStartOffset,
            pwsz,
            iChars * sizeof(wchar_t));
}

inline ZcDMMWideString operator+ (const ZcDMMWideString& wsLeft, wchar_t wch)
{
    ZcDMMWideString wsRet;

    wsRet.Alloc(wsLeft.m_pData,wsLeft.GetLength()+1);
    wsRet.m_pData[wsLeft.GetLength()] = wch;
    wsRet.m_pData[wsLeft.GetLength()+1] = 0;

    return(wsRet);
}

inline ZcDMMWideString operator+ (wchar_t wch, const ZcDMMWideString& wsRight)
{
    ZcDMMWideString wsRet;

    wsRet.Alloc(wsRight.GetLength()+1);
    wsRet.m_pData[0] = wch;
    wsRet.MoveChars(1,wsRight.m_pData,wsRight.GetLength()+1);

    return(wsRet);
}

inline ZcDMMWideString operator+ (const ZcDMMWideString& wsLeft,
    const ZcDMMWideString& wsRight)
{
    ZcDMMWideString wsRet(wsLeft);
    wsRet += wsRight;
    return(wsRet);
}

inline const ZcDMMWideString& ZcDMMWideString::operator += (ZcDMMWideString ws)
{
    if(!ws.IsEmpty()) {
        ZcDMMWideString wsOldThis = *this;
        Empty();
        Alloc(wsOldThis.GetLength() + ws.GetLength());

        MoveChars(0,wsOldThis.m_pData,wsOldThis.GetLength());

        MoveChars(wsOldThis.GetLength(),ws.m_pData,ws.GetLength()+1);
    }

    return(*this);
}

inline ZcDMMWideString::ZcDMMWideString()
: m_pData(NULL),
  m_iLength(0)
{
}

inline ZcDMMWideString::ZcDMMWideString(const ZcDMMWideString& ws)
: m_pData(NULL),
  m_iLength(0)
{
    Alloc(ws.m_pData? ws.m_pData: L"",ws.m_iLength);
}

inline ZcDMMWideString::ZcDMMWideString(PCWIDESTR pwsz)
: m_pData(NULL),
  m_iLength(0)
{
    Alloc(pwsz);
}

inline ZcDMMWideString::~ZcDMMWideString()
{
    Empty();
}

inline bool ZcDMMWideString::IsEmpty() const
{
    return(m_iLength == 0);
}

inline void ZcDMMWideString::Empty()
{
    if(m_pData)
        Release();

    m_iLength = 0;
}
inline ZcDMMWideString::operator PCWIDESTR() const
{
    return(m_pData ? m_pData : L"");
}
inline const ZcDMMWideString& ZcDMMWideString::operator=
    (const ZcDMMWideString& ws)
{
    Empty();
    m_iLength = ws.m_iLength;
    Alloc(ws.m_pData,ws.m_iLength);

    return(*this);
}

inline const ZcDMMWideString& ZcDMMWideString::operator= (PCWIDESTR pwsz)
{
    Empty();
    m_iLength = (unsigned)wcslen(pwsz);
    Alloc(pwsz,m_iLength);

    return(*this);
}

inline unsigned ZcDMMWideString::GetLength() const
{
    return this->m_iLength;
}
inline void ZcDMMWideString::Alloc(size_t iLen)
{
    assert(m_pData == NULL);
    assert(iLen == (unsigned)iLen);
    m_iLength = (unsigned)iLen;
    m_pData = new wchar_t[m_iLength+1];
}

inline void ZcDMMWideString::Alloc(PCWIDESTR pwsz,size_t iLen)
{
    assert(m_pData == NULL);
    assert(pwsz != NULL);

    if(iLen > 0) {
        Alloc(iLen);
        MoveChars(0,pwsz,iLen+1);
    }
}

inline void ZcDMMWideString::Alloc(PCWIDESTR pwsz)
{
    assert(m_pData == NULL);
    assert(pwsz != NULL);
	if (pwsz == NULL)
		return;
    Alloc(pwsz,wcslen(pwsz));
}

inline void ZcDMMWideString::Release(PWIDESTR pwsz)
{
    if (pwsz)
        delete[] pwsz;
}
inline void ZcDMMWideString::Release()
{
    Release(m_pData);
    m_pData = NULL;
    m_iLength = 0;
}

typedef ZcArray<ZcDMMWideString> ZcDMMStringVec;

class ZcDMMNode
{
public:
    ZcDMMNode()
    : m_nodeNumber(0),
      m_nodeName(NULL)
    {
    }
    ZcDMMNode(int number, wchar_t * name)
    {
        m_nodeNumber = number;
        if (NULL != name) {
			size_t nSize = ::wcslen(name) + 1;
            m_nodeName = new wchar_t[nSize];
            ::wcscpy_s(m_nodeName, nSize, name);
        } else
            m_nodeName = NULL;
    }
    ZcDMMNode(const ZcDMMNode &src)
    : m_nodeName(NULL)
    {
        *this = src;
    }
    ~ZcDMMNode()
    {
        if (NULL != m_nodeName)
            delete []m_nodeName;
    }
    int nodeNumber()const {return m_nodeNumber;};
    void SetNodeNumber(int number) {m_nodeNumber = number;};
    const wchar_t * nodeName()const {return m_nodeName;};
    void SetNodeName(const wchar_t * name)
    {
        if (NULL != m_nodeName)
            delete []m_nodeName;
        if (NULL != name) {
			size_t nSize = ::wcslen(name) + 1;
            m_nodeName = new wchar_t[nSize];
            ::wcscpy_s(m_nodeName, nSize, name);
        } else
            m_nodeName = NULL;
    }
    ZcDMMNode & operator= (const ZcDMMNode &src)
    {
        if (this == &src)
            return *this;

        SetNodeNumber(src.m_nodeNumber);
        SetNodeName(src.m_nodeName);
        return *this;
    }

private:
    int m_nodeNumber;
    wchar_t * m_nodeName;
};

class ZcDMMResourceInfo
{
public:
    ZcDMMResourceInfo()
    : m_mime(NULL),
      m_role(NULL),
      m_path(NULL)
    {
    }
    ZcDMMResourceInfo(const wchar_t *role, const wchar_t *mime,
        const wchar_t *path)
    {
        if (NULL != role) {
			size_t nSize = ::wcslen(role) + 1;
            m_role = new wchar_t[nSize];
            ::wcscpy_s(m_role, nSize, role);
        } else
            m_role = NULL;

        if (NULL != mime) {
			size_t nSize = ::wcslen(mime) + 1;
            m_mime = new wchar_t[nSize];
            ::wcscpy_s(m_mime, nSize, mime);
        } else
            m_mime = NULL;

        if (NULL != path) {
			size_t nSize = ::wcslen(path) + 1;
            m_path = new wchar_t[nSize];
            ::wcscpy_s(m_path, nSize, path);
        } else
            m_path = NULL;
    }
    ZcDMMResourceInfo(const ZcDMMResourceInfo & src)
    : m_role(NULL),
      m_mime(NULL),
      m_path(NULL)
    {
        *this = src;
    }
    ~ZcDMMResourceInfo()
    {
        if (NULL != m_role)
            delete []m_role;
        if (NULL != m_mime)
            delete []m_mime;
        if (NULL != m_path)
            delete []m_path;
    }
    void SetRole(wchar_t * role)
    {
        if (NULL != m_role)
            delete []m_role;
        if (NULL != role) {
			size_t nSize = ::wcslen(role) + 1;
            m_role = new wchar_t[nSize];
            ::wcscpy_s(m_role, nSize, role);
        } else
            m_role = NULL;
    }
    const wchar_t * GetRole()const {return m_role;};
    void SetMime(wchar_t * mime)
    {
        if (NULL != m_mime)
            delete []m_mime;
        if (NULL != mime) {
			size_t nSize = ::wcslen(mime) + 1;
            m_mime = new wchar_t[nSize];
            ::wcscpy_s(m_mime, nSize, mime);
        } else
            m_mime = NULL;
    }
    const wchar_t * GetMime()const {return m_mime;};
    void SetPath(wchar_t * path)
    {
        if (NULL != m_path)
            delete []m_path;
        if (NULL != path) {
			size_t nSize = ::wcslen(path) + 1;
            m_path = new wchar_t[nSize];
            ::wcscpy_s(m_path, nSize, path);
        } else
            m_path = NULL;
    }
    const wchar_t * GetPath()const {return m_path;};
    ZcDMMResourceInfo& operator= (const ZcDMMResourceInfo &src)
    {
        if (this == &src)
            return *this;

        SetRole(src.m_role);
        SetMime(src.m_mime);
        SetPath(src.m_path);
        return *this;
    }

private:
    wchar_t * m_role;
    wchar_t * m_mime;
    wchar_t * m_path;
};

typedef ZcArray<ZcDMMResourceInfo> ZcDMMResourceVec;

#endif 
