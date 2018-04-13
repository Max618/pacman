#ifndef ALLEGROIMAGEPROVIDER_H
#define ALLEGROIMAGEPROVIDER_H
class AllegroImageProvider {
/*----------------- File: Wall.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por “Gabriel Maximiniano" em 13/04/2018|
+-----------------------------------------------------+ */
	private:
		char *image;
		int position_x, position_y;
	public:
		AllegroImageProvider();
		void setImage(char*,int, int);
		void loadImage();
};
#endif