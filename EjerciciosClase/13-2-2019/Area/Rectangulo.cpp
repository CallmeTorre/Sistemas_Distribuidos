#include "Rectangulo.h"
#include <iostream>
using namespace std;

Rectangulo::Rectangulo() : superiorIzq(), inferiorDer(){}

Rectangulo::Rectangulo(Coordenada supIzq, Coordenada infDer):superiorIzq(supIzq), inferiorDer(infDer){}

void Rectangulo::imprimeEsq(){
    cout << "Para la esquina superior izquierda.\n";
    cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
    cout << "Para la esquina inferior derecha.\n";
    cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;
}

Coordenada Rectangulo::obtieneSupIzq(){
    return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer(){
    return inferiorDer;
}

int Rectangulo::obtieneArea(){
    int alto, ancho;
    alto = obtieneSupIzq().obtenerY() - obtieneInfDer().obtenerY();
    ancho = obtieneInfDer().obtenerX() - obtieneSupIzq().obtenerX();
    return ancho*alto;
}