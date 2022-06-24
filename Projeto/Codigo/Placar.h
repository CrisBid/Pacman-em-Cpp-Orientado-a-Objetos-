#include <allegro5/allegro5.h>

#ifndef PLACAR_H
#define PLACAR_H

class Placar
{
public:
	Placar();
	void set_placar(int);
	int getPlacar();
	void desenhaPlacar();
	~Placar();

private:
	ALLEGRO_BITMAP* placar;
	int num_placar;

	int num_placarX;
	int num_placarXX;
	int num_placarXXX;
};

#endif
