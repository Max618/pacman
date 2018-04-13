#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include "AllegroImageProvider.h"

using namespace std;

AllegroImageProvider::AllegroImageProvider(){
	this->image = NULL;
	this->position_x = this->position_y = 0;
}

void setImage(char* filename,int x, int y){
	this->image = al_load_bitmap(filename);
	this->position_x = x;
	this->position_y = y;
}

void loadImage(){
	al_draw_bitmap(this->image,this->position_x,this->position_y,0);
}