#include "Jugador.h"


Jugador::Jugador(std::string NAME, int GOLD){
    name = NAME;
    gold = GOLD;
    estado = new JugadorEsperando();
}
Jugador::~Jugador(){};

std::string Jugador::getName(){return name;};

void Jugador::setColorMod(Uint8 R,Uint8 G ,Uint8 B){
	r=R;
	g=G;
	b=B;
};

Uint8 Jugador::getR(){ return r;};
Uint8 Jugador::getG(){return g;};
Uint8 Jugador::getB(){ return b;};

void Jugador::setNumero(int x){
	numero = x;
};
int Jugador::getNumero(){ return numero;};
