#pragma once
#include "../includes.h"
#include "BasicObject.h"

class Player : public BasicObject
{
public:
	Player();
	~Player();
	
	void EventHandle();
	void SetPosition(SDL_Point _point);
	void SetMapSize( SDL_Point& _mapSize ) { mMapSize = _mapSize; }
	
	int GetScore() { return mScore; }

	void Draw();

private:
	double mAngle;
	SDL_Point mCenter;
	SDL_RendererFlip mFlip=SDL_FLIP_NONE;

	SDL_Point mMapSize;

	int mScore;
};

