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
		m_Window->Bind_CallBackFn(this, &Application::OnEvent);
	}

	Application::~Application()
	{
	
	}

	void Application::OnEvent(Event& e)
	{
		std::cout << e.GetEventString() << std::endl;
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
