#pragma once
#include <iostream>
#include <string>
#include "../Constantes.h"

/* Entidades no se instancian, necesita sprite? */


class IEntidad {
    public:
        virtual ~IEntidad(){};

        virtual void update() = 0;
        virtual void moveTo(int,int) = 0;
        virtual void move() = 0;
        virtual int getX() = 0;
        virtual int getY() = 0;
        virtual void setXD(int) = 0;
        virtual void setYD(int) = 0;
        //cvirtual void 

};