# Detect the operating system
UNAME_S := $(shell uname -s)

# Define the compiler
CXX = g++

# Define base compile-time flags
CXXFLAGS = -std=c++17 -Wall
DEBUGFLAGS = -g -O0 -DDEBUG

# ncurses-specific files
NCURSES_FILES = Login.cpp main.cpp
NCURSES_OBJECTS = $(NCURSES_FILES:.cpp=.o)

# Define the name of the executable
ifeq ($(UNAME_S),Windows_NT)
    TARGET = game.exe
    DEBUGTARGET = game_debug.exe
else
    TARGET = game
    DEBUGTARGET = game_debug
endif

# Automatically find all cpp files in the current directory, excluding ncurses-specific files
SOURCES = $(filter-out $(NCURSES_FILES), $(wildcard *.cpp))

# Define object files for regular compilation
OBJECTS = $(SOURCES:.cpp=.o)
DEBUGOBJECTS = $(SOURCES:.cpp=.debug.o)

# Default target
all: $(TARGET)

# Debug target
debug: $(DEBUGTARGET)

# Link the target with all objects
$(TARGET): $(OBJECTS) $(NCURSES_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lncurses -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Link the debug target with all debug objects
$(DEBUGTARGET): $(DEBUGOBJECTS) $(NCURSES_OBJECTS)
	$(CXX) $(DEBUGFLAGS) -o $@ $^ -lncurses -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Compile each cpp file to an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Compile each cpp file to a debug object file
%.debug.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -c $< -o $@

# Compile ncurses-specific cpp files to object files
$(NCURSES_OBJECTS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up the build
clean:
ifeq ($(UNAME_S),Windows_NT)
	del /f $(TARGET) $(DEBUGTARGET) $(OBJECTS) $(DEBUGOBJECTS) $(NCURSES_OBJECTS)
else
	rm -f $(TARGET) $(DEBUGTARGET) $(OBJECTS) $(DEBUGOBJECTS) $(NCURSES_OBJECTS)
endif

.PHONY: all clean debug
