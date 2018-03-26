#include "InputManager.h"
#include "Window.h"


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::EventHandle()
{
	while(SDL_PollEvent( Window::gEvent ))
	{
		if(Window::gEvent->type == SDL_QUIT)
			Window::Close();
	}
	

}

bool InputManager::IsKeyDown( SDL_Keycode _keycode )
{
	return SDL_GetKeyboardState( NULL )[_keycode];
}
