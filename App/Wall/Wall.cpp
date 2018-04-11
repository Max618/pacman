#include<iostream>
#include"Wall.h"
#include<string.h>
#include<stdio.h>

using namespace std;

void Wall::setColor(char c[]){
	strcpy(this->color, c);
}

void Wall::setWidth(float w){
	this->width = w;
}

void Wall::setHeight(float h){
	this->height = h;
}

void Wall::setPositionX(float x){
	this->position_x = x;
}

void Wall::setPositionY(float y){
	this->position_y = y;
}

char* Wall::getColor(){
	return this->color;
}

float Wall::getWidth(){
	return this->width;
}

float Wall::getHeight(){
	return this->height;
}

float Wall::getPositionX(){
	return this->position_x;
}

float Wall::getPositionY(){
	return this->position_y;
}