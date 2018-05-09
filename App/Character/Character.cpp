#include<iostream>
#include"Character.h"
#include<string.h>
#include<stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <cstring>

using namespace std;



Character::Character(){
	this->imageName = NULL;
	this->position_x = this->position_y = -1;
}

Character::~Character(){
	al_destroy_bitmap(this->imageName);
	// delete [] this->imageName;
}

void Character::setPositions(int x, int y){
	al_install_keyboard();
	al_init_image_addon();
	this->imageName = al_load_bitmap("Images/garuleft.png");
	this->position_x = x;
	this->position_y = y;
}

int Character::getPositionX(){
	return position_x;
}

int Character::getPositionY(){
	return position_y;
}


void Character::loadImage(){
	al_draw_bitmap_region(this->imageName, 0, 0, 25, 25, this->position_x,this->position_y,0);
}

void Character::destroyImage(){
	al_destroy_bitmap(this->imageName);
	this->imageName = NULL;
	this->position_y = this->position_x = -1;
}

void Character::waitEvent(ALLEGRO_EVENT_QUEUE* fila_eventos){
	al_wait_for_event(fila_eventos,&(this->event));
}

void Character::getKeyDown(bool vet[]){
	switch((this->event).keyboard.keycode){
		case ALLEGRO_KEY_UP:
			vet[0] = true;
		break;
		case ALLEGRO_KEY_DOWN:
			vet[1] = true;
		break;
		case ALLEGRO_KEY_LEFT:
			vet[2] = true;
		break;
		case ALLEGRO_KEY_RIGHT:
			vet[3] = true;
		break;
		case ALLEGRO_KEY_ESCAPE:
			vet[4] = true;
	}
}

bool Character::eventKeyDown(){
	return ((this->event).type == ALLEGRO_EVENT_KEY_DOWN);
}

bool Character::eventKeyUp(){
	return ((this->event).type == ALLEGRO_EVENT_KEY_UP);
}

bool Character::eventCloseDisplay(){
	return ((this->event).type == ALLEGRO_EVENT_DISPLAY_CLOSE);
}

void Character::getKeyUp(bool vet[]){
	switch((this->event).keyboard.keycode){
		case ALLEGRO_KEY_UP:
			vet[0] = false;
		break;
		case ALLEGRO_KEY_DOWN:
			vet[1] = false;
		break;
		case ALLEGRO_KEY_LEFT:
			vet[2] = false;
		break;
		case ALLEGRO_KEY_RIGHT:
			vet[3] = false;
		break;
		case ALLEGRO_KEY_ESCAPE:
			vet[4] = false;
	}
}


void Character::move(bool vet[]){
	if(vet[0] && this->position_y>0){
		this->position_y -= 25 * vet[0];
		printf("UP X: %d - Y: %d\n", this->position_x, this->position_y);
		for(int i = 0; i < 4; i++){
			printf("vet[%d]: %d\n", i, vet[i]);
		}
	}
	else if(vet[1] && this->position_y<600){
		this->position_y +=  25 * vet[1];
		printf("DOWN X: %d - Y: %d\n", this->position_x, this->position_y);
		for(int i = 0; i < 4; i++){
			printf("vet[%d]: %d\n", i, vet[i]);
		}
	}
	else if(vet[2] && this->position_x>0){
		this->position_x -= 25 * vet[2];
		printf("LEFT X: %d - Y: %d\n", this->position_x, this->position_y);
		for(int i = 0; i < 4; i++){
			printf("vet[%d]: %d\n", i, vet[i]);
		}
	}
	else if(vet[3] && this->position_x<800){
		this->position_x += 25 * vet[3];
		printf("RIGHT X: %d - Y: %d\n", this->position_x, this->position_y);
		for(int i = 0; i < 4; i++){
			printf("vet[%d]: %d\n", i, vet[i]);
		}
	}

			al_clear_to_color(al_map_rgb(0,0,0));
			this->loadImage();
			al_flip_display();

    /*if(vet[0]){
    	while(this->position_y>0){
    		this->position_y -= 25 * vet[0];
			printf("UP X: %d - Y: %d\n", this->position_x, this->position_y);
			this->loadImage();
    		al_flip_display();
    		al_clear_to_color(al_map_rgb(0,0,0));
    	}
    	//vet[0] = false;
    }
    else if(vet[1]){
    	while(this->position_y<600){
    		this->position_y +=  25 * vet[1];
			printf("DOWN X: %d - Y: %d\n", this->position_x, this->position_y);
			this->loadImage();
    		al_flip_display();
    		al_clear_to_color(al_map_rgb(0,0,0));
    	}
    	//vet[1] = false;
    }
    else if(vet[2]){
    	while(this->position_x>0){
    		this->position_x -= 25 * vet[2];
			printf("LEFT X: %d - Y: %d\n", this->position_x, this->position_y);
			this->loadImage();
    		al_flip_display();
    		al_clear_to_color(al_map_rgb(0,0,0));
    	}
    	//vet[2] = false;
    }
    else if(vet[3]){
    	while(this->position_x<800){
    		this->position_x += 25 * vet[3];
			printf("RIGHT X: %d - Y: %d\n", this->position_x, this->position_y);
			this->loadImage();
    		al_flip_display();
    		al_clear_to_color(al_map_rgb(0,0,0));
    	}
    	//vet[3] = false;
    }*/
}