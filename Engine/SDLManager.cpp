#include "SDLManager.h"



SDLManager& SDLManager::getInstance(){
	static  SDLManager instancia;
	return instancia;
};

SDLManager::SDLManager()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        getError("No se pudo inicializar SDL.");
    ventana = SDL_CreateWindow(TITULO, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, PANTALLA_AN, PANTALLA_AL, SDL_WINDOW_SHOWN);//SDL_WINDOW_FULLSCREEN
    render = SDL_CreateRenderer(ventana, -1, GAME_OPTIONS);

    //tileset = cargarTextura(render, ASSETS_PATH);

    timer = new Timer();
    timer->start();
    proximoTick = timer->get_ticks() + 1000;

    texto = new Texto();
    texto->init(TEXTO_SIZE);
    texto->setAlpha(TEXTO_ALPHA);

    FPS = 0;
};
SDLManager::~SDLManager(){};

void SDLManager::imprimirTexto(std::string mensaje, int x, int y, int r, int g, int b)
{

    texto->ponerTexto(mensaje, x, y, r, g, b, render);
}

SDL_Texture *SDLManager::cargarTextura(SDL_Renderer * renderer, std::string path)
{
    SDL_Texture * textura;
    textura = IMG_LoadTexture(renderer, path.c_str());
    if (textura == NULL)
    {
        getError("No se pudo cargar la textura: " + path);
        return NULL;
    }
    return textura;
};

void SDLManager::limpiarRender() { SDL_RenderClear(render); };
void SDLManager::renderizar() { //Renderizo y aumento el conteo de FPS.
    SDL_RenderPresent(render);
    FPS++;
};

SDL_Renderer * SDLManager::getRender() { return render; };

void SDLManager::drawFPS(){
	if(timer->get_ticks() >= proximoTick) {
		proximoTick = timer->get_ticks() + 1000;
		FPSMAX = FPS;
		FPS = 0;
	}
	char txt[25];
	sprintf(txt,"FPS: %.0f",FPSMAX);
	imprimirTexto(txt,25,50,255,0,125);
};

void SDLManager::takeScreenshot(){

    SDL_Surface *sshot = SDL_CreateRGBSurface(0, PANTALLA_AN, PANTALLA_AL, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(render, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
    SDL_SaveBMP(sshot, "screenshot.bmp");
    std::cout<<"Screenshot taken!"<<std::endl;
    SDL_FreeSurface(sshot);

}
