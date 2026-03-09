cmake_minimum_required(VERSION 3.20)

project(GameEngine C)

set(CMAKE_C_STANDARD 11)

# Find SDL libraries installed on system
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf REQUIRED)
find_package(SDL3_mixer REQUIRED)

# Collect source files
file(GLOB_RECURSE ENGINE_SRC
    Engine/*.c
)

file(GLOB_RECURSE SCRIPT_SRC
    Scripts/*.c
)

# Create executable
add_executable(game
    main.c
    ${ENGINE_SRC}
    ${SCRIPT_SRC}
)

# Include directories
target_include_directories(game PRIVATE
    Engine
    Scripts
)

# Link SDL libraries
target_link_libraries(game PRIVATE
    SDL3::SDL3
    SDL3_image::SDL3_image
    SDL3_ttf::SDL3_ttf
    SDL3_mixer::SDL3_mixer
)

# Copy asset folders to build directory
file(COPY Art DESTINATION ${CMAKE_BINARY_DIR})
file(COPY Fonts DESTINATION ${CMAKE_BINARY_DIR})