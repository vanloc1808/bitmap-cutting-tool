CC = g++

all: Bitmap.o main.o
	$(CC) Bitmap.o main.o -o cutt

Bitmap.o: Bitmap.cpp Bitmap.hpp
	$(CC) -g -c Bitmap.cpp

main.o: Bitmap.hpp main.cpp
	$(CC) -g -c main.cpp
	
clean:
	rm *.o
	rm cutt