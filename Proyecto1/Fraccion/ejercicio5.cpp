#include "Fraccion.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
    Fraccion frac(18,15);
    cout << frac.obtenResultado() << endl;
    frac.reducirFraccion();
    return 0;
}