#ifndef INPUT_H
#define INPUT_H
#include <SDL3/SDL.h>
#include "engine.h"
#define KEY(x) SDLK_(x)

typedef struct InputManager{
    char input;
} InputManager;

void input_handle_events(Engine *engine);
bool input_get_key_down(SDL_KeyboardEvent key);

#endif