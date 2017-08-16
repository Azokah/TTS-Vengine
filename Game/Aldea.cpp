#include "Aldea.h"

Aldea::Aldea(){};
Aldea::Aldea(std::string NAME,std::string DESC,int HP,int DEFENSE,int SIZE, int X, int Y){
    setName(NAME);
    setDesc(DESC);
    setHP(HP);
    setDef(DEFENSE);
    setSize(SIZE);
    setX(X);
    setY(Y);

    sprite = new Sprite();
    sprite->agregarFrame(TILE_W*2,TILE_H,TILE_W*2,TILE_H*2);
};
Aldea::~Aldea(){};


void Aldea::update(){

};