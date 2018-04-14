#include<iostream>
#include"Wall.h"
#include<string.h>
#include<stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

Wall::Wall(){
	this->imageName = NULL;
	this->position_x = this->position_y = -1;
}

Wall::~Wall(){
	al_destroy_bitmap(this->imageName);
	delete [] this->imageName;
}

void Wall::setImage(char* filename,int x, int y){
	al_init_image_addon();
	this->imageName = al_load_bitmap(filename);
	this->position_x = x;
	this->position_y = y;
}

void Wall::loadImage(){
	al_draw_bitmap(this->imageName,this->position_x,this->position_y,0);
}
void Wall::destroyImage(){
	al_destroy_bitmap(this->imageName);
	this->imageName = NULL;
	this->position_y = this->position_x = -1;
}