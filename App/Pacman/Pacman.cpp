#include<iostream>
#include"Pacman.h"
#include<string.h>
#include<stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <cstring>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

Pacman::Pacman(){
}

Pacman::~Pacman(){
}

void Pacman::waitEvent(ALLEGRO_EVENT_QUEUE* fila_eventos){
	al_wait_for_event(fila_eventos,&(this->event));
}

ALLEGRO_EVENT Pacman::getEvent(){
	return (this->event);
}

bool Pacman::eventKeyDown(){
	return ((this->event).type == ALLEGRO_EVENT_KEY_DOWN);
}

bool Pacman::eventKeyUp(){
	return ((this->event).type == ALLEGRO_EVENT_KEY_UP);
}

bool Pacman::eventCloseDisplay(){
	return ((this->event).type == ALLEGRO_EVENT_DISPLAY_CLOSE);
}

bool Pacman::eventEscape(){
	return ((this->event).keyboard.keycode == ALLEGRO_KEY_ESCAPE);
}

bool Pacman::eventTimer(){
	return ((this->event).type == ALLEGRO_EVENT_TIMER);
}

void Pacman::move(int matriz[][32]){

	if(Character::getDirection() == 1 && matriz[Character::getPositionY()-1][Character::getPositionX()] != 1){
		Character::setPositionY(Character::getPositionY() - 1);
		Character::setBeforeD(Character::getDirection());
	}
	
	else if(Character::getDirection() == 2 && matriz[Character::getPositionY()+1][Character::getPositionX()] != 1){
		Character::setPositionY(Character::getPositionY() + 1);
		Character::setBeforeD(Character::getDirection());
	}

	else if(Character::getDirection() == 3 && matriz[Character::getPositionY()][Character::getPositionX()-1] != 1){
		Character::setPositionX(Character::getPositionX() - 1);
		Character::setBeforeD(Character::getDirection());
	}

	else if(Character::getDirection() == 4 && matriz[Character::getPositionY()][Character::getPositionX()+1] != 1){
		Character::setPositionX(Character::getPositionX() + 1);
		Character::setBeforeD(Character::getDirection());
	}

	else{
		if(Character::getBeforeD() == 1 && matriz[Character::getPositionY()-1][Character::getPositionX()] != 1){
			Character::setPositionY(Character::getPositionY() - 1);
		}

		else if(Character::getBeforeD() == 2 && matriz[Character::getPositionY()+1][Character::getPositionX()] != 1){
			Character::setPositionY(Character::getPositionY() + 1);
		}

		else if(Character::getBeforeD() == 3 && matriz[Character::getPositionY()][Character::getPositionX()-1] != 1){
			Character::setPositionX(Character::getPositionX() - 1);
		}

		else if(Character::getBeforeD() == 4 && matriz[Character::getPositionY()][Character::getPositionX()+1] != 1){
			Character::setPositionX(Character::getPositionX() + 1);
		}
	}

}