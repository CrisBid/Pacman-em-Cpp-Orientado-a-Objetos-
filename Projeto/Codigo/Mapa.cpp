#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Pirula.h"

#include "Mapa.h"

using namespace std;

Mapa::Mapa() {
	//Inicializa��o da imagem
	image = NULL;

	if (!image) {
		printf("Imagem criado com sucesso!\n");
	}

}
/*
ALLEGRO_BITMAP* Mapa::loadImage() {
	
	if (!image) {
		printf("Falha ao Criar Imagem!\n");
	}
	return image;
}

ALLEGRO_BITMAP* Mapa::getImage() {
	return image;
}*/



void Mapa::setMapa(sMatriz *matriz) {


	Tijolinho Tijolos;
	Pirula Pirulas;

	Tijolos.setTijolos(matriz);
	
	Pirulas.setPirula(matriz);

}

Mapa::~Mapa() {
	al_destroy_bitmap(image); //Destroi a Imagem
}

