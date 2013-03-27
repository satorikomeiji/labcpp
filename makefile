CC=g++
all: test1

test1: list.o main.o
	$(CC) list.o main.o -o test1 -lboost_unit_test_framework
main.o: test1.cpp 
	$(CC) -c test1.cpp -o main.o
list.o: list.cpp
	$(CC) -c list.cpp -o list.o
clean:
	rm -rf *.o test1
