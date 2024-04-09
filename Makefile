# Detect the operating system
UNAME_S := $(shell uname -s)

# Define the compiler
CXX = g++

# Define base compile-time flags
CXXFLAGS = -std=c++17 -Wall

# ncurses-specific files
NCURSES_FILES = Login.cpp main.cpp
NCURSES_OBJECTS = $(NCURSES_FILES:.cpp=.o)

# Define the name of the executable
ifeq ($(UNAME_S),Windows_NT)
    TARGET = game.exe
else
    TARGET = game
endif

# Automatically find all cpp files in the current directory, excluding ncurses-specific files
SOURCES = $(filter-out $(NCURSES_FILES), $(wildcard *.cpp))

# Define object files for regular compilation
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link the target with all objects
$(TARGET): $(OBJECTS) $(NCURSES_OBJECTS)
    $(CXX) $(CXXFLAGS) -o $@ $^ -lncurses -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
# Compile each cpp file to an object file
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $<

# Compile ncurses-specific cpp files to object files with -lncurses
$(NCURSES_OBJECTS): %.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -lncurses

# Clean up the build
clean:
ifeq ($(UNAME_S),Windows_NT)
    del /f $(TARGET) $(OBJECTS) $(NCURSES_OBJECTS)
else
    rm -f $(TARGET) $(OBJECTS) $(NCURSES_OBJECTS)
endif

.PHONY: all clean
# Detect the operating system
UNAME_S := $(shell uname -s)

# Define the compiler
CXX = g++

# Define base compile-time flags
CXXFLAGS = -std=c++17 -Wall

# ncurses-specific files
NCURSES_FILES = Login.cpp main.cpp
NCURSES_OBJECTS = $(NCURSES_FILES:.cpp=.o)

# Define the name of the executable
ifeq ($(UNAME_S),Windows_NT)
    TARGET = game.exe
else
    TARGET = game
endif

# Automatically find all cpp files in the current directory, excluding ncurses-specific files
SOURCES = $(filter-out $(NCURSES_FILES), $(wildcard *.cpp))

# Define object files for regular compilation
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link the target with all objects
$(TARGET): $(OBJECTS) $(NCURSES_OBJECTS)
    $(CXX) $(CXXFLAGS) -o $@ $^ -lncurses -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
# Compile each cpp file to an object file
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $<

# Compile ncurses-specific cpp files to object files with -lncurses
$(NCURSES_OBJECTS): %.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -lncurses

# Clean up the build
clean:
ifeq ($(UNAME_S),Windows_NT)
    del /f $(TARGET) $(OBJECTS) $(NCURSES_OBJECTS)
else
    rm -f $(TARGET) $(OBJECTS) $(NCURSES_OBJECTS)
endif

.PHONY: all clean
