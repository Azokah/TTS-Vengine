#pragma once
#include <iostream>
#include <string>
#include "Sprite.h"
#include "../Constantes.h"

/* Clase que contiene la definicion de los componentes del GUI
 * GuiComponent es una clase Abstracta de la cual heredan los componentes
 * */

enum enumTipo {
	TEXTO,
	BUTTON
};
class GuiComponent {

	public:
		GuiComponent(std::string txt,int X,int Y):texto(txt),x(X),y(Y){};
		virtual ~GuiComponent(){};
		
		std::string getText(){return texto;};
		int getX(){return x;};
		int getY(){return y;};
		
		void setTipo(enumTipo TIPO){ tipo = TIPO; };
		enumTipo getTipo(){ return tipo;};

		virtual bool inBounds(int,int)  = 0;
		virtual onClick() = 0;

		

	private:
		std::string texto;
		int x, y;
		enumTipo tipo;	
};

class GuiTexto : public GuiComponent {
	public:
		GuiTexto(std::string txt, int X, int Y):GuiComponent(txt,X,Y){
			GuiComponent::setTipo(TEXTO);
		};
		~GuiTexto(){};
		virtual bool inBounds(int X, int Y){
			if( X >= GuiComponent::getX() && X <= GuiComponent::getX()+(texto.size()*TEXTO_SIZE)){
				if( Y >= GuiComponent::getY() && Y <= GuiComponent::getY()+(GuiComponent::getText().size())){
				return true;
				}
			}else return false;
				
		};

		virtual void onClick(){
			std::cout<<GuiComponent::getText()<<std::endl;
		}
};


class GuiButton : public GuiComponent {
	public:
		GuiButton(std::string txt, int X, int Y):GuiComponent(txt,X,Y){
			GuiComponent::setTipo(BUTTON);
			sprite = new Sprite();
			sprite->agregarFrame(TILE_W*7,0,64,32);
			sprite->agregarFrame(TILE_W*9,0,64,32);
		};
		~GuiButton(){};

		/*Override*/
		virtual bool inBounds(int X, int Y){
			if(X >= GuiComponent::getX() && X <= GuiComponent::getX()+sprite->getFrame()->w){
				if(Y >= GuiComponent::getY() && Y <= GuiComponent::getY()+sprite->getFrame()->h){
					std::cout<< Y << " - " << GuiComponent::getY() << " - " << sprite->getFrame()->h<<std::endl;
					return true;
				}
			}
			else return false;
		};
		
		/* Override */
		virtual void onClick(){
			sprite->play();
			sprite->run();
		};

		Sprite * sprite;

		
};
