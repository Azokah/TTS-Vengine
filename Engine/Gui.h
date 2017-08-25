#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Constantes.h"
#include "GuiComponent.h"



class Gui {
	public:
		Gui();
		~Gui();
	
		std::vector<GuiComponent *> componentes;
	private:

};
