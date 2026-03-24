#pragma once

#include "Core.h"
#include "Event/Event.h"
#include "GLFW/glfw3.h"

namespace Twist
{
	class TWIST_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		Window();
		Window(const std::string& title, unsigned int width, unsigned int height);
		~Window();

		void Init();
		void OnUpdate();

		unsigned int GetWidth() const { return m_Data.width; }
		unsigned int GetHeight() const { return m_Data.height; }

		void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled);
		bool IsVSync() const { return m_Data.VSync; };

		//static Window* Create(const WindowInstance& wInst = WindowInstance());

	private:
		void ShutDown();

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string title;
			int width, height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}