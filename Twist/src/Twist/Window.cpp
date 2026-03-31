#include "twpch.h"
#include "Window.h"
#include "Log.h"

#include "Event/ApplicationEvent.h"
#include "Event/KeyEvent.h"
#include "Event/MouseEvent.h"

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

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* pWindow, int width, int height)
			{
				WindowData* pWindowData = (WindowData*)glfwGetWindowUserPointer(pWindow);
				pWindowData->width = width;
				pWindowData->height = height;

				WindowResizedEvent event(width, height);
				pWindowData->EventCallback(event);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* pWindow)
			{
				WindowData* pWindowData = (WindowData*)glfwGetWindowUserPointer(pWindow);
				WindowClosedEvent event;
				pWindowData->EventCallback(event);
			});

		glfwSetWindowMaximizeCallback(m_Window, [](GLFWwindow* pWindow, int maximized)
			{
				WindowData* pWindowData = (WindowData*)glfwGetWindowUserPointer(pWindow);
				if (maximized == GLFW_TRUE)
				{
					WindowMaximizedEvent event;
					pWindowData->EventCallback(event);
				}
				else
				{
					TW_CORE_ASSERT(false, "maximize window fails, too bad, but what can you do??");
				}
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* pWindow, int button, int action, int mods)
			{
				WindowData* pWindowData = (WindowData*)glfwGetWindowUserPointer(pWindow);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					pWindowData->EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					pWindowData->EventCallback(event);
					break;
				}
				default:
					TW_CORE_ASSERT(false, "Congrats, you neither pressed nor released mouse button, but somehow triggered mouse button event, what a genius!");
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* pWindow, double xoffset, double yoffset)
			{
				WindowData* pWindowData = (WindowData*)glfwGetWindowUserPointer(pWindow);
				MouseScrolledEvent event(xoffset, yoffset);
				pWindowData->EventCallback(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* pWindow, double xPos, double yPos)
			{
				WindowData* pWindowData = (WindowData*)glfwGetWindowUserPointer(pWindow);
				MouseMovedEvent event(xPos, yPos);
				pWindowData->EventCallback(event);
			});
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