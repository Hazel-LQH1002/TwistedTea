#include "Application.h"
#include "Event/ApplicationEvent.h"
#include "Log.h"


namespace Twist
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent resizeEvent(1280, 720);
		if (resizeEvent.IsInCategory(EventCategoryApplication))
		{
			TW_TRACE(resizeEvent.GetEventString());
		}
		if (resizeEvent.IsInCategory(EventCategoryInput))
		{
			TW_TRACE(resizeEvent.GetEventString());
		}

		while (true);
	}
}
