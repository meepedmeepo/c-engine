#ifndef SPRITE_H
#define SPRITE_H
#include "ctexture.h"
#include "SDL3/SDL.h"
#include <SDL3/SDL_rect.h>
#include <cstddef>
#include <tuple>

class Sprite{
    public:
    Sprite(CTexture* texture, SDL_FRect* clip = NULL);
    ~Sprite();

    SDL_FRect* getClip(){
        return mClip;
    }

    SDL_Texture* getTexture(){
        return mTexture->getTexture();
    }

    const std::tuple<float,float> getDimensions(){
        return std::tuple(mWidth, mHeight);
    }

    private:
    SDL_FRect* mClip;
    CTexture* mTexture;
    float mWidth;
    float mHeight;
};

#endif
