#include <iostream>

#include "StructMatriz.h"
#include "Movimentacao.h"

#include <allegro5/allegro5.h>

#ifndef PACMAN_H
#define PACMAN_H

using namespace std;

class Pacman : public Movimentacao
{
public:
	Pacman();
	Pacman(int,int);

	ALLEGRO_BITMAP* getPacman();

	void posicaoPacman();

	bool colisaoPacman(sMatriz*);

	void colisaoPacmanPirula(sMatriz*);
    int getAtualPlacar();

	bool colisaoPacmanTop(sMatriz*);
	bool colisaoPacmanBottom(sMatriz*);
	bool colisaoPacmanRight(sMatriz*);
	bool colisaoPacmanLeft(sMatriz*);

    float getPacmanX();
    float getPacmanY();

    void setPacmanX(float);
    void setPacmanY(float);

	void movimentacaoPacman(int, sMatriz*);
	void execusaoMovPacman(sMatriz*);

	void desenhaPacman(int);

	~Pacman();

private:
	ALLEGRO_BITMAP* pacman;

    int placar;

	//Variaveis de Tamanho da Sprite
	int pacman_altura;
	int pacman_largura;

	//Variaveis de Direção
	bool top;
	bool right;
	bool bottom;
	bool left;
	int lado;

};
#endif