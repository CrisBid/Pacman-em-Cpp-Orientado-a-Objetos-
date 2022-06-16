#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include "Matriz.h"



Matriz::Matriz()
{
	//Inicialização Altura/Largura da matriz
	ptrmatriz.matriz_altura = 64;
	ptrmatriz.matriz_largura = 66;

	//Inicialização da matriz
	for (int i = 0; i < ptrmatriz.matriz_altura; i++)
	{
		for (int j = 0; j < ptrmatriz.matriz_largura; j++)
		{
			ptrmatriz.dados_matriz[i][j] = 0;
		}
	}

	//Inicialização do arquivo
	inFile.open("Arquivos/Mapa.txt", ios::in); // abre o arquivo para leitura
	if (!inFile) //Verifica se o arquivo foi aberto
	{
		cout << "Arquivo nao pode ser aberto" << endl;
		abort();
	}
}

sMatriz Matriz::getMatriz() {
	return ptrmatriz;
}
void Matriz::loadFileMatriz() {
	for (int i = 0; i < ptrmatriz.matriz_altura; i++) //pega os valores da matriz txt e passa para a matriz do codigo
	{
		for (int j = 0; j < ptrmatriz.matriz_largura; j++)
		{
			inFile >> ptrmatriz.dados_matriz[i][j];
		}
	}
}
void Matriz::setDadosMatriz(int elem, int i, int j) {
	ptrmatriz.dados_matriz[i][j] = elem;
}
void Matriz::setAlturaMatriz(int elem) {
	ptrmatriz.matriz_altura = elem;
}
void Matriz::setLarguraMatriz(int elem) {
	ptrmatriz.matriz_largura = elem;
}

Matriz::~Matriz()
{
	for (int i = 0; i < ptrmatriz.matriz_altura; i++)
	{
		for (int j = 0; j < ptrmatriz.matriz_largura; j++)
		{
			ptrmatriz.dados_matriz[i][j] = 0;
		}
	}
	inFile.close();// Fecha o arquivo
}