#pragma once
#include "../includes.h"

class BasicObject
{
public:
	BasicObject();
	~BasicObject();

	void SetTexture( SDL_Texture* _texture ) { if(mEntity.texture != nullptr) SDL_DestroyTexture( mEntity.texture ); mEntity.texture = _texture; }
	void SetPosition( SDL_Point _position ) { mEntity.rectOnScreen.x = _position.x; mEntity.rectOnScreen.y = _position.y; }
	void SetSizeFromTexture() { 
		SDL_QueryTexture( mEntity.texture, NULL, NULL, &mEntity.rectOnTexture.w, &mEntity.rectOnTexture.h );
		mEntity.rectOnScreen.w = mEntity.rectOnTexture.w; mEntity.rectOnScreen.h = mEntity.rectOnTexture.h; }

	void Draw();

protected:
	Entity mEntity;
};

