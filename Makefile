CC = g++
CFLAGS = -g -Wall -Wextra -I
VER = -std=c++17

lab1All:
	$(CC) $(CFLAGS) $(VER) -o ./Lab01/HelloWorld/helloWorld ./Lab01/HelloWorld/helloWorld.cpp
	./Lab01/HelloWorld/helloWorld
