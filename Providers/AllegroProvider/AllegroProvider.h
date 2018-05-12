#ifndef ALLEGROPROVIDER_H
#define ALLEGROPROVIDER_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
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
		ALLEGRO_BITMAP  *image;
		char* getPublic(char*);
		ALLEGRO_EVENT_QUEUE *events;
		ALLEGRO_FONT *font;
		ALLEGRO_TIMER *timer;
	public:
		AllegroProvider();
		~AllegroProvider();
		void setDisplay(int,int);
		void loadDisplay();
		void setBackgroundColor(int, int, int);
		void destroyDisplay();
		void loadImage(char*);

		void setEvents();
		ALLEGRO_EVENT_QUEUE* getEvents();

		void loadFont();
		void writeScore(int);

		bool checkEvents();
		void setFPS(int);
};
#endif