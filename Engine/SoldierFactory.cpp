#include "SoldierFactory.h"

SoldierFactory& SoldierFactory::getInstance(){
	static SoldierFactory * instance = new SoldierFactory();
	return *instance;
};


SoldierFactory::SoldierFactory(){};
SoldierFactory::~SoldierFactory(){};

void SoldierFactory::reclutar(int X, int Y){
	Gui::getInstance().componentes.push_back(new GuiMenu(X,Y));
	
};
