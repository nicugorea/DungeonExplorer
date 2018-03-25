#pragma once
#include "../includes.h"
#include "BasicObject.h"


class GameMap
{
public:
	GameMap();
	~GameMap();

	bool LoadFromFile( const char* _path );
	void DrawMap();

private:
	int** mMap;
	SDL_Point mSize;
	BasicObject mCell;
	BasicObject mTreasure;
	BasicObject mMonster;
	BasicObject mWall;

};

