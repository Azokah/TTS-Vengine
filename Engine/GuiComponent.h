#pragma once
#include <iostream>
#include <string>
#include "SDLManager.h"
#include "RenderComponent.h"
#include "Camara.h"
#include "Sprite.h"
#include "../Constantes.h"
#include "GuiCommands.h"

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
					255,255,255);
		};
	private:

		void (* accion)();
};


class GuiRect : public GuiComponent {
	public:
		GuiRect(int X, int Y,int W, int H, int R, int G, int B, int A):GuiComponent("Rect",X,Y){
			rect.x = X;
			rect.y = Y;
			rect.w = W;
			rect.h = H;
			r = (Uint8)R;
			g = (Uint8)G;
			b = (Uint8)B;
			a = (Uint8)A;
		};
		~GuiRect(){};
		virtual bool inBounds(int X, int Y) override {
			if( X >= rect.x &&
				       	X <= rect.x+rect.w){
				if( Y >= rect.y &&
					       	Y <= rect.y+rect.h){
					return true;
				}else return false;
			}else return false;
				
		};

		virtual void onClick() override{
		}

		virtual void dibujar() override{
			SDL_SetRenderDrawColor(SDLManager::getInstance().getRender(),
					r,g,b,a);
			SDL_RenderFillRect(SDLManager::getInstance().getRender(),&rect);
			SDL_RenderDrawRect(SDLManager::getInstance().getRender(),&rect);
		};
	private:

		SDL_Rect rect;
		Uint8 r, g, b, a;
};
class GuiMenu : public GuiComponent {
	public:
		
		GuiMenu(int X, int Y):GuiComponent("Menu",X,Y){
			x = X;
			y = Y;
			addOpcion("Cerrar",do_cerrar_menu);
			fondo = new GuiRect(x,y,getWidth(),getHeight(),0,0,0,255);
		};
		~GuiMenu(){};
		virtual bool inBounds(int X, int Y) override {
			if(fondo->inBounds(X,Y)){
				for(int i = 0; i < opciones.size();i++){
					if(opciones.at(i)->inBounds(X,Y)){
						opciones.at(i)->onClick();
					}
				}
				return true;
			}else return false;
		};

		virtual void onClick() override{
			
		};

		virtual void dibujar() override{
			fondo->dibujar();
			for(int i = 0; i < opciones.size(); i++){
				opciones.at(i)->dibujar();
			}
		};

		void addOpcion(std::string texto,void (*accion)()){
			
			GuiTexto * opcion = new GuiTexto(texto, x, y, accion);
			opciones.insert(opciones.begin(),opcion);
			//GuiTexto(std::string txt, int X, int Y, void (* action)(void))
			
			fondo = new GuiRect(x,y,getWidth(),getHeight(),0,0,0,255);
		};
	private:
		GuiRect * fondo;
		std::vector<GuiTexto*> opciones;
		int x, y;

		int getWidth(){
			int nw = 0, width = opciones.at(0)->getText().size()*TEXTO_SIZE;
			for(int i = 0; i < opciones.size(); i++){
				nw = opciones.at(i)->getText().size()*TEXTO_SIZE;
				if(nw > width) width = nw;
			}
			return width;
		};
		int getHeight(){
			return opciones.size()*TEXTO_SIZE;
		};
};
