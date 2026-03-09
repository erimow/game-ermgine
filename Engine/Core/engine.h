#ifndef ENGINE_H
#define ENGINE_H

#include <SDL3/SDL.h>
#include "constants.h"
#include <stdio.h>

typedef struct Engine {
  SDL_Window *window;
  SDL_Renderer *renderer;
  uint16_t screen_width;
  uint16_t screen_height;

  bool running;
} Engine;



int engine_init(Engine *engine, char *title);
//int engine_
int engine_quit(Engine *engine);

#endif