#include "StructMatriz.h"
#include "Movimentacao.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#ifndef INIMIGOS_H
#define INIMIGOS_H

class Inimigos : public Movimentacao
{
	public:
		Inimigos();
		Inimigos(int, int);

		ALLEGRO_BITMAP* getInimigos();

		void posicaoInimigos();

		bool colisaoInimigos(sMatriz*);

		bool colisaoInimigosTop(sMatriz*);
		bool colisaoInimigosBottom(sMatriz*);
		bool colisaoInimigosRight(sMatriz*);
		bool colisaoInimigosLeft(sMatriz*);

		float getInimigosX();
		float getInimigosY();

		void setInimigosX(float);
		void setInimigosY(float);

		void sorteioDirecao(sMatriz* matriz);

		void movimentacaoInimigos(sMatriz*);
		void execusaoMovInimigos(sMatriz*);

		void desenhaInimigos(int, int);

		~Inimigos();

	private:
		ALLEGRO_BITMAP* inimigo;

		//Variaveis de Tamanho da Sprite
		int inimigos_altura;
		int inimigos_largura;

		//Variaveis de Dire��o
		bool top;
		bool right;
		bool bottom;
		bool left;
		int lado;

		//Variaveis de Randomiza��o

		int opcao3[3];

		int aleatorio2;
		int aleatorio3;

		int Instrucao;

};

#endif

