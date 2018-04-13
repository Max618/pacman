#ifndef ALLEGROPROVIDER_H
#define ALLEGROPROVIDER_H
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
		ALLEGRO_DISPLAY* loadDisplay();
		void setBackgroundColor(int, int, int);
		void destroyDisplay();
};
#endif