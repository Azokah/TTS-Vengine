#pragma once
#include <iostream>
#include <string>
#include "Jugador.h"
#include "../Constantes.h"

/*
 *	Strategy,
 *	Contiene los metodos que toda entidad debe implementar.
 *	Jaime Gonzalez Bonorino - 2017
 * */


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
        virtual bool inBounds(int,int) = 0;
        virtual void setOwner(Jugador *) = 0;
        virtual Jugador* getOwner() = 0;
        virtual void onClick(Jugador*) = 0;
        //cvirtual void 
	virtual void dibujar() = 0; //Porque todas las entidades poseen Sprite

};
