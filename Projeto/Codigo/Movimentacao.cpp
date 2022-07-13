#include "Movimentacao.h"
#include <math.h>

Movimentacao::Movimentacao()
{
    //Posiçao do player em Px
    Player_x = 160;
    Player_y = 60;

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

Movimentacao::Movimentacao(int x, int y)
{
    //Posiçao do player em Px
    Player_x = x;
    Player_y = y;

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

int Movimentacao::getColisaoPlayerX() {
    return colisaoXPlayer;
}
int Movimentacao::getColisaoPlayerY() {
    return colisaoYPlayer;
}

float Movimentacao::getPlayerX() {
    return Player_x;
}
float Movimentacao::getPlayerY() {
    return Player_y;
}
void Movimentacao::setPlayerX(float x) {
    Player_x = x;
}
void Movimentacao::setPlayerY(float y) {
    Player_y = y;
}

void Movimentacao::posicaoPlayer() {

    //Posi��o Player
    colisaoYPlayer = ((Player_y - 40) / 10);
    colisaoXPlayer = ((Player_x - 140) / 10);

    //Colis�o Cima
    colisaoYC = ceil(((Player_y - 40) / 10));
    colisaoXC = ((Player_x - 140) / 10);
    colisaoYCN = ceil(((Player_y - 40) / 10));
    colisaoXCN = ceil(((Player_x - 140) / 10));

    //Colis�o Esquerda
    colisaoYE = ceil(((Player_y - 40) / 10));
    colisaoXE = ceil(((Player_x - 140) / 10));
    colisaoYEN = ((Player_y - 40) / 10);
    colisaoXEN = ceil(((Player_x - 140) / 10));

    //Colis�o Direita
    colisaoYD = ceil(((Player_y - 40) / 10));
    colisaoXD = ((Player_x - 140) / 10);
    colisaoYDN = ((Player_y - 40) / 10);
    colisaoXDN = ((Player_x - 140) / 10);

    //Colis�o Baixo
    colisaoYB = (((Player_y - 40) / 10));
    colisaoXB = ceil(((Player_x - 140) / 10));
    colisaoYBN = (((Player_y - 40) / 10));
    colisaoXBN = (((Player_x - 140) / 10));

}

bool Movimentacao::colisaoPlayer(sMatriz* matriz) {
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


bool Movimentacao::colisaoPlayerTop(sMatriz* matriz) {
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
bool Movimentacao::colisaoPlayerBottom(sMatriz* matriz) {
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
bool Movimentacao::colisaoPlayerRight(sMatriz* matriz) {
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
bool Movimentacao::colisaoPlayerLeft(sMatriz* matriz) {

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

Movimentacao::~Movimentacao()
{
}