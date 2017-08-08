#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <boost/signals2.hpp>
#include "../Constantes.h"
#include "Camara.h"
//#include "Signal.h"


class InputManager { //: public Signal //Aplica interfaz Signal{
    public:
        //singleton
        static InputManager& getInstance();
        ~InputManager();

        void run(Camara*);

        int getMouseX();
        int getMouseY();

        boost::signals2::signal<void (int,bool)> signalTecla;
        boost::signals2::signal<void (int,int,int)> signalBoton; // Quizas deberia hacer interfaz
    private:
        InputManager();

        SDL_Event event;
        bool teclas[TECLAS];
        bool botones[BOTONES];
        int mousex, mousey;
};