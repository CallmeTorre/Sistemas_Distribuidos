#include <iostream>
using namespace std;

const double PI = 3.1415926;

int main(){
    float radio, area;

    cout << "Bienvenido.\n";
    cout << "Calcularemos el area de un circulo.\n";
    cout << "Inserte el valor del radio: ";
    cin >> radio;

    area = PI * radio * radio;

    cout << "El area del circulo es: ";
    cout << area << endl;

    return 0;
}