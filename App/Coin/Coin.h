#ifndef COIN_H
#define COIN_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
class Coin {
/*----------------- File: Coin.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por “Victor Alcantara" em 17/04/2018|
+-----------------------------------------------------+ */
	private:
		ALLEGRO_BITMAP* imageName;
		int position_x, position_y;
	public:
		void destroyImage();
		void setPositions(int, int);
		void loadImage();

		int getPositionX();
		int getPositionY();

		Coin();
		~Coin();
};
#endif