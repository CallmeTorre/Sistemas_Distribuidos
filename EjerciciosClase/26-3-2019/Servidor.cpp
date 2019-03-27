#include "Respuesta.h"
#include "Mensaje.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
using namespace std;


int messageType; //0= Solicitud, 1 = Respuesta
 unsigned int requestId; //Identificador del mensaje
 char IP[16];
 int puerto;
 int operationId; //Identificador de la operación
 char arguments[TAM_MAX_DATA];


int main()
{
	Respuesta res(7200);
	struct mensaje* rec;
	char cadenaInvertida[100];
	char cadenaRecibida[100];
	rec=res.getRequest();
	memcpy(cadenaRecibida, rec->arguments, strlen(rec->arguments));

	cout << cadenaRecibida << endl;
	/////////////////////////////////////////////////////////////
	/////////////////////INVERTIR CADENAS AQUI///////////////////
	/////////////////////////////////////////////////////////////

	res.sendReply("cadenaInvertida", rec->IP, rec->puerto);
}