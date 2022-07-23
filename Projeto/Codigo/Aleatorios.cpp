#include "Aleatorios.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include<time.h>

using namespace std;

Aleatorios::Aleatorios()
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

}

Aleatorios::Aleatorios(int x, int y) :Inimigos(x, y)
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


}

void Aleatorios::posicaoInimigos() {
    Inimigos::posicaoPlayer();
}

bool Aleatorios::colisaoInimigos(sMatriz* matriz) {
    return Inimigos::colisaoPlayer(matriz);
}

bool Aleatorios::colisaoInimigosTop(sMatriz* matriz) {
    return Inimigos::colisaoPlayerTop(matriz);
}
bool Aleatorios::colisaoInimigosBottom(sMatriz* matriz) {
    return Inimigos::colisaoPlayerBottom(matriz);
}
bool Aleatorios::colisaoInimigosRight(sMatriz* matriz) {
    return Inimigos::colisaoPlayerRight(matriz);
}
bool Aleatorios::colisaoInimigosLeft(sMatriz* matriz) {
    return Inimigos::colisaoPlayerLeft(matriz);
}

float Aleatorios::getInimigosX() {
    return Inimigos::getPlayerX();
}
float Aleatorios::getInimigosY() {
    return Inimigos::getPlayerY();
}
void Aleatorios::setInimigosX(float x) {
    Inimigos::setPlayerX(x);
}
void Aleatorios::setInimigosY(float y) {
    Inimigos::setPlayerY(y);
}

void Aleatorios::sorteioDirecao(sMatriz* matriz, float pacX, float pacY) {
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

    int flag = 0;

    int direcoes[] = { ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT ,ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN };

    srand(time(NULL));

    flag = rand() % 4;

    Instrucao = direcoes[flag];

}

void Aleatorios::movimentacaoInimigos(sMatriz* matriz) {
    //Verifica se o camando pode ser executado e define as variaveis para que isso aconte�a

    //Top
    if (Instrucao == ALLEGRO_KEY_UP && colisaoInimigosTop(matriz) == true && bottom != true && top != true)
    {
        top = true;
        bottom = false;
        left = false;
        right = false;
        lado = 2;
    }
    //Bottom
    if (Instrucao == ALLEGRO_KEY_DOWN && colisaoInimigosBottom(matriz) == true && top != true && bottom != true)
    {
        bottom = true;
        top = false;
        left = false;
        right = false;
        lado = 3;
    }
    //Left
    if (Instrucao == ALLEGRO_KEY_LEFT && colisaoInimigosLeft(matriz) == true && right != true && left != true)
    {
        left = true;
        top = false;
        bottom = false;
        right = false;
        lado = 1;
    }
    //Right
    if (Instrucao == ALLEGRO_KEY_RIGHT && colisaoInimigosRight(matriz) == true && left != true && right != true)
    {
        right = true;
        top = false;
        bottom = false;
        left = false;
        lado = 0;
    }
}

void Aleatorios::execusaoMovInimigos(sMatriz* matriz) {


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

void Aleatorios::desenhaInimigos(int sprite, int tipo) {
    inimigo = al_load_bitmap("Images/Teemo/TeemoSprite.png");

    al_draw_bitmap_region(inimigo, tipo * inimigos_largura, 0 * inimigos_altura, inimigos_largura, inimigos_altura, Inimigos::getPlayerX(), Inimigos::getPlayerY(), 0);
}

ALLEGRO_BITMAP* Aleatorios::getInimigos() {
    return inimigo;
}

void Aleatorios::Destrutor()
{
    al_destroy_bitmap(inimigo); //Destroi a tela
}


Aleatorios::~Aleatorios()
{
    al_destroy_bitmap(inimigo); //Destroi a tela
}

