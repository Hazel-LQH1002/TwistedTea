#pragma once

#ifdef TW_PLATFORM_WINDOWS

extern Twist::Application* Twist::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Twist::CreateApplication();
	app->Run();
	delete app;
}
#endif