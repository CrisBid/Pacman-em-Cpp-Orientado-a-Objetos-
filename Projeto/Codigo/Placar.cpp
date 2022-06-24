#include "Placar.h"
#include <iostream>

using namespace std;


Placar::Placar()
{
	placar = NULL;

	num_placar = 0;
	
	num_placarX = 0;
	num_placarXX = 0;
	num_placarXXX = 0;

}

void Placar::set_placar(int x) {
	num_placar = x;

	int a = num_placar;

	int temp, i(0);
	int vetResults[20];
	do {

		vetResults[i] = a % 10;
		a = a / 10;
		i++;

	} while (a >= 10);
	vetResults[i] = a;

	if (num_placar >= 100)
	{
		num_placarX = vetResults[i - 2];
		num_placarXX = vetResults[i - 1];
		num_placarXXX = vetResults[i];
	}
	else
	{
		num_placarX = vetResults[i - 1];
		num_placarXX = vetResults[i];
	}
	for (int j = i; j >= 0; j--)printf("%d \n", i);
}

int Placar::getPlacar() {
	return num_placar;
}

void Placar::desenhaPlacar() {
	
	placar = al_load_bitmap("Images/Numeros/BitmapNumeros.png");
	al_draw_bitmap_region(placar, num_placarX * 30, 0, 30, 30, 80, 155, 0);
	al_draw_bitmap_region(placar, num_placarXX  * 30, 0, 30, 30, 50, 155, 0);
	al_draw_bitmap_region(placar, num_placarXXX  * 30, 0, 30, 30, 20, 155, 0);

	
}

Placar::~Placar()
{
	al_destroy_bitmap(placar);
}