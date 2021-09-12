#include "stdafx.h"
#include "Application.h"

#include "Resource2.h"

#include "OweShell/KeyNames.h"
#include "OweShell/OweReg.h"

Application::Application()
	: OweAppBase(_AtlBaseModule)
{
	m_flags &= ~OWE_AF_SHOW_START_PAGE;
	m_flags |= OWE_AF_HIDE_SOLUTION | OWE_AF_HIDE_SOLUTION_NODE | OWE_AF_STORAGE_DOC;

	/*OweKeyNames::Company = L"Keymnt";
	OweKeyNames::AppName = L"RdeDesk";
	OweKeyNames::Version = L"1.0";*/
}

OWE_REG_ENTRY _regMap[] = {
	{ OWE_REG_ROOT_BEGIN, L"REGROOT_BEGIN", 0 },
	{ OWE_REG_ROOT_END, L"REGROOT_END", 0 },
	{ OWE_REG_END, nullptr, 0 },
};

void _UpdateRegistry(BOOL bRegister)
{
	CComModule module;
	HRESULT hr = RegEnvironement::UpdateFromResource(IDR_APP, bRegister, _regMap);
	if (FAILED(hr))
	{
		Message::MessageBoxH(nullptr, hr);
	}
}

bool Application::TryRegistry(LPCWSTR cmdLine)
{
	if (cmdLine)
	{
		if (!_wcsicmp(cmdLine, L"/Register") || !_wcsicmp(cmdLine, L"-Register"))
		{
			_UpdateRegistry(TRUE);
			return true;
		}
		else if (!_wcsicmp(cmdLine, L"/UnRegister") || !_wcsicmp(cmdLine, L"-UnRegister"))
		{
			_UpdateRegistry(FALSE);
			return true;
		}
	}

	return false;
}
