#include "../Engine/Core/render.h"
#include "../Engine/Core/engine.h"
#include "../Engine/Core/texture.h"
#include "../Engine/Other/camera.h"
#include "mouseinfo.h"
#include "editor_overlay.c"



static Camera cam;
static float camPosXOnClick=0, camPosYOnClick=0;
static MouseInfo mouseinfo;
static Texture test;

static void editor_start(Engine *engine){
    printf("In Editor start\n");
    camera_init(&cam);
    mouseinfo_init(&mouseinfo);
    Texture_loadFromFile(&test, engine->renderer, "Art/test.png");
}

static void editor_handle_input(Engine *engine, SDL_Event *e){
    switch(e->type){
        case SDL_EVENT_KEY_DOWN:
            printf("Key pressed in editor\n");
        break;
        case SDL_EVENT_MOUSE_MOTION:
            SDL_GetMouseState(&mouseinfo.xPos, &mouseinfo.yPos);
        break;
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            mouseinfo.isMousePressed=true;
            mouseinfo.xPosOnMousePress=mouseinfo.xPos; mouseinfo.yPosOnMousePress=mouseinfo.yPos;
            camPosXOnClick=cam.x; camPosYOnClick=cam.y;
        break;
        case SDL_EVENT_MOUSE_BUTTON_UP:
            mouseinfo.isMousePressed=false;
        break;
    }
}

static void editor_update(Engine *engine){
    if (mouseinfo.isMousePressed){
        camera_set_position(&cam,camPosXOnClick+mouseinfo.xPosOnMousePress-mouseinfo.xPos, camPosYOnClick+mouseinfo.yPosOnMousePress-mouseinfo.yPos);
    }
    printf("Camera xPos: %f, yPos: %f\n", cam.x, cam.y);
}

static void editor_render(Engine *engine){
    SDL_SetRenderDrawColor(engine->renderer, 200, 0, 0, 255);
    SDL_RenderFillRect(engine->renderer,&(SDL_FRect){
        500-cam.x, 500-cam.y, 30, 30
    });
    Texture_render_with_camera(&test, engine->renderer, &cam, NULL, &(SDL_FRect){800, 1000, 300, 300},0.0,NULL,SDL_FLIP_NONE);
    e_overlay_render(engine); //render editor overlay
}

static void editor_stop(){
    printf("Stopping edtor scene\n");
    Texture_free(&test);
}