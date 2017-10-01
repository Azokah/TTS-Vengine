#include "Game.h"

Game &Game::getInstance()
{
    static Game instancia;
    return instancia;
};

Game::Game()
{
    srand((unsigned)time(NULL));
    estado = INICIANDO;
    //Inicializar elementos engine
    //Singletons
    sdl = &sdl->getInstance();
    in = &in->getInstance();
    camara = &camara->getInstance();
    renderComp = &renderComp->getInstance(sdl->getRender());
    turnManager = &turnManager->getInstance();
    selectionManager = &selectionManager->getInstance();

    colision = new Colision();
    musica = new Musica();
    musica->tocar();
    timer = new Timer();
    timer->start();
    gui = new Gui();
    //Inicializar elementos game
    
    mapa = new Mapa();

    bindearInput();

    setUP();
    estado = CORRIENDO;
};
Game::~Game(){
};

void Game::setUP(){
    int players;
    int opc;
    std::string nombre;
    do{
        std::cout<<"Ingrese el numero de jugadores: ";
        std::cin>>players;
    }while(players <= 0 && players >= 4);
    for(int i = 0; i < players; i++){
        std::cout<<"Ingrese el nombre del jugador numero "<<i<<":";
        std::cin>>nombre;
        jugadores.push_back(new Jugador(nombre,100));
	jugadores.at(i)->setNumero(i);
	jugadores.at(i)->setColorMod(rand()%256,rand()%256,rand()%256); //MOMENTANEO
    }

    for(int j = 0; j < jugadores.size();j++){
        std::cout<<"Jugador "<<jugadores.at(j)->getName()<<" escoge capital: "<<std::endl;
        for(int i = 0; i < mapa->estructuras.size();i++)
        {
            if(mapa->estructuras.at(i)->getOwner()->getName().compare(SIN_DUENO) == 0){
                std::cout<<i<<". "<<mapa->estructuras.at(i)->getName()<<std::endl;
            }
        }
        do{
            std::cin>>opc;
        }while(opc <= -1 && opc >= mapa->estructuras.size());
        mapa->estructuras.at(opc)->setOwner(jugadores.at(j));
    }
    turnManager->jugadores = jugadores;
    turnManager->start();
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
    mapa->dibujar();   
    
	//Estructuras
	for(int o = 0; o < mapa->estructuras.size(); o++){
		mapa->estructuras.at(o)->dibujar();
	}

    dibujarTop();
    

};
void Game::dibujarTop(){
	sdl->drawFPS();
	
	for(int i = 0; i < gui->componentes.size(); i++){
		gui->componentes.at(i)->dibujar();
      	};
	SDLManager::getInstance().imprimirTexto(turnManager->jugadorActual->getName(),PANTALLA_AN-(CURRENT_TURN_PLAYER_OFFSET*2),CURRENT_TURN_PLAYER_OFFSET,turnManager->jugadorActual->getR(),
			turnManager->jugadorActual->getG(),
			turnManager->jugadorActual->getB());
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
    X=X/TILE_W;
    Y=Y/TILE_W;
    for(int i = 0; i < mapa->estructuras.size(); i++){
        if(mapa->estructuras.at(i)->inBounds(X,Y)) selectionManager->select(mapa->estructuras.at(i));//->onClick(turnManager->jugadorActual);
    }
};


void Game::bindearInput(){
/* Signals and slots for input*/
    in->signalTecla.connect(boost::bind(&Game::input, this, _1, _2));
    in->signalBoton.connect(boost::bind(&Game::inputMouse, this, _1, _2, _3));
    in->signalBoton.connect(boost::bind(&Gui::inputMouse,gui,_1,_2,_3));
    in->checkMouse.connect(boost::bind(&Camara::checkMouse, camara,_1, _2));
};

