#ifndef ALLEGROMAPPROVIDER_H
#define ALLEGROMAPPROVIDER_H
class AllegroMapProvider {
/*----------------- File: Wall.h ---------------------+
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
		AllegroMapProvider();
		void setDisplay(int,int);
		ALLEGRO_DISPLAY* loadDisplay();
		void setImg(char*);
		ALLEGRO_BITMAP* getImg();
		void setBackgroundColor(int, int, int);
		void destroyDisplay();
		void destroyImage();
};
#endif