# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++20 -Wall

# Source files
SRCS = $(wildcard */*.cpp)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable names
TARGETS = $(patsubst %.cpp,%,$(SRCS))

# Default target
all: $(TARGETS)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executables
%: %.o
	$(CC) $(CFLAGS) $< -o $@

# Clean up object files and executables
clean:
	rm -f $(OBJS) $(TARGETS) $(wildcard */*:Zone.Identifier)
	