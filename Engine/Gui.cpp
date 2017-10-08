#include "Gui.h"

Gui& Gui::getInstance(){
	static Gui * instance = new Gui();
	return *instance;
};
Gui::Gui(){
	componentes.push_back(new GuiTexto("Turno de: ",PANTALLA_AN-250,50));
	componentes.push_back(new GuiBoton("Pasar Turno", PANTALLA_AN-250,100,BOTON_PASARTURNO));
	componentes.push_back(new GuiTexto("Oro: ", CURRENT_TURN_PLAYER_GOLD,CURRENT_TURN_PLAYER_GOLD));
};
Gui::~Gui(){};


void Gui::inputMouse(int tecla, int X, int Y)
{
	X -= Camara::getInstance().getX();
	Y -= Camara::getInstance().getY();
    switch (tecla){
        case SDL_BUTTON_LEFT:
 	
	for(int i = 0; i < componentes.size(); i++){
		if(componentes.at(i)->inBounds(X,Y))
			componentes.at(i)->onClick();
	};

        break;
    }
};

void Gui::dibujar(){
	for(int i = 0; i < componentes.size(); i++){
		componentes.at(i)->dibujar();
      	};

	SDLManager::getInstance().imprimirTexto(TurnManager::getInstance().jugadorActual->getName(),
			PANTALLA_AN-(CURRENT_TURN_PLAYER_OFFSET*2),
			CURRENT_TURN_PLAYER_OFFSET,
			TurnManager::getInstance().jugadorActual->getR(),
			TurnManager::getInstance().jugadorActual->getG(),
			TurnManager::getInstance().jugadorActual->getB());

	SDLManager::getInstance().imprimirTexto(std::to_string(TurnManager::getInstance().jugadorActual->getGold()),
			(CURRENT_TURN_PLAYER_GOLD*4),
			CURRENT_TURN_PLAYER_GOLD,
			TurnManager::getInstance().jugadorActual->getR(),
			TurnManager::getInstance().jugadorActual->getG(),
			TurnManager::getInstance().jugadorActual->getB());


}
