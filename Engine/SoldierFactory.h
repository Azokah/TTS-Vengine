#pragma once
#include <iostream>
#include "../Constantes.h"
#include "Gui.h"
#include "GuiComponent.h"
#include "../Game/Infanteria.h"
#include "../Game/Arqueros.h"
#include "../Game/Caballeria.h"



class SoldierFactory {
	public:

		static SoldierFactory& getInstance();
		~SoldierFactory();

		void reclutar(int,int);
	private:

		SoldierFactory();

};
