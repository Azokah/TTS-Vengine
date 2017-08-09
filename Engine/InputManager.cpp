#include "InputManager.h"

InputManager& InputManager::getInstance(){
            static InputManager instancia;
            return instancia;
}
InputManager::InputManager(){
    for(int i = 0; i < TECLAS; i++) { teclas[i] = false; }
    for(int i = 0; i < BOTONES; i++) { botones[i] = false; }
    //SDL_EnableKeyRepeat(0,0);
};
InputManager::~InputManager(){};
void InputManager::run(Camara * camara){

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                SDL_Quit();
                break;
            case SDL_MOUSEMOTION:
                checkMouse(event.motion.x, event.motion.y);
                break;
            case SDL_KEYDOWN:
                std::cout<<"Se apreto tecla: "<<event.key.keysym.scancode<<std::endl;
                teclas[event.key.keysym.scancode] = true;
                signalTecla(event.key.keysym.scancode,true);
                break;
            case SDL_KEYUP:
                std::cout<<"Se solto tecla: "<<event.key.keysym.scancode<<std::endl;
                teclas[event.key.keysym.scancode] = false;
                signalTecla(event.key.keysym.scancode,false);
                break;
            case SDL_MOUSEBUTTONUP:
                switch (event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    //signalBoton(event.button.button,false);
                    break;
                case SDL_BUTTON_RIGHT:
                    //signalBoton(event.button.button,false);
                    break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                mousex = event.button.x;
                mousey = event.button.y;
                signalBoton(event.button.button,mousex + camara->getX(),mousey + camara->getY());
                switch (event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    break;
                case SDL_BUTTON_RIGHT:
                    break;
                case SDL_BUTTON_MIDDLE:
                    break;
                }
                break;
            default:
                break;
            }
        }
};

int InputManager::getMouseX(){ return mousex;};
int InputManager::getMouseY(){ return mousey;};