#include "Player.h"
#include "../core/InputManager.h"
#include "../core/ResourceManager.h"
#include "GameMap.h"


Player::Player()
{
	mEntity.texture = ResourceManager::GetTextureFromFile( "res/img/player.png" );
	mCenter.x = mEntity.rectOnScreen.x + mEntity.rectOnScreen.w / 2;
	mCenter.y = mEntity.rectOnScreen.y + mEntity.rectOnScreen.h / 2;
	mAngle = 0;
	mScore = 0;
}


Player::~Player()
{

}

void Player::EventHandle()
{
	bool moved = true;
	bool rotated = true;

	if(InputManager::IsKeyDown( SDL_SCANCODE_RIGHT ))
		mAngle += 90;
	else if(InputManager::IsKeyDown( SDL_SCANCODE_LEFT ))
		mAngle -= 90;
	else rotated = false;

	if(InputManager::IsKeyDown( SDL_SCANCODE_UP ))
	{
		//LOGLN( "POS: " << mEntity.rectOnScreen.x << " " << mEntity.rectOnScreen.y );
		//LOGLN( "POS: " << mMapSize.x*SCALED_W << " " << mMapSize.y*SCALED_H );

		//up
		if(mAngle == 0 && mEntity.rectOnScreen.y > 0)
		{
			if(GameMap::GetMapCell( { mEntity.rectOnScreen.y / SCALED_H - 1,mEntity.rectOnScreen.x / SCALED_W } ) != 1)
				mEntity.rectOnScreen.y -= SCALED_H;
		}
		//right
		else if((mAngle == 90 || mAngle == -270) && mEntity.rectOnScreen.x < mMapSize.x*SCALED_W - SCALED_W)
		{
			if(GameMap::GetMapCell( { mEntity.rectOnScreen.y / SCALED_H ,mEntity.rectOnScreen.x / SCALED_W + 1 } ) != 1)
				mEntity.rectOnScreen.x += SCALED_W;
		}
		//down
		else if((mAngle == 180 || mAngle == -180) && mEntity.rectOnScreen.y < mMapSize.y*SCALED_H - SCALED_H)
		{
			if(GameMap::GetMapCell( { mEntity.rectOnScreen.y / SCALED_H + 1,mEntity.rectOnScreen.x / SCALED_W } ) != 1)
				mEntity.rectOnScreen.y += SCALED_H;
		}
		//left
		else if((mAngle == 270 || mAngle == -90) && mEntity.rectOnScreen.x > 0)
		{
			if(GameMap::GetMapCell( { mEntity.rectOnScreen.y / SCALED_H ,mEntity.rectOnScreen.x / SCALED_W - 1 } ) != 1)
				mEntity.rectOnScreen.x -= SCALED_W;
		}
	}
	else moved = false;

	if(mAngle == 360) mAngle = 0;
	if(mAngle == -360) mAngle = 0;

	if(GameMap::GetMapCell( { mEntity.rectOnScreen.y / SCALED_H, mEntity.rectOnScreen.x / SCALED_W } ) == -2)
	{
		mScore -= 1000;
		GameMap::ClearCell( { mEntity.rectOnScreen.y / SCALED_H, mEntity.rectOnScreen.x / SCALED_W } );
	}
	else if(GameMap::GetMapCell( { mEntity.rectOnScreen.y / SCALED_H, mEntity.rectOnScreen.x / SCALED_W } ) == -1)
	{
		mScore += 500;
		GameMap::ClearCell( { mEntity.rectOnScreen.y / SCALED_H, mEntity.rectOnScreen.x / SCALED_W } );
	}

	if(moved || rotated) SDL_Delay( SPEED );


}

void Player::SetPosition( SDL_Point _point )
{
	mEntity.rectOnScreen.x = _point.x*SCALED_W;
	mEntity.rectOnScreen.y = _point.y*SCALED_H;

}


void Player::Draw()
{
	ResourceManager::DrawEntityEx( mEntity, mAngle, mCenter, mFlip );
}
