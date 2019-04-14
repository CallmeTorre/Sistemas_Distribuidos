#include "Solicitud.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "Header.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char buffer[BUFSIZ];


Solicitud::Solicitud(){
	socketlocal = new SocketDatagrama(0);
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *name){
	printf("Realizando operacion %d\n", operationId);
	int destino, origen, nbytes;
	struct mensaje men;
	men.opcode=operationId;
	memcpy(men.IP,IP, strlen(IP)+1);
	men.puerto=puerto;
	memcpy(men.name, name, strlen(name)+1);

	printf("Haciendo solicitud a %s:%d\n", men.IP, men.puerto);
	if(operationId == GET){
		PaqueteDatagrama datagrama = PaqueteDatagrama((char *)&men, sizeof(men), IP, puerto);
		socketlocal->envia(datagrama);
		destino = open("cositas2.txt", O_WRONLY|O_TRUNC|O_CREAT, 0666);
		if(destino == -1){
			perror("cositas2.txt");
			exit(-1);
		}
		while(true){
			PaqueteDatagrama datagramaR =  PaqueteDatagrama(sizeof(struct mensaje));
			socketlocal->recibe(datagramaR);
			struct mensaje* ans = (struct mensaje*)datagramaR.obtieneDatos();
			if(ans->count > 0){
				write(destino, ans->data, ans->count);
			}
			else{
				close(destino);
				break;
			}
		}
	}
	else if(operationId == POST){
		origen = open(men.name, O_RDONLY);
        if(origen == -1){
            perror(name);
            exit(-1);
        }
		while(true){
            nbytes = read(origen, buffer, sizeof buffer);
            if(nbytes > 0){
				memcpy(men.data, buffer, strlen(buffer)+1);
				men.count = nbytes;
				PaqueteDatagrama datagramaReply = PaqueteDatagrama((char *)&men, sizeof(men), IP, puerto);
				socketlocal->envia(datagramaReply);            }
            else{
				men.count = 0;
				PaqueteDatagrama datagramaReply = PaqueteDatagrama((char *)&men, sizeof(men), IP, puerto);
				socketlocal->envia(datagramaReply);
                break;
            }
        }
        close(origen);
	}

	return "data";
}