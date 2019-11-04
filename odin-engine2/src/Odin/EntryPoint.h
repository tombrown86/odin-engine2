#pragma once


#ifdef ODIN_PLATFORM_WINDOWS
	extern Odin::Application * Odin::CreateApplication();

	int main(int argc, char** argv)
	{
		printf("Odin engine");
		
		Odin::Log::init();
		ODIN_CORE_WARN("Initialized CoreLogger !!! ");
		ODIN_INFO("Initialized ClientLogger {0} !!! ", "poo");

		auto app = Odin::CreateApplication();
		app->Run();
		delete app;
	}
#endif