#include<iostream>
#include"Character.h"
#include<string.h>
#include<stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <cstring>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;

Character::Character(){
	this->imageName[0] = NULL;
	this->imageName[1] = NULL;
	this->position_x = this->position_y = this->beforeD = this->direction = -1;
}

Character::~Character(){
	al_destroy_bitmap(this->imageName[0]);
	al_destroy_bitmap(this->imageName[1]);
}

void Character::setPositions(int x, int y){
	this->position_x = x;
	this->position_y = y;
}

void Character::setPositionX(int x){
	this->position_x = x;
}

void Character::setPositionY(int y){
	this->position_y = y;
}

void Character::setImages(char* img, char* img2){
	this->imageName[0] = al_load_bitmap(img);
	this->imageName[1] = al_load_bitmap(img2);
}

int Character::getPositionX(){
	return this->position_x;
}

int Character::getPositionY(){
	return this->position_y;
}


void Character::loadImage(int direction){
	if(direction == 1 || direction == 4)
		al_draw_bitmap_region(this->imageName[1], 0, 0, 25, 25, this->position_x*25,this->position_y*25,0);
	if(direction == 2 || direction == 3)
		al_draw_bitmap_region(this->imageName[0], 0, 0, 25, 25, this->position_x*25,this->position_y*25,0);
}

void Character::destroyImage(){
	al_destroy_bitmap(this->imageName[0]);
	al_destroy_bitmap(this->imageName[1]);
	this->imageName[0] = NULL;
	this->imageName[1] = NULL;
	this->position_y = this->position_x = -1;
}

void Character::setBeforeD(int d){
	this->beforeD = d;
}

int Character::getBeforeD(){
	return this->beforeD;
}

void Character::setDirection(int d){
	this->direction = d;
}

int Character::getDirection(){
	return this->direction;
}