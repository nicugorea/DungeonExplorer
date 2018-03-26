#pragma once
#include "../includes.h"

class BasicObject
{
public:
	BasicObject();
	~BasicObject();

	void SetTexture( SDL_Texture* _texture ) { mEntity.texture = _texture; }
	void SetPosition( SDL_Point _position ) { mEntity.rectOnScreen.x = _position.x; mEntity.rectOnScreen.y = _position.y;}
	
	void Draw();

protected:
	Entity mEntity;
};

