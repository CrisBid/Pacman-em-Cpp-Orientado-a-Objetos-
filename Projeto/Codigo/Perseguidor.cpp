#include "Perseguidor.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include<time.h>

using namespace std;

Perseguidor::Perseguidor()
{
    inimigo = NULL;

    //Altura e Largura da Sprite
    inimigos_altura = 30;
    inimigos_largura = 30;

    //Variaveis de Dire��o
    top = false;
    right = false;
    bottom = false;
    left = false;
    lado = 0;

    //Variaveis de Randomiza��o

    for (size_t i = 0; i < 2; i++)
    {
        opcao3[i] = 0;
    }

    aleatorio2 = 0;
    aleatorio3 = 0;

    Instrucao = 0;

    bufferX = 0.0;
    bufferY = 0.0;

}

Perseguidor::Perseguidor(int x, int y) :Inimigos(x, y)
{
    inimigo = NULL;

    //Altura e Largura da Sprite
    inimigos_altura = 30;
    inimigos_largura = 30;

    //Variaveis de Dire��o
    top = false;
    right = false;
    bottom = false;
    left = false;
    lado = 0;

    //Variaveis de Randomiza��o

    for (size_t i = 0; i < 2; i++)
    {
        opcao3[i] = 0;
    }

    aleatorio2 = 0;
    aleatorio3 = 0;

    Instrucao = 0;

    bufferX = 0.0;
    bufferY = 0.0;

}

void Perseguidor::posicaoInimigos() {
    Inimigos::posicaoPlayer();
}

bool Perseguidor::colisaoInimigos(sMatriz* matriz) {
    return Inimigos::colisaoPlayer(matriz);
}

bool Perseguidor::colisaoInimigosTop(sMatriz* matriz) {
    return Inimigos::colisaoPlayerTop(matriz);
}
bool Perseguidor::colisaoInimigosBottom(sMatriz* matriz) {
    return Inimigos::colisaoPlayerBottom(matriz);
}
bool Perseguidor::colisaoInimigosRight(sMatriz* matriz) {
    return Inimigos::colisaoPlayerRight(matriz);
}
bool Perseguidor::colisaoInimigosLeft(sMatriz* matriz) {
    return Inimigos::colisaoPlayerLeft(matriz);
}

float Perseguidor::getInimigosX() {
    return Inimigos::getPlayerX();
}
float Perseguidor::getInimigosY() {
    return Inimigos::getPlayerY();
}
void Perseguidor::setInimigosX(float x) {
    Inimigos::setPlayerX(x);
}
void Perseguidor::setInimigosY(float y) {
    Inimigos::setPlayerY(y);
}

