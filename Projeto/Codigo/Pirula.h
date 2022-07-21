#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#include "StructMatriz.h"

using namespace std;

#ifndef PIRULA_H
#define PIRULA_H

class Pirula {
public:
	Pirula();
	void setPirula(sMatriz*);
	~Pirula();
; private:

	ALLEGRO_BITMAP* pirula;
};

#endif // PIRULA_H
