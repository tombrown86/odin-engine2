#pragma once

#ifdef ODIN_PLATFORM_WINDOWS

	extern Odin::Application * Odin::CreateApplication();

	int main(int argc, char** argv)
	{
		printf("Odin engine");
		auto app = Odin::CreateApplication();
		app->Run();
		delete app;
	}

#endif