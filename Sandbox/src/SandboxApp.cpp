#include <LonEngine.h>
class Sandbox : public LonEngine::Application 
{
public :
	Sandbox()
	{

	}
	~Sandbox() 
	{

	}
};
LonEngine::Application* LonEngine::CreateApplication()
{
	return new Sandbox;
}