#pragma once

#include "Core.h"
#include "Event/Event.h"

namespace Twist
{
	class TWIST_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined In Client
	Application* CreateApplication();

}

