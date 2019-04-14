#include "Respuesta.h"
#include "Header.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;
char buffer[BUFSIZ];

int main()
{
	Respuesta respuesta(7200);
	struct mensaje* recibido;
	char nombreArchivo[100];
    int nbytes, destino;
	recibido=respuesta.getRequest();
    memcpy(nombreArchivo, recibido->name, strlen(recibido->name));
    if(recibido->opcode == GET){
        printf("GET Operation\n");
        int origen = open(nombreArchivo, O_RDONLY);
        if(origen == -1){
            perror(nombreArchivo);
            exit(-1);
        }
        while(true){
            nbytes = read(origen, buffer, sizeof buffer);
            if(nbytes > 0){
                respuesta.sendReply(buffer, nbytes, recibido->IP, recibido->puerto);
            }
            else{
                respuesta.sendReply(buffer, 0, recibido->IP, recibido->puerto);
                break;
            }
        }
        close(origen);
    }
    else if(recibido->opcode == POST){
        printf("POST Operation\n");
        destino = open("cositas3.txt", O_WRONLY|O_TRUNC|O_CREAT, 0666);
        if(destino == -1){
			perror("cositas2.txt");
			exit(-1);
		}
			if(recibido->count > 0){
				write(destino, recibido->data, recibido->count);
			}
			else{
				close(destino);
			}
    }
    else{
        printf("RIP\n");
    }
}