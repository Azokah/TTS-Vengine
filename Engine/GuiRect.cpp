#include "GuiRect.h"
GuiRect::GuiRect(int X, int Y,int W, int H, int R, int G, int B, int A):GuiComponent("Rect",X,Y){
	rect.x = X;
	rect.y = Y;
	rect.w = W;
	rect.h = H;
	r = (Uint8)R;
	g = (Uint8)G;
	b = (Uint8)B;
	a = (Uint8)A;
};
GuiRect::~GuiRect(){};
bool GuiRect::inBounds(int X, int Y){
	if( X >= rect.x &&
			X <= rect.x+rect.w){
		if( Y >= rect.y &&
				Y <= rect.y+rect.h){
			return true;
		}else return false;
	}else return false;
		
};

void GuiRect::onClick(){
}

void GuiRect::dibujar(){
	SDL_SetRenderDrawColor(SDLManager::getInstance().getRender(),
			r,g,b,a);
	SDL_RenderFillRect(SDLManager::getInstance().getRender(),&rect);
	SDL_RenderDrawRect(SDLManager::getInstance().getRender(),&rect);
};
