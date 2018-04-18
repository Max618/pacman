all: Moeda.o Main.o
	g++ Moeda.o Main.o -o Moeda.exe
Wall.o: Moeda.h
	g++ -c Moeda.cpp
Main.o: Moeda.h Main.cpp
	g++ -c Main.cpp
clean:
	rm *.o
	rm Moeda.exe 