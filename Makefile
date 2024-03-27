# Detect the operating system
UNAME_S := $(shell uname -s)

# Define the compiler
CXX = g++

# Define compile-time flags
CXXFLAGS = -std=c++17 -Wall

# Define the name of the executable
ifeq ($(UNAME_S),Windows_NT)
    TARGET = game.exe
else
    TARGET = game
endif

# Automatically find all cpp files in the current directory
SOURCES = $(wildcard *.cpp)

# Define object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link the target with all objects
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each cpp file to an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up the build
clean:
ifeq ($(UNAME_S),Windows_NT)
	del /f $(TARGET) $(OBJECTS)
else
	rm -f $(TARGET) $(OBJECTS)
endif

.PHONY: all clean
