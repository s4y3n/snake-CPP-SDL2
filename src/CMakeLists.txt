message("CMAKE_SYSTEM_NAME : ${CMAKE_SYSTEM_NAME}")

set(CMAKE_CXX_STANDARD 11)

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
	score.cpp
	window.cpp
	button.cpp
	configuration.cpp
	bestscores.cpp
	newGame.cpp
	configure.cpp
	pallette.cpp
	bgcolor.cpp
)

if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
	message("COMPILE FOR WINDOWS")	
	find_package(SDL2 REQUIRED)
	find_package(SDL2_image REQUIRED)
	find_package(SDL2_ttf REQUIRED)
else() 
	message("COMPILE FOR LINUX")	
	find_package(SDL2 REQUIRED sdl2)
	INCLUDE(FindPkgConfig)
	pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
endif()
include_directories(${CMAKE_SOURCE_DIR}/include)
if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
	message("Linking for FOR WINDOWS")	
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32")
	target_include_directories(SNAKE PRIVATE ${SDL2_INCLUDE_DIRS})
	target_link_libraries(SNAKE ${SDL2_LIBRARIES})
	target_include_directories(SNAKE PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS})
	target_link_libraries(SNAKE ${SDL2_IMAGE_LIBRARIES})
	target_include_directories(SNAKE PRIVATE ${SDL2_TTF_INCLUDE_DIRS})
	target_link_libraries(SNAKE ${SDL2_TTF_LIBRARIES})
	# WORKING FINE
#	file(COPY ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/bin/SDL2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
#	file(COPY ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/bin/SDL2_image.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
#	file(COPY ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/bin/SDL2_ttf.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
#	file(COPY ${CMAKE_SOURCE_DIR}/x86_64-w64-mingw32/bin/libfreetype-6.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
else()
	message("Linking for FOR Linux")	
	#WORKING 
	target_include_directories(SNAKE PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2_TFF_INCLUDE_DIRS})
	target_link_libraries(SNAKE ${SDL2_LIBRARIES} ${SDL2MAIN_LIBRARY} ${SDL2_TTF_LIBRARIES})
endif()
file(COPY ${CMAKE_SOURCE_DIR}/fonts/04B_20__.TTF DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
file(COPY ${CMAKE_SOURCE_DIR}/fonts/BebasNeue-Regular.ttf DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
