#include "GuiMenu.h"

GuiMenu::GuiMenu(int X, int Y):GuiComponent("Menu",X,Y){
	x = X;
	y = Y;
	addOpcion("Cerrar",BOTON_CERRAR);
	fondo = new GuiRect(x,y,getWidth(),getHeight(),0,0,0,255);
};
GuiMenu::~GuiMenu(){};
bool GuiMenu::inBounds(int X, int Y){
	if(fondo->inBounds(X,Y)){
		for(int i = 0; i < opciones.size();i++){
			if(opciones.at(i)->inBounds(X,Y)){
				opciones.at(i)->onClick();
			}
		}
		return true;
	}else return false;
};

void GuiMenu::onClick(){
	
};

void GuiMenu::dibujar(){
	fondo->dibujar();
	for(int i = 0; i < opciones.size(); i++){
		opciones.at(i)->dibujar();
	}
};

void GuiMenu::addOpcion(std::string texto,AccionesBoton accion){
	
	GuiBoton * opcion = new GuiBoton(texto, x, y, accion);
	opciones.insert(opciones.begin(),opcion);
};
int GuiMenu::getWidth(){
	int nw = 0, width = opciones.at(0)->getGuiTexto()->getText().size()*TEXTO_SIZE;
	for(int i = 0; i < opciones.size(); i++){
		nw = opciones.at(i)->getGuiTexto()->getText().size()*TEXTO_SIZE;
		if(nw > width) width = nw;
	}
	return width;
};
int GuiMenu::getHeight(){
	return opciones.size()*TEXTO_SIZE;
};
