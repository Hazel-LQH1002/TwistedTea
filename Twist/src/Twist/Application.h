#pragma once

#include "Core.h"
#include "Event/Event.h"
#include "Window.h"

namespace Twist
{
	class TWIST_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined In Client
	Application* CreateApplication();
}

