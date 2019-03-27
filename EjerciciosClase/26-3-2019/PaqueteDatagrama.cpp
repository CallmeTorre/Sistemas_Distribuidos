#include "PaqueteDatagrama.h"
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

PaqueteDatagrama::PaqueteDatagrama(char * info, unsigned int longitud_mensaje, char * ip_addr, int port)
{
	datos = new char[longitud_mensaje];
	memcpy(datos, info, sizeof(char)*longitud_mensaje);
	memcpy(ip, ip_addr, sizeof(char)*16);
    longitud = longitud_mensaje;
    puerto = port;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longitud_mensaje)
{
	datos = new char[longitud_mensaje];
	longitud = longitud_mensaje;
}

char * PaqueteDatagrama::obtieneDireccion()
{
	return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud()
{
	return longitud;
}

int PaqueteDatagrama::obtienePuerto()
{
	return puerto;
}

char *PaqueteDatagrama::obtieneDatos()
{
	return datos;
}

void PaqueteDatagrama::inicializaPuerto(int port)
{
	puerto = port;
}

void PaqueteDatagrama::inicializaIp(char * ip_addr)
{
	memcpy(ip, ip_addr, sizeof(char)*16);
}

PaqueteDatagrama::~PaqueteDatagrama()
{
	delete(datos);
}

void PaqueteDatagrama::inicializaDatos(char * info)
{
	memcpy(datos, info, longitud);
}