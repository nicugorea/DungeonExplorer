#include "includes.h"

#include "core\Window.h"
#include "core\ResourceManager.h"
#include "core\InputManager.h"
#include "game\BasicObject.h"



int main(int argc, char** argv)
{
	Window window;
	BasicObject obj;

	obj.SetTexture( ResourceManager::GetTextureFromFile( "res/img/cell.png" ) );

	while(window.IsRunning())
	{
		InputManager::EventHandle();

		ResourceManager::Clear();
		obj.Draw();

		

	
		ResourceManager::Show();
	}



	return 0;
}