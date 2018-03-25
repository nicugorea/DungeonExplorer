#include "includes.h"

#include "core\Window.h"
#include "core\ResourceManager.h"
#include "core\InputManager.h"
#include "game\BasicObject.h"
#include "game\GameMap.h"



int main(int argc, char** argv)
{
	Window window;
	GameMap map;
	map.LoadFromFile( "res/map/map.txt" );

	while(window.IsRunning())
	{
		InputManager::EventHandle();

		ResourceManager::Clear();
		map.DrawMap();
		

	
		ResourceManager::Show();
	}



	return 0;
}