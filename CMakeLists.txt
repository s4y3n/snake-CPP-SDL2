cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_BUILD_TYPE Release)
project(SNAKE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


set(SDL_LOCATION ${CMAKE_SOURCE_DIR}/SDL2/SDL2)
add_subdirectory(${SDL_LOCATION})
add_subdirectory(src)

