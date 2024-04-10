# Detect the operating system
UNAME_S := $(shell uname -s)

# Define the compiler
CXX = g++

# Define compile-time flags
CXXFLAGS = -std=c++17 -Wall
DEBUGFLAGS = -g -O0 -DDEBUG

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

# Link the target with all objects
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Link the debug target with all debug objects
$(DEBUGTARGET): $(DEBUGOBJECTS)
	$(CXX) $(DEBUGFLAGS) -o $@ $^

# Compile each cpp file to an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Compile each cpp file to a debug object file
%.debug.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -c $< -o $@

# Clean up the build
clean:
ifeq ($(UNAME_S),Windows_NT)
	del /f $(TARGET) $(DEBUGTARGET) $(OBJECTS) $(DEBUGOBJECTS)
else
	rm -f $(TARGET) $(DEBUGTARGET) $(OBJECTS) $(DEBUGOBJECTS)
endif

.PHONY: all clean debug
