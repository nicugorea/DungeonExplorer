#include "Player.h"
#include "../core/InputManager.h"
#include "../core/ResourceManager.h"


Player::Player()
{
	mEntity.rectOnScreen = STD_RECT;
	mEntity.rectOnScreen.w = STD_W;
	mEntity.rectOnScreen.h = STD_H;
	mEntity.rectOnTexture = STD_RECT;
	mEntity.texture = ResourceManager::GetTextureFromFile( "res/img/player.png" );
	mCenter.x = mEntity.rectOnScreen.x + mEntity.rectOnScreen.w / 2;
	mCenter.y = mEntity.rectOnScreen.y + mEntity.rectOnScreen.h / 2;
}


Player::~Player()
{
}

void Player::EventHandle()
{
	if(InputManager::IsKeyDown( SDL_SCANCODE_RIGHT ))
		mAngle += 90;
	if(InputManager::IsKeyDown( SDL_SCANCODE_LEFT ))
		mAngle -= 90;

	if(mAngle > 360) mAngle -= 360;
	if(mAngle < -360) mAngle += 360;

	if(InputManager::IsKeyDown( SDL_SCANCODE_UP ))
		if(mAngle == 0)
			mEntity.rectOnScreen.y -= STD_H;
		else if(mAngle == 180 || mAngle == -180)
			mEntity.rectOnScreen.y += STD_W;
		else if(mAngle == 270 || mAngle == -90)
			mEntity.rectOnScreen.x -= STD_W;
		else if(mAngle == 90 || mAngle == -270)
			mEntity.rectOnScreen.x += STD_H;


	SDL_Delay( 150 );
}

void Player::SetPosition( SDL_Point _point )
{
	mEntity.rectOnScreen.x = _point.x*STD_W;
	mEntity.rectOnScreen.y = _point.y*STD_H;

}


void Player::Draw()
{
	ResourceManager::DrawEntityEx( mEntity, mAngle, mCenter, mFlip );
}
