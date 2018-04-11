#ifndef WALL_H
#define WALL_H
class Wall {
/*----------------- File: Wall.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por “Gabriel Maximiniano" em 11/04/2018|
+-----------------------------------------------------+ */
	private:
		char color[7];
		float width, height, position_x, position_y;
	public:
		void setColor(char[]);
		char* getColor();
		void setWidth(float);
		float getWidth();
		void setHeight(float);
		float getHeight();
		void setPositionX(float);
		float getPositionX();
		void setPositionY(float);
		float getPositionY();
};
#endif