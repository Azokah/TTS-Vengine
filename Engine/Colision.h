#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "../Constantes.h"

//Colision: Chequear colision y si en la posicion proxima va a haber colision, no mover.(shi, shi)


class Colision {
    public:
        Colision();
        ~Colision();

        bool detectar( int, int, int, int, int, int, int, int);
        bool detectar(SDL_Rect *, SDL_Rect *);
    private:

};
