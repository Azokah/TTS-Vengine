/**********************************************************
** Clase que se encarga de de guardar la hoja de sprites **
***********************************************************/

#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../Constantes.h"


using namespace std;
class SpriteSheet {
    public:
        static SpriteSheet& getInstance(SDL_Renderer *);
        ~SpriteSheet();

        void loadSpriteSheet(SDL_Renderer *);


        SDL_Texture* getSpriteSheet();
    private:
        SpriteSheet(SDL_Renderer *);
        SDL_Texture * textura;

        

};