#include <allegro5/allegro5.h>

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
