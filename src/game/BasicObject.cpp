#include "BasicObject.h"
#include "../core/ResourceManager.h"


BasicObject::BasicObject()
{
	mEntity.rectOnScreen = STD_RECT;
	mEntity.rectOnTexture = STD_RECT;
}


BasicObject::~BasicObject()
{
	SDL_DestroyTexture( mEntity.texture );
}

void BasicObject::Draw()
{
	ResourceManager::DrawEntity( mEntity );
}
