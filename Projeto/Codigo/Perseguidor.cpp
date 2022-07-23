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
    /*
    if (colisaoInimigosTop(matriz) == true)
    {
        if (opcao3[0] == 0 && opcao3[0] != ALLEGRO_KEY_UP)
        {
            opcao3[0] =  ALLEGRO_KEY_UP;
        }
        else if (opcao3[1] == 0 && opcao3[0] != ALLEGRO_KEY_UP)
        {
            opcao3[1] = ALLEGRO_KEY_UP;
        }
        else if (opcao3[2] == 0 && opcao3[0] != ALLEGRO_KEY_UP)
        {
            opcao3[2] = ALLEGRO_KEY_UP;
        }
    }
    //Bottom
    if (colisaoInimigosBottom(matriz) == true)
    {
        if (opcao3[0] == 0 && opcao3[0] != ALLEGRO_KEY_DOWN)
        {
            opcao3[0] = ALLEGRO_KEY_DOWN;
        }
        else if (opcao3[1] == 0 && opcao3[0] != ALLEGRO_KEY_DOWN)
        {
            opcao3[1] = ALLEGRO_KEY_DOWN;
        }
        else if (opcao3[2] == 0 && opcao3[0] != ALLEGRO_KEY_DOWN)
        {
            opcao3[2] = ALLEGRO_KEY_DOWN;
        }
    }
    //Left
    if (colisaoInimigosLeft(matriz) == true)
    {
        if (opcao3[0] == 0 && opcao3[0] != ALLEGRO_KEY_LEFT)
        {
            opcao3[0] = ALLEGRO_KEY_LEFT;
        }
        else if (opcao3[1] == 0 && opcao3[0] != ALLEGRO_KEY_LEFT)
        {
            opcao3[1] = ALLEGRO_KEY_LEFT;
        }
        else if (opcao3[2] == 0 && opcao3[0] != ALLEGRO_KEY_LEFT)
        {
            opcao3[2] = ALLEGRO_KEY_LEFT;
        }
    }
    //Right
    if (colisaoInimigosRight(matriz) == true)
    {
        if (opcao3[0] == 0 && opcao3[0] != ALLEGRO_KEY_RIGHT)
        {
            opcao3[0] = ALLEGRO_KEY_RIGHT;
        }
        else if (opcao3[1] == 0 && opcao3[0] != ALLEGRO_KEY_RIGHT)
        {
            opcao3[1] = ALLEGRO_KEY_RIGHT;
        }
        else if (opcao3[2] == 0 && opcao3[0] != ALLEGRO_KEY_RIGHT)
        {
            opcao3[2] = ALLEGRO_KEY_RIGHT;
        }
    }
    cout << opcao3[0] << opcao3[1] << opcao3[2] << endl;
    */

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
            cout << "Indo pra Direira" << endl;
        }
        else if (distanciaPacX >= 0)
        {
            if (distanciaPacY >= 0)
            {
                Instrucao = direcoes[3];
                cout << "Indo pra Baixo" << endl;
            }
            else
            {
                Instrucao = direcoes[2];
                cout << "Indo pra Cima" << endl;
            }
        }
        else
        {
            Instrucao = direcoes[0];
            cout << "Indo pra Esquerda" << endl;
        }
    }
    else
    {
        if (distanciaPacY > 0)
        {
            Instrucao = direcoes[3];
            cout << "Indo pra Baixo" << endl;
        }
        else if (distanciaPacY == 0)
        {
            if (distanciaPacX >= 0)
            {
                Instrucao = direcoes[1];
                cout << "Indo pra Direira" << endl;
            }
            else
            {
                Instrucao = direcoes[0];
                cout << "Indo pra Esquerda" << endl;
            }
        }
        else
        {
            Instrucao = direcoes[2];
            cout << "Indo pra Cima" << endl;
        }
    }


    if (bufferX == getInimigosX() && bufferY == getInimigosY())
    {
        int flag = 0;

        srand(time(NULL));

        flag = rand() % 4;

        Instrucao = direcoes[flag];

        cout << "X" << bufferX << endl;
        cout << "Y" << bufferY << endl;
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

void Perseguidor::execusaoMovInimigos(sMatriz* matriz) {


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

