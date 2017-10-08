#pragma once
#include <iostream>
#include <string>
#include "SDLManager.h"
#include "GuiComponent.h"
#include "../Constantes.h"
class GuiRect : public GuiComponent {
	public:
		GuiRect(int X, int Y,int W, int H, int R, int G, int B, int A);
		~GuiRect();
		virtual bool inBounds(int X, int Y);

		virtual void onClick();

		virtual void dibujar();
	private:

		SDL_Rect rect;
		Uint8 r, g, b, a;
};

