#pragma once
#include <iostream>
#include <string>
#include "GuiComponent.h"
#include "GuiTexto.h"
#include "GuiRect.h"
#include "../Constantes.h"
#include "TurnManager.h"
#include "SoldierFactory.h"

enum AccionesBoton{
	BOTON_NADA,
	BOTON_PASARTURNO,
	BOTON_CERRAR,
	BOTON_RECLUTAR
};


class GuiBoton : public GuiComponent {
	public:
		GuiBoton(std::string txt, int X, int Y, AccionesBoton action);
		~GuiBoton();
		virtual bool inBounds(int X, int Y);

		virtual void onClick();

		virtual void dibujar();

		
		GuiTexto * getGuiTexto();
	private:
		GuiRect * fondo;
		GuiTexto * texto;
		AccionesBoton accion;
		
		int getWidth();
		int getHeight();
};
;
