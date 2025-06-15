#ifndef RENDERER_H
#define RENDERER_H
#include "SDL3/SDL.h"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>
#include "sprite.h"

class Renderer{
    public:
    Renderer();
    ~Renderer() {
        SDL_DestroyRenderer(mRenderer);
        SDL_DestroyWindow(mWindow);

        mRenderer = NULL;
        mWindow = NULL;
    }


    void update();

    void renderSprite(Sprite* sprite, float x, float y);

    SDL_Renderer* getRenderer(){
        return mRenderer;
    }

    void setColor(SDL_Color* col){
        SDL_SetRenderDrawColor(mRenderer, col->r, col->g, col->b, col->a);
    }

    void clear(){
        setColor(&mRendererClearColor);
        SDL_RenderClear(mRenderer);
    }

    private:
    SDL_Renderer* mRenderer;
    SDL_Window* mWindow;
    SDL_Color mRendererClearColor;

};


#endif
