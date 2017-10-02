#pragma once
#include <iostream>
#include "Gui.h"
#include "TurnManager.h"


void do_cerrar_menu(){
	//Gui::getInstance().componentes.push_back(new GuiMenu(seleccion->getX()*TILE_W,
	//			seleccion->getY()*TILE_H));
	//GG
	Gui::getInstance().componentes.erase(Gui::getInstance().componentes.end());
};

void do_nothing(){};
void do_pasar_turno(){
	TurnManager::getInstance().pasarTurno();
};


