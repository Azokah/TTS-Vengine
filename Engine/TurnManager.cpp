#include "TurnManager.h"


TurnManager& TurnManager::getInstance(){
	static TurnManager instancia;
	return instancia;
};

TurnManager::TurnManager(){
	currentPlayer = 0;
};
TurnManager::~TurnManager(){};


void TurnManager::start(){
	jugadorActual = jugadores.at(currentPlayer);
};


void TurnManager::pasarTurno(){

	currentPlayer += 1;

	if(currentPlayer >= jugadores.size()){
		currentPlayer = 0;
	}
	start();
};
