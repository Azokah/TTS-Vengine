#include "GuiTexto.h"

GuiTexto::GuiTexto(std::string txt, int X, int Y):GuiComponent(txt,X,Y){};
GuiTexto::~GuiTexto(){};
bool GuiTexto::inBounds(int X, int Y){
	if( X >= GuiComponent::getX() &&
			X <= GuiComponent::getX()+(getText().size()*TEXTO_SIZE)){
		if( Y >= GuiComponent::getY() &&
				Y <= GuiComponent::getY()+
				(GuiComponent::getText().size())){
			return true;
		}else return false;
	}else return false;
		
};

void GuiTexto::onClick(){};

void GuiTexto::dibujar(){
	SDLManager::getInstance().imprimirTexto(getText(),
			getX(),
			getY(),
			255,255,255);
};
