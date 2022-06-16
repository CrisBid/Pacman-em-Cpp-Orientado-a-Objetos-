#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include "Pirula.h"

#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

Pirula::Pirula() {

	//Inicialição do objeto das Pirulas
	pirula = NULL;
	pirula = al_load_bitmap("Images/pirula.png");
	if (!pirula) {
		printf("ERRO NO BLOCO");
	}
	else {
		printf("\nBloco criado com sucesso\n");
	}
}



void Pirula::setPirula(sMatriz* matriz) {
	for (int i = 0; i < matriz->matriz_altura; i++) //Crição do mapa a partir da matriz
	{
		for (int j = 0; j < matriz->matriz_largura; j++)
		{
			if (matriz->dados_matriz[i][j] == 2)
			{
				al_draw_bitmap_region(pirula, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
		}
	}
	al_flip_display();

}

Pirula::~Pirula() {
	al_destroy_bitmap(pirula);// destroi os tijolos
}
