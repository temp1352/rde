#include "stdafx.h"
#include "RpcShell.h"

#include <xdump.h>
#include "Application.h"
#include "MainFrame.h"

#include "OweConfig/Global.h"

XTL::AppDump _appDump(true);

int _Start(LPTSTR cmdLine, int cmdShow)
{
	wcscpy_s(OweGlobal::_appKeyName, L"Software\\Keymnt\\RdeDesk\\1.0");
	_SetLocalResourceInstance(_AtlBaseModule.GetModuleInstance());

	HRESULT hRes = RE_OleInitialize();

	ATLASSERT(SUCCEEDED(hRes));

	// this resolves ATL window thunking problem when Microsoft Layer for Unicode (MSLU) is used
	::DefWindowProc(NULL, 0, 0, 0L);

	//AtlInitCommonControls(ICC_BAR_CLASSES);	// add flags to support other controls

	ATLASSERT(SUCCEEDED(hRes));

	AtlAxWinInit();
	Application app;
	MainFrame mainFrame;
	int ret = app.Start(cmdLine, &mainFrame);

	_AtlWinModule.m_rgWindowClassAtoms.RemoveAll();

	RE_OleUninitialize();

	return ret;
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR cmdLine, int cmdShow)
{
	int ret = 0;
	if (!Application::TryRegistry(cmdLine))
	{
		ret = _Start(cmdLine, cmdShow);
	}

	return ret;
}
