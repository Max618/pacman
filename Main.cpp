#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"Providers/AllegroProvider/AllegroProvider.h"
#include"App/Wall/Wall.h"
#include"App/Coin/Coin.h"
#include"App/Character/Character.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;

void rewrite(Wall wall[],Coin coin[],Character character[]){
    //DESENHA IMAGENS
    for(int i = 0; i < 360; i++){
      wall[i].loadImage();
    }

    for(int i = 0; i < 374; i++){
      coin[i].loadImage();
    }

    //DESENHA CHARACTER
    for(int i = 0; i < 1; i++){
      character[i].loadImage();
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

void escreve(ALLEGRO_FONT *fonte, int score){
  al_draw_textf(fonte, al_map_rgb(0, 0, 0), 1000, 300, ALLEGRO_ALIGN_CENTRE, "PLACAR: %d", score);
}

int main(){

    bool exit = false, reWrite = true;
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
  alP->setEvents();

  //CRIA OBJETOS
  Wall *wall = new Wall[360];
  Coin *coin = new Coin[374];
  Character *character = new Character;
  int w = 0, c = 0, ch = 0, k, score=0;

  //CRIANDO SCORE
  ALLEGRO_FONT *fonte = NULL;
  al_init_font_addon();
  al_init_ttf_addon();
  fonte = al_load_font ("fonts/PORKYS_.TTF", 30, 0);



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
        character[ch++].setPositions(j,i);
      }
    }
  }

  //EVENTOS DO TECLADO PARA ANDAR
  while(!exit){
    //if(direction == 0)
      character->waitEvent(alP->getEvents());
    


    if(character->eventKeyDown()){
      switch(character->getEvent().keyboard.keycode){
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
    else if(character->eventKeyUp()){
      switch(character->getEvent().keyboard.keycode){
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
        break;
        case ALLEGRO_KEY_ESCAPE:
          direction = 5;
      }
    
    }
    if(character->eventCloseDisplay()){
      exit = true;
      //exit(1);
    }

    if(direction==1 && matriz[character->getPositionY()-1][character->getPositionX()] != 1){
        
        k = getCoin(coin, character->getPositionX(), character->getPositionY()-1);
        character->setPositions(character->getPositionX(),character->getPositionY()-1);

        if(k >= 0){
          coin[k].setPositions(-1, 601);
          score++;
        } 

    }

    else if(direction==2 && matriz[character->getPositionY()+1][character->getPositionX()] != 1){
        character->setPositions(character->getPositionX(),character->getPositionY()+1);

        k = getCoin(coin, character->getPositionX(), character->getPositionY());
        if(k >= 0){
          coin[k].setPositions(-1, 601);
          score++;
        } 
    }

    else if(direction==3 && matriz[character->getPositionY()][character->getPositionX()-1] != 1){
        character->setPositions(character->getPositionX()-1,character->getPositionY());

        k = getCoin(coin, character->getPositionX(), character->getPositionY());
        if(k >= 0){
          coin[k].setPositions(-1, 601);
          score++;
        } 
    }
    else if(direction==4 && matriz[character->getPositionY()][character->getPositionX()+1] != 1){
        character->setPositions(character->getPositionX()+1,character->getPositionY());

        k = getCoin(coin, character->getPositionX(), character->getPositionY());
        if(k >= 0){
          coin[k].setPositions(-1, 601);
          score++;
        } 
    }
    else
      direction = 0;

    escreve(fonte, score);
    rewrite(wall,coin,character);
    


    //printf("%d\n", direction);
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