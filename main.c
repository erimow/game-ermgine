#include <SDL3/SDL.h>
#include "Engine/Core/engine.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    Engine engine; 
    engine.running = true;
    printf("Testing the new engine.\n"); 
    engine_init(&engine, "game");
    while (engine.running){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if (e.type == SDL_EVENT_QUIT){
                engine.running = false;
            }
        }
        SDL_SetRenderDrawColor(engine.renderer, 100, 200,120,255);
        SDL_RenderClear(engine.renderer);
        SDL_RenderPresent(engine.renderer);
    }
    engine_quit(&engine);
}
