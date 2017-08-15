#include "Ejercito.h"
Ejercito::Ejercito(){
    sprite = new Sprite();
    sprite->agregarFrame(5*TILE_W,5*TILE_H,TILE_W,TILE_H);
}
Ejercito::~Ejercito(){};
void Ejercito::update(){
    move();
};
void Ejercito::moveTo(int XD,int YD){
    setXD(XD);
    setYD(YD);
};
void Ejercito::move(){
    if( xd != x || yd != y){
        x = xd;
        y = yd;
    }
}
int Ejercito::getX(){return x;};
int Ejercito::getY(){return y;};
void Ejercito::setYD(int YD){ yd = YD;};
void Ejercito::setXD(int XD){ xd = XD;};