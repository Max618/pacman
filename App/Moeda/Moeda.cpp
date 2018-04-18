#include<iostream>
#include"Moeda.h"
#include<string.h>
#include<stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <cstring>

using namespace std;

Moeda::Moeda(){
	this->imageName = NULL;
	this->position_x = this->position_y = -1;
}

Moeda::~Moeda(){
	al_destroy_bitmap(this->imageName);
	delete [] this->imageName;
}

void Moeda::setImage(char* filename,int x, int y){
	al_init_image_addon();
	this->imageName = al_load_bitmap(this->getPublic(filename));
	this->position_x = x;
	this->position_y = y;
}

void Moeda::loadImage(){
	al_draw_bitmap(this->imageName,this->position_x,this->position_y,0);
}
void Moeda::destroyImage(){
	al_destroy_bitmap(this->imageName);
	this->imageName = NULL;
	this->position_y = this->position_x = -1;
}

char* Moeda::getPublic(char* filename){
	char *file;
	strcpy(file,"Images/");
	strcat(file,filename);
	return file;
}