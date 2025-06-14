#include "renderer.h"
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>

Renderer::Renderer(){

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
