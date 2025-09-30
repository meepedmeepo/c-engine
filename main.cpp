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
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include "ui/main_ui.h"

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

    // Init ImGui
    // TODO! move this to seperate init func
    float main_scale = SDL_GetDisplayContentScale(SDL_GetPrimaryDisplay());
    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::StyleColorsDark();
    ImGuiStyle& style = ImGui::GetStyle();
    style.ScaleAllSizes(main_scale);
    style.FontScaleDpi = main_scale;

    ImGui_ImplSDL3_InitForSDLRenderer( rend->getWindow(), rend->getRenderer());
    ImGui_ImplSDLRenderer3_Init(rend->getRenderer());


    MainCanvas canvas = MainCanvas();
    //CTexture tex = CTexture();

    if(rend != nullptr){
        //main loop
        while(!quit)
        {
            //pump events
            SDL_Event event;
            SDL_zero(event);

            while(SDL_PollEvent(&event)){
                ImGui_ImplSDL3_ProcessEvent(&event);
                if(event.type == SDL_EVENT_QUIT){
                    quit = true;
                }
            }
            //Clear screen for new rendering pass.
            rend->clear();

            //Carry out main drawing for this frame.

            //Start ImGui Frame
            ImGui_ImplSDLRenderer3_NewFrame();
            ImGui_ImplSDL3_NewFrame();
            ImGui::NewFrame();

            canvas.Draw();


            //Apply ui drawing to this frame.
            ImGui::Render();
            ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), rend->getRenderer());
        
            //rendererPresent
            rend->update();
        }
    }
    
    //Cleanup ImGui Ctx
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
    
    SDL_Quit();
}
