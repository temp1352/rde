#include "stdafx.h"
#include "AboutDialog.h"

#include "Resource2.h"

#include "OweSpace/AppBase.h"

AboutDialog::AboutDialog()
	: AwxDialog(_theApp, IDD_ABOUTBOX, _AtlBaseModule.GetResourceInstance())
{
}