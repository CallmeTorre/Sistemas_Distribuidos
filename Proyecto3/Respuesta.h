#ifndef RESPUESTA_H
#define RESPUESTA_H
#include "SocketDatagrama.h"

class Respuesta{
    public:
        Respuesta(int pl);
        struct mensaje *getRequest(void);
        void sendReply(char *respuesta, int nbytes, char *ipCliente, int puertoCliente);
    private:
        SocketDatagrama *socketlocal;
    };

#endif