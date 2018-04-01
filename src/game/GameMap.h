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
	
	int** GetMap() { return mMap; }
	void UpdateMap( int**& _map )
	{
		for(int i = 0; i < mSize.y; i++)
			for(int j = 0; j < mSize.x; j++)
				mMap[i][j] = _map[i][j];
	}

	void Draw();


private:
	int** mMap;
	SDL_Point mPlayerPos;
	SDL_Point mSize;
	BasicObject mCell;
	BasicObject mTreasure;
	BasicObject mMonster;
	BasicObject mWall;

};

