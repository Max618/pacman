#ifndef WALL_H
#define WALL_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
class Wall {
/*----------------- File: Wall.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por “Gabriel Maximiniano" em 11/04/2018|
+-----------------------------------------------------+ */
	private:
		ALLEGRO_BITMAP* imageName;
		int position_x, position_y;
	public:
		void destroyImage();
		void setPositions(int, int);
		void loadImage();

		Wall();
		~Wall();
};
#endif