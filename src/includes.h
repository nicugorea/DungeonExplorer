#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>

typedef struct{
	SDL_Rect rectOnScreen;
	SDL_Rect rectOnTexture;
	SDL_Texture* texture;

}Entity;



#define WINDOW_W 1024
#define WINDOW_H 512
#define WINDOW_N "Dungeon Explorer"

#define LOG(info)  std::cout<<info
#define LOGLN(info)  std::cout<<info<<'\n'

#define STD_RECT {0,0,128,128}

#define BG_COLOR 27,3,199,255



