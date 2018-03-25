#include "ResourceManager.h"
#include "Window.h"


ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
}

void ResourceManager::Clear()
{
	SDL_SetRenderDrawColor( Window::gRenderer, BG_COLOR );
	SDL_RenderClear( Window::gRenderer );
}

void ResourceManager::Show()
{
	SDL_RenderPresent(Window::gRenderer);
}
