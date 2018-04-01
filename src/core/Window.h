#pragma once
#include "../includes.h"

class Window
{
public:
	Window();
	~Window();
	bool IsRunning() { return running; }
	
	static void Close() { running = false; }


	static SDL_Window	*gWindow;
	static SDL_Renderer *gRenderer;
	static SDL_Event	*gEvent;
	static TTF_Font		*gFont;

private:
	bool Init();


	static bool running;

};

