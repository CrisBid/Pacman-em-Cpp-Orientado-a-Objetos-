#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include "Tijolinho.h"

#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

Tijolinho::Tijolinho() {

	//Inicialição do objeto dos Tijolos
	tijolo = NULL;
	tijolo = al_load_bitmap("Images/bloco.png");
	if (!tijolo) {
		printf("ERRO NO BLOCO");
	}
	tijoloE = NULL;
	tijoloE = al_load_bitmap("Images/Mapa/Esquerda.png");
	if (!tijoloE) {
		printf("ERRO NO BLOCO");
	}
	tijoloM = NULL;
	tijoloM = al_load_bitmap("Images/Mapa/Meio.png");
	if (!tijoloM) {
		printf("ERRO NO BLOCO");
	}
	tijoloD = NULL;
	tijoloD = al_load_bitmap("Images/Mapa/Direita.png");
	if (!tijoloD) {
		printf("ERRO NO BLOCO");
	}
}



void Tijolinho::setTijolos(sMatriz *matriz) {
	for (int i = 0; i < matriz->matriz_altura; i++) //Crição do mapa a partir da matriz
	{
		for (int j = 0; j < matriz->matriz_largura; j++)
		{
			if (matriz->dados_matriz[i][j]==5)
			{
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);
				al_draw_bitmap_region(tijoloE, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
			if (matriz->dados_matriz[i][j] == 6)
			{
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);
				al_draw_bitmap_region(tijoloM, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
			if (matriz->dados_matriz[i][j] == 7)
			{
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);
				al_draw_bitmap_region(tijoloD, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
		}
	}
}
 
Tijolinho::~Tijolinho() {
	al_destroy_bitmap(tijolo);// destroi os tijolos
}
