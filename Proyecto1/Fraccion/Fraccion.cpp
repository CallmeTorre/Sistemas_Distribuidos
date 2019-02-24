#include "Fraccion.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Fraccion::Fraccion(int num, int dem): numerador(num), denominador(dem){}

int Fraccion::gcd(int num, int dem){
    if (num == 0) 
		return dem; 
	return gcd((num % dem), num); 
}

double Fraccion::obtenResultado(){
    cout << numerador << "/" << denominador << endl;
    return (double)numerador/(double)denominador;
}

void Fraccion::reducirFraccion(){
    int gcd_num;
    gcd_num = gcd(numerador, denominador);
    cout << numerador / gcd_num << "/" << denominador / gcd_num << endl;
}