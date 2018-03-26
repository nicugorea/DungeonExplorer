#pragma once
#include "../includes.h"

class InputManager
{
public:
	InputManager();
	~InputManager();

	static void EventHandle();

	static bool IsKeyDown( SDL_Keycode _keycode );

};

