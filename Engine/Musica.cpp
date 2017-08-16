#include "Musica.h"


Musica::Musica(void)
{
	musica = NULL;
	volumen = 100;
	init();
}


Musica::~Musica(void)
{
}
void Musica::init()
{	
	if(Mix_OpenAudio(AUDIO_HZ, MIX_DEFAULT_FORMAT,AUDIO_CHANNELS,AUDIO_CHUNK_SIZE) == -1)
	{
		getError("No se pudo inicializar el Mixer.");
		std::cout << "No se cargo el audio" << std::endl;
	}

	musica = Mix_LoadMUS("Assets/Musica/MainTheme.mp3");
	if(musica == NULL)
	{
		getError("No se pudo cargar la Musica.");
	}
	Mix_VolumeMusic(volumen);
}
int Musica::getVolume()
{
	return volumen;
}
void Musica::tocar()
{
	if(Mix_PlayingMusic() == 0)
	{
		Mix_PlayMusic(musica, -1);
	}
	
}

void Musica::setVolume(int x)
{

	if(volumen+x <= 100 && volumen+x >= 0)
	{
		volumen = volumen+x;
		Mix_VolumeMusic(volumen);
	}
}