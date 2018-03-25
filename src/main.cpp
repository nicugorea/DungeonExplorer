#include "includes.h"

#include "core\Window.h"
#include "core\ResourceManager.h"
#include "core\InputManager.h"



int main(int argc, char** argv)
{
	Window window;


	while(window.IsRunning())
	{
		InputManager::EventHandle();

		ResourceManager::Clear();
	



	
		ResourceManager::Show();
	}



	return 0;
}