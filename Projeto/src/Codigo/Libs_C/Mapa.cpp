#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include "../Libs_H/Mapa.h"

using namespace std;

Mapa::Mapa() {
	display = NULL;
	if (!display) {
		printf("Tabuleiro criado com sucesso!");
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
}

void Mapa::destroiDisplay() {
	al_destroy_display(display); //Destroi a tela
}

