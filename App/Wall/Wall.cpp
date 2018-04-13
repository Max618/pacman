#include<iostream>
#include"Wall.h"
#include<string.h>
#include<stdio.h>

using namespace std;

Wall::Wall(){
	this->imageName = "\0";
	this->position_x = this->position_y = -1;
}

Wall::~Wall(){
}

void Wall::setImageName(char c[]){
	strcpy(this->imageName, c);
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

char* Wall::getImageName(){
	return this->imageName;
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