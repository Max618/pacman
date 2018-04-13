all: Providers.o Models.o Main.o
	g++ Providers.o Models.o Main.o -o Pacman.exe

Providers.o: AllegroImageProvider.o AllegroProvider.o
	g++ AllegroImageProvider.o AllegroProvider.o

Models.o: Wall.o
	g++ Wall.o

Main.o: Main.cpp
	g++ -c Main.cpp

AllegroProvider.o: ./Providers/AllegroProvider/AllegroProvider.h ./Providers/AllegroProvider/AllegroProvider.cpp
	g++ -c ./Providers/AllegroProvider/AllegroProvider.cpp

AllegroImageProvider.o: ./Providers/AllegroImageProvider/AllegroImageProvider.h ./Providers/AllegroImageProvider/AllegroImageProvider.cpp
	g++ -c ./Providers/AllegroImageProvider/AllegroImageProvider.cpp

Wall.o: ./App/Wall/Wall.h ./App/Wall/Wall.cpp
	g++ -c ./App/Wall/Wall.cpp

clean:
	rm *.o
	rm Pacman.exe 