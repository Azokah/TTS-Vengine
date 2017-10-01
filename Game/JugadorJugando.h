#pragma once
#include <iostream>
#include "JugadorState.h"

class JugadorJugando : public JugadorState {
	public:
		JugadorJugando(){};
		~JugadorJugando(){};

		virtual int esTurno() override {
			return 1;
		};
};
