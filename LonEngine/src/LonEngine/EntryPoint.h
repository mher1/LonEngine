#pragma once
#ifdef LE_Platform_Windows

extern LonEngine::Application* LonEngine::CreateApplication();
int main(int argc, char** argv) 
{
	LonEngine::Log::Init();


	auto app = LonEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif