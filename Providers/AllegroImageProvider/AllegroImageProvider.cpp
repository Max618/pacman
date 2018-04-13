#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include "AllegroImageProvider.h"

using namespace std;

AllegroImageProvider::AllegroImageProvider(){
	this->image = NULL;
	this->position_x = this->position_y = -1;
}

AllegroImageProvider::~AllegroImageProvider(){
	delete [] image;
}

void AllegroImageProvider::setImage(char* filename,int x, int y){
	this->image = al_load_bitmap(filename);
	this->position_x = x;
	this->position_y = y;
}

void AllegroImageProvider::loadImage(){
	al_draw_bitmap(this->image,this->position_x,this->position_y,0);
}
void AllegroImageProvider::destroyImage(){
	al_destroy_bitmap(this->image);
	this->image = NULL;
	this->position_y = this->position_x = -1;
}