#include "Entidad.h"

Entidad::Entidad(std::string NOMBRE)
{
    nombre = NOMBRE;
    sprite = new Sprite(); //Entidades necesitan sprite?, no tienen posicion...
    sprite->agregarFrame(0, 0, 32, 32);
};

void Entidad::update()
{
    sprite->play();
    sprite->run();
};


std::string Entidad::getNombre() { return nombre; };