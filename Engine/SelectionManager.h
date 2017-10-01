#include <iostream>
#include "../Constantes.h"
#include "../Game/IEntidad.h"
#include "TurnManager.h"
#include "Gui.h"

/*	Clase que se encarga de administrar las entidades seleccionadas
 *	ejecuta sus metodos onClick, y hace de puente con otros elementos del juego
 *	como el GUI por ejemplo.	*/


class SelectionManager{

	public:
		static SelectionManager& getInstance();
		~SelectionManager();
		
		void select(IEntidad*);

	private:
		SelectionManager();
		IEntidad * seleccion;
};
