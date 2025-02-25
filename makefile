CC = clang++

all:
	$(CC) -std=c++20 -Iinclude main.cpp source/*.cpp -o prog.out
