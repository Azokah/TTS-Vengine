#pragma once
#include <iostream>
#include <vector>
#include "../Constantes.h"
#include "../Game/Jugador.h"

/*
 *	Singleton encargado de administrar de quien es el turno
 * */

class TurnManager {
	public:
		static TurnManager& getInstance();
		~TurnManager();

		Jugador* jugadorActual;
		std::vector<Jugador*> jugadores;
		
		void start();
		void pasarTurno();
	private:
		TurnManager();
		int currentPlayer;

};
