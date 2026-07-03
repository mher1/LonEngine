#pragma once
#include "Core.h"
namespace LonEngine
{
	class LONENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	//this will be defined in client
	Application* CreateApplication();
}

