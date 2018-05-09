#include<iostream>
#include<string.h>
#include<stdio.h>
#include"Providers/AllegroProvider/AllegroProvider.h"
#include"App/Wall/Wall.h"
#include"App/Coin/Coin.h"
#include"App/Character/Character.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

using namespace std;


bool haveWall(int x, int y, bool vet[], Wall wall[])
  {
      if(vet[0])
      {
        for (int i=0; i < 360; i++)
        {
          if(wall[i].getPositionX() == x && wall[i].getPositionY() == y-25)
            return true;
        }
      }

      if(vet[1])
      {
        for (int i=0; i < 360; i++)
        {
          if(wall[i].getPositionX() == x && wall[i].getPositionY() == y+25)
            return true;
        }
      }

      if(vet[2])
      {
        for (int i=0; i < 360; i++)
        {
          if(wall[i].getPositionY() == y && wall[i].getPositionX() == x-25)
            return true;
        }
      }

      if(vet[3])
      {
        for (int i=0; i < 360; i++)
        {
          if(wall[i].getPositionY() == y && wall[i].getPositionX() == x+25)
            return true;
        }
      }

      return false;

  }

int main(){

    bool vet[5]= {false}, exit = false;
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
  alP->setDisplay(900,700);
  alP->loadDisplay();
  alP->loadImage("background.jpg");
  alP->setEvents();

  //CRIA OBJETOS
  Wall *wall = new Wall[360];
  Coin *coin = new Coin[374];
  Character *character = new Character;
  int w = 0, c = 0, ch = 0;


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
        character[ch++].setPositions(j*25,i*25);
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

  for(int i = 0; i < 1; i++){
    character[i].loadImage();
  }

  //EVENTOS DO TECLADO PARA ANDAR
  while(!exit){
    character->waitEvent(alP->getEvents());
    if(character->eventKeyDown()){
      character->getKeyDown(vet);
      if(vet[4])
        exit = true;
    }
    else /*if(character->eventKeyUp())*/{
      character->getKeyUp(vet);
    }
    if(character->eventCloseDisplay()){
      exit = true;
    }

    if(!haveWall(character->getPositionX(), character->getPositionY(), vet, wall))
      character->move(vet);




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
    character[i].destroyImage();
  }

  delete [] alP;
  delete [] wall;
  delete [] coin;
  delete [] character;
  

  return 0;
}