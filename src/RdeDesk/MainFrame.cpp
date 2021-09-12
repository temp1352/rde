#include "stdafx.h"
#include "MainFrame.h"

#include "AboutDialog.h"

#include <atldlgs.h>

void MainFrame::OnAbout(LPCGUID pCmdGroupGuid, DWORD nCmdID, DWORD /*flags*/, VARIANT* /*pIn*/, VARIANT* /*pOut*/)
{
	/*CPropertyPage<6501> testPage;
	testPage.m_psp.hInstance = _AtlBaseModule.GetModuleInstance();

	CPropertySheet testSheet;
	testSheet.AddPage(testPage);
	testSheet.SetWizardMode();
	testSheet.m_psh.dwFlags |= PSH_AEROWIZARD;
	testSheet.DoModal();*/

	AboutDialog dlg;
	dlg.DoModal();
}