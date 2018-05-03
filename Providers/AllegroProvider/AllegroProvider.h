#ifndef ALLEGROPROVIDER_H
#define ALLEGROPROVIDER_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
class AllegroProvider {
/*----------------- File: AllegroProvider.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por “Gabriel Maximiniano" em 13/04/2018|
+-----------------------------------------------------+ */
	private:
		int width, height, matrix[24][32];
		ALLEGRO_DISPLAY *display; //Tela
		ALLEGRO_EVENT_QUEUE *event_queue; //Fila de Eventos
		ALLEGRO_TIMER *timer; //Timer
		char* getPublic(char*);

		void startEvents();
	public:
		AllegroProvider();
		void setDisplay(int,int);
		void loadDisplay();
		void setBackgroundColor(int, int, int);
		void destroyDisplay();
		void loadImage(char*);
};
#endif