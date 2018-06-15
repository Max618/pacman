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
	int d = 0;
	bool checkD[4] = {false,false,false,false};

	if(this->pacY < Character::getPositionY())
		checkD[0] = true;
	if(this->pacY > Character::getPositionY())
		checkD[1] = true;
	if(this->pacX < Character::getPositionX())
		checkD[2] = true;
	if(this->pacX > Character::getPositionX())
		checkD[3] = true;

	if(this->pacY - Character::getPositionY() == 0 && (this->pacX - Character::getPositionX()) < 0 && (matriz[Character::getPositionY()+1][Character::getPositionX()] != 1 && matriz[Character::getPositionY()-1][Character::getPositionX()] != 1))
    	checkD[1] = true;
    if(this->pacY - Character::getPositionY() == 0 && (this->pacX - Character::getPositionX()) > 0 && (matriz[Character::getPositionY()+1][Character::getPositionX()] != 1 && matriz[Character::getPositionY()-1][Character::getPositionX()] != 1))
    	checkD[0] = true;
    if(this->pacX - Character::getPositionX() == 0 && (this->pacY - Character::getPositionY()) < 0 && (matriz[Character::getPositionY()][Character::getPositionX()+1] != 1 && matriz[Character::getPositionY()][Character::getPositionX()-1] != 1))
    	checkD[2] = true;
    if(this->pacX - Character::getPositionX() == 0 && (this->pacY - Character::getPositionY()) > 0 && (matriz[Character::getPositionY()][Character::getPositionX()+1] != 1 && matriz[Character::getPositionY()][Character::getPositionX()-1] != 1))
    	checkD[3] = true;

	if(matriz[Character::getPositionY()-1][Character::getPositionX()] == 1 || matriz[Character::getPositionY()-1][Character::getPositionX()] == 6 || Character::getBeforeD() == 1){
      checkD[0] = false;
    }
    if(matriz[Character::getPositionY()+1][Character::getPositionX()] == 1 || matriz[Character::getPositionY()+1][Character::getPositionX()] == 6 || Character::getBeforeD() == 0){
      checkD[1] = false;
    }
    if(matriz[Character::getPositionY()][Character::getPositionX()-1] == 1 || matriz[Character::getPositionY()][Character::getPositionX()-1] == 6 || Character::getBeforeD() == 3){
      checkD[2] = false;
    }
    if(matriz[Character::getPositionY()][Character::getPositionX()+1] == 1 || matriz[Character::getPositionY()][Character::getPositionX()+1] == 6 || Character::getBeforeD() == 2){
      checkD[3] = false;
    }

    if(!checkD[0] && !checkD[1] && !checkD[2] && !checkD[3]){
    	checkD[0] = checkD[1] = checkD[2] = checkD[3] = true;
    	if(matriz[Character::getPositionY()-1][Character::getPositionX()] == 1 || matriz[Character::getPositionY()-1][Character::getPositionX()] == 6 || Character::getBeforeD() == 1){
	      checkD[0] = false;
	    }
	    if(matriz[Character::getPositionY()+1][Character::getPositionX()] == 1 || matriz[Character::getPositionY()+1][Character::getPositionX()] == 6 || Character::getBeforeD() == 0){
	      checkD[1] = false;
	    }
	    if(matriz[Character::getPositionY()][Character::getPositionX()-1] == 1 || matriz[Character::getPositionY()][Character::getPositionX()-1] == 6 || Character::getBeforeD() == 3){
	      checkD[2] = false;
	    }
	    if(matriz[Character::getPositionY()][Character::getPositionX()+1] == 1 || matriz[Character::getPositionY()][Character::getPositionX()+1] == 6 || Character::getBeforeD() == 2){
	      checkD[3] = false;
	    }
	    do{
	      d = (1+rand()%4)%4;
	    }while(!checkD[d]);
    }

    if(checkD[0] && (matriz[Character::getPositionY()-1][Character::getPositionX()] != 1 )){
		Character::setPositionY(Character::getPositionY() - 1);
		Character::setBeforeD(0);
	}
	else if(checkD[1] && (matriz[Character::getPositionY()+1][Character::getPositionX()] != 1 )){
		Character::setPositionY(Character::getPositionY() + 1);
		Character::setBeforeD(1);
	}
	else if(checkD[2] && (matriz[Character::getPositionY()][Character::getPositionX()-1] != 1 )){
		Character::setPositionX(Character::getPositionX() - 1);
		Character::setBeforeD(2);
	}
	else if(checkD[3] && (matriz[Character::getPositionY()][Character::getPositionX()+1] != 1 )){
		Character::setPositionX(Character::getPositionX() + 1);
		Character::setBeforeD(3);
	}
	else{
		if(Character::getBeforeD() == 0 && (matriz[Character::getPositionY()-1][Character::getPositionX()] != 1 )){
			Character::setPositionY(Character::getPositionY() - 1);
		}
		else if(Character::getBeforeD() == 1 && (matriz[Character::getPositionY()+1][Character::getPositionX()] != 1 )){
			Character::setPositionY(Character::getPositionY() + 1);
		}
		else if(Character::getBeforeD() == 2 && (matriz[Character::getPositionY()][Character::getPositionX()-1] != 1 )){
			Character::setPositionX(Character::getPositionX() - 1);
		}
		else if(Character::getBeforeD() == 3 && (matriz[Character::getPositionY()][Character::getPositionX()+1] != 1 )){
			Character::setPositionX(Character::getPositionX() + 1);
		}
	}
}