#include <iostream>
#include <math.h>
using namespace std;

const double GRAVITY = 9.81;

int main(){
    int vel_inicial = 0;
    double tiempo, altura;

    cout << "Bienvenido." << endl;
    cout << "Calcularemos la altura de un edificio dado que conocemos el tiempo que tarda en caer una pelota del punto mas alto de un edificio." << endl;
    cout << "Inserte el tiempo que tarda en segundos: ";
    cin >> tiempo;

    altura = (vel_inicial * tiempo) + ((GRAVITY * pow(tiempo, 2)) / 2);

    cout << "La altura del edificio es: ";
    cout << altura << " metros" << endl;

    return 0;
}