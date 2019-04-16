#include "Header.h"
#include "Solicitud.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
	Solicitud solCliente;
 	char IP[16];
 	memcpy(IP, "127.0.0.1", strlen("127.0.0.1"));
 	int puerto = 7200;
	printf("La respuesta del servidor es: %s\n",solCliente.doOperation(IP, puerto, atoi(argv[2]), argv[1]));
}