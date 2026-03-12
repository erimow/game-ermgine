#include "../Engine/Core/engine.h"
#include "../Engine/Core/render.h"
#include "../Engine/Other/scenemanager.h"
#include "editor.c"

typedef enum scenes{
EDITOR,
MENU,
PLAY
} scenes;

static SceneManager scenemanager;

static void game_start(Engine *engine){
    SceneManager_init(&scenemanager, 1);
    SceneManager_addScene(&scenemanager, EDITOR, editor_start, editor_update, editor_handle_input, editor_render, editor_stop);
    SceneManager_switchScene(&scenemanager, EDITOR, engine);

    // SceneManager_currentScene_Start(&scenemanager, engine);
}

static void game_loop(Engine *engine){
    while (engine->running){
        SDL_Event e;
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_EVENT_QUIT){ //change to swtich statement
                engine->running = false;
            }

            SceneManager_currentScene_HandleEvents(&scenemanager, engine, &e);
        }
        SceneManager_currentScene_Update(&scenemanager, engine);

        render_set_draw_color(engine->renderer, 99, 200,120,255);
        render_clear(engine->renderer);
        render_present(engine->renderer);
        SceneManager_currentScene_Render(&scenemanager, engine);
    }
}

static void game_stop(Engine *engine){
    SceneManager_currentScene_Stop(&scenemanager, engine);
    SceneManager_deinit(&scenemanager);
}