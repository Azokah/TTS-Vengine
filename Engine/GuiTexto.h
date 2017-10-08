#pragma once
#include <iostream>
#include <string>
#include "SDLManager.h"
#include "GuiComponent.h"
#include "../Constantes.h"


class GuiTexto : public GuiComponent {
	public:
		GuiTexto(std::string txt, int X, int Y);
		~GuiTexto();
		virtual bool inBounds(int X, int Y);

		virtual void onClick();
		virtual void dibujar();		
	private:
};
;
