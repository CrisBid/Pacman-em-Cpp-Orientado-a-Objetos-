#include "StructMatriz.h"
#include "Inimigos.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#ifndef PERSEGUIDOR_H
#define PERSEGUIDOR_H

class Perseguidor : public Inimigos
{
public:
	Perseguidor();
	Perseguidor(int, int);

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

	virtual void sorteioDirecao(sMatriz* matriz, float, float);

	virtual void movimentacaoInimigos(sMatriz*);
	virtual void execusaoMovInimigos(sMatriz*);

	virtual void desenhaInimigos(int, int);

	virtual void Destrutor();
	~Perseguidor();

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

	float bufferX;
	float bufferY;

};

#endif
