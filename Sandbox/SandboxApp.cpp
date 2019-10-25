#include "Odin.h"

class SandboxApp : public Odin::Application
{
	public:
		SandboxApp()
		{

		}
		~SandboxApp()
		{

		}
};


Odin::Application * Odin::CreateApplication()
{
	return new SandboxApp();
}