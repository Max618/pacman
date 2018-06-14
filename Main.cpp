#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"Providers/AllegroProvider/AllegroProvider.h"
#include"App/Wall/Wall.h"
#include"App/Coin/Coin.h"
#include"App/Pacman/Pacman.h"
#include"App/Ghost/Ghost.h"
#include"App/SmartGhost/SmartGhost.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdlib.h>

using namespace std;

void rewrite(Wall wall[],Coin coin[],Pacman pacman[], int direction, Ghost ghost[], SmartGhost smart[]){
    //DESENHA IMAGENS
    for(int i = 0; i < 368; i++){
      wall[i].loadImage();
    }

    for(int i = 0; i < 362; i++){
      coin[i].loadImage();
    }

    //DESENHA pacman
    for(int i = 0; i < 1; i++){
      pacman[i].loadImage(direction);
    }

    //DESENHA GHOST
    for(int i = 0; i < 3; i++){
      ghost[i].loadImage(1);
    }
    smart->loadImage(1);


    al_flip_display();
    al_draw_bitmap(al_load_bitmap("Images/background.jpg"),0,0,0);
}

int getCoin(Coin coin[], int x, int y){

    int i=0;
    for (i = 0; i < 362; i++)
      {
        if (coin[i].getPositionX() == x*25 && coin[i].getPositionY() == y*25)
         {
           return i;
         } 
         
      }
    return -1;
}

bool checkPacmanGhost(Pacman pacman[], Ghost ghost[]){
  for(int i = 0; i < 3; i++){
    if(pacman->getPositionX() == ghost[i].getPositionX() && pacman->getPositionY() == ghost[i].getPositionY())
      return true;
  }
  return false;
}

int main(){

    bool Exit = false, reWrite = true;
    int matriz[24][32] = {
                          1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                          1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1,
                          1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,
                          1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
                          1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,
                          1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
                          1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,
                          1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
                          1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,
                          1,0,1,0,0,0,0,1,0,0,0,1,2,2,2,2,2,2,2,2,1,0,0,0,1,0,0,0,0,1,0,1,
                          1,0,1,0,0,1,0,1,0,1,0,1,2,1,1,2,2,1,1,2,1,0,1,0,1,0,1,0,0,1,0,1,
                          1,0,0,0,0,1,0,1,0,1,0,1,2,1,2,2,2,2,1,2,1,0,1,0,1,0,1,0,0,0,0,1,
                          1,0,1,0,0,1,0,1,0,1,0,1,2,1,2,2,3,2,1,2,1,0,1,0,1,0,1,0,0,1,0,1,
                          1,0,1,0,0,1,0,1,0,1,0,1,2,1,1,1,1,1,1,2,1,0,1,0,1,0,1,0,0,1,0,1,
                          1,0,1,0,0,1,0,0,0,1,0,0,2,2,2,2,2,2,2,2,0,0,1,0,0,0,1,0,0,1,0,1,
                          1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,
                          1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
                          1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,
                          1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
                          1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,
                          1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
                          1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,
                          1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,
                          1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
                          };

  //STARTA O JOGO
  AllegroProvider *alP = new AllegroProvider;
  alP->setDisplay(1200,600);
  alP->loadDisplay();
  alP->loadImage("background.jpg");
  alP->setFPS(6);
  alP->setEvents();
  alP->loadFont();

  //CRIA OBJETOS
  Wall *wall = new Wall[368];
  Coin *coin = new Coin[362];
  Pacman *pacman = new Pacman;
  Ghost *ghost = new Ghost[3];
  SmartGhost *smart = new SmartGhost;
  int w = 0, c = 0, ch = 0, g = 0, k = 0, score = 0;
  bool startGame = false;


  //SETA POSICAO DAS IMAGENS
  for(int i = 0; i < 24; i++){
    for(int j = 0; j < 32; j++){
      if((matriz[i][j]) == 1){
        wall[w++].setPositions(j*25,i*25);
      }
      else if((matriz[i][j]) == 0){
        coin[c++].setPositions(j*25,i*25);
      }
      else if((matriz[i][j]) == 3){
        pacman[ch].setImages("Images/garuleft.png","Images/garuright.png");
        pacman[ch++].setPositions(j,i);
      }
      else if(matriz[i][j] == 4){
        ghost[g].setImages("Images/garuright.png","Images/garuleft.png");
        ghost[g++].setPositions(j,i);
      }
      else if(matriz[i][j] == 5){
        smart->setImages("Images/garuright.png","Images/garuleft.png");
        smart->setPositions(j,i);
      }
    }
  }

  //DESENHA IMAGENS
  for(int i = 0; i < 368; i++){
    wall[i].loadImage();
  }

  for(int i = 0; i < 362; i++){
    coin[i].loadImage();
  }

  //DESENHA PACMAN
  for(int i = 0; i < 1; i++){
    pacman[i].loadImage(0);
  }

  //DESENHA GHOST
  for(int i = 0; i < 3; i++){
    ghost[i].loadImage(0);
  }
  smart->loadImage(0);

  //EVENTOS DO TECLADO PARA ANDAR
  while(!Exit){
    pacman->waitEvent(alP->getEvents());

    if(pacman->eventCloseDisplay()){
      exit(1);
    }
    if(pacman->eventEscape()){
      exit(1);
    }

    else if(pacman->eventTimer()){
      if(pacman->getDirection() != -1){
        pacman->move(matriz);
        k = getCoin(coin, pacman->getPositionX(), pacman->getPositionY());
        if(k >= 0){
          coin[k].setPositions(-1, 601);
          score++;
        }
      }

      if(startGame){
        for(int i = 0; i < 3; i++){
          ghost[i].move(matriz);
        }
        smart->setPac(pacman->getPositionX(),pacman->getPositionY());
        smart->move(matriz);
      }
    }
    else if(pacman->eventKeyDown()){
      switch(pacman->getEvent().keyboard.keycode){
        case ALLEGRO_KEY_UP:
          pacman->setDirection(1);
        break;
        case ALLEGRO_KEY_DOWN:
          pacman->setDirection(2);
        break;
        case ALLEGRO_KEY_LEFT:
          pacman->setDirection(3);
        break;
        case ALLEGRO_KEY_RIGHT:
          pacman->setDirection(4);
      }
      startGame = true;
    }

    if(score == 362 || checkPacmanGhost(pacman,ghost) || checkPacmanGhost(pacman,smart)){
      alP->writeEndGame(score);
      exit(1);
    }

    reWrite = true;
    if(alP->checkEvents() && reWrite){
      alP->writeScore(score);
      rewrite(wall,coin,pacman,pacman->getDirection(),ghost, smart);
      reWrite = false;
    }

  }




  //DESTROI O JOGO
  alP->destroyDisplay();
  for(int i = 0; i < 368; i++){
    wall[i].destroyImage();
  }

  for(int i = 0; i < 362; i++){
    coin[i].destroyImage();
  }

  for(int i = 0; i < 1; i++){
    pacman[i].destroyImage();
  }

  for(int i = 0; i < 3; i++){
    ghost[i].destroyImage();
  }
  smart->destroyImage();

  delete [] alP;
  delete [] wall;
  delete [] coin;
  delete [] pacman;
  delete [] ghost;
  delete [] smart;

  return 0;
}