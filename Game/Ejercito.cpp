#include "Ejercito.h"
Ejercito::Ejercito(Unidad * unidad){
    sprite = new Sprite();
    sprite->agregarFrame(5*TILE_W,0*TILE_H,TILE_W,TILE_H);
    x = 0;
    y = 0;
    addUnidad(unidad);
    size = 1;
    speed = unidad->getSpeed();
    damage = unidad->getDamage();
    fort = 0;

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
    //TODO
    if( xd != x || yd != y){
        x = xd;
        y = yd;
    }
}
int Ejercito::getX(){return x;};
int Ejercito::getY(){return y;};
void Ejercito::setYD(int YD){ yd = YD;};
void Ejercito::setXD(int XD){ xd = XD;};
void Ejercito::addUnidad(Unidad * unidad){
    unidades.push_back(unidad);
    size = unidades.size();
    speed = 0;
    damage = 0;
    for(int i = 0; i<size; i++){
        speed += unidades.at(i)->getSpeed();
        damage += unidades.at(i)->getDamage();
    }
    speed = speed/size;
    damage = damage/size;
}

bool Ejercito::inBounds(int X, int Y){
    if(X == x  && Y == y){
			return true;
	} else return false;
};


void Ejercito::setOwner(Jugador * OWNER){
	owner = OWNER;
};
Jugador* Ejercito::getOwner(){
	return owner;
};

void Ejercito::onClick(){
    int opc;
    std::cout<<"Acciones: "<<std::endl;
    std::cout<<"1. Reclutar."<<std::endl;
    do{
        std::cin>>opc;
    }while(opc <= 0 && opc >= 2);
    
};

void Ejercito::lucharCon(Ejercito *){

};
void Ejercito::unirseA(Ejercito *){

};
void Ejercito::vigilarA(Ejercito *){

};
void Ejercito::seguirA(Ejercito *){

};
void Ejercito::esperar(){};
