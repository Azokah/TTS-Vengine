#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "../Constantes.h"
#include "../Engine/Sprite.h"
#include "../Engine/SDLManager.h"
#include "Estructura.h"
#include "Castillo.h"
#include "Aldea.h"

/*
 * Mapa deberia ser una entidad?
 * */


class Mapa {
    public:
        Mapa();
        ~Mapa();
        
        int getMapa(int,int);
	void dibujar();

        Sprite * sprite;
        std::vector<Estructura *> estructuras;
    
    
    private:
        int mapa[MAPA_H][MAPA_W];
        
        
};
