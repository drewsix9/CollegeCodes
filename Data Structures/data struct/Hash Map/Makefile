# use Clang to compile

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Source files
SRCS = hashmap.cpp main.cpp linkedlist.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
TARGET = app

# Default target
all: $(TARGET)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files into the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
