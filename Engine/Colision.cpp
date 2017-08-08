#include "Colision.h"


Colision::Colision(){};
Colision::~Colision(){};

bool Colision::detectar(SDL_Rect * rect1, SDL_Rect * rect2){
    return detectar(
        rect1->x,rect1->y,rect1->w,rect1->h,
        rect2->x,rect2->y,rect2->w,rect2->h);
};
bool Colision::detectar( int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2){
    //COLISION AABB
    bool retorno = false;
    if((x1 >= x2 && x1 <= x2+w2) || (x1+w1 >= x2 && x1+w1 <= x2+w2)){
        if((y1 >= y2 && y1 <= y2+h2) || (y1+h1 >= y2 && y1+h1 <= y2+h2)){
            retorno = true;
        };
    }
    return retorno;
};