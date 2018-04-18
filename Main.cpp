#include<iostream>
#include<string.h>
#include<stdio.h>
#include"Providers/AllegroProvider/AllegroProvider.h"
#include"App/Wall/Wall.h"
#include"App/Moeda/Moeda.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

using namespace std;

int main(){

    /*int matriz[10][15] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                          1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                          1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                          1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                          1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                          1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                          1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                          1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                          1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                          1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  	*/


	AllegroProvider al_p;
	Wall h;
  Moeda m;
	al_p.setDisplay(1000,700);
	al_p.loadDisplay();
	al_p.setBackgroundColor(255,255,255);


	/*for(int i=0;i<10;i++)
    {
        for(int j=0;j<15;j++)
        {
            if((matriz[i][j])==1)
            {
                al_draw_bitmap(muro, j*TAM,i*TAM,0);
 
            }
            else
            {
                al_draw_bitmap(moeda, j*TAM,i*TAM,0);
            }
        }
    }*/


	h.setImage("teste.png",10,50);
	h.loadImage();
  m.setImage("moeda.png", 5, 10);
  m.loadImage();
	al_flip_display();//Atualiza o Buffer da Tela
   	al_rest(5); //Tempo que a tela fica ativa (em segundos)
   	al_p.destroyDisplay();
	h.destroyImage();
	printf("copilou");
	return 0;
}