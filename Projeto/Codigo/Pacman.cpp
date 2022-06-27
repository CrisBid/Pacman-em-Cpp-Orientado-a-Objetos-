#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include "Pacman.h"

using namespace std;

Pacman::Pacman()
{

    pacman = NULL;

    pacman_x = 160;
    pacman_y = 60;

    pacman_altura = 30;
    pacman_largura = 30;

    placar = 0;

    //Posição do player
    colisaoYPlayer = 0;
    colisaoXPlayer = 0;

    //Colisão Cima
    colisaoYC = 0;
    colisaoXC = 0;
    colisaoYCN = 0;
    colisaoXCN = 0;

    //Colisão Esquerda
    colisaoYE = 0;
    colisaoXE = 0;
    colisaoYEN = 0;
    colisaoXEN = 0;

    //Colisão Direita
    colisaoYD = 0;
    colisaoXD = 0;
    colisaoYDN = 0;
    colisaoXDN = 0;

    //Colisão Baixo
    colisaoXB = 0;
    colisaoYB = 0;
    colisaoXBN = 0;
    colisaoYBN = 0;

}

void Pacman::posicaoPacman() {

    //Posi��o Player
    colisaoYPlayer = ((pacman_y - 40) / 10);
    colisaoXPlayer = ((pacman_x - 140) / 10);

    //Colis�o Cima
    colisaoYC = ceil(((pacman_y - 40) / 10));
    colisaoXC = ((pacman_x - 140) / 10);
    colisaoYCN = ceil(((pacman_y - 40) / 10));
    colisaoXCN = ceil(((pacman_x - 140) / 10));

    //Colis�o Esquerda
    colisaoYE = ceil(((pacman_y - 40) / 10));
    colisaoXE = ceil(((pacman_x - 140) / 10));
    colisaoYEN = ((pacman_y - 40) / 10);
    colisaoXEN = ceil(((pacman_x - 140) / 10));

    //Colis�o Direita
    colisaoYD = ceil(((pacman_y - 40) / 10));
    colisaoXD = ((pacman_x - 140) / 10);
    colisaoYDN = ((pacman_y - 40) / 10);
    colisaoXDN = ((pacman_x - 140) / 10);

    //Colis�o Baixo
    colisaoYB = (((pacman_y - 40) / 10));
    colisaoXB = ceil(((pacman_x - 140) / 10));
    colisaoYBN = (((pacman_y - 40) / 10));
    colisaoXBN = (((pacman_x - 140) / 10));

}

