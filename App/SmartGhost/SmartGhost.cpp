#include<iostream>
#include"SmartGhost.h"
#include<string.h>
#include<stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <cstring>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

SmartGhost::SmartGhost(){
	this->pacX = this->pacY = -1;
}

SmartGhost::~SmartGhost(){

}

void SmartGhost::setPac(int x, int y){
	this->pacX = x;
	this->pacY = y;
}

void SmartGhost::move(int matriz[][32]){
	if(this->pacY < Character::getPositionY() && matriz[Character::getPositionY()-1][Character::getPositionX()] != 1)
		Character::setPositionY(Character::getPositionY() - 1);
	else if(this->pacY > Character::getPositionY() && matriz[Character::getPositionY()+1][Character::getPositionX()] != 1)
		Character::setPositionY(Character::getPositionY() + 1);
	else if(this->pacX < Character::getPositionX() && matriz[Character::getPositionY()][Character::getPositionX()-1] != 1)
		Character::setPositionX(Character::getPositionX() - 1);
	else if(this->pacX > Character::getPositionX() && matriz[Character::getPositionY()][Character::getPositionX()+1] != 1)
		Character::setPositionX(Character::getPositionX() + 1);
}

int SmartGhost::mod(int x){
	if(x < 0)
		return -x;
	return x;
}