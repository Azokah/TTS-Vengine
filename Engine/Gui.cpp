#include "Gui.h"

Gui::Gui(){
	componentes.push_back(new GuiTexto("Turno de: ",PANTALLA_AN-250,50));
	componentes.push_back(new GuiButton("Pasar Turno", PANTALLA_AN-250,100));
};
Gui::~Gui(){};


void Gui::inputMouse(int tecla, int X, int Y)
{
    switch (tecla){
        case SDL_BUTTON_LEFT:
 	
	for(int i = 0; i < componentes.size(); i++){
		if(componentes.at(i)->inBounds(X,Y))
			componentes.at(i)->onClick();
	};

        break;
    }
};
