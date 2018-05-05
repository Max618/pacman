#ifndef ALLEGROPROVIDER_H
#define ALLEGROPROVIDER_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
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
		char* getPublic(char*);
		ALLEGRO_EVENT_QUEUE *events;
	public:
		AllegroProvider();
		void setDisplay(int,int);
		void loadDisplay();
		void setBackgroundColor(int, int, int);
		void destroyDisplay();
		void loadImage(char*);

		void setEvents();
		ALLEGRO_EVENT_QUEUE* getEvents();
};
#endif