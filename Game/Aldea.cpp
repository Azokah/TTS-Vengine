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
    setOwner(new Jugador(SIN_DUENO,0));

    sprite = new Sprite();
    sprite->agregarFrame(TILE_W*9,TILE_H*2,TILE_W,TILE_H);
};
Aldea::~Aldea(){};


void Aldea::update(){

};

void Aldea::onClick(Jugador* jugador){
    int opc;
    std::cout<<"Aldea "<<getName()<<"."<<std::endl;
    if(Estructura::getOwner()->getName().compare(jugador->getName()) == 0){
    	std::cout<<"Acciones: "<<std::endl;
    	std::cout<<"1. Irse."<<std::endl;
    	do{
        	std::cin>>opc;
    	}while(opc <= 0 && opc >= 2);
    }
};
