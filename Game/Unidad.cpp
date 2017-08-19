#include "Unidad.h"

void Unidad::setName(std::string NAME){name=NAME;};
void Unidad::setDescription(std::string desc){description=desc;};
void Unidad::setSpeed(float SPEED){speed=SPEED;};
void Unidad::setHP(int HP){hp=HP;};
void Unidad::setDamage(int DAMAGE){damage=DAMAGE;};
void Unidad::setDefense(int DEFENSE){defense=DEFENSE;};
void Unidad::setRange(int RANGE){range=RANGE;};
void Unidad::setOwner(Jugador * OWNER){
	owner = OWNER;
};
Jugador* Unidad::getOwner(){
	return owner;
};



std::string Unidad::getName(){return name;};
std::string Unidad::getDescription(){return description;};
float Unidad::getSpeed(){return speed;};
int Unidad::getHP(){return hp;};
int Unidad::getDamage(){return damage;};
int Unidad::getDefense(){return defense;};
int Unidad::getRange(){return range;};