#include "includes.h"
#include "core\Window.h"
#include "core\ResourceManager.h"
#include "core\InputManager.h"
#include "game\Game.h"


int main(int argc, char** argv)
{
	Window window;
	Game game;

	while(window.IsRunning())
	{
			  game.Run();
	}



	return 0;
}