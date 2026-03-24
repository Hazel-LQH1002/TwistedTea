#include "twpch.h"
#include "Window.h"
#include "Log.h"

namespace Twist
{
	static bool s_GLFWInitialized = false;

	Window::Window()
	{
		m_Data.title = "The Best Engine In The World!!";
		m_Data.width = 1280;
		m_Data.height = 720;
	}

	Window::Window(const std::string& title, unsigned int width, unsigned int height)
	{
		m_Data.title = title;
		m_Data.width = width;
		m_Data.height = height;
	}

	Window::~Window()
	{
		ShutDown();
	}

	void Window::Init()
	{
		TW_CORE_INFO("Creating Window title-{0},width-{1},height-{2}", m_Data.title, m_Data.width, m_Data.height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			TW_CORE_ASSERT(success, "Could not intialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void Window::ShutDown()
	{
		glfwDestroyWindow(m_Window);
	}

	void Window::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Window::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}
}