CC=g++
DEPS=-std=c++11 -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2
INCLUDES= Engine/Camara.h Engine/Colision.h Engine/getError.h Engine/Gui.h Engine/GuiComponent.h Engine/GuiBoton.h Engine/GuiMenu.h Engine/GuiRect.h Engine/GuiTexto.h Engine/ImouseInput.h Engine/InputManager.h Engine/Musica.h Engine/RenderComponent.h Engine/SDLManager.h Engine/SelectionManager.h Engine/SoldierFactory.h Engine/Sprite.h Engine/SpriteSheet.h Engine/Texto.h Engine/Timer.h Engine/TurnManager.h Game/

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(DEPS)
all : 
	$(CC) -w *.cpp Engine/*.cpp Game/*.cpp -o tts.out $(DEPS)
