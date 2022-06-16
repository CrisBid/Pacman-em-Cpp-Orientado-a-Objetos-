#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>

#include "Mapa.h"
#include "Pirula.h"

using namespace std;

Mapa::Mapa() {
	//Inicialização da imagem
	image = NULL;

	if (!image) {
		printf("Imagem criado com sucesso!\n");
	}

}



void Mapa::setMapa(sMatriz *matriz) {

	image = al_load_bitmap("Images/mapa.png");

	al_draw_bitmap(image, 0, 0, 0); //Desenha a imagem
	
	Tijolinho Tijolos;
	Pirula Pirulas;

	Tijolos.setTijolos(matriz);
	
	Pirulas.setPirula(matriz);

}

Mapa::~Mapa() {
	al_destroy_bitmap(image); //Destroi a Imagem
}

