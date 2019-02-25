#include "Fecha.h"
#include <iostream> 
using namespace std;

int main(){
    Fecha a, b, c(21, 9, 2018);
    a.muestraFecha();
    b.muestraFecha();
    c.muestraFecha();

    /*-------------------------------
        Metodo que convierte la fecha 
        en (anio * 10000 + mes * 100 + dia)
        y lo regresa como entero.
      -------------------------------*/

    cout << "Fecha convertida: " << a.convierte() << endl;
    cout << "Fecha convertida: " << b.convierte() << endl;
    cout << "Fecha convertida: " << c.convierte() << endl;

    /*-------------------------------
        Metodo que determina si un año
        es bisiesto o no y regresa 
        un booleano (True o False)
      -------------------------------*/

    cout << "El año es bisiesto: " << a.leapyr() << endl;
    cout << "El año es bisiesto: " << b.leapyr() << endl;
    cout << "El año es bisiesto: " << c.leapyr() << endl;

    cout << "Numero de anio bisisestos: " << a.countleapyr() << endl;
    return 0;
}