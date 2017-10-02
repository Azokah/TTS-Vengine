#pragma once
#include <iostream>
#include <string>
#include "../Engine/Sprite.h"
#include "../Constantes.h"
#include "Estructura.h"

//Deberia incluir estos 3?... quizas usar alguna interfaz..
#include "Infanteria.h"
#include "Arqueros.h"
#include "Caballeria.h"


class Castillo : public Estructura {
    public:
        Castillo();
        Castillo(std::string, std::string, int,int,int,int,int);
        ~Castillo();

        virtual void update();
        virtual void onClick(Jugador *);

	void reclutar(); //El castillo puede reclutar?... o el jugador puede reclutar? en un castillo?
};
