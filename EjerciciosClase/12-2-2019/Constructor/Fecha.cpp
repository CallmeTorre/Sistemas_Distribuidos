
#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa) : dia(dd), mes(mm), anio(aaaa) {
   if((anio > 2019) || (anio < 0)){
      cout << "Valor ilegal para el anio!\n";
      exit(1);
   }
   if((dia > 31) || (dia < 1)){
      cout << "Valor ilegal para el dia!\n";
      exit(1);
   }
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa){
   anio = aaaa;
   mes = mm;
   dia = dd;
   return;
}
void Fecha::muestraFecha(){
    cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
    return; 
}

int Fecha::convierte(){
   return (anio * 10000) + (mes * 100) + dia;
}

bool Fecha::leapyr(){
   if((anio % 4 ==0 and anio % 100 != 0) or anio % 400 == 0)
      return true;
   else
      return false;
}

int Fecha::countleapyr(){
   int res = 0;
   for(int i = 1; i <= 2019; i++){
      if((i % 4 ==0 and i % 100 != 0) or i % 400 == 0)
         res++;
   }
   return res;
}