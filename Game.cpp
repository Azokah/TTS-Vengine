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
    //Singletons
    sdl = &sdl->getInstance();
    in = &in->getInstance();
    camara = &camara->getInstance();
    renderComp = &renderComp->getInstance(sdl->getRender());
    
    
    colision = new Colision();
    musica = new Musica();
    musica->tocar();
    timer = new Timer();
    timer->start();
    gui = new Gui();
    //Inicializar elementos game
    
    mapa = new Mapa();

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
    }

    for(int j = 0; j < jugadores.size();j++){
        std::cout<<"Jugador "<<jugadores.at(j)->getName()<<" escoge capital: "<<std::endl;
        for(int i = 0; i < mapa->estructuras.size();i++)
        {
            if(mapa->estructuras.at(i)->getOwner() == NULL){
                std::cout<<i<<". "<<mapa->estructuras.at(i)->getName()<<std::endl;
            }
        }
        do{
            std::cin>>opc;
        }while(opc <= -1 && opc >= mapa->estructuras.size());
        mapa->estructuras.at(opc)->setOwner(jugadores.at(j));
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
   
		/* Esto se podria resolver con dynamic_cast... no se si es lo correcto
		 * , creo que hay algun tipo de falla en el diseño de esto... */
		//Notas de andres
		//Cada elemento que se va a dibujar deberia implementar la interfaz Drawable.
		//La interfaz Drawable especifica el metodo 'dibuja()' que va a dictar como se
		//va a graficar cada objeto. 
		//Es decir, cada objeto debe saber dibujarse a si mismo.
		// Solucion mas rapida, implementar la interfaz Drawable en los Sprite 
		// y que posean un puntero a RenderComponent?
    };
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
    X=X/TILE_W;
    Y=Y/TILE_W;
    for(int i = 0; i < mapa->estructuras.size(); i++){
        if(mapa->estructuras.at(i)->inBounds(X,Y)) mapa->estructuras.at(i)->onClick();
    }
};


void Game::bindearInput(){
/* Signals and slots for input*/
    in->signalTecla.connect(boost::bind(&Game::input, this, _1, _2));
    in->signalBoton.connect(boost::bind(&Game::inputMouse, this, _1, _2, _3));
    in->signalBoton.connect(boost::bind(&Gui::inputMouse,gui,_1,_2,_3));
    in->checkMouse.connect(boost::bind(&Camara::checkMouse, camara,_1, _2));
};

//Crear clase resource manager:
/*
**ResourceManager: Controla la carga y descarga de recursos. 
*/
