#include "Infanteria.h"

Infanteria::Infanteria(){
    setName("Infanteria");
    setDescription("Unidad estandar de combate.");
    setSpeed(2);
    setHP(100);
    setDamage(5);
    setDefense(5);
    setRange(1);
};

Infanteria::~Infanteria(){};