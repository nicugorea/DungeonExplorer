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
	SDL_RenderPresent( Window::gRenderer );
}

SDL_Texture * ResourceManager::GetTextureFromFile( const char * _path )
{
	SDL_Surface* tmpSurface = IMG_Load( _path );
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface( Window::gRenderer, tmpSurface );
	SDL_FreeSurface( tmpSurface );
	return tmpTexture;
}

SDL_Texture * ResourceManager::GetTextureFromFont( int  _val )
{
	char text[32];
	itoa( _val, text, 10 );
	SDL_Surface* tmpSurface = TTF_RenderText_Blended( Window::gFont, text, { 123,32,55 } );
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface( Window::gRenderer, tmpSurface );
	SDL_FreeSurface( tmpSurface );

	return tmpTexture;
}

void ResourceManager::DrawEntity( Entity & _entity )
{
	SDL_RenderCopy( Window::gRenderer, _entity.texture, &_entity.rectOnTexture, &_entity.rectOnScreen );
}

void ResourceManager::DrawEntityEx( Entity & _entity, double & _angle, SDL_Point& _center, SDL_RendererFlip _flip )
{
	SDL_RenderCopyEx( Window::gRenderer, _entity.texture, &_entity.rectOnTexture, &_entity.rectOnScreen, _angle, &_center, _flip );
}


