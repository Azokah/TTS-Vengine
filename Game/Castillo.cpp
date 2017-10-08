#include "Castillo.h"

Castillo::Castillo(){};
Castillo::Castillo(std::string NAME,std::string DESC,int HP,int DEFENSE,int SIZE, int X, int Y){
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
Castillo::~Castillo(){};


void Castillo::update(){

};

void Castillo::onClick(Jugador * jugador){
    int opc;
    std::cout<<"Castillo "<<getName()<<"."<<std::endl;
    std::cout<<"Guarecidas: "<<Estructura::unidadesGuarecidas.size()<<std::endl;
    if(jugador->getName().compare(Estructura::getOwner()->getName()) == 0){
	    std::cout<<"Acciones: "<<std::endl;
	    std::cout<<"1. Reclutar."<<std::endl;
	    do{
		std::cin>>opc;
	    }while(opc <= 0 && opc >= 2);
	    switch(opc){
		case 1:
			//reclutar();
			break;
		default:
			break;
	    }
    };
    
};
