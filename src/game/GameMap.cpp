#include "GameMap.h"
#include "../core/ResourceManager.h"



GameMap::GameMap()
{
	mCell.SetTexture( ResourceManager::GetTextureFromFile( "res/img/cell.png" ) );
	mWall.SetTexture( ResourceManager::GetTextureFromFile( "res/img/wall.png" ) );
	mTreasure.SetTexture( ResourceManager::GetTextureFromFile( "res/img/treasure.png" ) );
	mMonster.SetTexture( ResourceManager::GetTextureFromFile( "res/img/monster.png" ) );
}


GameMap::~GameMap()
{
	for(int i = 0; i < mSize.y; i++)
	{
		delete[]( mMap[i] );
	}
	delete[]( mMap );
}

bool GameMap::LoadFromFile( const char * _path )
{
	std::ifstream input( _path );
	if(!input.is_open())
	{
		LOGLN( "Can not open " << _path );
		return false;
	}
	input >> mSize.x;
	input >> mSize.y;

	mMap = new int*[mSize.y];
	for(int i = 0; i < mSize.y; i++)
	{
		mMap[i] = new int[mSize.x];
	}

	for(int i = 0; i < mSize.y; i++)
	{
		for(int j = 0; j < mSize.x; j++)
		{
			char tmp;
			input >> tmp;
			int id;
			if(tmp == 'W') id = 1;
			if(tmp == 'M') id = -2;
			if(tmp == 'T') id = -1;
			if(tmp == 'A') id = 0;

			mMap[i][j]=id;
		}

	}
	input.close();




}

void GameMap::DrawMap()
{
	for(int i = 0; i < mSize.y; i++)
	{
		for(int j = 0; j < mSize.x; j++)
		{
			mCell.SetPosition( { j*STD_W, i*STD_H } );
			mCell.Draw();
			if(mMap[i][j] == 1)
			{
				mWall.SetPosition( { j*STD_W, i*STD_H } );
				mWall.Draw();
			}
			if(mMap[i][j] == -1)
			{
				mTreasure.SetPosition( { j*STD_W, i*STD_H } );
				mTreasure.Draw();
			}
			if(mMap[i][j] == -2)
			{
				mMonster.SetPosition( { j*STD_W, i*STD_H } );
				mMonster.Draw();
			}
		}
	}


}


