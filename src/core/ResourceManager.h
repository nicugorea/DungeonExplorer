#pragma once
#include "../includes.h"
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	static void Clear();
	static void Show();

	static SDL_Texture* GetTextureFromFile( const char* _path );

	static void DrawEntity( Entity& _entity );

};

