#include <allegro5/allegro5.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

#ifndef TIJOLINHO_H
#define TIJOLINHO_H

const int largura = 66;//Tab Interno 660 = 66*10
const int altura = 64; //Tab Interno 640 = 64*10

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
