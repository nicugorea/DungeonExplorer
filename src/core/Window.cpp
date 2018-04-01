#include "Window.h"




SDL_Window*		Window::gWindow = nullptr;
SDL_Renderer*	Window::gRenderer = nullptr;
SDL_Event*		Window::gEvent = nullptr;
TTF_Font*		Window::gFont = nullptr;
bool			Window::running = false;



Window::Window()
{
	running = Init();
}


Window::~Window()
{				   
	TTF_CloseFont( gFont );
	delete(gEvent);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

bool Window::Init()
{
	if(SDL_Init( SDL_INIT_VIDEO ))
	{
		LOGLN( "SDL init error" );
		return false;
	}

	if(!IMG_Init( IMG_INIT_PNG ))
	{
		LOGLN( "IMG init error" );
		return false;
	}

	if(TTF_Init())
	{
		LOGLN( "TFF init error" );
		return false;
	}

	gWindow = SDL_CreateWindow( WINDOW_N, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, NULL );
	if(gWindow == nullptr)
	{
		LOGLN( "Creating Window error" );
		return false;
	}

	gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
	if(gRenderer == nullptr)
	{
		LOGLN( "Creating Renderer error" );
		return false;
	}

	gEvent = new SDL_Event;
	if(gEvent==nullptr)
	{
		LOGLN( "Creating Event error" );
		return false;
	}

	gFont = TTF_OpenFont( "res/font/font.ttf", 32 );

	return true;
}
