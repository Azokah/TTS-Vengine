#include "Camina.h"

Camina::Camina(int X, int Y){
    x = X;
    y = Y;
    xDestino = x;
    yDestino = y;
    xIncremento = yIncremento = 0;
    direccion = PJ_DIRECCION_SUR;
    velocidad = PJ_VELOCIDAD;
};
//Camina::~Camina(){};

float Camina::normaVector(float X, float Y) { return sqrt(X * X + Y * Y); };
void Camina::normalizar(float *X, float *Y)
{
    float norma = normaVector(*X, *Y);
    *X /= norma;
    *Y /= norma;
    *X *= velocidad;
    *Y *= velocidad;
};

void Camina::moveTo(int X, int Y)
{
    xDestino = (((int)X-PJ_OFFSET_X)/32)*32;
    yDestino = (((int)Y-PJ_OFFSET_Y)/32)*32;
    xIncremento = xDestino - x;
    yIncremento = yDestino - y;
    if(std::abs(xIncremento) > std::abs(yIncremento)){
        if(xIncremento > 0) direccion = PJ_DIRECCION_OESTE;
        else direccion = PJ_DIRECCION_ESTE;
    }  else {
        if( yIncremento > 0) direccion = PJ_DIRECCION_SUR;
        else direccion = PJ_DIRECCION_NORTE;
    }
    normalizar(&xIncremento, &yIncremento);
};

bool Camina::move()
{
    bool retorno = true;
    if ((int)xDestino != (int)x || (int)yDestino != (int)y)
    { //Esta mejor pero puede mejorar
        
        if(((xDestino > x) &&(x+xIncremento > xDestino)) || ((xDestino < x) &&(x+xIncremento < xDestino))) x = xDestino;
        else x += xIncremento;
        
        if(((yDestino > y) &&(y+yIncremento > yDestino)) || ((yDestino < y) &&(y+yIncremento < yDestino))) y = yDestino;
        else y += yIncremento;
        
    }
    else retorno = false;
    caminando = retorno;
    return retorno;
};

int Camina::getX() { return x; };
int Camina::getY() { return y; };