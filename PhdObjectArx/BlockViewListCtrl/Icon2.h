#pragma once

#define CXTPImageManagerIconHandle CIcon2

class CIcon2
{
public:

	CIcon2& operator =(HICON _icon);

	explicit CIcon2(HICON _icon = nullptr);

	~CIcon2();

	void Draw(CDC* pDc, POINT pt, SIZE sz);

private:
	HICON m_hIcon;
};

inline CIcon2& CIcon2::operator=(HICON _icon)
{
	m_hIcon = _icon;
	return *this;
}

inline CIcon2::CIcon2(HICON _icon): m_hIcon(_icon)
{
}

inline CIcon2::~CIcon2()
{
	if (nullptr != m_hIcon)
	{
		::DestroyIcon(m_hIcon);
	}
}

inline void CIcon2::Draw(CDC* pDc, POINT pt, SIZE sz)
{
	pDc->DrawIcon(pt, m_hIcon);
}
