#pragma once

#define CXTResize CResize2

// ------------------------------------------------------------------------------------------------------------------------
// class	- Resize2
// Summary	- 
// author	- yhl
// date		- 2016/08/15
// ------------------------------------------------------------------------------------------------------------------------
class CResize2
{
public:
	CResize2(CWnd* pWnd = nullptr);

private:
	CWnd* m_pWnd;
};

inline CResize2::CResize2(CWnd* pWnd): m_pWnd(pWnd)
{
}
