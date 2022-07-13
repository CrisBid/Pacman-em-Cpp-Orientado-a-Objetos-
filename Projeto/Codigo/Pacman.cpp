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

    placar = 0;

    //Altura e Largura da Sprite
    pacman_altura = 30;
    pacman_largura = 30;

    //Variaveis de Direção
    top = false;
    right = false;
    bottom = false;
    left = false;
    lado = 0;

}

Pacman::Pacman(int x, int y):Movimentacao(x, y)
{
    pacman = NULL;

    placar = 0;

    //Altura e Largura da Sprite
    pacman_altura = 30;
    pacman_largura = 30;

    //Variaveis de Direção
    top = false;
    right = false;
    bottom = false;
    left = false;
    lado = 0;

}

void Pacman::posicaoPacman() {
    Movimentacao::posicaoPlayer();
}

bool Pacman::colisaoPacman(sMatriz *matriz) {
    return Movimentacao::colisaoPlayer(matriz);
}
void Pacman::colisaoPacmanPirula(sMatriz* matriz) {
    if (matriz->dados_matriz[Movimentacao::getColisaoPlayerY()][Movimentacao::getColisaoPlayerX()] == 2)
    {
        matriz->dados_matriz[Movimentacao::getColisaoPlayerY()][Movimentacao::getColisaoPlayerX()] = 16;
        placar++;
    }
    if (matriz->dados_matriz[Movimentacao::getColisaoPlayerY() + 1][Movimentacao::getColisaoPlayerX() + 1] == 2)
    {
        matriz->dados_matriz[Movimentacao::getColisaoPlayerY() + 1][Movimentacao::getColisaoPlayerX() + 1] = 16;
        placar++;
    }
    if (matriz->dados_matriz[Movimentacao::getColisaoPlayerY()][Movimentacao::getColisaoPlayerX() + 1] == 2)
    {
        matriz->dados_matriz[Movimentacao::getColisaoPlayerY()][Movimentacao::getColisaoPlayerX() + 1] = 16;
        placar++;
    }
    if (matriz->dados_matriz[Movimentacao::getColisaoPlayerY() + 1][Movimentacao::getColisaoPlayerX()] == 2)
    {
        matriz->dados_matriz[Movimentacao::getColisaoPlayerY() + 1][Movimentacao::getColisaoPlayerX()] = 16;
        placar++;
    }
    if (matriz->dados_matriz[Movimentacao::getColisaoPlayerY()][Movimentacao::getColisaoPlayerX() - 1] == 2)
    {
        matriz->dados_matriz[Movimentacao::getColisaoPlayerY()][Movimentacao::getColisaoPlayerX() - 1] = 16;
        placar++;
    }
    if (matriz->dados_matriz[Movimentacao::getColisaoPlayerY() - 1][Movimentacao::getColisaoPlayerX()] == 2)
    {
        matriz->dados_matriz[Movimentacao::getColisaoPlayerY() - 1][Movimentacao::getColisaoPlayerX()] = 16;
        placar++;
    }
    if (matriz->dados_matriz[Movimentacao::getColisaoPlayerY() + 1][Movimentacao::getColisaoPlayerX() - 1] == 2)
    {
        matriz->dados_matriz[Movimentacao::getColisaoPlayerY() + 1][Movimentacao::getColisaoPlayerX() - 1] = 16;
        placar++;
    }
    if (matriz->dados_matriz[Movimentacao::getColisaoPlayerY() - 1][Movimentacao::getColisaoPlayerX() - 1] == 2)
    {
        matriz->dados_matriz[Movimentacao::getColisaoPlayerY() - 1][Movimentacao::getColisaoPlayerX() - 1] = 16;
        placar++;
    }
    if (matriz->dados_matriz[Movimentacao::getColisaoPlayerY() - 1][Movimentacao::getColisaoPlayerX() + 1] == 2)
    {
        matriz->dados_matriz[Movimentacao::getColisaoPlayerY() - 1][Movimentacao::getColisaoPlayerX() + 1] = 16;
        placar++;
    }
}

int Pacman::getAtualPlacar() {
    return placar;
}

bool Pacman::colisaoPacmanTop(sMatriz* matriz) {
    return Movimentacao::colisaoPlayerTop(matriz);
}
bool Pacman::colisaoPacmanBottom(sMatriz* matriz) {
    return Movimentacao::colisaoPlayerBottom(matriz);
}
bool Pacman::colisaoPacmanRight(sMatriz* matriz) {
    return Movimentacao::colisaoPlayerRight(matriz);
}
bool Pacman::colisaoPacmanLeft(sMatriz* matriz) {
    return Movimentacao::colisaoPlayerLeft(matriz);
}

float Pacman::getPacmanX() {
    return Movimentacao::getPlayerX();
}
float Pacman::getPacmanY() {
    return Movimentacao::getPlayerY();
}
void Pacman::setPacmanX(float x) {
    Movimentacao::setPlayerX(x);
}
void Pacman::setPacmanY(float y) {
    Movimentacao::setPlayerY(y);
}

void Pacman::movimentacaoPacman(int Instrucao, sMatriz* matriz) {
    //Verifica se o camando pode ser executado e define as variaveis para que isso aconteça

    //Top
    if (Instrucao == ALLEGRO_KEY_UP && colisaoPacmanTop(matriz) == true)
    {
        top = true;
        bottom = false;
        left = false;
        right = false;
        lado = 2;
    }
    //Bottom
    if (Instrucao == ALLEGRO_KEY_DOWN && colisaoPacmanBottom(matriz) == true)
    {
        bottom = true;
        top = false;
        left = false;
        right = false;
        lado = 3;
    }
    //Left
    if (Instrucao == ALLEGRO_KEY_LEFT && colisaoPacmanLeft(matriz) == true)
    {
        left = true;
        top = false;
        bottom = false;
        right = false;
        lado = 1;
    }
    //Right
    if (Instrucao == ALLEGRO_KEY_RIGHT && colisaoPacmanRight(matriz) == true)
    {
        right = true;
        top = false;
        bottom = false;
        left = false;
        lado = 0;
    }
}

void Pacman::execusaoMovPacman(sMatriz* matriz) {


    //Executa a movimentação

    if (top == true && colisaoPacmanTop(matriz) == true) { //Movimetação para Cima
        setPacmanY(getPacmanY() - 2.0);
        //darth_y -= 2.0;
    }

    if (bottom == true && colisaoPacmanBottom(matriz) == true) { //Movimentação para Baixo
        setPacmanY(getPacmanY() + 2.0);
        //darth_y += 2.0;
    }

    if (left == true && colisaoPacmanLeft(matriz) == true) { //Movimentação para Esquerda
        setPacmanX(getPacmanX() - 2.0);
        //darth_x -= 2.0;
    }

    if (right == true && colisaoPacmanRight(matriz) == true) { //Movimentação para Direita
        setPacmanX(getPacmanX() + 2.0);
        //darth_x += 2.0;
    }
}

void Pacman::desenhaPacman(int sprite) {
    pacman = al_load_bitmap("Images/Poro/PacmanSprite.png");

    al_draw_bitmap_region(pacman, lado * pacman_largura, sprite * pacman_altura, pacman_largura, pacman_altura, Movimentacao::getPlayerX(), Movimentacao::getPlayerY(), 0);
}

ALLEGRO_BITMAP* Pacman::getPacman() {
    return pacman;
}

Pacman::~Pacman()
{
	al_destroy_bitmap(pacman); //Destroi a tela
}

