CC = clang++

all:
	$(CC) -std=c++20 -Iinclude main.cpp source/shapes.cpp -o prog.out
