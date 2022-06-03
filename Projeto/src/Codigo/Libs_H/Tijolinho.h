#include <allegro5/allegro5.h>
#ifndef TIJOLINHO_H
#define TIJOLINHO_H

class Tijolinho {
public:
	Tijolinho();
	void draw();
	void destroyDraw();
;	private:
	ALLEGRO_BITMAP* blocopng;
};

#endif // !BLOCO_H
