#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::Run()
{
	mRunning = true;
	mMap.LoadFromFile( "res/map/map.txt" );
	mPlayer.SetPosition( mMap.GetPlayerPosition() );
	mPlayer.SetMapSize( mMap.GetMapSize() );

	Uint32 lastFrame = SDL_GetTicks();
	int delay;

	while(mRunning)
	{

		EventHandle();
		ResourceManager::Clear();
		mMap.Draw();
		mPlayer.Draw();


		ResourceManager::Show();


		if(delay < FPS)
		{
			SDL_Delay( FPS - delay );
			lastFrame = SDL_GetTicks();
		}
	}
}

void Game::EventHandle()
{
	InputManager::EventHandle();
	mPlayer.EventHandle();

}
