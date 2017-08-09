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
	right = left = up = down = false;
};

Camara::~Camara(){};

int Camara::getX(){ return x;};

int Camara::getY(){ return y;};

int Camara::getW(){ return w;};

int Camara::getH(){ return h;};

void Camara::setX(int X){ x = X;};
void Camara::setY(int Y){ y = Y;};



void Camara::update() {
	

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

void Camara::checkMouse(int x, int y){
	if ( x < CAMARA_BORDE ){
		goLeft();
	}else if( x > CAMARA_W - CAMARA_BORDE){
		goRight();
	}else if( y < CAMARA_BORDE){
		goUp();
	}else if( y > CAMARA_H - CAMARA_BORDE){
		goDown();
	}
};
void Camara::goUp(){
	if(up) y -= CAMARA_SPEED; 
};
void Camara::goDown(){
	if(down) y += CAMARA_SPEED; 
};
void Camara::goLeft(){
	if(left) x -= CAMARA_SPEED;
};
void Camara::goRight(){
	if(right) x += CAMARA_SPEED; 
};