#include <SDL3/SDL.h>
#include "Engine/Core/engine.h"
#include "Engine/Core/render.h"
#include "Engine/Core/input.h"
#include "Scripts/game.c"
#include <stdio.h>

int main(int argc, char *argv[]) {
    Engine engine; 
    engine.running = true;
    // InputManager im;
    // im.input = '\0';
    printf("Testing the new engine.\n"); 
    engine_init(&engine, "game");

    game_start(&engine);
    game_loop(&engine);
    game_stop(&engine);

    engine_quit(&engine);
}
