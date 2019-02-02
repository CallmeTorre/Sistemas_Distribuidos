#include <iostream>
using namespace std;

int main(){
    int numeroDeLenguajes;

    cout << "!!!Hola!!!.\n" << "Bienvenido a C++.\n";
    cout << "Cuantos lenguajes de programación dominas? ";
    cin >> numeroDeLenguajes;

    if (numeroDeLenguajes < 1)
        cout << "Sería recomendable aprender antes un lenguaje más sencillo...\n" << "por ejemplo C, aunque nada es imposible.\n";
    else
        cout << "Este curso será sencillo para ti.\n";
    return 0;
}