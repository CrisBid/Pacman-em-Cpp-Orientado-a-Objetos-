#include "StructMatriz.h"

#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

class Movimentacao
{
public:
	Movimentacao();
    Movimentacao(int, int);

    float getPlayerX();
    float getPlayerY();

    void setPlayerX(float x);
    void setPlayerY(float y);

    void posicaoPlayer();

    int getColisaoPlayerX();
    int getColisaoPlayerY();

    bool colisaoPlayer(sMatriz*);

    bool colisaoPlayerTop(sMatriz*);
    bool colisaoPlayerBottom(sMatriz*);
    bool colisaoPlayerRight(sMatriz*);
    bool colisaoPlayerLeft(sMatriz*);

	~Movimentacao();

private:
    //Variaveis de posicao em Px
    float Player_x;
    float Player_y;

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

