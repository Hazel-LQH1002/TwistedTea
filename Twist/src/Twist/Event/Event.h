#pragma once

#include "twpch.h"
#include "Core.h"

namespace Twist
{
	enum class EventType_e
	{
		NONE = 0,
		WindowClosed,
		WindowResized,
		WindowMoved,
		WindowMaximized,
		AppTick,
		AppUpdate,
		AppRender,
		KeyPressed,
		KeyReleased,
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	enum EventCategory_e
	{
		NONE = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type)					\
	static EventType_e GetStaticType()	{return EventType_e::##type;}		\
	EventType_e GetEventType() const override {return GetStaticType();}	\
	const char* GetEventName() const override {return #type;};				\

#define EVENT_CLASS_CATEGORY(category) int GetCategoryFlags() const override {return category;}

	class TWIST_API Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType_e GetEventType() const = 0;
		virtual const char* GetEventName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string GetEventString() const { return GetEventName(); }

		inline bool IsInCategory(EventCategory_e category) { return GetCategoryFlags() & category; }

	protected:
		bool m_Handled = false;
	};

	class TWIST_API EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			:m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};	

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.GetEventString();
	}
}




