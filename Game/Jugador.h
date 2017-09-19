#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Constantes.h"

enum estadoJugador{
	EN_ESPERA,
	JUGANDO
};

class Jugador {
    public:
        Jugador(std::string,int);
        ~Jugador();

        std::string getName();
        
	estadoJugador estado;
    private:
        std::string name;
        int gold;
};
