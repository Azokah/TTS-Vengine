#include "Sprite.h"

Sprite::Sprite(){
    frame = 0;
    direction = 0;
    timer = new Timer();
    timer->start();
    lastTick = timer->get_ticks();
    playing = false;
    velocidadAnimacion = TIEMPO_ANIMACION;
    
};
Sprite::~Sprite(){};

void Sprite::run(){
    if(playing){
        if(timer->get_ticks() > lastTick + velocidadAnimacion){
            lastTick = timer->get_ticks();
            if(frame+1 < frames[direction].size()) frame++;
            else frame = 0;
        }
    }
    
};

void Sprite::agregarFrame(SDL_Rect rect,int dir){
    frames[dir].push_back(rect);
};
void Sprite::agregarFrame(int x, int y, int w ,int h)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    frames[0].push_back(rect);
}
void Sprite::agregarFrame(int x, int y, int w ,int h, int dir)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    frames[dir].push_back(rect);
}

SDL_Rect* Sprite::getFrame(){
    return &frames[0].at(frame);
};
SDL_Rect* Sprite::getFrameDir(){
    return &frames[direction].at(frame);
};

void Sprite::play(){
    playing = true;
    direction = 0;
};
void Sprite::play(int dir){
     playing = true;
     direction = dir;
};
void Sprite::stop(){
    playing = false;
    frame = 0;
};

void Sprite::setVelocidad(int x){ velocidadAnimacion = x;};