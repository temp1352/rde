#pragma once

#include "OweSpace/AppBase.h"

class Application : public OweAppBase
{
public:
	Application();

	static bool TryRegistry(LPCWSTR cmdLine);
};