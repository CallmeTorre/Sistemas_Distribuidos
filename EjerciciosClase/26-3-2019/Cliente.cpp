#include "Solicitud.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define TAM_MAX_DATA 4000

int main()
{
	Solicitud solCliente;
 	char IP[16];
 	memcpy(IP,"127.0.0.1", strlen("127.0.0.1")+1);
 	int puerto = 7200;
 	int ordenaCadena = 1;
 	char cadenota[TAM_MAX_DATA];
 	memcpy(cadenota, "cadena", strlen("cadena")+1);
	printf("La respuesta del servidor es %s\n",solCliente.doOperation(IP, puerto, ordenaCadena, cadenota));
}