#include "Fecha.h"
#include <iostream> 
#include <stdlib.h>
using namespace std;

//int masVieja(Fecha fecha1, Fecha fecha2){ // Paso por valor, cuando pasas por valor copias todo el objeto
int masVieja(Fecha &fecha1, Fecha &fecha2){ // Paso por referencia, cuando pasas por referencia pasas la direccion de memoria en donde se encuentra un objeto
	if(fecha1.convierte() > fecha2.convierte()){
		return 1;
  	}
  	else if (fecha1.convierte() == fecha2.convierte()){
		return 0;
  	}
  	else{
		return -1;
	}
}

int main(){
	for(int i = 0; i < 100000000; i++){
		int dia_a = rand() % 30 + 1;
		int mes_a = rand() % 10 + 1;
		int anio_a = rand() % 30 + 1985;
		int dia_b = rand() % 30 + 1;
		int mes_b = rand() % 10 + 1;
		int anio_b = rand() % 30 + 1985;
		Fecha a(dia_a, mes_a, anio_a);
		Fecha b(dia_b, mes_b, anio_b);
		masVieja(a, b);
	}
	Fecha a(1, 1, 1);
	cout << sizeof(a) << endl;
	cout << sizeof(&a) << endl;
	return 0;
}