#include "../Engine/Core/engine.h"
#include "../Engine/Core/texture.h"

typedef struct Icon{
    Texture texture;
}Icon;

static void e_overlay_render(Engine *engine){
    SDL_SetRenderDrawColor(engine->renderer, 50, 50, 50, 100);
   SDL_RenderFillRect(engine->renderer, &(SDL_FRect){
    0, 0, SCREEN_WIDTH/5, SCREEN_HEIGHT
   });
}