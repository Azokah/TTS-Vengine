/*************************************************************
** Clase que se encarga de obtener los sprites necesarios ****
** de la hoja de sprites. Tambien se encarga de animaciones **
*************************************************************/

#pragma once
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "Timer.h"

using namespace std;

class Sprite {
    public:
        Sprite();
        ~Sprite();

        void run();
        void stop();
        void play();
        void play(int dir);

        void agregarFrame(SDL_Rect, int);
        void agregarFrame(int,int,int,int);
        void agregarFrame(int,int,int,int,int);
        SDL_Rect* getFrame();
        SDL_Rect* getFrameDir();

        void setVelocidad(int);

    private:
        vector<SDL_Rect> frames[DIRECCIONES];
        int frame, direction;
        Timer * timer;
        int lastTick;
        bool playing;
        int velocidadAnimacion;

};