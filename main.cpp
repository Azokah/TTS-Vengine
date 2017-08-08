
#include <iostream>
#include "Game.h"


int main(int argc, char * argv[]){

    std::cout<<"Iniciando Quest..."<<std::endl;
    Game * game = &game->getInstance();
    game->run();

    return 0;
};