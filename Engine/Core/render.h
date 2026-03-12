#ifndef RENDER_H
#define RENDER_H

#include <SDL3/SDL.h>

void render_clear(SDL_Renderer *renderer);
void render_set_draw_color(SDL_Renderer *renderer, uint8_t r, uint8_t g,uint8_t b,uint8_t a);
void render_present(SDL_Renderer *renderer);


#endif