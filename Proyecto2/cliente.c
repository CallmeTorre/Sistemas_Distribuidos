#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>

int puerto = 7200;

int main(void)
{
    struct sockaddr_in msg_to_server_addr, client_addr;
    int s, num;
    float res;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    /* rellena la dirección del servidor */
    bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
    msg_to_server_addr.sin_family = AF_INET;
    msg_to_server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    msg_to_server_addr.sin_port = htons(puerto);

    /* rellena la direcciòn del cliente*/
    bzero((char *)&client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = INADDR_ANY;

    /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
    client_addr.sin_port = htons(0);
    bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));

    for(num = 1; num <= 25; num++){
        sendto(s, (int *)&num, sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
    }
    num = 0;
    sendto(s, (int *)&num, sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));

    /* se bloquea esperando respuesta */
    recvfrom(s, (int *)&res, sizeof(int), 0, NULL, NULL);
    printf("Paquetes perdidos: %f\n",res);
    printf("Porcentaje de paquetes enviados: %f\n", 100 - (res * 100) / 25);
    close(s);
    return 0;
}
