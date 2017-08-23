#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Engine/Sprite.h"
#include "../Constantes.h"
#include "Unidad.h"
#include "IEntidad.h"
#include "Jugador.h"


class Estructura : public IEntidad {
    public:
        
        virtual ~Estructura(){};

        virtual void update() = 0; // Metodo inexistente para Estructuras
        virtual void moveTo(int,int);// Metodo inexistente para Estructuras pero con cuerpo
        virtual void move();// Metodo inexistente para Estructuras pero con cuerpo
        virtual int getX();
        virtual int getY();
        virtual void setXD(int);// Metodo inexistente para Estructuras pero con cuerpo
        virtual void setYD(int);// Metodo inexistente para Estructuras pero con cuerpo
        
        virtual bool inBounds(int,int);
        virtual void onClick() = 0;

        virtual void setOwner(Jugador * OWNER);
        virtual Jugador* getOwner();

        void setX(int);
        void setY(int);

        std::string getName();
        std::string getDesc();
        int getHP();
        int getDef();
        int getSize();

        void setName(std::string);
        void setDesc(std::string);
        void setHP(int);
        void setDef(int);
        void setSize(int);
        

        Sprite * sprite;

        std::vector<Unidad *> unidadesGuarecidas;



    private:
        std::string name,description;
        int hp, defense, size;
        int x, y;

        Jugador * owner;
};