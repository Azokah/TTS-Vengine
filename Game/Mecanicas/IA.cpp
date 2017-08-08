#include "IA.h"


IA::IA(int X, int Y) : Camina(X,Y){
    timer = new Timer();
    timer->start();
    lastTick = timer->get_ticks();
    deadTime = IA_IDLE_DEADTIME;
    srand(time(NULL));
};


int IA::generarRandom(int max)
{
    return (rand()%max) + 1;
}

bool IA::checkTimer(){
    if(timer->get_ticks() > lastTick + deadTime){
            lastTick = timer->get_ticks();
            return true;
    }else return false;
}
bool IA::idle(){

    if(checkTimer()){
     switch(generarRandom(4)){
            case 1:
               moveTo(getX(),getY()+generarRandom(4)*32);
                break;
          case 2:
               moveTo(getX(),getY()-generarRandom(4)*32);
               break;
           case 3:
               moveTo(getX()+generarRandom(4)*32,getY());
               break;
           case 4:
               moveTo(getX()-generarRandom(4)*32,getY());
               break;
            default:
                return true;
                break;
        }
    }else return false;
};