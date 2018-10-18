all: main run

run:
	./main

main: main.o Cstring.o
	g++ -Wall main.o Cstring.o -o main

Cstring.o: Cstring.cpp Cstring.h
	g++ -c -Wall Cstring.cpp Cstring.h

main.o: main.cpp
	g++ -c -Wall main.cpp Cstring.h

clean:
	rm -f *.o *.gch main
