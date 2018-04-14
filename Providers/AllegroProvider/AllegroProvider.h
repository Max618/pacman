#ifndef ALLEGROPROVIDER_H
#define ALLEGROPROVIDER_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
class AllegroProvider {
/*----------------- File: AllegroProvider.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por “Gabriel Maximiniano" em 13/04/2018|
+-----------------------------------------------------+ */
	private:
		int width, height;
		ALLEGRO_DISPLAY *display; //Tela
	public:
		AllegroProvider();
		void setDisplay(int,int);
		void loadDisplay();
		void setBackgroundColor(int, int, int);
		void destroyDisplay();
};
#endif