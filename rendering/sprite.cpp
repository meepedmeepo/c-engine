#include "sprite.h"
#include "ctexture.h"
#include <SDL3/SDL_rect.h>
Sprite::Sprite(CTexture* texture, SDL_FRect* clip){
    mClip = clip;
    mTexture = texture;

    if(mClip){
        mWidth = mClip->w;
        mHeight = mClip->h;
    } else{
        mWidth = texture->getWidth();
        mHeight = texture->getHeight();
    }
}

Sprite::~Sprite(){
    if(mClip)
    delete mClip;
}
