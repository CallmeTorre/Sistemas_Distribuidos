#include <iostream>
#include <vector>
using namespace std;

vector<bool> arregloNumeros(int numeros){
    std::vector<bool> vector(numeros);
    vector[0] = false;
    vector[1] = false;
    for(int i = 2; i < numeros; i++){
        vector[i] = true;
    }
    return vector;
}

int main(){
    int num;
    cout << "Escriba un numero entero entre el 2 y 99999: ";
    cin >> num;
    vector<bool> vector = arregloNumeros(num);
    for(int i = 2; i <= num; i++){
        if(vector[i] == true){
            for(int j = i; j <= (num/i); j++){
                vector[i*j] = false;
            }
        }
    }
    for(int x = 0; x < vector.size(); x++){
        if(vector[x] == true){
            cout << x << endl;
        }
    }
    return 0;
}