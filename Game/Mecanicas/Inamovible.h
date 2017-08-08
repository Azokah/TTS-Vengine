#pragma once
#include <iostream>
#include "../../Constantes.h"

class Inamovible {
    public:
        //Camina();
        virtual ~Inamovible(){};

        int getX();
        int getY();

    protected:
        float x, y;
        int direccion;
};
