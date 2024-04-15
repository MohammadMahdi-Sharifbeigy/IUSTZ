# Detect the operating system
UNAME_S := $(shell uname -s)

# Define the compiler
CXX = g++

# Define base compile-time flags
CXXFLAGS := -std=c++17 -Wall $(shell pkg-config --cflags sfml-all)
DEBUGFLAGS = -g -O0 -DDEBUG

# Library flags and libraries
LDFLAGS := $(shell pkg-config --libs sfml-all)

# Define the path to the source files and include the root directory
# Automatically find all cpp files in the project
SOURCES := $(shell find . -name '*.cpp')
OBJECTS := $(SOURCES:.cpp=.o)
DEBUGOBJECTS := $(SOURCES:.cpp=_debug.o)

# Define the name of the executable
ifeq ($(UNAME_S),Windows_NT)
    TARGET = game.exe
    DEBUGTARGET = game_debug.exe
else
    TARGET = game
    DEBUGTARGET = game_debug
endif

# Default target
all: $(TARGET)

# Debug target
debug: $(DEBUGTARGET)

# Link the target with all objects
$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

# Link the debug target with all debug objects
$(DEBUGTARGET): $(DEBUGOBJECTS)
	$(CXX) $(DEBUGFLAGS) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

# Compile each cpp file to an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile debug objects
%_debug.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -c $< -o $@

# Clean up the build
clean:
ifeq ($(UNAME_S),Windows_NT)
	del /f $(TARGET) $(DEBUGTARGET) $(OBJECTS) $(DEBUGOBJECTS)
else
	rm -f $(TARGET) $(DEBUGTARGET) $(OBJECTS) $(DEBUGOBJECTS)
endif

.PHONY: all clean debug