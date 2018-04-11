all: Wall.o Main.o
	g++ Wall.o Main.o -o Wall.exe
Wall.o: Wall.h
	g++ -c Wall.cpp
Main.o: Wall.h Main.cpp
	g++ -c Main.cpp
clean:
	rm *.o
	rm Wall.exe 