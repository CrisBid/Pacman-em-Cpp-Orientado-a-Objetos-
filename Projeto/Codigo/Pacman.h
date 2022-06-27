#include <iostream>

#include "StructMatriz.h"

#include <allegro5/allegro5.h>

#ifndef PACMAN_H
#define PACMAN_H

using namespace std;

class Pacman
{
public:
	Pacman();

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

	void desenhaPacman(int, int);

	~Pacman();

private:
	ALLEGRO_BITMAP* pacman;

    float pacman_x;
    float pacman_y;

    int pacman_altura;
    int pacman_largura;

    int placar;

    //Posição do player
    int colisaoYPlayer;
    int colisaoXPlayer;

    //Colisão Cima
    int colisaoYC;
    int colisaoXC;
    int colisaoYCN;
    int colisaoXCN;

    //Colisão Esquerda
    int colisaoYE;
    int colisaoXE;
    int colisaoYEN;
    int colisaoXEN;

    //Colisão Direita
    int colisaoYD;
    int colisaoXD;
    int colisaoYDN;
    int colisaoXDN;

    //Colisão Baixo
    int colisaoXB;
    int colisaoYB;
    int colisaoXBN;
    int colisaoYBN;

};
#endif