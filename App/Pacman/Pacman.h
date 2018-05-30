#ifndef PACMAN_H
#define PACMAN_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include "../Character/Character.h"
class Pacman : public Character {
/*----------------- File: Pacman.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por "Gabriel Maximiniano" em 30/05/2018|
+-----------------------------------------------------+ */
	private:
		ALLEGRO_EVENT event;
	public:

		void waitEvent(ALLEGRO_EVENT_QUEUE*);
		bool eventKeyDown();
		bool eventKeyUp();
		bool eventCloseDisplay();
		bool eventEscape();
		bool eventTimer();
		ALLEGRO_EVENT getEvent();

		virtual void move(int);

		Pacman();
		~Pacman();
};
#endif