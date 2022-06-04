#include <allegro5/allegro5.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

#ifndef TIJOLINHO_H
#define TIJOLINHO_H

const int largura = 66;//Tab Interno 630 = 21*30
const int altura = 60;//Tab Interno x   = x*30

class Tijolinho {
	public:
		Tijolinho();
		void draw();
		void destroyDraw();
	;private:
		ALLEGRO_BITMAP* blocopng;

		int l_matriz = largura, a_matriz = altura;

		int matriz[altura][largura];

		ifstream inFile;
};

#endif // !BLOCO_H
