#pragma once
#include <iostream>
#include <string>
#include "GuiComponent.h"
#include "GuiRect.h"
#include "GuiBoton.h"
#include "../Constantes.h"

class GuiMenu : public GuiComponent {
	public:
		
		GuiMenu(int X, int Y);
		~GuiMenu();
		virtual bool inBounds(int X, int Y);
		virtual void onClick();
		virtual void dibujar();
		void addOpcion(std::string texto,AccionesBoton accion);
	private:
		GuiRect * fondo;
		std::vector<GuiBoton*> opciones;
		int x, y;

		int getWidth();
		int getHeight();
};
