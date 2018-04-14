#include<iostream>
#include<string.h>
#include<stdio.h>
#include"Providers/AllegroProvider/AllegroProvider.h"
#include"App/Wall/Wall.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

using namespace std;

int main(){
	AllegroProvider al_p;
	Wall h;
	al_p.setDisplay(400,400);
	h.setImage("Images/teste.png",200,300);
	al_p.loadDisplay();
	h.loadImage();
	al_flip_display();//Atualiza o Buffer da Tela
   	al_rest(5); //Tempo que a tela fica ativa (em segundos)
   	al_p.destroyDisplay();
	h.destroyImage();
	printf("copilou");
	return 0;
}