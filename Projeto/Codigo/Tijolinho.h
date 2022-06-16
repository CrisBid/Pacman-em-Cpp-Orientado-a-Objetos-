#include <allegro5/allegro5.h>

#include "StructMatriz.h"

using namespace std;

#ifndef TIJOLINHO_H
#define TIJOLINHO_H

class Tijolinho {
	public:
		Tijolinho();
		void setTijolos(sMatriz*);
		~Tijolinho();
	;private:
		ALLEGRO_BITMAP* tijolo;
};

#endif // !BLOCO_H
