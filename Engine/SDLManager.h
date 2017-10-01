#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "../Constantes.h"
#include "getError.h"
#include "Texto.h"
#include "Timer.h"

class SDLManager {

	public:
		static SDLManager& getInstance();
		~SDLManager();

		void limpiarRender();
		void renderizar();
		
		void imprimirTexto(std::string mensaje, int x, int y, int r, int g, int b);
	
		SDL_Renderer * getRender();
		
		void drawFPS();

		void takeScreenshot();
	private:
		SDLManager();
		float FPS,FPSMAX,proximoTick;
		SDL_Texture * cargarTextura(SDL_Renderer * renderer, std::string path);

		SDL_Window * ventana;
		SDL_Renderer * render;

		SDL_Texture * tileset;

        SDL_Event event;

		Texto * texto;
};

