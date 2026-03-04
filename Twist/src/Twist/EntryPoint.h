#pragma once

#ifdef TW_PLATFORM_WINDOWS

extern Twist::Application* Twist::CreateApplication();

int main(int argc, char** argv)
{
	Twist::Log::Init();
	TW_CORE_WARN("Initialized Core Log! Dumb Game is running, can you believe it??");
	auto app = Twist::CreateApplication();
	app->Run();
	delete app;
}
#endif