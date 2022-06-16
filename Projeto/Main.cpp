#include <stdio.h>
#include <iostream>
#include "allegro5/allegro.h"
#include <allegro5/allegro_native_dialog.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
//#include "Codigo/Tijolinho.h"
#include "Codigo/Mapa.h"
#include "Codigo/Matriz.h"
#include "Codigo/Display.h"

using namespace std;

const float FPS = 60;
const int SCREEN_W = 964;//Tab Interno 630 = 21*30
const int SCREEN_H = 750;//Tab Interno x   = x*30


int main() {

    Matriz CMatriz;

    Mapa mapa;

    Display Tela;

    sMatriz *ptrmatriz = NULL;

    ptrmatriz = (sMatriz*)malloc(sizeof(sMatriz));
    if (ptrmatriz)
    {
        CMatriz.loadFileMatriz();

        *ptrmatriz = CMatriz.getMatriz();
    }
    else
    {
        printf("Erro na alocacao");
        exit(1);
    }

    al_init();
    al_init_image_addon();//Função de Imagem
    al_install_keyboard();//Funcoes Teclado

    Tela.setDisplay(SCREEN_W, SCREEN_H); // 21- 31
    mapa.setMapa(ptrmatriz);

    al_rest(20);
    

    return 0;
}

