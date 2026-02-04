#pragma once

#ifdef TW_PLATFORM_WINDOWS

extern Twist::Application* Twist::CreateApplication();

int main(int argc, char** argv)
{
	Twist::Log::Init();
	TW_CORE_WARN("Initialized Core Log!");
	int a = 5;
	int b = 6;
	TW_INFO("Client Info! Var={0} Nextvar={1}", a, b);
	auto app = Twist::CreateApplication();
	app->Run();
	delete app;
}
#endif