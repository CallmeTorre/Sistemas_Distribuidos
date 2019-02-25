#include "Ortoedro.h"
#include "math.h"
#include <iostream>
using namespace std;

Ortoedro::Ortoedro(Coordenada cercana, Coordenada alejada):cercanaOrigen(cercana), alejadaOrigen(alejada) {}

double Ortoedro::obtieneArea(){
    double a, b , c;
    a = alejadaOrigen.obtenerX() - cercanaOrigen.obtenerX();
    b = alejadaOrigen.obtenerY() - cercanaOrigen.obtenerX();
    c = alejadaOrigen.obtenerZ() - cercanaOrigen.obtenerZ();
    return 2 * ((a * b) + (a * c) + (b * c));
}

double Ortoedro::obtieneVolumen(){
    double a, b , c;
    a = alejadaOrigen.obtenerX() - cercanaOrigen.obtenerX();
    b = alejadaOrigen.obtenerY() - cercanaOrigen.obtenerX();
    c = alejadaOrigen.obtenerZ() - cercanaOrigen.obtenerZ();
    return a * b * c;
}