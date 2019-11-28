main : Graph.o main.o cubelist.o
	g++ -o main Graph.o main.o cubelist.o
main.o : main.cpp Graph.h
	g++ -g -c main.cpp
Graph.o : Graph.cpp Graph.h cubelist.h trick.h
	g++ -g -c Graph.cpp
cubelist.o : cubelist.cpp cubelist.h
	g++ -g -c cubelist.cpp

clean :
	rm Graph.o main.o cubelist.o main
