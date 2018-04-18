#include<iostream>
#include"Coin.h"
#include<string.h>
#include<stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <cstring>

using namespace std;

Coin::Coin(){
	this->imageName = NULL;
	this->position_x = this->position_y = -1;
}

Coin::~Coin(){
	al_destroy_bitmap(this->imageName);
	delete [] this->imageName;
}

void Coin::setImage(char* filename){
	al_init_image_addon();
	this->imageName = al_load_bitmap(this->getPublic(filename));
}

void Coin::loadImage(int x, int y){
	al_draw_bitmap(this->imageName,x,y,0);
}
void Coin::destroyImage(){
	al_destroy_bitmap(this->imageName);
	this->imageName = NULL;
	this->position_y = this->position_x = -1;
}

char* Coin::getPublic(char* filename){
	char *file;
	strcpy(file,"Images/");
	strcat(file,filename);
	return file;
}