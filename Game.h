#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <SDL2/SDL_image.h>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include "Constantes.h"
#include "Engine/ImouseInput.h"
#include "Engine/SDLManager.h"
#include "Engine/InputManager.h"
#include "Engine/Camara.h"
#include "Engine/RenderComponent.h"
#include "Engine/Colision.h"
#include "Engine/Musica.h"
#include "Engine/Timer.h"
#include "Engine/Gui.h"
#include "Engine/SoldierFactory.h"
#include "Engine/TurnManager.h"
#include "Engine/SelectionManager.h"
#include "Game/Mapa.h"
#include "Game/Ejercito.h"
#include "Game/Infanteria.h"
#include "Game/Arqueros.h"
#include "Game/Caballeria.h"
#include "Game/Castillo.h"
#include "Game/Aldea.h"
#include "Game/Jugador.h"

class Game : public ImouseInput{
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
        virtual void inputMouse(int tecla, int X, int Y);
        void dibujar();
        void dibujarHUD();
        void dibujarTop();
        void bindearInput();
        void selectEntidades(int,int);
	
        void setUP();


        //Engine
        SDLManager * sdl;
        InputManager * in;
        Camara * camara;
        RenderComponent * renderComp;
        Colision * colision;
        Musica * musica;
        Timer * timer;
	Gui * gui;
	SoldierFactory * sFactory;
	TurnManager * turnManager;
	SelectionManager * selectionManager;

        //Game
        std::vector<Jugador *> jugadores;
        Mapa * mapa;
};
