#include <iostream>
using namespace std;

int main(){
    double precio = 78.7;
    
    cout << "Variable con un decimal: ";
    cout << precio << endl;
    cout << "\n";

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Variable con dos decimales: ";
    cout << precio << endl;

    return 0;
}