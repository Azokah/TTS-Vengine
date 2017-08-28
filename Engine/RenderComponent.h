#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "../Constantes.h"
#include "SpriteSheet.h"
#include "Camara.h"

class RenderComponent {
    public:
        static RenderComponent& getInstance(SDL_Renderer *);
        ~RenderComponent();

        void renderizar(int, int, int, int,SDL_Rect*,Camara*);
        void renderizarFixed(int,int,int,int,SDL_Rect*,bool);
        void renderizarViewport(int,int,int,int,SDL_Rect*,SDL_Rect*);

        void setClip(SDL_Rect *);
    private:
        SDL_Renderer * render;
        RenderComponent(SDL_Renderer *);
        SpriteSheet * sprSh;
        SDL_Rect vPort;
};
