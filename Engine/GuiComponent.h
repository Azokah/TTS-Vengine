#pragma once
#include <iostream>
#include <string>


/*ABSTRACTA*/
class GuiComponent {

	public:
		GuiComponent(std::string txt,int X,int Y):texto(txt),x(X),y(Y){};
		virtual ~GuiComponent(){};
		
		std::string getText(){return texto;};
		int getX(){return x;};
		int getY(){return y;};

		virtual bool inBounds(int,int)  = 0;
		virtual void onClick() = 0;
		virtual void dibujar() = 0;
		

	private:
		std::string texto;
		int x, y;
};
