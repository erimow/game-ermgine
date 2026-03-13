#include "../Engine/Core/render.h"
#include "../Engine/Core/engine.h"
#include "../Engine/Other/camera.h"
#include "mouseinfo.h"



static Camera cam;
static float camPosXOnClick=0, camPosYOnClick=0;
static MouseInfo mouseinfo;

static void editor_start(Engine *engine){
    printf("In Editor start\n");
    camera_init(&cam);
    mouseinfo_init(&mouseinfo);
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
    
}

static void editor_stop(){
    printf("Stopping edtor scene\n");
}