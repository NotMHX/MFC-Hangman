#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"

class CMFCHangmanApp : public CWinApp
{
public:
	CMFCHangmanApp();

	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CMFCHangmanApp theApp;
