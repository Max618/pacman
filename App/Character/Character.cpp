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
	delete [] this->imageName;
}

void Character::setPositions(int x, int y){
	al_init_image_addon();
	this->imageName = al_load_bitmap("Images/garuleft.png");
	this->position_x = x;
	this->position_y = y;
}

void Character::loadImage(){
	al_draw_bitmap(this->imageName,this->position_x,this->position_y,0);
}

void Character::destroyImage(){
	al_destroy_bitmap(this->imageName);
	this->imageName = NULL;
	this->position_y = this->position_x = -1;
}