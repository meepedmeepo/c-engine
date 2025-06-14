#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <cstddef>
#include <memory>
#include "rendering/renderer.h"


std::shared_ptr<Renderer> init(){

    if( SDL_Init(SDL_INIT_VIDEO) == false){
        SDL_Log("SDL Couldn't initialise. SDL Error: %s\n ", SDL_GetError());
        return nullptr;
    }else{
        return std::make_shared<Renderer>();
    }
 }

int main(int argc, char* args[]){
    bool quit = false;

    std::shared_ptr<Renderer> rend = init();

    if(rend != nullptr){
        while(!quit)
        {
            //main loop
        }
    }

     SDL_Quit();
}
