#ifndef SMARTGHOST_H
#define SMARTGHOST_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include "../Ghost/Ghost.h"
class SmartGhost : public Ghost {
/*--------------- File: SmartGhost.h ----------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por "Gabriel Maximiniano" em 08/06/2018|
+-----------------------------------------------------+ */
	private:
		
	public:

		virtual void move(int);

		SmartGhost();
		~SmartGhost();
};
#endif