bool Pacman::colisaoPacman(sMatriz *matriz) {
    if (matriz->dados_matriz[colisaoYPlayer][colisaoXPlayer] != 1)
    {

        cout << colisaoYPlayer << " ";
        cout << colisaoXPlayer << endl;
        if (matriz->dados_matriz[colisaoYPlayer + 1][colisaoXPlayer + 1] != 1)
        {
            if (matriz->dados_matriz[colisaoYPlayer][colisaoXPlayer + 1] != 1)
            {
                if (matriz->dados_matriz[colisaoYPlayer + 1][colisaoXPlayer] != 1)
                {
                    if (matriz->dados_matriz[colisaoYPlayer][colisaoXPlayer - 1] != 1)
                    {
                        if (matriz->dados_matriz[colisaoYPlayer - 1][colisaoXPlayer] != 1)
                        {
                            if (matriz->dados_matriz[colisaoYPlayer + 1][colisaoXPlayer - 1] != 1)
                            {
                                if (matriz->dados_matriz[colisaoYPlayer - 1][colisaoXPlayer - 1] != 1)
                                {
                                    if (matriz->dados_matriz[colisaoYPlayer - 1][colisaoXPlayer + 1] != 1)
                                    {
                                        return true;
                                    }
                                    else
                                    {
                                        return false; 
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false; 
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        } 
    }
    else
    {
        return false;
    }
}
void Pacman::colisaoPacmanPirula(sMatriz* matriz) {
    if (matriz->dados_matriz[colisaoYPlayer][colisaoXPlayer] == 2)
    {
        matriz->dados_matriz[colisaoYPlayer][colisaoXPlayer] = 16;
        placar++;
    }
    if (matriz->dados_matriz[colisaoYPlayer + 1][colisaoXPlayer + 1] == 2)
    {
        matriz->dados_matriz[colisaoYPlayer + 1][colisaoXPlayer + 1] = 16;
        placar++;
    }
    if (matriz->dados_matriz[colisaoYPlayer][colisaoXPlayer + 1] == 2)
    {
        matriz->dados_matriz[colisaoYPlayer][colisaoXPlayer + 1] = 16;
        placar++;
    }
    if (matriz->dados_matriz[colisaoYPlayer + 1][colisaoXPlayer] == 2)
    {
        matriz->dados_matriz[colisaoYPlayer + 1][colisaoXPlayer] = 16;
        placar++;

    }
    if (matriz->dados_matriz[colisaoYPlayer][colisaoXPlayer - 1] == 2)
    {
        matriz->dados_matriz[colisaoYPlayer][colisaoXPlayer - 1] = 16;
        placar++;
    }
    if (matriz->dados_matriz[colisaoYPlayer - 1][colisaoXPlayer] == 2)
    {
        matriz->dados_matriz[colisaoYPlayer - 1][colisaoXPlayer] = 16;
        placar++;
    }
    if (matriz->dados_matriz[colisaoYPlayer + 1][colisaoXPlayer - 1] == 2)
    {
        matriz->dados_matriz[colisaoYPlayer + 1][colisaoXPlayer - 1] = 16;
        placar++;
    }
    if (matriz->dados_matriz[colisaoYPlayer - 1][colisaoXPlayer - 1] == 2)
    {
        matriz->dados_matriz[colisaoYPlayer - 1][colisaoXPlayer - 1] = 16;
        placar++;
    }
    if (matriz->dados_matriz[colisaoYPlayer - 1][colisaoXPlayer + 1] == 2)
    {
        matriz->dados_matriz[colisaoYPlayer - 1][colisaoXPlayer + 1] = 16;
        placar++;
    }
}

int Pacman::getAtualPlacar() {
    return placar;
}

bool Pacman::colisaoPacmanTop(sMatriz* matriz) {
    if (matriz->dados_matriz[colisaoYC - 2][colisaoXC - 1] != 1 && matriz->dados_matriz[colisaoYCN - 2][colisaoXCN - 1] != 1)
    {
        if (matriz->dados_matriz[colisaoYC - 2][colisaoXC] != 1 && matriz->dados_matriz[colisaoYCN - 2][colisaoXCN] != 1)
        {
            if (matriz->dados_matriz[colisaoYC - 2][colisaoXC + 1] != 1 && matriz->dados_matriz[colisaoYCN - 2][colisaoXCN + 1] != 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool Pacman::colisaoPacmanBottom(sMatriz* matriz) {
    if (matriz->dados_matriz[colisaoYB + 2][colisaoXB - 1] != 1 && matriz->dados_matriz[colisaoYBN + 2][colisaoXBN - 1] != 1)
    {
        if (matriz->dados_matriz[colisaoYB + 2][colisaoXB] != 1 && matriz->dados_matriz[colisaoYBN + 2][colisaoXBN] != 1)
        {
            if (matriz->dados_matriz[colisaoYB + 2][colisaoXB + 1] != 1 && matriz->dados_matriz[colisaoYBN + 2][colisaoXBN + 1] != 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool Pacman::colisaoPacmanRight(sMatriz* matriz) {
    if (matriz->dados_matriz[colisaoYD][colisaoXD + 2] != 1 && matriz->dados_matriz[colisaoYDN][colisaoXDN + 2] != 1)
    {
        if (matriz->dados_matriz[colisaoYD - 1][colisaoXD + 2] != 1 && matriz->dados_matriz[colisaoYDN - 1][colisaoXDN + 2] != 1)
        {
            if (matriz->dados_matriz[colisaoYD + 1][colisaoXD + 2] != 1 && matriz->dados_matriz[colisaoYDN + 1][colisaoXDN + 2] != 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool Pacman::colisaoPacmanLeft(sMatriz* matriz) {

    if (matriz->dados_matriz[colisaoYE][colisaoXE - 2] != 1 && matriz->dados_matriz[colisaoYEN][colisaoXEN - 2] != 1)
    {
        if (matriz->dados_matriz[colisaoYE - 1][colisaoXE - 2] != 1 && matriz->dados_matriz[colisaoYEN - 1][colisaoXEN - 2] != 1)
        {
            if (matriz->dados_matriz[colisaoYE + 1][colisaoXE - 2] != 1 && matriz->dados_matriz[colisaoYEN + 1][colisaoXEN - 2] != 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

float Pacman::getPacmanX() {
    return pacman_x;
}
float Pacman::getPacmanY() {
    return pacman_y;
}
void Pacman::setPacmanX(float x) {
    pacman_x = x;
}
void Pacman::setPacmanY(float y) {
    pacman_y = y;
}

void Pacman::desenhaPacman(int lado, int sprite) {
    pacman = al_load_bitmap("Images/Poro/PacmanSprite.png");

    al_draw_bitmap_region(pacman, lado * pacman_largura, sprite * pacman_altura, pacman_largura, pacman_altura, pacman_x, pacman_y, 0);
}

ALLEGRO_BITMAP* Pacman::getPacman() {
    return pacman;
}

Pacman::~Pacman()
{
	al_destroy_bitmap(pacman); //Destroi a tela
}