void Perseguidor::sorteioDirecao(sMatriz* matriz, float pacX, float pacY) {

    int distanciaPacX;
    int distanciaPacY;

    int direcoes[] = { ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT ,ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN };

    distanciaPacX = pacX - getInimigosX();
    distanciaPacY = pacY - getInimigosY();

    if (distanciaPacX < distanciaPacY)
    {
        if (distanciaPacX > 0)
        {
            Instrucao = direcoes[1];
            //cout << "Indo pra Direira" << endl;
        }
        else if (distanciaPacX >= 0)
        {
            if (distanciaPacY >= 0)
            {
                Instrucao = direcoes[3];
                //cout << "Indo pra Baixo" << endl;
            }
            else
            {
                Instrucao = direcoes[2];
                //cout << "Indo pra Cima" << endl;
            }
        }
        else
        {
            Instrucao = direcoes[0];
            //cout << "Indo pra Esquerda" << endl;
        }
    }
    else
    {
        if (distanciaPacY > 0)
        {
            Instrucao = direcoes[3];
            //cout << "Indo pra Baixo" << endl;
        }
        else if (distanciaPacY == 0)
        {
            if (distanciaPacX >= 0)
            {
                Instrucao = direcoes[1];
                //cout << "Indo pra Direira" << endl;
            }
            else
            {
                Instrucao = direcoes[0];
                //cout << "Indo pra Esquerda" << endl;
            }
        }
        else
        {
            Instrucao = direcoes[2];
            //cout << "Indo pra Cima" << endl;
        }
    }


    if (bufferX == getInimigosX() && bufferY == getInimigosY())
    {
        int flag = 0;
        int posibilidades = 0;

        int direcoes[4];

        for (int i = 0; i < 4; i++)
        {
            direcoes[i] = 0;
        }

        if (left == true)
        {

            //Left
            if (colisaoInimigosLeft(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
                posibilidades++;
            }
            //Top
            if (colisaoInimigosTop(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_UP;
                posibilidades++;
            }
            //Botton
            if (colisaoInimigosBottom(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
                posibilidades++;
            }

            srand(time(NULL));

            if (posibilidades > 0)
            {
                flag = rand() % posibilidades;

                Instrucao = direcoes[flag];
            }

        }

        else if (right == true)
        {

            //Right
            if (colisaoInimigosRight(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
                posibilidades++;
            }
            //Top
            if (colisaoInimigosTop(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_UP;
                posibilidades++;
            }
            //Botton
            if (colisaoInimigosBottom(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
                posibilidades++;
            }

            srand(time(NULL));

            if (posibilidades > 0)
            {
                flag = rand() % posibilidades;

                Instrucao = direcoes[flag];
            }

        }

        else if (top == true)
        {

            //Left
            if (colisaoInimigosLeft(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
                posibilidades++;
            }
            //Right
            if (colisaoInimigosRight(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
                posibilidades++;
            }
            //Top
            if (colisaoInimigosTop(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_UP;
                posibilidades++;
            }

            srand(time(NULL));

            if (posibilidades > 0)
            {
                flag = rand() % posibilidades;

                Instrucao = direcoes[flag];
            }

        }

        else if (bottom == true)
        {

            //Left
            if (colisaoInimigosLeft(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
                posibilidades++;
            }
            //Right
            if (colisaoInimigosRight(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
                posibilidades++;
            }
            //Botton
            if (colisaoInimigosBottom(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
                posibilidades++;
            }

            srand(time(NULL));

            if (posibilidades > 0)
            {
                flag = rand() % posibilidades;

                Instrucao = direcoes[flag];
            }

        }

        else
        {
            //Left
            if (colisaoInimigosLeft(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
                posibilidades++;
            }
            //Right
            if (colisaoInimigosRight(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
                posibilidades++;
            }
            //Top
            if (colisaoInimigosTop(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_UP;
                posibilidades++;
            }
            //Botton
            if (colisaoInimigosBottom(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
                posibilidades++;
            }

            srand(time(NULL));

            if (posibilidades > 0)
            {
                flag = rand() % posibilidades;

                Instrucao = direcoes[flag];
            }


        }
    }

    bufferX = getInimigosX();

    bufferY = getInimigosY();

}

void Perseguidor::movimentacaoInimigos(sMatriz* matriz) {
    //Verifica se o camando pode ser executado e define as variaveis para que isso aconte�a

    //Top
    if (Instrucao == ALLEGRO_KEY_UP && colisaoInimigosTop(matriz) == true && bottom != true)
    {
        top = true;
        bottom = false;
        left = false;
        right = false;
        lado = 2;
    }
    //Bottom
    if (Instrucao == ALLEGRO_KEY_DOWN && colisaoInimigosBottom(matriz) == true && top != true)
    {
        bottom = true;
        top = false;
        left = false;
        right = false;
        lado = 3;
    }
    //Left
    if (Instrucao == ALLEGRO_KEY_LEFT && colisaoInimigosLeft(matriz) == true && right != true)
    {
        left = true;
        top = false;
        bottom = false;
        right = false;
        lado = 1;
    }
    //Right
    if (Instrucao == ALLEGRO_KEY_RIGHT && colisaoInimigosRight(matriz) == true && left != true)
    {
        right = true;
        top = false;
        bottom = false;
        left = false;
        lado = 0;
    }
}

void Perseguidor::execusaoMovInimigos(sMatriz* matriz, bool status) {

    if (status == false)
    {
        //Executa a movimenta��o

        if (top == true && colisaoInimigosTop(matriz) == true) { //Movimeta��o para Cima
            setInimigosY(getInimigosY() - 2.0);
            //darth_y -= 2.0;
        }

        if (bottom == true && colisaoInimigosBottom(matriz) == true) { //Movimenta��o para Baixo
            setInimigosY(getInimigosY() + 2.0);
            //darth_y += 2.0;
        }

        if (left == true && colisaoInimigosLeft(matriz) == true) { //Movimenta��o para Esquerda
            setInimigosX(getInimigosX() - 2.0);
            //darth_x -= 2.0;
        }

        if (right == true && colisaoInimigosRight(matriz) == true) { //Movimenta��o para Direita
            setInimigosX(getInimigosX() + 2.0);
            //darth_x += 2.0;
        }
    }
}

void Perseguidor::desenhaInimigos(int sprite, int tipo) {
    inimigo = al_load_bitmap("Images/Teemo/TeemoSprite.png");

    al_draw_bitmap_region(inimigo, tipo * inimigos_largura, 0 * inimigos_altura, inimigos_largura, inimigos_altura, Inimigos::getPlayerX(), Inimigos::getPlayerY(), 0);
}

ALLEGRO_BITMAP* Perseguidor::getInimigos() {
    return inimigo;
}

void Perseguidor::Destrutor()
{
    al_destroy_bitmap(inimigo); //Destroi a tela
}

Perseguidor::~Perseguidor()
{
    al_destroy_bitmap(inimigo); //Destroi a tela
}

