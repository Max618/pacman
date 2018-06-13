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

void Ghost::move(int matriz[][32]){
	int d = 0;
	bool checkD[4] = {true,true,true,true};
    if(matriz[Character::getPositionY()-1][Character::getPositionX()] == 1 || Character::getBeforeD() == 1){
      checkD[0] = false;
    }
    if(matriz[Character::getPositionY()+1][Character::getPositionX()] == 1 || Character::getBeforeD() == 0){
      checkD[1] = false;
    }
    if(matriz[Character::getPositionY()][Character::getPositionX()-1] == 1 || Character::getBeforeD() == 3){
      checkD[2] = false;
    }
    if(matriz[Character::getPositionY()][Character::getPositionX()+1] == 1 || Character::getBeforeD() == 2){
      checkD[3] = false;
    }
    do{
      d = (1+rand()%4)%4;
    }while(!checkD[d]);
    Character::setBeforeD(d);
    if(d == 0)
		Character::setPositionY(Character::getPositionY() - 1);
	else if(d == 1)
		Character::setPositionY(Character::getPositionY() + 1);
	else if(d == 2)
		Character::setPositionX(Character::getPositionX() - 1);
	else if(d == 3)
		Character::setPositionX(Character::getPositionX() + 1);
}