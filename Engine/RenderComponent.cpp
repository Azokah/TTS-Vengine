#include "RenderComponent.h"

RenderComponent& RenderComponent::getInstance(SDL_Renderer * RENDER){
    static RenderComponent * instance = new RenderComponent(RENDER);
    return *instance;
};

RenderComponent::RenderComponent(SDL_Renderer * RENDER){
    render = RENDER;
    sprSh = &sprSh->getInstance(RENDER);

    vPort.x = 0;
    vPort.y = 0;
    vPort.w = PANTALLA_AN;
    vPort.h = PANTALLA_AL;
    
};
RenderComponent::~RenderComponent(){};

void RenderComponent::renderizar(int x, int y,int w, int h,SDL_Rect * rect, Camara * camara){
    SDL_Rect pos;
    pos.x = x - camara->getX();
    pos.y = y - camara->getY();
    pos.w = w;
    pos.h = h;
    if((x >= camara->getX()-TILE_W && x  <= (camara->getX() + PANTALLA_AN+TILE_W)) &&
       (y >= camara->getY()-TILE_H && y <= (camara->getY() + PANTALLA_AL+TILE_H))) SDL_RenderCopy(render,sprSh->getSpriteSheet(),rect,&pos);
    //SDL_RenderDrawRect(render,&pos);
};

void RenderComponent::renderizarFixed(int x, int y,int w, int h,SDL_Rect * rect,bool flipped){
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    pos.w = w;
    pos.h = h;
    if(!flipped) SDL_RenderCopy(render,sprSh->getSpriteSheet(),rect,&pos);
    else SDL_RenderCopyEx(render,sprSh->getSpriteSheet(),rect,&pos,0,NULL,SDL_FLIP_HORIZONTAL);
    //SDL_RenderDrawRect(render,&pos);
};

void RenderComponent::renderizarViewport(int x, int y,int w, int h,SDL_Rect * rect,SDL_Rect* viewport){
    SDL_RenderSetViewport(render,viewport);
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    pos.w = w;
    pos.h = h;
    SDL_RenderCopy(render,sprSh->getSpriteSheet(),rect,&pos);
    SDL_RenderSetViewport(render,&vPort);
};

void RenderComponent::setClip(SDL_Rect * clip){
    SDL_RenderSetClipRect(render,clip);
};

void RenderComponent::setColorMod(Uint8 r, Uint8 g, Uint8 b){
	SDL_SetTextureColorMod(sprSh->getSpriteSheet(),r,g,b);
};
