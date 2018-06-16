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

void rewrite(Wall wall[],Coin coin[],Pacman pacman[], int direction[5], Ghost **ghosts){
    int s = 0;
    //DESENHA IMAGENS
    for(int i = 0; i < 368; i++){
      wall[i].loadImage();
    }

    for(int i = 0; i < 362; i++){
      coin[i].loadImage();
    }

    //DESENHA pacman
    for(int i = 0; i < 1; i++){
      pacman[i].loadImage(direction[s++]);
    }

    //DESENHA GHOST
    for(int i = 0; i < 4; i++){
      ghosts[i]->loadImage(s++);
    }


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

bool checkPacmanGhost(Pacman pacman[], Ghost **ghost){
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
                          1,0,1,0,0,1,0,1,0,1,0,1,2,1,1,6,6,1,1,2,1,0,1,0,1,0,1,0,0,1,0,1,
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
  Ghost *ghosts[4];
  SmartGhost *smart = new SmartGhost;
  int w = 0, c = 0, ch = 0, g = 0, k = 0, score = 0, img = 0, a = 0;
  bool startGame = false;

  char images[6][50];
  strcpy(images[0],"Images/capacetin-left.png");
  strcpy(images[1],"Images/capacetin-right.png");
  strcpy(images[2],"Images/chapeu-left.png");
  strcpy(images[3],"Images/chapeu-right.png");
  strcpy(images[4],"Images/loirinha-right.png");
  strcpy(images[5],"Images/loirinha-left.png");


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
        ghost[g].setImages(images[img++],images[img++]);
        ghost[g++].setPositions(j,i);
      }
      else if(matriz[i][j] == 5){
        smart->setImages("Images/puccona-left.png","Images/puccona-right.png");
        smart->setPositions(j,i);
      }
    }
  }

  ghosts[0] = &ghost[0];
  ghosts[1] = &ghost[1];
  ghosts[2] = &ghost[2];
  ghosts[3] = smart;

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
  for(int i = 0; i < 4; i++){
    ghosts[i]->loadImage(0);
  }
  //smart->loadImage(0);

  //EVENTOS DO TECLADO PARA ANDAR
  while(!Exit){
    /*for(int i = 0; i < 24; i++){
      for(int j = 0; j < 32; j++){
        printf("%d ", matriz[i][j]);
      }
      printf("\n");
    }
    printf("\n");*/

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
        smart->setPac(pacman->getPositionX(),pacman->getPositionY());
        k = getCoin(coin, pacman->getPositionX(), pacman->getPositionY());
        if(k >= 0){
          coin[k].setPositions(-1, 601);
          score++;
        }
      }

      if(startGame){
        for(int i = 0; i < 4; i++){
          ghosts[i]->move(matriz);
        }
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

    reWrite = true;
    if(alP->checkEvents() && reWrite){
      alP->writeScore(score);
      int dir[5] = {pacman->getDirection(),ghosts[0]->getDirection()+1,ghosts[1]->getDirection()+1,ghosts[2]->getDirection()+1, ghosts[3]->getDirection()+1};
      rewrite(wall,coin,pacman,dir,ghosts);
      reWrite = false;
    }

    if(score == 362 || checkPacmanGhost(pacman,ghosts)){
      alP->writeEndGame(score);
      exit(1);
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

  for(int i = 0; i < 4; i++){
    ghosts[i]->destroyImage();
  }

  delete [] alP;
  delete [] wall;
  delete [] coin;
  delete [] pacman;
  delete [] ghost;
  delete [] smart;
  delete [] ghosts;

  return 0;
}