#pragma once
#include <iostream>
#include <cmath> 
#include "../../Constantes.h"

class Camina {
    public:
        Camina(int, int);
        virtual ~Camina(){};
        void moveTo( int, int);

        int getX();
        int getY();

    protected:
        float x, y, xDestino, yDestino,xIncremento, yIncremento, velocidad;
        int direccion;
        bool caminando;
        
        float normaVector( float, float);
        void normalizar(float *, float *);
        bool move();
};