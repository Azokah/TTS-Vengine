#pragma once
#include <iostream>
#include <string>
#include "../Constantes.h"

class Unidad {
    public:
        
        virtual ~Unidad(){};

        void setName(std::string NAME);
        void setDescription(std::string desc);
        void setSpeed(float SPEED);
        void setHP(int HP);
        void setDamage(int DAMAGE);
        void setDefense(int DEFENSE);
        void setRange(int RANGE);

        std::string getName();
        std::string getDescription();
        float getSpeed();
        int getHP();
        int getDamage();
        int getDefense();
        int getRange();

    private:
        std::string name,description; 
        float speed;
        int hp, damage, defense, range;

};