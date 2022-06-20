#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include "Pacman.h"



Pacman::Pacman()
{
	//Inicialização do display

	pacman = NULL;

	if (!pacman) {
		printf("Tabuleiro criado com sucesso!\n");
	}
}

ALLEGRO_BITMAP* Pacman::getPacman() {
	return pacman;
}

void Pacman::setPacman(int w, int h) {
	pacman = al_load_bitmap("Images/Pacman.png");

	if (pacman == NULL) {
		printf("ERRO no display");
		return;
	}
}

Pacman::~Pacman()
{
	al_destroy_bitmap(pacman); //Destroi a tela
}

