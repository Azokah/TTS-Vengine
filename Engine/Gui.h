#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "Camara.h"
#include "../Constantes.h"
#include "GuiComponent.h"
#include "GuiTexto.h"
#include "GuiBoton.h"
#include "GuiRect.h"
#include "GuiMenu.h"
#include "ImouseInput.h"
#include "TurnManager.h"

class Gui : ImouseInput{
	public:
		static Gui& getInstance();
		~Gui();
		
		virtual void inputMouse(int tecla, int X, int Y);
	
		std::vector<GuiComponent *> componentes;
		void dibujar();

	private:
		Gui();

};
