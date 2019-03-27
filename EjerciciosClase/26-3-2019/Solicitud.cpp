#include "Solicitud.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "Mensaje.h"
#include <stdio.h>
#include <string.h>


Solicitud::Solicitud(){
	socketlocal = new SocketDatagrama(0);
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments){
	struct mensaje men;
	men.messageType=0;
	men.requestId=1;
	memcpy(men.IP,IP, strlen(IP)+1);
	men.puerto=puerto;
	men.operationId=operationId;
	memcpy(men.arguments, arguments, strlen(arguments)+1);
	PaqueteDatagrama datagrama = PaqueteDatagrama((char *)&men, sizeof(men), IP, puerto);
	socketlocal->envia(datagrama);
	PaqueteDatagrama datagramaR =  PaqueteDatagrama(sizeof(struct mensaje));
	printf("Esperando respuesta...\n");
	printf("Recibe respuesta... Bytes recibidos: %d\n", socketlocal->recibe(datagramaR));
	struct mensaje* ans = (struct mensaje*)datagramaR.obtieneDatos();
	return ans->arguments;
}