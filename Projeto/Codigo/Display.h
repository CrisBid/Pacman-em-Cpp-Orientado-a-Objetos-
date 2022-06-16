#include <iostream>

#include <allegro5/allegro5.h>

#ifndef DISPLAY_H
#define DISPLAY_H

using namespace std;

class Display
{
public:
	Display();
	ALLEGRO_DISPLAY* getDisplay();
	void setDisplay(int, int);
	~Display();

private:
	ALLEGRO_DISPLAY* display;
};
#endif