#include "pch.h"
#include "main.h"
#include "MFCHangman/MFCHangman.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CMFCHangmanApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CMFCHangmanApp::CMFCHangmanApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CMFCHangmanApp theApp;

BOOL CMFCHangmanApp::InitInstance()
{
	__super::InitInstance();

	MFCHangman::InitGame(nullptr);
	return FALSE;
}

