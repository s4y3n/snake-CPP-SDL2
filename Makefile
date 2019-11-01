CC = g++
CFLAGS = -Wall -I./src #-I/usr/include/SDL2 -D_REENTRANT -L/usr/lib/x86_64-linux-gnu -lSDL2
LFLAGS = -L/usr/lib/x86_64-linux-gnu 
LIBS = -lSDL2
INCLUDE = -I/usr/include/SDL2 -D_REENTRANT -Iinclude 
#OBJS = game.o functions.o head.o cell.o main.o
SRCDIR = src
INCDIR = include 
OBJDIR = obj
BINDIR = bin

TARGET = snake

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
INCLUDES = $(wildcard $(INCDIR)/*.hpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)


#all :
#	make snake

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CC) $(CGLAGS) $(INCLUDE) $(OBJECTS) $(LFLAGS) $(LIBS) -o $@

$(OBJECTS) : $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDES) -c $< -o $@
	@echo "Compiled "$<" successfully" 

#functions.o : functions.cpp
#	$(CC) $(CFLAGS) $(INCLUDE) -c functions.cpp

#cell.o : cell.cpp
#	$(CC) $(CFLAGS) $(INCLUDE) -c cell.cpp

#head.o : head.cpp
#	$(CC) $(CFLAGS) $(INCLUDE) -c head.cpp

#game.o : game.cpp
#	$(CC) $(CFLAGS) $(INCLUDE) -c game.cpp

#main.o : main.cpp
#	$(CC) $(CFLAGS) $(INCLUDE) -c main.cpp

#snake : $(OBJS)
#	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(OBJS) $(LFLAGS) $(LIBS)

clean :
	rm $(OBJECTS)
