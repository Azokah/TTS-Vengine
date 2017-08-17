#include "Game.h"

Game &Game::getInstance()
{
    static Game instancia;
    return instancia;
};

Game::Game()
{
    estado = INICIANDO;
    //Inicializar elementos engine
    sdl = new SDLManager();
    in = &in->getInstance();
    camara = &camara->getInstance();
    renderComp = &renderComp->getInstance(sdl->getRender());
    colision = new Colision();
    musica = new Musica();
    musica->tocar();
    timer = new Timer();
    timer->start();
    //Inicializar elementos game
    
    mapa = new Mapa(sdl->getRender());

    /* 
    * Problemas principales:
            Sprite deberia tener la textura de Missing texture de forma automatica.
    */
    bindearInput();

    setUP();
    estado = CORRIENDO;
};
Game::~Game(){
};

void Game::setUP(){
    int players;
    std::string nombre;
    do{
        std::cout<<"Ingrese el numero de jugadores: ";
        std::cin>>players;
    }while(players <= 0 && players >= 4);
    for(int i = 0; i < players; i++){
        std::cout<<"Ingrese el nombre del jugador numero "<<i<<":";
        std::cin>>nombre;
        jugadores.push_back(new Jugador(nombre,100));
    }
}

void Game::run()
{
    std::cout << "El juego ha comenzado..." << std::endl;
    while (estado == CORRIENDO)
    {
        sdl->limpiarRender();
        update();
        dibujar();
        sdl->renderizar();
    }
};
void Game::update()
{
    in->run(camara);
    camara->update();
};
void Game::dibujar(){
    //mapa
    for (int i = 0; i < MAPA_H; i++){
        for (int j = 0; j < MAPA_W; j++){
            renderComp->renderizar(j * TILE_W, i * TILE_H, TILE_W, TILE_H, mapa->sprite->getFrame(), camara);
            //Estructuras
            for(int o = 0; o < mapa->estructuras.size(); o++){
                if(mapa->estructuras.at(o)->getX() == j && mapa->estructuras.at(o)->getY() == i)
                renderComp->renderizar(j * TILE_W, i * TILE_H, TILE_W, TILE_H, mapa->estructuras.at(o)->sprite->getFrame(), camara);
            }
        } 
    }

    dibujarTop();
    

    /*
    if(colision->detectar(pj->getX(),pj->getY(),PJ_SPRITE_W,PJ_SPRITE_H,
        pj2->getX(),pj2->getY(),PJ_SPRITE_W,PJ_SPRITE_H))
            sdl->imprimirTexto("Colision entre Pj1 y pj2.",500,300,255,125,0); //Prueba...
    */
};
void Game::dibujarTop(){
    sdl->drawFPS();
}

void Game::input(int tecla, bool estadoTecla){
    switch (tecla)
    {
    case SDL_SCANCODE_ESCAPE:
        if (estadoTecla) estado = TERMINADO;
        break;
    case SDL_SCANCODE_RIGHT:
        camara->goRight();
        break;
    case SDL_SCANCODE_LEFT:
        camara->goLeft();
        break;
    case SDL_SCANCODE_UP:
        camara->goUp();
        break;
    case SDL_SCANCODE_DOWN:
        camara->goDown();
        break;
    case SDL_SCANCODE_INSERT:
        sdl->takeScreenshot();
        break;
    }
};
void Game::inputMouse(int tecla, int X, int Y)
{
    switch (tecla){
        case SDL_BUTTON_LEFT:
        selectEntidades(X,Y);
        break;
    }
};

void Game::selectEntidades(int X,int Y){
    /* Funcion que recibe una posicion y checkea si alguna entidad del juego la ocupa. y luego la pasa al HUD para setear objetivo
        Puede ser modificado para que devuelva la entidad y darle mayor scope a la funcion. 
    std::cout<<"Personajes: "<<personajes.size()<<"."<<std::endl<<"Objetos: "<<mapa->objetos.size()<<"."<<std::endl;
    for(int o = 0; o < personajes.size(); o++){
        if(personajes.at(o)->getX()/32 == X/32  && personajes.at(o)->getY()/32 == Y/32) hud->setObjetivo(personajes.at(o));
    }
    for(int o = 0; o < mapa->objetos.size(); o++){
        if(mapa->objetos.at(o)->getX() == X/32  && mapa->objetos.at(o)->getY() == Y/32) hud->setObjetivo(mapa->objetos.at(o));
    }*/

    for(int i = 0; i < mapa->estructuras.size(); i++){
        if(mapa->estructuras.at(i)->sprite->inBounds(X,Y)) std::cout<<"Seleccionada estructura: "<<i<<std::endl;
    }

    std::cout<<"Click"<<std::endl;
};

void Game::bindearInput(){
    in->signalTecla.connect(boost::bind(&Game::input, this, _1, _2));
    in->signalBoton.connect(boost::bind(&Game::inputMouse, this, _1, _2, _3));
    in->checkMouse.connect(boost::bind(&Camara::checkMouse, camara,_1, _2));
};

//Crear clase resource manager:
/*
**ResourceManager: Controla la carga y descarga de recursos. 
*/