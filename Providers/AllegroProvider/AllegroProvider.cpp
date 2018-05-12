#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include "AllegroProvider.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;

AllegroProvider::AllegroProvider(){
	this->display = NULL;
	this->font = NULL;
	this->timer = NULL;
	this->image = NULL;
	al_init();
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
  	al_init_ttf_addon();
}

AllegroProvider::~AllegroProvider(){
	al_destroy_display(this->display);
	al_destroy_bitmap(this->image);
	al_destroy_event_queue(this->events);
	al_destroy_timer(this->timer);
	al_destroy_font(this->font);
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
	al_flip_display();//Atualiza o Buffer da Tela
  	al_rest(5); //Tempo que a tela fica ativa (em segundos)
	al_destroy_display(this->display);
}

void AllegroProvider::loadImage(char* filename){
	this->image = al_load_bitmap(this->getPublic(filename));
	al_draw_bitmap(image,0,0,0);
}

char* AllegroProvider::getPublic(char* filename){
	char *file;
	strcpy(file,"Images/");
	strcat(file,filename);
	return file;
}

void AllegroProvider::setEvents(){
	this->events = al_create_event_queue();
	al_register_event_source(this->events,al_get_display_event_source(this->display));
	al_register_event_source(this->events,al_get_keyboard_event_source());
	al_register_event_source(this->events, al_get_timer_event_source(this->timer));
	al_start_timer(timer);
	
}

ALLEGRO_EVENT_QUEUE* AllegroProvider::getEvents(){
	return this->events;
}

void AllegroProvider::loadFont(){
	this->font = al_load_font("fonts/PORKYS_.TTF", 64, 0);
}

void AllegroProvider::writeScore(int score){
	al_draw_textf(this->font, al_map_rgb(0, 0, 0), 1000, 150, ALLEGRO_ALIGN_CENTRE, "PLACAR: %d", score);
}

bool AllegroProvider::checkEvents(){
	return al_is_event_queue_empty(this->events);
}

void AllegroProvider::setFPS(int x){
	this->timer = al_create_timer(1.0 / x);
}