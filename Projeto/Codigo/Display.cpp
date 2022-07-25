#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Display.h"



Display::Display()
{
	//Inicializa��o do display

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
}

void Display::Destrutor()
{
	al_destroy_display(display); //Destroi a tela
}

Display::~Display()
{
	al_destroy_display(display); //Destroi a tela
}

