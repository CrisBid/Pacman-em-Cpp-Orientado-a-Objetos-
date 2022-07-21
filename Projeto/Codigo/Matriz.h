#include <iostream>
#include "StructMatriz.h"

#include "allegro5/allegro.h"

#include <fstream>

#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz
{
public:
	Matriz();
	sMatriz getMatriz();
	void setDadosMatriz(int, int, int);
	void setAlturaMatriz(int);
	void setLarguraMatriz(int);
	void loadFileMatriz();
	~Matriz();

private:

	sMatriz ptrmatriz;
	ifstream inFile;
};
#endif