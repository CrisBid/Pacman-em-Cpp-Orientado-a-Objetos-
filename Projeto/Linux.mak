COMPILADOR=g++

ALLEGRO_FLAGS=-L/usr/local/lib `pkg-config --libs allegro-5 allegro_audio-5 allegro_dialog-5 allegro_image-5 allegro_memfile-5 allegro_primitives-5 allegro_acodec-5 allegro_color-5 allegro_font-5 allegro_physfs-5 allegro_ttf-5` 

ALLEGRO_INCLUDE= -I/usr/local/include/allegro5

all: ./Codigo/Mapa.o ./Codigo/Pirula.o ./Codigo/Tijolinho.o ./Codigo/Placar.o ./Codigo/Matriz.o ./Codigo/Display.o ./Codigo/Inimigos.o ./Codigo/Pacman.o ./Codigo/Movimentacao.o Main.o
	$(COMPILADOR) ./Codigo/Mapa.o ./Codigo/Pirula.o ./Codigo/Tijolinho.o ./Codigo/Placar.o ./Codigo/Matriz.o ./Codigo/Display.o ./Codigo/Inimigos.o ./Codigo/Pacman.o ./Codigo/Movimentacao.o Main.o -o Main $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)



Movimentacao.o: ./Codigo/Movimentacao.h ./Codigo/Movimentacao.cpp ./Codigo/StructMatriz.h
	$(COMPILADOR) -c ./Codigo/Movimentacao.cpp -o ./Codigo/Movimentacao.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Pacman.o: ./Codigo/Pacman.h ./Codigo/Pacman.cpp ./Codigo/Movimentacao.h ./Codigo/StructMatriz.h
	$(COMPILADOR) -c ./Codigo/Pacman.cpp -o ./Codigo/Pacman.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Inimigos.o: ./Codigo/Inimigos.h ./Codigo/Inimigos.cpp ./Codigo/Movimentacao.h ./Codigo/StructMatriz.h
	$(COMPILADOR) -c ./Codigo/Inimigos.cpp -o ./Codigo/Inimigos.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)



Tijolinho.o: ./Codigo/Tijolinho.h ./Codigo/Tijolinho.cpp ./Codigo/StructMatriz.h
	$(COMPILADOR) -c ./Codigo/Tijolinho.cpp -o ./Codigo/Tijolinho.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Pirula.o: ./Codigo/Pirula.h ./Codigo/Pirula.cpp ./Codigo/StructMatriz.h
	$(COMPILADOR) -c ./Codigo/Pirula.cpp -o ./Codigo/Pirula.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Mapa.o: ./Codigo/Mapa.h ./Codigo/Mapa.cpp ./Codigo/Tijolinho.h ./Codigo/Pirula.h
	$(COMPILADOR) -c ./Codigo/Mapa.cpp -o Mapa.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)



Display.o: ./Codigo/Display.h ./Codigo/Display.cpp
	$(COMPILADOR) -c ./Codigo/Display.cpp -o ./Codigo/Display.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Matriz.o: ./Codigo/Matriz.h ./Codigo/Matriz.cpp ./Codigo/StructMatriz.h
	$(COMPILADOR) -c ./Codigo/Matriz.cpp -o ./Codigo/Matriz.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Placar.o: ./Codigo/Placar.h ./Codigo/Placar.cpp
	$(COMPILADOR) -c ./Codigo/Placar.cpp -o ./Codigo/Placar.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)



Main.o: ./Codigo/Mapa.h ./Codigo/Matriz.h ./Codigo/Display.h ./Codigo/Mapa.h ./Codigo/Inimigos.h ./Codigo/Pacman.h ./Codigo/Placar.h ./Codigo/StructMatriz.h Main.cpp
	$(COMPILADOR) -c Main.cpp -o Main.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

clean: 
	rm *.o tic ./Codigo/*.o