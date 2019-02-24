#include "Temperatura.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

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