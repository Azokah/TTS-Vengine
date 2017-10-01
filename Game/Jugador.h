#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "SDL2/SDL.h"
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

	void setNumero(int);
	int getNumero();
	void setColorMod(Uint8,Uint8,Uint8);
	Uint8 getR();
	Uint8 getG();
	Uint8 getB();

	void setGold(int);
	int getGold();
    private:
        std::string name;
        int gold;
	Uint8 r,g,b;
	int numero;
};
