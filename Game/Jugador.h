#include <iostream>
#include <string>
#include <vector>
#include "../Constantes.h"
#include "Ejercito.h"
#include "Estructura.h"


class Jugador {
    public:
        Jugador(std::string,int);
        ~Jugador();


        std::vector<Ejercito *> ejercitos;
        std::vector<Estructura  *>  estructuras;

        
    private:
        std::string name;
        int gold;

};