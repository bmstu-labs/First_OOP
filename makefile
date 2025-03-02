CXX := clang++
CXXFLAGS := -Wall -Iinclude -std=c++20
TARGET := prog.out

SRC := \
	main.cpp \
    source/commands.cpp \
    source/context.cpp \
    source/dot.cpp \
    source/menu.cpp \
    source/shape_allocators.cpp \
    source/shapes/circle.cpp \
    source/shapes/rectangle.cpp \
    source/shapes/shape.cpp \
    source/shapes/triangle.cpp \
    source/exceptions/input_error.cpp

OBJ := $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $^ -o $@ && rm -f $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: clean