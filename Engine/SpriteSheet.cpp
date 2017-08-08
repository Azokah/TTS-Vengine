#include "SpriteSheet.h"


SpriteSheet& SpriteSheet::getInstance(SDL_Renderer * render){
    static SpriteSheet * instance = new SpriteSheet(render);
    return *instance;
};
SpriteSheet::SpriteSheet(SDL_Renderer * render){
    loadSpriteSheet(render);
};

SpriteSheet::~SpriteSheet(){
    SDL_DestroyTexture(textura);
};

void SpriteSheet::loadSpriteSheet(SDL_Renderer * render){
    textura = IMG_LoadTexture(render,ASSETS_PATH);
};

SDL_Texture* SpriteSheet::getSpriteSheet(){return textura;};