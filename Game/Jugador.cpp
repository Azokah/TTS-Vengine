#include "Jugador.h"


Jugador::Jugador(std::string NAME, int GOLD){
    name = NAME;
    gold = GOLD;
    estado = new JugadorEsperando();
}
Jugador::~Jugador(){};

std::string Jugador::getName(){return name;};
