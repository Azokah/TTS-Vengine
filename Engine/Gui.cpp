#include "Gui.h"

void do_nothing(){};
void hacer_algo(){
	std::cout<<"Hago algo"<<std::endl;
};
Gui::Gui(){
	componentes.push_back(new GuiTexto("Turno de: ",PANTALLA_AN-250,50,do_nothing));
	componentes.push_back(new GuiTexto("Pasar Turno", PANTALLA_AN-250,100,hacer_algo));
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
