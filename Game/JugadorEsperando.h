#pragma once
#include <iostream>
#include "JugadorState.h"

class JugadorEsperando : public JugadorState {
	public:
		JugadorEsperando(){};
		~JugadorEsperando(){};
		
		virtual int esTurno() override {
			return 0;
		};
};
