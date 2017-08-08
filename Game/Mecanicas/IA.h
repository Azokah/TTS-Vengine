#pragma once
#include <iostream>
#include <time.h>
#include <cmath> 
#include <cstdlib>
#include "Camina.h"
#include "../../Engine/Timer.h"
#include "../../Constantes.h"

class IA : public Camina{
    public:
        IA(int, int);
        virtual ~IA(){};

        bool idle();
    private:
        int generarRandom(int);
        bool checkTimer();
        Timer * timer;
        int lastTick, deadTime;


};