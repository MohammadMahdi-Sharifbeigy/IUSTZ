# Detect the operating system
UNAME_S := $(shell uname -s)

# Define the compiler
CXX = g++

# Define compile-time flags
CXXFLAGS = -std=c++17 -Wall

# Include directories for SFML
SFML_INCLUDE = -I/usr/local/include

# SFML libraries
SFML_LIBS = -lsfml-audio -lsfml-system

# Define the name of the executable
ifeq ($(UNAME_S),Windows_NT)
    TARGET = game.exe
    DEBUGTARGET = game_debug.exe
else
    TARGET = game
    DEBUGTARGET = game_debug
endif

# Automatically find all cpp files in the current directory
SOURCES = $(wildcard *.cpp)

# Define object files
OBJECTS = $(SOURCES:.cpp=.o)
DEBUGOBJECTS = $(SOURCES:.cpp=.debug.o)

# Default target
all: $(TARGET)

# Debug target
debug: $(DEBUGTARGET)

# Link the target with all objects and SFML libraries
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

# Link the debug target with all debug objects and SFML libraries
$(DEBUGTARGET): $(DEBUGOBJECTS)
	$(CXX) $(DEBUGFLAGS) -o $@ $^ $(SFML_LIBS)

# Compile each cpp file to an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c $<

# Compile each cpp file to a debug object file
%.debug.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) $(SFML_INCLUDE) -c $< -o $@

# Clean up the build
clean:
ifeq ($(UNAME_S),Windows_NT)
	del /f $(TARGET) $(DEBUGTARGET) $(OBJECTS) $(DEBUGOBJECTS)
else
	rm -f $(TARGET) $(DEBUGTARGET) $(OBJECTS) $(DEBUGOBJECTS)
endif

.PHONY: all clean debug
