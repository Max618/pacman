#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <stdio.h>
#include "AllegroProvider.h"

using namespace std;

AllegroProvider::AllegroProvider(){
	this->display = NULL;
	this->event_queue = al_create_event_queue();
	this->timer = al_create_timer(1.0 / 60);
	al_init();
	al_install_keyboard();//Funcoes Teclado
	al_init_image_addon();
}

void AllegroProvider::setDisplay(int width, int height){
	this->width = width;
	this->height = height;
}

void AllegroProvider::loadDisplay(){
	this->display = al_create_display(this->width,this->height); 
	this->startEvents();
}

void AllegroProvider::setBackgroundColor(int r,int g, int b){
	al_clear_to_color(al_map_rgb(r,g,b));
}

void AllegroProvider::destroyDisplay(){
	al_flip_display();//Atualiza o Buffer da Tela
  	al_rest(20); //Tempo que a tela fica ativa (em segundos)
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

void AllegroProvider::startEvents(){
	al_register_event_source(this->event_queue, al_get_display_event_source(this->display));//Evento da Tela
   	al_register_event_source(this->event_queue, al_get_timer_event_source(this->timer));//Evento de tempo

   	al_start_timer(this->timer);
}