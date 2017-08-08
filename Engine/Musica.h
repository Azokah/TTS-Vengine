#pragma once

#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "getError.h"
#include "../Constantes.h"

class Musica
{
public:
	Musica();
	~Musica();
	
	void tocar();
	void setVolume(int x);
	int getVolume();
private:
	Mix_Music * musica;
	int volumen;

	void init();
};

