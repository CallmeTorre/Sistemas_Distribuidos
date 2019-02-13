#include "Coordenada.h"
#include "Rectangulo.h"
#include "math.h"
#include <iostream> 
#include <stdlib.h>
using namespace std;

int main(){
    Rectangulo rectangulo1(Coordenada(sqrt(13), 56.31),Coordenada(sqrt(26), 11.31));
    double ancho, alto;

    cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano:\n";
    rectangulo1.imprimeEsq();

    cout << "El área del rectángulo es = " << rectangulo1.obtieneArea() << endl;
    return 0;
}