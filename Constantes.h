#pragma once
//General
//Constantes de Juego
#define VERSION 0.3.1
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



//SPRITE
#define ASSETS_PATH "Assets/tileset.png"
#define MAPA_SPRITE_W TILE_W
#define MAPA_SPRITE_H TILE_H
#define DIRECCIONES 4


//ANIMADOR
#define TIEMPO_ANIMACION 250 //en MS


//AUDIO
#define AUDIO_HZ 22050
#define AUDIO_CHANNELS 2
#define AUDIO_CHUNK_SIZE 4096