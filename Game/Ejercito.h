#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Constantes.h"
#include "../Engine/Sprite.h"
#include "IEntidad.h"
#include "Unidad.h"
#include "Jugador.h"

enum estado{
    ATACANDO,
    DEFENDIENDO,
    ESPERANDO,
    CAMINANDO
};

class Ejercito : public IEntidad {
    public:
        Ejercito(Unidad * unidad);
        ~Ejercito();

        virtual void update();
        virtual void moveTo(int,int);
        virtual void move();
        virtual int getX();
        virtual int getY();
        virtual void setXD(int);
        virtual void setYD(int);
	virtual bool inBounds(int,int);
	virtual void setOwner(Jugador *);
	virtual Jugador* getOwner();
	virtual void onClick();


        void addUnidad(Unidad * unidad);

        Sprite * sprite;

        std::vector<Unidad *> unidades;

        void lucharCon(Ejercito *);
        void unirseA(Ejercito *);
        void vigilarA(Ejercito *);
        void seguirA(Ejercito *);
        void esperar();

    private:
        int size;
        float speed, fort, damage;
	
	Jugador * owner;

        int x, y, xd, yd;
};
