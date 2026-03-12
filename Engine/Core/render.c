#include "render.h"

void render_clear(SDL_Renderer *renderer){
    SDL_RenderClear(renderer);
}
void render_set_draw_color(SDL_Renderer *renderer, uint8_t r, uint8_t g,uint8_t b,uint8_t a){
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}
void render_present(SDL_Renderer *renderer){
    SDL_RenderPresent(renderer);
}