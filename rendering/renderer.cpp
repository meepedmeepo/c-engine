#include "renderer.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <cstddef>
#include "SDL3_image/SDL_image.h"

Renderer::Renderer(){
    mWindow = NULL;
    mRenderer = NULL;

    if(SDL_CreateWindowAndRenderer("C_Engine", 600, 400, SDL_WINDOW_VULKAN, &mWindow, &mRenderer) == false){
        SDL_Log("Couldn't create window. SDL_Error: %s \n", SDL_GetError());
        throw "SDL_FUCKING_DIED";
    }

    SDL_SetRenderVSync(mRenderer, 1);
    
    mRendererClearColor = {0xFF, 0x0, 0x0, 0xFF};

}

//TODO: possibly make private to not allow for multiple calls to this per frame idk
void Renderer::update(){
    SDL_RenderPresent(mRenderer);
}

void Renderer::renderSprite(Sprite* sprite, float x, float y){
    std::tuple<float, float> spriteDimensions = sprite->getDimensions();
    SDL_FRect dstrect = SDL_FRect{x, y, std::get<0>(spriteDimensions), std::get<1>(spriteDimensions)};

    SDL_RenderTexture(mRenderer, sprite->getTexture(), sprite->getClip(), &dstrect);
}
