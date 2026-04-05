#include "twpch.h"
#include "Application.h"
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
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>([this](WindowClosedEvent &e)
			{
				return OnWindowClose(e);
			});
		std::cout << e.GetEventString() << std::endl;
	}

	bool Application::OnWindowClose(WindowClosedEvent& e)
	{
		m_Running = false;
		return true;
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
