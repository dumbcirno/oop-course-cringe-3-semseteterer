# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
LDFLAGS = 

# Target executable name
TARGET = main

# Source files
SOURCES = main.cpp string.cpp

# Object files (automatically derived from sources)
OBJECTS = $(SOURCES:.cpp=.o)

# Header files
HEADERS = string.hpp

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compile main.cpp to main.o
main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Compile string.cpp to string.o
string.o: string.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c string.cpp -o string.o

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild everything
rebuild: clean all

# Phony targets (not actual files)
.PHONY: all clean rebuild

