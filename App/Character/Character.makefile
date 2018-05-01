all: Character.o Main.o
	g++ Character.o Main.o -o Character.exe
Wall.o: Character.h
	g++ -c Character.cpp
Main.o: Character.h Main.cpp
	g++ -c Main.cpp
clean:
	rm *.o
	rm Character.exe 