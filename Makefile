link: PriorityQueue PriorityQueueDr.cpp
	g++ -Wall -g -pedantic-errors -o a2 PriorityQueue.o PriorityQueueDr.cpp

PriorityQueue: PriorityQueue.cpp PriorityQueue.h
	g++ -c -Wall -g -pedantic-errors PriorityQueue.cpp

run:
	./a2

clean:
	/bin/rm *.o a2