CC = g++
FLAGS = -std=c++14 -Wall -g

all: hw12

hw12: hw12.cpp
	$(CC) $(FLAGS) hw12.cpp -o hw12
	
clean:
	rm *.o hw12 hw12.tar hw12.scr

tar:
	tar cf hw12.tar queue.h arrayQueue.h  hw12.scr makefile hw12.cpp


