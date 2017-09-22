#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Constantes.h"
#include "JugadorState.h"
#include "JugadorJugando.h"
#include "JugadorEsperando.h"


class Jugador {
    public:
        Jugador(std::string,int);
        ~Jugador();

        std::string getName();
        
	JugadorState * estado;
    private:
        std::string name;
        int gold;
};
