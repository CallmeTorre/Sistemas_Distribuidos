#include <stdio.h>
#include "math.h"

const double MAX = 100000000;

int main() {
    double i = 0;
    double seno = 0;
    double coseno = 0;
    double tangente = 0;
    double logaritmo = 0;
    double raizCuadrada = 0;
    while(i < MAX){
        seno += sin(i);
        coseno += cos(i);
        tangente += tan(i);
        logaritmo += log(i);
        raizCuadrada += sqrt(i);
        i++;
    }
   return 0;
}