#include "Engine/SDL/SDL/include/SDL3/SDL.h"
#include "Engine/Core/engine.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    Engine engine; 
    printf("Testing the new engine.\n"); 
    engine_init(&engine, "game");
    while (engine.running){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if (e.type == SDL_EVENT_QUIT){
                engine.running = false;
            }
        }
    }
    engine_quit(&engine);
}
