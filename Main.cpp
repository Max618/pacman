#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"Providers/AllegroProvider/AllegroProvider.h"
#include"App/Wall/Wall.h"
#include"App/Coin/Coin.h"
#include"App/Pacman/Pacman.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;

void rewrite(Wall wall[],Coin coin[],Pacman pacman[], int direction){
    //DESENHA IMAGENS
    for(int i = 0; i < 360; i++){
      wall[i].loadImage();
    }

    for(int i = 0; i < 374; i++){
      coin[i].loadImage();
    }

    //DESENHA pacman
    for(int i = 0; i < 1; i++){
      pacman[i].loadImage(direction);
    }
    al_flip_display();
    al_draw_bitmap(al_load_bitmap("Images/background.jpg"),0,0,0);
}

int getCoin(Coin coin[], int x, int y){

    int i=0;
    for (i = 0; i < 374; i++)
      {
        if (coin[i].getPositionX() == x*25 && coin[i].getPositionY() == y*25)
         {
           return i;
         } 
         
      }
    return -1;
}

int main(){

    bool Exit = false, reWrite = true;
    int direction = 0, next = 0;
    int matriz[24][32] = {
                          1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                          1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                          1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,
                          1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
                          1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,
                          1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
                          1,0,1,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,1,0,1,
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
                          1,0,1,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,1,0,1,
                          1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
                          1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,
                          1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
                          1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,
                          1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
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
  Wall *wall = new Wall[360];
  Coin *coin = new Coin[374];
  Pacman *pacman = new Pacman;
  int w = 0, c = 0, ch = 0, k = 0, score = 0, before = 0;


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
    }
  }

  //DESENHA IMAGENS
  for(int i = 0; i < 360; i++){
    wall[i].loadImage();
  }

  for(int i = 0; i < 374; i++){
    coin[i].loadImage();
  }

  //DESENHA pacman
  for(int i = 0; i < 1; i++){
    pacman[i].loadImage(0);
  }
  //al_flip_display();

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
      if(direction == 1 && matriz[pacman->getPositionY()-1][pacman->getPositionX()] != 1){
        pacman->move(direction);
         k = getCoin(coin, pacman->getPositionX(), pacman->getPositionY());
        if(k >= 0){
          coin[k].setPositions(-1, 601);
          score++;
        }
        before = direction; 
      }
      else if(direction == 2 && matriz[pacman->getPositionY()+1][pacman->getPositionX()] != 1){
        pacman->move(direction);
        k = getCoin(coin, pacman->getPositionX(), pacman->getPositionY());
        if(k >= 0){
          coin[k].setPositions(-1, 601);
          score++;
        }
        before = direction; 
      }
      else if(direction == 3 && matriz[pacman->getPositionY()][pacman->getPositionX()-1] != 1){
        pacman->move(direction);
        k = getCoin(coin, pacman->getPositionX(), pacman->getPositionY());
        if(k >= 0){
          coin[k].setPositions(-1, 601);
          score++;
        }
        before = direction; 
      }
      else if(direction == 4 && matriz[pacman->getPositionY()][pacman->getPositionX()+1] != 1){
        pacman->move(direction);
        k = getCoin(coin, pacman->getPositionX(), pacman->getPositionY());
        if(k >= 0){
          coin[k].setPositions(-1, 601);
          score++;
        }
        before = direction; 
      }
      else{
          if(before == 1 && matriz[pacman->getPositionY()-1][pacman->getPositionX()] != 1){
            k = getCoin(coin, pacman->getPositionX(), pacman->getPositionY()-1);
            pacman->move(before);
            if(k >= 0){
              coin[k].setPositions(-1, 601);
              score++;
            }
          }
          else if(before == 2 && matriz[pacman->getPositionY()+1][pacman->getPositionX()] != 1){
            pacman->move(before);
            k = getCoin(coin, pacman->getPositionX(), pacman->getPositionY());
            if(k >= 0){
              coin[k].setPositions(-1, 601);
              score++;
            }
          }
          else if(before == 3 && matriz[pacman->getPositionY()][pacman->getPositionX()-1] != 1){
            pacman->move(before);
            k = getCoin(coin, pacman->getPositionX(), pacman->getPositionY());
            if(k >= 0){
              coin[k].setPositions(-1, 601);
              score++;
            }
          }
          else if(before == 4 && matriz[pacman->getPositionY()][pacman->getPositionX()+1] != 1){
            pacman->move(before);
            k = getCoin(coin, pacman->getPositionX(), pacman->getPositionY());
            if(k >= 0){
              coin[k].setPositions(-1, 601);
              score++;
            }
          }
      }
    }
    else if(pacman->eventKeyDown()){
      switch(pacman->getEvent().keyboard.keycode){
        case ALLEGRO_KEY_UP:
          direction = 1;
        break;
        case ALLEGRO_KEY_DOWN:
          direction = 2;
        break;
        case ALLEGRO_KEY_LEFT:
          direction = 3;
        break;
        case ALLEGRO_KEY_RIGHT:
          direction = 4;
      }
    }

    if(score == 374){
      exit(1);
    }

    reWrite = true;
    if(alP->checkEvents() && reWrite){
      alP->writeScore(score);
      rewrite(wall,coin,pacman,direction);
      reWrite = false;
    }

  }




  //DESTROI O JOGO
  alP->destroyDisplay();
  for(int i = 0; i < 360; i++){
    wall[i].destroyImage();
  }

  for(int i = 0; i < 374; i++){
    coin[i].destroyImage();
  }

  for(int i = 0; i < 1; i++){
    pacman[i].destroyImage();
  }

  delete [] alP;
  delete [] wall;
  delete [] coin;
  delete [] pacman;
  

  return 0;
}