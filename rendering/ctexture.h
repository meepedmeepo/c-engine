#ifndef CTEXTURE_H
#define CTEXTURE_H
#include "SDL3/SDL.h"
#include <string>

//RAII Wrapper over SDL_Texture - doesn't handle any rendering as that is the job of sprite
class CTexture {
    public:
    static constexpr float kOriginalSize = -1.0f;

    CTexture();
    ~CTexture();

    bool load(int width, int height, std::string path);

    SDL_Texture* getTexture(){
        return mTexture;
    }

    const int getWidth(){
        return mWidth;
    }

    const int getHeight(){
        return mHeight;
    }

    bool isLoaded(){
        return mTexture != nullptr;
    }

    void Destroy();

    private:
    SDL_Texture* mTexture;

    int mWidth;
    int mHeight;
};

#endif
