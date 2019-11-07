message("CMAKE_SYSTEM_NAME : ${CMAKE_SYSTEM_NAME}")
if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
	message("COMPILE FOR WINDOWS")	
	set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/)
	find_package(SDL2 REQUIRED)
	INCLUDE(FindPkgConfig)
	pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
else() 
	message("COMPILE FOR LINUX")	
	find_package(SDL2 REQUIRED sdl2)
	INCLUDE(FindPkgConfig)
	pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
endif()

message("CMAKE_FIND_ROOT_PATH : ${CMAKE_FIND_ROOT_PATH}")

include_directories(${CMAKE_SOURCE_DIR}/include)

message("SDL2_LIBRARY : ${SDL2_LIBRARY}") 
message("SDL2_LIBRARIES : ${SDL2_LIBRARIES}") 
message("SDL2_TTF_LIBRARY : ${SDL2_TTF_LIBRARY}") 
message("SDL2_TTF_LIBRARIES : ${SDL2_TTF_LIBRARIES}") 

message("SDL2_INCLUDE_DIRS : ${SDL2_INCLUDE_DIRS}") 
message("SDL2_TTF_INCLUDE_DIRS : ${SDL2_TTF_INCLUDE_DIRS}") 

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
	link_directories(SNAKE ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/lib)
	target_link_libraries(SNAKE ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})
	file(COPY ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/bin/SDL2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
	file(COPY ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/bin/SDL2_image.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
	file(COPY ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/bin/SDL2_ttf.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
	file(COPY ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/bin/libfreetype-6.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
else()
	message("Linking for FOR Linux")	
	target_include_directories(SNAKE PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2_TFF_INCLUDE_DIRS})
	target_link_libraries(SNAKE ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})
endif()
message("output dir : ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
file(COPY ${CMAKE_SOURCE_DIR}/fonts/BebasNeue-Regular.ttf DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
