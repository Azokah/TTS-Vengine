#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL_image.h>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include "Constantes.h"
#include "Engine/SDLManager.h"
#include "Engine/InputManager.h"
#include "Engine/Camara.h"
#include "Engine/RenderComponent.h"
#include "Engine/Colision.h"
#include "Engine/Musica.h"
#include "Engine/Timer.h"
#include "Game/Mapa.h"


enum game_estado{
        INICIANDO,
        CORRIENDO,
        TERMINADO
};

class Game {
    public:
        //singleton
        static Game& getInstance();
        ~Game();

        void run();
    private:
        Game();
        game_estado estado;

        void update();
        void input(int tecla, bool estado);
        void inputMouse(int tecla, int X, int Y);
        void dibujar();
        void dibujarHUD();
        void dibujarTop();
        void bindearInput();
        void selectEntidades(int,int);


        //Engine
        SDLManager * sdl;
        InputManager * in;
        Camara * camara;
        RenderComponent * renderComp;
        Colision * colision;
        Musica * musica;
        Timer * timer;

        //Game
        Mapa * mapa;
};