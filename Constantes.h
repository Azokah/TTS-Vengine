#pragma once
//Notas:
//Implementar patron STATE para el manejo de TURNOS de los jugadores.
//Si es el turno del jugador rojo, el input y las acciones 
//	posibles deben reaccionar de una determinada manera.
//	El contexto es el turno del jugador actual.
//
//Crear clase resource manager:
//	ResourceManager: Controla la carga y descarga de recursos. 
//Problemas principales:
//          Sprite deberia tener la textura de Missing texture de forma automatica.
//Consejos recibidos:
//	Migrar todo a NODOS. Asi se manejan los engine hoy en dia.
//






//General
//Constantes de Juego
#define VERSION 0.3.3
#define TILE_W 32
#define TILE_H 32

//SDLWrapper
#define TITULO "Titulo"
#define PANTALLA_AN 800
#define PANTALLA_AL 600
#define GAME_OPTIONS SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
#define GAME_OPTIONS_NOVSYNC SDL_RENDERER_ACCELERATED

//Texto
#define TEXTO_SIZE 18
#define FUENTE "Assets/ARCADE_N.TTF"
#define TEXTO_ALPHA 1


//InputManager
#define TECLAS 285
#define BOTONES 3

//Mapa
#define MAPA_H 100
#define MAPA_W 100

//Camara
#define CAMARA_W PANTALLA_AN
#define CAMARA_H PANTALLA_AL
#define CAMARA_SPEED 2
#define CAMARA_BORDE 32



//SPRITE
#define ASSETS_PATH "Assets/tileset.png"
#define MAPA_SPRITE_W TILE_W
#define MAPA_SPRITE_H TILE_H
#define DIRECCIONES 4


//ANIMADOR
#define TIEMPO_ANIMACION 250 //en MS


//AUDIO
#define AUDIO_HZ 44100
#define AUDIO_CHANNELS 2
#define AUDIO_CHUNK_SIZE 4096

//GUI
#define CURRENT_TURN_PLAYER_OFFSET 50
