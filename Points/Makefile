run:
	./main

main: main.o Point.o Forme.o PointColor.o
	g++ -Wall main.o Point.o Forme.o PointColor.o -o main

main.o: main.cpp Point.h Forme.h PointColor.h
	g++ -Wall -c main.cpp Point.h Forme.h PointColor.h

Point.o: Point.cpp Point.h
	g++ -Wall -c Point.cpp Point.h

PointColor.o: PointColor.cpp PointColor.h Point.h
	g++ -Wall -c PointColor.cpp PointColor.h Point.h

Forme.o: Forme.cpp Forme.h Point.h
	g++ -Wall -c Forme.cpp Forme.h Point.h

clean:
	rm -f *.o *.gch main
