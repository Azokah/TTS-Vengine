#include "SelectionManager.h"


SelectionManager& SelectionManager::getInstance(){
	static SelectionManager instance;
	return instance;
};

SelectionManager::~SelectionManager(){

};

SelectionManager::SelectionManager(){};
void SelectionManager::select(IEntidad * entidad){
	seleccion = entidad;
	seleccion->onClick(TurnManager::getInstance().jugadorActual);
	/*Gui::getInstance().componentes.push_back(new GuiRect(seleccion->getX(),
				seleccion->getY(),
				200,200,0,0,0,0));*/
};
