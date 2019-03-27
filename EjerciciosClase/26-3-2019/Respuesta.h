#ifndef __RESPUESTA_H__
#define __RESPUESTA_H__
#include "SocketDatagrama.h"

class Respuesta{
public:
 Respuesta(int pl);
 struct mensaje *getRequest(void);
 void sendReply(char *respuesta, char *ipCliente, int puertoCliente);
private:
 SocketDatagrama *socketlocal;
};

#endif