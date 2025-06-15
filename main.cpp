#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_timer.h>
#include <cstddef>
#include <memory>
#include "rendering/ctexture.h"
#include "rendering/renderer.h"

//Creates first Window and Renderer.
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

    //CTexture tex = CTexture();

    if(rend != nullptr){
        //main loop
        while(!quit)
        {
            //pump events
            SDL_Event event;
            SDL_zero(event);

            while(SDL_PollEvent(&event)){
                if(event.type == SDL_EVENT_QUIT){
                    quit = true;
                }
            }
            //clear screen for new rendering pass
            rend->clear();

            //rendererPresent
            rend->update();
            SDL_Delay(50);
        }
    }

     SDL_Quit();
}
