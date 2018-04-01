#include "GameMap.h"
#include "../core/ResourceManager.h"

int** GameMap::mMap=nullptr;

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
			if(tmp == 'P') {
				id = 0;
				mPlayerPos.x = j;
				mPlayerPos.y = i;
			}

			mMap[i][j]=id;
		}

	}
	input.close();




}



void GameMap::Draw()
{
	for(int i = 0; i < mSize.y; i++)
	{
		for(int j = 0; j < mSize.x; j++)
		{
			mCell.SetPosition( { j*SCALED_W, i*SCALED_H } );
			mCell.Draw();
			if(mMap[i][j] == 1)
			{
				mWall.SetPosition( { j*SCALED_W, i*SCALED_H } );
				mWall.Draw();
			}
			if(mMap[i][j] == -1)
			{
				mTreasure.SetPosition( { j*SCALED_W, i*SCALED_H } );
				mTreasure.Draw();
			}
			if(mMap[i][j] == -2)
			{
				mMonster.SetPosition( { j*SCALED_W, i*SCALED_H } );
				mMonster.Draw();
			}
		}
	}


}


