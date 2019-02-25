#include "Temperatura.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

const double KEVINCONST = 273.15;

Temperatura::Temperatura(float temp): grados(temp){}

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