#include "Estructura.h"

int Estructura::getX(){ return x;};
int Estructura::getY(){ return y;};

int Estructura::getHP(){return hp;};
int Estructura::getDef(){return defense;};
int Estructura::getSize(){return size;};

void Estructura::setHP(int HP){hp=HP;};
void Estructura::setDef(int DEF){defense = DEF;};
void Estructura::setSize(int SIZE){size = SIZE;};


void Estructura::moveTo(int X,int Y){/*Castles dont move*/};
void Estructura::move(){/*Castles dont move;*/};
void Estructura::setXD(int X){ /* Castles dont move*/};
void Estructura::setYD(int Y){/* Castles dont move*/};