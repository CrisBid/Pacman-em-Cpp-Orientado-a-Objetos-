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
		ALLEGRO_BITMAP* tijoloE;
		ALLEGRO_BITMAP* tijoloM;
		ALLEGRO_BITMAP* tijoloD;

		ALLEGRO_BITMAP* tijoloEH;
		ALLEGRO_BITMAP* tijoloMH;
		ALLEGRO_BITMAP* tijoloDH;

		ALLEGRO_BITMAP* tijoloQ1;
		ALLEGRO_BITMAP* tijoloQ2;
		ALLEGRO_BITMAP* tijoloQ3;
		ALLEGRO_BITMAP* tijoloQ4;

		ALLEGRO_BITMAP* tijoloQ5;
		ALLEGRO_BITMAP* tijoloQ6;
		ALLEGRO_BITMAP* tijoloQ7;
		ALLEGRO_BITMAP* tijoloQ8;
};

#endif // !BLOCO_H
