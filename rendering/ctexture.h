#ifndef CTEXTURE_H
#define CTEXTURE_H
#include "SDL3/SDL.h"
class CTexture {
    public:
    static constexpr float kOriginalSize = -1.0f;

    CTexture();
    ~CTexture();

    private:
    SDL_Texture* mTexture;

    int mWidth;
    int mHeight;
};

#endif
