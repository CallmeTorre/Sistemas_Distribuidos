#include <iostream>
using namespace std;

int main(){
    double celsius, farenheit;
    cout << "Bienvenido.\n";
    cout << "Convertiremos de Celsius a Farenheit .\n";
    cout << "Inserte los grados: ";
    cin >> celsius;

    farenheit = ((9 * celsius)/5) + 32.0;

    cout << farenheit << endl;

    return 0;
}