#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include "AllegroProvider.h"

using namespace std;

AllegroProvider::AllegroProvider(){
	this->display = NULL;
	al_init();
	al_init_image_addon();
}

void AllegroProvider::setDisplay(int width, int height){
	this->width = width;
	this->height = height;
}

void AllegroProvider::loadDisplay(){
	this->display = al_create_display(this->width,this->height); 
}

void AllegroProvider::setBackgroundColor(int r,int g, int b){
	al_clear_to_color(al_map_rgb(r,g,b));
}

void AllegroProvider::destroyDisplay(){
	al_destroy_display(this->display);
}

void AllegroProvider::loadImage(char* filename){
	ALLEGRO_BITMAP  *image   = NULL;
	image = al_load_bitmap(this->getPublic(filename));
	al_draw_bitmap(image,0,0,0);
}

char* AllegroProvider::getPublic(char* filename){
	char *file;
	strcpy(file,"Images/");
	strcat(file,filename);
	return file;
}