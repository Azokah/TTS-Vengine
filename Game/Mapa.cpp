#include "Mapa.h"


Mapa::Mapa(){
    sprite = new Sprite();
    sprite->agregarFrame(0,3*TILE_W,TILE_W,TILE_H);
    for(int i = 0; i < MAPA_H; i++)
        for(int j = 0; j < MAPA_W; j++)
            mapa[i][j] = 0;
    
    estructuras.push_back(new Castillo("Casterly Rock","The original Lannister's castle",5000,100,500,10,10));
    estructuras.push_back(new Castillo("Rocksterly Cast","The non-original Lannister's castle",5000,100,500,20,25));
    estructuras.push_back(new Aldea("Casterly","The original Lannister's aldea",500,50,100,15,18));
};
Mapa::~Mapa(){};


void Mapa::dibujar(){
	RenderComponent::getInstance(SDLManager::getInstance().getRender()).setColorMod(0,255,0);

	for (int i = 0; i < MAPA_H; i++){
		for (int j = 0; j < MAPA_W; j++){ 
		       sprite->dibujar(j*TILE_W,i*TILE_H);
		}	
    	}
}
int Mapa::getMapa(int x, int y){return mapa[x][y];};
