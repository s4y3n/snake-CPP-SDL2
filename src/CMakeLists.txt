include_directories(${CMAKE_SOURCE_DIR}/include)
message("CMAKE_SYSTEM_NAME : l${CMAKE_SYSTEM_NAME}l")
if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
	message("COMPILE FOR WINDOWS")	
	set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/lib/SDL2_64/x86_64-w64-mingw32/)
else() 
	message("COMPILE FOR LINUX")	
endif()
find_package(SDL2 REQUIRED)

INCLUDE(FindPkgConfig)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

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

if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
	message("Linking for FOR WINDOWS")	
	target_link_libraries(SNAKE ${CMAKE_SOURCE_DIR}/lib/SDL2_64/x86_64-w64-mingw32/libSDL2.a 
		${CMAKE_SOURCE_DIR}/lib/SDL2_64/x86_64-w64-mingw32/libSDL2_ttf.a
	)
else()
	message("Linking for FOR Linux")	
	target_link_libraries(SNAKE ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})
endif()
