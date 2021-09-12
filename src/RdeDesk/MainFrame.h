#pragma once

#include "OweSpace/MainFrame.h"

class MainFrame : public OweMainFrame
{
public:
	BEGIN_OLE_COMMAND_HANDLER_MAP_EX(MainFrame, OweMainFrame)
		OLE_COMMAND_HANDLER(GUID_StdCommandSet, ID_ABOUT, OnCmdEnabled, OnAbout)
	END_OLE_COMMAND_HANDLER_MAP_EX()

	void OnAbout(LPCGUID pCmdGroupGuid, DWORD nCmdID, DWORD /*flags*/, VARIANT* /*pIn*/, VARIANT* /*pOut*/);
};