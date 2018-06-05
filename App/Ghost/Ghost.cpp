#include<iostream>
#include"Ghost.h"
#include<string.h>
#include<stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <cstring>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

Ghost::Ghost(){

}

Ghost::~Ghost(){

}

void Ghost::move(int direction){
	if(direction == 0){
		Character::setPositionY(Character::getPositionY() - 1);
	}
	else if(direction == 1){
		Character::setPositionY(Character::getPositionY() + 1);
	}
	else if(direction == 2){
		Character::setPositionX(Character::getPositionX() - 1);
	}
	else if(direction == 3){
		Character::setPositionX(Character::getPositionX() + 1);
	}
}