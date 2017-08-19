#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Constantes.h"



class Jugador {
    public:
        Jugador(std::string,int);
        ~Jugador();

        std::string getName();
        
    private:
        std::string name;
        int gold;

};