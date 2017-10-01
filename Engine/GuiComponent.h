#pragma once
#include <iostream>
#include <string>
#include "SDLManager.h"
#include "RenderComponent.h"
#include "Camara.h"
#include "Sprite.h"
#include "../Constantes.h"

/* Clase que contiene la definicion de los componentes del GUI
 * GuiComponent es una clase Abstracta de la cual heredan los componentes
 * */
class GuiComponent {

	public:
		GuiComponent(std::string txt,int X,int Y):texto(txt),x(X),y(Y){};
		virtual ~GuiComponent(){};
		
		std::string getText(){return texto;};
		int getX(){return x;};
		int getY(){return y;};

		virtual bool inBounds(int,int)  = 0;
		virtual void onClick() = 0;
		virtual void dibujar() = 0;
		

	private:
		std::string texto;
		int x, y;
};

class GuiTexto : public GuiComponent {
	public:
		GuiTexto(std::string txt, int X, int Y, void (* action)(void)):GuiComponent(txt,X,Y){
		accion = action;
		};
		~GuiTexto(){};
		virtual bool inBounds(int X, int Y) override {
			if( X >= GuiComponent::getX() &&
				       	X <= GuiComponent::getX()+(getText().size()*TEXTO_SIZE)){
				if( Y >= GuiComponent::getY() &&
					       	Y <= GuiComponent::getY()+
						(GuiComponent::getText().size())){
					return true;
				}else return false;
			}else return false;
				
		};

		virtual void onClick() override{
			accion();
		}

		virtual void dibujar() override{
			SDLManager::getInstance().imprimirTexto(getText(),
					getX(),
					getY(),
					255,0,0);
		};
	private:

		void (* accion)();
};
