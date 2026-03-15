#include "engine.h"

int engine_init(Engine *engine, char *title){
bool success = false;
if (!SDL_Init(SDL_INIT_VIDEO)){
    printf("SDL could not init! SDL Error: %s\n", SDL_GetError());
    }
    else {
        if (!SDL_CreateWindowAndRenderer(title, SCREEN_WIDTH, SCREEN_HEIGHT, 0, &engine->window, &engine->renderer)){
            printf("SDL could not create window or renderer: %s\n", SDL_GetError());
        }else{
            if (!SDL_SetRenderDrawBlendMode(engine->renderer,SDL_BLENDMODE_BLEND)){
                printf("SDL could not change render blend mode: %s\n", SDL_GetError());
            }else{
                success = true;
            }
        }
    }
    return success;
}

int engine_quit(Engine *engine){
    SDL_DestroyRenderer(engine->renderer);
    engine->renderer = NULL;
    SDL_DestroyWindow(engine->window);
    engine->window = NULL;
    SDL_Quit();
    printf("Application finished\n");
}