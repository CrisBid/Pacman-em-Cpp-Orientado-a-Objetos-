#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include "Display.h"



Display::Display()
{
	//Inicialização do display

	display = NULL;

	if (!display) {
		printf("Tabuleiro criado com sucesso!\n");
	}
}

ALLEGRO_DISPLAY* Display::getDisplay() {
	return display;
}

void Display::setDisplay(int w, int h) {
	display = al_create_display(w, h);

	if (display == NULL) {
		printf("ERRO no display");
		return;
	}
	al_clear_to_color(al_map_rgb(21, 10, 0));
	al_flip_display();
}

Display::~Display()
{
	al_destroy_display(display); //Destroi a tela
}

