
#include <allegro5/allegro5.h>
#ifndef MAPA_H
#define MAPA_H

class Mapa {
public:
	Mapa();
	void getDisplay(int w, int h);
	void destroiDisplay();
private:
	ALLEGRO_DISPLAY* display;
};

#endif