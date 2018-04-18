all: Coin.o Main.o
	g++ Coin.o Main.o -o Coin.exe
Wall.o: Coin.h
	g++ -c Coin.cpp
Main.o: Coin.h Main.cpp
	g++ -c Main.cpp
clean:
	rm *.o
	rm Coin.exe 