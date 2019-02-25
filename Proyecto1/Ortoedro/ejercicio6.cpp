#include "Ortoedro.h"
#include <iostream>
using namespace std;

int main(){
    Ortoedro orto(Coordenada(0.0,0.0,0.0), Coordenada(2.0,2.0,2.0));
    cout << "El area es: " << orto.obtieneArea() << " cm^2" << endl;
    cout << "El volumen es: " << orto.obtieneVolumen() << " cm^3" << endl;
    return 0;
}