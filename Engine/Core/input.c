#include "input.h"



void input_handle_events(Engine *engine){
    SDL_Event e;
    while (SDL_PollEvent(&e)){
        if (e.type == SDL_EVENT_QUIT){ //change to swtich statement
            engine->running = false;
            }
        else if(e.type == SDL_EVENT_KEY_DOWN){
            input_get_key_down(e.key);
        }
        // if (im->input != '\0'){
            
        // }
    }
}

bool input_get_key_down(SDL_KeyboardEvent key){
    printf("Key pressed %d\n", key.key);
    // if (key.key == SDLK_G){
        
    // }
    return true;
}