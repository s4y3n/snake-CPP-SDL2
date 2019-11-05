include_directories(${CMAKE_SOURCE_DIR}/include)
#set(SDL2_PATH "/usr/include/SDL2")
find_package(SDL2 REQUIRED)
#find_file(SDL2_INCLUDE_DIR NAME SDL.h HINTS SDL2)
#message("SDL2_INCLUDE_DIR : ${SDL2_INCLUDE_DIR}")

INCLUDE(FindPkgConfig)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
#find_package(SDL2_ttf REQUIRED)
#find_file(SDL2_TTF_INCLUDE_DIR NAME SDL_ttf.h HINTS SDL2)
#find_library(SDL2_TTF_LIBRARY NAME SDL2_ttf)


add_executable(SNAKE 
	body.cpp
	cell.cpp
	cible.cpp
	functions.cpp
	game.cpp
	head.cpp
	main.cpp
	snake.cpp
)
target_include_directories(SNAKE PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2_TFF_INCLUDE_DIRS})
target_link_libraries(SNAKE ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})
#target_include_directories(SNAKE PUBLIC ${SDL2_ttf_INCLUDE_DIRS})
#target_link_libraries(SNAKE ${SDL2_ttf_LIBRARIES})
