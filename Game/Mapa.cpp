#include "Mapa.h"


Mapa::Mapa(){
    sprite = new Sprite();
    sprite->agregarFrame(32,0,32,32);
    for(int i = 0; i < MAPA_H; i++)
        for(int j = 0; j < MAPA_W; j++)
            mapa[i][j] = 0;
    
    estructuras.push_back(new Castillo("Casterly Rock","The original Lannister's castle",5000,100,500,10,10));
    estructuras.push_back(new Castillo("Rocksterly Cast","The non-original Lannister's castle",5000,100,500,20,25));
    estructuras.push_back(new Aldea("Casterly","The original Lannister's aldea",500,50,100,15,18));
};
Mapa::~Mapa(){};


void Mapa::dibujar(){
	for (int i = 0; i < MAPA_H; i++){
		for (int j = 0; j < MAPA_W; j++){
           RenderComponent::getInstance(SDLManager::getInstance().getRender()).renderizar(j * TILE_W,
			    i * TILE_H,
			    TILE_W,
			    TILE_H,
			    sprite->getFrame(),
			    &Camara::getInstance());
        } 
    }
}
int Mapa::getMapa(int x, int y){return mapa[x][y];};
