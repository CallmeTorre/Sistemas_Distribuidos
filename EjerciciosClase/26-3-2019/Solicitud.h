#ifndef __SOLICITUD_H__
#define __SOLICITUD_H__
#include "SocketDatagrama.h"

class Solicitud{
public:
 Solicitud();
 char * doOperation(char *IP, int puerto, int operationId, char *arguments);
private:
 SocketDatagrama *socketlocal;
};

#endif