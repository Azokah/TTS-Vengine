#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "getError.h"
#include "../Constantes.h"

/*class Timer
{
public:
	Timer(void);
	~Timer(void);
	void run();
	void pause();
	void stop();
	void start();
	Uint32 getTime();
	bool esperar(int tiempo);
private:

	Uint32 _timer;
	bool _running;
	int _tiempo;
};

*/

//The timer
class Timer
{
    private:
    //The clock time when the timer started
    int startTicks;

    //The ticks stored when the timer was paused
    int pausedTicks;
    
	int _contando;

    //The timer status
    bool paused;
    bool started;
    public:
    //Initializes variables
    Timer();
    
    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();
	bool wait(int tiempo);
    //Gets the timer's time
    int get_ticks();

	//Obtener el tiempo del timer desde la ultima llamada
	int getUpdateTicks();
	int lastUpdateTicks;
    
    //Checks the status of the timer
    bool is_started();
    bool is_paused(); 
};