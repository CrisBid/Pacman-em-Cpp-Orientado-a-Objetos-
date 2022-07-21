#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Pirula.h"

#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

Pirula::Pirula() {

	//Iniciali��o do objeto das Pirulas
	pirula = NULL;
	pirula = al_load_bitmap("Images/Mapa/MeioBiscoito.png");
	if (!pirula) {
		printf("ERRO NO BLOCO");
	}
}



void Pirula::setPirula(sMatriz* matriz) {
	for (int i = 0; i < matriz->matriz_altura; i++) //Cri��o do mapa a partir da matriz
	{
		for (int j = 0; j < matriz->matriz_largura; j++)
		{
			if (matriz->dados_matriz[i][j] == 2)
			{
				al_draw_bitmap_region(pirula, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
		}
	}
}

Pirula::~Pirula() {
	al_destroy_bitmap(pirula);// destroi os tijolos
}
