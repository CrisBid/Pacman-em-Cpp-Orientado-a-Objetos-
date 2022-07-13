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

	//Vertical

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

	//Horizontal

	tijoloEH = NULL;
	tijoloEH = al_load_bitmap("Images/Mapa/EsquerdaH.png");
	if (!tijoloEH) {
		printf("ERRO NO BLOCO");
	}
	tijoloMH = NULL;
	tijoloMH = al_load_bitmap("Images/Mapa/MeioH.png");
	if (!tijoloMH) {
		printf("ERRO NO BLOCO");
	}
	tijoloDH = NULL;
	tijoloDH = al_load_bitmap("Images/Mapa/DireitaH.png");
	if (!tijoloDH) {
		printf("ERRO NO BLOCO");
	}

	//Encruzilhadas de 2 direçoes

	tijoloQ1 = NULL;
	tijoloQ1 = al_load_bitmap("Images/Mapa/2Direcao-1.png");
	if (!tijoloQ1) {
		printf("ERRO NO BLOCO");
	}
	tijoloQ2 = NULL;
	tijoloQ2 = al_load_bitmap("Images/Mapa/2Direcao-2.png");
	if (!tijoloQ2) {
		printf("ERRO NO BLOCO");
	}
	tijoloQ3 = NULL;
	tijoloQ3 = al_load_bitmap("Images/Mapa/2Direcao-3.png");
	if (!tijoloQ3) {
		printf("ERRO NO BLOCO");
	}
	tijoloQ4 = NULL;
	tijoloQ4 = al_load_bitmap("Images/Mapa/2Direcao-4.png");
	if (!tijoloQ4) {
		printf("ERRO NO BLOCO");
	}

	//Encruzilhadas de 0 direçoes

	tijoloQ5 = NULL;
	tijoloQ5 = al_load_bitmap("Images/Mapa/0Direcao-1.png");
	if (!tijoloQ5) {
		printf("ERRO NO BLOCO");
	}
	tijoloQ6 = NULL;
	tijoloQ6 = al_load_bitmap("Images/Mapa/0Direcao-2.png");
	if (!tijoloQ6) {
		printf("ERRO NO BLOCO");
	}
	tijoloQ7 = NULL;
	tijoloQ7 = al_load_bitmap("Images/Mapa/0Direcao-3.png");
	if (!tijoloQ7) {
		printf("ERRO NO BLOCO");
	}
	tijoloQ8 = NULL;
	tijoloQ8 = al_load_bitmap("Images/Mapa/0Direcao-4.png");
	if (!tijoloQ8) {
		printf("ERRO NO BLOCO");
	}
}



void Tijolinho::setTijolos(sMatriz *matriz) {
	for (int i = 0; i < matriz->matriz_altura; i++) //Crição do mapa a partir da matriz
	{
		for (int j = 0; j < matriz->matriz_largura; j++)
		{
			//Vertical
			if (matriz->dados_matriz[i][j] == 15)
			{
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);
				al_draw_bitmap_region(tijoloE, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
			if (matriz->dados_matriz[i][j] == 16)
			{
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);
				al_draw_bitmap_region(tijoloM, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
			if (matriz->dados_matriz[i][j] == 17)
			{
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);
				al_draw_bitmap_region(tijoloD, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
			//Horizontal
			if (matriz->dados_matriz[i][j] == 25)
			{
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);
				al_draw_bitmap_region(tijoloEH, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
			if (matriz->dados_matriz[i][j] == 26)
			{
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);
				al_draw_bitmap_region(tijoloMH, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
			if (matriz->dados_matriz[i][j] == 27)
			{
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);
				al_draw_bitmap_region(tijoloDH, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
			//2 Direçoes Encruzilhada
			if (matriz->dados_matriz[i][j] == 31)
			{
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);
				al_draw_bitmap_region(tijoloQ1, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
			if (matriz->dados_matriz[i][j] == 32)
			{
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);
				al_draw_bitmap_region(tijoloQ2, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
			if (matriz->dados_matriz[i][j] == 33)
			{
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);
				al_draw_bitmap_region(tijoloQ3, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
			if (matriz->dados_matriz[i][j] == 34)
			{
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);
				al_draw_bitmap_region(tijoloQ4, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);
			}
			//0 Direçoes Encruzilhada
			if (matriz->dados_matriz[i][j] == 35)
			{																						//35
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);                          //1 0 0
				al_draw_bitmap_region(tijoloQ5, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);   //0 0 0
			}																					   //0 0 0
			if (matriz->dados_matriz[i][j] == 36)
			{																						//36
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);                          //0 0 1
				al_draw_bitmap_region(tijoloQ6, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);   //0 0 0
			}																					   //0 0 0
			if (matriz->dados_matriz[i][j] == 37)
			{																						//37
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);                          //0 0 0
				al_draw_bitmap_region(tijoloQ7, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);   //0 0 0
			}																					   //0 0 1
			if (matriz->dados_matriz[i][j] == 38)
			{																						//38
				//al_draw_bitmap(blocopng, 130+(10 * j), 60+(10 * i), 0);                          //0 0 0
				al_draw_bitmap_region(tijoloQ8, 0, 0, 10, 10, 150 + (10 * j), 50 + (10 * i), 0);   //0 0 0
			}																					   //1 0 0
		}
	}
}
 
Tijolinho::~Tijolinho() {
	al_destroy_bitmap(tijolo);// destroi os tijolos

	al_destroy_bitmap(tijoloE);// destroi os tijolos
	al_destroy_bitmap(tijoloM);// destroi os tijolos
	al_destroy_bitmap(tijoloD);// destroi os tijolos

	al_destroy_bitmap(tijoloEH);// destroi os tijolos
	al_destroy_bitmap(tijoloMH);// destroi os tijolos
	al_destroy_bitmap(tijoloDH);// destroi os tijolos

	al_destroy_bitmap(tijoloQ1);// destroi os tijolos
	al_destroy_bitmap(tijoloQ2);// destroi os tijolos
	al_destroy_bitmap(tijoloQ3);// destroi os tijolos
	al_destroy_bitmap(tijoloQ4);// destroi os tijolos

	al_destroy_bitmap(tijoloQ5);// destroi os tijolos
	al_destroy_bitmap(tijoloQ6);// destroi os tijolos
	al_destroy_bitmap(tijoloQ7);// destroi os tijolos
	al_destroy_bitmap(tijoloQ8);// destroi os tijolos
}
