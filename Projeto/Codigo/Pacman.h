#include <iostream>

#include <allegro5/allegro5.h>

#ifndef PACMAN_H
#define PACMAN_H

using namespace std;

class Pacman
{
public:
	Pacman();
	ALLEGRO_BITMAP* getPacman();
	void setPacman(int, int);
	~Pacman();

private:
	ALLEGRO_BITMAP* pacman;
};
#endif