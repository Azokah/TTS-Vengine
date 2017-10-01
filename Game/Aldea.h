#pragma once
#include <iostream>
#include <string>
#include "../Engine/Sprite.h"
#include "../Constantes.h"
#include "Estructura.h"

class Aldea : public Estructura {
    public:
        Aldea();
        Aldea(std::string, std::string, int,int,int,int,int);
        ~Aldea();

        virtual void update();
        virtual void onClick(Jugador*);
};
