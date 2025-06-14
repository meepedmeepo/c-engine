#include "ctexture.h"
#include <SDL3/SDL_render.h>
#include <string>

CTexture::CTexture(){
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
}

CTexture::~CTexture(){
    if(mTexture){
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
    }
}

//TODO: install SDL3_Img and complete this function
bool CTexture::load(int width, int height, std::string path){

    mWidth = width;
    mHeight = height;
    return true;
}
