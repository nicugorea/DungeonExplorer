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



#define WINDOW_W 1200
#define WINDOW_H 675
#define WINDOW_N "Dungeon Explorer"

#define LOG(info)  std::cout<<info
#define LOGLN(info)  std::cout<<info<<'\n'

#define SPEED 200

#define STD_X 0
#define STD_Y 0
#define STD_W 128
#define STD_H 128

#define SCALE_TEXTURE 0.5

#define SCALED_W (int)(STD_W*SCALE_TEXTURE)
#define SCALED_H (int)(STD_H*SCALE_TEXTURE)


#define SCALED_RECT {STD_X, STD_Y, SCALED_W, SCALED_H}
#define STD_RECT {STD_X,STD_Y,STD_W,STD_H}

#define BG_COLOR 27,3,199,255

#define FPS 1000/30



