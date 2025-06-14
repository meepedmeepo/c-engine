#ifndef RENDERER_H
#define RENDERER_H
#include "SDL3/SDL.h"
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>

class Renderer{
    public:
    Renderer();
    ~Renderer() {
        SDL_DestroyRenderer(mRenderer);
        mScreenSurface = nullptr;
        SDL_DestroyWindow(mWindow);

        mRenderer = NULL;
        mWindow = NULL;
    }
    void present();


    private:
    SDL_Renderer* mRenderer;
    SDL_Surface* mScreenSurface;
    SDL_Window* mWindow;

};


#endif
