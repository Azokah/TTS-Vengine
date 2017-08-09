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

		void setX(int);
		void setY(int);

		void update(int,int);
		void update();

		void goUp();
		void goDown();
		void goLeft();
		void goRight();

		void checkMouse(int,int); // Funcion que recibe X e Y del mouse y mueve la camara

	private:
		Camara();

		int x, y, w, h;
		bool right,left,up,down;
};
