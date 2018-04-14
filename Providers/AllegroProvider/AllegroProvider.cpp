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

ALLEGRO_DISPLAY* AllegroProvider::loadDisplay(){
	this->display = al_create_display(this->width,this->height); 
}

void AllegroProvider::setBackgroundColor(int r,int g, int b){
	al_clear_to_color(al_map_rgb(r,g,b));
}

void AllegroProvider::destroyDisplay(){
	al_destroy_display(this->display);
}