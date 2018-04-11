#include<iostream>
#include<string.h>
#include"Wall.h"
#include<stdio.h>

using namespace std;

int main(){
	Wall *wall;
	wall = new Wall;
	wall->setColor("#000000");
	printf("%s",wall->getColor());
	return 0;
}