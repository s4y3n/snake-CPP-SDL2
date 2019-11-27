CC = g++
CFLAGS = -Wall -g -std=c++11#-I./src 
LFLAGS = -L/usr/lib/x86_64-linux-gnu 
LIBS = -lSDL2 -lSDL2_ttf -lstdc++  # -lSDL2_image
INCLUDE = -I/usr/include/SDL2 -D_REENTRANT -Iinclude 
SRCDIR = src
INCDIR = include 

OBJDIR := obj
BINDIR := bin

TARGET = snake

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
INCLUDES = $(wildcard $(INCDIR)/*.hpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)


all :
	make $(BINDIR)/$(TARGET) 

$(BINDIR)/$(TARGET): $(OBJECTS)
	mkdir -p $(BINDIR)
	cp fonts/*.ttf $(BINDIR)
	$(CC) $(CGLAGS) $(INCLUDE) $(OBJECTS) $(LFLAGS) $(LIBS) -o $@

$(OBJECTS) : $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "Compiled "$<" successfully" 



clean :
	rm $(OBJECTS)
