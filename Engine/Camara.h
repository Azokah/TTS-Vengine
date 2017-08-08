#pragma once
#include <iostream>
#include "../Constantes.h"

class Camara {

	public:
		static Camara& getInstance();
		~Camara();

		int getX();
		int getY();
		
		int getW();
		int getH();

		void update(int,int);
	private:
		Camara();

		int x, y, w, h;
};
