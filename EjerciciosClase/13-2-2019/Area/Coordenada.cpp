#include "Coordenada.h"
#include "math.h"
#include <iostream>
using namespace std;

const double PI = 3.1415926;

Coordenada::Coordenada(double radius, double angle) : radius(radius), angle(angle){}

double Coordenada::obtenerX(){
    double x;
    x = radius * cos(angle * PI / 180);
    return round(x);
}

double Coordenada::obtenerY(){
    double y;
    y = radius * sin(angle * PI / 180);
    return round(y);
}