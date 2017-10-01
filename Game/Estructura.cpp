#include "Estructura.h"

int Estructura::getX(){ return x;};
int Estructura::getY(){ return y;};
void Estructura::setX(int X){ x = X;};
void Estructura::setY(int Y){ y=Y;};

int Estructura::getHP(){return hp;};
int Estructura::getDef(){return defense;};
int Estructura::getSize(){return size;};

void Estructura::setHP(int HP){hp=HP;};
void Estructura::setDef(int DEF){defense = DEF;};
void Estructura::setSize(int SIZE){size = SIZE;};

std::string Estructura::getName(){return name;};
std::string Estructura::getDesc(){return description;};
void Estructura::setName(std::string NAME){ name = NAME;};
void Estructura::setDesc(std::string DESC){ description = DESC;};


void Estructura::moveTo(int X,int Y){/*Castles dont move*/};
void Estructura::move(){/*Castles dont move;*/};
void Estructura::setXD(int X){ /* Castles dont move*/};
void Estructura::setYD(int Y){/* Castles dont move*/};


bool Estructura::inBounds(int X, int Y){
    if(X == x  && Y == y){
			return true;
	} else return false;
};
void Estructura::dibujar(){
	RenderComponent::getInstance(SDLManager::getInstance().getRender()).setColorMod(180,180,180);
	sprite->dibujar(Estructura::getX()*TILE_W,Estructura::getY()*TILE_H);
};

void Estructura::setOwner(Jugador * OWNER){
	owner = OWNER;
};
Jugador* Estructura::getOwner(){
	return owner;
};
