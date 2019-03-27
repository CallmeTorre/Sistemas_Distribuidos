#include "Solicitud.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	Solicitud solCliente;
 	char IP[16];
 	memcpy(IP, "127.0.0.1", strlen("127.0.0.1"));
 	int puerto = 7200;
 	int ordenaCadena = 1;
	printf("La cadena que enviaremos es: %s\n", "Esto es una cadena");
	printf("La respuesta del servidor es: %s\n",solCliente.doOperation(IP, puerto, ordenaCadena, "Esto es una cadena"));
}