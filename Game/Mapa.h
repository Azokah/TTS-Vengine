#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "../Constantes.h"
#include "../Engine/Sprite.h"

class Mapa {
    public:
        Mapa(SDL_Renderer * RENDER);
        ~Mapa();
        
        int getMapa(int,int);

        Sprite * sprite;
        //std::vector<Estructura *> estructuras;
    private:
        int mapa[MAPA_H][MAPA_W];
        
        
};