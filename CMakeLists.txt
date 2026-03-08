cmake_minimum_required(VERSION 3.20)
project(GameEngine C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(Engine/SDL/SDL)
add_subdirectory(Engine/SDL/SDL_image)
add_subdirectory(Engine/SDL/SDL_ttf)
add_subdirectory(Engine/SDL/SDL_mixer)

file(GLOB_RECURSE ENGINE_SRC Engine/*.c)
file(GLOB_RECURSE GAME_SRC Scripts/*.c)

add_executable(game
    main.c
    ${ENGINE_SRC}
    ${GAME_SRC}
)

target_link_libraries(game PRIVATE
    SDL3::SDL3
    SDL3_image::SDL3_image
    SDL3_ttf::SDL3_ttf
    SDL3_mixer::SDL3_mixer
)