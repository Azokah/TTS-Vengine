#pragma once
#include <iostream>
#include <string>
#include "../Constantes.h"

class GuiComponent {

	public:
		GuiComponent(std::string txt,int X,int Y):texto(txt),x(X),y(Y){};
		~GuiComponent(){};
		
		std::string getText(){return texto;};
		int getX(){return x;};
		int getY(){return y;};

	private:
		std::string texto;
		int x, y;
};
