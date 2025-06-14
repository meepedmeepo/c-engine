#include "renderer.h"
#include <SDL3/SDL_render.h>

Renderer::Renderer(){

}

//TODO: possibly make private to not allow for multiple calls to this per frame idk
void Renderer::present(){
    SDL_RenderPresent(mRenderer);
}
