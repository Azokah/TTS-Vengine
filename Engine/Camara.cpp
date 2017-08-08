#include "Camara.h"

Camara& Camara::getInstance(){
            static Camara instancia;
            return instancia;
}
Camara::Camara(){
	x = 0;
	y = 0;
	w = CAMARA_W;
	h = CAMARA_H;
};

Camara::~Camara(){};

int Camara::getX(){ return x;};

int Camara::getY(){ return y;};

int Camara::getW(){ return w;};

int Camara::getH(){ return h;};


void Camara::update(int nx, int ny) {
	
     x = nx-CAMARA_W/2;
	 y = ny-CAMARA_H/2;

	 if(x > ((TILE_W*MAPA_W) - w)){
	 	x = ((TILE_W*MAPA_W)-w);
	 } else if (x < 0) {
		x = 0;
	 }

	 if (y < 0 ) {
		y = 0;
	 } else if (y > ((TILE_H*MAPA_H) - h)) {
		y = (TILE_H*MAPA_H) - h;
	 }
};
