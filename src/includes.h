#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include <fstream>

typedef struct{
	SDL_Rect rectOnScreen;
	SDL_Rect rectOnTexture;
	SDL_Texture* texture;

}Entity;



#define WINDOW_W 1280
#define WINDOW_H 512
#define WINDOW_N "Dungeon Explorer"

#define LOG(info)  std::cout<<info
#define LOGLN(info)  std::cout<<info<<'\n'

#define STD_W 64
#define STD_H 64
#define STD_RECT {0,0,2*STD_W,2*STD_H}

#define BG_COLOR 27,3,199,255

#define FPS 1000/60


