#include "Tijolinho.h"
#include "allegro5/allegro.h"

using namespace std;

#ifndef MAPA_H
#define MAPA_H

class Mapa {
public:
	Mapa();
	ALLEGRO_BITMAP* loadImage();
	ALLEGRO_BITMAP* getImage();
	void setMapa(sMatriz*);
	~Mapa();
private:

	ALLEGRO_BITMAP* image;
};

#endif