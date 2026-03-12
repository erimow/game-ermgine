#include "../Engine/Core/render.h"
#include "../Engine/Core/engine.h"

static void editor_start(Engine *engine){
    printf("In Editor start\n");
}

static void editor_handle_input(Engine *engine, SDL_Event *e){
    switch(e->type){
        case SDL_EVENT_KEY_DOWN:
        break;
        case SDL_EVENT_MOUSE_MOTION:
        break;
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
        break;
        case SDL_EVENT_MOUSE_BUTTON_UP:
        break;
    }
    if (e->type == SDL_EVENT_KEY_DOWN){
        printf("Key pressed in editor\n");
    } else
}

static void editor_update(Engine *engine){

}

static void editor_render(Engine *engine){
    
}

static void editor_stop(){
    printf("Stopping edtor scene\n");
}