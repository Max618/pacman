#ifndef GHOST_H
#define GHOST_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include "../Character/Character.h"
class Ghost : public Character {
/*----------------- File: Ghost.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por "Gabriel Maximiniano" em 30/05/2018|
+-----------------------------------------------------+ */
	private:
		
	public:

		virtual void move(int);

		Ghost();
		~Ghost();
};
#endif