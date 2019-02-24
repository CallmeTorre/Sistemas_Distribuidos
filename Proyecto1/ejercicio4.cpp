#include <stdlib.h>
#include <iostream>
using namespace std;

const double KEVINCONST = 273.15;

class Temperatura{
    private:
        float grados;
    public:
        Temperatura(float = 0);
        void setTempKelvin(float);
        void setTempFarenheit(float);
        void setTempCelsius(float);
        void printTempKelvin();
        void printTempFarenheit();
        void printTempCelsius();
};

Temperatura::Temperatura(float temp){
    grados = temp;
}

void Temperatura::setTempKelvin(float temp){
    grados = temp;
}

void Temperatura::setTempFarenheit(float temp){
    grados = (((temp - 32) * 5) / 9) + KEVINCONST;
}

void Temperatura::setTempCelsius(float temp){
    grados = temp + KEVINCONST;
}

void Temperatura::printTempKelvin(){
    cout << "La temperatura en grados Kelvin es: " << grados << endl;
}

void Temperatura::printTempFarenheit(){
    float temp;
    temp = (((grados - KEVINCONST) * 9) / 5) + 32;
    cout << "La temperatura en grados Farenheit es: " << temp << endl;
}

void Temperatura::printTempCelsius(){
    float temp;
    temp = grados - KEVINCONST;
    cout << "La temperatura en grados Celsius es: " << temp << endl;
}

int main(){
    Temperatura temp(32);
    temp.printTempKelvin();
    temp.printTempCelsius();
    temp.printTempFarenheit();
    temp.setTempFarenheit(32);
    temp.printTempKelvin();
    temp.printTempCelsius();
    temp.printTempFarenheit();
    temp.setTempCelsius(32);
    temp.printTempKelvin();
    temp.printTempCelsius();
    temp.printTempFarenheit();
    return 0;
}