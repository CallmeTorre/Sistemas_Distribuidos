#ifndef __MENSAJE_H__
#define __MENSAJE_H__
#define TAM_MAX_DATA 4000

struct mensaje{
    int messageType; //0= Solicitud, 1 = Respuesta
    unsigned int requestId; //Identificador del mensaje
    char IP[16];
    int puerto;
    int operationId; 
    char arguments[TAM_MAX_DATA];
};

#endif