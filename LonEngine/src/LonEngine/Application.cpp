#include "lepch.h"
#include "Application.h"
#include "LonEngine/Log.h"
#include "Events/Event.h"

#include "Events/ApplicationEvent.h"

namespace LonEngine
{
Application::Application()
{
}

Application::~Application()
{
}

void Application::Run()
{
    WindowResizeEvent e(1280, 720);
    LE_TRACE(e.ToString());
    while (true);
}
}
