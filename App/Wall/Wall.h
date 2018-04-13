#ifndef WALL_H
#define WALL_H
#include "../../Providers/AllegroProvider/AllegroProvider.h"
class Wall : public AllegroProvider {
/*----------------- File: Wall.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por “Gabriel Maximiniano" em 11/04/2018|
+-----------------------------------------------------+ */
	private:
		char imageName[50];
		float position_x, position_y;
	public:
		void setImageName(char[]);
		char* getImageName();
		void setWidth(float);
		float getWidth();
		void setHeight(float);
		float getHeight();
		void setPositionX(float);
		float getPositionX();
		void setPositionY(float);
		float getPositionY();

		Wall();
		~Wall();
};
#endif