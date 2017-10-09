#include "GuiBoton.h"

GuiBoton::GuiBoton(std::string txt, int X, int Y, AccionesBoton action):GuiComponent(txt,X,Y){
			accion = action;
			texto = new GuiTexto(txt,X,Y);
			fondo = new GuiRect(X,Y,getWidth(),getHeight(),0,0,0,255);
};
GuiBoton::~GuiBoton(){};
bool GuiBoton::inBounds(int X, int Y){ return fondo->inBounds(X,Y);};
void GuiBoton::onClick(){
	switch(accion){
		case BOTON_NADA:
			//do nothing
			break;
		case BOTON_CERRAR:
			//delete this;
			Gui::getInstance().componentes.pop_back();
			break;
		case BOTON_RECLUTAR:
			//crear menu de reclutamiento
			SoldierFactory::getInstance().reclutar(GuiComponent::getX()+(getText().size()*TEXTO_SIZE),GuiComponent::getY());
			break;
		case BOTON_PASARTURNO:
			TurnManager::getInstance().pasarTurno();
			break;
		default:

			break;
	};
};
void GuiBoton::dibujar(){
	fondo->dibujar();
	texto->dibujar();
};

	
GuiTexto * GuiBoton::getGuiTexto(){ return texto;};


int GuiBoton::getWidth(){ return  getText().size()*TEXTO_SIZE;};
int GuiBoton::getHeight(){ return TEXTO_SIZE;};
