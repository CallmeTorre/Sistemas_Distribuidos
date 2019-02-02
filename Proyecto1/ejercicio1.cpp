#include <iostream>
using namespace std;

const double GRAVITY = 9.81;

int main(){
    float estimation = 1, num;

    cout << "Bienvenido." << endl;
    cout << "Calcularemos la raiz cuadrada de un numero." << endl;
    cout << "Inserte un numero: ";
    cin >> num;

    for (int i = 0; i < 20; i++){
        estimation = (estimation + (num / estimation)) / 2;
    }


    cout << "La raiz cuadrada es: ";
    cout << estimation << " metros" <<'\n';

    return 0;
}