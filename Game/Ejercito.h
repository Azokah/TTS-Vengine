#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Constantes.h"
#include "../Engine/Sprite.h"
#include "IEntidad.h"
#include "Unidades.h"

class Ejercito : public IEntidad {
    public:
        Ejercito();
        ~Ejercito();

        virtual void update();
        virtual void moveTo(int,int);
        virtual void move();
        virtual int getX();
        virtual int getY();
        virtual void setXD(int);
        virtual void setYD(int);

        Sprite * sprite;

    private:
        int size;
        float speed, fort, damage;

        int x, y, xd, yd;

        std::vector<Unidad *> unidades;

};