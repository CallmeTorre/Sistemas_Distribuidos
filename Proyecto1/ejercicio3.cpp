#include <iostream>
using namespace std;

const double GRAVITY = 9.81;

int main(){
    double tiempo;
    int horas, minutos, segundos;

    cout << "Bienvenido." << endl;
    cout << "Pasaremos de segundos a un formato H M S." << endl;
    cout << "Inserte los segundos a transformar: ";
    cin >> tiempo;

    horas = tiempo / 3600;
    minutos = (tiempo - (horas * 3600)) / 60;
    segundos = tiempo - ((horas * 3600) + (minutos * 60));

    cout << "Como resultado tenemos: ";
    cout << horas << " horas " << minutos << " minutos " << segundos << " segundos." << endl;

    return 0;
}