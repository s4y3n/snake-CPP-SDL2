message("CMAKE_SYSTEM_NAME : ${CMAKE_SYSTEM_NAME}")

add_executable(SNAKE 
	body.cpp
	cell.cpp
	cell_SDL.cpp
	cible.cpp
	functions.cpp
	game.cpp
	head.cpp
	eye.cpp
	main.cpp
	snake.cpp
	welcome.cpp
	text.cpp
	button.cpp
	score.cpp
)

if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
	message("COMPILE FOR WINDOWS")	
#	set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/)

#	set(SDL_LOCATION ${CMAKE_SOURCE_DIR}/../SDL2)
#	add_subdirectory(${SDL_LOCATION} EXCLUDE_FROM_ALL)
	set(SDL2_LIBRARY SDL2)
	set(SDL2MAIN_LIBRARY SDL2main)
	set(SDL2_TTF_LIBRARY SDL2_ttf)
#	add_library(SDL2 SHARED IMPORTED GLOBAL)
#	set_target_properties(SDL2 PROPERTIES IMPORTED_LOCATION ${SDL_LOCATION}/SDL2/lib/libSDL2.a)
#	add_library(SDL2_image SHARED IMPORTED GLOBAL)
#	set_target_properties(SDL2_image PROPERTIES IMPORTED_LOCATION ${SDL_LOCATION}/SDL2/lib/libSDL2_image.a)
#	add_library(SDL2_ttf SHARED IMPORTED GLOBAL)	
#	set_target_properties(SDL2_ttf PROPERTIES IMPORTED_LOCATION ${SDL_LOCATION}/SDL2/lib/libSDL2_ttf.a)
	message("SDL2 ${SDL2}")
#	include_directories(${SDL_LOCATION}/SDL2/include)
	
	# WORKING 
	#find_package(SDL2 REQUIRED)
	#INCLUDE(FindPkgConfig)
	#pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
else() 
	message("COMPILE FOR LINUX")	
	set(SDL2_LIBRARY SDL2)
	set(SDL2MAIN_LIBRARY SDL2main)
	set(SDL2_TTF_LIBRARY SDL2_ttf)
	
	
#	find_package(SDL2 REQUIRED sdl2)
#	INCLUDE(FindPkgConfig)
#	pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
#	target_include_directories(SNAKE PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2_TFF_INCLUDE_DIRS})
endif()

message("CMAKE_FIND_ROOT_PATH : ${CMAKE_FIND_ROOT_PATH}")

include_directories(${CMAKE_SOURCE_DIR}/include)

message("SDL2_LIBRARY_FOUND : ${SDL2_FOUND}")
message("SDL2_LIBRARY : ${SDL2_LIBRARY}") 
message("SDL2_LIBRARIES : ${SDL2_LIBRARIES}") 
message("SDL2_TTF_LIBRARY : ${SDL2_TTF_LIBRARY}") 
message("SDL2_TTF_LIBRARIES : ${SDL2_TTF_LIBRARIES}") 

message("SDL2_INCLUDE_DIRS : ${SDL2_INCLUDE_DIRS}") 
message("SDL2_TTF_INCLUDE_DIRS : ${SDL2_TTF_INCLUDE_DIRS}") 



if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
	message("Linking for FOR WINDOWS")	
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32")
	target_link_libraries(SNAKE ${SDL2MAIN_LIBRARY} ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY})
	# WORKING FINE
#	link_directories(SNAKE ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/lib)
#	target_link_libraries(SNAKE ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})
	file(COPY ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/bin/SDL2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
	file(COPY ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/bin/SDL2_image.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
	file(COPY ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/bin/SDL2_ttf.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
	file(COPY ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/bin/libfreetype-6.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
else()
	message("Linking for FOR Linux")	
	
	target_include_directories(SNAKE PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2_TFF_INCLUDE_DIRS})
	target_link_libraries(SNAKE ${SDL2MAIN_LIBRARY} ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY})
	#WORKING 
#	target_include_directories(SNAKE PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2_TFF_INCLUDE_DIRS})
	#target_link_libraries(SNAKE ${SDL2_LIBRARIES} ${SDL2MAIN_LIBRARY} ${SDL2_TTF_LIBRARIES})
endif()
message("output dir : ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
file(COPY ${CMAKE_SOURCE_DIR}/fonts/BebasNeue-Regular.ttf DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
