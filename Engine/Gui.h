#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "../Constantes.h"
#include "GuiComponent.h"
#include "ImouseInput.h"
#include "TurnManager.h"


class Gui : ImouseInput{
	public:
		Gui();
		~Gui();
		
	virtual void inputMouse(int tecla, int X, int Y);

		std::vector<GuiComponent *> componentes;
	private:

};
