#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"

#include "Codigo/Mapa.h"
#include "Codigo/Matriz.h"
#include "Codigo/Display.h"
#include "Codigo/Pacman.h"
#include "Codigo/Inimigos.h"
#include "Codigo/Aleatorios.h"
#include "Codigo/Perseguidor.h"
#include "Codigo/Placar.h"


#include <math.h>

using namespace std;

const float FPS = 45;
const int SCREEN_W = 900; //Largura
const int SCREEN_H = 720; //Altura


int main(int argc, char **argv) {

    Matriz CMatriz;

    Mapa mapa;

    Pacman player(160,60);

    Perseguidor fantasmas(410, 300);
    Aleatorios fantasmas2(160, 620), fantasmas3(660, 620), fantasmas4(660, 60);

    Inimigos* vetInimigos[4];

    vetInimigos[0] = &fantasmas;
    vetInimigos[1] = &fantasmas2;
    vetInimigos[2] = &fantasmas3;
    vetInimigos[3] = &fantasmas4;
    

    Placar atualPlacar;

    Display Tela, Tela2;

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
    ALLEGRO_BITMAP* imageMenu = NULL;
    ALLEGRO_BITMAP* imageDerrota = NULL;
    ALLEGRO_BITMAP* imageVitoria = NULL;
    
    ALLEGRO_SAMPLE* sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE* instance = NULL;
    ALLEGRO_SAMPLE* sample2 = NULL;
    ALLEGRO_SAMPLE_INSTANCE* instance2 = NULL;
    ALLEGRO_SAMPLE* sample3 = NULL;
    ALLEGRO_SAMPLE_INSTANCE* instance3 = NULL;

    //Vetor de Teclas
    bool teclas[255] = { false };

    if (!al_init()) {
        fprintf(stderr, "Falha ao inicial Allegro!\n");
        return -1;
    }
    al_init_image_addon();//Fun��o de Imagem
    al_install_keyboard();//Funcoes de Teclado
    al_init_image_addon();//Imagens
    al_install_audio(); //Fun�oes de audio
    al_init_acodec_addon();//Fun�oes de audio
    al_reserve_samples(1);//Fun�oes de audio

    timer = al_create_timer(1.0 / FPS);
    if (!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }


    Tela2.setDisplay(1280, 720);


    //Eventos
    event_queue = al_create_event_queue();
    if (!event_queue) {
        fprintf(stderr, "failed to create event_queue!\n");
        Tela2.~Display();
        al_destroy_timer(timer);
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(Tela2.getDisplay()));//Evento da Tela

    al_register_event_source(event_queue, al_get_timer_event_source(timer));//Evento de tempo

    al_register_event_source(event_queue, al_get_keyboard_event_source());//Evento de Teclado

    al_start_timer(timer);

    
    sample = al_load_sample("Audios/Enemy.wav");
    instance = al_create_sample_instance(sample);
    sample2 = al_load_sample("Audios/Lofi.wav");
    instance2 = al_create_sample_instance(sample2);
    sample3 = al_load_sample("Audios/pacman_comer.wav");
    instance3 = al_create_sample_instance(sample3);

    al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(instance2, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(instance3, al_get_default_mixer());

    if (!sample) {
        printf("Audio clip sample not loaded!\n");
        return -1;
    }

    if (!sample2) {
        printf("Audio clip sample not loaded!\n");
        return -1;
    }

    if (!sample3) {
        printf("Audio clip sample not loaded!\n");
        return -1;
    }

    
    bool re_desenha = true;
    bool termina = false;
    bool termina2 = false;

    int sprite = 0, fator = 1;
    int tempo, miliseg = 200;

    int proximaIntrucao = 0;

    imageMenu = al_load_bitmap("Images/Menu/Tela Modificada.png");
    imageDerrota = al_load_bitmap("Images/Final/Derrota.png");
    imageVitoria = al_load_bitmap("Images/Final/Vitoria.png");

    while (!termina2)
    {

        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        al_play_sample_instance(instance);


        if (ev.type == ALLEGRO_EVENT_TIMER) {


            //Recebe o comando e guarda ele na variavel ate q ele seja possivel de ser executado

            if (teclas[ALLEGRO_KEY_ENTER])
            {
                termina2 = true;
            }


            re_desenha = true;
        }

        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            termina = true;
            termina2 = true;
            break;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            teclas[ev.keyboard.keycode] = true;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            teclas[ev.keyboard.keycode] = false;
            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                termina = true;
                termina2 = true;

        }

        if (re_desenha && al_is_event_queue_empty(event_queue)) { //Redesenha se a fila de eventos esta vazia
            re_desenha = false;
            //Limpa a tela e Redesenha
            al_clear_to_color(al_map_rgb(000, 000, 255));
            al_draw_bitmap(imageMenu, 0, 0, 0); //Desenha a imagem de fundo


            al_flip_display();
        }

    }

    //al_destroy_event_queue(event_queue); //Destroi a Fila de Eventos

    al_stop_sample_instance(instance);

    Tela2.Destrutor();

    //Inicio do Jogo

    bool vitoria = false;
    bool derrota = false;
    bool status = false;
    int bufferplacar = 0;

    Tela.setDisplay(SCREEN_W, SCREEN_H);

    al_register_event_source(event_queue, al_get_display_event_source(Tela.getDisplay()));//Evento da Tela



    image = al_load_bitmap("Images/Mapa/Mapa_Fundo.png");

    mapa.setMapa(ptrmatriz);

    player.desenhaPacman(0);


    while (!termina)
    {

        //al_play_sample(sample2, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

        bufferplacar = atualPlacar.getPlacar();

        player.posicaoPacman();
        player.colisaoPacmanPirula(ptrmatriz);

        for (int i = 0; i < 4; i++)
        {
            vetInimigos[i]->posicaoInimigos();
            vetInimigos[i]->sorteioDirecao(ptrmatriz, player.getPacmanX(), player.getPacmanY());

            vetInimigos[i]->movimentacaoInimigos(ptrmatriz);
            vetInimigos[i]->execusaoMovInimigos(ptrmatriz, status);
        }

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

            if (status == false)
            {
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
            }

            player.movimentacaoPacman(proximaIntrucao, ptrmatriz);
            player.execusaoMovPacman(ptrmatriz, status);
            if (bufferplacar != atualPlacar.getPlacar())
            {
                al_play_sample_instance(instance3);
            }

            re_desenha = true;
        }

        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            termina = true;
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
            mapa.~Mapa(); //Destrutor dos elementos do mapa
            mapa.setMapa(ptrmatriz); //Contrutor dos elemtos do mapa

            atualPlacar.~Placar();
            atualPlacar.desenhaPlacar();

            //Desenha o pacman
            player.~Pacman();
            player.desenhaPacman(sprite);

            //Desenha os inimigos

            for (int i = 0; i < 4; i++)
            {
                vetInimigos[i]->Destrutor();
                vetInimigos[i]->desenhaInimigos(sprite, i);
            }

            if (derrota == true)
            {
                al_draw_bitmap(imageDerrota, 0, 0, 0); //Desenha a imagem de fundo
                
            }

            if (vitoria == true)
            {
                al_draw_bitmap(imageVitoria, 0, 0, 0); //Desenha a imagem de fundo
            }

            al_flip_display();

        }

        
        for (int i = 0; i < 4; i++)
        {
            if (player.getPacmanX() == vetInimigos[i]->getInimigosX() && player.getPacmanY() == vetInimigos[i]->getInimigosY())
            {
                derrota = true;
            }
            if (player.getPacmanX() == vetInimigos[i]->getInimigosX()+ 2 && player.getPacmanY() == vetInimigos[i]->getInimigosY())
            {
                derrota = true;
            }
            if (player.getPacmanX() == vetInimigos[i]->getInimigosX() - 2 && player.getPacmanY() == vetInimigos[i]->getInimigosY())
            {
                derrota = true;
            }
            if (player.getPacmanX() == vetInimigos[i]->getInimigosX() && player.getPacmanY() == vetInimigos[i]->getInimigosY() + 2)
            {
                derrota = true;
            }
            if (player.getPacmanX() == vetInimigos[i]->getInimigosX() && player.getPacmanY() == vetInimigos[i]->getInimigosY() - 2)
            {
                derrota = true;
            }
            if (player.getPacmanX() == vetInimigos[i]->getInimigosX() + 2 && player.getPacmanY() == vetInimigos[i]->getInimigosY() + 2)
            {
                derrota = true;
            }
            if (player.getPacmanX() == vetInimigos[i]->getInimigosX() - 2 && player.getPacmanY() == vetInimigos[i]->getInimigosY() + 2)
            {
                derrota = true;
            }
            if (player.getPacmanX() == vetInimigos[i]->getInimigosX() - 2 && player.getPacmanY() == vetInimigos[i]->getInimigosY() - 2)
            {
                derrota = true;
            }
            if (player.getPacmanX() == vetInimigos[i]->getInimigosX() + 2 && player.getPacmanY() == vetInimigos[i]->getInimigosY() - 2)
            {
                derrota = true;
            }
        }

        if (atualPlacar.getPlacar() == 246)
        {
            vitoria = true;
        }
        if (vitoria == true || derrota == true)
        {
            status = true;
        }

    }

    free(ptrmatriz); //Desaloca o ponteiro que aponta para a matriz
    al_destroy_timer(timer); //Destroi o Timer
    al_destroy_bitmap(image); //Destroi a Imagem
    al_destroy_bitmap(imageMenu); //Destroi a Imagem do Menu
    al_destroy_bitmap(imageDerrota); //Destroi a Imagem de Derrota
    al_destroy_bitmap(imageVitoria); //Destroi a Imagem de Vitoria
    al_destroy_sample(sample); //Destroi Sample
    al_destroy_sample_instance(instance); //Destroi Instance
    al_destroy_sample(sample2); //Destroi Sample2
    al_destroy_sample_instance(instance2); //Destroi Instance2
    al_destroy_sample(sample3); //Destroi Sample3
    al_destroy_sample_instance(instance3); //Destroi Instance3
    al_destroy_event_queue(event_queue); //Destroi a Fila de Eventos


    return 0;
}
