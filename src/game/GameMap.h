#pragma once
#include "../includes.h"
#include "BasicObject.h"


class GameMap
{
public:
	GameMap();
	~GameMap();

	bool LoadFromFile( const char* _path );

	SDL_Point GetPlayerPosition() { return mPlayerPos; }
	SDL_Point GetMapSize() { return mSize; }
	
	static int GetMapCell( SDL_Point _pos ) { return mMap[_pos.x][_pos.y]; }
	static void ClearCell( SDL_Point _pos ) { mMap[_pos.x][_pos.y] = 0; }

	void Draw();


private:
	static int** mMap;
	SDL_Point mPlayerPos;
	SDL_Point mSize;
	BasicObject mCell;
	BasicObject mTreasure;
	BasicObject mMonster;
	BasicObject mWall;

};

