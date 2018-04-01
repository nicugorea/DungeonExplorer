#include "Player.h"
#include "../core/InputManager.h"
#include "../core/ResourceManager.h"


Player::Player()
{
	mEntity.texture = ResourceManager::GetTextureFromFile( "res/img/player.png" );
	mCenter.x = mEntity.rectOnScreen.x + mEntity.rectOnScreen.w / 2;
	mCenter.y = mEntity.rectOnScreen.y + mEntity.rectOnScreen.h / 2;
	mAngle = 0;
}


Player::~Player()
{
}

void Player::EventHandle()
{
	bool moved = true;

	if(InputManager::IsKeyDown( SDL_SCANCODE_RIGHT ))
		mAngle += 90;
	else if(InputManager::IsKeyDown( SDL_SCANCODE_LEFT ))
		mAngle -= 90;
	else if(InputManager::IsKeyDown( SDL_SCANCODE_UP ))
	{
		if(mAngle == 0)
			mEntity.rectOnScreen.y -= SCALED_H;
		else if(mAngle == 90 || mAngle == -270)
			mEntity.rectOnScreen.x += SCALED_H;
		else if(mAngle == 180 || mAngle == -180)
			mEntity.rectOnScreen.y += SCALED_W;
		else if(mAngle == 270 || mAngle == -90)
			mEntity.rectOnScreen.x -= SCALED_W;
	}
	else moved = false;

	if(mAngle == 360) mAngle =0;
	if(mAngle == -360) mAngle =0;

	if(moved) SDL_Delay( SPEED );
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
