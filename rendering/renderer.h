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
        SDL_DestroyRenderer(pRenderer);
        mScreenSurface = nullptr;
        SDL_DestroyWindow(mWindow);

        pRenderer = NULL;
        mWindow = NULL;
    }

    SDL_Surface* mScreenSurface;
    SDL_Window* mWindow;

    private:
    SDL_Renderer* pRenderer;

};


#endif
