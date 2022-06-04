#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include "Mapa.h"

using namespace std;

Mapa::Mapa() {

	display = NULL;

	if (!display) {
		printf("Tabuleiro criado com sucesso!\n");
	}

	image = NULL; //Imagem

	if (!image) {
		printf("Imagem criado com sucesso!\n");
	}
}

void Mapa::getDisplay(int w, int h) {
	display = al_create_display(w, h);

	if (display == NULL) {
		printf("ERRO no display");
		return;
	}
	al_clear_to_color(al_map_rgb(21, 10, 0));
	al_flip_display();

	image = al_load_bitmap("Images/mapa.png");

	al_draw_bitmap(image, 0, 0, 0); //Desenha a imagem

}

void Mapa::destroiDisplay() {
	al_destroy_display(display); //Destroi a tela
}

