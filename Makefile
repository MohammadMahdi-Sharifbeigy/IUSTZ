# Define the compiler
CXX = g++

# Define compile-time flags
CXXFLAGS = -std=c++17 -Wall

# Define the name of the executable
TARGET = game

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
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
