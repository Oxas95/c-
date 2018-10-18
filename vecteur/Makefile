run:
	./main

main: main.o Vecteur.o
	g++ main.o Vecteur.o -o main

main.o: main.cpp Vecteur.h
	g++ -c -Wall main.cpp Vecteur.h

Vecteur.o: Vecteur.cpp Vecteur.h
	g++ -c -Wall Vecteur.cpp Vecteur.h

clean:
	rm -f *.o *.gch main
