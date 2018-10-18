all: main run

run:
	./main

main: main.o Cstring.o Definition.o
	g++ -Wall main.o Cstring.o Definition.o -o main

Cstring.o: Cstring.cpp Cstring.h
	g++ -c -Wall Cstring.cpp Cstring.h

Definition.o: Definition.cpp Definition.h
	g++ -c -Wall Definition.cpp Definition.h Cstring.h

main.o: main.cpp Cstring.h Definition.h
	g++ -c -Wall main.cpp Cstring.h Definition.h

clean:
	rm -f *.o *.gch main
