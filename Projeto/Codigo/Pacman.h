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

    //Posi��o do player
    int colisaoYPlayer;
    int colisaoXPlayer;

    //Colis�o Cima
    int colisaoYC;
    int colisaoXC;
    int colisaoYCN;
    int colisaoXCN;

    //Colis�o Esquerda
    int colisaoYE;
    int colisaoXE;
    int colisaoYEN;
    int colisaoXEN;

    //Colis�o Direita
    int colisaoYD;
    int colisaoXD;
    int colisaoYDN;
    int colisaoXDN;

    //Colis�o Baixo
    int colisaoXB;
    int colisaoYB;
    int colisaoXBN;
    int colisaoYBN;

};
#endif