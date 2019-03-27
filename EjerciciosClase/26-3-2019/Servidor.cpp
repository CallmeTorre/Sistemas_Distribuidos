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

string reversa(string cadena) 
{ 
    int i=cadena.length()-1; 
    int inicio, fin = i + 1; 
    string res = ""; 
    while(i >= 0) 
    { 
        if(cadena[i] == ' ') 
        { 
            inicio = i + 1; 
            while(inicio != fin) 
                res += cadena[inicio++]; 
            res += ' ';   
            fin = i; 
        } 
        i--; 
    } 
    inicio = 0; 
    while(inicio != fin) 
        res += cadena[inicio++];       
    return res; 
} 

int main()
{
	Respuesta respuesta(7200);
	struct mensaje* recibido;
	char cadenaInvertida[100];
	char cadenaRecibida[100];
	recibido=respuesta.getRequest();
	memcpy(cadenaRecibida, recibido->arguments, strlen(recibido->arguments));
	string cadena = reversa(cadenaRecibida);
	strcpy(cadenaInvertida, cadena.c_str());
	respuesta.sendReply(cadenaInvertida, recibido->IP, recibido->puerto);
}