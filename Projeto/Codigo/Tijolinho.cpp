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
	//Inicialização da matriz
	inFile.open("Arquivos/Mapa.txt", ios::in); // abre o arquivo para leitura
	if (!inFile) //Verifica se o arquivo foi aberto
	{
		cout << "Arquivo nao pode ser aberto" << endl;
		abort();
	}

	for (int i = 0; i < a_matriz; i++) //pega os valores da matriz txt e passa para a matriz do codigo
	{
		for (int j = 0; j < l_matriz; j++) 
		{
			inFile >> matriz[i][j];
		}
	}
	//Inicialição do objeto dos Tijolos
	blocopng = NULL;
	blocopng = al_load_bitmap("Images/bloco.png");
	if (!blocopng) {
		printf("ERRO NO BLOCO");
	}
	else {
		printf("\nBloco criado com sucesso\n");
	}
}

void Tijolinho::draw() {
	for (int i = 0; i < a_matriz; i++) //Crição do mapa a partir da matriz
	{
		for (int j = 0; j < l_matriz; j++) 
		{
			if (matriz[i][j]==1)
			{
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);
				al_draw_bitmap_region(blocopng, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
		}
	}
	al_flip_display();

}

void Tijolinho::destroyDraw() {
	al_destroy_bitmap(blocopng);// destroi os tijolos
	inFile.close();// Fecha o arquivo
}