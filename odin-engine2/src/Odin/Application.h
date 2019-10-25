#pragma once

#include "Core.h"

namespace Odin {
	class ODIN_API Application
	{
		public:
			Application();
			virtual ~Application(); 

			void Run();
	};


	// to be defined in client
	Application * CreateApplication();
}


