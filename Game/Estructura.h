#pragma once
#include <iostream>
#include <string>
#include "../Engine/Sprite.h"
#include "../Constantes.h"
#include "IEntidad.h"

class Estructura : public IEntidad {
    public:
        
        virtual ~Estructura();

        virtual void update();
        virtual void moveTo(int,int);
        virtual void move();
        virtual int getX();
        virtual int getY();
        virtual void setXD(int);
        virtual void setYD(int);

        int getHP();
        int getDef();
        int getSize();

        void setHP(int);
        void setDef(int);
        void setSize(int);

        Sprite * sprite;


    private:
        std::string name,description;
        int hp, defense, size;
        int x, y;
};