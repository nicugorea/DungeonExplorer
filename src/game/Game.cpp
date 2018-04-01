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
	mScore.SetPosition( { WINDOW_W - SCORE_W, SCORE_H } );

	Uint32 lastFrame = SDL_GetTicks();
	int delay;

	while(mRunning)
	{

		EventHandle();
		
		ResourceManager::Clear();

		mMap.Draw();
		mPlayer.Draw();
		mScore.Draw();

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
	//mScore.SetTexture( ResourceManager::GetTextureFromFile( "res/img/player.png" ) );
	mScore.SetTexture( ResourceManager::GetTextureFromFont( mPlayer.GetScore() ) );
	mScore.SetSizeFromTexture();

}
