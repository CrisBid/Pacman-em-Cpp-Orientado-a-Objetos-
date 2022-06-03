#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "Mapa.h"
#include "Tijolinho.h"

using namespace std;

Tijolinho::Tijolinho() {
	blocopng = NULL;
	blocopng = al_load_bitmap("bloco.png");
	if (!blocopng) {
		printf("ERRO NO BLOCO");
	}
}

void Tijolinho::draw() {
	al_draw_bitmap(blocopng, 200, 200, 0);
	al_flip_display();
}

void Tijolinho::destroyDraw() {
	al_destroy_bitmap(blocopng);
}