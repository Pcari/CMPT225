
all: driver

driver: Deque.o driver.o
	g++ -o driver driver.o Deque.o

driver.o: driver.cpp Deque.o Deque.h
	g++ -c driver.cpp

Deque.o: Deque.cpp Deque.h
	g++ -c Deque.cpp

clean: 
	rm -f driver *.o


