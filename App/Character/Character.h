#ifndef CHARACTER_H
#define CHARACTER_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
class Character {
/*----------------- File: Character.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por "Matheus Candido" em 30/04/2018|
+-----------------------------------------------------+ */
	private:
		ALLEGRO_BITMAP* imageName[2];
		int position_x, position_y;
		int beforeD, direction;
		
		
	public:
		void destroyImage();
		void setPositions(int, int);
		int getPositionX();
		int getPositionY();
		void setPositionX(int);
		void setPositionY(int);
		void loadImage(int);
		void setImages(char*, char*);

		void setBeforeD(int);
		int getBeforeD();

		void setDirection(int);
		int getDirection();

		virtual void move(int[][32]) = 0;

		Character();
		virtual ~Character();
};
#endif