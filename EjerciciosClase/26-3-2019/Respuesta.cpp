#include "Respuesta.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "Mensaje.h"
#include <stdio.h>
#include <string.h>


Respuesta::Respuesta(int pl)
{
	int p=pl;
	socketlocal = new SocketDatagrama(p);
}

struct mensaje* Respuesta::getRequest(void){
	PaqueteDatagrama datagrama = PaqueteDatagrama(sizeof(struct mensaje));
	socketlocal->recibe(datagrama);
	printf("Peticion recibida...\n");
	struct mensaje* peticionCliente = (struct mensaje*)datagrama.obtieneDatos();
	peticionCliente->puerto=datagrama.obtienePuerto();
	memcpy(peticionCliente->IP, datagrama.obtieneDireccion(), strlen(datagrama.obtieneDireccion()));
	return peticionCliente;
}

void Respuesta::sendReply(char *respuesta, char *ipCliente, int puertoCliente){
	struct mensaje men;
	men.messageType=1;
	men.requestId=1;
	memcpy(men.IP,ipCliente, strlen(ipCliente)+1);
	men.puerto=puertoCliente;
	men.operationId=100000;
	memcpy(men.arguments, respuesta, strlen(respuesta)+1);
	PaqueteDatagrama datagramaReply = PaqueteDatagrama((char *)&men, sizeof(men), ipCliente, puertoCliente);
	printf("Envia respuesta...Bytes enviados: %d\n", socketlocal->envia(datagramaReply));
}