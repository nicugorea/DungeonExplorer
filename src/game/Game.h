#pragma once
#include "../includes.h"

#include "BasicObject.h"
#include "GameMap.h"
#include "Player.h"

#include "../core/InputManager.h"
#include "../core/ResourceManager.h"



class Game
{
public:
	Game();
	~Game();

	void Run();
	void Reset();
	void Stop();

	void EventHandle();

private:
	bool mRunning;
	GameMap mMap;
	Player mPlayer;
	BasicObject mScore;

};

