#include "twpch.h"
#include "Application.h"
#include "Event/ApplicationEvent.h"
#include "Log.h"


namespace Twist
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(new Window());
		m_Window->Init();
	}

	Application::~Application()
	{
	
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
