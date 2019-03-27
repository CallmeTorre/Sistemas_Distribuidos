#include "Respuesta.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "Mensaje.h"
#include <stdio.h>
#include <string.h>


Respuesta::Respuesta(int pl)
{
	socketlocal = new SocketDatagrama(pl);
}

struct mensaje* Respuesta::getRequest(void){
	PaqueteDatagrama datagrama = PaqueteDatagrama(sizeof(struct mensaje));
	socketlocal->recibe(datagrama);
	struct mensaje* peticionCliente = (struct mensaje*)datagrama.obtieneDatos();
	peticionCliente->puerto=datagrama.obtienePuerto();
	printf("Peticion recibida de %s:%d\n",peticionCliente->IP, peticionCliente->puerto);
	memcpy(peticionCliente->IP, datagrama.obtieneDireccion(), strlen(datagrama.obtieneDireccion()));
	return peticionCliente;
}

void Respuesta::sendReply(char *respuesta, char *ipCliente, int puertoCliente){
	struct mensaje men;
	men.messageType=1;
	men.requestId=1;
	memcpy(men.IP,ipCliente, strlen(ipCliente)+1);
	men.puerto=puertoCliente;
	men.operationId=2;
	memcpy(men.arguments, respuesta, strlen(respuesta)+1);
	PaqueteDatagrama datagramaReply = PaqueteDatagrama((char *)&men, sizeof(men), ipCliente, puertoCliente);
	printf("Enviando Respuesta\n");
	printf("Bytes enviados: %d\n", socketlocal->envia(datagramaReply));
}