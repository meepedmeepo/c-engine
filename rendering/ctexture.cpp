#include "ctexture.h"
#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>
#include <string>

CTexture::CTexture(){
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
}

CTexture::~CTexture(){
    this->Destroy();
}

void CTexture::Destroy(){
    if(mTexture){
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
    }
}

//TODO: install SDL3_Img and complete this function
bool CTexture::load(SDL_Renderer* renderer, int width, int height, const char* path){

    mWidth = width;
    mHeight = height;
    mTexture = IMG_LoadTexture(renderer, path);
    return true;
}
