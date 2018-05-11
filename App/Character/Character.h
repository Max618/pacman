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
		ALLEGRO_BITMAP* imageName;
		int position_x, position_y;
		ALLEGRO_EVENT event;
		
	public:
		void destroyImage();
		void setPositions(int, int);
		int getPositionX();
		int getPositionY();
		void loadImage();
		void waitEvent(ALLEGRO_EVENT_QUEUE*);
		bool eventKeyDown();
		bool eventKeyUp();
		bool eventCloseDisplay();
		bool eventTimer();
		
		ALLEGRO_EVENT getEvent();

		Character();
		~Character();
};
#endif