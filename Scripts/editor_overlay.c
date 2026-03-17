#include "../Engine/Core/engine.h"
#include "../Engine/Core/texture.h"

#define ICONS_PER_ROW 2

typedef struct Icon{
    Texture texture;
    bool isSelected;
}Icon;

typedef struct IconList{
    uint16_t iconAmount;
    Icon *selectedIcon;
    Icon icons[];
} IconList;

static IconList iconlist;
static Icon test1;
static Texture test1tex;
static Icon test2;
static Texture test2tex;

static Icon e_overlay_make_icon(Engine *engine, Icon *icon, Texture *tex){
    icon->isSelected=false;
    icon->texture = *tex; //free tex after?
}

static void e_overlay_populate(Engine *engine, IconList *il){
    il->iconAmount = 2;
    Texture_loadFromFile(&test1tex, engine->renderer, "Art/test.png");
    Texture_loadFromFile(&test2tex, engine->renderer, "Art/test.png");
    e_overlay_make_icon(engine, &test1, &test1tex);
    e_overlay_make_icon(engine, &test2, &test2tex);
    il->icons[0]=test1;
    il->icons[1]=test2;

}

static void e_overlay_render(Engine *engine){
    SDL_SetRenderDrawColor(engine->renderer, 50, 50, 50, 100);
   SDL_RenderFillRect(engine->renderer, &(SDL_FRect){
    0, 0, SCREEN_WIDTH/5, SCREEN_HEIGHT
   });
   // ------------------------------------------------ //

    for (int i = 0; i < iconlist.iconAmount;i++){
        
    }
}