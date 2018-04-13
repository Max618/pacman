#ifndef ALLEGROIMAGEPROVIDER_H
#define ALLEGROIMAGEPROVIDER_H
class AllegroImageProvider {
/*----------------- File: AllegroImageProvider.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por “Gabriel Maximiniano" em 13/04/2018|
+-----------------------------------------------------+ */
	private:
		ALLEGRO_BITMAP* image;
		int position_x, position_y;
	public:
		AllegroImageProvider();
		~AllegroImageProvider();
		void setImage(char*,int, int);
		void loadImage();
		void destroyImage();
};
#endif