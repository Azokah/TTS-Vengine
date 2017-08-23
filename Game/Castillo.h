#pragma once
#include <iostream>
#include <string>
#include "../Engine/Sprite.h"
#include "../Constantes.h"
#include "Estructura.h"

class Castillo : public Estructura {
    public:
        Castillo();
        Castillo(std::string, std::string, int,int,int,int,int);
        ~Castillo();

        virtual void update();
        virtual void onClick();
};