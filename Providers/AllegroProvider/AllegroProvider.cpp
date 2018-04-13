#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include "AllegroProvider.h"

using namespace std;

AllegroMapProvider::AllegroMapProvider(){
	this->display = NULL;
	this->image = NULL;
	al_init();
	al_init_image_addon();
}

void setDisplay(int width, int height){
	this->width = width;
	this->height = height;
}

ALLEGRO_DISPLAY* loadDisplay(){
	this->display = al_create_display(this->width,this->height); 
}