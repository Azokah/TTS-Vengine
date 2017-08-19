#include "Sprite.h"

Sprite::Sprite(){
    frame = 0;
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
            if(frame+1 < frames.size()) frame++;
            else frame = 0;
        }
    }
    
};

void Sprite::agregarFrame(int x, int y, int w ,int h)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    frames.push_back(rect);
}
void Sprite::agregarFrame(int x, int y, int w ,int h, int dir)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    frames.push_back(rect);
}

SDL_Rect* Sprite::getFrame(){
    return &frames.at(frame);
};
SDL_Rect* Sprite::getFrameDir(){
    return &frames.at(frame);
};

void Sprite::play(){
    playing = true;
};

void Sprite::stop(){
    playing = false;
    frame = 0;
};

void Sprite::setVelocidad(int x){ velocidadAnimacion = x;};


