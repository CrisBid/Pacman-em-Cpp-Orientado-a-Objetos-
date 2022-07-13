#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include "allegro5/allegro.h"
#include <allegro5/allegro_native_dialog.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"

#include "Codigo/Mapa.h"
#include "Codigo/Matriz.h"
#include "Codigo/Display.h"
#include "Codigo/Pacman.h"
#include "Codigo/Inimigos.h"
#include "Codigo/Placar.h"

#include <math.h>

using namespace std;

const float FPS = 30;
const int SCREEN_W = 900;//Tab Interno 630 = 21*30
const int SCREEN_H = 720;//Tab Interno x   = x*30


int main() {

    Matriz CMatriz;

    Mapa mapa;

    Pacman player(160,60);

    //Inimigos fantasmas(360,300), fantasmas2(360, 340), fantasmas3(460, 300), fantasmas4(460, 340);

    Inimigos fantasmas(410,300), fantasmas2(160, 620), fantasmas3(660, 620), fantasmas4(660, 60);

    Placar atualPlacar;

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
        free(ptrmatriz);
        exit(1);
    }

    ALLEGRO_EVENT_QUEUE* event_queue = NULL; //Fila de Eventos
    ALLEGRO_TIMER* timer = NULL;//Timer
    ALLEGRO_BITMAP* image = NULL;
    //ALLEGRO_SAMPLE* sample = NULL;
    //ALLEGRO_SAMPLE_INSTANCE* instance = NULL;

    //Vetor de Teclas
    bool teclas[255] = { false };

    if (!al_init()) {
        fprintf(stderr, "Falha ao inicial Allegro!\n");
        return -1;
    }
    al_init_image_addon();//Função de Imagem
    al_install_keyboard();//Funcoes de Teclado
    al_init_image_addon();//Imagens
    //al_install_audio(); //Funçoes de audio
    //al_init_acodec_addon();//Funçoes de audio
    //al_reserve_samples(1);//Funçoes de audio

    timer = al_create_timer(1.0 / FPS);
    if (!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }


    Tela.setDisplay(SCREEN_W, SCREEN_H);

    image = al_load_bitmap("Images/Mapa/Mapa_Fundo.png");

    mapa.setMapa(ptrmatriz);

    player.desenhaPacman(0);

    //Eventos
    event_queue = al_create_event_queue();
    if (!event_queue) {
        fprintf(stderr, "failed to create event_queue!\n");
        Tela.~Display();
        al_destroy_timer(timer);
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(Tela.getDisplay()));//Evento da Tela

    al_register_event_source(event_queue, al_get_timer_event_source(timer));//Evento de tempo

    al_register_event_source(event_queue, al_get_keyboard_event_source());//Evento de Teclado

    al_start_timer(timer);

    /*
    sample = al_load_sample("Audios/Enemy.wav");
    instance = al_create_sample_instance(sample);

    al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());

    if (!sample) {
        printf("Audio clip sample not loaded!\n");
        return -1;
    }
    */
    bool re_desenha = true;
    bool termina = false;

    int sprite = 0, fator = 1;
    int tempo, miliseg = 200;

    int proximaIntrucao = 0;


    while (!termina)
    {

        player.posicaoPacman();
        player.colisaoPacmanPirula(ptrmatriz);

        fantasmas.posicaoInimigos();
        fantasmas.sorteioDirecao(ptrmatriz);

        fantasmas.movimentacaoInimigos(ptrmatriz);
        fantasmas.execusaoMovInimigos(ptrmatriz);

        fantasmas2.posicaoInimigos();
        fantasmas2.sorteioDirecao(ptrmatriz);

        fantasmas2.movimentacaoInimigos(ptrmatriz);
        fantasmas2.execusaoMovInimigos(ptrmatriz);

        fantasmas3.posicaoInimigos();
        fantasmas3.sorteioDirecao(ptrmatriz);

        fantasmas3.movimentacaoInimigos(ptrmatriz);
        fantasmas3.execusaoMovInimigos(ptrmatriz);

        fantasmas4.posicaoInimigos();
        fantasmas4.sorteioDirecao(ptrmatriz);

        fantasmas4.movimentacaoInimigos(ptrmatriz);
        fantasmas4.execusaoMovInimigos(ptrmatriz);

        atualPlacar.set_placar(player.getAtualPlacar());
        
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        tempo = al_get_timer_count(timer);

        if (ev.type == ALLEGRO_EVENT_TIMER) {


            //Timer para trocar o bitmap
            if (tempo == ((FPS * miliseg) / 1000) || tempo > ((FPS * miliseg) / 1000)) {
                al_set_timer_count(timer, 0);
                sprite = sprite + fator;    
                if (sprite == 0) fator = 1;
                if (sprite == 5) fator = -1;
            }

            //Recebe o comando e guarda ele na variavel ate q ele seja possivel de ser executado

            if (teclas[ALLEGRO_KEY_UP])
            {
                proximaIntrucao = ALLEGRO_KEY_UP;
            }
            if (teclas[ALLEGRO_KEY_DOWN])
            {
                proximaIntrucao = ALLEGRO_KEY_DOWN;
            }
            if (teclas[ALLEGRO_KEY_LEFT])
            {
                proximaIntrucao = ALLEGRO_KEY_LEFT;
            }
            if (teclas[ALLEGRO_KEY_RIGHT])
            {
                proximaIntrucao = ALLEGRO_KEY_RIGHT;
                
            }

            player.movimentacaoPacman(proximaIntrucao, ptrmatriz);
            player.execusaoMovPacman(ptrmatriz);

            re_desenha = true;
        }

        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            teclas[ev.keyboard.keycode] = true;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            teclas[ev.keyboard.keycode] = false;
            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                termina = true;

        }

        if (re_desenha && al_is_event_queue_empty(event_queue)) { //Redesenha se a fila de eventos esta vazia
            re_desenha = false;
            //Limpa a tela e Redesenha
            al_clear_to_color(al_map_rgb(000, 000, 255));
            al_draw_bitmap(image, 0, 0, 0); //Desenha a imagem de fundo

            //Chamada dos elemtos do mapa
            mapa.~Mapa(); //Destrutor dos elemtos do mapa
            mapa.setMapa(ptrmatriz); //Contrutor dos elemtos do mapa

            atualPlacar.desenhaPlacar();
            atualPlacar.~Placar();

            //Desenha o pacman
            player.~Pacman();
            player.desenhaPacman(sprite);

            //Desenha os inimigos

            //Inimigo 1
            fantasmas.~Inimigos();
            fantasmas.desenhaInimigos(sprite, 0);

            //Inimigo 2
            fantasmas2.~Inimigos();
            fantasmas2.desenhaInimigos(sprite, 1);

            //Inimigo 3
            fantasmas3.~Inimigos();
            fantasmas3.desenhaInimigos(sprite, 2);

            //Inimigo 4
            fantasmas4.~Inimigos();
            fantasmas4.desenhaInimigos(sprite, 3);
            

            al_flip_display();
        }
        if (player.getPacmanX() == fantasmas.getInimigosX() && player.getPacmanY() == fantasmas.getInimigosY())
        {
            termina = true;
            cout << "VC PERDEU" << endl;
        }
        if (player.getPacmanX() == fantasmas2.getInimigosX() && player.getPacmanY() == fantasmas2.getInimigosY())
        {
            termina = true;
            cout << "VC PERDEU" << endl;
        }
        if (player.getPacmanX() == fantasmas3.getInimigosX() && player.getPacmanY() == fantasmas3.getInimigosY())
        {
            termina = true;
            cout << "VC PERDEU" << endl;
        }
        if (player.getPacmanX() == fantasmas4.getInimigosX() && player.getPacmanY() == fantasmas4.getInimigosY())
        {
            termina = true;
            cout << "VC PERDEU" << endl;
        }
    }

    free(ptrmatriz); //Desaloca o ponteiro que aponta para a matriz
    al_destroy_timer(timer); //Destroi o Timer
    al_destroy_bitmap(image); //Destroi a Imagem
    al_destroy_event_queue(event_queue); //Destroi a Fila de Eventos


    return 0;
}
