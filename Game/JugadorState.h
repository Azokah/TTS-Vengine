#pragma once
#include <iostream>

class JugadorState {
	public:
		virtual ~JugadorState(){};
		virtual int esTurno() =0;
};
