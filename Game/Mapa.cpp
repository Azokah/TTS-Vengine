#include "Mapa.h"


Mapa::Mapa(SDL_Renderer * RENDER){
    sprite = new Sprite();
    sprite->agregarFrame(32,0,32,32);
    for(int i = 0; i < MAPA_H; i++)
        for(int j = 0; j < MAPA_W; j++)
            mapa[i][j] = 0;
    
};
Mapa::~Mapa(){};

int Mapa::getMapa(int x, int y){return mapa[x][y];};
