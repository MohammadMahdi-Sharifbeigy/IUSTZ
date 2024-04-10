# Detect the operating system
UNAME_S := $(shell uname -s)

# Define the compiler
CXX = g++

# Define base compile-time flags
CXXFLAGS = -std=c++17 -Wall
DEBUGFLAGS = -g -O0 -DDEBUG

# Define the path to the source files
SRC_DIRS := Characters GameLoop Items Reports Fonts

# Automatically find all cpp files in the specified subdirectories
SOURCES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))

# Define the object files based on the source files
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))

# Define the name of the executable
ifeq ($(UNAME_S),Windows_NT)
    TARGET = game.exe
    DEBUGTARGET = game_debug.exe
    # Use Windows-specific find command
    SOURCES += $(shell dir /s /b *.cpp | findstr /v "Login.cpp main.cpp")
else
    TARGET = game
    DEBUGTARGET = game_debug
    # Use Unix-like find command
    SOURCES += $(shell find . -name '*.cpp' ! -name 'Login.cpp' ! -name 'main.cpp')
endif

# ncurses-specific files
NCURSES_FILES := GameLoop/Login.cpp
NCURSES_OBJECTS := $(NCURSES_FILES:.cpp=.o)

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
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile ncurses-specific cpp files to object files
$(NCURSES_OBJECTS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the build
clean:
ifeq ($(UNAME_S),Windows_NT)
	del /f $(TARGET) $(DEBUGTARGET) $(OBJECTS) $(DEBUGOBJECTS) $(NCURSES_OBJECTS)
else
	rm -f $(TARGET) $(DEBUGTARGET) $(OBJECTS) $(DEBUGOBJECTS) $(NCURSES_OBJECTS)
endif

.PHONY: all clean debug
