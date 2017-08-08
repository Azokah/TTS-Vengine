#pragma once
#include <iostream>
#include <string>
#include "../Constantes.h"
#include "../Engine/Sprite.h"

/* Entidades no se instancian, necesita sprite? */


class Entidad {
    public:
        Entidad(std::string);
        virtual ~Entidad() {};

        void update();

        std::string getNombre();
        Sprite * sprite;

    protected:
        std::string nombre;
};