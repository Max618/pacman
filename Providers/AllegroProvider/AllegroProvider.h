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
   		ALLEGRO_BITMAP  *image; //Imagem
	public:
		AllegroProvider();
		void setDisplay(int,int);
		ALLEGRO_DISPLAY* loadDisplay();
		void setImg(char*);
		ALLEGRO_BITMAP* getImg();
		void setBackgroundColor(int, int, int);
		void destroyDisplay();
		void destroyImage();
};
#endif