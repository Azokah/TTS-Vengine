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
	
};
