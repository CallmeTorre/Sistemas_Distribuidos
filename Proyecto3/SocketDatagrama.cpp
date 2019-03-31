#include "SocketDatagrama.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <cstring>
#include <stdio.h>

SocketDatagrama::SocketDatagrama(int port)
{
	s = socket(AF_INET, SOCK_DGRAM, 0);
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(port);
	bind(s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama()
{
	shutdown(s, 2);
}

int SocketDatagrama::recibe(PaqueteDatagrama &p)
{
	unsigned int addr_len = sizeof(direccionForanea);
	int answer = recvfrom(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &addr_len);
	p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	return answer;
}

int SocketDatagrama::envia(PaqueteDatagrama &p)
{
	direccionForanea.sin_family = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port = htons(p.obtienePuerto());
	int answer=sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
	return answer;
}